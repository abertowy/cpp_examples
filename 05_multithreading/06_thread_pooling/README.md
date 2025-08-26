Thread Pooling
==============
  
A `thread pool` is a collection of pre-initialized and reusable threads designed to manage and execute tasks concurrently.  
Instead of creating and destroying `threads` for each task, which incurs overhead, a `thread pool` **maintains a set of worker threads** that can be assigned tasks from a queue.  
This approach significantly **improves performance** and resource utilization in applications requiring frequent or numerous concurrent operations.  
  
Components
----------
- Task Queue:  
    A thread-safe data structure (e.g., std::queue protected by a std::mutex and std::condition_variable) where tasks are submitted by the main thread or other threads.
- Worker Threads:  
    A fixed or dynamically sized group of threads that continuously fetch and execute tasks from the task queue.  
- Synchronization Mechanisms:  
    std::mutex: To protect shared resources, especially the task queue, from concurrent access by multiple threads.  
    std::condition_variable: To allow worker threads to wait when the task queue is empty and to be notified when new tasks are added.  
- Task Management:  
    A mechanism to encapsulate tasks, typically using std::function or std::packaged_task, allowing various callable objects to be submitted.  
- Result Handling (Optional):  
    Using std::future to retrieve results from asynchronously executed tasks.  
  
How it Works:
- The thread pool is initialized with a specified number of worker threads.
- These worker threads enter a loop, waiting on a condition variable.
- When a task is submitted to the pool, it is added to the task queue, and the condition variable is notified, waking up one or more waiting worker threads.
- A woken worker thread acquires a lock, retrieves a task from the queue, and releases the lock.
- The worker thread executes the task.
- Upon completion, the worker thread returns to waiting on the condition variable for new tasks.
  
Benefits of using a Thread Pool:
- Reduced Overhead: Minimizes the overhead associated with thread creation and destruction.
- Improved Performance: Reusing threads leads to faster task execution.
- Resource Management: Limits the number of active threads, preventing resource exhaustion.
- Simplified Concurrency: Provides a structured way to manage concurrent tasks.