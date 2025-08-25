Polymorphism
============

**Polymorphism** allows objects of different classes to be treated as objects of a common base class, enabling a single interface to represent multiple forms of behavior.  
The term **"polymorphism"** literally means "many forms."

Compile-Time Polymorphism (Static Polymorphism)
-----------------------------------------------
Achieved during compilation.  
**Function Overloading**  
Defining multiple functions with the same name but different parameters (number, type, or order of arguments) within the same scope.  
The compiler determines which function to call based on the arguments provided during the function call.  
**Operator Overloading**  
Enabling operators (like +, -, *, /) to perform different operations depending on the context or the types of operands they are used with.

Run-Time Polymorphism (Dynamic Polymorphism)
-----------------------------------------------
Achieved during program execution.  
**Function Overriding (Virtual Functions)**  
This is the most common form of run-time polymorphism in C++. It involves a base class and one or more derived classes.  
A virtual function is declared in the base class.  
Derived classes can provide their own specific implementations (override) of this virtual function.  
When a pointer or reference to the base class points to an object of a derived class,
calling the virtual function through that base class pointer/reference will execute the derived class's overridden version of the function at runtime.  
This is achieved through a mechanism called the virtual table (vtable).

Inheritance
-----------
**Polymorphism**:  
Relies heavily on inheritance, where derived classes inherit from a base class, establishing an "is-a" relationship (e.g., a Square is a Rectangle).  
**Virtual Functions**:  
Essential for run-time polymorphism, allowing dynamic dispatch of function calls based on the actual type of the object pointed to by a base class pointer or reference.

Benefits of Polymorphism
-------------------------
1. **Code Reusability**  
    Write generic code that works with objects of different types as long as they share a common base class and interface.
2. **Flexibility and Extensibility**  
    Easily add new derived classes without modifying existing code, promoting a more modular and maintainable design.
3. **Reduced Complexity**  
    Simplifies code by using a single interface for diverse functionalities.