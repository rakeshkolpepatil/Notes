
  ### <span style="color: #e1881c">9.  Enums  </span> 
  Enums, or enumerations, in Dart are a special data type that allows developers to define a set of named constant values. 
  They are particularly useful for representing a fixed number of related options, such as days of the week, user roles, or status codes.
  Enums enhance code readability and maintainability by providing a clear and structured way to manage these constant values.

  #### <i> <span style="color: #32CD32 ">  Syntax of Enums </span> </i>
  To declare an enum in Dart, you use the `enum` keyword followed by the name of the enum and its values enclosed in curly braces. Here’s the basic syntax:
  ```dart
  enum EnumName {
      Value1,
      Value2,
      Value3,
      // ...
  }
  ```

  #### <i> <span style="color: #32CD32 ">  Example of Basic Enum </span> </i>
  Here’s an example of a simple enum representing the days of the week:
  ```dart
  enum Days {
      Sunday,
      Monday,
      Tuesday,
      Wednesday,
      Thursday,
      Friday,
      Saturday
  }

  void main() {
      var today = Days.Friday;
      switch (today) {
          case Days.Sunday:
              print("Today is Sunday.");
              break;
          case Days.Monday:
              print("Today is Monday.");
              break;
          case Days.Tuesday:
              print("Today is Tuesday.");
              break;
          case Days.Wednesday:
              print("Today is Wednesday.");
              break;
          case Days.Thursday:
              print("Today is Thursday.");
              break;
          case Days.Friday:
              print("Today is Friday.");
              break;
          case Days.Saturday:
              print("Today is Saturday.");
              break;
      }
  }
  ```

  #### <i> <span style="color: #32CD32 ">  Accessing Enum Values </span> </i>
  Dart provides a built-in property called `values` that returns all the values of an enum as a list. This can be useful for iterating over the enum values:

  ```dart
  void main() {
      for (Days day in Days.values) {
          print(day);
      }
  }
  ```

  #### <i> <span style="color: #32CD32 ">  Enhanced Enums </span> </i>
  Starting from Dart 2.6, enums can have associated members, allowing you to attach additional data or methods to each enum value. Here’s how you can define an enhanced enum:
  ```dart
  enum CompanyType {
      SoleProprietorship("Sole Proprietorship"),
      Partnership("Partnership"),
      Corporation("Corporation"),
      LimitedLiabilityCompany("Limited Liability Company");

      final String description;

      const CompanyType(this.description);
  }

  void main() {
      var type = CompanyType.SoleProprietorship;
      print(type.description);                    // Outputs: Sole Proprietorship
  }
  ```

  #### <i> <span style="color: #32CD32 ">  Advantages of Using Enums </span> </i>
  1. **Readability** 
    Enums provide meaningful names for constant values, making the code easier to understand.
  
  2. **Type Safety** 
    Enums help catch errors at compile-time by restricting variable values to predefined constants.
  
  3. **Maintainability**
    Grouping related constants into enums reduces redundancy and simplifies code maintenance.
  
  4. **Integration with Control Structures**
    Enums work seamlessly with switch statements and other control structures, enhancing decision-making logic.

  #### <i> <span style="color: #32CD32 ">  Conclusion </span> </i>
  Enums in Dart are a powerful feature that allows developers to define a set of related constant values in a structured manner. They improve code readability and maintainability while providing type safety and reducing the risk of errors. With the introduction of enhanced enums, developers can now associate additional data with enum values, further expanding their utility in Dart applications.

  #### <i> <span style="color: #32CD32 ">  Citations: </span> </i>
  1. https://dart-tutorial.com/object-oriented-programming/enum-in-dart/
  2. https://www.geeksforgeeks.org/data-enumeration-in-dart/
  3. https://www.scaler.com/topics/dart-enum/
  4. https://www.freecodecamp.org/news/how-to-use-enhanced-enums-in-dart/
  5. https://www.darttutorial.org/dart-tutorial/dart-enum/
  6. https://www.javatpoint.com/dart-enumeration
  7. https://www.tutorialspoint.com/dart_programming/dart_programming_enumeration.htm
  8. https://dev.to/catoverflow/how-to-use-enum-in-dart-3274

---