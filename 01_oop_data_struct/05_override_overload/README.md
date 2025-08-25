Override vs Overload
====================
**Overloading** and **overriding** are distinct concepts related to polymorphism, but they apply in different contexts.  
  
Overloading
-----------
**Overloading** involves defining multiple functions (or operators) with the same name within the same scope (e.g., within the same class or namespace), but with different parameter lists (different number of parameters or different types of parameters).
  
- Purpose:  
    It allows a single function name to perform different actions based on the types and number of arguments passed to it.  
    This enhances code readability and reusability by using a familiar name for similar operations on different data types.
- Mechanism:
    The compiler determines which overloaded function to call at compile time based on the argument types provided in the function call.  
    This is a form of compile-time polymorphism (static polymorphism).  
- Example:
    ```
    sum(int x, int y);
    sum(double x, double y)
    ```
  
Overriding
----------
**Overriding** occurs in the context of inheritance, where a derived class provides its own specific implementation for a virtual function that is already defined in its base class.  
The function in the derived class must have the exact same signature (name, return type, and parameter list) as the virtual function in the base class.  
- Purpose:  
    It allows a derived class to customize or extend the behavior inherited from its base class, enabling run-time polymorphism (dynamic polymorphism).  
    This means that the specific version of the function called depends on the actual type of the object at runtime, not just the pointer or reference type.  
- Mechanism:  
    The base class function must be declared as virtual.  
    The override keyword in the derived class (optional) ensures that the function correctly overrides a base class virtual function.  
    When a virtual function is called through a base class pointer or reference, the correct derived class implementation is invoked based on the object's actual type.
- Example:
    ```
    virtual void sum(int a, int b) { std::cout << "IT's a SUM:" << a+b << std::endl;}
    void sum(int a, int b) { std::cout << "NOW we are processing a sum. And it is .... " << a+b << std::endl;}
    ```