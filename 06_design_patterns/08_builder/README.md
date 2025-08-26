Builder
========
  
`Builder` design pattern is a **creational pattern** that **separates the construction** of a complex object from its **representation**.  
This allows the same construction process to **create different representations** of an object.  
It is particularly useful when an object has a **large number of optional parameters or configurations**, avoiding the issue of `"telescoping constructors"` (multiple constructors with increasing numbers of parameters).  
  
Components
----------
- **Product:**  
    The **complex object** that is being built. It typically has a set of attributes or components that can be configured.  
- **Builder Interface (Abstract Builder):**  
    Declares the **interface** for creating parts of the `Product` object. It defines the methods for building each component of the product.  
- **Concrete Builder:**  
    Implements the `Builder` **interface** to construct and assemble parts of the `product`.  
    It provides a **specific implementation** for building each component and typically includes a method to **retrieve** the `final product`.  
- **Director (Optional):**  
    **Manages** the construction process. It uses a `Builder` object to construct the product in a specific sequence or configuration.  
    The `Director` knows the **steps** to build a `product` but **not the details** of how each step is implemented.  
- **Client:**  
    **Creates** a `Concrete Builder` object and optionally **passes** it to a `Director` to initiate the construction process.  
    The `Client` then retrieves the f`inal product` from the `Builder`.  
  
Advantages of using the Builder pattern
----------------------------------------
- **Improved Readability:**  
    Makes object creation more readable, especially when dealing with objects having many optional parameters.  
- **Flexibility:**  
    Allows for creating different representations of an object using the same construction process.  
- **Encapsulation:**  
    Encapsulates the complex object construction logic within the builder classes, separating it from the product class.  
- **Extensibility:**  
    Easier to add new types of products or new ways of constructing existing products without modifying existing code.  
- **Avoids Telescoping Constructors:**  
    Eliminates the need for multiple constructors with varying numbers of arguments.  
  
Typical Implementation Steps
-----------------------------
- Define the Product class with its various attributes.
- Create an abstract Builder interface (or base class) with methods for building each part of the Product.
- Implement one or more ConcreteBuilder classes that inherit from the Builder interface and provide specific implementations for building the Product parts. These methods typically return *this to enable method chaining (fluent interface).
- Add a build() or getProduct() method to the ConcreteBuilder to return the assembled Product.
- (Optional) Create a Director class to orchestrate the building process by calling the appropriate builder methods in a defined sequence.
- In the client code, create a ConcreteBuilder instance, call its building methods (potentially through a Director), and then retrieve the final Product.