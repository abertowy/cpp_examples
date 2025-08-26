Initialization
==============
  
```
A a1;       // DFT CTOR
A a2 = a1;  // COPY CTOR
a1 = a2;    // copy operator operator=()
```

uniform (braced) initialization
-------------------------------
```
int x {0};
vector <int> y {1, 2, 3};
atomic <int> z {0};
```
  
BUT !!!
------
```
double x, y, z;
int sum {x + y + z}; // FAILURE
```
  
Vexing ???
----------
```
A a1(10);   // OK, CTOR
A a2();     // fun a2 declaration
A a3{};     // OK, CTOR
```
  
CTOR with initializer_list is used if possible (preferrable) -> A a3{1, true} -> call initializer_list CTOR even if type should be casted  
```
A a4{} -> call DFT CTOR!
A a5({}) -> CTOR with blank initializer_list

vector <int> v1 (10, 20);   // v1.size() = 10, v1[0] .. v1[9] = 20
vector <int> v2 {10, 20};   // v2.size() = 2,  v2[0] = 10, v2[1] = 20
```
  
NULLPTR
--------
```
0 => INT
NULL -> INT or LONG
nullptr -> pointer to any type
```
  
using is pretty much the same as typedef, but cann be directly used in templates