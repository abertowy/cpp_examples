Templates
==========
  
Compilation time mechanism  

Code Reusability and Genericity:
---------------------------------
Templates allow for the creation of functions and classes that can operate on different data types without requiring separate implementations for each type. This promotes code reuse and reduces redundancy. For example, a single sort function template can sort arrays of integers, doubles, or custom objects.  
  
Type Safety:
------------
Templates provide compile-time type checking. This means that type mismatches are caught during compilation, rather than at runtime, leading to more robust and reliable code. Unlike solutions using void* or macros, templates ensure that operations are performed on compatible types.  
  
Efficiency and Performance:
-----------------------------
Since templates are instantiated at compile time, the compiler can generate specialized and optimized code for each specific type used. This can result in performance comparable to, or even better than, manually written code for each type, as it avoids runtime overhead often associated with polymorphism or dynamic dispatch.  
  
Flexibility and Generic Programming:
------------------------------------
Templates are a cornerstone of generic programming in C++, enabling the development of highly flexible and adaptable libraries and components. They allow algorithms and data structures to be designed independently of the specific types they will operate on, leading to more maintainable and extensible codebases.  
  
Шаблоны обеспечивают параметрический полиморфизм (времени компиляции)  
  
```
template<typename T>
class Vector {
private:
  T* elem; // elem points to an array of sz elements of type T
  int sz;
public:
  explicit Vector(int s);
  ~Vector() { delete[] elem; }
  T& operator[](int i);
  const T& operator[](int i) const;
  int size() const { return sz; }
};
```
```
template<typename T>
Vector<T>::Vector(int s) {
  if (s<0) {
    throw length_error{"Vector constructor: negative size"};
  }
  elem = new T[s];
  sz = s;
}
```
```
template<typename T>
const T& Vector<T>::operator[](int i) const {
  if (i<0 || size()<=i) {
    throw out_of_range{"Vector::operator[]"};
  }
  return elem[i];
}
```
  
Restricted args
----------------
```
template<Element T> // Element - all vec elemants can be copied
class Vector {
private:
  T* elem;
  int sz;
};
```
  
```
typename T - arg type
int N - arg val

template<typename T, int N>
struct Buffer {
  constexpr int size() { return N; }
  T elem[N];
};
```
  
**Aliases:**  
```
using size_t = unsigned int;
using value_type = T;
```
  
'if' on compilation time
-------------------------
```
template<typename T>
void update(T& target)
{
  if constexpr(is_trivially_copyable_v<T>) {
    simple_and_fast(target);
  }
  else {
    slow_and_safe(target);
  }
}
```
  
Variadic Template
---------------------------------
```
template<typename T>
concept Printable = requires(T t) { std::cout << t; } // just one operation!
void print() {}
template<Printable T, Printable... Tail>
void print(T head, Tail... tail)
{
  cout << head << ' ';
  if constexpr(sizeof...(tail)> 0) {
    print(tail...);
  }
}
```