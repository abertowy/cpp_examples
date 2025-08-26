SIGSEGV vs memory pages
=======================
  
Memory management and protection in operating systems.  
  
SIGSEGV
-------
A `SIGSEGV` is a signal sent by the operating system to a process when it attempts to access a memory location that **it does not have permission to access**, or that **does not exist** within its allocated virtual address space.  
This typically occurs due to errors in the program's logic, such as:  
- Dereferencing a null or uninitialized pointer.
- Accessing an array or buffer out of bounds.
- Attempting to write to read-only memory.
- Stack overflow.
  
Upon receiving a `SIGSEGV`, the default behavior is typically **program termination**, often with a "core dumped" message, indicating that a snapshot of the program's memory was saved for debugging.  
  
Memory Pages
------------
Modern operating systems use virtual memory, which divides a process's address space into fixed-size blocks called "pages" (e.g., 4KB).  
These virtual pages are mapped to physical memory "page frames" by the `Memory Management Unit (MMU)` of the CPU, managed by the operating system.  
Each memory page has associated permissions (`read`, `write`, `execute`) that determine how the process can interact with the data within that page.  
  
Notes
-------
`SIGSEGV` is a consequence of violating memory page permissions or boundaries. When a program attempts an operation (`read` or `write`) on a virtual address that falls outside its allocated pages, or within a page but with insufficient permissions (e.g., **writing to a read-only page**), the `MMU` detects this violation.  
The `MMU` then signals the operating system, which in turn sends a `SIGSEGV` to the offending process, leading to its termination.  
Therefore, `memory pages` are the underlying mechanism by which the operating system **enforces memory protection**, and `SIGSEGV` is the **signal** indicating that this protection has been violated.