lambda
=======

`[&](int a){ return a<x; }`
  
`[ ]` - nothing will be captured  
`[&]` - all local vars are captured by reference  
`[=]` - all local vars are captured by value (copied)  
`[x]` - x is copied  
`[&x]` - x is captured by ref  
  
Useful for **predicates** in algorithmes (example: predicate for `std::count_if`)
```
vector<unique_ptr<Shape>> v;
for_each(v,[](unique_ptr<Shape>& ps){ ps->rotate(45); });
```
  
Initialization
--------------
```
vector<int> v = [&] {
  switch (m) {
  case zero:	return vector<int>(n);
  case seq:	return vector<int>{p,q};
  case cpy:	return arg;
 }
}();
```