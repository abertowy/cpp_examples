Abstract class, pure virtual
============================
  
Abstract class
--------------
**Abstract class** is a class designed to serve as a base class for other classes, but it cannot be instantiated directly. This means you cannot create objects of an abstract class type. A class becomes abstract if it contains at least one pure virtual function.  
Pointers and references to an abstract class type can be declared and used to point to or refer to objects of derived classes.  
  
Pure virtual
------------
**Pure virtual** function is a virtual function declared in a base class with no implementation in that base class.  
It is indicated by the = 0 specifier in its declaration.  
This signifies that derived classes must provide an implementation for this function.  
If a derived class fails to implement all inherited pure virtual functions, that derived class also becomes abstract.  
Enables runtime polymorphism by ensuring that a specific function signature exists across a hierarchy, but its implementation is deferred to concrete derived classes.  
```
    virtual void func() = 0;
```