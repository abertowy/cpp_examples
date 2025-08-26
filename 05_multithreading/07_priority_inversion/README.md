Priority inversion
==================
  
`Priority inversion` refers to a scheduling anomaly that can occur in real-time or multi-threaded systems using priority-based, preemptive scheduling, especially when shared resources are involved.  
It happens when a **high-priority thread is blocked** or delayed **by a lower-priority thread**, effectively inverting their intended execution order.  
  
Mechanism of Priority Inversion
--------------------------------
- A low-priority thread (L) acquires a shared resource, typically protected by a mutex or semaphore.
- A high-priority thread (H) becomes ready to run and attempts to acquire the same shared resource.  
  Since L holds the resource, H is blocked and must wait for L to release it.  
- A medium-priority thread (M), which does not need the shared resource, becomes ready and preempts L.  
  Because M has a higher priority than L, the operating system's scheduler allows M to run, even though L is holding a resource that H needs.  
- As a result, H, the highest-priority thread, is indirectly blocked by M (which prevents L from releasing the resource) and is unable to execute.
  
Consequences
------------
- Violated Real-time Deadlines: High-priority tasks in real-time systems might miss their deadlines, leading to system instability or failure
- Unpredictable Behavior: The timing and responsiveness of high-priority tasks become unpredictable.
- Reduced System Performance: Overall system performance can degrade due to inefficient resource utilization.
  
Solutions in C++ (and generally in RTOS)
----------------------------------------
1. Priority Inheritance Protocol:  
When a high-priority thread attempts to acquire a resource held by a low-priority thread, the low-priority thread's priority is temporarily elevated to that of the waiting high-priority thread.  
This allows the low-priority thread to quickly complete its critical section and release the resource, minimizing the blocking time for the high-priority thread.  
Once the resource is released, the low-priority thread's priority reverts to its original level.  
2. Priority Ceiling Protocol:  
Each shared resource is assigned a "priority ceiling" which is the highest priority of any task that might access that resource.  
When a thread acquires a resource, its priority is immediately raised to the resource's priority ceiling.  
This prevents any lower-priority or medium-priority threads from preempting the resource-holding thread.  
3. Careful Resource Design:  
Minimize the time spent in critical sections and consider alternative synchronization mechanisms if priority inversion is a persistent issue.  
4. Avoidance:  
In some simpler embedded systems, priority inversion can be avoided by careful system design and resource allocation to prevent contention between tasks of vastly different priorities.  