Fork
=====
  
`fork()` system call is used to create a *new process*, known as the `child` process, which is an almost **exact duplicate** of the calling process, known as the `parent` process.  
This system call is primarily used in Unix-like operating systems (Linux, macOS, etc.) and is not directly available on Windows without emulation layers.  
  
When `fork()` is called, the operating system creates a new process that is a copy of the parent process.  
This includes **copies** of the parent's memory space, open file descriptors, and other process-related information.  
  
The `fork()` function returns different values in the parent and child processes:  
- **In the parent process:** `fork()` returns the Process ID (`PID`) of the newly created child process.
- **In the child process:** `fork()` returns `0`.
- **On failure:** `fork()` returns `-1` in the parent process, and no child process is created.
  
After the `fork()` call, both the `parent` and `child` processes continue execution from the instruction immediately following the `fork()` call.
This requires conditional logic (e.g., using if statements to check the return value of `fork()`) to differentiate between the `parent` and `child` and execute different code paths for each.  
  
Differences between Parent and Child Processes
-----------------------------------------------
- **PID:** The `child` process has a unique `PID`, different from the `parent's` `PID`.
- **Parent PID:** The `child` process's `parent PID` (`PPID`) is set to the `PID` of the process that called `fork()`.
- **Resource Sharing:** While the `child` process initially inherits copies of the parent's resources (like file descriptors), they are distinct copies.  
    Changes made to resources in one process do not directly affect the other, unless explicit inter-process communication mechanisms are used.  