Rule of 3, 5, 0
===============
  
Rule of 3
---------
  
If a class requires a user-defined destructor, a user-defined copy constructor, or a user-defined copy assignment operator, it almost certainly requires all three.  
  
Because C++ copies and copy-assigns objects of user-defined types in various situations (passing/returning by value, manipulating a container, etc), these special member functions will be called, if accessible, and if they are not user-defined, they are implicitly-defined by the compiler.  
  
The implicitly-defined special member functions should not be used if the class manages a resource whose handle is an object of non-class type (raw pointer, POSIX file descriptor, etc), whose destructor does nothing and copy constructor/assignment operator performs a "shallow copy" (copies the value of the handle, without duplicating the underlying resource).  
  
Classes that manage non-copyable resources through copyable handles may have to declare copy assignment and copy constructor private and not provide their definitions(until C++11)define copy assignment and copy constructor as = delete(since C++11). This is another application of the rule of three: deleting one and leaving the other to be implicitly-defined typically incorrect.  
  
Rule of 5
---------
  
Because the presence of a user-defined (include = default or = delete declared) destructor, copy-constructor, or copy-assignment operator prevents implicit definition of the move constructor and the move assignment operator, any class for which move semantics are desirable, has to declare all five special member functions  
  
Unlike Rule of Three, failing to provide move constructor and move assignment is usually not an error, but a missed optimization opportunity.  
  
Rule of 0
---------
  
Classes that have custom destructors, copy/move constructors or copy/move assignment operators should deal exclusively with ownership (which follows from the Single Responsibility Principle). Other classes should not have custom destructors, copy/move constructors or copy/move assignment operators.  
  
This rule also appears in the C++ Core Guidelines as C.20: If you can avoid defining default operations, do  
  
When a base class is intended for polymorphic use, its destructor may have to be declared public and virtual. This blocks implicit moves (and deprecates implicit copies), and so the special member functions have to be defined as = default  
  
However, this makes the class prone to slicing, which is why polymorphic classes often define copy as = delete (see C.67: ` A polymorphic class should suppress public copy/move` in C++ Core Guidelines), which leads to the following generic wording for the Rule of Five:  
`C.21: If you define or =delete any copy, move, or destructor function, define or =delete them all`  