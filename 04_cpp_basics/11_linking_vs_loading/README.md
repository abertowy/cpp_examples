linking vs loading
===================
  
Linking
--------
The primary goal of linking is to **combine** various pieces of **compiled code and data** into a single **executable file** or a shared library.  
After compilation, individual source files are **converted** into `object file`s (`.o` or `.obj`).  
These `object files` contain **machine code** but often have unresolved references to functions or variables defined in other object files or libraries.  
The `linker` **resolves** these references, binding abstract names (like function names) to their concrete memory addresses or offsets within the final executable.  
- **Static Linking:**  
    All necessary library code is directly copied into the executable during linking. This results in **larger executables** but eliminates runtime dependencies on external libraries.  
- **Dynamic Linking:**  
    References to shared libraries (`.dll`, `.so`) are resolved at **runtime**.  
    The executable contains only **pointers** to these **libraries**, which are loaded into memory when the program starts or when a function from the library is first called.  
    This results in **smaller executables** and allows multiple programs to share the same library in memory.  
  
Loading
---------
Brings the executable program or shared library from secondary storage (`hard disk`) into the main memory (`RAM`) so that the CPU can execute its instructions.  
The `loader`, a **component of the operating system**, is responsible for this task.  
It allocates memory for the program, copies the program's code and data segments into that memory, and performs any necessary address adjustments (relocation) to ensure the program runs correctly within its assigned memory space.  
`Loading` typically occurs when a **program is launched**.  
In the case of dynamically linked libraries, they are loaded into memory when the program starts or when a function within them is first accessed.  