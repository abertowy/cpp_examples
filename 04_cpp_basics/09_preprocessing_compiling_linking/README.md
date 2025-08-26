preprocessing vs compiling vs linking
=====================================
  
Preprocessing
---------------
This is the initial stage where the preprocessor modifies the source code based on preprocessor directives.
- **Actions:**  
    It handles directives like #include (inserting content of header files), #define (macro expansion and constant definition), and conditional compilation directives (#ifdef, #ifndef).  
    It also removes comments.  
- **Output:**  
    A modified, expanded source file that is then passed to the compiler.  
  
Compiling:
----------
This stage translates the preprocessed source code into assembly code and then into machine-level object code.  
- **Actions:**  
    The compiler takes the preprocessed C++ code and translates it into assembly language.  
    Subsequently, an assembler converts this assembly code into machine-readable object files (e.g., .o or .obj files),  
    which contain machine code for the functions and data defined in that specific source file, but do not yet contain addresses for external references.  
- **Output:**  
    One or more object files, each corresponding to a source file.  
  
Linking:
-----------
This is the final stage that combines all the object files and necessary libraries into a single executable program.  
- **Actions:**  
    The linker resolves external references by finding the definitions of functions and variables declared in one object file but defined in another,  
    or in external libraries (e.g., standard library functions). It combines all these pieces of machine code into a single, complete executable file.  
- **Output:**  
    A final executable program (e.g., .exe on Windows, or a file without an extension on Linux).  