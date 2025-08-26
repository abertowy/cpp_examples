virtual / physical memory
=========================
  
Programs interact with `virtual memory`, not directly with `physical memory`. The operating system, in conjunction with hardware (specifically the `Memory Management Unit or MMU`), handles the mapping between these two memory types.  
  
Virtual Memory
--------------
- `Virtual memory` refers to the address space that a C++ program perceives and utilizes. Every process running on a modern operating system has **its own isolated virtual address space**.
- C++ operations like `new`, `malloc`, and accessing variables (`local`, `global`, `static`) all interact with **virtual addresses**.
- The **virtual address** space is typically **much larger** than the available **physical RAM**, allowing programs to allocate more memory than physically present and facilitating multi-tasking and process isolation.
- The `virtual memory` is often divided into segments like `code`, `data` (`static`/`global`), `stack`, and `heap`.
  
Physical Memory
---------------
- `Physical memory` refers to the actual `RAM` chips installed in the computer. This is the **hardware component** where data is physically stored.
- The **operating system** manages the allocation and deallocation of physical memory to different processes and parts of their virtual address spaces.
- When a program accesses a `virtual address`, the `MMU` translates it into a corresponding `physical address`, which the CPU then uses to access the `RAM`.
- If a `virtual address` is accessed but its corresponding data is **not currently** in physical memory (e.g., it has been swapped out to disk), a **page fault occurs**, and the operating system loads the required data into physical memory.
  
C++ code, when compiled and executed, operates entirely within the realm of `virtual memory`. `Pointers` in C++ store `virtual addresses`.
The C++ language itself **does not provide** direct mechanisms to manipulate physical memory addresses. This abstraction is handled by the operating system for security, stability, and resource management.  
While C++ programmers typically don't need to directly manage the virtual-to-physical memory mapping, understanding the concept is crucial for optimizing memory usage, debugging memory leaks, and comprehending performance implications related to memory access patterns and caching.  