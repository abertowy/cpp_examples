lvalue vs rvalue
================
  
The distinction between `lvalues` and `rvalues` is crucial for understanding `move semantics` and `rvalue` references
`Rvalue` references allow for efficient transfer of resources from temporary objects (rvalues) without costly deep copies, leading to performance improvements in certain scenarios.  
  
Lvalue (left hand side)
-----------------------
- An `lvalue` represents an object that occupies a persistent, identifiable memory location (i.e., it has an address).
- `Lvalues` can appear on the `left-hand side` of an assignment operator, meaning their **value can be modified**.
- Examples include variable names, array elements, and function calls returning lvalue references.  
  
Any `const-qualified` type is also considered to be an `lvalue`, but it can never appear on the left hand side of an assignment statement because it can not be modified.  
So, the term `"modifiable lvalue"` was created to refer to an lvalue that can be modified, and a `const-qualified` type does not fall into this category.  
  
Rvalue (right hand side)
------------------------
- An `rvalue` represents a temporary value or an object that does not have a persistent, identifiable memory location.
- `Rvalues` typically appear on the `right-hand side` of an assignment operator and cannot be assigned to directly.
- Examples include `literal constants`, `temporary objects` created by expressions, and function calls `returning values by copy`
  
Addressability
--------------
- `lvalues` have a stable memory address that can be taken (using the & operator)
- `rvalues` typically do not have an address that persists beyond the expression.
  
Modifiability
-------------
- `lvalues` can be modified (assigned to)
- `rvalues` generally cannot be assigned to directly.
  
Lifetime
---------
- `lvalues` persist beyond the expression in which they are created
- `rvalues` are temporary and typically destroyed at the end of the full expression