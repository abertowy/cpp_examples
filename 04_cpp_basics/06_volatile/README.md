Volatile
========

`volatile` keyword is a `type qualifier` used to inform the compiler that a variable's **value may change unexpectedly** due to factors outside the program's explicit control.  
  
Hardware interactions
---------------------
In embedded systems, `volatile` is crucial when dealing with `memory-mapped hardware registers`, whose **values can be altered by external events** or peripherals.  
- **Interrupt Service Routines (ISRs):**  
    Variables shared between the main program flow and an `ISR` should be declared volatile because the `ISR` can modify them at any time, asynchronously.  
- **Multithreading (with caveats):**  
    While `volatile` ensures that reads and writes to a variable are **not optimized** away or reordered by the compiler,  
    **it does not provide thread-safety** guarantees like `mutual exclusion` or `memory visibility` between threads.  
    For robust multithreaded programming, synchronization primitives (e.g., `mutexes`, `atomic operations`) are necessary.  
  
When a variable is declared `volatile`, the compiler is instructed to:  
- **Not optimize away accesses:**  
    Every `read` from or `write` to a `volatile` variable **must be performed**, preventing the compiler from caching its value in a register or eliminating seemingly redundant accesses.  
- **Not reorder accesses:**  
    The order of operations involving `volatile` variables is **preserved**, preventing the compiler from reordering reads or writes in a way that could lead to unexpected behavior.