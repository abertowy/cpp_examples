inline functions
==================
  
`inline function` is a function for which the compiler is **suggested** to `substitute` the function's code directly into the calling code at the point of each call, rather than `generating` a separate function call instruction. This process is known as `"inlining"` or `"inline expansion"`
  
Performance Optimization
-------------------------
The primary motivation for using `inline` functions is to **reduce the overhead** associated with traditional function calls.  
This overhead includes **pushing arguments** onto the `stack`, **saving registers**, **jumping** to the function's memory location, **executing** the function, and **returning** to the calling point.  
By `inlining`, these steps are eliminated, potentially leading to **faster execution** for small, frequently called functions.  
  
Compiler Optimization Opportunities
-----------------------------------
`Inlining` can expose more optimization opportunities to the compiler, as it can perform optimizations across the boundaries of the inlined function and its calling code.  
  
```
inline int add(int a, int b) {
    return a + b;
}
```
  
Considerations
----------------
- **Compiler Hint, Not a Command:**  
    The compiler is free to **ignore** this suggestion if it determines that inlining would not be beneficial (e.g., for very large functions or functions with complex control flow).  
- **Increased Code Size:**  
    `Inlining` can lead to an **increase** in the overall **executable size** if the function is inlined at many call sites, as its code is duplicated.  
    This can potentially lead to **worse cache performance**.  
- **One Definition Rule (ODR):**  
    When an `inline` function is defined in a `header file` (which is common practice for `inline` functions), it can be included in multiple translation units.  
    The `inline` keyword **allows** for `multiple definitions` of the same function as long as they are identical, satisfying the One Definition Rule.  
- **Member Functions:**  
    `Member functions` defined directly within a class definition are **implicitly** `inline`, even without the explicit inline keyword.  
  
When to Consider Using Inline Functions:
----------------------------------------
- **Small Functions:** Functions with very few lines of code where the function call overhead might be significant compared to the function's execution time.
- **Frequently Called Functions:** Functions that are called repeatedly within loops or performance-critical sections of code.
  
When to Avoid Inline Functions:
-----------------------------------
- **Large Functions:** Inlining large functions can significantly increase code size and potentially degrade performance due to cache issues.
- **Functions with Complex Logic:** loops, recursion, or extensive conditional statements the overhead of the function call becomes negligible compared to the execution time of the function itself.