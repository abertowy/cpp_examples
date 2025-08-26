Smart pointers
==============
  
unique_ptr:
-----------
- **Exclusive Ownership:**  
    Unique_ptr uniquely owns the object it points to. Only one unique_ptr can manage a specific object at a time, preventing multiple unique_ptr instances from pointing to the same resource.
- **Automatic Memory Management:**  
    When a unique_ptr goes out of scope, or when it is assigned a new pointer, it automatically deallocates the memory of the object it previously owned by calling its associated deleter.  
    The default deleter uses delete (or delete[] for arrays).
- **Move Semantics:**  
    unique_ptr cannot be copied, ensuring exclusive ownership. However, ownership can be transferred (moved) from one unique_ptr to another using std::move.  
    This allows for efficient transfer of resources without deep copies.
- **Efficiency:**  
    unique_ptr is designed to be as efficient as a raw pointer, incurring minimal overhead.
- **Use Cases:**  
    return value of a Factory
- **Size:**  
    Size of pointer + size of custom deleter (if provided)  
  
shared_ptr:
------------
- **Shared Ownership:**  
    Multiple shared_ptr instances can point to and manage the same underlying raw pointer.  
- **Reference Counting:**  
    A control block associated with the managed object keeps track of how many shared_ptr instances currently own it.  
    This "reference count" is incremented when a shared_ptr is copied and decremented when a shared_ptr goes out of scope or is reset.  
- **Automatic Memory Management:**  
    When the reference count for an object reaches zero, the shared_ptr automatically deallocates the memory occupied by the object, preventing memory leaks.
- **Safety:**  
    It helps prevent common pointer-related issues like dangling pointers and double-free errors by ensuring the object's lifetime is tied to its owners.
- **Size:**  
    pointer to data + pointer to Control block (ref counter, weak counter, custom deleter, allocator, etc)  
  
**std::make_shared**  
This utility function is the preferred way to create shared_ptr instances.  
It allocates the object and its control block in a single memory allocation, which can improve performance and exception safety.  
  
Shoildn't be created from a raw pointer (mem leak, double deallocation, etc)  
  
weak_ptr:
---------
- **Non-owning reference:**
    A weak_ptr does not increase the reference count of the object it points to.  
    This means that the existence of a weak_ptr does not prevent the object from being deallocated when all shared_ptr instances managing it are destroyed.  
- **Preventing circular references:**
    Main application of weak_ptr. In scenarios where two or more objects managed by shared_ptr have mutual shared_ptr references to each other,  
    a circular dependency can form, preventing the objects from being deallocated even when no other shared_ptr instances point to them.  
    Using weak_ptr for one or more of these references breaks the cycle, allowing proper deallocation.  
- **Observing an object's lifetime:**
    A weak_ptr can be used to observe whether the object it points to is still alive.  
    The lock() method can be used to attempt to obtain a shared_ptr to the managed object.  
    If the object has already been deallocated, lock() will return an empty shared_ptr.  
- **Cannot directly access the object:**
    Unlike shared_ptr, a weak_ptr cannot be directly dereferenced to access the underlying object. Access requires first converting it to a shared_ptr using lock().  
  
```
if (auto shared_a = b->a_ptr.lock()) {
  std::cout << "A is still alive." << std::endl;
} else {
  std::cout << "A has been deallocated." << std::endl;
}
```