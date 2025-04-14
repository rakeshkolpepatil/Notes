  ### <span style="color: #e1881c">  7.  Constructors  </span>
  - Constructor names can be either `ClassName` or `ClassName.identifier`. 
  - For example, the following code creates Point objects using the `Point()` and `Point.fromJson()` constructors.
  
    ```dart
    var p1 = Point(2, 2);
    var p2 = Point.fromJson({'x': 1, 'y': 2});
    // The 'new' keyword while creating an objects using constructor is optional.
    var p1 = new Point(2, 2);
    var p2 = new Point.fromJson({'x': 1, 'y': 2});
    ```
    #### `7.1 Generative constructors`
    - Creates new instances and initializes instance variables.
      ```dart
      class Point {
        // Instance variables to hold the coordinates of the point.
        double x;
        double y;
        // Generative constructor with initializing formal parameters:
        Point(this.x, this.y);
      }
      ```
    #### `7.2 Default constructors`
    - Used to create a new instance when a constructor hasn't been specified. It doesn't take arguments and isn't named.
    - If you don't declare a constructor, Dart uses the default constructor. The default constructor is a generative constructor without arguments or name.
    #### `7.3 Named constructors`
    - Clarifies the purpose of a constructor or allows the creation of multiple constructors for the same class.
    - Use a named constructor to implement multiple constructors for a class or to provide extra clarity
      ```dart
      const double xOrigin = 0;
      const double yOrigin = 0;
      class Point {
        final double x;
        final double y;
        // Sets the x and y instance variables
        // before the constructor body runs.
        Point(this.x, this.y);
        // Named constructor
        Point.origin()
            : x = xOrigin,
              y = yOrigin;
      }
      ```
    - A subclass doesn't inherit a superclass's named constructor. To create a subclass with a named constructor defined in the superclass, implement that constructor in the subclass.
    #### `7.4 Constant constructors`
    - Creates instances as compile-type constants.
    - If your class produces unchanging objects, make these objects compile-time constants. To make objects compile-time constants, define a const constructor with all instance variables set as `final`.
      ```dart
      class ImmutablePoint {
        static const ImmutablePoint origin = ImmutablePoint(0, 0);
        final double x, y;
        const ImmutablePoint(this.x, this.y);
      }
      ```
    - Constant constructors don't always create constants. They might be invoked in a non-const context.
  
    - Constructing two identical compile-time constants results in a single, canonical instance.
      ```dart
      var a = const ImmutablePoint(1, 1);
      var b = const ImmutablePoint(1, 1);
      assert(identical(a, b)); // They are the same instance!
      ```
    - Within a constant context, you can omit the const before a constructor or literal. For example, look at this code, which creates a const map:
      ```dart 
      // Lots of const keywords here.
      const pointAndLine = const {
        'point': const [const ImmutablePoint(0, 0)],
        'line': const [const ImmutablePoint(1, 10), const ImmutablePoint(-2, 11)],
      };
      ```
      - You can omit all but the first use of the `const` keyword
        ```dart 
        // Only one const, which establishes the constant context.
        const pointAndLine = {
          'point': [ImmutablePoint(0, 0)],
          'line': [ImmutablePoint(1, 10), ImmutablePoint(-2, 11)],
        };
        ```
    - If a `constant constructor` is outside of a `constant` context and is invoked without `const`, it creates a non-constant object:
      ```dart
      var a = const ImmutablePoint(1, 1);   // Creates a constant
      var b = ImmutablePoint(1, 1);         // Does NOT create a constant
      assert(!identical(a, b)); // NOT the same instance!
      ```
    #### `7.5 Factory constructors` 
    - Either creates a new instance of a subtype or returns an existing instance from cache.
    - Factory constructors provide a way to create instances of a class with more flexibility than traditional constructors. 
    - They can return an instance of the class or its subclass or a cached instance of the class.
      ```dart
      class Logger {
        final String name; // The name of the logger
        bool muted = false; // Indicates if the logger is muted
        // Cache to store Logger instances
        static final Map<String, Logger> _cache = <String, Logger>{};
        // Private named constructor
        Logger._create(this.name);
        // Factory constructor
        factory Logger(String name) {
          // Return the existing instance if it exists in the cache
          return _cache.putIfAbsent(name, () => Logger._create(name));
        }
        // Method to log messages
        void log(String message) {
          if (!muted) {
            print('$name: $message');
          }
        }
      }
      void main() {
        var logger1 = Logger('console');                // Creates a new Logger instance
        logger1.log('This is the first log message.');
        var logger2 = Logger('console');                // Retrieves the cached instance
        logger2.log('This is the second log message.');
        print(identical(logger1, logger2));             // Outputs: true (both references point to the same object)
      }
      ```
    - The factory constructor factory Logger(String name) checks if an instance with the given name already exists in _cache.
    - If it does, it returns that instance; otherwise, it creates a new one and adds it to the cache.
    - One more example of factory constructor used for validation or conditional instantiation and that returns instances of subclasses
      ```dart 
      abstract class Shape {
        double area();
        factory Shape(String type, {double? radius, double? width, double? height}) {     // parameters specified within curly braces are optional parameters,
                                                                                          // '?' specifies that the parameter can be 'null'.
          if (type == 'circle') {
            if (radius == null || radius <= 0) {
              throw ArgumentError('Radius must be greater than zero for Circle.');
            }
            return Circle(radius);
          } else if (type == 'rectangle') {
            if (width == null || height == null || width <= 0 || height <= 0) {
              throw ArgumentError('Width and height must be greater than zero for Rectangle.');
            }
            return Rectangle(width, height);
          } else {
            throw ArgumentError('Unknown shape type: $type');
          }
        }
      }
      class Circle implements Shape {
        final double radius;
        Circle(this.radius);
        @override
        double area() => 3.14 * radius * radius;                 // πr²
      }
      class Rectangle implements Shape {
        final double width;
        final double height;
        Rectangle(this.width, this.height);
        @override
        double area() => width * height;                         // width * height
      }  
      void main() {
        try {
          Shape circle = Shape('circle', radius: 5);
          print('Circle area: ${circle.area()}');                // Outputs: Circle area: 78.5
          Shape rectangle = Shape('rectangle', width: 4, height: 6);
          print('Rectangle area: ${rectangle.area()}');          // Outputs: Rectangle area: 24
          // Attempting to create a shape with invalid parameters
          Shape invalidCircle = Shape('circle', radius: -3);     // This will throw an error
        } catch (e) {
          print(e);                                              // Outputs error message for invalid parameters
        }
        try {
          Shape unknownShape = Shape('triangle');                // This will throw an error
        } catch (e) {
          print(e);                                              // Outputs error message for unknown shape type
        }
      }
      ```
  
      ##### `Benefits of Using Factory Constructors`
      - **Instance Management** \
        They allow for efficient management of instances (e.g., singletons or cached objects).
      - **Custom Logic** \
        You can implement custom logic for object creation, such as validation or conditional instantiation.
      - **Returning Subtypes** \
        Factory constructors can return instances of subclasses or other types, providing flexibility in object-oriented design.
    #### `7.6 Redirecting constructor`
    - Forwards calls to another constructor in the same class.
    - A redirecting constructor has an empty body. The constructor uses this instead of the class name after a colon (:).
      ```dart
      class Point {
        double x, y;
        // The main constructor for this class.
        Point(this.x, this.y);
        // Delegates to the main constructor.
        Point.alongXAxis(double x) : this(x, 0);
      }
      ```
    #### `7.7 Tear-Offs` 
    - In Dart, **tear-offs** refer to the ability to refer to a function, method, or named constructor without invoking it, effectively creating a closure that can be called later. This allows you to treat functions and methods as first-class objects, enabling more flexible programming patterns.
      #### How Tear-offs Work ?
      When you reference a function or method without parentheses, Dart creates a tear-off:
      - **`Function Tear-off`**  Referring to a standalone function.
      - **`Method Tear-off`** Referring to a method of an object.\
      For example:
      ```dart
      void printMessage(String message) {
        print(message);
      }
      void main() {
        var messages = ['Hello', 'World'];
        // Function tear-off
        messages.forEach(printMessage); // Passes the function itself
        // Method tear-off
        var buffer = StringBuffer();
        messages.forEach(buffer.write); // Passes the method itself
      }
      ```
      In this example:
      - `printMessage` is a standalone function that is passed directly to `forEach` without parentheses, creating a tear-off.
      - `buffer.write` is a method tear-off that allows the `write` method of `StringBuffer` to be invoked for each message.
      ### Benefits of Using Tear-offs
      1. **`Simplification`**: Tear-offs simplify the syntax when passing functions or methods as arguments.
      2. **`Performance`**: They can be more efficient than creating a new closure explicitly since they directly reference an existing function or method.
      3. **`Readability`**: Code becomes cleaner and easier to read by avoiding unnecessary lambda expressions.
      #### `7.8 Lambda Functions in Dart`
      **Lambda functions**, also known as anonymous functions or arrow functions, are functions that do not have a name and can be defined inline. They are often used as arguments to higher-order functions or for short operations where defining a full function would be verbose.
      #### Syntax of Lambda Functions
      A lambda function can be defined using either the arrow syntax (`=>`) or the standard function syntax:
      1. **Arrow Syntax**
         ```dart
         var add = (int a, int b) => a + b;
         ```
      2. **Standard Function Syntax**
         ```dart
         var add = (int a, int b) {
           return a + b;
         };
         ```
      #### Example of Using Lambda Functions
      Here’s an example of using lambda functions in Dart:
      ```dart
      void main() {
        var numbers = [1, 2, 3, 4];
        // Using lambda function with forEach
        numbers.forEach((number) {
          print(number * 2);          // Prints double of each number
        });
        // Using arrow syntax for simplicity
        var squared = numbers.map((number) => number * number).toList();
        print(squared);               // Prints [1, 4, 9, 16]
      }
      ```
      #### `7.9 Differences Between Tear-offs and Lambda Functions`
      - **Tear-offs** 
        1. refer to existing functions or methods and allow you to pass them around without invoking them immediately.
        2. provide a way to reference existing functions and methods directly, enhancing flexibility and readability in your code.
      - **Lambda functions** 
        1. are defined inline and are typically used for short operations where you need a quick function without formally declaring it.
        2. allow for concise inline function definitions that are useful in functional programming contexts.
-
  #### <span style="color: #e1881c"> what do you mean by `closure` ? </span>
  - In programming, a **closure** is a function that captures and retains access to variables from its surrounding lexical scope,
    even after that scope has finished executing. This allows the closure to "remember" the environment in which it was created, 
    which can be particularly useful for maintaining state or creating function factories.
    #### `Key Concepts of Closures`
    1. **Lexical Scope**:\
      A closure has access to its own scope (the variables defined within it) as well as the outer (enclosing) scope where it was defined. This means that closures can use variables that are not defined within their own body.
    2. **Capturing Variables**:\
      When a closure is created, it captures the variables from its surrounding scope. These captured variables remain accessible even after the outer function has completed execution.
    3. **Persistence**:\
      Closures allow for persistent local state. The values of the captured variables are retained in memory as long as the closure itself is accessible.
    ### `Example of a Closure`
    Here’s a simple example in Dart to illustrate how closures work
    ```dart
    void main() {
      var counter = makeCounter();
      print(counter());     // Outputs: 1
      print(counter());     // Outputs: 2
      print(counter());     // Outputs: 3
    }
    Function makeCounter() {
      int count = 0;        // This variable is captured by the closure
      return () {
        count++;            // The closure modifies the captured variable
        return count;
      };
    }
    ```
    `In this example:`
    - The `makeCounter` function defines a local variable `count` and returns an anonymous function (closure) that increments and returns `count`.
    - Each time the returned closure is called, it retains access to `count`, allowing it to maintain state across calls.
    #### `Benefits of Using Closures`
    1. **Encapsulation** \
      Closures can encapsulate private data and expose only what is necessary through public methods.
    2. **Functional Programming** \
      They enable functional programming paradigms, such as higher-order functions, where functions can be passed around as first-class objects.
    3. **State Management** \
      Closures allow functions to maintain state without using global variables or class instances.
    #### `Summary`
      A closure is a powerful feature in programming languages like Dart, JavaScript, and others that allows functions to capture and retain access to their lexical environment. This capability makes closures useful for creating functions with private state, implementing callbacks, and managing complex asynchronous operations.
    #### `Citations` 
      1. https://en.wikipedia.org/wiki/Closure_(computer_programming)\
      2. https://clubztutoring.com/ed-resources/math/closure-definitions-examples-6-7-4-2/\
      3. https://softwareengineering.stackexchange.com/questions/40454/what-is-a-closure/40708\
      4. https://simple.wikipedia.org/wiki/Closure_(computer_science)\
      5. https://stackoverflow.com/questions/36636/what-is-a-closure\
      6. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Closures\
      7. https://www.geeksforgeeks.org/closure-in-javascript/\
      8. https://docs.swift.org/swift-book/documentation/the-swift-programming-language/closures/\


    #### <span style="color: #e1881c"> Instance Variable Initialization </span>
    - Dart can initialize variables in three ways.
    - 

    #### <span style="color: #e1881c"> Constructor inheritance </span>
    - Subclasses, or child classes, don't inherit constructors from their `superclass`, or `immediate parent class`. 
    - If a class doesn't declare a constructor, it can only use the default constructor.
    - A class can inherit the parameters of a superclass. These are called `super parameters`.
    - Constructors work in a somewhat similar way to how you call a chain of static methods.
    - Each subclass can call its superclass's constructor to initialize an instance, like a subclass can call a superclass's static method. This process doesn't "inherit" constructor bodies or signatures.
    
    - Dart executes constructors in the following order
      1. initializer list
      2. superclass's unnamed, no-arg constructor
      3. main class's no-arg constructor

    - If the superclass lacks an unnamed, no-argument constructor, call one of the constructors in the superclass. 
    - Before the constructor body (if any), specify the superclass constructor after a colon `(:)`.
    - In the following example, the Employee class constructor calls the named constructor for its superclass, Person. 
    
      ```dart
      class Person {
        String? firstName;

        Person.fromJson(Map data) {
          print('in Person');
        }
      }

      class Employee extends Person {
        // Person does not have a default constructor;
        // you must call super.fromJson().
        Employee.fromJson(Map data) : super.fromJson(data) {
          print('in Employee');
        }
      }

      void main() {
        var employee = Employee.fromJson({});
        print(employee);
        // Prints:
        // in Person
        // in Employee
        // Instance of 'Employee'
      }
      ```

    #### <span style="color: #e1881c"> `Super` parameters </span>
    - A class can inherit the parameters of a superclass. These are called `super parameters`.
    - With super parameters, you can define a subclass constructor that directly uses the parameters intended for the 
      superclass constructor by prefixing them with `super`.
    - This eliminates the redundancy and makes the code cleaner and easier to maintain.
    - Here’s how super parameters work in practice:

      **Before Dart 2.17 (Old Syntax)**:
      ```dart
      class A {
        A({int? x, int? y});
      }

      class B extends A {
        B({int? x, int? y}) : super(x: x, y: y);
      }
      ```

      **After Dart 2.17 (Using Super Parameters)**:
      ```dart
      class A {
        A({int? x, int? y});
      }
      
      class B extends A {
        B({super.x, super.y});      // Directly using super parameters
      }
      ```

    #### <span style="color: #e1881c"> `@override` annotation </span>
    - It is used to indicate that a method in a subclass is intended to override a method in its superclass.
    - Improves code clarity and compiled-time checks.
    - While using @override is not mandatory, it is considered good practice to include it whenever you are overriding methods.
    - Dart allows overriding methods to have different return types, as long as they are compatible (e.g., returning a subtype).
