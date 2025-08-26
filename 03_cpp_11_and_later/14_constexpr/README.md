constexpr
===========
  
`constexpr` is a const expr and it's value is known in compilation time  
Values known on `compilation time` can be placed in `read only` mem  
`const` can be initialized **not** in **compilation time**  
  
`constexpr` fun wiil produce `const compilation time` if they are **called** with `consts compilation time`. **If not - not**  
`constexpr` functions can be used with given and return **ONLY** literal types  