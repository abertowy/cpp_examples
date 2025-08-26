sizeof structure (padding)
===========================
  
`sizeof operator` used on a structure (`struct`) returns the total memory occupied by an instance of that structure, including any padding bytes added by the compiler. This **padding** is a mechanism used by compilers to ensure proper data alignment in memory, which can significantly improve performance for accessing structure members.  

Alignment Requirements
----------------------
  
Different data types have specific alignment requirements. For instance, an int might need to be aligned on a 4-byte boundary, while a double might require an 8-byte boundary. This means their memory addresses must be a multiple of their respective alignment values.  
  
Compiler Optimization
---------------------
  
To meet these alignment requirements and optimize memory access, compilers may insert **padding bytes** between structure members or at the end of the structure. This ensures that each member starts at an address that is a multiple of its size or the largest alignment requirement within the structure.  
  
Impact on sizeof
----------------
  
Because `sizeof` reports the total memory allocated for the structure, it includes these padding bytes. Consequently, the value returned by `sizeof(struct_name)` or `sizeof(struct_variable)` might be greater than the sum of the sizes of individual members.  
```
struct Example {
    char c;    // 1 byte
    int i;     // 4 bytes
    char d;    // 1 byte
};
```
  
`sizeof(ex)` might output 12 bytes, even though the sum of the individual member sizes is `1 + 4 + 1 = 6 bytes`. This is because the compiler likely adds padding after c to align i on a 4-byte boundary, and potentially padding at the end of the structure to ensure the overall size is a multiple of the largest alignment requirement (which is 4 bytes for int in this case).  
  
While compilers typically handle **padding** automatically, some compilers offer directives like `#pragma` pack to control or disable padding, allowing for more compact memory layouts, though this can sometimes come at the cost of performance.  