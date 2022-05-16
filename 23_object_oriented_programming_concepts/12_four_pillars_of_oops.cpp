/* 
    Topics: Four Pillars of OOPs

   Abouts OOPs:
    - Object-Oriented Programming is a methodology or paradigm to design a program using classes and objects. 

    - It simplifies the software development and maintenance by providing some concepts:
       1. Class
       2. Objects
       3. Abstraction
       4. Encapsulation
       5. Inheritance
       6. Polymorphism

    - Advantage of OOPs over Procedure-oriented programming language
       - OOPs makes development and maintenance easier where as in Procedure-oriented programming language
         it is not easy to manage if code grows as project size grows.
       - OOPs provide data hiding whereas in Procedure-oriented programming language a global data can be 
         accessed from anywhere.
       - OOPs provide ability to simulate real-world event much more effectively. We can provide the solution
         of real word problem if we are using the Object-Oriented Programming language.

    Reference: https://www.javatpoint.com/cpp-oops-concepts

   ----------------------------------------------------------------------------------

   Four Pillars of OOPs:
    1. Abstraction       [Eg: Abstract Classes, Interface & using Access Specifiers - Public, Private, Protected]
    2. Encapsulation     [Eg: Accessing Private members using Getter & Setter]
    3. Inheritance       [Derived class, Base class, Single, Multilevel, Hierarchical, Hybrid & Multiple Inheritance]
    4. Polymorphism      [Overloading, Overriding, virtual function]


  Abstraction:
    - Hiding internal details and showing functionality is known as abstraction. 
      For example: phone call, we don't know the internal processing.
    - In C++, we use abstract class and interface to achieve abstraction.
      
    > Interfaces in C++ (Abstract Classes)
      - Abstract class and interface both can have abstract methods which are necessary for abstraction.
      - C++ Abstract class: In C++ class is made abstract by declaring at least one of its functions as pure "virtual function". 
                            A pure virtual function is specified by placing "= 0" in its declaration & Its implementation must 
                            be provided by derived classes.
                            
      Reference: https://www.javatpoint.com/interfaces-in-cpp

    > Data Abstraction in C++
      - C++ provides a great level of abstraction. 
        For example, pow() function is used to calculate the power of a number without knowing the
                     algorithm the function follows.

      - In C++ program if we implement class with private and public members then it is an example 
        of data abstraction. 
      
      - Data Abstraction can be achieved in two ways:
        1. Abstraction using classes
        2. Abstraction in header files. 

    - Abstraction using Classes:
      - An abstraction can be achieved using classes. 
      - A class is used to group all the data members and member functions into a single unit by using the
        access specifiers. 
      - A class has the responsibility to determine which data member is to be visible outside and 
        which is not.

    - Abstraction in Header files:
      - An another type of abstraction is header file. 
      - For example, pow() function available is used to calculate the power of a number without actually 
        knowing which algorithm function uses to calculate the power. 
      - Thus, we can say that header files hides all the implementation details from the user.

    - Abstraction using access specifiers:
      - Access specifiers are the main pillar of implementing abstraction in C++. 
      - Access Specifiers Implement Abstraction.
      - We can use access specifiers to enforce restrictions on class members. 
      - For example:
        - Members declared as public in a class, can be accessed from anywhere in the program.
        - Members declared as private in a class, can be accessed only from within the class. 
          They are not allowed to be accessed from any part of code outside the class.

      - We can easily implement abstraction using the above two features provided by access specifiers.
    
      Reference:  https://www.javatpoint.com/data-abstraction-in-cpp

      Reference:  https://www.geeksforgeeks.org/abstraction-in-c/



  Encapsulation:
    - Binding (or wrapping) code and data together into a single unit is known as encapsulation. 
      For example: capsule, it is wrapped with different medicines.
 
    - The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users. 
    - To achieve this, you must declare class variables/attributes as private (cannot be accessed from 
      outside the class). If you want others to read or modify the value of a private member, you can 
      provide public get and set methods.

     Reference:  https://www.w3schools.com/CPP/cpp_encapsulation.asp


  Inheritance:
    - When one object acquires all the properties and behaviours of parent object i.e. known as inheritance.
      It provides code reusability. It is used to achieve runtime polymorphism.
    - It is useful for code reusability: reuse attributes and methods of an existing class when you 
      create a new class.

    - In C++, it is possible to inherit attributes and methods from one class to another. 
    - We group the "inheritance concept" into two categories:

       - Derived Class (child) - the class that inherits from another class
       - Base Class (parent) - the class being inherited from

    - To inherit from a class, use the : symbol.

    > Single Inheritance:
    > Multilevel Inheritance: A class can also be derived from one class, which is already derived from another class.
    > Hierarchical Inheritance:
    > Hybrid Inheritance:
    > Multiple Inheritance: A class can also be derived from more than one base class, using a comma-separated list:

    Reference:  https://www.w3schools.com/CPP/cpp_inheritance.asp



  Polymorphism:
    - When one task is performed by different ways i.e. known as polymorphism.
    - For example, think of a base class called Animal that has a method called animalSound(). 
                   Derived classes of Animals could be Pigs, Cats, Dogs, Birds - And they also have 
                   their own implementation of an animal sound (the pig oinks, and the cat meows,etc)
      Reference:  https://www.w3schools.com/CPP/cpp_polymorphism.asp
    
    - Function Overloading
      - If we create two or more members having the same name but different in number or type of parameter, 
        it is known as C++ overloading. 
      - In C++, we can overload:
        - methods,
        - constructors, and
        - indexed properties
        (It is because these members have parameters only.)
        Reference:  https://www.javatpoint.com/cpp-overloading

    - Function Overriding:
       - If derived class defines same function as defined in its base class, it is known as function overriding. 
       - It is used to achieve runtime polymorphism. It enables you to provide specific implementation of the 
         function which is already provided by its base class.
       Eg: create Pig and Dog objects and override the animalSound() method of Animal class.
       Reference:  https://www.javatpoint.com/cpp-function-overriding

    - C++ virtual function
       - A C++ virtual function is a member function in the base class that you redefine in a derived class. 
         It is declared using the virtual keyword.
       - It is used to tell the compiler to perform dynamic linkage or late binding on the function.
       - When the function is made virtual, C++ determines which function is to be invoked at the 
         runtime based on the type of the object pointed by the base class pointer.

       - Late binding or Dynamic linkage
         In late binding function call is resolved during runtime. Therefore compiler determines the type of
         object at runtime, and then binds the function call.

       - Rules of Virtual Function
         - Virtual functions must be members of some class.
         - Virtual functions cannot be static members.
         - They are accessed through object pointers.
         - They can be a friend of another class.
         - A virtual function must be defined in the base class, even though it is not used.
         - The prototypes of a virtual function of the base class and all the derived classes must be identical.
           If the two functions with the same name but different prototypes, C++ will consider them as the
           overloaded functions.
         - We cannot have a virtual constructor, but we can have a virtual destructor
         - Consider the situation when we don't use the virtual keyword.

       Reference:  https://www.javatpoint.com/cpp-virtual-function

*/