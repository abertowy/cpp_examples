Heap vs Stack
=============
  
Stack
-----
- **Allocation**: Memory is automatically allocated and deallocated by the compiler during function calls. Local variables, function parameters, and return addresses are stored here.
- **Speed**: Allocation and deallocation are very fast, essentially involving adjusting a stack pointer.
- **Size**: The stack has a relatively fixed and limited size, typically determined by the operating system or compiler settings.
- **Lifetime**: Data stored on the stack has a limited lifetime, existing only while the function it belongs to is active.
- **Management**: Memory management is automatic and efficient, with no risk of memory leaks from stack-allocated variables.
  
Heap
----
- **Allocation**: Memory is (MANUAL) dynamically allocated and deallocated by the programmer using new and delete (or malloc and free in C). This is used for objects and data structures whose size or lifetime is not known at compile time.
- **Speed**: Allocation and deallocation are generally slower than on the stack due to the need to search for available memory blocks and manage fragmentation.
- **Size**: The heap is a larger, more flexible pool of memory, limited only by the system's available RAM.
- **Lifetime**: Data on the heap persists until explicitly deallocated by the programmer or the program terminates.
- **Management**: Requires manual memory management, making it susceptible to memory leaks if deallocation is forgotten, or dangling pointers if deallocated prematurely.