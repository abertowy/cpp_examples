Observer
========
  
The `Observer` pattern is a **behavioral design pattern** that establishes a **one-to-many dependency** (one `subject` and many `observers`) between objects.  
In this pattern, when one object (the `subject`) **changes** its state, all its dependents (`observers`) are **notified and updated** automatically.  
The `Observer` pattern is the easiest and most widely used behavioral pattern to implement **event-based communication**  

Components
----------
- **Subject:**  
    It holds the `state` being observed. It maintains a list of `observers` and provides methods for **subscribing, unsubscribing, and notifying** `observers`.  
- **Observer:**  
    This is the `interface` that defines the **update** method, which the subject calls to **notify** `observers` of any state changes.  
- **Concrete Subject:**  
    This is a subclass of the subject class, which **implements** the **specific behavior** of subscribing, unsubscribing, and notifying `observers`.  
    It also contains the actual state that `observers` are interested in.  
- **Concrete Observer:**  
    This is a subclass of the `observer` interface that implements the **update** method.  
    Each concrete `observer` can define its behavior for handling **updates** from the subject.  
  
Usage
------
- **Publisher** acts as the `subject`, responsible for managing a list of subscribers and publishing messages.
- **Observer** defines the **interface** for receiving updates (messages).
- **ConcreteObserver** implements **specific behavior** for handling messages.
- In the main() function, we create a **Publisher** instance and two **ConcreteObserver** instances.
- The `observers` are attached to the `publisher` using the `attach()` method.
- Messages are published using the `publish()` method of the **publisher**, which **notifies** all `observers` by calling their `update()` method.
- Each `observer` **reacts** to the message by printing it to the console, simulating message processing.