Virtual vs non Virtual sample
=============================
  
`Non-virtual` member functions are **resolved statically**.  
Member function are binding statically at compile-time based on the type of the pointer (or reference) to the object.  
  
In contrast, `virtual` member functions are **binding dynamically** at run-time.  
If class have atleast one virtual member function then compiler puts a hidden pointer in the object called a vptr(virtual table address) during the construction of object.  
  
The compiler creates a `vtable` for each class that has at least one `virtual` function. `Virtual` table contain virtual function's address. It can be array or list(depend upon the compiler) of virtual function pointer's.  
During a dispatch of a `virtual` function, the run-time system follows the object’s v-pointer (fetch the address from class object) to the class’s `vtable`, then offset is added to the base address(vptr) and call the function.  
  
The space-cost overhead of the above technique is nominal: an extra pointer per object (but only for objects that will need to do dynamic binding), plus an extra pointer per method (but only for virtual methods). The time-cost overhead is also fairly nominal: compared to a normal function call, a virtual function call requires two extra fetches (one to get the value of the v-pointer, a second to get the address of the method).  
  
None of this runtime activity happens with non-virtual functions, since the compiler resolves non-virtual functions exclusively at compile-time based on the type of the pointer.  