
  ## <span style="color: #e1881c"> 6.  Classes  </span>
  - Dart is an object-oriented language with classes and mixin-based inheritance. 
  - Every object is an instance of a class, and all classes except `Null` descends from `Object` class. 
  - Mixin-based inheritance means that although every class (except for the top class, Object?) has 
    exactly one superclass, a class body can be reused in multiple class hierarchies. 
  - Use a dot `(.)` to refer to an instance variable or method.
  - Use `?.` instead of `.` to avoid an exception when the leftmost operand is null.
  - An uninitialized instance variable declared with a nullable type has the value null. 
    Non-nullable instance variables must be initialized at declaration.
  - All instance variables generate an implicit getter method. `Non-final instance variables` and `late final 
    instance variables` without initializers also generate an implicit setter method.
    
    ```dart
    class Point {
      double? x;      // Declare instance variable x, initially null.
      double? y;      // Declare y, initially null.
      double z = 0;   // Declare z, initially 0.
    }
    
    var p = Point(2, 2);        // Get the value of y.
    assert(p.y == 2);           // Invoke distanceTo() on p.
    double distance = p.distanceTo(Point(4, 4));
    
    // If p is non-null, set a variable equal to its y value.
    var a = p?.y;
    ```
  - To get an object's `type` at runtime, you can use the Object property `runtimeType`, which returns a `Type` object.
    ```dart
    print('The type of a is ${a.runtimeType}');
    ```
  
  - `Type test operators` 
    - The `as`, `is`, and `is!` operators are handy for checking types at runtime.
      | Operator | 	Meaning                                           |
      |----------|----------------------------------------------------| 
      | as	     | Typecast (also used to specify library prefixes)   | 
      | is	     | True if the object has the specified type          | 
      | is!	     | True if the object doesn't have the specified type |
    - The result of `obj is T` is true if obj implements the interface specified by T. For example, `obj is Object?` is always true.
    
  - Use the `as` operator to cast an object to a particular type if and only if you are sure that the object is of that type. Example:
    ```dart
    (employee as Person).firstName = 'Bob';
    ```
  - If you aren't sure that the object is of type `T`, then use is `T` to check the type before using the object.
    ```dart
    if (employee is Person) {
      // Type check
      employee.firstName = 'Bob';
    }
    ```
  - Initializing a `non-late instance variable` where it's declared sets the value when the instance is created, 
    before the constructor and its initializer list executes. As a result, the initializing expression (after the =) 
    of a non-late instance variable can't access this.
    ```dart
    double initialX = 1.5;
    class Point {
      // OK, can access declarations that do not depend on `this`:
      double? x = initialX;
      
      // ERROR, can't access `this` in non-`late` initializer:
      double? y = this.x;
      
      // OK, can access `this` in `late` initializer:
      late double? z = this.x;
      
      // OK, `this.x` and `this.y` are parameter declarations, not expressions:
      Point(this.x, this.y);
    }
    ```
  - Instance variables can be `final`, in which case they must be set exactly once. 
  - Initialize `final`, `non-late` `instance variables` at declaration, using a constructor parameter, or using a constructor's initializer list.
    ```dart 
    class ProfileMark {
      final String name;
      final DateTime start = DateTime.now();
      ProfileMark(this.name);
      ProfileMark.unnamed() : name = '';
    }
    ```

### <u> `6.1 Private Variables ` </u>
  - In Dart, private variables are declared by prefixing the variable name with an underscore (`_`). This convention indicates that the variable is private to the library in which it is defined, rather than being strictly private to a class. Here’s a more detailed explanation:

### Declaration of Private Variables

1. **Using Underscore Prefix**:\
   To declare a private variable in Dart, simply prefix the variable name with an underscore. For example:

   ```dart
   class MyClass {
     int _privateVariable = 42; // This variable is private to the library
   }
   ```

3. **Library Scope**:\
   In Dart, privacy is scoped at the library level. This means that any identifier (variable, function, class) starting with an underscore is only accessible within the same library (file). If you try to access `_privateVariable` from another file, you will encounter an error indicating that the variable is undefined [1] [2].

4. **Accessing Private Variables**:\
   While private variables are not accessible outside their defining library, they can be accessed by any other code within the same library. This allows for encapsulation while still enabling related components to interact with each other [2] [3].

### Example

Here’s a simple example demonstrating how to declare and use private variables:

```dart
// my_library.dart
class MyClass {
  int _privateVariable = 10;            // Private variable

  void display() {
    print('Private Variable: $_privateVariable');
  }
}

// main.dart
import 'my_library.dart';

void main() {
  MyClass myClass = MyClass();
  myClass.display(); // This works

// print(myClass._privateVariable);     // This will cause an error: undefined 
                                        // variable '_privateVariable'}
```

### Summary

- **Private variables** in Dart are declared by prefixing their names with an underscore (`_`).
- They are **accessible only within the same library**, not just within the class.
- This design encourages better encapsulation and modularity in Dart applications [1] [2] [3]. 

By understanding this mechanism, you can effectively manage visibility and access control in your Dart applications.

Citations:
1. https://stackoverflow.com/questions/17488611/how-to-create-private-variables-in-dart
2. https://ufedojo.hashnode.dev/variables-in-dart-private-and-public-static-and-instance-cknzzlru300j12is19f724ibr
3. https://www.darttutorial.org/dart-tutorial/dart-private-fields/
4. https://groups.google.com/a/dartlang.org/g/misc/c/WllRrg0zTd4
5. https://github.com/dart-lang/sdk/issues/48864
6. https://dart.dev/language
7. https://www.youtube.com/watch?v=YsXMja1Qmn8


## <u> `6.2 Implicit interfaces ` </u>
  - Every class implicitly defines an interface containing all the instance members of the class and of any interfaces it implements. 
  - If you want to create a class A that supports class B's API without inheriting B's implementation, class A should `implement` the B interface.
  - A class implements one or more interfaces by declaring them in an implements clause and then providing the APIs required by the interfaces. For example:
    ```dart
      // A person. The implicit interface contains greet().
      class Person {
        // In the interface, but visible only in this library.
        final String _name;
        // Not in the interface, since this is a constructor.
        Person(this._name);
        // In the interface.
        String greet(String who) => 'Hello, $who. I am $_name.';
      }

      // An implementation of the Person interface.
      class Impostor implements Person {
        String get _name => '';
        String greet(String who) => 'Hi $who. Do you know who I am?';
      }

      String greetBob(Person person) => person.greet('Bob');

      void main() {
        print(greetBob(Person('Kathy')));
        print(greetBob(Impostor()));
      }

      // Output of the program :-
      Hello, Bob. I am Kathy.
      Hi Bob. Do you know who I am?
    ```
  - Here's an example of specifying that a class implements multiple interfaces:
    
    ```dart
    class Point implements Comparable, Location {...}
    ```
## <u> `6.3 Extensions Methods ` </u>
Extension methods in Dart are a way to add functionality to existing libraries, APIs, or classes without modifying the original code [1][5]. They provide a convenient way to enhance the capabilities of classes, especially when you can't directly alter them [1].

### Overview
Extension methods, introduced in Dart 2.7, allow you to add new methods, getters, setters, and operators to any class [2][1]. They are especially useful for working with primitive data types like strings and can help in writing more readable and reusable code [2].

## Usage
To use an extension method, you need to import the library containing the extension [1]. Once imported, you can use the extension method as if it were a regular method of the class[1].
```dart
import 'string_apis.dart';

void main() {
  print('42'.parseInt()); // Use an extension method
}
```
Extension methods are resolved against the static type of the receiver and are as fast as calling a static function[1]. However, they cannot be invoked on variables of type `dynamic`[1].

## Implementation
To create an extension method, you use the `extension` keyword followed by an optional name for the extension and the type you want to extend[4][1].
```dart
extension NumberParsing on String {
  int parseInt() {
    return int.parse(this);
  }
}
```
The members of an extension can include methods, getters, setters, and operators. Extensions can also have static fields and static helper methods[1].

## Unnamed extensions
You can also create unnamed extensions, which are only visible within the library where they are declared [1]. Unnamed extensions cannot be explicitly applied to resolve API conflicts [1].
```dart
extension on String {
  bool get isBlank => trim().isEmpty;
}
```
### Code Explaination 

**`extension on String`**
  *   `extension` keyword indicates that we're creating an extension.
  *   `on String` specifies that this extension applies to the `String` class. This means you'll be able to use the new functionality defined within this extension on any `String` object.

**`{ ... }`**\
 This block contains the members that are added to the `String` class via this extension. In this case, there's only one member: a getter called `isBlank`.

**`bool get isBlank => trim().isEmpty;`**
  *   `bool get isBlank` declares a getter named `isBlank`. Getters are like read-only properties. They allow you to access a value via a simple name (in this case, `isBlank`) without explicitly calling a method. The getter returns a `bool` (true or false).
  *   `=> trim().isEmpty;` is the body of the getter. It's a shorthand syntax for returning a value.
      *   `trim()` is a method that already exists on the `String` class. It removes any leading or trailing whitespace from the string.
      *   `isEmpty` is another method that already exists on the `String` class. It returns `true` if the string has a length of 0 (is empty), and `false` otherwise.
      *   So, `trim().isEmpty` first removes any leading or trailing whitespace from the string, and then checks if the resulting string is empty. The result of this check (`true` or `false`) is what the `isBlank` getter returns.

In summary, this extension adds a new getter called `isBlank` to the `String` class. The `isBlank` getter returns `true` if the string is empty or contains only whitespace; otherwise, it returns `false`. Because the extension is unnamed, it is only usable within the same library where it is defined.**

**Example:**

```dart
void main() {
  String str1 = "   ";
  String str2 = "Hello";
  String str3 = "";

  print(str1.isBlank); // Output: true (because it contains only whitespace)
  print(str2.isBlank); // Output: false (because it contains non-whitespace characters)
  print(str3.isBlank); // Output: true (because it's an empty string)
}
```

**Benefits of using this extension:**

*   **Readability:**  `str.isBlank` is more readable than `str.trim().isEmpty`.  It clearly conveys the intent: "Is this string blank?".
*   **Convenience:** It saves you from having to type `trim().isEmpty` every time you want to check if a string is blank.
*   **Reusability:**  You can use this `isBlank` getter throughout your code, ensuring consistency in how you check for blank strings.

## Generic extensions
Extensions can also have generic type parameters, allowing you to extend generic types like `List<T>`[1].
```dart
extension MyFancyList<T> on List<T> {
  int get doubleLength => length * 2;
  List<T> operator -() => reversed.toList();
  List<List<T>> split(int at) => [sublist(0, at), sublist(at)];
}
```
The type `T` is bound based on the static type of the list that the methods are called on[1].

OK, let's break down above Dart code snippet, which beautifully demonstrates the power of Dart extensions, especially with generics.

**Explanation:**

1.  **`extension MyFancyList<T> on List<T>`:**
    *   **`extension MyFancyList<T>`:**  This declares an extension named `MyFancyList`. The `<T>` indicates that this is a *generic* extension. This means the extension can work with lists of any type. `T` is a type parameter; it's a placeholder for the actual type that will be used when the extension is applied.
    *   **`on List<T>`:** This specifies that the extension applies to the `List` class. Importantly, it's `List<T>`, meaning it's a list of *some* type `T`.  This is crucial for working with typed lists.

2.  **`int get doubleLength => length * 2;`:**
    *   **`int get doubleLength`:** This defines a getter named `doubleLength`.  Getters, as we discussed earlier, provide a way to access a calculated value as if it were a property.  The getter returns an `int`.
    *   **`=> length * 2;`:** This is the implementation of the getter.  `length` is a property that already exists on the `List` class (it returns the number of elements in the list). This getter simply returns the length of the list multiplied by 2.

3.  **`List<T> operator -() => reversed.toList();`:**
    *   **`List<T> operator -()`:** This defines an *operator* named `-`. Operators allow you to overload existing operators (like +, -, \*, /, etc.) to work with your own classes.  In this case, it's overloading the unary minus operator (the one that appears before a single operand, like `-5`). The `()` after the operator name indicates that it's a unary operator (takes no explicit arguments).  The return type is `List<T>`, meaning it returns a new list of the same type as the original list.
    *   **`=> reversed.toList();`:** This is the implementation of the `-` operator. `reversed` is a property that returns an `Iterable` of the elements in reverse order. `toList()` converts the `Iterable` to a new `List<T>`. Therefore, this operator returns a *new* list that is the reverse of the original list.

4.  **`List<List<T>> split(int at) => [sublist(0, at), sublist(at)];`:**
    *   **`List<List<T>> split(int at)`:** This defines a method named `split`. The method takes one argument named `at` of type `int`.  The return type is `List<List<T>>`. This means it returns a list of lists, where each inner list contains elements of type `T`. This method splits the original list into two sublists.
    *   **`=> [sublist(0, at), sublist(at)];`:** This is the implementation of the `split` method.
        *   `sublist(0, at)` creates a new list containing the elements from index 0 up to (but not including) index `at`.
        *   `sublist(at)` creates a new list containing the elements from index `at` to the end of the original list.
        *   `[...]` creates a new list containing the two sublists created by `sublist()`. Therefore, the split function divides the list into two parts at the index provided by the `at` parameter and returns those lists in a new List.

**In summary:**

This extension adds three new features to the `List` class:

*   **`doubleLength`**: A getter that returns twice the length of the list.
*   **`-` (unary minus operator)**: An operator that returns a reversed copy of the list.
*   **`split(int at)`**: A method that splits the list into two sublists at the specified index.

**Example Usage:**

```dart
void main() {
  List<int> numbers = [1, 2, 3, 4, 5];

  print(numbers.doubleLength);  // Output: 10

  List<int> reversedNumbers = -numbers;
  print(reversedNumbers);       // Output: [5, 4, 3, 2, 1]

  List<List<int>> splitNumbers = numbers.split(3);
  print(splitNumbers);          // Output: [[1, 2, 3], [4, 5]]

  List<String> names = ["Alice", "Bob", "Charlie"];
  print(names.doubleLength);    // Output: 6 (works for lists of strings too!)

  List<List<String>> splitNames = names.split(1);
  print(splitNames);            // Output: [[Alice], [Bob, Charlie]]
}
```

**Key takeaways about this example:**

- **Generics make it reusable:** \
  The extension works with lists of *any* type. You can use it with `List<int>`, `List<String>`, `List<YourCustomClass>`, etc. The type `T` is determined at compile time based on the type of list you're calling the extension methods on.

- **Clean, expressive code:**\
  Extensions allow you to add functionality to existing classes in a clean and organized way, without modifying the original class definition.

- **Operator overloading:**\
  The `-` operator provides a concise and intuitive way to reverse a list.  It integrates seamlessly with Dart's syntax.

This example showcases the power and flexibility of Dart extensions, especially when combined with generics. They allow you to write more readable, reusable, and maintainable code by extending the capabilities of existing classes without resorting to inheritance or modification of the original classes.


## Enabling Extensions
To use extensions in a Dart project, ensure that the SDK version in your `pubspec.yaml` file is 2.6.0 or greater[3].
```yaml
environment:
  sdk: ">=2.6.0 <3.0.0"
```

Citations:
1. https://dart.dev/language/extension-methods
2. https://wilsonwilson.dev/articles/dart-extension-methods
3. https://codewithandrea.com/videos/dart-extensions-full-introduction/
4. https://quickbirdstudios.com/blog/dart-extension-methods/
5. https://sentry.io/answers/extensions-in-dart/
6. https://www.youtube.com/watch?v=D3j0OSfT9ZI
7. https://dart.dev/resources/language/evolution
8. https://github.com/dart-lang/language/issues/41

---
Answer from Perplexity: pplx.ai/share
  
## <u> `6.4 Class Modifiers ` </u>
  -  Class modifiers allow you to control how libraries can subtype a class.
  
## <u> `6.5 Class Variables and Methods ` </u>
  - `static` keyword is used to implement class-wide variables and methods.
    #### <i> <span style="color: green"> <u> Static variables </u> </span> </i>
    - `Static` variables (class variables) are useful for class-wide state and constants:
    
      ```dart
      class Queue {
        static const initialCapacity = 16;
        // ···
      }

      void main() {
        assert(Queue.initialCapacity == 16);
      }
      ```
    - `Static` variables aren't initialized until they're used.
    - Usually, lowerCamelCase styling is preferred for constant names.
    
    #### <i> <span style="color: green"> <u> Static methods </u> </span> </i>
      - Static methods (or aka class methods) don't operate on an `instance`, and thus don't have access to `this`. 
      - They do, however, have access to static variables. 
      - As the following example shows, you invoke static methods directly on a class:
        ```dart
        import 'dart:math';
        class Point {
          double x, y;
          Point(this.x, this.y);
          static double distanceBetween(Point a, Point b) {
            var dx = a.x - b.x;
            var dy = a.y - b.y;
            return sqrt(dx * dx + dy * dy);
          }
        }
        void main() {
          var a = Point(2, 2);
          var b = Point(4, 4);
          var distance = Point.distanceBetween(a, b);
          assert(2.8 < distance && distance < 2.9);
          print(distance);
        }
        ```
      - Consider using top-level functions, instead of static methods, for common or widely used utilities and functionality.
      - You can use static methods as compile-time constants. For example, you can pass a static method as a parameter to a constant constructor.
       
## <u> `6.6 Using Constructors` </u>
  - Constructor names can be either `ClassName` or `ClassName.identifier`.
    ```dart
    var p1 = Point(2, 2);
    var p2 = Point.fromJson({'x': 1, 'y': 2});
    ```
  - The following code has the same effect, but uses the optional new keyword before the constructor name
    ```dart 
    var p1 = new Point(2, 2);
    var p2 = new Point.fromJson({'x': 1, 'y': 2});
    ```
