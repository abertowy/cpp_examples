macros
======
  
`Macro` is a `preprocessor directive` that allows for `text substitution` within the source code **before compilation**.  
`Macros` are defined using the `#define` directive and are processed by the preprocessor, not the compiler.  
`Macros` can be undefined using the `#undef` directive to remove their definition.  
  
**Object-like macros:** These `macros` resemble data objects and are used for **simple text replacement**, often to define symbolic constants.  
`  #define PI 3.14159`
  
**Function-like macros:** These `macros` behave like functions and can accept arguments, allowing for more complex code generation and substitution.  
 ` #define SQUARE(x) ((x) * (x))`
  
- **Preprocessing:**  
    `Macros` are expanded during the preprocessing phase, before the actual compilation.  
- **Text substitution:**  
    They perform simple text substitution, which can sometimes lead to **unexpected behavior** if not used carefully (e.g., issues with operator precedence or side effects).  
- **No type safety:**  
    Unlike functions, `macros` are **not type-safe** and do not perform type checking.  
- **Potential for side effects:**  
    Expressions with side effects (like x++) can behave unexpectedly when used within `macros` due to multiple evaluations.  
- **Alternatives:**  
    `const`, `constexpr`, `inline functions`, and `templates` are often preferred over `macros` for their type safety, scope control, and better debugging capabilities.  
- **Use cases:**  
    `Macros` are still used in specific scenarios, such as conditional compilation (`#ifdef`, `#ifndef`), platform-specific configurations, or for certain debugging purposes.  