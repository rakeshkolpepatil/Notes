
## <span style="color: #e1881c"> Dart language for Flutter development </span>
- Flutter is a single code/language framework. Dart language is used for both front-end and back-end development.
- While developing native Android apps, xml is used for frontend, whereas Java is used for backend.
- Dart language is focused on frontend UI development.
- Dart is strongly typed, object oriented language developed by Google in 2011.
- It is mixture of Javascript, Java and C#.

### Benefits of Dart 
- Use of Async and await for asynchronous programming.
- Dart is perhaps the only mainstream language that is well suited to being compiled both, ahead-of-time(AOT) and Just-in-time(JIT).\
  This provides a significant advantage to dart and in turn to the flutter (hot reloading feature).
- Jit compilation is used during development and when an app is ready for release, it is compile AOT.
- Fast development cycles, fast execution and startup times.
- Dart can be compiled into javascript so that, it can be executed in browsers.
- Flutter doesn't split layout between your program and an additional templating or layout languages like JSX or XML, nor does it require separate visual layout tools.



#  <span style="color: #e1881c"> Dart Basics </span> 
- Online editor for practicing Dart programming - https://dartpad.dev 
- The execution of flutter or dart program starts from the compulsory "void main()" function.
- Functions that don't explicitly return a value have the `void` return type.

### <span style="color: #e1881c"> 1.  Variables  </span>
  - Variables can be declared without explicitly specifying their type using `var` keyword. Type of these variables is determined by their initial values.
  - The 'var' variables default out to 'null' value unless explicitly initialized.
    ```dart
    var name = 'Voyager I';
    name = 8;         // This will throw error. once initialized, only same data type
                      // values can be assigned.
    var year = 1977;
    var antennaDiameter = 3.7;
    var flybyObjects = ['Jupiter', 'Saturn', 'Uranus', 'Neptune'];
    var image = {
      'tags': ['saturn'],
      'url': '//path/to/saturn.jpg'
    };
    var int myNum = 10;   // Not OK. This should be either 'var myNum = 10' or 'int myNum = 10'

    // 'city' will be initialized to 'null' by default.
    var city;
    if(city == null){
      print('The city is null');
    }

    // The compound operator '??=' will assign the rhs value to the lhs variable only if it is null.
    status ??= 'unmarried';
    print('The status is - $status ');
    ``` 

  - Variables declared using `Object` or `dynamic` keyword can store values of any data type.
    ```dart
    Object name = 'Bob';
    name = 3.14;
    name = [1, 2, 3, 4, 5];
    ```
  - The Dart language enforces sound null safety.
  - Null dereference error occurs when you access a property or call a method on an expression that evaluates to null. An exception to this rule is when null supports the property or method, like toString() or hashCode. 
  - With null safety, the Dart compiler detects these potential errors at compile time.
    ```dart
    String? name  // Nullable type. Can be `null` or string.
    String name   // Non-nullable type. Cannot be `null` but can be string.
    ```
  - You must initialize non-nullable variables before using them. Nullable variables are initialized to null by default. Dart doesn't set initial values to non-nullable types.
  - You can't access properties or call methods on an expression with a nullable type except property or method that `null` supports like hashCode or toString().

  #### <u> `Late` variables </u>
  - Dart's control flow analysis can detect when a non-nullable variable is set to a non-null value before it's used, but sometimes analysis fails.
  - Dart can't determine whether op-level variables and instance variables are initialized or not. 
  - If you're sure that a variable is set before it's used, but Dart disagrees, then you can fix the error by marking the variable as `late`
  - If you fail to initialize a late variable, a runtime error occurs when the variable is used.
  - When a variable is marked as late but is initialized at its declaration, then the actual initialization is done for first time when that variable is actually used. This lazy initialization is handy in a couple of cases:
    1. The variable might not be needed, and initializing it is costly.
    2. You're initializing an instance variable, and its initializer needs access to this.

  #### <u> `Final` and `const` </u>
  - If you never intend to change a variable, use `final` or `const` either, instead of `var` or in addition to a type. 
  - A `final` variable can be set only once; a `const` variable is a compile-time constant. 
  - The `final` variables can be declared without initialization. However, a `cost` variable must be initialized at its declaration and can never be modified.
  - Also, you can not use `final` keyword along with `var` keyword because `var` means a variable that can be assigned multiple times.
  - Const variables are implicitly final.
  - Both `final` and `const` variables must be initialized before they are used. 
  - Both `final` and `const` variables are nullable and can be set to null. 
  - If a composite variable is declared as constant, then it cannot be modified at all, over lifetime of program, whereas if the composite variable is declared as final, then it can be modified multiple times, but can be assigned only once.
    
    ```dart
    final name = 'Bob';               // Without a type annotation
    final var name = 'Bob';           // Not OK. not correct
    final String nickname = 'Bobby';

    //✗ static analysis: failure
    name = 'Alice';        // Error: a final variable can only be set once.
    ```

  - Use `const` for variables that you want to be compile-time constants. 
  - If the `const` variable is at the class level, mark it `static const`. 
  - In case of const variables, it is compulsory to set its value at the time of declaration to a compile-time constant such as a number/string literal to 
    a const variable, or the result of an arithmetic operation on constant numbers.

    ```dart
    const bar = 1000000;                // Unit of pressure (dynes/cm2)
    const double atm = 1.01325 * bar;   // Standard atmosphere
    ```

  - The const keyword isn't just for declaring constant variables. 
  - It can also be used to create constant values, as well as to declare constructors that create constant values. 
  - Any variable can have a constant value.
    ```dart
    var foo = const [];
    final bar = const [];
    const baz = [];       // Equivalent to `const []`
    ```
  - You can omit const from the initializing expression of a const declaration, like for `baz` above.
  - You can change the value of a non-final, non-const variable, even if it used to have a const value:
    ```dart
    foo = [1, 2, 3];      // Was const []
    ```

  - You can't change the value of a const variable:
    ```dart
    ✗ static analysis: failure
    baz = [42];           // Error: Constant variables can't be assigned a value.
    ```

  - You can define constants that use `type checks` and `casts (is and as)`, collection if, and spread operators (... and ...?):
    ```dart
    const Object i = 3;                             // Where i is a const Object with an int value...
    const list = [i as int];                        // Use a typecast.
    const map = {if (i is int) i: 'int'};           // Use is and collection if.
    const set = {if (list is List<int>) ...list};   // ...and a spread.
    ```

  - Although a `final object` cannot be modified, its fields can be changed. In comparison, a `const object` and its fields cannot be changed. They're immutable.

---

  ### <span style="color: #e1881c"> 2.  Control flow statements  </span>
  - Dart supports the following control flow statements
  
    ```dart
    if (year >= 2001) {                           // Nested if else
      print('21st century');
    } else if (year >= 1901) {
      print('20th century');
    }

    for (final object in flybyObjects) {          // for loop
      print(object);
    }

    for (int month = 1; month <= 12; month++) {   // for loop 
      print(month);
    }

    while (year < 2016) {                         // while loop
      year += 1;
    }
    ```


  ---
  ### <span style="color: #e1881c"> 3.  Operators  </span>
  - Operators are just simple functions. 
  - In older languages, we didn't had access to the operator functions. However in modern languages you can create your own operators.
  - Dart has following types of operators 
    1. Unary Prefix
    2. Unary Postfix
    3. Binary Infix
    4. compound assignment
  - Parenthesis has more precedence than other operators.
  - Operator functions are defined as follow -
  
    ```dart
    num +(num other)    // First 'num' tells that the return type is 'num', '+' specifies that it is '+' operator
                        // signature, and '(num other)' indicates that the '+' operator operates upon other 'num' values.
    ```


  ---
  ### <span style="color: #e1881c"> 4.  Functions  </span>

  4.1 Synchronous Generators
  ```dart
  void main(List<String> args) {
    for(final String name in getNames()){
      print(name);
    }

    print('\n -- Printing only names --');
    for(final String name in getNames1()){
      print(name);
    }
  }

  Iterable<String> getNames() sync* {
    yield 'Ram';
    yield 'Shyam';
    yield 'Ganesh';
    yield 'Rajesh';

    print('\n Printing more names ...');
    yield *getMoreNames();
  }

  Iterable<String> getMoreNames() sync* {
    yield 'Krishna';
    yield 'Sudhir';
    yield 'Raghu';
  }
  
  Output :-
    Ram
    Shyam
    Ganesh
    Rajesh
    Krishna
    Sudhir
    Raghu
  ```
  ---
  ### <span style="color: #e1881c"> 5.  Linting  </span>
  - The linter is used to specify the error highlighting rules.
  - They are specified in the file `analysis_options.yaml` like below -

    ```yaml
    linter:
      rules:
        - camel_case_types
    ```

  - Linter Rules Table 
  
    | Linter Rule Name                     | Description                                                |
    |--------------------------------------|------------------------------------------------------------|
    | always_declare_return_types          | Require return types on functions and methods.             |
    | always_specify_types                 | Require all variables to be declared with a data type .    |
    | annotate_overrides                   | Require the `@override` annotation on overridden methods.  |
    | avoid_as                             | Avoid using `as` for type casting.                         |
    | avoid_await_in_completer             | Avoid using `await` in a completer.                        |
    | avoid_empty_else                     | Avoid empty `else` clauses.                                |
    | avoid_init_to_null                   | Avoid initializing variables to `null`.                    |
    | avoid_print                          | Avoid using `print` statements.                            |
    | avoid_return_types_on_setters        | Do not specify return types for setters.                   |
    | camel_case_types                     | Use camel case for type names.                             |
    | constant_identifier_names            | Use uppercase for constant identifiers.                    |
    | non_constant_identifier_names        | Use lower camel case for non-constant identifiers.         |
    | empty_constructor_bodies             | Avoid empty constructor bodies.                            |
    | hash_and_equals                      | Implement `==` and `hashCode` when defining a class.       |
    | invalid_case_patterns                | Avoid invalid patterns in switch cases.                    |
    | one_member_abstracts                 | Prefer having only one member in abstract classes.         |
    | prefer_final_fields                  | Prefer using `final` for fields that are not reassigned.   |
    | prefer_single_quotes                 | Prefer single quotes for string literals.                  |
    | sort_constructors_first              | Sort constructors before other members in classes.         |
    | unnecessary_brace_in_string_interps  | Avoid unnecessary braces in string interpolation.          |

  ---
  ### <span style="color: #e1881c"> 6.  Comments  </span>
  ```dart
  // This is a normal, one-line comment.
  
  /// This is a documentation comment, used to document libraries,
  /// classes, and their members. Tools like IDEs and dartdoc treat
  /// doc comments specially.
  
  /* Comments like these are also supported. */

  ```

---
### <span style="color: #e1881c"> 7.  Optional Parameters  </span>

### Optional Function Parameters
Dart allows parameters to be marked as optional, enabling function calls with varying arguments. There are two types:

#### 1. **Optional Positional Parameters**
- Defined using square brackets `[]`.
- Parameters must be passed in order if used.
- Default values can be assigned (otherwise, they default to `null`).

```dart
void printDetails(String name, [int age = 25, String city]) {
  print('Name: $name, Age: $age, City: ${city ?? "Unknown"}');
}

void main() {
  printDetails('Alice');      // Name: Alice, Age: 25, City: Unknown
  printDetails('Bob', 30);    // Name: Bob, Age: 30, City: Unknown
  printDetails('Charlie', 28, 'Paris'); 
}
```
Here, `age` and `city` are optional. If omitted, `age` defaults to `25`, and `city` uses `null` [4] [5].

#### 2. **Optional Named Parameters**
- Defined using curly braces `{}`.
- Parameters are referenced by name, allowing flexibility in order.
- Default values can be assigned.

```dart
void calculateArea({int length = 0, int width = 0}) {
  print('Area: ${length * width}');
}

void main() {
  calculateArea(length: 10, width: 5);  // Area: 50
  calculateArea(width: 8);              // Area: 0 (length defaults to 0)
}
```
Named parameters improve readability by explicitly labeling arguments[1][3].

---

### Default Values
Optional parameters (both positional and named) can declare default values:
```dart
void greet(String name, {String title = 'Guest'}) {
  print('Hello, $title $name!');
}

void main() {
  greet('Alice');                 // Hello, Guest Alice!
  greet('Bob', title: 'Dr.');     // Hello, Dr. Bob!
}
```
If `title` is omitted, it uses `'Guest'` [1][4].

---

### Null Safety and Optional Variables
Dart’s null safety ensures variables are non-nullable by default. To declare a variable that can hold `null`, use `?`:
```dart
String? nullableName; // Can be String or null
int? age; 
```
This replaces the need for an `Optional` type by enforcing null checks at compile time[7][8].

## `! Operator`
In Dart, the `!` operator is used in two main contexts

1. **Null Assertion Operator (`!`):**
   - The null assertion operator (`!`) is used to assert that an expression is not null. It is typically used when you are certain that a nullable variable is not null at a specific point in your code.
   - In the provided code snippet:

     ```dart
     UnmodifiableListView? get siblings =>
       _siblings == null ? null : UnmodifiableListView(_siblings!);
     ```

     The `_siblings!` expression asserts that `_siblings` is not null. If `_siblings` is null at runtime, Dart will throw a runtime error.

2. **Logical NOT Operator (`!`):**
   - The logical NOT operator (`!`) is used to negate a boolean value. It returns `true` if the operand is `false`, and vice versa.
   - This is not the case in the provided code snippet.

**Why Use the Null Assertion Operator ?**

- **Code Readability:**\
  It makes your code more readable by clearly indicating that you expect a variable to be non-null.

- **Type Safety:**\
  It helps Dart's type system understand that a nullable variable is safe to use as if it were non-nullable at a specific point.

- **Avoiding Null Checks:**\
  It can simplify code by avoiding explicit null checks in some situations.

However, using the null assertion operator (`!`) can lead to runtime errors if the variable is null. Therefore, use it only when you are certain that the variable is not null.

In the context of the provided code, if `_siblings` is null, the function will return null. The null assertion is used after checking that `_siblings` is not null, which makes it safe in this specific case. However, Dart's null safety features encourage using null-aware operators or checks to handle nulls more robustly. 

For example, you could use the null-aware operator (`??`) or the null-coalescing operator (`??=`) to handle nulls more safely:

```dart
UnmodifiableListView? get siblings =>
  _siblings != null ? UnmodifiableListView(_siblings) : null;
```

Or, using null-aware operators:

```dart
UnmodifiableListView? get siblings =>
  _siblings?.map((e) => e).toUnmodifiable();
```

This approach avoids the need for the null assertion operator (`!`).

Citations:
1. https://www.scaler.com/topics/dart-operator/
2. https://www.tpointtech.com/dart-operators
3. https://dart-tutorial.com/introduction-and-basics/operators-in-dart/
4. https://www.dhiwise.com/post/a-practical-guide-to-understanding-dart-operators
5. https://dart.dev/language/operators
6. https://www.codecademy.com/resources/docs/dart/operators
7. https://www.tutorialspoint.com/dart_programming/dart_programming_operators.htm
8. https://dart.dev/resources/dart-cheatsheet


## Key Differences: Positional vs. Named
| Feature                | Positional Parameters          | Named Parameters               |
|------------------------|--------------------------------|--------------------------------|
| **Syntax**             | `[param1, param2]`             | `{param1, param2}`             |
| **Order**              | Must follow declaration order  | Can be passed in any order     |
| **Default Values**     | Supported                      | Supported                      |
| **Readability**        | Less explicit                  | More explicit (named labels)   |

Named parameters are preferred for functions with many optional arguments to avoid confusion [3][5].

---

### When to Use Optional Parameters
- **Optional Function Arguments**: Simplify function calls by omitting non-essential parameters.
- **API Design**: Create flexible APIs where some parameters are rarely used.
- **Backward Compatibility**: Add new parameters to existing functions without breaking code.

---

### Common Pitfalls
1. **Mixing Parameter Types**: 
   ```dart
   // Invalid: Positional optional parameters must come last
   void invalidFunc([int a], int b) {} 
   ```
2. **Overusing Named Parameters**: Can clutter function calls if overused.


### Citations:
1. https://www.dhiwise.com/en-in/post/the-ultimate-guide-to-dart-named-parameters
2. https://www.educative.io/answers/what-are-dart-optional-parameters
3. https://zaiste.net/posts/dart-optional-function-parameters/
4. https://www.darttutorial.org/dart-tutorial/dart-optional-parameters/
5. https://www.tutorialspoint.com/optional-parameters-in-dart-programming
6. https://github.com/dart-lang/language/issues/3731
7. https://dart.dev/overview
8. https://dart.dev/language
9. https://www.tutorialspoint.com/optional-parameters-in-dart-programming
10. https://stackoverflow.com/questions/65859725/functions-with-optional-parameter-dart
11. https://stackoverflow.com/questions/76487642/dart-optional-vlaue-as-prop
12. https://www.tutorialspoint.com/dart_programming/dart_programming_optional_parameters_with_default_values.htm
13. https://github.com/dart-lang/language/issues/15
14. https://dart.dev/language/functions
15. https://pub.dev/documentation/optional/latest/
16. https://www.linkedin.com/pulse/dart-optionals-aldanis-vigo
17. https://www.darttutorial.org/dart-tutorial/dart-optional-parameters/
18. https://www.dhiwise.com/en-in/post/the-ultimate-guide-to-dart-named-parameters


---
### <span style="color: #e1881c"> 8. Optional/Nullable Variables in Dart  </span>
- Optionally in dart is an ability for a variable to have a value or contain a `null`.
- If a variable is assigned a null value without specifying any data type then Dart assumes that variable to be of `dynamic` type.
- In Dart, the `??` operator is known as the coalesce operator. It is also considered a null-aware operator.
- The '??' operator returns the expression on its left if that expression is not null; 
  otherwise, it evaluates and returns the expression on its right2. 
- For example, `a ?? b` means if a is not null, it resolves to a. But if a is null, it resolves to b.

--- 
### <span style="color: #e1881c"> 9. cast() method in Dart </span>

The `cast()` method in Dart is used to view a collection, such as a `List`, as a collection of another type [5][7]. If the original collection contains only instances of the specified type, all operations will work correctly. However, if an operation tries to access an element that is not an instance of the specified type, an error will be thrown at runtime [3, 7].

**How `cast()` Works ?**\
The `cast<R>()` method provides a view of the original iterable as an iterable of type `R`[5].

- **Type Safety**: \
  It ensures type safety when working with collections [3].

- **Runtime Checks**:\
  The type of elements is checked at runtime [3, 6].

- **Lazy Collection**:\
  `cast()` returns a lazy collection that checks the element type on every operation[6].

**Syntax**
```dart
List<R> newList = originalList.cast<R>();
```
Here, `R` refers to the desired list type like `int`, `double`, `String`, or `bool`[3].

**Example of Using `cast()`**
```dart
void main() {
  // Example of cast<T>()
  List<dynamic> dynamicList = [1, 2.2, 'three'];

  // Example with potential error
  try {
    List<int> intListCast = dynamicList.cast<int>(); // Might throw an error at runtime
    print('Integer list (cast): $intListCast');
  } catch (e) {
    print('Error during cast: $e');
  }
}
```



**Alternatives to `cast()`**

*   **`whereType<T>()`**: This method filters elements of a specific type `T` from a collection[3].  It is useful when you want to extract elements of a particular type from a mixed-type list.
    ```dart
    void main() {
      List<dynamic> dynamicList = [1, 2.2, 'three'];
      List<int> intList = dynamicList.whereType<int>().toList();
      List<double> doubleList = dynamicList.whereType<double>().toList();
      List<String> stringList = dynamicList.whereType<String>().toList();

      print('Original list: $dynamicList');
      print('Integer list: $intList');
      print('Double list: $doubleList');
      print('String list: $stringList');
    }
    ```

*   **Using `as` keyword**: The `as` keyword can be used for explicit type casting.  However, it performs more like an assertion and throws a runtime exception if the type doesn't match[6].
    ```dart
    void main() {
      dynamic x = "123";
      String s = x as String;
      print(s); // Output: 123
    }
    ```
    
*   **Using `map()`**:  The `map()` method can be used to transform each element in a list to a different type [6].

    ```dart
    void main() {
      List<dynamic> dynamicList = [1, 2, 3];
      List<String> stringList = dynamicList.map((e) => e.toString()).toList();
      print(stringList); // Output: [1, 2, 3]
    }
    ```

Here's a summary as a table:

| Method               | Description                             | Error Handling     |
| -------------------  |-----------------------------------------| ------------------ |
| `cast<T>()`          | Provides a *view* of the original list as a list of type `T`. Throws a runtime error if an element is not of type `T`.   | Throws `TypeError` at runtime if an element cannot be cast to type `T` [3]. |
| `whereType<T>()`     | Creates a new list containing only elements of type `T`.      | Does not throw errors; simply excludes elements that are not of type `T`.     |
| `as`                 | Performs explicit type casting (more like a type assertion).  | Throws an exception if the cast is not possible [6].                           |
| `map()`              | Transforms each element in the list based on a provided function. | Depends on the transformation logic defined in the `map()` function.      |

Citations:
1. https://www.dhiwise.com/en-in/post/the-ultimate-guide-to-dart-type-cast-converting-data-types
2. https://stackoverflow.com/questions/52632119/in-dart-syntactically-nice-way-to-cast-dynamic-to-given-type-or-return-null/69417271
3. https://www.codecademy.com/resources/docs/dart/list/cast
4. https://dart.dev/resources/dart-cheatsheet
5. https://api.dart.dev/stable/3.4.4/dart-core/Iterable/cast.html
6. https://stackoverflow.com/questions/49541914/why-an-explicit-cast-function-in-dart-instead-of-as
7. https://api.flutter.dev/flutter/dart-core/List/cast.html
8. https://dart.dev/language/type-system
9. https://dart.dev/language
10. https://github.com/dart-lang/site-www/issues/736
11. https://api.flutter.dev/flutter/dart-core/Map/cast.html
12. https://github.com/dart-lang/language/issues/1732
13. https://www.educative.io/answers/how-to-cast-a-string-to-an-integer-in-dart
14. https://github.com/dart-lang/sdk/issues/42889
15. https://stackoverflow.com/questions/66121579/how-to-cast-object-to-a-specified-type-in-flutter/66122558
16. https://dart.dev/effective-dart/design
17. https://stackoverflow.com/questions/49541914/why-an-explicit-cast-function-in-dart-instead-of-as
18. https://docs.flutter.dev/platform-integration/platform-channels
19. https://stackoverflow.com/questions/52632119/in-dart-syntactically-nice-way-to-cast-dynamic-to-given-type-or-return-null/69417271
20. https://github.com/dart-lang/sdk/issues/54125
21. https://www.dhiwise.com/en-in/post/the-ultimate-guide-to-dart-type-cast-converting-data-types
22. https://github.com/dart-lang/language/issues/193
23. https://api.dart.dev/stable/3.4.4/dart-core/Iterable/cast.html
24. https://pub.dev/packages/dot_cast/example
25. https://api.flutter.dev/flutter/dart-core/List/cast.html
