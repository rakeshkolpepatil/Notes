
void main (List<String> args) {
  // No modifications are allowed on 'const' type of variables.
  // Const variables do not allow any type of reassignment to the variables and also 
  // do allow any modification to the value of the variable.

  const String name = 'India';

  // name = 'USA';                 // const variables can not be modified.
  print(name);

  // 'final' variables are half way restrictive to that of 'const' variables.
  // 'final' variables can be assigned only once but their values can be modified if the assigned 
  // values are composite values.

  final List<int> age = <int>[1, 2, 3, 4, 5];
  //age = [ 5, 6, 7];              // reassignment to 'final' variables is not allowed
  age[0] = 10;                     // however, composite values can be modified.
  print(age);

  // 'final' variables can be assigned values after declaration but only once.
  final String gender;
  gender = 'Male';                 
  print('Gender = $gender');

  const List<String> subjects = <String>['Marathi', 'English', 'Hindi'];
  print(subjects);
  //subjects.add('Science');        // 'const' variable values can't be modified.

  // The normal vanilla variables can be reassigned multiple times and their values can be 
  // changed multiple times.

  String address = '123 Main street';
  print('Original Address - $address');

  address = '456 Main street';
  print('Modified Address - $address');

  address = address.replaceAll('Main', 'Cross');
  print('Latest Address   - $address');

  // Variables can be declared by mentioning data types explicitly or with generic 
  // data type named 'var' whose data type is determined by the value stored in it at 
  // compile time.

  int num = 10;
  // num = '3.14';              // compiler assumes data type of 'num' to be 'integer' so 'string' 
                                // value can not be assigned to it.
  // num = 3.14;                // even float values can be assigned to 'num'                            

  String city = 'Mumbai';  
  String state = 'Punjab';
  print('city - $city');

  // only variable having same data type can be assigned to each other.  
  city = state;                 
  print('city - $city');

  // 'const' values can be assigned to 'final' values but 'final' values can not be assigned 
  // to the 'const' values. The concept is that more strict values can be assigned to less strict
  // values however, less strict values can not be assigned to more strict values.
  final int f1;
  const int c1 = 20;
  f1 = c1;
  
  // const c2 = f1;   // 'final' values can not be assigned to 'const' variables. 

  // Dart infers the data type depending upon the value stored in the variable.
  const int x = 10;       // explicitly specifying the data type 
  const int y = 20;           // dart infers the data type

  print('');
  print('x - $x, y - $y');
  print('x - ${x.runtimeType}, y - ${y.runtimeType}');

  // const List<int> myList = List<int>.filled(3, 0);
  const List<int> myListConst = <int>[1, 2, 3, 4, 5, 6, 7, 8];
  print(myListConst);

  print('');
  List<int> filledList = List<int>.filled(5, 0); // Creates a list of length 5 filled with 0s
  print(filledList); // Output: [0, 0, 0, 0, 0]

  // A 'const' value can be assigned to the 'final' value
  print('');
  final List<int> myListFinal = myListConst;
  print('myListFinal - $myListFinal');

  // However, a 'final' value can not be assigned to the 'const' type variable.
  // const List<int> myListConst2 = myListFinal;

  print('');
  late final int myVal = 10;
  print('myVal - $myVal ');

  print('');
  final int yourVal1 = getValue();
  print('Inside main function');
  print('yourVal1 - $yourVal1');

  // The 'late' variables, are assigned the value only when it is first used.
  // Therefore, the 'getValue()' function is called when the 'yourVal2' is used in print().
  print('');
  late final int yourVal2 = getValue();
  print('Inside main function');
  print('yourVal2 - $yourVal2');

  // Specifying data type of the variable is optional in dart, but a rule can be added 
  // to linter so that it highlights/enforces that the types are specified for the variables. 
  final String Entry = 'Male';
  final String sex = 'Female';

  // Saving a less precise data type into a more precise data type is called as type promotion.
  final double likes = 10;

  // Saving a more precise data type into a less precise data type is called as type demotion 
  // and is not allowed.
  // final int comments = 3.14;

  // By default, all the variables names should be in lower camel case in Dart.
  // Therefore, following variables is highlighted by linter as a problem.
  final double Pi = 3.14;
  print('Pi - $Pi');

  // As I am not following naming convention for const variables, linter is highlighting 
  // it as a problem.
  const double Epsilon = 3.789;
  print('EPSILON - $Epsilon');

  print('\nListing all data types -');
  const int someInteger = 10;
  print('someInteger - $someInteger');
  const double someDouble = 1.89;
  print('someDouble - $someDouble');
  const String someString = 'Hello';
  print('someString - $someString');
  const bool someBool = true;
  print('someBool - ${!someBool} ');
  const bool someBool1 = true;
  print('someBool - $someBool1 ');

  const List<int> someList = <int>[1, 2, 3, 4];
  print('\nsomeList - $someList');
  const Map<String, String> someMap = <String, String>{'foo':'bar'};
  print('someMap - $someMap');
  print('someMap["foo"] - ${someMap["foo"]}');
  const Set<int> someSet = <int>{1, 2, 3, 4, 5, 6, 7, 8, 9};
  print('someSet - $someSet');
  print('someSet Length - ${someSet.length}');

  // The 'dynamic' data type also exists in the Dart language.
  const dynamic someNull = Null;
  print('\nsomeNull - $someNull');

  // The 'Symbol' data type also exists in the Dart language.
  const Symbol someSymbol = #someNull;
  print('someSymbol - $someSymbol');
}

int getValue(){
  print('getValue() called !');
  return 21;
}
