Struct vs Class
===============
  
`struct` and `class` are fundamentally very similar constructs used to define user-defined types. The primary and practically only technical difference between them lies in their default member access specifier.  
  
Class
-----
Members (data and functions) declared within a `class` are `private` by default. This means that if you don't explicitly specify public, protected, or private for a member, it will be **private**.  
  
Struct
------
Members (data and functions) declared within a `struct` are `public` by default. This means that if you don't explicitly specify public, protected, or private for a member, it will be **public**.  
  
Typically used for Plain Old Data (POD) structures or simple data aggregations where the primary purpose is to group related data items, and direct access to members is often intended. They are also often used when interfacing with C libraries.  
  
Common
------
Beyond this default access difference, struct and class are virtually identical in C++ functionality.
- Have member functions (methods).
- Have constructors and destructors.
- Support inheritance.
- Contain a mix of public, private, and protected members.