
// Youtube Video - https://youtu.be/2uyMvzTr9xI?list=PL6yRaaP0WPkVLSOchfoIA0ZXySz4eSYV2

int main(List<String> args) {
  Person(age: 0);
  tryCreatingPerson(age: -1);
  tryCreatingPerson(age: 150);
  tryCreatingPerson(age: 15);
  tryCreatingPersonWithSpecificException();
  return 0;
}

void tryCreatingPerson( { int age=0 } ){
  try{
    print(Person(age: age).age);
  } catch(e) {
    print(e.runtimeType);
    print(e);
  }
  print("\n--------------------------- ");
}

void tryCreatingPersonWithSpecificException(){
  try{
    print(Person(age: 151).age);
  } on InvalidAgeException catch(e, stackTrace) {
    print(e.runtimeType);
    print(e);
    print(stackTrace);
  }
}

class Person {
  final int age;
  Person( {required this.age}) {
    if(age < 0) {
      throw Exception('Age must be greater than 0');
    } else if (age > 140){
      throw 'Age must be less than 140';
    }
  }
}

class InvalidAgeException implements Exception {
  final String message;
  final int age;

  InvalidAgeException(this.message, this.age);
  @override
  String toString() => 'InvalidAgeException: $message (Age: $age)';
}
