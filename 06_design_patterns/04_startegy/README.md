Strategy
========
  
`Strategy` is a **behavioral pattern** that e**ncapsulates a family of algorithms**, making them interchangeable.  
It allows an algorithm **to be selected at runtime**, promoting flexibility and reusability.  
  
Components
----------
- **Strategy Interface (Abstract Strategy):**  
    This is an `abstract class` or `interface` that declares a `common interface` for all supported algorithms.  
    It defines the `contract` that all concrete strategies must adhere to.  
- **Concrete Strategies:**  
    These are classes that **implement** the `Strategy interface`, providing specific implementations of the algorithms.  
    Each `concrete strategy` represents a different way of performing the same task.  
- **Context:**  
    This class **maintains a reference** to a `Strategy object` and delegates the execution of the algorithm to the linked strategy.  
    The `Context` does not know the concrete type of the strategy, only interacts with it through the `Strategy interface`.  
  
Usage
-----
The client code can create a `Context` object and inject a specific `Concrete Strategy` at **runtime**, or change the strategy dynamically.  
  
The `Strategy` pattern promotes the `Open/Closed Principle`, allowing new strategies to be added without modifying existing client code or the `Context`.  
It also separates the algorithm's implementation from its usage, leading to more **maintainable** and **flexible** designs.  
  
Examples vector sum, sorting, etc