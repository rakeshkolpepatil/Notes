import 'dart:async';

void main() {
  // Create a Completer
  Completer<String> completer1 = Completer<String>();
  Completer<String> completer2 = Completer<String>();

  // Get the Future from the Completer
  Future<String> future1 = completer1.future;
  Future<String> future2 = completer2.future;

  // Simulate an asynchronous operation (e.g., fetching data)
  Future.delayed(Duration(seconds: 2), () {
    // Complete the Future with a value
    completer1.complete("future1: Data fetched successfully!");
    
    // Uncomment the next line to simulate an error instead
    // completer.completeError("Failed to fetch data");
  });

  // Simulate an asynchronous operation (e.g., fetching data)
  Future.delayed(Duration(seconds: 2), () => completer2.completeError("future2: Failed to fetch data") );

  // Handle the Future's result
  future1.then((String value) {
    print(value);               // Output: Data fetched successfully!
  }).catchError((error) {
    print(error);               // Handle any errors
  });

  
  // Handle the Future's result
  future2.then((String value) {
    print(value);               // Output: Data fetched successfully!
  }).catchError((error) {
    print(error);               // Handle any errors
  });
}