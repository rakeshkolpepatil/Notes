
### <span style="color: #e1881c">  10. Inheritance  </span>
  - Inheritance is one of the core principles of `Object-Oriented Programming (OOP)` that allows a class to inherit properties and methods from another class.
  - In Dart, inheritance helps to promote code reuse and establishes relationships between classes, making the code more maintainable and structured. 

  #### <i> <span style="color: #32CD32 "> 10.1 What is Inheritance? </span> </i>
  - Inheritance in Dart allows one class (called the subclass or child class) to inherit the properties and methods of another class (called the superclass or parent class). 
  - This provides a way to create a hierarchy of classes, where the child class extends the functionality of the parent class without rewriting code.

    |Superclass         | The class that is being inherited from.      |
    |-------------------|--------------------------------------------- |
    |Subclass           | The class that inherits from the superclass. |
    |Method Overriding  | Allows a subclass to provide a specific implementation of a method that is already defined in the superclass. |

  #### <i> <span style="color: #32CD32 "> 10.2 Basic Inheritance </span> </i>
  - In Dart, inheritance is implemented using the `extends` keyword. When a class `extends` another class, it inherits all `non-private members` (properties and methods) of the superclass.
    ```dart
    class Animal {
      void eat() {
        print("Animal is eating");
      }
    }

    class Dog extends Animal {
      void bark() {
        print("Dog is barking");
      }
    }

    void main() {
      var dog = Dog();
      dog.eat();        // Inherited from Animal
      dog.bark();       // Defined in Dog
    }
    // Output:
    //    Animal is eating
    //    Dog is barking
    ```
  - Explanation
    - In this example, the Dog class inherits the eat() method from the Animal class. 
    - Additionally, Dog defines its own method, bark(). 
    - This demonstrates the basic idea of inheritance: reusing code from the parent class while adding specific functionality in the child class.

  #### <i> <span style="color: #32CD32 "> 10.3 Method Overriding  </span> </i>
  - In Dart, a subclass can override a method of the superclass. 
  - This is useful when the subclass needs to provide a specific implementation of a method that is already defined in the superclass.
    ```dart
    class Animal {
      void sound() {
        print("Animal makes a sound");
      }
    }

    class Cat extends Animal {
      @override
      void sound() {
        print("Cat meows");
      }
    }

    void main() {
      var cat = Cat();
      cat.sound(); // Output: Cat meows
    }
    ```
  - Explanation:
    - In this example, the Cat class overrides the sound() method of the Animal class using the `@override` annotation. 
    - Although the Animal class has a sound() method, the Cat class provides its own implementation.

  #### <i> <span style="color: #32CD32 "> 10.4 `super` Keyword  </span> </i>
  - The `super` keyword in Dart is used to refer to the superclass and its members. 
  - It allows the child class to call the parent class’s constructor, methods, or properties.

    ```dart
      class Vehicle {
        void start() {
          print("Vehicle started");
        }
      }

      class Car extends Vehicle {
        @override
        void start() {
          super.start();  // Calls the start method of Vehicle
          print("Car started");
        }
      }

      void main() {
        var car = Car();
        car.start();  
        // Output:
        // Vehicle started
        // Car started
      }
    ```
  - Explanation:
    - In the Car class, the start() method first calls the start() method of the Vehicle class using super.start(), and then it adds its own implementation. 
    - This is a great way to extend the functionality of a parent class method.

  #### <i> <span style="color: #32CD32 "> 10.5 Constructors and Inheritance  </span> </i>
  - When a `subclass` is instantiated, the constructor of the superclass is automatically called before the constructor of the subclass. 
  - You can explicitly call a superclass constructor using super() in the subclass’s constructor.
  
    ```dart
    class Person {
      String name;
      Person(this.name);

      void introduce() {
        print("Hi, my name is $name");
      }
    }

    class Employee extends Person {
      String company;

      Employee(String name, this.company) : super(name);  // Calls the Person constructor

      @override
      void introduce() {
        super.introduce();  // Calls the Person's introduce method
        print("I work at $company");
      }
    }

    void main() {
      var emp = Employee("John", "Google");
      emp.introduce();
      // Output:
      // Hi, my name is John
      // I work at Google
    }
    ```
  - Explanation:
    - In this example, the Employee class inherits from the Person class. The Employee constructor explicitly calls the Person constructor using super(name). 
    - Additionally, the introduce() method of the Employee class overrides the one in Person but still calls the superclass version using super.introduce().

  #### <i> <span style="color: #32CD32 "> 10.6 Inheritance and Private Variables  </span> </i>
  - In Dart, private variables (those prefixed with an underscore _) in a class are not inherited by subclasses. 
  - This ensures encapsulation of private data. 
  - Subclasses cannot directly access private members of their parent classes.
    
    ```dart
    class Parent {
      String _secret = "This is private";

      void showSecret() {
        print(_secret);
      }
    }

    class Child extends Parent {
      void display() {
        // print(_secret);  // Error: '_secret' is private and cannot be accessed
        print("Trying to access private data");
      }
    }

    void main() {
      var child = Child();
      child.display(); // Output: Trying to access private data
    }
    ```
  - Explanation
    - In this case, the _secret variable is private to the Parent class, and the Child class cannot directly access it. 
    - This preserves encapsulation even in an inheritance hierarchy.

  #### <i> <span style="color: #32CD32 "> 10.7 Multiple Inheritance in Dart  </span> </i>
  - Dart does not support multiple inheritance, meaning a class cannot inherit from more than one class. 
  - However, Dart supports a feature called `Mixins`, which allows you to reuse code from multiple sources.
    ```dart
    mixin CanFly {
      void fly() {
        print("Flying...");
      }
    }

    class Bird with CanFly {}

    void main() {
      var bird = Bird();
      bird.fly();  // Output: Flying...
    }
    ```
  - Explanation
    - Mixins allow a class like Bird to use code from multiple sources, simulating the effect of multiple inheritance. 
    - In this example, Bird can “inherit” the fly() method from the CanFly mixin.

  #### Best Practices for Inheritance in Dart
   1. **Use Inheritance Wisely**\
      Inheritance is a powerful tool, but it should be used when a true `“is-a”` relationship exists between the parent and child classes.\
      For example, a Dog is an Animal, but a Car is not a Vehicle in every case.

   2. **Avoid Deep Inheritance Chains**\
      Having deep chains of inheritance can make the code difficult to maintain and understand. It’s better to keep inheritance hierarchies shallow.\
   
   3. **Leverage Composition Over Inheritance**\
      In some cases, using composition (where objects are composed of other objects) can be more flexible than inheritance.


---
  ### <span style="color: #e1881c">  11. Polymorphism in Dart </span>
  - Polymorphism refers to the ability of different classes to respond to the same method call in their own way. 
  - In Dart, this is achieved through method overriding and interface implementation, where a subclass can provide its specific implementation for a method defined in the superclass. 
  - Polymorphism ensures that the same method behaves differently for different objects, enhancing flexibility and reusability.

    #### <i> <span style="color: #32CD32 "> Key Concepts of Polymorphism in Dart </span> </i>
    - **Method Overriding**\
      A subclass provides a specific implementation of a method that is already defined in the superclass.

    - **Interfaces**\
      Classes can implement interfaces (abstract classes or normal classes) to define their specific behaviors.

    - **Dynamic Dispatch**\
      The correct method is called based on the actual object at runtime, not at compile time.

    #### <span style="color: #32CD32 "> 11.1  Method Overriding </span> 
    - Method Overriding is a form of polymorphism in which a subclass provides a specific implementation of a method already defined in its superclass. 
    - The `@override` annotation is used in Dart to indicate that a method is being overridden.
    
      ```dart
      class Animal {
      void sound() {
          print("Animal makes a sound");
        }
      }

      class Dog extends Animal {
        @override
        void sound() {
          print("Dog barks");
        }
      }

      class Cat extends Animal {
        @override
        void sound() {
          print("Cat meows");
        }
      }

      void main() {
        Animal myDog = Dog();
        Animal myCat = Cat();

        myDog.sound();  // Output: Dog barks
        myCat.sound();  // Output: Cat meows
      }
      ```
    - Both the Dog and Cat classes inherit from the Animal class but override the sound() method to provide their specific implementations. 
    - This demonstrates polymorphism because the same method sound() behaves differently for different objects

    #### <span style="color: #32CD32 "> 11.2  Polymorphism with Interfaces </span> 
    - Polymorphism in Dart can also be achieved through interfaces. 
    - In Dart, every class can act as an interface, meaning that other classes can implement that class to inherit its properties and methods, or define their specific behavior for the methods.
    
      ```dart
      abstract class Shape {
        void draw();  // Abstract method
      }

      class Circle implements Shape {
        @override
        void draw() {
          print("Drawing a circle");
        }
      }

      class Rectangle implements Shape {
        @override
        void draw() {
          print("Drawing a rectangle");
        }
      }

      void main() {
        Shape shape1 = Circle();
        Shape shape2 = Rectangle();

        shape1.draw();  // Output: Drawing a circle
        shape2.draw();  // Output: Drawing a rectangle
      }
      ```

    #### <span style="color: #32CD32 "> 11.3 Dynamic Dispatch </span> 
    - In polymorphism, `dynamic dispatch refers to the process by which a method call is resolved at runtime, not at compile time.` 
    - This ensures that the correct method implementation is called based on the actual object, even if the method is invoked using 
      a reference of the superclass type.
      
      ```dart
      class Employee {
        void work() {
          print("Employee works");
        }
      }

      class Manager extends Employee {
        @override
        void work() {
          print("Manager oversees work");
        }
      }

      class Developer extends Employee {
        @override
        void work() {
          print("Developer writes code");
        }
      }

      void main() {
        Employee emp = Manager();
        emp.work();  // Output: Manager oversees work

        emp = Developer();
        emp.work();  // Output: Developer writes code
      }
      ```
    - The Employee reference `emp` is used to invoke the work() method, but the actual method called is determined at runtime based 
      on the object (Manager or Developer) assigned to the reference. 
    - This is the essence of dynamic dispatch in polymorphism.

    #### <span style="color: #32CD32 "> 11.4 Polymorphism in Collections </span> 
    - Polymorphism is often used in collections, where a list of objects can contain different types of objects that share a common superclass or interface. 
    - Each object in the collection can respond to the same method call in its unique way.

      ```dart
      class Animal {
        void sound() {
          print("Some animal sound");
        }
      }

      class Dog extends Animal {
        @override
        void sound() {
          print("Dog barks");
        }
      }

      class Cat extends Animal {
        @override
        void sound() {
          print("Cat meows");
        }
      }

      void main() {
        List<Animal> animals = [Dog(), Cat()];

        for (var animal in animals) {
          animal.sound();  // Output: Dog barks, Cat meows
        }
      }
      ```
    - A list of Animal objects contains instances of both Dog and Cat. 
    - When iterating through the list, each object responds to the sound() method according to its specific implementation, demonstrating polymorphism in collections.

    #### <span style="color: #32CD32 "> 11.5 Benefits of Polymorphism </span> 
    - Polymorphism provides several key benefits in Dart, especially in the context of object-oriented programming:
      
      - **Code Reusability**\
        Polymorphism allows you to write more reusable code. For example, a method can operate on objects of a superclass or interface type, without needing to know the specifics of each subclass or implementation.

      - **Flexibility**\
        Polymorphism increases the flexibility of the code by allowing the same interface or superclass to be used for different object types.

      - **Extensibility**\
        It makes the system more extendable since new classes can be added without modifying existing code, as long as they implement the necessary methods.

---

  ### <span style="color: #e1881c">  12.  Encapsulation  </span>
  - Encapsulation is bundling of data (variables) and methods that operate on that data into a single unit, usually a class, while restricting direct access to some of the object’s components to prevent unauthorized access and enhance code maintainability and flexibility.
  - In Dart, encapsulation uses private variables, getters, setters, and access control mechanisms.
  - Encapsulation refers to protecting an object’s internal state from unintended interference and misuse by external code. 
  - To achieve this, class properties are made private, while public methods are provided to access and update these properties safely.

    #### <span style="color: #32CD32 "> Key Concepts of Encapsulation in Dart </span>
      - ****Private Variables**\
        To begin with, data within a class can be made private by using the underscore (_) prefix.

      - **Getters and Setters**\
        Additionally, getters and setters are utilized to access and modify private data.

      - **Access Modifiers**\
        Unlike other languages, Dart does not have public, protected, or private keywords. Instead, it uses underscores (_) to define private access within libraries.

  #### <span style="color: #32CD32 ">12.1  Private Variables </span>
  - Any variable or method prefixed with an underscore (_) is considered private to its library. 
  - Consequently, this approach effectively hides the internal state of a class from other parts of the code.

    ```dart
    class Employee {
      String _name;  // Private variable
      int _age;      // Private variable

      Employee(this._name, this._age);

      void displayInfo() {
        print('Name: $_name, Age: $_age');
      }
    }

    void main() {
      var emp = Employee('Alice', 30);
      emp.displayInfo();      // Output: Name: Alice, Age: 30
      // emp._name = 'Bob';   // Error: '_name' is private
    }
    ```

  #### <span style="color: #32CD32 ">12.2  Getters and Setters </span>
  - Controlled access to private properties is achieved using Getters and Setters in Dart. Getters retrieve private variable values, while setters modify them.

    ```dart
    class BankAccount {
      double _balance;  // Private variable

      BankAccount(this._balance);

      // Getter for balance
      double get balance => _balance;

      // Custom Getter for balance
      double get balanceWithdrawable => _balance - 500;

      // Setter for balance
      set balance(double amount) {
        if (amount >= 0) {
          _balance = amount;
        } else {
          print('Invalid amount');
        }
      }
    }

    void main() {
      var account = BankAccount(1000);
      print('Current balance: \$${account.balance}');  // Output: Current balance: $1000
      account.balance = 1500;  // Using setter
      print('Updated balance: \$${account.balance}');  // Output: Updated balance: $1500
      account.balance = -500;  // Output: Invalid amount
    }
    ```
  - **Getter**\
    Getters are methods used to retrieve or “get” the value of a private property.\
    Allows reading the value of `_balance`.

  - **Setter**\
    Setter methods are used to assign or “set” the value of a private property with some validation or conditions.\
    Allows modifying the value of `_balance` with validation logic.

  - **Benefits of Getters and Setters**
    - **Data Validation** \
      Setters allow you to validate the data before assigning it to a private variable, ensuring that only valid values are set.

    - **Encapsulation**\
      By providing indirect access to private variables, getters and setters help maintain the integrity of the class’s internal state.

    - **Controlled Access**\
      You can add custom logic in getters and setters to control how variables are accessed or modified.

    - **Flexibility**\
      You can modify the internal implementation of a getter or setter without changing how external code interacts with the class.


  #### <span style="color: #32CD32 ">12.3 Encapsulation with Immutable Objects </span>
  - Dart allows the creation of immutable objects using final variables. 
  - This ensures that once an object is created, its state cannot be changed.
    
    ```dart
    class Student {
      final String _name;
      final int _age;

      const Student(this._name, this._age);

      String get name => _name;  // Getter
      int get age => _age;       // Getter
    }

    void main() {
      var student = Student('Bob', 20);
      print('Name: ${student.name}, Age: ${student.age}');  // Output: Name: Bob, Age: 20
      // student.name = 'Alice';                            // Error: The setter 'name' isn't defined
    }
    ```
  - Immutable Objects: The `Student` class is immutable because its properties are `final` and do not have `setters`.

  #### <span style="color: #32CD32 ">12.4 Encapsulation in Libraries </span>
  - In Dart, the underscore (_) makes a variable or method private to its library. 
  - As a result, this allows encapsulation to extend beyond a single class and apply to an entire library.

    File: library1.dart
    ```dart
    // library1.dart
    class LibraryClass {
      String _secret = "This is private to the library";

      void showSecret() {
        print(_secret);
      }
    }
    ```
    
    File: main.dart
    ```dart 
    // main.dart
    import 'library1.dart';

    void main() {
      var lib = LibraryClass();
      lib.showSecret();         // Output: This is private to the library
      // print(lib._secret);    // Error: '_secret' isn't accessible from outside the library
    }
    ```
  - The `_secret` variable is private to library1.dart and cannot be accessed in main.dart.

  #### <span style="color: #32CD32 ">  Best Practices for Encapsulation </span>

  1. **Use Private Variables for Sensitive Data**\
    Always mark sensitive data as private using an underscore `(_)`.

  2. **Use Getters and Setters**\
    Instead of providing direct access to class fields, use getters and setters to control and validate data access.

  3. **Minimize the Exposure of Internal State**\
    Only expose what is necessary for the external use of the class.

  4. **Follow the Principle of Least Privilege**\
    Give access to data and methods only to the extent necessary for a class to perform its function.

---
  ### <span style="color: #e1881c">  13. Abstraction </span>

  - Abstraction refers to hiding the complex implementation details of a class and showing only the essential features. 
  - It allows developers to work with higher-level concepts without worrying about the intricacies of how they work. 
  - This is achieved through `abstract classes` and `interfaces`.

  #### <span style="color: #32CD32 ">  Key Concepts of Abstraction in Dart </span>
  
  - **Abstract Classes**\
    A class that cannot be instantiated and is meant to be extended by other classes.
  
  - **Abstract Methods**\
    Methods declared in an abstract class without a body, leaving the implementation to the subclasses.
  
  - **Interfaces**\
    Any class can serve as an interface in Dart, enabling abstraction by requiring other classes to implement specific methods.

  #### <span style="color: #32CD32 "> 13.1 Abstract Classes </span>
  - Abstract classes are classes that cannot be instantiated and are defined using the `abstract` keyword. 
  - They serve as blueprints for other classes, providing a common interface for subclasses while leaving the actual implementation details to them.
    ```dart
    abstract class Animal {
      void sound();  // Abstract method with no implementation

      void eat() {
        print("Animal is eating");
      }
    }

    class Dog extends Animal {
      @override
      void sound() {
        print("Dog barks");
      }
    }

    class Cat extends Animal {
      @override
      void sound() {
        print("Cat meows");
      }
    }

    void main() {
      var dog = Dog();
      dog.sound();  // Output: Dog barks
      dog.eat();    // Output: Animal is eating

      var cat = Cat();
      cat.sound();  // Output: Cat meows
    }
    ```
  - The `Animal class` is abstract and defines an abstract method `sound()`, but it also contains `a concrete method eat()`.\
    The Dog and Cat classes inherit from Animal and provide their own implementation for the sound() method.
  - The abstract class provides a framework for the child classes, ensuring they implement the necessary methods while sharing common functionality like eat().

  #### <span style="color: #32CD32 "> 13.2 Abstract Methods </span>
  - An `abstract method` is a method that is declared in an `abstract class` but has no body. 
  - Subclasses are required to provide an implementation for these methods. 
  - Abstract methods are used when you want to ensure that certain functionality is implemented in all subclasses but the specific implementation may vary.
    
    ```dart
    abstract class Shape {
      void calculateArea();  // Abstract method
    }
    
    class Circle extends Shape {
      double radius;
    
      Circle(this.radius);
    
      @override
      void calculateArea() {
        print("Area of Circle: ${3.14 * radius * radius}");
      }
    }
    
    class Rectangle extends Shape {
      double length, width;
    
      Rectangle(this.length, this.width);
    
      @override
      void calculateArea() {
        print("Area of Rectangle: ${length * width}");
      }
    }
    
    void main() {
      var circle = Circle(5);
      circle.calculateArea();       // Output: Area of Circle: 78.5
    
      var rectangle = Rectangle(4, 5);
      rectangle.calculateArea();    // Output: Area of Rectangle: 20
    }    
    ```
  - In this example, the `Shape` abstract class defines an abstract method `calculateArea()`.\
    The `Circle` and `Rectangle` classes implement the `calculateArea()` method in their specific ways.

  #### <span style="color: #32CD32 "> 13.3 Interfaces and Abstraction </span>
  - In Dart, any class can act as an interface, and other classes can implement it. 
  - Unlike abstract classes, classes that implement an interface must provide concrete implementations for all of the methods declared in the interface.
    
    ```dart
    class Printer {
      void printDocument();  // Abstract method by default
    }
    
    class LaserPrinter implements Printer {
      @override
      void printDocument() {
        print("Laser Printer printing document...");
      }
    }
    
    class InkjetPrinter implements Printer {
      @override
      void printDocument() {
        print("Inkjet Printer printing document...");
      }
    }
    
    void main() {
      Printer laserPrinter = LaserPrinter();
      laserPrinter.printDocument();   // Output: Laser Printer printing document...
    
      Printer inkjetPrinter = InkjetPrinter();
      inkjetPrinter.printDocument();  // Output: Inkjet Printer printing document...
    }  
    ```
  - Here, `Printer` acts as an interface, and both `LaserPrinter` and `InkjetPrinter` implement the `printDocument()` method.\
    This ensures that both printer types can be used interchangeably under the Printer interface while providing different implementations for the same method.

  #### <span style="color: #32CD32 "> 13.4 Abstract Classes vs Interfaces </span>
  - While both abstract classes and interfaces promote abstraction, there are key differences:
    - **Abstract Classes** : Can contain both abstract and concrete methods. They are intended to be extended by a single subclass.
    - **Interfaces** : Classes that implement an interface must provide concrete implementations for all methods. Interfaces can be implemented by multiple classes.

  - When to Use Abstract Classes:
    - When you want to define common behavior that multiple classes can inherit.
    - When some methods will have a default implementation while others need to be overridden.

  - When to Use Interfaces:
    - When you want to define a contract that multiple classes can implement, without sharing any concrete behavior.

  #### <span style="color: #32CD32 "> 13.5 Best Practices for Abstraction in Dart </span>
  - **Use Abstraction to Simplify Complex Systems**\
    Abstract away the complex implementation details and expose only the necessary functionalities.

  - **Combine Abstraction with Other OOP Principles** \
    Use abstraction in conjunction with encapsulation, inheritance, and polymorphism for well-structured and maintainable code.

  - **Avoid Unnecessary Abstraction**\
    Only abstract when it adds value to the design. Overuse of abstraction can lead to overly complex code.


---
  ### <span style="color: #e1881c"> 14. Operator Overloading </span>

  #### <span style="color: #32CD32 "> 14.1 What is Operator Overloading? </span>
  - Operator overloading enables a class to define its own implementation for standard operators. 
  - This means that you can specify how operators behave when applied to instances of your class. 
  - For instance, if you have a Vector class, you can overload the `+` operator to add two vectors together in a way that makes sense for your application.
  
    ```dart
    class Complex {
      final double real;
      final double imaginary;

      Complex(this.real, this.imaginary);

      // Overloading the '+' operator
      Complex operator +(Complex other) {
        return Complex(real + other.real, imaginary + other.imaginary);
      }

      // Overriding toString method
      @override
      String toString() {
        return '$x+$yi';
      }
    }
    ```
  - The `+` operator is overloaded for the Complex class, allowing two complex numbers to be added together using the `+` operator.
  - Dart allows you to overload a variety of operators, including:
  
    |Type Of Operator          | Operator List        |
    |--------------------------| ---------------------|
    |  Arithmetic Operators    |  +, -, *, /, ~/, %   |
    |  Comparison Operators    |  ==, !=, <, >, <=, >=|
    |  Unary Operators         |  -, ++, --           |
    |  Indexing Operator       |  []                  | 
    |  String Representation   |  toString()          |

  - Operator overloading is a valuable feature in Dart that enhances the expressiveness and usability of your custom classes. 
  - By allowing operators to be defined in a way that is natural for the data types being manipulated, you can create code that is easier to read and maintain.



# `Extends` Vs `Implements` keyword

In Dart, the keywords **extends** and **implements** are used for different purposes in object-oriented programming, specifically regarding class inheritance and interface implementation. Here’s a detailed comparison:

## Extends

- **Purpose**: The `extends` keyword is used when a class inherits from another class, establishing an "is-a" relationship. This means the subclass can inherit properties and methods from the parent class.
- **Single Inheritance**: Dart supports single inheritance, meaning a class can only extend one superclass. This prevents complexities associated with multiple inheritance.
- **Method Overriding**: When using `extends`, the subclass can override methods from the parent class, but it is not mandatory to do so. The subclass inherits all non-private methods and properties from the parent class.
- **Use Case**: Typically used when you want to create a more specific version of a class.

### Example of Extends
```dart
class Animal {
  void move() {
    print('The animal moves');
  }
}

class Dog extends Animal {
  void bark() {
    print('The dog barks');
  }
}

void main() {
  Dog dog = Dog();
  dog.move();       // Inherited from Animal
  dog.bark();       // Defined in Dog
}
```

## Implements

- **Purpose**: The `implements` keyword is used when a class promises to fulfill the contract defined by an interface. This means the class must provide concrete implementations for all abstract methods declared in the interface.
- **Multiple Interfaces**: A class can implement multiple interfaces, allowing for greater flexibility and code reuse.
- **Mandatory Method Implementation**: Unlike `extends`, when using `implements`, the implementing class must override all methods of the interface, even if they have default implementations in the superclass.
- **Use Case**: Used when you want to define a contract that other classes must adhere to without providing any implementation details.

### Example of Implements
```dart
abstract class Animal {
  void move();
}

class Dog implements Animal {
  @override
  void move() {
    print('The dog moves');
  }

  void bark() {
    print('The dog barks');
  }
}

void main() {
  Dog dog = Dog();
  dog.move(); // Must be implemented
  dog.bark(); // Defined in Dog
}
```

## Key Differences

| Feature                | Extends                                | Implements                                   |
|------------------------|----------------------------------------|--------------------------------------------- |
| Relationship Type      | Inheritance (is-a relationship)        | Interface contract (can-do relationship)     |
| Number of Classes      | Can extend only one class              | Can implement multiple interfaces            |
| Method Inheritance     | Inherits methods, can override         | Must implement all methods                   |
| Typical Use Case       | When one class is a type of another    | When enforcing method signatures             |

In summary, use `extends` when you want to create a subclass that inherits behavior from a superclass, allowing for method overriding and shared functionality. Use `implements` when you want to ensure that a class adheres to an interface's contract by implementing all required methods without inheriting any implementation details. Understanding these distinctions is essential for effective Dart programming and designing robust applications.

Citations:
1. https://piembsystech.com/extends-vs-with-vs-implements-in-dart-language/
2. https://www.geeksforgeeks.org/dart-extends-vs-with-vs-implements/
3. https://stackoverflow.com/questions/73206120/what-is-the-difference-between-implements-keyword-and-extends-keyword-in-dar
4. https://www.topcoder.com/thrive/articles/dart-differences-between-extends-implements-and-mixin
5. https://www.youtube.com/watch?v=PrJaBCfGyrY
6. https://www.youtube.com/watch?v=F-k5YCPeon8
7. https://www.youtube.com/watch?v=2BEv5VuGGuE
8. https://howtoflutter.dev

