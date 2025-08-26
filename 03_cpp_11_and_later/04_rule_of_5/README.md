Rule of 5
==========
  
The `"Rule of Five"` is a guideline stating that if a class requires a user-defined implementation of any of the following five special member functions, it should provide user-defined implementations for all of them:
- Destructor
- Copy Constructor
- Copy Assignment Operator
- Move Constructor
- Move Assignment Operator
  
The core principle behind the Rule of Five is `resource management`.  
If a class manages resources (e.g., `dynamically allocated memory`, `file handles`, `network connections`) that require explicit cleanup in its `destructor`, then the **default-generated** `copy` and `move` operations might not handle these resources correctly  
  
**Double Deletion:** Multiple objects attempting to free the same resource.  
**Memory Leaks:** Resources not being properly released.  
**Incorrect Resource Sharing:** Copies or moves resulting in unintended shared ownership of resources.