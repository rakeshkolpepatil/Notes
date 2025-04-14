void main( List<String> args ){
  // Example usage of InvalidAgeException
  try {
    tryCreatingPerson('John', -1);
  } catch (e, st) {
    print(e);   // Output: InvalidAgeException: Age cannot be negative, Age: -1
    print(st);
  }
}

void tryCreatingPerson(String name, int age){
  try {
    Person person = Person(name, age); // Throws InvalidAgeException
  } on InvalidAgeException {
    rethrow;            // Output: InvalidAgeException: Age cannot be negative, Age: -1
  } catch (e, stackTrace){
    print(e);
    print(stackTrace);
  }
}

class Person {
  final String name;
  final int age;
  
  Person(this.name, this.age){
    if(age < 0) {
      throw InvalidAgeException('Age cannot be negative', age);
    }
  }
}

class InvalidAgeException implements Exception {
  final String message;
  final int age;

  InvalidAgeException (this.message, this.age );

  @override
  String toString() {
    return "InvalidAgeException: $message, Age: $age";
  }
}