Vtable
=======
  
*Vtable* (virtual table) is a mechanism used to implement runtime polymorphism through virtual functions. It is an implementation detail of most C++ compilers, although not explicitly mandated by the C++ standard.  
The primary purpose of a vtable is to enable dynamic dispatch for virtual function calls.  
This means that when a virtual function is called through a base class pointer or reference, the correct overridden function in the derived class is invoked at runtime, rather than being determined at compile time.  
  
- Each class that has at least one virtual function (or inherits from a class with virtual functions) will have its own vtable.
- The vtable is essentially an array of function pointers, where each entry points to the implementation of a virtual function for that specific class.
- Each object of such a class contains a hidden pointer, commonly referred to as a vptr (virtual pointer), which points to the vtable of its class.
  
When a `virtual function` is called on an object through a base class pointer or reference, the compiler generates code to access the object's `vptr`.  
The `vptr` then leads to the correct vtable for the actual type of the object.  
Within that `vtable`, the appropriate function pointer for the `virtual function` is found and invoked.  
  
- Vtables are typically created by the compiler during the compilation process and are usually stored in the data segment of the program.
- All instances of a given class share the same vtable, as the vtable is a class-level construct, not an object-level one.
- Vtables also often contain information for Run-Time Type Information (RTTI), which allows for dynamic type identification (e.g., using dynamic_cast).