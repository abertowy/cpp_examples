Virtual Constructor and Destructor
==================================

Virtual Constructors
--------------------
C++ does not directly support virtual constructors.  
**A constructor's purpose is to initialize an object**, and at the time a constructor is called, the object's type is already known and fixed. Polymorphism, which virtual functions enable, relies on the `virtual table (vtable)` and `virtual pointer (vptr)` mechanism to determine the correct function to call at runtime. However, during object construction, the `vtable` is not yet fully established for the derived class, and the object's type is being determined. Therefore, making a constructor virtual is **not possible** and would lead to a compilation error.  
While a **virtual constructor** in the sense of creating different derived types based on runtime conditions isn't directly supported, similar functionality can be achieved using design patterns like the **Factory** or **Prototype** pattern. These patterns allow for the creation of derived class objects through a base class interface, effectively simulating a "virtual construction" process.  

Virtual Destructors
--------------------
**Virtual destructors** are crucial in C++ when dealing with polymorphism and inheritance, particularly when objects are managed through base class pointers.  
When a derived class object is deleted through a base class pointer, a `non-virtual destructor` for the base class would be called, potentially leading to **memory leaks** or undefined behavior if the derived class has resources that need to be deallocated by its own destructor.  
Declaring a `destructor as virtual` in the base class ensures that when an object of a derived class is deleted via a base class pointer, the **correct destructor chain is invoked**. This means the derived class's destructor is called first, followed by the base class's destructor, ensuring proper resource cleanup.