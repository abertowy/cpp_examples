SFINAE
======
  
`substitution failure is not an error`  
This rule applies during overload resolution of function templates:  
    When substituting the explicitly specified or deduced type for the template parameter fails, the specialization is discarded from the overload set instead of causing a compile error.  
  
This feature is used in template metaprogramming.  
  
Function template parameters are substituted (replaced by template arguments) twice:
- explicitly specified template arguments are substituted before template argument deduction
- deduced arguments and the arguments obtained from the defaults are substituted after template argument deduction
  
Substitution occurs in:
- all types used in the function type (which includes return type and the types of all parameters)
- all types used in the template parameter declarations
- all types used in the template argument list of a partial specialization
- all expressions used in the function type
- all expressions used in a template parameter declaration
- all expressions used in the template argument list of a partial specialization
- all expressions used in the explicit specifier (`since C++20`)
  
A substitution failure is any situation when the type or expression above would be ill-formed (with a required diagnostic), if written using the substituted arguments.  
  
Only the failures in the types and expressions in the immediate context of the function type or its template parameter types or its explicit specifier(`since C++20`) are `SFINAE` errors. If the evaluation of a substituted type/expression causes a side-effect such as instantiation of some template specialization, generation of an implicitly-defined member function, etc, errors in those side-effects are treated as hard errors. A lambda expression is not considered part of the immediate context.(`since C++20`)  
  
Substitution proceeds in lexical order and stops when a failure is encountered.  
  
If there are multiple declarations with different lexical orders (e.g. a function template declared with trailing return type, to be substituted after a parameter, and redeclared with ordinary return type that would be substituted before the parameter), and that would cause template instantiations to occur in a different order or not at all, then the program is ill-formed; no diagnostic required.
  
```
template<typename A>
struct B { using type = typename A::type; };

template<
    class T,
    class U = typename T::type,    // SFINAE failure if T has no member type
    class V = typename B<T>::type> // hard error if B has no member type
                                   // (guaranteed to not occur via CWG 1227 because
                                   // substitution into the default template argument
                                   // of U would fail first)
void foo (int);

template<class T>
typename T::type h(typename B<T>::type);

template<class T>
auto h(typename B<T>::type) -> typename T::type; // redeclaration

template<class T>
void h(...) {}

using R = decltype(h<int>(0));     // ill-formed, no diagnostic required
```
  
SFINAE errors
-------------
- attempting to instantiate a pack expansion containing multiple packs of different lengths
- attempting to create an array of void, array of reference, array of function, array of negative size, array of non-integral size, or array of size zero:
```
template<int I>
void div(char(*)[I % 2 == 0] = nullptr)
{
    // this overload is selected when I is even
}

template<int I>
void div(char(*)[I % 2 == 1] = nullptr)
{
    // this overload is selected when I is odd
}
```
- attempting to use a type on the left of a scope resolution operator :: and it is not a class or enumeration:
```
template<class T>
int f(typename T::B*);
 
template<class T>
int f(T);
 
int i = f<int>(0); // uses second overload
```
- attempting to use a member of a type, where
-- the type does not contain the specified member
-- the specified member is not a type where a type is required
-- the specified member is not a template where a template is required
-- the specified member is not a non-type where a non-type is required
- attempting to create a pointer to reference
- attempting to create a reference to void
- attempting to create pointer to member of T, where T is not a class type:
```
template<typename T>
class is_class
{
    typedef char yes[1];
    typedef char no[2];
 
    template<typename C>
    static yes& test(int C::*); // selected if C is a class type
 
    template<typename C>
    static no& test(...);       // selected otherwise
public:
    static bool const value = sizeof(test<T>(nullptr)) == sizeof(yes);
};
```
- attempting to give an invalid type to a constant template parameter:
```
template<class T, T>
struct S {};
 
template<class T>
int f(S<T, T()>*);
 
struct X {};
int i0 = f<X>(0);
// todo: needs to demonstrate overload resolution, not just failure
```
- attempting to perform an invalid conversion in
-- in a template argument expression
-- in an expression used in function declaration
- attempting to create a function type with a parameter of type void
- attempting to create a function type which returns an array type or a function type
  
Further reading: https://en.cppreference.com/w/cpp/language/sfinae.html