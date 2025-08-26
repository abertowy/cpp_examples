Bridge
======
  
`Bridge` pattern is a **structural design pattern** that aims to **decouple an abstraction from its implementation**, allowing both to vary independently.  
This separation promotes **flexibility** and avoids a permanent binding between the abstraction and its underlying implementation.  
  
Components
----------
- **Abstraction:**  
    This defines the high-level `interface` for the client. It contains a reference to an `Implementor` object and delegates the actual work to it.  
- **Refined Abstraction:**  
    These are **concrete implementations** of the `Abstraction` interface, providing **specific variations** of the high-level logic.  
- **Implementor:**  
    This defines the `interface` for the implementation classes. It provides a **set of primitive operations** that the `Abstraction` can use.  
- **Concrete Implementor:**  
    These are **concrete implementations** of the `Implementor` interface, providing different ways to perform the primitive operations.  
  
How it works
------------
- The `Abstraction` class maintains a **pointer or reference** to an `Implementor` object.
- When a client calls a method on the `Abstraction`, the `Abstraction` **delegates** the call to its associated `Implementor` object.
- This allows the `Abstraction` to work with **different implementations** without being tied to a specific one.
  
Benefits
--------
- **Decoupling:**  
    It separates the abstraction from its implementation, allowing independent development and modification.  
- **Flexibility:**  
    New implementations can be added without modifying the existing abstraction, and vice versa.  
- **Reduced Complexity:**  
    It helps manage complex class hierarchies by breaking them down into smaller, more manageable parts.  
- **Improved Maintainability:**  
    Changes in one part of the system have a minimal impact on other parts.  