Move operator
=============
  
`Move semantic` allows more efficient `transfer of resources` (like dynamically allocated memory or file handles) from one object to another, avoiding expensive deep copies.  
Instead of copying the underlying data, `move semantics` enables `"transferring ownership"` of resources from a temporary or expiring object to a new one.  
  
The primary benefit of move semantics is **performance optimization**, especially when dealing with large objects or containers that manage significant resources.  
By avoiding unnecessary deep copies, it can drastically reduce memory allocations and copying overhead, leading to more efficient code.  
This is particularly relevant in scenarios like returning large objects from functions, passing objects by value, or swapping objects.  
  
`MOVE CTOR` and `MOVE assignment operator` will **not be genearted** if any of those are defined or if `COPY ctor` or `copy assignment operator` are defined (no `DTOR` defined, as well).  
  
Rvalue references (&&)
----------------------
These are references that bind to `rvalues` (temporary objects or expressions that are about to expire).  
They are crucial for distinguishing between operations on lvalues (objects with a persistent identity) and rvalues, allowing for different behavior, such as moving instead of copying.  
  
Move constructor
-----------------
A special constructor that takes an rvalue reference to an object of the same type.  
Its purpose is to transfer the resources from the source object to the newly constructed object, typically by copying pointers or handles and then nullifying or invalidating the source object's pointers/handles to prevent double-free issues.  
  
Move assignment operator
------------------------
Similar to the move constructor, this operator takes an rvalue reference and transfers resources during an assignment operation.  
  
std::move
---------
A standard library utility function that casts an lvalue to an rvalue reference.  
This explicitly indicates intent to move from the object and allows the compiler to select move-aware overloads (like move constructors or move assignment operators) if available.  
**It does not actually perform the move itself**, but rather enables it by changing the value category.  
  
std::forward
------------
Used primarily in `template programming` to **conditionally cast an argument to an rvalue reference**, preserving its original value category (lvalue or rvalue).  
This is essential for **perfect forwarding** in generic functions.  