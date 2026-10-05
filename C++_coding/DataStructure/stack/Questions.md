# C++ Comprehensive Problem Set: **Stack + Classes**

Since you already know the **basics of OOP**, these problems focus on applying **classes + stack + pointers + dynamic memory + problem-solving** together.

**Total: 12 Problems**

* 🟢 2 Easy
* 🟡 3 Medium
* 🔴 4 Hard
* 🟣 3 Difficult / Interview Level

No code solutions, only **problem statements, inputs, outputs, examples, edge cases, hints, and expected complexity**.

---

# 🟢 EASY

## Problem 1: Browser Back Button [EASY]

**Statement:**
A web browser stores the pages visited by a user. When the user presses the **Back** button, the browser should return to the most recently visited page that has not already been removed.

Use a `Stack` class to implement this behavior.

Operations:

* `VISIT page`
* `BACK`
* `CURRENT`

**Input:**

First line: number of operations `Q`.

Constraints:

* `1 ≤ Q ≤ 10^5`
* Page names contain only English letters.

**Output:**

For `CURRENT`, print the current page.

For `BACK`, print the page returned to.

If no previous page exists:

```text
No previous page
```

**Example 1:**

```text
Input:
VISIT Google
VISIT YouTube
VISIT GitHub
BACK
CURRENT

Output:
YouTube
Google
```

**Explanation:**
The stack contains previously visited pages. `GitHub` is removed first because it is the most recent page.

**Example 2:**

```text
Input:
VISIT Google
BACK

Output:
No previous page
```

**Edge Cases:**

* No pages visited.
* Only one page.
* Multiple consecutive `BACK` operations.
* Back operation after reaching the first page.

**Hints:**

* Create a `Stack` class.
* Store page names inside stack nodes.
* The top represents the most recently visited page.

**Expected Time Complexity:**

* `VISIT`: `O(1)`
* `BACK`: `O(1)`
* `CURRENT`: `O(1)`

---

# Problem 2: Stack-Based Plate Manager [EASY]

**Statement:**
A restaurant stores plates in a vertical stack. A plate can only be removed from the top.

Each plate has:

* Plate ID
* Plate type

Implement:

* `PUSH`
* `POP`
* `TOP`
* `SIZE`

Use a `Plate` class and a `Stack` class.

**Input:**

```text
PUSH id type
POP
TOP
SIZE
```

Constraints:

* `1 ≤ Q ≤ 10^5`
* Plate ID is positive.

**Example:**

```text
Input:
PUSH 101 Dinner
PUSH 102 Dessert
TOP
POP
SIZE

Output:
102 Dessert
102 Dessert
1
```

**Edge Cases:**

* Pop from an empty stack.
* Top on an empty stack.
* One plate.
* Many plates.
* Repeated IDs.

**Hints:**

* The newest plate should always become the top.
* A linked-list implementation can make push and pop `O(1)`.

**Expected Time Complexity:**

* Push: `O(1)`
* Pop: `O(1)`
* Top: `O(1)`
* Size: `O(1)` if maintained.

---

# 🟡 MEDIUM

## Problem 3: Undo Operation in a Text Editor [MEDIUM]

**Statement:**
A text editor supports an **Undo** operation.

Every time the user performs an action such as:

* `TYPE character`
* `DELETE character`

the action is stored in a stack.

When `UNDO` is called, the most recent action should be reversed.

Create suitable classes to model the actions and stack.

**Input:**

```text
TYPE A
TYPE B
DELETE B
UNDO
UNDO
```

**Example:**

```text
Input:
TYPE A
TYPE B
TYPE C
UNDO
UNDO
PRINT

Output:
A
```

**Explanation:**
The operations are:

```text
A
AB
ABC
AB
A
```

**Edge Cases:**

* Undo when there are no actions.
* Multiple consecutive undos.
* Undoing a deletion.
* Empty text.

**Hints:**

* Store an action object in the stack.
* An action should contain enough information to reverse itself.
* Think about how `TYPE` and `DELETE` differ.

**Expected Time Complexity:**

* Action: `O(1)`
* Undo: `O(1)`

---

## Problem 4: Balanced Parentheses Checker [MEDIUM]

**Statement:**
A compiler needs to verify whether brackets in an expression are correctly balanced.

Supported brackets:

```text
()
[]
{}
```

Use a stack implemented through a class.

**Input:**

* One string containing brackets and other characters.
* `1 ≤ N ≤ 10^5`

**Output:**

Print:

```text
Balanced
```

or

```text
Not Balanced
```

**Examples:**

```text
Input:
{[()]}

Output:
Balanced
```

```text
Input:
{[(])}

Output:
Not Balanced
```

**Explanation:**
The closing bracket `]` does not match the most recent opening bracket `(`.

**Edge Cases:**

* Empty expression.
* Only opening brackets.
* Only closing brackets.
* Nested brackets.
* Multiple independent bracket groups.
* Characters other than brackets.

**Hints:**

* Push every opening bracket.
* When a closing bracket appears, compare it with the stack's top.
* The stack must be empty at the end.

**Expected Time Complexity:** `O(N)`

**Extra Space:** `O(N)`

---

## Problem 5: Calculator Using Stack [MEDIUM]

**Statement:**
Build a calculator that evaluates a postfix expression using a stack.

Example:

```text
5 3 + 2 *
```

means:

```text
(5 + 3) × 2 = 16
```

Use a `Stack` class to store operands.

Supported operators:

```text
+ - * /
```

**Input:**

* A valid postfix expression.
* `1 ≤ N ≤ 10^5`

**Example 1:**

```text
Input:
5 3 + 2 *

Output:
16
```

**Example 2:**

```text
Input:
10 2 / 3 +

Output:
8
```

**Edge Cases:**

* Division by zero.
* Negative numbers.
* Single operand.
* Large expression.
* Integer division.

**Hints:**

* Number → push onto stack.
* Operator → pop required operands.
* Perform operation.
* Push result back.

**Expected Time Complexity:** `O(N)`

---

# 🔴 HARD

## Problem 6: Call Stack Simulator [HARD]

**Statement:**
You are building a simplified simulator of function calls.

Whenever a function is called, it is pushed onto the call stack.

When a function returns, it is popped.

Each function contains:

* Function name
* Function ID
* Local variable count

Implement:

```text
CALL id name variables
RETURN
CURRENT
DISPLAY_STACK
```

**Example:**

```text
Input:
CALL 1 main 3
CALL 2 calculate 5
CALL 3 print 2
CURRENT
RETURN
CURRENT

Output:
3 print
2 calculate
```

**Edge Cases:**

* Return when stack is empty.
* Only one function.
* Deep recursion.
* Multiple returns.

**Hints:**
The top of the stack represents the currently executing function.

**Expected Time Complexity:**

* CALL: `O(1)`
* RETURN: `O(1)`
* CURRENT: `O(1)`
* Display: `O(N)`

---

## Problem 7: Min Stack [HARD]

**Statement:**
Design a stack that supports normal stack operations plus retrieving the **minimum element in O(1)** time.

Operations:

```text
PUSH x
POP
TOP
GET_MIN
```

**Example:**

```text
Input:
PUSH 5
PUSH 3
PUSH 7
GET_MIN
POP
GET_MIN

Output:
3
3
```

**Explanation:**
Initially:

```text
5
3 ← minimum
7
```

After removing `7`, minimum is still `3`.

**Edge Cases:**

* Empty stack.
* Duplicate minimum values.
* Negative values.
* Minimum element is popped.
* One element.

**Hints:**
You need more information than just the normal stack.

Consider maintaining:

```text
Main Stack
Minimum Stack
```

**Expected Time Complexity:**

* Push: `O(1)`
* Pop: `O(1)`
* Get minimum: `O(1)`

---

## Problem 8: Browser History with Forward and Back [HARD]

**Statement:**
Build a browser history system supporting:

* `VISIT page`
* `BACK`
* `FORWARD`
* `CURRENT`

Use **two stacks**.

Example:

```text
Google → YouTube → GitHub
```

After:

```text
BACK
```

current page becomes:

```text
YouTube
```

Then:

```text
FORWARD
```

returns to:

```text
GitHub
```

**Important Rule:**
If the user visits a new page after going back, the forward history must be cleared.

**Example:**

```text
VISIT A
VISIT B
VISIT C
BACK
VISIT D
FORWARD
```

`FORWARD` should not return to `C`.

**Edge Cases:**

* Back at first page.
* Forward at latest page.
* Visit after back.
* Empty history.
* Repeated back/forward.

**Hints:**
Maintain:

```text
Back Stack
Forward Stack
```

When visiting a new page, think carefully about what happens to the forward stack.

**Expected Time Complexity:**

* Visit: `O(1)`
* Back: `O(1)`
* Forward: `O(1)`

---

## Problem 9: Expression Conversion [HARD]

**Statement:**
A compiler receives mathematical expressions in **infix notation**:

```text
A + B * C
```

Convert them into **postfix notation**:

```text
A B C * +
```

Use a stack to handle operators and precedence.

Support:

```text
+
-
*
/
^
()
```

**Examples:**

```text
Input:
A+B*C

Output:
ABC*+
```

```text
Input:
(A+B)*C

Output:
AB+C*
```

**Edge Cases:**

* Nested parentheses.
* Multiple operators.
* Operator precedence.
* Spaces.
* Single operand.
* Expressions containing `^`.

**Hints:**
You need to define precedence:

```text
^
*
/
+
-
```

When an operator arrives, compare its precedence with the operator on the stack.

**Expected Time Complexity:** `O(N)`

---

# 🟣 DIFFICULT / INTERVIEW LEVEL

## Problem 10: Stock Span Problem [DIFFICULT]

**Statement:**
A financial application receives daily stock prices.

For every day, calculate the number of consecutive days ending today for which the stock price was **less than or equal to today's price**.

Example:

```text
Prices:
100 80 60 70 60 75 85
```

Output:

```text
1 1 1 2 1 4 6
```

Use a stack-based approach.

**Constraints:**

* `1 ≤ N ≤ 10^6`
* `0 ≤ price ≤ 10^9`

**Edge Cases:**

* Increasing prices.
* Decreasing prices.
* All prices equal.
* One price.
* Very large `N`.

**Hints:**
Instead of checking previous days one by one, maintain a stack of useful previous indices.

When today's price is greater than the price represented by the stack top, those previous days can be removed.

**Expected Time Complexity:** `O(N)`

This is an important interview pattern because every element is pushed and popped at most once.

---

## Problem 11: Largest Rectangle in Histogram [DIFFICULT]

**Statement:**
A data-visualization system represents values as vertical bars.

Given the heights of bars, find the largest possible rectangular area formed using consecutive bars.

Example:

```text
Heights:
2 1 5 6 2 3
```

Output:

```text
10
```

Because bars `5` and `6` form a rectangle with:

```text
height = 5
width = 2
area = 10
```

**Constraints:**

* `1 ≤ N ≤ 10^6`
* `0 ≤ height ≤ 10^9`

**Edge Cases:**

* One bar.
* All bars equal.
* Increasing heights.
* Decreasing heights.
* Zero-height bars.
* Very large values.

**Hints:**
Use a **monotonic stack**.

The stack should help you determine when a bar's possible rectangle ends.

For every bar, think about:

```text
Nearest smaller element on the left
Nearest smaller element on the right
```

**Expected Time Complexity:** `O(N)`

---

## Problem 12: Undo/Redo System [DIFFICULT]

**Statement:**
Design an editor that supports both **Undo** and **Redo**.

Operations:

```text
TYPE text
UNDO
REDO
PRINT
```

Rules:

1. Every new action is added to the undo history.
2. `UNDO` moves the latest action to the redo history.
3. `REDO` moves the latest undone action back to the undo history.
4. If a new action is performed after `UNDO`, the redo history must be cleared.

Use classes and two stacks.

**Example:**

```text
Input:
TYPE A
TYPE B
TYPE C
UNDO
UNDO
REDO
PRINT
```

Output:

```text
AB
```

**Explanation:**

```text
TYPE A → A
TYPE B → AB
TYPE C → ABC

UNDO → AB
UNDO → A

REDO → AB
```

Final text:

```text
AB
```

**Example 2:**

```text
TYPE A
TYPE B
UNDO
TYPE C
REDO
PRINT
```

Output:

```text
AC
```

`REDO` does nothing because a new action `TYPE C` cleared the redo history.

**Edge Cases:**

* Undo on empty history.
* Redo on empty history.
* Multiple undos.
* Multiple redos.
* New action after undo.
* Undo everything.
* Redo everything.
* Empty text.

**Hints:**
Use two stacks:

```text
Undo Stack
Redo Stack
```

Think of every user operation as an object containing enough information to reverse and reapply it.

The most important rule is:

> **A new action after an UNDO clears the REDO stack.**

**Expected Time Complexity:**

* TYPE: `O(1)` excluding text-copy cost
* UNDO: `O(1)` excluding text manipulation
* REDO: `O(1)` excluding text manipulation

---

# 📊 Concept Progression

| #  | Problem              | Level     | Main Concepts                 |
| -- | -------------------- | --------- | ----------------------------- |
| 1  | Browser Back         | Easy      | Class + Stack                 |
| 2  | Plate Manager        | Easy      | Class + Linked Stack          |
| 3  | Text Editor Undo     | Medium    | Stack + Objects               |
| 4  | Balanced Parentheses | Medium    | Stack + Strings               |
| 5  | Postfix Calculator   | Medium    | Stack + Expression Evaluation |
| 6  | Call Stack Simulator | Hard      | Stack + Classes               |
| 7  | Min Stack            | Hard      | Multiple Stacks               |
| 8  | Browser History      | Hard      | Two Stacks                    |
| 9  | Infix → Postfix      | Hard      | Stack + Operator Precedence   |
| 10 | Stock Span           | Difficult | Monotonic Stack               |
| 11 | Histogram            | Difficult | Monotonic Stack               |
| 12 | Undo/Redo            | Difficult | OOP + Two Stacks              |

### Recommended solving order

**1 → 2 → 3 → 4 → 5 → 6 → 8 → 7 → 9 → 10 → 12 → 11**

For interview preparation, pay special attention to **7, 9, 10, 11, and 12**. Those problems move beyond simply implementing `push()` and `pop()` and test whether you can recognize **stack-based algorithmic patterns**.

Perfect! Here are **Stack problems** organized by difficulty with multiple test cases (LeetCode style):

---

# **EASY PROBLEMS**

## **Problem E1: Valid Parentheses**

Check if parentheses are balanced in an expression.

**Problem:** Given a string with parentheses `()`, `{}`, `[]`, determine if they are properly matched.

**Input:** A string with mixed parentheses

**Output:** `true` if valid, `false` if invalid

**Test Cases:**

```
Test 1:
Input: "()"
Output: true

Test 2:
Input: "()[]{}"
Output: true

Test 3:
Input: "(]"
Output: false

Test 4:
Input: "([{}])"
Output: true

Test 5:
Input: "({[}])"
Output: false

Test 6:
Input: ""
Output: true

Test 7:
Input: "((("
Output: false
```

**Constraints:** 1 ≤ length ≤ 10^4

**Hint:** Use a stack. For opening brackets, push. For closing brackets, check if it matches the top.

---

## **Problem E2: Reverse a String using Stack**

Reverse a string using a stack data structure.

**Problem:** Given a string, use a stack to reverse it.

**Input:** A string

**Output:** Reversed string

**Test Cases:**

```
Test 1:
Input: "hello"
Output: "olleh"

Test 2:
Input: "abc"
Output: "cba"

Test 3:
Input: "a"
Output: "a"

Test 4:
Input: "12345"
Output: "54321"

Test 5:
Input: "racecar"
Output: "racecar"

Test 6:
Input: ""
Output: ""
```

**Constraints:** 1 ≤ length ≤ 10^5

**Hint:** Push each character to stack, then pop all to get reverse.

---

## **Problem E3: Decimal to Binary using Stack**

Convert a decimal number to binary using stack.

**Problem:** Given a decimal number, convert it to binary representation using a stack.

**Input:** A decimal number

**Output:** Binary representation as string

**Test Cases:**

```
Test 1:
Input: 5
Output: "101"

Test 2:
Input: 10
Output: "1010"

Test 3:
Input: 1
Output: "1"

Test 4:
Input: 16
Output: "10000"

Test 5:
Input: 255
Output: "11111111"

Test 6:
Input: 0
Output: "0"
```

**Constraints:** 0 ≤ n ≤ 10^9

**Hint:** Repeatedly divide by 2, push remainders, pop to build binary.

---

## **Problem E4: Balanced Brackets in Expression**

Check if brackets are balanced considering nesting depth.

**Problem:** Determine if all brackets in an expression are properly balanced and nested.

**Input:** String with brackets and other characters

**Output:** `true` if balanced, `false` otherwise

**Test Cases:**

```
Test 1:
Input: "{[()]}"
Output: true

Test 2:
Input: "{[(])}"
Output: false

Test 3:
Input: "abc{def[ghi]jkl}mno"
Output: true

Test 4:
Input: "[[["
Output: false

Test 5:
Input: "{}"
Output: true

Test 6:
Input: "{"
Output: false
```

**Constraints:** 1 ≤ length ≤ 10^4

**Hint:** Match opening and closing brackets on stack.

---

## **Problem E5: Remove Adjacent Duplicates**

Remove all adjacent duplicate characters from a string.

**Problem:** Given a string, remove all adjacent duplicates.

**Input:** A string

**Output:** String with adjacent duplicates removed

**Test Cases:**

```
Test 1:
Input: "abbaca"
Output: "ca"

Test 2:
Input: "aa"
Output: ""

Test 3:
Input: "abc"
Output: "abc"

Test 4:
Input: "aabbcc"
Output: ""

Test 5:
Input: "azxxzy"
Output: "ay"

Test 6:
Input: "a"
Output: "a"
```

**Constraints:** 1 ≤ length ≤ 10^5

**Hint:** Push to stack if different, pop if same as top.

---

## **Problem E6: Next Greater Element**

Find the next greater element for each element in array.

**Problem:** Given array, for each element find the nearest greater element to the right. If none, return -1.

**Input:** Array of integers

**Output:** Array of next greater elements

**Test Cases:**

```
Test 1:
Input: [1, 5, 0, 3, 4, 5]
Output: [5, -1, 3, 4, 5, -1]

Test 2:
Input: [1, 2, 3, 4]
Output: [2, 3, 4, -1]

Test 3:
Input: [4, 3, 2, 1]
Output: [-1, -1, -1, -1]

Test 4:
Input: [5, 4, 3, 2, 1]
Output: [-1, -1, -1, -1, -1]

Test 5:
Input: [1]
Output: [-1]

Test 6:
Input: [2, 1, 3, 4, 2]
Output: [3, 3, 4, -1, -1]
```

**Constraints:** 1 ≤ n ≤ 10^4

**Hint:** Traverse from right, use stack to maintain decreasing elements.

---

## **Problem E7: Check if Number is Palindrome using Stack**

Check if a number is palindrome using stack.

**Problem:** Given a number, check if it's a palindrome using stack.

**Input:** A positive integer

**Output:** `true` if palindrome, `false` otherwise

**Test Cases:**

```
Test 1:
Input: 121
Output: true

Test 2:
Input: 123
Output: false

Test 3:
Input: 1001
Output: true

Test 4:
Input: 1
Output: true

Test 5:
Input: 12321
Output: true

Test 6:
Input: 1234
Output: false
```

**Constraints:** 0 ≤ n ≤ 10^9

**Hint:** Push all digits to stack, compare with original.

---

---

# **MEDIUM PROBLEMS**

## **Problem M1: Evaluate Postfix Expression**

Evaluate an expression written in postfix notation.

**Problem:** Given a postfix expression (Reverse Polish Notation), evaluate its result.

**Input:** Postfix expression as array of strings/numbers

**Output:** Integer result

**Test Cases:**

```
Test 1:
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: (2 + 1) * 3 = 9

Test 2:
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: 4 + 13/5 = 6 (integer division)

Test 3:
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22

Test 4:
Input: ["3", "4", "+"]
Output: 7

Test 5:
Input: ["15"]
Output: 15

Test 6:
Input: ["6", "2", "/"]
Output: 3
```

**Constraints:** Valid postfix expression with +, -, *, / operators

**Hint:** Push numbers, pop when seeing operator, calculate and push result.

---

## **Problem M2: Largest Rectangle in Histogram**

Find the largest rectangle area in a histogram.

**Problem:** Given heights of bars in a histogram, find the largest rectangular area that can be formed.

**Input:** Array of integers representing heights

**Output:** Integer (maximum area)

**Test Cases:**

```
Test 1:
Input: [2, 1, 5, 6, 2, 3]
Output: 10
Explanation: Rectangle with height 5 and width 2 = 10

Test 2:
Input: [2, 4]
Output: 4

Test 3:
Input: [0, 0, 0]
Output: 0

Test 4:
Input: [1, 2, 3, 4, 5]
Output: 9
Explanation: Rectangle with height 3 and width 3

Test 5:
Input: [5, 4, 3, 2, 1]
Output: 9

Test 6:
Input: [1]
Output: 1
```

**Constraints:** 1 ≤ n ≤ 10^4, 0 ≤ heights ≤ 10^5

**Hint:** Use stack to keep track of increasing heights, pop when height decreases.

---

## **Problem M3: Validate Stack Sequences**

Check if a push-pop sequence is valid.

**Problem:** Given pushed sequence and a popped sequence, verify if it's valid (output order matches push-pop operations).

**Input:** Two arrays - pushed and popped

**Output:** `true` if valid, `false` otherwise

**Test Cases:**

```
Test 1:
Input: pushed = [1,2,3], popped = [1,3,2]
Output: false

Test 2:
Input: pushed = [1,2,3], popped = [1,2,3]
Output: true

Test 3:
Input: pushed = [1,0], popped = [1,0]
Output: true

Test 4:
Input: pushed = [1,2], popped = [2,1]
Output: true

Test 5:
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true

Test 6:
Input: pushed = [1,2,3], popped = [3,1,2]
Output: false
```

**Constraints:** 1 ≤ n ≤ 100

**Hint:** Simulate push-pop operations, check if popped sequence matches.

---

## **Problem M4: Infix to Postfix Conversion**

Convert infix expression to postfix notation.

**Problem:** Given an infix expression, convert it to postfix notation.

**Input:** Infix expression as string (with operators +, -, *, /, and parentheses)

**Output:** Postfix expression as string

**Test Cases:**

```
Test 1:
Input: "a+b*c"
Output: "abc*+"

Test 2:
Input: "(a+b)*c"
Output: "ab+c*"

Test 3:
Input: "a+b+c"
Output: "ab+c+"

Test 4:
Input: "(a+b)*(c+d)"
Output: "ab+cd+*"

Test 5:
Input: "a*b+c*d"
Output: "ab*cd*+"

Test 6:
Input: "a"
Output: "a"
```

**Constraints:** Valid infix expression with single character operands

**Hint:** Use operator precedence, push operators to stack, pop based on precedence.

---

## **Problem M5: Minimum Stack**

Implement stack with O(1) getMin() operation.

**Problem:** Design a stack that supports push, pop, top, and getMin operations in O(1) time.

**Input:** Series of operations

**Output:** Results of operations

**Test Cases:**

```
Test 1:
push(2)
push(0)
push(3)
getMin() -> Output: 0
pop()
getMin() -> Output: 0
pop()
getMin() -> Output: 2

Test 2:
push(1)
getMin() -> Output: 1
push(2)
getMin() -> Output: 1
push(0)
getMin() -> Output: 0

Test 3:
push(5)
push(3)
push(7)
getMin() -> Output: 3
pop()
getMin() -> Output: 3
pop()
getMin() -> Output: 5
```

**Constraints:** Multiple operations, values up to 10^9

**Hint:** Use two stacks - one for data, one for min values.

---

## **Problem M6: Remove K Digits**

Remove K digits to get smallest number.

**Problem:** Given a string of digits, remove K digits to get the smallest possible number.

**Input:** String of digits and K (number to remove)

**Output:** Smallest number as string

**Test Cases:**

```
Test 1:
Input: num = "1432219", k = 3
Output: "1219"

Test 2:
Input: num = "10200", k = 1
Output: "200"

Test 3:
Input: num = "10", k = 2
Output: "0"

Test 4:
Input: num = "112", k = 1
Output: "11"

Test 5:
Input: num = "9", k = 1
Output: "0"

Test 6:
Input: num = "1123456", k = 3
Output: "1123"
```

**Constraints:** 1 ≤ length ≤ 10^4, k < length

**Hint:** Use stack to maintain increasing digits, remove larger digits when possible.

---

## **Problem M7: Daily Temperatures**

Find days until warmer temperature.

**Problem:** Given array of daily temperatures, output for each day the number of days until warmer temperature.

**Input:** Array of integers (temperatures)

**Output:** Array of integers (days until warmer)

**Test Cases:**

```
Test 1:
Input: [73, 74, 75, 71, 69, 72, 76, 73]
Output: [1, 1, 4, 2, 1, 1, 0, 0]

Test 2:
Input: [30, 40, 50, 60]
Output: [1, 1, 1, 0]

Test 3:
Input: [30, 60, 90]
Output: [1, 1, 0]

Test 4:
Input: [89, 62, 70, 58, 47, 47, 46, 76, 100, 70]
Output: [8, 1, 5, 4, 3, 3, 1, 2, 0, 0]

Test 5:
Input: [50]
Output: [0]

Test 6:
Input: [100, 99, 98, 97]
Output: [0, 0, 0, 0]
```

**Constraints:** 1 ≤ n ≤ 10^5, 30 ≤ temp ≤ 100

**Hint:** Use stack with indices, pop when finding warmer day.

---

---

# **HARD PROBLEMS**

## **Problem H1: Trapping Rain Water**

Calculate water trapped between elevation map.

**Problem:** Given an elevation map, calculate how much water can be trapped after raining.

**Input:** Array of integers representing elevation

**Output:** Integer (units of water trapped)

**Test Cases:**

```
Test 1:
Input: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6

Test 2:
Input: [4, 2, 0, 3, 2, 5]
Output: 9

Test 3:
Input: [0, 0, 0]
Output: 0

Test 4:
Input: [3, 0, 2, 0, 4]
Output: 7

Test 5:
Input: [1, 2, 3]
Output: 0

Test 6:
Input: [5, 4, 3, 2, 1]
Output: 0
```

**Constraints:** 1 ≤ n ≤ 10^4

**Hint:** Use stack to track bars, calculate water between bars.

---

## **Problem H2: Maximal Rectangle**

Find largest rectangle in binary matrix.

**Problem:** Given a 2D binary matrix, find the largest rectangle containing only 1s.

**Input:** 2D array with 0s and 1s

**Output:** Integer (maximum area)

**Test Cases:**

```
Test 1:
Input: [
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

Test 2:
Input: [["0"]]
Output: 0

Test 3:
Input: [["1"]]
Output: 1

Test 4:
Input: [
  ["1","1"],
  ["1","1"]
]
Output: 4

Test 5:
Input: [
  ["1","0"],
  ["1","0"]
]
Output: 1

Test 6:
Input: [
  ["1","1","1","1","1"],
  ["0","1","1","1","0"]
]
Output: 4
```

**Constraints:** m, n ≤ 200

**Hint:** Convert each row to histogram problem, use largestRectangleArea.

---

## **Problem H3: Online Stock Span**

Calculate span of stock prices.

**Problem:** Price of a stock on each day, span = number of consecutive days before current day where price ≤ current price.

**Input:** Series of prices

**Output:** Span for each price

**Test Cases:**

```
Test 1:
Prices: [100, 80, 60, 70, 60, 75, 85]
Spans: [1, 1, 1, 2, 1, 4, 6]

Test 2:
Prices: [100, 100, 100]
Spans: [1, 2, 3]

Test 3:
Prices: [1]
Spans: [1]

Test 4:
Prices: [5, 4, 3, 2, 1]
Spans: [1, 1, 1, 1, 1]

Test 5:
Prices: [1, 2, 3, 4, 5]
Spans: [1, 2, 3, 4, 5]

Test 6:
Prices: [87, 34, 37, 23, 48, 97, 50, 13]
Spans: [1, 1, 2, 1, 2, 5, 1, 1]
```

**Constraints:** n ≤ 10^4, price ≤ 10^5

**Hint:** Use monotonic stack with indices to find previous smaller element.

---

## **Problem H4: Largest Rectangle in Skyline**

Find largest rectangle under skyline.

**Problem:** Buildings have different heights, find largest rectangle that can fit under the skyline.

**Input:** Array of building heights

**Output:** Integer (maximum rectangle area)

**Test Cases:**

```
Test 1:
Input: [2, 1, 5, 6, 2, 3]
Output: 10

Test 2:
Input: [1, 1]
Output: 2

Test 3:
Input: [0, 9]
Output: 9

Test 4:
Input: [5, 4, 3, 2, 1]
Output: 9

Test 5:
Input: [1, 2, 3, 4, 5]
Output: 9

Test 6:
Input: [2, 2, 2, 2, 2]
Output: 10
```

**Constraints:** 1 ≤ n ≤ 10^4

**Hint:** Similar to largest rectangle in histogram.

---

## **Problem H5: Parse Nested List Integer Sum**

Sum all integers in nested list.

**Problem:** Given a nested list of integers and lists, find sum of all integers.

**Input:** Nested list structure

**Output:** Integer (total sum)

**Test Cases:**

```
Test 1:
Input: [[1,1],2,[1,1]]
Output: 6

Test 2:
Input: [1,[4,[6]]]
Output: 11

Test 3:
Input: [1,2,3]
Output: 6

Test 4:
Input: [[]]
Output: 0

Test 5:
Input: [[[1]]]
Output: 1

Test 6:
Input: [1,[2,[3,[4]]]]
Output: 10
```

**Constraints:** Depth ≤ 50

**Hint:** Use stack to track depth and sum values at each level.

---

## **Problem H6: Remove Duplicate Letters**

Remove duplicate letters keeping lexicographic order.

**Problem:** Remove duplicate characters while keeping smallest lexicographic result and maintaining order.

**Input:** String with duplicate characters

**Output:** String with unique characters in smallest lexicographic order

**Test Cases:**

```
Test 1:
Input: "bcabc"
Output: "abc"

Test 2:
Input: "cbacdcbc"
Output: "acdb"

Test 3:
Input: "ecbacba"
Output: "eacb"

Test 4:
Input: "a"
Output: "a"

Test 5:
Input: "bac"
Output: "abc"

Test 6:
Input: "ecdba"
Output: "ecdba"
```

**Constraints:** 1 ≤ length ≤ 10^4

**Hint:** Use stack with character frequencies, pop if current is smaller and char appears later.

---

## **Problem H7: Brace Expansion**

Generate all strings from brace expansion.

**Problem:** Given a string with braces like "a{b,c}d", expand all possibilities.

**Input:** String with braces

**Output:** Sorted list of expanded strings

**Test Cases:**

```
Test 1:
Input: "{a,b}{c,d}"
Output: ["ac", "ad", "bc", "bd"]

Test 2:
Input: "{a,b,c}"
Output: ["a", "b", "c"]

Test 3:
Input: "a{b,c}d"
Output: ["abd", "acd"]

Test 4:
Input: "{a{b,c}}"
Output: ["a{b", "a{c"]

Test 5:
Input: "ab"
Output: ["ab"]

Test 6:
Input: "{a,{b,c}}"
Output: ["a", "{b", "{c"]
```

**Constraints:** 1 ≤ length ≤ 50

**Hint:** Use stack to track braces, build combinations recursively.

---

---

## **Quick Reference:**

| Difficulty | Focus |
|-----------|-------|
| **Easy** | Basic stack operations, simple patterns |
| **Medium** | Operators, sequences, optimization |
| **Hard** | Complex patterns, nested structures, multi-dimensional |

---

**Start with which one? Or share your solution?** 💻
