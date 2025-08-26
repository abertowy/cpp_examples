Difference between abstract factory and builder
===============================================
  
Abstract Factory
----------------
Provides an **interface** for creating families of related or dependent objects without specifying their concrete classes.  
It focuses on creating "families of products".  
Defines an `abstract factory` **interface** with **methods for creating each product** in the family.  
Concrete factories implement this interface to produce specific product variations.  
  
When a system needs to be independent of how its products are created, composed, and represented, or when a family of related product objects needs to be created.  
**For example**, creating GUI elements (buttons, menus) for different operating systems.  
  
Builder
-------
**Separates the construction** of a complex object from its **representation**, allowing the same construction process to create different representations.
It focuses on constructing a single, complex object step-by-step.  
Defines a `builder` **interface** with **methods for building different parts of the complex object**.  
A director class orchestrates the building process by calling these builder methods in a specific sequence.  
  
When the construction of a complex object should be independent of its parts and how they are assembled, or when the object's construction process allows for different representations.  
**For example**, building different types of reports (HTML, PDF) from the same data.  
  
Key Differences
-----------------
1. Scope of Creation:
    - **Abstract Factory** creates families of objects
    - **Builder** constructs a single complex object step-by-step.
2. Complexity of Creation:
    - **Abstract Factory** handles the creation of multiple related objects, often with simpler individual creation processes.
    - **Builder** addresses the complexity of assembling a single object with many parts or options.
3. Return Value:
    - **Abstract Factory** methods typically return an instance of a product directly.
    - **Builder** methods often return the builder itself (for chaining) until a final build() method is called to return the constructed object.
4. Control over Construction:
    - With **Abstract Factory**, the client requests specific products from the factory.
    - With **Builder**, a director class often controls the sequence of building steps, delegating the actual construction to the builder.
