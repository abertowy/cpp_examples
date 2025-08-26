Decorator
=========

`Decorator` is a **structural pattern** that allows for the **dynamic addition of new behaviors** or responsibilities to individual objects without altering their underlying class structure.  
It achieves this by wrapping concrete components with decorator objects that share the same interface as the components they decorate.  
  
Components
-----------
- **Component Interface:**  
    An `abstract base class` or `interface` that defines the common operations for both concrete components and decorators.  
    This ensures that `decorators` and `components` can be used interchangeably.  
- **Concrete Component:**  
    The `original object` to which new responsibilities will be added. It **implements** the `Component interface`.  
- **Decorator Base Class:**  
    An `abstract class` that also **implements** the `Component interface` and holds a reference to a `Component object`.  
    This class serves as the base for all concrete decorators.  
- **Concrete Decorators:**  
    Classes that **inherit** from the `Decorator base class` and add specific **new functionalities**.  
    They override the `operation()` method to add their own behavior before or after calling the wrapped component's `operation()`.  
  
How it works
------------
- A `ConcreteComponent` is created.
- `ConcreteDecorator` objects are created, each wrapping the previous `Component` (either a `ConcreteComponent` or another `Decorator`).
- When `operation()` is called on the outermost `Decorator`, it delegates the call to its wrapped `Component`, which in turn delegates to its wrapped `Component`, and so on, until the `ConcreteComponent's` `operation()` is executed.
- Each `Decorator` adds its own specific behavior during this chain of calls.
  
Benefits
---------
- **Flexibility:** New functionalities can be added dynamically at runtime.
- **Composition over Inheritance:** Avoids the explosion of subclasses that can occur when extending functionality through inheritance.
- **Open/Closed Principle:** Allows extending functionality without modifying existing code.