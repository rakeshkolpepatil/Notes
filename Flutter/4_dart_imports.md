
### <span style="color: #e1881c"> 5.  Imports  </span>
- To access APIs defined in other libraries, use import.
  ```dart
  // Importing core libraries
  import 'dart:math';
  // Importing libraries from external packages
  import 'package:test/test.dart';
  // Importing files
  import 'path/to/my_other_file.dart';
  ```
- The `import` and `library` directives can help you create a modular and shareable code base. 
- Libraries not only provide APIs, but are a unit of privacy: identifiers that start with an underscore (_) are visible only inside the library. 
- Every Dart file (plus its parts) is a library, even if it doesn't use a library directive.
- Libraries can be distributed using packages.
  #### <u> `5.1 Using Libraries` </u>
  - Use import to specify how a namespace from one library is used in the scope of another library.\
    For example, Dart web apps generally use the `dart:html` library, which they can import like this:
      ```dart
      import 'dart:html';
      ```
  - The only required argument to import is a URI (uniform Resource Identifier) specifying the library. For built-in libraries, the URI has the special `dart:` scheme. For other libraries, you can use a file system path or the `package:` scheme. 
  - The `package:` scheme specifies libraries provided by a package manager such as the pub tool. For example:
    ```dart
    import 'package:test/test.dart';
    ```
  - URI stands for uniform resource identifier. URLs (uniform resource locators) are a common kind of URI.

  #### <u> `5.2 Specifying a library prefix` </u>
  - If you import two libraries that have conflicting identifiers, then you can specify a prefix for one or both libraries.\
    For example, if `library1` and `library2` both have an Element class, then you might have code like this:
    ```dart
    import 'package:lib1/lib1.dart';
    import 'package:lib2/lib2.dart' as lib2;

    // Uses Element from lib1.
    Element element1 = Element();

    // Uses Element from lib2.
    lib2.Element element2 = lib2.Element();
    ```
  #### <u> `5.3 Importing only part of a library` </u>
  - If you want to use only part of a library, you can selectively import the library. For example:
    ```dart
    // Import only foo.
    import 'package:lib1/lib1.dart' show foo;

    // Import all names EXCEPT foo.
    import 'package:lib2/lib2.dart' hide foo;
    ```

  #### <u> `5.4 Lazily loading a library` </u>
  - Deferred loading (also called lazy loading) allows a web app to load a library on demand, if and when the library is needed. 
  - Use deferred loading when you want to meet one or more of the following needs.
    1. Reduce a web app's initial startup time.
    2. Perform A/B testing. For Example, trying out alternative implementations of an algorithm.
    3. Load rarely used functionality, such as optional screens and dialogs.

  - To lazily load a library, first import it using deferred as.
    ```dart
    import 'package:greetings/hello.dart' deferred as hello;

    // When you need the library, invoke loadLibrary() using the library's identifier.

    Future<void> greet() async {
      await hello.loadLibrary();
      hello.printGreeting();
    }
    ```

  - Please note following things when you use deferred loading:
    1. A deferred library's constants aren't constants in the importing file. Remember, these constants don't exist until the deferred library is loaded.
    2. You can't use types from a deferred library in the importing file. Instead, consider moving interface types to a library imported by both the deferred library and the importing file.
    3. Dart implicitly inserts loadLibrary() into the namespace that you define using deferred as namespace. The `loadLibrary()` function returns a Future.

  - You can invoke `loadLibrary()` multiple times on a library without problems. The library is loaded only once.

  #### <u> `5.5 The library directive` </u>
  - To specify library-level doc comments or metadata annotations, attach them to a library declaration at the start of the file.

    ```dart
    /// A really great test library.
    @TestOn('browser')
    library;
    ```
  ---