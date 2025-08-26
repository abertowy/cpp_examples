Synchronisation mechanism
=========================
  
Managing access to shared resources in multithreaded environments, preventing data corruption and ensuring correct program behavior.  
  
Mutexes (std::mutex)
-----------------------
Provide mutual exclusion, ensuring that only one thread can access a critical section of code at a time.  
std::lock_guard and std::unique_lock are RAII wrappers that simplify mutex management by automatically acquiring and releasing the lock.  
  
Condition Variables (std::condition_variable)
---------------------------------------------
Allow threads to wait for a specific condition to become true.  
A waiting thread releases its mutex and blocks until another thread notifies the condition variable, typically after changing the shared state that the waiting thread is interested in.  
  
Semaphores (C++20: std::counting_semaphore)
-------------------------------------------
A counting and signaling mechanism that can be used to control access to a limited number of resources or to signal between threads.  
  
Latches (C++20: std::latch)
---------------------------
A one-shot synchronization primitive that allows a group of threads to wait until a certain number of operations have completed.  
Once the count reaches zero, all waiting threads are released, and the latch cannot be reused.  
  
Barriers (C++20: std::barrier)
------------------------------
Similar to latches but reusable.  
Threads wait at a barrier until a specified number of threads have reached it, then all are released, and the barrier can be reset for subsequent phases of synchronization.  
  
Atomic Operations (std::atomic)
-------------------------------
Provide thread-safe operations on individual variables without the need for explicit locking.  
These are suitable for simple, low-level synchronization where performance is critical.  
  
Spin Locks
----------
A type of mutex where a thread repeatedly checks a lock variable in a loop until it becomes available.  
They can be efficient for very short critical sections but consume CPU resources while waiting.  
