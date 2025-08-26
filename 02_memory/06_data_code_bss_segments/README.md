data/code/bss segments
======================
  
program's memory is typically divided into several segments, each serving a specific purpose. Three fundamental segments are the code (or text) segment, the data segment, and the BSS (Block Started by Symbol) segment.  
  
Code (or Text) Segment
----------------------
This segment stores the compiled machine code instructions of the program. It is typically read-only to prevent accidental modification of the program's logic during execution. This includes the executable instructions for all functions, including main().  
  
Data Segment
---------------
This segment stores initialized global and static variables. These are variables that exist throughout the program's lifetime and have a specific initial value assigned to them in the source code. For example, int global_var = 10; would reside in the data segment.  
  
BSS Segment
-----------
This segment stores uninitialized global and static variables, as well as those explicitly initialized to zero. The name "BSS" originates from an old assembler directive. Variables in this segment are not explicitly stored in the executable file, but their size is noted. When the program loads, the operating system or startup code automatically initializes these variables to zero. For example, static int uninitialized_static; or int zero_initialized_global = 0; would reside in the BSS segment. This optimization reduces the size of the executable file since only the size of the BSS segment needs to be stored, not the actual zero values.  