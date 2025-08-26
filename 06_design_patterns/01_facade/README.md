Facade
======
  
The `Facade` design pattern, is a **structural design pattern** that provides a simplified, unified interface to a complex system of classes, library, or framework.  
It acts as a `facade` or `front-facing interface`, **masking the underlying complexity** of the system from client code  
It offers a **high-level, easy-to-use interface**, reducing the need for client code to interact directly with multiple complex components of a subsystem.  
It **minimizes dependencies** between client code and the internal workings of a subsystem.  
Changes within the subsystem's components are less likely to impact client code as long as the `Facade's` interface remains consistent.  
By providing a clear and concise API, it makes the system easier to understand and use.  
  
A `Facade` class typically contains references or pointers to the various components of the complex subsystem it manages.  
Its methods then orchestrate calls to these internal components to fulfill client requests.  
  
Consider a home theater system with components like a DVD player, projector, amplifier, and lights.  
Without a `Facade`, a user would need to interact with each component individually to watch a movie.  
A HomeTheaterFacade class could provide methods like `watchMovie(std::string movieName)` and `endMovie()`.  
The `watchMovie` method would internally handle the sequence of operations across the DVD player, projector, amplifier, and lights, simplifying the process for the user.  