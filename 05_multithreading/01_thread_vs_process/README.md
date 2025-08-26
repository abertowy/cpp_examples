Thread vs Process
=================
  
Process
-------
- A `process` is an independent execution environment for a program.
- Each `process` has its own `dedicated memory space`, including its own `heap`, `stack`, and `global variables`.
- `Processes` are **isolated** from each other, meaning one process cannot directly access the memory or resources of another without explicit `inter-process communication mechanisms`.
- Creating and terminating `processes` is a relatively **"heavyweight"** operation, consuming significant system resources and time.
- Context switching between `processes` is more **expensive** due to the need to **save and restore** entire memory contexts.
  
Thread
-------
- A `thread` is a **lightweight** unit of execution that exists within a `process`.
- `Threads` within the same `process` **share** the `process's` memory **space and resources**, including `global variables`, open `files`, and `network connections`.
- `Threads` have their own **independent** execution flow, including their own `stack` and `program counter`.
- Creating and terminating `threads` is a **"lightweight"** operation compared to processes.
- Context switching between `threads` within the same `process` is **faster** because they **share the same memory space**.
- `Threads` require careful **synchronization mechanisms** (e.g., `mutexes`, `semaphores`) to prevent data corruption when multiple `threads` access shared resources concurrently.