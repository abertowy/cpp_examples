Proxy
=====
  
The `Proxy` Design Pattern is a **structural design pattern** that provides a **substitute** or placeholder **for another object** to **control access to it**.  
It acts as an intermediary, allowing for additional functionalities like `access control`, `lazy initialization`, `caching`, `logging`, or `remote communication` before or after accessing the real object.  
  
Components
----------
- **Subject Interface:**  
    It defines the `common interface` for both the `Real Subject` and the `Proxy`, ensuring they are interchangeable from the client's perspective  
- **Real Subject:**  
    The actual object that performs the core logic and is resource-intensive or sensitive.  
- **Proxy:**  
    Maintains a reference to the `Real Subject` and implements the `Subject interface`. It **controls access** to the `Real Subject` and can add extra behavior.  
- **Client:**  
    Interacts with the `Subject interface`, unaware whether it's dealing with the `Real Subject` or the `Proxy`.  
  
The client interacts with the `Proxy` object as if it were the `Real Subject`.  
The `Proxy` then intercepts these requests and can perform various actions before or after delegating the request to the `Real Subject`.  
  
- **Virtual Proxy:** Delaying the creation and initialization of expensive objects until they are actually needed (`lazy loading`).
- **Protection Proxy:** Controlling access to the Real Subject based on certain permissions or conditions.
- **Remote Proxy:** Providing a local representation for an object located in a different address space.
- **Smart Reference:** Adding additional behavior like reference counting or logging object access.