Functor
=======
  
`Functor`, also known as a `function object`, is an object that can be called as if it were a function.  
This is achieved by **overloading** the function call operator, `operator()`, within a class or struct  
  
Overloaded operator()
---------------------
The core of a functor is the overloaded operator(). This special operator allows instances of the class to be invoked using the familiar function call syntax (e.g., object_name(arguments)).  
  
Statefulness
------------
Unlike regular functions, functors are objects and can therefore hold internal state (member variables). This allows them to maintain information between calls to operator(), enabling more complex and adaptable behavior.  
  
Encapsulation
--------------
Functors encapsulate both data (state) and behavior (the operator() implementation) within a single entity, promoting modularity and reusability.  
  
Uses of functors
----------------
- **Customizable algorithms:**  
    Functors are widely used in STL algorithms (e.g., std::sort, std::for_each) to provide custom comparison logic or actions.
- **Callbacks and event handling:**  
    They can serve as flexible callbacks, allowing different behaviors to be executed based on specific events or conditions.
- **Stateful operations:**  
    When a function needs to maintain state across multiple invocations, a functor provides a clean and efficient way to achieve this.
- **Implementing policies:**  
    Functors can be used to define different policies or strategies that can be swapped at runtime.