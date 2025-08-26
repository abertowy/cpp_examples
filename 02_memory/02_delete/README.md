delete p vs delete[] p
======================
  
`delete p` and `delete[] p` are used to `deallocate dynamically allocated memory`, but they are used for different types of allocations:

delete p
--------
  
This operator is used to deallocate memory that was allocated for a `single object` using the `new operator`. When `delete p` is called, the destructor of the object pointed to by p is invoked (if p points to an object of a class type), and then the memory occupied by that single object is returned to the heap.  
  
delete[] p
----------
  
This operator is used to deallocate memory that was allocated for an `array of objects` using the `new[] operator`. When `delete[] p` is called, the destructors of each object in the array pointed to by p are invoked (if p points to an array of objects of a class type), and then the entire block of memory occupied by the array is returned to the heap.  
  
For class types, `delete[] p` ensures that the destructor for every object in the array is called, preventing resource leaks or improper state.` delete p` only calls the destructor for a single object.  
  
`delete[] p` correctly deallocates the entire block of memory allocated for the array, while `delete p` when used on an **array** might only deallocate the memory for the **first element** or lead to undefined behavior, potentially causing memory leaks or heap corruption.