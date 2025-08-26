free/malloc vs new/delete
=========================

malloc() vs new()
-----------------
  
- `malloc()` is a C library function that can also be used in C++
- `new operator` is specific for C++ only.
- both `malloc()` and `new` are used to allocate the memory **dynamically in heap**. But `new` does call the **constructor** of a class whereas `malloc()` does not.
  
free() vs delete
----------------
  
- `free()` is a C library function that can also be used in C++
- `delete` is a C++ keyword
- `free()` frees memory but doesn't call Destructor of a class whereas `delete` frees the memory and also **calls the Destructor** of the class.
  
The **destructor** is still called even though the delete operator is not used. The reason for the destructor call is the statement `return 0`. This statement when executed within the main function calls the **destructor** of each class for which object was created.
To **avoid** the Destructor calling we can replace the statement `return 0 `with `exit(0)`.