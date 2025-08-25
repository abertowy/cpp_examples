Multiple Inheritance (rhomboidal scheme) paradigm
=================================================
The `rhomboidal` (or diamond) scheme in C++ multiple inheritance refers to a specific inheritance hierarchy where a class inherits from two classes that both, in turn, inherit from a common base class. This creates a "diamond" shape in the inheritance graph.  
  
The Diamond Problem
-------------------
The `rhomboidal scheme` introduces a challenge known as the "diamond problem." `FinalDerived` inherits `Base` through two distinct paths: `Derived1` -> `Base` and `Derived2` -> `Base`. This leads to ambiguity when `FinalDerived` attempts to access members of `Base`, as the compiler cannot determine which `Base` sub-object to use. For instance, if `Base` has a member value, and `FinalDerived` tries to access value, it becomes ambiguous whether to use Derived1's value or `Derived2`'s value.  
  
Resolution with Virtual Inheritance
-----------------------------------
C++ addresses the diamond problem using virtual inheritance. By declaring the common base class as virtual during inheritance, a single shared instance of the Base sub-object is created for the FinalDerived class, regardless of how many paths lead to it.  
  
Consequences of Virtual Inheritance
------------------------------------
- Single Instance: Ensures only one instance of the virtual base class is present in the derived object.
- Constructor Call Order: Virtual base class constructors are called first, before any non-virtual base class constructors, and only once.
- Performance Overhead: Accessing members of a virtual base class can incur a slight performance overhead due to the need for dynamic resolution to locate the single shared instance.