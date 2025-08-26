Composition vs Aggregation
==========================

`Composition` and `Aggregation` are two specific types of `"has-a"` **relationships** in OOP, particularly relevant for defining how objects relate to each other.  
The key distinction lies in the **lifetime dependency** and **ownership** of the contained object.  

Composition
--------------
- **Strong "has-a" relationship:**  
    Represents a whole-part relationship where the part cannot exist independently of the whole.  
- **Ownership:**  
    The composite (whole) object is responsible for the creation and destruction of its component (part) objects.  
- **Lifetime Dependency:**  
    If the composite object is destroyed, its component objects are also destroyed.  
- **Implementation:**  
    Often implemented by embedding the component object directly as a member variable within the composite class, or by using smart pointers like std::unique_ptr to manage the component's lifetime.  
  
**Example:** A Car composed of Engine and Wheels. An Engine cannot exist meaningfully without a Car, and if the Car is destroyed, its Engine and Wheels are also conceptually destroyed with it.  
  
Aggregation
------------
- **Weak "has-a" relationship:**  
    Represents a whole-part relationship where the part can exist independently of the whole.  
- **No Ownership:**  
    The aggregator (whole) object does not own the aggregate (part) object; it merely uses or references it. The aggregate object's lifetime is managed externally.  
- **Independent Lifetime:**  
    The aggregate object can exist even if the aggregator object is destroyed.  
- **Implementation in C++:**  
    Typically implemented using pointers or references to the aggregate object, which is created and managed elsewhere.  
  
**Example:** A Department aggregating Professor objects. A Professor can exist independently of a specific Department and might even be associated with multiple departments. If the Department is dissolved, the Professor still exists.  