static vs dynamic lib
======================
  
`static` and `dynamic` libraries represent two distinct approaches to linking external code with an application.  
The primary difference lies in when the library code is integrated and how it is managed during execution  
  
Static Libraries (.lib, .a):
----------------------------
- Linking: library's compiled code is directly embedded into the final executable during the compilation and linking phase.
- Dependencies: the executable becomes self-contained, as it includes all necessary library code. This means no external library files are needed at runtime.
- Size: Executable files linked with static libraries are typically larger because they contain a copy of all used library code.
- Deployment: Easier deployment as only the executable needs to be distributed.
- Updates: Requires recompilation of the entire application if the static library is updated.
  
Dynamic (Shared) Libraries (.dll, .so, .dylib):
-----------------------------------------------
- Linking: The library's code is not embedded in the executable but is loaded into memory at runtime when the application starts or when a specific function from the library is called.
- Dependencies: The executable depends on the presence of the dynamic library file(s) on the system at runtime.
- Size: Executable files linked with dynamic libraries are generally smaller as they only contain references to the library, not the code itself.
- Deployment: Requires distributing both the executable and the necessary dynamic library files.
- Updates: Allows for updates to the library without recompiling the entire application, as long as the interface remains compatible.  
  Multiple applications can also share a single copy of the dynamic library in memory, potentially saving resources.  