Smart pointers
==============
  
`Smart pointers` provide a safer and more robust way to manage dynamic memory compared to raw pointers, reducing common memory-related errors and simplifying resource management in C++.  
  
std::unique_ptr
---------------
  
Represents exclusive ownership of an object.  
Cannot be copied, but its ownership can be transferred (moved) to another unique_ptr.  
Automatically deallocates the pointed-to object when the unique_ptr goes out of scope.  
Ideal for scenarios where a single owner is responsible for a resource.  
  
std::shared_ptr
---------------
  
Represents shared ownership of an object through reference counting.  
Multiple shared_ptr instances can point to the same object.  
The object is deallocated when the last shared_ptr pointing to it is destroyed or reset.  
Useful when multiple parts of a program need to share access to a single dynamically allocated object.  
  
std::weak_ptr
-------------
A non-owning smart pointer that can observe a shared_ptr without affecting its reference count.  
Used to break circular references that can occur with shared_ptr, preventing memory leaks in such cases.  
Does not prevent the pointed-to object from being deallocated. To access the object, a weak_ptr must be converted to a shared_ptr (which will be empty if the object has already been deallocated).  