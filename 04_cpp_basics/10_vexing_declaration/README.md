Vexing declaration
==================
  
The `"most vexing parse"` refers to a specific syntax ambiguity where a declaration can be interpreted either as the `declaration of a variable` or as the `declaration of a function`.  
The C++ standard mandates that in such ambiguous cases, the **declaration is always interpreted as a function declaration**.  
This can lead to **unexpected behavior** for programmers expecting a variable initialization.  
  
Common scenarios for the most vexing parse:  
- Default-constructing an object with empty parentheses:  
    ```
    class A {};
    A a1(); // This declares a function named 'a1' that takes no arguments and returns an A object.
            // It does NOT create an A object named 'a1' using its default constructor.
    ```
  
- Initializing an object with a temporary object created using functional-style cast:  
    ```
    class B {};
    class C {
    public:
        explicit C(B t) {}
    };

    C c1(B());  // This declares a function named 'c1' that takes a parameter of type 'B()'
                // (which is a function type: a function returning B and taking no arguments) and returns a C object.
                // It does NOT create a C object initialized with a temporary B object.
    ```
  
To avoid the most vexing parse when intending to create and initialize a variable, use:  
- Brace initialization (uniform initialization):  
    ```
    A a1{}; // Creates an A object named 'a1' using its default constructor.
    C c1{B{}}; // Creates a C object initialized with a temporary B object.
    ```
  
- Direct initialization without parentheses for default construction:  
    `A a1; // Creates an A object named 'a1' using its default constructor.`  