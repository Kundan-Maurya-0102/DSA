#include<stack>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main(){
    stack<string>st1;
    st1.push("Google");
    st1.push("Youtube");
    st1.push("Instagram");
    st1.pop();
    while(!st1.empty()){
        string t = st1.top();
        cout << t << endl;
        st1.pop();
    }
    return 0;
}