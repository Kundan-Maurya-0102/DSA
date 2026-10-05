import os, json, textwrap, zipfile, pathlib, shutil

root = pathlib.Path("/mnt/data/cpp_self_lock")
if root.exists():
    shutil.rmtree(root)
(root / "static").mkdir(parents=True)

problems = [
    {
        "id": 1,
        "title": "Second Largest",
        "difficulty": "Easy",
        "time_limit": 10,
        "statement": "Given N integers, print the second largest distinct value.",
        "input": "N followed by N integers.",
        "output": "Print the second largest distinct integer.",
        "constraints": "2 <= N <= 100000",
        "tests": [
            {"input": "5\n10 4 8 10 3\n", "output": "8\n"},
            {"input": "4\n-5 -2 -9 -2\n", "output": "-5\n"},
            {"input": "6\n1 2 3 4 5 6\n", "output": "5\n"},
        ]
    },
    {
        "id": 2,
        "title": "Palindrome String",
        "difficulty": "Easy",
        "time_limit": 8,
        "statement": "Given a single word, determine whether it reads the same forward and backward.",
        "input": "One word containing only English letters.",
        "output": "Print YES if it is a palindrome, otherwise print NO.",
        "constraints": "1 <= length <= 100000",
        "tests": [
            {"input": "level\n", "output": "YES\n"},
            {"input": "computer\n", "output": "NO\n"},
            {"input": "a\n", "output": "YES\n"},
        ]
    },
    {
        "id": 3,
        "title": "Frequency Counter",
        "difficulty": "Medium",
        "time_limit": 15,
        "statement": "Given N integers, print the frequency of each distinct value in ascending order.",
        "input": "N followed by N integers.",
        "output": "For each distinct value, print: value frequency, one per line.",
        "constraints": "1 <= N <= 100000",
        "tests": [
            {"input": "7\n4 2 4 3 2 4 3\n", "output": "2 2\n3 2\n4 3\n"},
            {"input": "5\n9 9 9 9 9\n", "output": "9 5\n"},
        ]
    },
    {
        "id": 4,
        "title": "Reverse Linked List",
        "difficulty": "Hard",
        "time_limit": 20,
        "statement": "Read N values, build a singly linked list, reverse it, and print the values.",
        "input": "N followed by N integers.",
        "output": "Print the reversed sequence separated by spaces.",
        "constraints": "1 <= N <= 100000",
        "tests": [
            {"input": "5\n1 2 3 4 5\n", "output": "5 4 3 2 1\n"},
            {"input": "1\n42\n", "output": "42\n"},
        ]
    }
]

(root / "problems.json").write_text(json.dumps(problems, indent=2), encoding="utf-8")

server_py = r'''#!/usr/bin/env python3
import json, os, re, subprocess, tempfile, time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import urlparse

BASE = Path(__file__).resolve().parent
PROBLEMS = json.loads((BASE / "problems.json").read_text())
STATIC = BASE / "static"

def clean_output(s):
    return re.sub(r"\s+", " ", s.strip())

def compile_and_run(code, tests):
    with tempfile.TemporaryDirectory(prefix="cpp_practice_") as d:
        src = Path(d) / "main.cpp"
        exe = Path(d) / "main"
        src.write_text(code, encoding="utf-8")
        cp = subprocess.run(
            ["g++", "-std=c++17", "-O2", "-pipe", str(src), "-o", str(exe)],
            capture_output=True, text=True, timeout=8
        )
        if cp.returncode != 0:
            return {"status":"COMPILE_ERROR", "passed":0, "total":len(tests),
                    "compile_error":cp.stderr[-5000:], "tests":[]}
        results = []
        passed = 0
        for i, t in enumerate(tests, 1):
            started = time.perf_counter()
            try:
                rp = subprocess.run(
                    [str(exe)], input=t["input"], capture_output=True,
                    text=True, timeout=2
                )
                elapsed = time.perf_counter() - started
                if rp.returncode != 0:
                    results.append({"case":i, "status":"RUNTIME_ERROR",
                                    "time":round(elapsed,3),
                                    "error":rp.stderr[-1000:]})
                    continue
                ok = clean_output(rp.stdout) == clean_output(t["output"])
                if ok: passed += 1
                results.append({"case":i, "status":"PASS" if ok else "WRONG_ANSWER",
                                "time":round(elapsed,3)})
            except subprocess.TimeoutExpired:
                results.append({"case":i, "status":"TIME_LIMIT"})
        return {"status":"ACCEPTED" if passed == len(tests) else "FAILED",
                "passed":passed, "total":len(tests), "tests":results}

class Handler(BaseHTTPRequestHandler):
    def send_json(self, obj, status=200):
        data = json.dumps(obj).encode()
        self.send_response(status)
        self.send_header("Content-Type","application/json")
        self.send_header("Content-Length",str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    def do_GET(self):
        path = urlparse(self.path).path
        if path == "/api/problems":
            self.send_json([{
                "id":p["id"], "title":p["title"], "difficulty":p["difficulty"],
                "time_limit":p["time_limit"]
            } for p in PROBLEMS])
            return
        if path == "/api/problem":
            from urllib.parse import parse_qs
            q = parse_qs(urlparse(self.path).query)
            pid = int(q.get("id",[1])[0])
            p = next(x for x in PROBLEMS if x["id"] == pid)
            public = {k:v for k,v in p.items() if k != "tests"}
            self.send_json(public)
            return
        if path == "/" or path == "/index.html":
            data = (STATIC/"index.html").read_bytes()
            self.send_response(200)
            self.send_header("Content-Type","text/html; charset=utf-8")
            self.send_header("Content-Length",str(len(data)))
            self.end_headers()
            self.wfile.write(data)
            return
        self.send_error(404)

    def do_POST(self):
        if urlparse(self.path).path != "/api/submit":
            self.send_error(404); return
        try:
            n = int(self.headers.get("Content-Length","0"))
            body = json.loads(self.rfile.read(n))
            pid = int(body["problem_id"])
            code = body["code"]
            if len(code) > 50000:
                self.send_json({"status":"REJECTED","message":"Code is too large."}, 400)
                return
            p = next(x for x in PROBLEMS if x["id"] == pid)
            self.send_json(compile_and_run(code, p["tests"]))
        except Exception as e:
            self.send_json({"status":"SERVER_ERROR","message":str(e)},500)

    def log_message(self, fmt, *args):
        return

print("C++ Self-Lock running at http://127.0.0.1:8000")
print("Press Ctrl+C to stop.")
ThreadingHTTPServer(("127.0.0.1",8000), Handler).serve_forever()
'''

(root / "server.py").write_text(server_py, encoding="utf-8")

html = r'''<!doctype html>
<html>
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>C++ Self-Lock</title>
<style>
*{box-sizing:border-box}body{margin:0;font-family:system-ui,sans-serif;background:#0b1020;color:#e8edf7}
header{height:58px;padding:14px 22px;border-bottom:1px solid #26304a;display:flex;justify-content:space-between}
.app{display:grid;grid-template-columns:270px 1fr;min-height:calc(100vh - 58px)}
aside{border-right:1px solid #26304a;padding:18px}.main{padding:20px;display:grid;grid-template-columns:40% 60%;gap:18px}
.card{background:#11182b;border:1px solid #26304a;border-radius:12px;padding:18px;margin-bottom:15px}
button,select{background:#1d2a48;color:#fff;border:1px solid #3a4d76;border-radius:8px;padding:9px 12px;cursor:pointer}
button:hover{background:#27395f}.problem{line-height:1.55}.tag{font-size:12px;padding:4px 7px;border-radius:5px;background:#223354;margin-left:8px}
textarea{width:100%;height:58vh;resize:none;background:#080d18;color:#e9eef8;border:1px solid #33415f;border-radius:10px;padding:15px;font:14px/1.5 monospace;outline:none}
.actions{display:flex;gap:10px;align-items:center;margin-top:10px}.timer{font:700 20px monospace}.result{white-space:pre-wrap;font-family:monospace;max-height:220px;overflow:auto}
li{margin:9px 0;cursor:pointer}.selected{color:#8ab4ff;font-weight:700}
.lock{font-size:12px;color:#9fb0cf;line-height:1.5}
</style>
</head>
<body>
<header><b>⚡ C++ Self-Lock</b><span id="timer" class="timer">--:--</span></header>
<div class="app">
<aside>
<div class="card">
<b>Problems</b>
<ul id="problems"></ul>
</div>
<div class="card lock">
<b>Practice rules</b><br><br>
• No browser / Google<br>
• No ChatGPT / AI<br>
• No external copy-paste<br>
• Use only your own reasoning<br>
• Submit when finished
</div>
</aside>
<section class="main">
<div>
<div class="card problem">
<h2 id="title">Select a problem</h2>
<div id="meta"></div>
<p id="statement"></p>
<h4>Input</h4><p id="input"></p>
<h4>Output</h4><p id="output"></p>
<h4>Constraints</h4><p id="constraints"></p>
</div>
<div class="card"><b>Result</b><div id="result" class="result">No submission yet.</div></div>
</div>
<div>
<div class="card">
<textarea id="code" spellcheck="false">// Write your C++17 solution here

#include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}
</textarea>
<div class="actions">
<button onclick="runSubmit()">▶ Submit</button>
<button onclick="resetCode()">↻ Reset</button>
<span id="status"></span>
</div>
</div>
</div>
</section>
</div>
<script>
let current=null, endAt=0, timerId=null;
const code=document.getElementById("code");
async function loadProblems(){
 const ps=await fetch("/api/problems").then(r=>r.json());
 document.getElementById("problems").innerHTML=ps.map(p=>
  `<li onclick="loadProblem(${p.id})" id="p${p.id}">${p.id}. ${p.title}<span class="tag">${p.difficulty}</span></li>`).join("");
 loadProblem(ps[0].id);
}
async function loadProblem(id){
 current=await fetch("/api/problem?id="+id).then(r=>r.json());
 document.querySelectorAll("li").forEach(x=>x.classList.remove("selected"));
 document.getElementById("p"+id).classList.add("selected");
 title.textContent=current.title;
 meta.textContent=current.difficulty+" • "+current.time_limit+" minutes";
 statement.textContent=current.statement; input.textContent=current.input;
 output.textContent=current.output; constraints.textContent=current.constraints;
 result.textContent="No submission yet.";
 endAt=Date.now()+current.time_limit*60000;
 clearInterval(timerId); timerId=setInterval(tick,250); tick();
 resetCode();
}
function tick(){
 let left=Math.max(0,endAt-Date.now()), sec=Math.floor(left/1000);
 timer.textContent=String(Math.floor(sec/60)).padStart(2,"0")+":"+String(sec%60).padStart(2,"0");
 if(left===0){clearInterval(timerId); status.textContent=" Time expired";}
}
function resetCode(){
 code.value=`#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your solution
    return 0;
}`;
 result.textContent="No submission yet.";
}
async function runSubmit(){
 if(!current) return;
 status.textContent=" Judging...";
 const r=await fetch("/api/submit",{method:"POST",headers:{"Content-Type":"application/json"},
 body:JSON.stringify({problem_id:current.id,code:code.value})});
 const x=await r.json();
 if(x.status==="COMPILE_ERROR"){
   result.textContent="COMPILE ERROR\n\n"+x.compile_error;
 } else {
   result.textContent=`${x.status}\nPassed: ${x.passed}/${x.total}\n\n`+
     x.tests.map(t=>`Test ${t.case}: ${t.status}${t.time!==undefined?" ("+t.time+"s)":""}`).join("\n");
 }
 status.textContent="";
}
loadProblems();
</script>
</body>
</html>

'''
(root / "static/index.html").write_text(html, encoding="utf-8")

# readme = """# C++ Self-Lock

# A local, offline-friendly C++ practice environment.

# ## Requirements

# Ubuntu/Linux with:
# - Python 3
# - g++
# - A normal browser

# Check:
# ```bash
# python3 --version
# g++ --version