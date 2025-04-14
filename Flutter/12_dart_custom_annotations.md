In Dart, functions can be annotated using the `@` symbol followed by an annotation reference. Annotations in Dart serve as metadata that can provide additional information about the function to tools, libraries, or the runtime. Here’s a detailed overview of how functions are annotated in Dart:

## Function Annotations

### Basic Syntax

To annotate a function, you simply place the annotation above the function definition. 
For example:
```dart
@override
void myFunction() {
  // Implementation
}
```

### Common Built-in Annotations
Dart provides several built-in annotations that can be used with functions:

- **`@override`**: Indicates that a method is intended to override a method in a superclass.
- **`@deprecated`**: Marks a function as deprecated, signaling that it should not be used and may be removed in future versions.
- **`@required`**: Used for named parameters to indicate that they must be provided when calling the function.

## Custom Annotations
You can also create custom annotations by defining a class and using it as an annotation. Here’s how you can create and use a custom annotation:

```dart
// Custom annotation class
class RequiresPermission {
  final String permission;
  const RequiresPermission(this.permission);
}

// Example function using RequiresPermission annotation
@RequiresPermission('INTERNET')
void fetchData() {
  // Fetch data from the internet
}
```

### Use Cases for Annotations
Annotations can be utilized for various purposes, including:

- **Documentation**: Automatically generating documentation from annotated functions.
- **Code Generation**: Tools like `build_runner` use annotations to generate boilerplate code.
- **Validation**: Enforcing coding standards or validating data based on annotations.

### Example of Function Annotation

Here’s a complete example demonstrating both built-in and custom annotations:

```dart
class MyService {
  @deprecated
  void oldMethod() {
    print("This method is deprecated.");
  }

  @RequiresPermission('CAMERA')
  void takePicture() {
    print("Taking a picture.");
  }
}

void main() {
  MyService service = MyService();
  service.oldMethod(); // Warning: This method is deprecated.
  service.takePicture();
}
```

## Summary
- Functions in Dart can be annotated using the `@` symbol followed by an annotation reference.
- Built-in annotations like `@override`, `@deprecated`, and `@required` are commonly used.
- Custom annotations can be created by defining a class and using it to annotate functions.
- Annotations serve various purposes, including documentation generation, code validation, and enforcing coding standards.

By using annotations effectively, you can enhance the readability and maintainability of your Dart code.

Citations:
1. https://blog.nonstopio.com/exploring-annotations-in-dart-programming-ae6a8e4b8624
2. https://dart.dev/language
3. https://dart.dev/language/functions
4. https://dart.dev/effective-dart/documentation
5. https://www.darttutorial.org/dart-tutorial/dart-functions/
6. https://dart.dev/effective-dart/design
7. https://pub.dev/packages/super_annotations
8. https://www.javatpoint.com/dart-function