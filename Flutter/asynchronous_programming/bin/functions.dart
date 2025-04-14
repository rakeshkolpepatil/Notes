void main(List<String> args){
  // Calling the function
  printWow();

  // It is always advisable to use return types while declaring functions. 
  // '-always_declare_return_types' is the linter rule that will enforce the return types while declaring functions.
  printHello();

  // If no return type is specified then the function will return 'null' by default.
  print('printHello() returns - ${printHello()}');
  
  // Also, if a function does not need to return a value then use 'void' return type.
  // When the function return type is 'void' the it will not return anything and trying to use the return value
  // of the function will cause compilation error.
  try{
    // print('printWow() returns   - ${printWow()}');
  }catch(e){
    print(e);
  }

  // Though technically it is possible to assign the return value of a 'void' function to a 'void' variable,
  // this should be avoided. It is like assigning nothingness to nothingness.
  final void temp = printWow();
  // print('temp  - $temp');

  print('\n----- Named Parameters ----- ');
  sayHelloTo();
  sayHelloTo(name: 'Ramesh');
  // sayHelloTo(null);
  
  print('');
  sayHelloToNew();
  // sayHelloToNew(null);
  sayHelloToNew();
  sayHelloToNew(name: null);
  sayHelloToNew(name: 'Tom');
  
  print('\n----- Positional Parameters ----- ');
  // sayHelloToNullable();              // as no default value is specified, not passing any argument will cause an error.
  sayHelloToNullable(null);
  sayHelloToNullable('Bob');
  // sayHelloToNullable(name: 'Tom');   // 'name' is positional parameter and not a 'named' parameter. So, giving name is 
                                        // not allowed during function call.

  // 'named' parameters do not need to be nullable if they do not have null values.

  // 'required named parameters' need to be passed compulsorily to the function'
  print('\n----- Required Named Parameter ----- ');
  print('\n----- Non-nullable Required Named Parameter ----- ');
  doSomething(name: 'Jensen');
  // doSomething();                   // 'Required Named Parameters' can not be omitted. Invalid Code.

  print('\n----- Nullable Required Named Parameter ----- ');
  doSomethingNullable(name: 'Jensen');
  doSomethingNullable(name: null);
  // doSomethingNullable();           // 'Required Nullable-Named Parameters' can not be omitted. 

  print('\n----- Nullable Required Named Parameters Default Behavior ----- ');
  ageProcessor(age: 16);
  ageProcessor(age: null);

  print('\n ----- Order does not matter in Named parameters ------');
  
  print('\n ----- Specifying none of the parameters -----');
  describePerson();
  describePerson(name: null, age: null);

  print('\n ----- Specifying only one parameter -----');
  describePerson(name: 'James');
  describePerson(age: 80);

  print('\n ----- Specifying both the parameters -----');
  describePerson(name: 'Harry', age: 30);
  describePerson(age: 30, name: 'Harry');

  print('\n ---- Positional Parameters (do not have names associated with them, must be passed always, in the same order, can not have default values) ----\n');
  sayGoodbye('Tom', 'Harry');
  sayGoodbye('Foo', 'Bar');
  // sayGoodbye('Harry');                // In Positional parameters, you can not omit the parameters.
  // sayGoodbye();                       // You can not omit the parameters in case of positional parameters.   

  print('\n ----- Nullable Positional Parameters -----');
  sayGoodbyeNullable(null, null);
  sayGoodbyeNullable('Ram', null);
  sayGoodbyeNullable(null, 'Shyam');

  print('\n ----- Optional Positional Parameters -----');
  sayGoodbyeOptional();
  sayGoodbyeOptional('Don');
  sayGoodbyeOptional('Don', 'Bosch');

  print('\n ----- Optional Nullable Positional Parameters -----');
  sayGoodbyeOptionalNullable();
  sayGoodbyeOptionalNullable('Sachin');
  sayGoodbyeOptionalNullable('Sachin', 'Pawan');

  print('\n ----- Optional Nullable Default Positional Parameters -----');
  sayGoodbyeOptionalNullable1();
  sayGoodbyeOptionalNullable1('Joe');
  sayGoodbyeOptionalNullable1('Joe', 'Kate');

  print('\n ----- Both Positional and Named parameters -----');
  bothPositionalOptional('Smith');
  bothPositionalOptional('Laxman', age: 18);
  bothPositionalOptional('Laxman', age: null);

  print('\n ----- Optional parameters with default values ----- ');
  print('addNum()     :- ${addNum()}');
  print('addNum(3, 2) :- ${addNum(3, 2)}');
  print('addNum(3)    :- ${addNum(3)}');
  print('addNum(1, 6) :- ${addNum(1, 6)}');

  print('\n ----- Arrow Function can omit "return" keyword ----- ');
  print('addArrow()         :- ${addArrow()}');
  print('addArrow(30, 5)    :- ${addArrow(30, 5)}');
  print('minusArrow()       :- ${minusArrow()}');
  print('minusArrow(30, 2)  :- ${minusArrow(30, 2)} ');

  print('\n ----- Functions are first class citizens in Dart Language -----'); 
  print('\n ----- i.e. Functions can be passed to a Function as an argument ----- ');

  print('performOperation(1, 1, (a, b) => a+b)  :- ${performOperation(1,1, (int a, int b) => a+b)}' );
  print('performOperation(1, 1, addArrow)       :- ${performOperation(1,1, addArrow)}'      );
  print('performOperation(1, 1, (a, b) => a-b)  :- ${performOperation(1, 1, (int a, int b) => a-b)}');
  print('performOperation(1, 1, minusArrow)     :- ${performOperation(1, 1, minusArrow)}'   );

  print('\n ----- Return Function from a Function ----- ');
  final int Function() tt = addFunc(1, 3);
  print('tt() :- ${tt()}');
  print('addFunc(1, 3)() :- ${addFunc(1, 3)()}');
} // end main() function

int Function() addFunc(int a, int b){
  return ()=> a + b;
}

int addArrow([int lhs = 10, int rhs = 20])   => lhs + rhs;
int minusArrow([int lhs = 10, int rhs = 20]) => lhs - rhs;
int performOperation(int a, int b, int Function(int, int) operation) => operation(a, b);

int addNum([int a=3, int b=2]){
  return a + b;
}

void bothPositionalOptional(String name, {int? age = 35}){
  print('Dear $name, you are $age years old.');
}

void sayGoodbyeOptional([String one='Jay', String two = 'Ramesh']){
  print('Optional :- Goodbye, $one and $two !');
}

void sayGoodbyeOptionalNullable([String? one = 'Tom', String? two]){
  print('Optional Nullable :- Goodbye, $one and $two !');
}

// Even the nullable optional positional parameters can have default values.
void sayGoodbyeOptionalNullable1([String? one ='Tom', String? two='Nick']){
  print('Optional Nullable Default :- Goodbye, $one and $two!');
}

void sayGoodbye(String one, String two){
  print('Goodbye, $one and $two !');
}

void sayGoodbyeNullable(String? one, String? two){
  print('Optional :- Goodbye, $one and $two !');
}

void describePerson({ String? name = 'Bob', int? age = 20 }){
  print('Hi, $name, you are $age years old! ');
}

// Function definition
void printWow(){
  print('Wow');
}

// Function definition - Pls use return types while declaring functions.
printHello(){
  print('Hello world');
}

// The parameters that are enclosed in curly brackets are called as 'named parameters'. 
// 'Named parameters' should either have default values or should be nullable.  
void sayHelloTo({String name = 'Bob'}){
  print('Inside sayHelloTo() function -  Hello $name');
}

// If you want your function to accept null values then whether the parameter is named or not, you need to make 
// that parameter as optional parameter.
void sayHelloToNew({String? name}){
  print('Inside sayHelloToNew() function -  Hello $name');
}

void sayHelloToNullable(String? name){
  print('Inside sayHelloToNullable() function - Hello $name');
}

void doSomething({required String name }){
  print('Hello $name');
}

void doSomethingNullable({required String? name }){
  print('Hello $name');
}

// Required named parameters can not have default values.
/*
void doSomethingDefault({required String? name = 'Bob' }){
  print('Hello $name');
}
*/

// As required named parameters can not have default values, but if they are nullable you can incorporate the 
// default behavior by checking for the 'null' values.
void ageProcessor({required int? age}){
  if(age != null){
    print('You will be of ${age+2} years in coming two years!');
  }
  else{
    print('You did not enter your age! ');
  }
}