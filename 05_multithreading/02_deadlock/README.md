Deadlock
=========
  
`deadlock` is a state where two or more `threads` are **blocked indefinitely**, each waiting for a resource that is held by another `thread` in the same group.  
This results in a standstill where none of the `threads` can proceed, effectively freezing or hanging the program  
  
Necessary Conditions for Deadlock (Coffman Conditions)
-------------------------------------------------------
- **Mutual Exclusion:**  
    **Resources** involved must be **non-sharable**, meaning only one `thread` can hold a resource at a time.  
    This is typically achieved using `mutexes` or similar locking mechanisms.  
- **Hold and Wait:**  
    A `thread` holds at least one resource while waiting to acquire additional resources held by other `threads`.  
- **No Preemption:**  
    Resources cannot be forcibly taken away from a `thread`; they must be voluntarily released by the `thread` holding them.  
- **Circular Wait:**  
    A set of `threads` exists where each `thread` is waiting for a resource held by the next `thread` in the set, forming a circular chain of dependencies.  
  
Common strategies to prevent deadlocks include
----------------------------------------------
- **Consistent Lock Ordering:**  
    Always acquire `locks` in a predefined, consistent order across all `threads`.  
- **std::lock**:  
    Use `std::lock` to acquire multiple `mutexes` simultaneously, ensuring atomicity and preventing deadlocks by acquiring all locks or none.  
- **Resource Hierarchy:**  
    Assign a hierarchy to resources and require `threads` to acquire resources only in increasing order of their hierarchy.  
- **Timeout Mechanisms:**  
    Use `try_lock` with a timeout to attempt acquiring a lock, allowing the `thread` to release held resources and retry later if the lock cannot be acquired within the specified time.