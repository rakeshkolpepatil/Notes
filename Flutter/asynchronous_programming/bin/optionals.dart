void main(){
  // null value is not allowed to 'nullName' as it is not defined nullable.
  // String nullName = null;
  
  // nullable variables, defined using '?', can store 'null' values.
  print('\n----- "conditional property access operator i.e. ? " ----- ');
  print('                    or ');
  print('----- "the null-aware access operator" -----');
  String? name;
  print(name);
  name = 'Sameer';
  print(name);

  // nullable/optional variables are by default initialized to 'null'
  String? status;
  print('Nullable variables are by default initialized to null: status = $status');

  // The compound operator '??=' will assign the rhs value to the lhs variable only if it is null.
  print('\n----- If null Operator -----');
  status ??= 'unmarried';
  print('The status is - $status ');
  status ??= 'married';
  print('The status is - $status ');

  // As you have stored a 'null' value in a variable, without specifying it's type while defining it,
  // Dart will assume its type as 'dynamic'
  var time;

  // The 'const' and 'final' variables must be initialized before using them, and as following 'const' 
  // and 'final' variables are nullable they can be initialized to 'null'
  const int? myVal= null;
  final int? temp = null;
  if(myVal == null){
    print('myVal is null');
  }else{
    print('myVal is not null');
  }

  // The 'var' variables, unless initialized explicitly, are initialized to 'null' by default.
  var city;
  print('city is null');

  // lenght of the variables
  print('\n----- Length of the variables: ----- ');
  final int numl = 20;
  final String namel = "Excellent";
  final double g = 9.8;
  final List<int> l = <int>[1, 2, 3, 4, 5, 6, 7];
  print('namel.length - ${namel.length}');
  print('l.length - ${l.length}');

  // Use of null-shorting cascade operator.
  String? str4;
  try{
    print('str4.length - ${str4?.length}');
  }catch(e){
    print('While accessing the properties of the nullable variables you much use "?."- null shorting cascade operator');
  }
  print('str4?.length - ${str4?.length}');

  // In Dart, the ?? operator is known as the coalesce operator1. 
  // It is also considered a null-aware operator2.
  // The '??' operator returns the expression on its left if that expression is not null; 
  // otherwise, it evaluates and returns the expression on its right2. 
  // For example, a ?? b means if a is not null, it resolves to a. But if a is null, it resolves to b1.

  // See how Dart assumes the type of the string 'result' as non-nullable 'String'
  String? nullName;
  final String result = nullName ?? 'blah';


  // See how Dart assumes the type of the string 'result' as nullable 'String'
  String? nullName1;
  String? nullName2;
  final String? result1 = nullName1 ?? nullName2;


  // nullable container variables example a nullable List of nullable variables.
  print('\n----- Nullable Lists -----');
  List<String?>? l1;
  print('l1 = $l1');

  l1?.add(null);
  print('l1 = $l1');
  
  l1?.add('Ram');
  print('l1 = $l1');

  l1 = <String?>[];
  l1.add('Ram');
  print('l1 = $l1');
  l1.add('John');
  print('l1 = $l1');

  l1.add(null);
  print('l1 = $l1');

  // The following code is a bug in Dart language. Even though the l2 list is non null empty list, 
  // the accessing first element of the l2 will cause program crash instead of returning null.
  print('l1[0] = ${l1[0]}');
  List<String> l2 =<String>[];
  try{
    print('l2.first = ${l2.first}');
    print('l2[0] = ${l2[0]}');
    print('l2[3] = ${l2[3]}');
  }catch(e){
    print('In Dart, trying to access elements from the empty list causes run time error!');
  }

  // However, accessing the elements from a nullable list will not throw error.
  print('\n----- Accessing elements of empty list raises exceptions -----');
  List<String>? l3;
  print('l3?.first = ${l3?.first}');

  List<String>? l4 =<String>[];
  try{
    print('l4.first = ${l4.first}');
    print('l4[0] = ${l4[0]}');
    print('l4[3] = ${l4[3]}');
  }catch(e){
    print('In Dart, trying to access elements from the empty list causes run time error!');
  }

  // Force reading the variables :-> '!' is null assertion operator. 
  // The null assertion operator tells the compiler that you are certain that 
  // the variable is not null and that it's safe to treat it as a `non-nullable` type
  print('\n----- Null Assertion Operator -----');
  final int? age = null;
  print('age :- $age');
  try{
    print('age! :- ${age!}');
  }catch(e){
    print('Using null assertion operator on a null value causes following error -');
    print(e);
  }

  // following function guarantees to return String value.
  String getFullName(){
    return 'Bob';
  }

  // following function does not guarantee to return String
  String? getFullNameOptional(){
    return null;
  }

  print('\n----- Use of Extensions -----');
  String? fullName = getFullName();
  fullName.describe();
  fullName = getFullNameOptional();
  fullName.describe();

  // create a function that takes a list of nullable/optional values and calls a callback function
  // if none of the values from the list are null.
  print('\n-----  -----');
  print(withAll(<Object?>['Rakesh', 'Patil'], (List<Object> l)=> l.join(' ')) );
  print(withAll(<Object?>['Rakesh', ''],      (List<Object> l)=> l.join(' ')) );
  print(withAll(<Object?>['Rakesh', null],    (List<Object> l)=> l.join(' ')) );
  print(withAll(<Object?>[null, null],        (List<Object> l)=> l.join(' ')) );
  print(withAll(<Object?>[null, 'Patil'],     (List<Object> l)=> l.join(' ')) );

  // flatmap
  print('\n----- Flatmap ----- ');
  String? firstName = 'John';
  String? lastName = 'Doe';

  String bla1 = firstName.flatMap((String f)=> lastName.flatMap((String l)=> '$f $l')) 
            ?? 'Either firstName or LastName or both are null';
  print(bla1);

  String? bla2 = "Ram".flatMap((String f)=> "Patil".flatMap((String l)=> '$f $l'));
  print(bla2);
  
  String? bla3 = null.flatMap((Object? f)=> "Patil".flatMap((String l)=> '$f $l'));
  print(bla3);
}// end of main function

// Using extension on null object
extension Describe on Object?{
  void describe(){
    if (this == null){
      print('This object is null');
    }else{
      print('$runtimeType : $this');
    } 
  }
}

// Within the definition of the 'withAll' function, "callback" is the name given to the parameter that will hold 
// the function you pass in. You use "callback" to refer to that function within the body of withAll when you 
// want to execute it.
// Callback functions do not need to be the last parameter when passed to a function in Dart. 
// They can be placed at any position in the parameter list. 
// The primary purpose of cast<T>() is to change the type of a list from List<dynamic> or List<T?> to List<T>

T? withAll<T>(
  List<T?> optionals,
  T Function(List<T>) callback,
) => optionals.any((e)=> e==null) ? null : callback(optionals.cast<T>());


extension FlatMap<T> on T? {
  R? flatMap<R>(
    R? Function(T) callback,
  ){
      final shadow = this;
      if(shadow == null) {
        return null;
      }else{
        return callback(shadow);
      }  
  }
}// end FlatMap function
