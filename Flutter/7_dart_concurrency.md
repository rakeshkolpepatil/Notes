
---
  ## <span style="color: #e1881c"> 8.  Concurrency in Dart  </span>
  ### <span style="color: #32CD32 "> 8.1 Asynchronous Support </span>
  ### <span style="color: #32CD32 "> 8.2 Isolates </span>
  
  ### <span style="color: #32CD32 "> 8.3 Futures </span>
  A `Future` is an object that represents the `result of an asynchronous operation`. It can be in one of two states:
  
  1. **Uncompleted** : The operation is still ongoing.
  2. **Completed** : The operation has finished, which can result in either:
      - A successful completion with a value.
      - A failure with an error.
  
  If you want to convert a function into a `'Future' function` you need to use the keyword `'async'`. 

  A `Future function` is a function that `returns a future`.
  ```dart
  Future<String> getUserName() async {
    // Do some asynchronous work
    return "John Doe";
  }
  ``` 

  ### Characteristics
  **Asynchronous Execution**\
  Futures allow Dart programs to perform other tasks while waiting for operations to complete. This is particularly important in UI applications where blocking the main thread would freeze the interface.
  
  **Event Loop**\
  Dart uses a single-threaded event loop to manage asynchronous tasks. When a Future is created, it schedules the task to run and immediately returns control to the program, allowing it to continue executing other code.

  ### Creating Futures
  You can create a Future using the `Future` class. Here are some common ways to create Futures. Following three constructs in Dart effectively resolve and return the futures:

  1. **Using `Future.value`**:\
    The following construct creates a future that completes immediately with the value "Hello".\
    It is a synchronous completion, meaning that the future is resolved right away.\
    You can retrieve the value using `await` or the `then()` method.\
    This is a straightforward way to create a completed future without any delay
      ```dart
      Future<String> futureValue = Future.value("Hello");
      ```

  2. **Using `Future.delayed`**:\
    The following construct creates a future that completes after a specified duration (in this case, 2 seconds). \
    The second argument is a function that returns the value `"Delayed Result"`.\
    After the delay, the future resolves with this value.\
    You can also retrieve it using `await` or `then()`.\
    This is useful for simulating asynchronous operations.

      ```dart
      // The `async` keyword in the following function is redundant. As, 'async' expects the 
      // 'await' keyword inside the function or the function should return the raw 'String' 
      // object. And we are doing neither of these two in the below function.

      Future<String> futureDelayed async= Future.delayed(
        Duration(seconds: 2), 
        () => "Delayed Result"                // Output: "Delayed Result" 
      );

      //(OR) Future<String> getPhoneNumberNew() => Future<String>.delayed(
      Future<String> getPhoneNumberNew() => Future.delayed(
        const Duration(seconds: 2),
        () { return '555-555-5555';}          // Using inline callback function
      );
      
      Future<String> getZipcode() => Future.delayed(
        const Duration(seconds: 3),
        ()=> 123123;
      );

      print(await getPhoneNumberNew());       // Output: '555-555-555'.
      print(futureDelayed);                   // Output: Instance of 'Future<String>'
      
      futureDelayed.then((value) {
        print(value);                         // Output: 'Delayed Result'
      }).catchError((error) {
        print(error);
      });

      print(getZipcode());                    // Output: 123123
      ```

  3. **Using `Completer`**:\
    The Completer class allows you to create a future that you can complete manually at a later point in your code.\
    When you call `completer.complete("Completed Result")`, it resolves the associated future with the provided value.\
    This approach is beneficial when you need to control when a future completes based on some external event or condition
      ```dart
      Completer<String> completer = Completer();
      // Later in your code
      completer.complete("Completed Result");
      Future<String> futureFromCompleter = completer.future;
      ```

  ### Consuming Futures
  To handle the result of a Future once it completes, you can use several methods:

  1. **Using `then`**:
      ```dart
      futureValue.then((value) {
        print(value);       // Output: Hello
      }).catchError((error) {
        print(error);
      });
      ```

  2. **Using `async` and `await`**:\
      Using `await` keyword resolves/consumes an instance of the `Future` and whenever you use `await`
      keyword in a function that function needs to be decorated with keyword `async`.

      The `async` and `await` keywords provide a more readable way to work with Futures.
      ```dart
      Future<void> fetchData() async {
        try {
          String data = await futureDelayed;
          print(data);      // Output: Delayed Result
        } catch (e) {
          print(e);
        }
      }
      ```

  ### Error Handling
  Futures can also fail, and you should handle errors appropriately. When using `async` and `await`, you can wrap your code in a `try-catch` block to manage exceptions:

  ```dart
  try {
    String result = await someFutureFunction();
  } catch (e) {
    print("Error occurred: $e");
  }
  ```

  ### Practical Use Cases
  Futures are commonly used in scenarios such as:
  - Fetching data from APIs.
  - Reading or writing files.
  - Performing database operations.

  #### Example: Fetching Data from an API
  Here's a simple example of using a Future to fetch data from an API:
  ```dart
  import 'dart:convert';
  import 'package:http/http.dart' as http;

  Future<String> fetchUserData() async {
    final response = await http.get(Uri.parse('https://jsonplaceholder.typicode.com/users/1'));
    if (response.statusCode == 200) {
      return jsonDecode(response.body)['name'];
    } else {
      throw Exception('Failed to load user');
    }
  }

  void main() async {
    try {
      String userName = await fetchUserData();
      print('User Name: $userName');
    } catch (e) {
      print(e);
    }
  }
  ```
  In this example, the function `fetchUserData` returns a Future that resolves with the user's name after making an HTTP GET request.

  ### Conclusion
  Futures are essential for managing asynchronous operations in Dart. They help keep applications responsive by allowing tasks to run concurrently without blocking the main execution thread. Understanding how to create, consume, and handle errors with Futures is crucial for effective Dart programming, especially in Flutter applications where UI responsiveness is paramount.

  ### Citations:
  1. https://dev.to/mateus-ic1101/understanding-asynchronous-programming-in-dart-futures-and-streams-explained-53kk
  2. https://www.darttutorial.org/dart-tutorial/dart-future/
  3. https://betterprogramming.pub/introduction-to-futures-in-dart-4edf6db3da90?gi=fadd16e60bbf
  4. https://www.geeksforgeeks.org/flutter-what-is-future-and-how-to-use-it/
  5. https://www.youtube.com/watch?v=9i86-zRePQs
  6. https://api.flutter.dev/flutter/dart-async/Future-class.html
  7. https://dart.dev/libraries/async/async-await
  8. https://stackoverflow.com/questions/63017280/what-is-a-future-and-how-do-i-use-it


  ### <span style="color: #32CD32 "> 8.4 Completer </span>
  In Dart, a **Completer** is a powerful utility that allows you to create and manage a `Future` manually. 
  
  It provides a way to complete a `Future` at some point in the future, either with a value or an error. This is particularly useful in scenarios where you need to control when a `Future` is completed, such as when dealing with asynchronous operations that may not have a straightforward completion point.

  ### Definition
  A **Completer** is an object that can create a `Future` and allows you to complete it later. 
  
  When you create a `Completer`, you can access its associated `Future` through the `future` property. You can then use the `complete()` method to provide a value or the `completeError()` method to indicate that an error occurred.

  ### Key Properties and Methods
  - **`Completer<T>`**: The generic type parameter `T` specifies the type of value that the `Future` will hold.
  - **`Future<T> future`**: This property returns the associated `Future` object.
  - **`void complete(T value)`**: This method completes the `Future` with the provided value.
  - **`void completeError(Object error)`**: This method completes the `Future` with an error.

  ### Example Usage
  Here’s an example demonstrating how to use a Completer in Dart:

  ```dart
  import 'dart:async';

  void main() {
    // Create a Completer
    Completer<String> completer1 = Completer<String>();
    Completer<String> completer2 = Completer<String>();

    // Get the Future from the Completer
    Future<String> future1 = completer.future;
    Future<String> future2 = completer.future;

    // Simulate an asynchronous operation (e.g., fetching data)
    Future.delayed(Duration(seconds: 2), () {
      // Complete the Future with a value
      completer1.complete("Data fetched successfully!");
      // Uncomment the next line to simulate an error instead
      // completer.completeError("Failed to fetch data");
    });

    
    // Error while fetching the data, use of arrow function, do not use curly braces while using arrow function
    Future.delayed(Duration(seconds: 2), () => completer2.completeError("future2: Failed to fetch data") );

    // Handle the Future's result
    future1.then((value) {
      print(value);               // Output: Data fetched successfully!
    }).catchError((error) {
      print(error);               // Handle any errors
    });
    
    // Handle the Future's result
    future2.then((value) {
      print(value);               // Output: Data fetched successfully!
    }).catchError((error) {
      print(error);               // Handle any errors
    });

  }
  ```

  ### Explanation of the Example
  1. **Creating a Completer**\
    A `Completer<String>` is created, which will manage a `Future<String>`.
  
  2. **Getting the Future** \
    The associated `Future` is accessed via `completer.future`.
  
  3. **Simulating Asynchronous Work**\
    A delayed operation simulates fetching data. After 2 seconds, it completes the Future with a success message.
  
  4. **Handling Results** \
    The result of the Future is handled using `.then()` for success and `.catchError()` for errors.

  ### Use Cases for Completers
  
  - **Custom Asynchronous APIs** \
    When building APIs that need to provide asynchronous results but do not follow standard callback patterns.
  
  - **Event Handling** \
    In scenarios where events occur at unpredictable times, and you want to return a Future that resolves when specific conditions are met.
  
  - **Bridging Callbacks and Futures**\
    When integrating libraries or code that uses callbacks but you want to expose a Future-based API.

  ### Conclusion
  In summary, Completers in Dart provide fine-grained control over asynchronous operations by allowing developers to complete Futures manually. This feature is particularly useful in complex scenarios where standard asynchronous patterns may not suffice. Understanding how to effectively use Completers can enhance your ability to manage asynchronous programming in Dart applications, leading to cleaner and more maintainable code.

  ### Citations:
  1. https://codewithandrea.com/courses/complete-dart-guide/
  2. https://www.udemy.com/course/complete-dart-programming-language-basic-to-advanced/
  3. https://dart.dev/overview
  4. https://en.wikipedia.org/wiki/Dart_(programming_language)
  5. https://www.geeksforgeeks.org/dart-tutorial/
  6. https://www.simplilearn.com/what-is-dart-programming-article
  7. https://dart.dev
  8. https://www.youtube.com/watch?v=JiSfa8oB06Y

---