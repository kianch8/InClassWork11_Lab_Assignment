## Written Comparison of Manual vs Smart Pointer Implementation

**Lines Of Code:**
The manual memory version (Part A) required more code to implement a destructor, copy constructor, assignment operator, and a private helper function `clear()`. On the other hand, the smart pointer version (Part B) eliminated these by implementing a shorter and cleaner method.

**Safety:**
Part A tends to be more error-prone because it relies on manual memory management, making it vulnerable to memory leaks, double-free errors, and use-after-free bugs. These issues were demonstrated using Valgrind in Part C by modifying the code from Part A. The smart pointer version (Part B) is much safer because `unique_ptr` automatically manages memory and prevents cases of accidental copying, double deletion, and memory leaks.

**Complexity:**\
(Part A: More complex)
* Rule of Three implementation
* Explicit memory handling
* Higher cognitive load

(Part B: Simpler)
* No need for Rule of Three
* Memory is managed automatically
* Code is more efficient, easier to read, and maintain

Hence, it can be seen that using `unique_ptr` has a much simpler implementation and significantly reduces the risk of memory-related bugs. One limitation is that it restricts copying, although it enforces safer design and is preferred in modern C++.

