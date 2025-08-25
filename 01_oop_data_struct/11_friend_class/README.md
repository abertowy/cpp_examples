Friend class/function
=====================
  
`friend class` or a `friend function` is a mechanism that grants special access privileges to a non-member function or an entire class, allowing them to access the private and protected members of another class.  
  
**Friend Function** is a non-member function that is declared as a friend inside a class. This declaration gives the function permission to directly access the private and protected data members and member functions of that class, even though it is not a member of the class itself.  
```
    friend void displayPrivateData(const MyClass& obj)
```
  
**Friend class** is a class that is declared as a friend inside another class. This declaration grants all member functions of the friend class the ability to access the private and protected members of the class that declared it as a friend.  
```
    class MyClass {
    private:
        int privateValue;
    public:
        MyClass(int val) : privateValue(val) {}
        friend class FriendClass; // Friend class declaration
    };

    void FriendClass::accessMyClass(MyClass& obj) {
        // Can access privateValue because FriendClass is a friend of MyClass
        std::cout << "Accessed private value: " << obj.privateValue << std::endl;
    }
```
  
- **Not Mutual**  
    Friendship is not automatically mutual. If ClassA declares ClassB as a friend, ClassB can access ClassA's private/protected members, but ClassA cannot automatically access ClassB's private/protected members.  
- **Encapsulation Consideration**  
    While useful for specific scenarios (e.g., operator overloading, tight coupling between related classes), excessive use of friend can weaken encapsulation and make code harder to maintain.  