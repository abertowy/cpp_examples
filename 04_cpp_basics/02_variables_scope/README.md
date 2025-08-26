variables scope
================
  
`Variable scope` defines the region of a program where a declared variable is visible and accessible.  
It dictates where a variable can be used by its name and determines its lifetime in memory  
  
Local Scope (Block Scope):
----------------------------
- Variables declared inside a function, a loop (like for or while), or an if statement block have local scope.
- They are only visible and accessible within the specific block where they are declared.
- Their lifetime begins when the block is entered and ends when the block is exited, at which point they are destroyed.
  
Global Scope (File Scope):
----------------------------
- Variables declared outside of any function, typically at the top of a source file, have global scope.
- They are visible and accessible from any part of the program, including all functions within that file.
- Their lifetime extends from the program's start until its termination.
  
Function Parameter Scope (Formal Parameters):
---------------------------------------------
- Variables declared as parameters in a function definition have a scope limited to that function.
- They are essentially local variables within the function's body, initialized with the values passed during the function call.
  
Class Scope:
-------------
- Member variables (data members) of a class have class scope.
- They are accessible within any member function of that class and, depending on their access specifier (public, private, protected), potentially outside the class through objects.
  
Static Local Variables (within a function):
-------------------------------------------
- **Lifetime:**  
    These variables are initialized only once, the first time the function containing them is called.  
    They retain their value across multiple calls to that function and exist for the entire duration of the program.  
    They are stored in static storage, not on the stack.  
- **Scope:**  
    Their scope remains local to the function in which they are declared. They cannot be accessed or modified from outside that function.  
  
Static Global Variables (at global or namespace scope):
-------------------------------------------------------
- **Lifetime:**  
    Similar to static local variables, they exist for the entire duration of the program.  
- **Scope (Internal Linkage):**  
    The static keyword at global or namespace scope restricts the variable's visibility to the translation unit (the source file) where it is defined.  
    This means the variable cannot be accessed from other source files, even if they try to declare an extern reference to it.  
    This prevents naming conflicts in larger projects.  
  
Static Member Variables (within a class):
-----------------------------------------
- **Lifetime:**  
    Static member variables belong to the class itself, not to individual objects of the class.  
    They are initialized once, typically outside the class definition, and exist for the entire program duration.  
- **Scope:**  
    They have class scope, meaning they can be accessed using the class name without needing an object of that class.  
    They are shared by all instances of the class.  