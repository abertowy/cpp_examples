Explicit constructor
====================
  
`explicit` keyword is used with constructors to prevent implicit type conversions.  
`explicit` keyword is primarily used with constructors that can be called with a single argument:
- Single-argument constructors: Any constructor that takes exactly one argument, or multiple arguments where all but one have default values.
- Constructors with std::initializer_list: Although they can take multiple elements, if the constructor can be invoked with a single std::initializer_list, explicit can be applied.
  
Implicit conversions can sometimes lead to unexpected behavior or incorrect logic, especially when a conversion is performed that the programmer did not intend. For example, if a class `MyClass` has a constructor `MyClass(int x)`, and you try to pass an int where a `MyClass` object is expected, the compiler might implicitly construct a `MyClass` object, which might not be the desired behavior.  
  
Implicit conversions can make code harder to understand by obscuring the actual type conversions taking place. Explicitly requiring the conversion makes the code's intent clearer.  
  
In some cases, implicit conversions might involve creating temporary objects, which can have performance implications. Preventing these unintended conversions can help avoid unnecessary object creations.  
  
DEFAULT CTOR will be generated if you didn't define any CTORS  
