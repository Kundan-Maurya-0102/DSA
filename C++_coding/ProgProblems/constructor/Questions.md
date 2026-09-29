# C++ Comprehensive Problem Set: **Pointers**

**Total: 12 Problems**
**Difficulty:** 2 Easy → 3 Medium → 4 Hard → 3 Difficult
**Focus:** Pointers, pointer arithmetic, arrays, strings, dynamic memory, functions, structures, linked lists, and interview-style problem solving.

---

## 🟢 EASY

### Problem 1: Swap Two Bank Account Balances [EASY]

**Statement:**
A banking application stores the balances of two accounts. You need to swap their balances without using a third variable.

Write a program that receives two integer balances and swaps them using **pointers**.

**Input:**

* Two integers `A` and `B`.
* Constraints:

  * `-10^9 ≤ A, B ≤ 10^9`

**Output:**

* Print the values after swapping.

**Examples:**

**Example 1**

```text
Input:
5000 8000

Output:
8000 5000
```

**Explanation:**
Account A originally has ₹5000 and B has ₹8000. After swapping, A has ₹8000 and B has ₹5000.

**Example 2**

```text
Input:
100 100

Output:
100 100
```

**Explanation:**
Both balances are already equal.

**Edge Cases:**

* Both values are equal.
* One value is `0`.
* Negative values.
* Maximum/minimum allowed integer values.

**Hints:**

* Create two integer variables.
* Pass their addresses to a function.
* Modify the values through dereferenced pointers.
* Avoid using a third variable.

**Time Complexity Expected:** `O(1)`

---

### Problem 2: Find Maximum Sensor Reading [EASY]

**Statement:**
An IoT device records temperature readings throughout the day. The readings are stored in an array.

Find the maximum temperature using **pointer traversal** instead of array indexing.

**Input:**

* First line: integer `N`.
* Second line: `N` integers representing temperature readings.
* Constraints:

  * `1 ≤ N ≤ 10^5`
  * `-1000 ≤ reading ≤ 1000`

**Output:**

* Print the maximum reading.

**Examples:**

**Example 1**

```text
Input:
5
32 35 29 41 37

Output:
41
```

**Example 2**

```text
Input:
4
-10 -5 -20 -3

Output:
-3
```

**Explanation:**
The program should traverse the array using a pointer and keep track of the largest value.

**Edge Cases:**

* `N = 1`.
* All values are negative.
* All values are identical.
* Maximum value occurs at the first or last position.

**Hints:**

* A pointer can point to the first array element.
* Move the pointer forward using pointer arithmetic.
* Keep one variable for the current maximum.

**Time Complexity Expected:** `O(N)`

---

# 🟡 MEDIUM

### Problem 3: Reverse Customer Name [MEDIUM]

**Statement:**
A customer-management system stores a customer's name as a character array.

Reverse the string **in-place using pointers**. You are not allowed to create another character array for the reversed string.

**Input:**

* A single string.
* Constraints:

  * Length: `1 ≤ N ≤ 10^5`
  * String may contain uppercase/lowercase English letters and spaces.

**Output:**

* Print the reversed string.

**Examples:**

**Example 1**

```text
Input:
Kundan

Output:
nadnuK
```

**Example 2**

```text
Input:
Hello World

Output:
dlroW olleH
```

**Explanation:**
Use one pointer at the beginning and another at the end. Swap characters while the pointers move toward each other.

**Edge Cases:**

* Single-character string.
* Empty string, if allowed by the implementation.
* String containing spaces.
* Palindrome.
* Repeated characters.

**Hints:**

* Find the end of the character array.
* Maintain two pointers.
* Swap the characters pointed to by them.
* Move one pointer forward and the other backward.

**Time Complexity Expected:** `O(N)`
**Extra Space:** `O(1)`

---

### Problem 4: Dynamic Student Marks Analyzer [MEDIUM]

**Statement:**
A college system does not know the number of students until runtime.

Dynamically allocate memory for `N` students' marks and calculate:

1. Average marks
2. Highest marks
3. Lowest marks

The solution must use **dynamic memory and pointers**.

**Input:**

* First line: `N`
* Second line: `N` integer marks.
* Constraints:

  * `1 ≤ N ≤ 10^6`
  * `0 ≤ marks ≤ 100`

**Output:**
Print:

```text
Average: X
Highest: Y
Lowest: Z
```

**Examples:**

**Example 1**

```text
Input:
5
70 80 90 60 100

Output:
Average: 80
Highest: 100
Lowest: 60
```

**Example 2**

```text
Input:
3
50 50 50

Output:
Average: 50
Highest: 50
Lowest: 50
```

**Edge Cases:**

* `N = 1`.
* All marks equal.
* All marks are `0`.
* All marks are `100`.
* Very large `N`.
* Correctly releasing dynamically allocated memory.

**Hints:**

* Allocate an integer array dynamically.
* Use a pointer to traverse it.
* Maintain `sum`, `maximum`, and `minimum`.
* Remember to release the allocated memory.

**Time Complexity Expected:** `O(N)`
**Extra Space:** `O(N)`

---

### Problem 5: Calculator Using Function Pointers [MEDIUM]

**Statement:**
You are developing a calculator where the operation is selected at runtime.

Supported operations:

* Addition
* Subtraction
* Multiplication
* Division

Use **function pointers** to select and execute the appropriate operation.

**Input:**

* Two numbers `A`, `B`.
* A character representing the operation: `+`, `-`, `*`, `/`.
* Constraints:

  * `-10^9 ≤ A, B ≤ 10^9`
  * Division by zero must be handled.

**Output:**
Print the calculated result.

**Examples:**

**Example 1**

```text
Input:
20 5
+

Output:
25
```

**Example 2**

```text
Input:
20 5
/

Output:
4
```

**Example 3**

```text
Input:
20 0
/

Output:
Error: Division by zero
```

**Edge Cases:**

* Division by zero.
* Negative numbers.
* `0 + 0`.
* Invalid operation.
* Integer overflow considerations.
* Floating-point division if decimal output is required.

**Hints:**

* Create separate functions for operations.
* Store the appropriate function's address in a function pointer.
* Invoke the selected function through the pointer.

**Time Complexity Expected:** `O(1)`

---

# 🔴 HARD

### Problem 6: Remove Duplicate Characters In-Place [HARD]

**Statement:**
A username-cleaning system receives a string containing repeated characters.

Remove duplicate characters **in-place**, keeping only the first occurrence of each character.

You should use pointers and avoid creating another string of the same size.

**Input:**

* A string of lowercase English characters.
* Constraints:

  * `1 ≤ N ≤ 10^5`
  * Characters: `a-z`

**Output:**

* Print the string after removing duplicates.

**Examples:**

**Example 1**

```text
Input:
programming

Output:
progamin
```

**Explanation:**
Only the first occurrence of each character is retained.

**Example 2**

```text
Input:
abcdef

Output:
abcdef
```

**Example 3**

```text
Input:
aaaaaa

Output:
a
```

**Edge Cases:**

* All characters identical.
* No duplicates.
* Duplicate characters at the beginning.
* Duplicate characters at the end.
* String length `1`.

**Hints:**

* Use pointers to inspect characters.
* For each character, determine whether it has appeared earlier.
* Shift later characters when a duplicate is found.
* Think about how you can modify the same character array.

**Time Complexity Expected:** `O(N²)`
**Extra Space:** `O(1)` or `O(K)` depending on your duplicate-detection approach.

---

### Problem 7: Bank Transaction Ledger [HARD]

**Statement:**
A bank stores a customer's transaction amounts in dynamically allocated memory.

Positive values represent deposits and negative values represent withdrawals.

You need to:

1. Calculate the final balance.
2. Find the largest deposit.
3. Find the largest withdrawal.
4. Count how many withdrawals occurred.

Use pointers for traversal.

**Input:**

* Initial balance `B`.
* Number of transactions `N`.
* `N` transaction values.
* Constraints:

  * `0 ≤ B ≤ 10^9`
  * `1 ≤ N ≤ 10^5`
  * `-10^7 ≤ transaction ≤ 10^7`

**Output:**

```text
Final Balance: X
Largest Deposit: Y
Largest Withdrawal: Z
Withdrawals: W
```

**Examples:**

**Example 1**

```text
Input:
10000
5
5000 -2000 3000 -1000 -500

Output:
Final Balance: 14500
Largest Deposit: 5000
Largest Withdrawal: -2000
Withdrawals: 3
```

**Example 2**

```text
Input:
5000
3
-1000 -2000 -500

Output:
Final Balance: 1500
Largest Deposit: 0
Largest Withdrawal: -2000
Withdrawals: 3
```

**Edge Cases:**

* No deposits.
* No withdrawals.
* Balance becomes zero.
* Negative final balance.
* Transaction value is zero.
* Very large balance and transaction values.

**Hints:**

* Traverse using a pointer.
* Maintain separate variables for deposits and withdrawals.
* Be careful with the meaning of "largest withdrawal". A withdrawal of `-1000` is larger numerically than `-5000`, but `-5000` is the larger withdrawal amount in absolute terms.

**Time Complexity Expected:** `O(N)`

---

### Problem 8: Custom Memory Copy [HARD]

**Statement:**
You are implementing a low-level utility similar to the C++ memory-copy functionality.

Given a source character array and a destination array, copy exactly `N` characters using **pointers only**.

You cannot use built-in string-copy functions.

**Input:**

* Source string.
* Number of characters `N`.
* Constraints:

  * `1 ≤ N ≤ 10^5`
  * `N` must not exceed the source string length.

**Output:**

* Print the destination content.

**Examples:**

**Example 1**

```text
Input:
HelloWorld
5

Output:
Hello
```

**Example 2**

```text
Input:
Computer
8

Output:
Computer
```

**Edge Cases:**

* Copy exactly one character.
* Copy the entire string.
* `N = 0`, if allowed.
* Source contains spaces.
* Destination capacity is smaller than `N`, which should be handled safely.

**Hints:**

* Maintain one pointer for source and one for destination.
* Copy the value pointed to by the source pointer.
* Increment both pointers.
* Think about null termination if treating the destination as a C-string.

**Time Complexity Expected:** `O(N)`
**Extra Space:** `O(N)` for destination storage.

---

### Problem 9: Singly Linked List Memory Manager [HARD]

**Statement:**
A task-management application stores tasks using a singly linked list.

Each node contains:

* Task ID
* Task priority
* Pointer to the next task

Implement operations to:

1. Insert a task at the beginning.
2. Insert a task at the end.
3. Delete a task by ID.
4. Search for a task.
5. Display all tasks.

Use dynamically allocated nodes and pointers.

**Input:**

* Number of operations `Q`.
* Each operation specifies the required action.
* Constraints:

  * `1 ≤ Q ≤ 10^5`
  * Task ID is unique.
  * `1 ≤ priority ≤ 10`

**Output:**
For display operations, print tasks in their current order.

For search/delete operations, report whether the task exists.

**Examples:**

**Example 1**

```text
Input:
INSERT_BEGIN 101 3
INSERT_END 102 5
INSERT_BEGIN 103 1
DISPLAY

Output:
103 1
101 3
102 5
```

**Example 2**

```text
Input:
INSERT_END 10 2
DELETE 10
DISPLAY

Output:
List is empty
```

**Edge Cases:**

* Empty list.
* Insert into an empty list.
* Delete the first node.
* Delete the last node.
* Delete the only node.
* Search for a nonexistent ID.
* Multiple nodes with different priorities.
* Correct memory deallocation.

**Hints:**

* A node contains data plus a pointer.
* Keep a pointer to the head.
* Carefully update links when deleting.
* Always consider the special case where the node being deleted is the head.

**Time Complexity Expected:**

* Insert beginning: `O(1)`
* Insert end: `O(N)` without a tail pointer
* Search: `O(N)`
* Delete: `O(N)`

---

# 🟣 DIFFICULT

### Problem 10: LRU Cache Using Pointers [DIFFICULT]

**Statement:**
You are building a browser cache that stores recently accessed pages.

The cache can hold at most `K` pages.

Rules:

* Accessing an existing page makes it the **most recently used**.
* Adding a new page also makes it most recently used.
* When the cache is full, remove the **least recently used** page.

Implement the cache using a **doubly linked list and pointers**.

**Input:**

* Cache capacity `K`.
* Number of operations `Q`.
* Operations such as:

  * `GET page`
  * `PUT page`

Constraints:

* `1 ≤ K ≤ 10^4`
* `1 ≤ Q ≤ 10^5`

**Output:**
For each `GET`, print whether the page exists.

After requested operations, display the cache from most recently used to least recently used.

**Examples:**

**Example 1**

```text
Capacity = 2

PUT A
PUT B
GET A
PUT C
```

Final cache:

```text
C A
```

**Explanation:**
`A` was accessed after `B`, so `B` became the least recently used page and was removed when `C` was inserted.

**Example 2**

```text
Capacity = 3

PUT A
PUT B
PUT C
PUT D
```

Final cache:

```text
D C B
```

**Edge Cases:**

* Capacity is `1`.
* Repeated `GET` operations.
* Repeated `PUT` for the same key.
* Removing the only node.
* Removing the head/tail.
* Empty cache.
* Cache reaches capacity exactly.

**Hints:**

* A doubly linked list allows movement in both directions.
* Maintain `head` and `tail`.
* You need fast lookup as well as fast movement.
* Consider combining a hash table with a doubly linked list.
* When a node becomes recently used, move it to the front.

**Time Complexity Expected:** `O(1)` average per `GET`/`PUT`.

---

### Problem 11: Dynamic Matrix Rotation Using Pointer Arithmetic [DIFFICULT]

**Statement:**
An image-processing application stores an `N × M` grayscale image dynamically.

Rotate the image **90 degrees clockwise**.

The matrix is dynamically allocated, and access should primarily use pointer arithmetic.

**Input:**

* Two integers `N` and `M`.
* `N × M` matrix elements.
* Constraints:

  * `1 ≤ N, M ≤ 1000`
  * Pixel value: `0 ≤ value ≤ 255`

**Output:**

* Print the matrix after rotating it 90° clockwise.

**Examples:**

**Example 1**

```text
Input:
2 3
1 2 3
4 5 6

Output:
4 1
5 2
6 3
```

**Explanation:**

Original:

```text
1 2 3
4 5 6
```

After clockwise rotation:

```text
4 1
5 2
6 3
```

**Example 2**

```text
Input:
1 4
10 20 30 40

Output:
10
20
30
40
```

**Edge Cases:**

* `1 × 1` matrix.
* `1 × M`.
* `N × 1`.
* Square matrix.
* Very large matrix.
* All elements identical.

**Hints:**

* Notice that an `N × M` matrix becomes an `M × N` matrix.
* Determine where the element at `(i, j)` goes after rotation.
* Pointer arithmetic can represent a 2D dynamically allocated structure.
* Consider whether you can perform the rotation without allocating another full matrix.

**Time Complexity Expected:** `O(N × M)`

---

### Problem 12: Memory-Safe Dynamic Array With Custom Reallocation [DIFFICULT]

**Statement:**
You are implementing a simplified version of a dynamic array similar to `std::vector`.

The array initially has a small capacity. Whenever the number of elements exceeds the capacity, allocate a larger memory block, copy the old elements, release the old memory, and continue.

Implement operations:

* `PUSH value`
* `POP`
* `GET index`
* `SIZE`
* `CAPACITY`

You must manage memory manually using pointers.

**Input:**

* Number of operations `Q`.
* Up to `10^5` operations.
* Constraints:

  * `1 ≤ Q ≤ 10^5`
  * Integer values: `-10^9 ≤ value ≤ 10^9`
  * `0 ≤ index < current_size` for valid `GET`.

**Output:**

For `GET`:

```text
Value: X
```

For `SIZE`:

```text
Size: X
```

For `CAPACITY`:

```text
Capacity: X
```

For invalid `POP` or `GET`, print an appropriate error message.

**Examples:**

**Example 1**

```text
PUSH 10
PUSH 20
PUSH 30
SIZE
GET 1

Output:
Size: 3
Value: 20
```

**Example 2**

```text
PUSH 5
PUSH 10
POP
SIZE

Output:
Size: 1
```

**Example 3**

```text
GET 0

Output:
Error: Invalid index
```

**Edge Cases:**

* Pushing the first element.
* Capacity becomes full.
* Reallocation occurs.
* Multiple reallocations.
* Popping until empty.
* `POP` on an empty array.
* Invalid index.
* Negative values.
* Very large number of operations.
* Memory must be released at the end.

**Hints:**

* Maintain three important pieces of information:

  * Pointer to allocated memory
  * Current size
  * Current capacity
* When capacity is full, allocate a larger block.
* Copy elements from the old block using pointers.
* Release the old memory only after copying successfully.
* Think carefully about pointer invalidation after reallocation.

**Time Complexity Expected:**

* `GET`: `O(1)`
* `SIZE`: `O(1)`
* `CAPACITY`: `O(1)`
* `POP`: `O(1)`
* `PUSH`: **Amortized `O(1)`**
* Reallocation: `O(N)`

---

# 📌 Difficulty & Concept Map

| #  | Problem                | Level        | Main Pointer Concept          |
| -- | ---------------------- | ------------ | ----------------------------- |
| 1  | Swap Bank Balances     | 🟢 Easy      | Pointer + dereference         |
| 2  | Sensor Maximum         | 🟢 Easy      | Pointer arithmetic            |
| 3  | Reverse Customer Name  | 🟡 Medium    | Character pointers            |
| 4  | Dynamic Marks Analyzer | 🟡 Medium    | Dynamic memory                |
| 5  | Calculator             | 🟡 Medium    | Function pointers             |
| 6  | Remove Duplicates      | 🔴 Hard      | In-place manipulation         |
| 7  | Bank Ledger            | 🔴 Hard      | Dynamic array + traversal     |
| 8  | Custom Memory Copy     | 🔴 Hard      | Raw pointers                  |
| 9  | Linked List Manager    | 🔴 Hard      | Node pointers                 |
| 10 | LRU Cache              | 🟣 Difficult | Doubly linked list + hash map |
| 11 | Matrix Rotation        | 🟣 Difficult | Dynamic 2D memory             |
| 12 | Dynamic Array          | 🟣 Difficult | Manual memory management      |

### 🎯 Recommended solving order

**1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 10 → 11 → 12**

Agar tum genuinely **pointers interview-level** tak master karna chahte ho, especially **9 → 12** ko bina solution dekhe solve karna kaafi important hai. Inmein pointer syntax se zyada **memory ownership, pointer movement, dynamic allocation, linked structures aur edge-case handling** test hogi.
