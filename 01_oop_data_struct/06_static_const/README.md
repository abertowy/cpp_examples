Static, const keywords
======================
Static
------
**Static (usually counters)**: primarily concerns storage duration (lifetime) and linkage (visibility), and enables class-level members.  
  
- Static Local Variables:  
    When declared inside a function, a static local variable is initialized only once, the first time the function is called. It retains its value across subsequent function calls and its lifetime extends for the entire duration of the program, even after the function exits.
- Static Global Variables/Functions:  
    At global or namespace scope, static variables and functions have internal linkage, meaning they are only visible and accessible within the compilation unit (source file) where they are defined. This prevents name collisions across multiple files.
- Static Class Members:  
    Within a class, static data members are shared by all objects of the class; there is only one copy of the static member, regardless of how many objects are created. static member functions can only access static data members and static member functions of the class. They can be called without creating an object of the class.

CONST
-----
**CONST** primarily concerns mutability, ensuring that a value or object's state remains unchanged after initialization.
  
The const keyword signifies immutability, meaning the value of a variable or object cannot be modified after its initialization.  
  
- Constant Variables:  
    A const variable must be initialized at the time of its declaration and its value cannot be changed later
- Constant Member Functions:  
    When applied to a member function of a class, const indicates that the function will not modify the state (data members) of the object on which it is called. This allows const objects to call such functions.
- const Pointers and References:  
    const can be used with pointers and references to control whether the pointed-to/referenced data or the pointer/reference itself can be modified.