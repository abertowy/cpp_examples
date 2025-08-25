Public, private and virtual inheritance
=======================================

Public Inheritance
------------------
- Public members of the base class remain public in the derived class.
- Protected members of the base class remain protected in the derived class.
- Private members of the base class are not directly accessible in the derived class.
- Public inheritance represents an "is-a" relationship, meaning the derived class is a type of the base class.
  
Private Inheritance
-------------------
- Public and protected members of the base class become private in the derived class.
- Private members of the base class are not directly accessible in the derived class.
- Private inheritance represents an "implemented-in-terms-of" relationship, where the derived class uses the base class's implementation but does not expose its interface publicly.
  
Protected Inheritance
---------------------
- Public and protected members of the base class become protected in the derived class.
- Private members of the base class are not directly accessible in the derived class.
- Protected inheritance allows derived classes to access the base class's members, but these members are not accessible from outside the derived class hierarchy.
  
Virtual Inheritance
--------------------
- Virtual inheritance is used in multiple inheritance scenarios to solve the "diamond problem," where a class inherits from two classes that both inherit from a common base class, leading to multiple instances of the common base.
- By using virtual keyword during inheritance, only one shared instance of the virtual base class is created, preventing ambiguity and redundancy.