Adapter design pattern
======================
  
`Adapter` design pattern is a **structural pattern** that allows objects with **incompatible interfaces** to collaborate.  
It acts as a wrapper or a bridge, **translating the interface** of one class (the `Adaptee`) into another interface (the `Target`) that a client expects.  
This enables classes that couldn't otherwise work together due to interface mismatches to interact seamlessly.  
  
Components
----------
- **Target:**  
This is the **interface** that the client code expects to interact with.  
- **Adaptee:**  
This is the existing class with the **incompatible interface** that needs to be **adapted**.  
- **Adapter:**  
This class implements the `Target` **interface** and contains an **instance** of the `Adaptee`.  
It **translates calls** from the client (through the `Target` interface) into calls that the `Adaptee` can understand and execute.  
  
How it Works
------------
- The `Adapter` class essentially **adapts** the `Adaptee's` interface **to match** the `Target` interface.
- When the client calls a method on the `Adapter` (using the `Target` interface), the `Adapter` **translates** this call into the corresponding method call on the `Adaptee`, effectively bridging the incompatibility.
  
Common Use Cases
----------------
- **Integrating Legacy Code:**  
    When incorporating older code or libraries into a modern system, the Adapter pattern can be used to make the legacy code conform to the new system's interfaces without modifying the original code.  
- **Third-Party Library Integration:**  
    Similar to legacy code, if a third-party library has an interface that doesn't directly align with your application's design, an Adapter can be used to make it compatible.  
- **Providing Alternative Interfaces:**  
    When you need to offer a different or simplified interface to an existing class, the Adapter pattern can achieve this without altering the original class.  
  
Example
-------
Imagine you have a LegacyPrinter class with an oldPrint() method, but your current system expects a Printer interface with a print() method.  
An PrinterAdapter class would implement the Printer interface and internally call legacyPrinter.oldPrint() when its print() method is invoked.  