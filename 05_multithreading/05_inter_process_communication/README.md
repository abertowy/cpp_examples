Inter Process communication
============================
  
Inter-Process Communication (IPC) involves various mechanisms allowing separate processes to exchange data and synchronize their actions.  
This is crucial for applications that require multiple independent processes to collaborate, such as microservices or systems with heavy, isolated tasks  
  
Common IPC mechanisms in C++ include
------------------------------------
1. Pipes:  
    - **Unnamed Pipes:**  
        Primarily used for communication between related processes (parent-child) where one process writes and another reads from a shared pipe (typically unidirectional)  
    - **Named Pipes (FIFOs):**  
        Allow communication between unrelated processes by providing a named entry point in the file system, enabling processes to open and interact with the pipe like a regular file.  
2. Shared Memory:  
    Provides the most efficient IPC mechanism by mapping a region of memory into the address space of multiple processes, allowing direct access and modification of shared data.  
    This eliminates the need for data copying through the kernel. Synchronization primitives (like semaphores or mutexes) are essential to prevent race conditions.  
3. Message Queues:  
    Enable processes to exchange messages by placing them into a system-managed queue and retrieving them.  
    This provides a structured way to send and receive data packets, often with message prioritization.  
4. Sockets:  
    - **Unix Domain Sockets:**  
        Facilitate communication between processes on the same machine, often offering better performance than network sockets for local IPC.  
        They operate through the file system.  
    - **Network Sockets (TCP/IP):**  
        Used for communication between processes on different machines or for more complex network-based interactions on the same machine.
5. Signals:  
    A basic, asynchronous mechanism for sending simple notifications or events between processes.  
    They are primarily used for signaling events rather than data exchange.  
6. Boost.Interprocess:  
    A C++ library within the Boost framework that simplifies the use of shared memory, message queues, and other IPC mechanisms, offering a more portable and convenient interface.  
7. Flow-IPC:  
    toolkit designed for high-performance IPC, particularly focused on efficient sharing and transmission of data structures with minimal copying, especially relevant for C++17  