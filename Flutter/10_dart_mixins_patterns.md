  ### <span style="color: #e1881c">  15. Mixins </span>
  - Mixins in Dart are a way to share functionality between multiple classes without creating a complex inheritance hierarchy. 
  - You can think of mixins as a class with reusable methods and properties that other classes can “mix in” without formally inheriting from them.

  #### <span style="color: #32CD32 "> 15.1 Key Concepts of Mixins in Dart </span>

  - **Code Reusability** \
    Mixins allow you to reuse code across unrelated classes.

  - **Multiple Inheritance** \
    Unlike classes, Dart allows you to apply multiple mixins to a single class, enabling a form of multiple inheritance.

  - **No Constructor Requirement** \
    Mixins don’t require constructors, making them easy to apply to any class without complex inheritance chains.

  #### <span style="color: #32CD32 "> 15.2 Defining and Using Mixins </span>
  - Mixins are created just like normal classes in Dart, but they use the `mixin` keyword. 
  - To use a mixin in a class, you use the `with` keyword, followed by the mixin name.
  
    ```dart
    mixin CanFly {
      void fly() {
        print('Flying...');
      }
    }

    class Bird with CanFly {
      void chirp() {
        print('Bird is chirping');
      }
    }

    void main() {
      var bird = Bird();
      bird.chirp();  // Output: Bird is chirping
      bird.fly();    // Output: Flying...
    }
    ```

  - **Mixin** \
    The CanFly mixin defines a fly() method.

  - **Using Mixins** \
    The Bird class applies the CanFly mixin using the with keyword. As a result, the Bird class inherits the fly() method, even though it doesn’t formally extend the CanFly mixin.

  #### <span style="color: #32CD32 "> 15.3 Applying Multiple Mixins </span>
  - One of the most powerful features of mixins in Dart is the ability to apply multiple mixins to a class. 
  - This allows a class to inherit behavior from multiple sources, which is not possible with traditional single inheritance.
  
    ```dart
    mixin CanSwim {
      void swim() {
        print('Swimming...');
      }
    }

    mixin CanWalk {
      void walk() {
        print('Walking...');
      }
    }

    class Duck with CanSwim, CanWalk, CanFly {
      void quack() {
        print('Duck is quacking');
      }
    }

    void main() {
      var duck = Duck();
      duck.quack();  // Output: Duck is quacking
      duck.fly();    // Output: Flying...
      duck.swim();   // Output: Swimming...
      duck.walk();   // Output: Walking...
    }
    ```

  - **Multiple Mixins**\
    The Duck class uses three mixins: CanSwim, CanWalk, and CanFly. This allows the duck to inherit behaviors from all three mixins.
  - **Multiple Inheritance**\
    Dart enables this form of multiple inheritance through mixins, providing flexibility and reducing code duplication.

  #### <span style="color: #32CD32 "> 15.4 Restrictions on Mixins </span>
  While mixins are a powerful tool, they come with some restrictions:

  1. **No Constructors** \
    `Mixins` cannot have constructors. This means they can only add methods and properties, but not state initialization.

  2. **Cannot Extend from Other Classes** \
    A `mixin` cannot extend from another class, though it can extend from Object.

      ```dart
      mixin CanClimb {
        // Mixins cannot have constructors
        // Can only add methods and properties
        void climb() {
          print('Climbing...');
        }
      }

      class Monkey with CanClimb {
        // Monkey inherits the climb method but cannot inherit constructors
      }
      ```

  #### <span style="color: #32CD32 "> 15.5 When to Use Mixins </span>
  - Mixins are useful in scenarios where you want to reuse code across multiple, unrelated classes. 
  - Unlike traditional inheritance, mixins don’t create a strict hierarchical relationship. 
  - Here are some ideal cases to use mixins:

    - **Unrelated Classes**\
      When two or more classes need to share functionality but are not related through inheritance.

    - **Utility Functions**\
      If a group of utility functions needs to be shared across multiple classes (like logging, caching, etc.), a mixin is ideal.

    - **Multiple Behaviors**\
      If a class requires behavior from multiple sources, you can combine mixins to provide this functionality.

      ```dart
      mixin Logger {
        void log(String message) {
          print('Log: $message');
        }
      }

      class Database with Logger {
        void saveData() {
          log('Saving data to database...');
        }
      }

      class File with Logger {
        void writeFile() {
          log('Writing data to file...');
        }
      }

      void main() {
        var db = Database();
        db.saveData();      // Output: Log: Saving data to database...

        var file = File();
        file.writeFile();   // Output: Log: Writing data to file...
      }
      ```

    - **Utility Mixin** \
      The Logger mixin provides a log() function that is reused by both the Database and File classes.

    - **Code Reusability**\
      By using mixins, both classes gain logging functionality without needing to extend a common parent class.

  #### <span style="color: #32CD32 "> 15.6 Mixins vs Inheritance vs Interfaces </span>
  - Dart provides multiple ways to share functionality: inheritance, mixins, and interfaces. 
  - Here’s how they compare:

    - **Inheritance**\
      Best for a strict parent-child relationship where a subclass needs to inherit from a single parent class.

    - **Mixins**\
      Best for sharing functionality between unrelated classes without enforcing a strict inheritance relationship.

    - **Interfaces**\
      Best for enforcing certain methods or properties that a class must implement.


    - **Example Comparison**
      - **Inheritance** \
        When a class “is-a” type of another class (e.g., Dog extends Animal).

      - **Mixin** \
        When you want to add capabilities without implying an “is-a” relationship (e.g., Duck with CanFly).

      - **Interface** \
        When you want to enforce certain behaviors but leave the implementation up to the class.


---
  ### <span style="color: #e1881c">  16.  Patterns </span>
  - Pattern matching allows you to check whether a given value:
    1. has a certain shape.
    2. is a certain constant.
    3. is equal to something else.
    4. has a certain type.
    
  #### Matching 
  - A pattern always tests against a value to determine if the value has the form you expect.
  - A constant pattern matches if the value is equal to the pattern's constant. 
    ```dart
    switch (number) {
      // Constant pattern matches if 1 == number.
      case 1:
        print('one');
    }
    ```
  - Many patterns make use of sub-patterns, sometimes called outer and inner patterns, respectively. 
  - Patterns match recursively on their sub-patterns. 
      ```dart
      const a = 'a';
      const b = 'b';
      switch (obj) {
        // List pattern [a, b] matches obj first if obj is a list with two fields,
        // then if its fields match the constant subpatterns 'a' and 'b'.
        case [a, b]:
          print('$a, $b');
      }
      ```
  - Patterns can be used for Variable Declaration 
    ```dart
    // Declares new variables a, b, and c.
    var (a, [b, c]) = ('str', [1, 2]);
    ```
  - A pattern variable declaration must start with either var or final, followed by a pattern.
  - Use a variable assignment pattern to swap the values of two variables without declaring a third temporary one.
    ```dart
    var (a, b) = ('left', 'right');
    (b, a) = (a, b); // Swap.
    print('$a $b'); // Prints "right left".
    ```

  #### Destructuring
  - When an object and pattern match, the pattern can then access the object's data and extract it in parts. 
  - In other words, the pattern destructures the object.
    
    ```dart 
    var numList = [1, 2, 3];
    // List pattern [a, b, c] destructures the three elements from numList...
    var [a, b, c] = numList;
    // ...and assigns them to new variables.
    print(a + b + c);
    ```
  - The case clause ['a' || 'b', var c] is intended to match a list where the first element is either 'a' or 'b', 
    and the second element is captured in the variable `c`
    ```dart
    switch (list) {
      case ['a' || 'b', var c]:
        print(c);
    }
    ```
  
  #### <span style="color: #32CD32 "> 16.1 Pattern Types </span>
  #### <span style="color: #32CD32 "> 16.2 Applied Tutorial </span>

---