Access specifiers - public / private / protected
================================================
Public
------
- Members declared as **public** are accessible from anywhere, both inside and outside the class.
- They can be accessed directly using an object of the class or through pointers/references to the object.
- This is typically used for interfaces and functionalities intended for external use.

Private
-------
- Members declared as **private** are accessible only within the class itself.
- They cannot be accessed directly from outside the class, even through objects or pointers/references.
- This enforces data encapsulation and information hiding, preventing unauthorized external modification of internal state.
- By default, members of a class are **private** if no access specifier is explicitly provided.

Protected
---------
- Members declared as **protected** are accessible within the class itself and by its derived classes (classes that inherit from it).
- They are not accessible directly from outside the class, similar to **private** members, but they allow controlled access for inheritance hierarchies.
- This facilitates code reuse and specialization in object-oriented programming while maintaining a level of encapsulation.

By default, members of a class are **private**, while members of a structs and unions are **public**. It is considered good practice to explicitly define access specifiers for clarity and to enforce proper encapsulation.

Inheritance
-----------
1. **Public inheritance**  
    The **public** and **protected** members of the base class listed after the access specifier **keep their member access** in the derived class.
2. **Protected inheritance**  
    The **public** and **protected** members of the base class listed after the access specifier are **protected** members of the derived class.
3. **Private inheritance**  
    The **public** and **protected** members of the base class listed after the access specifier are **private** members of the derived class.

The **private** members of the base class are **always inaccessible** to the derived class regardless of public, protected, or private inheritance.

In details
----------
Member access does not affect visibility: names of private and privately-inherited members are visible and considered by overload resolution, implicit conversions to inaccessible base classes are still considered, etc.  
**Member access check is the last step** after any given language construct is interpreted. The intent of this rule is that replacing any private with public never alters the behavior of the program.

Access checking for the names used in default function arguments as well as in the default template parameters is performed at the **point of declaration**, not at the point of use.

Access rules for the names of virtual functions are checked at the **call point** using the type of the expression used to denote the object for which the member function is called. The access of the final overrider is ignored:

```
struct B
{
    virtual int f(); // f is public in B
};
 
class D : public B
{
private:
    int f(); // f is private in D
};
 
void f()
{
    D d;
    B& b = d;
 
    b.f(); // OK: B::f is public, D::f is invoked even though it's private
    d.f(); // error: D::f is private
}
```

Further reading: https://en.cppreference.com/w/cpp/language/access.html