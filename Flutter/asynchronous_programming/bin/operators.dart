void main(List<String> args){
  const int age1 = 30;
  const int age2 = 27;
  print('age1 = $age1');
  print('age2 = $age2');
  print('age1 + age2 = ${age1 + age2}');
  print('age1 + age2 + 10 = ${age1 + age2 + 10}');
  print('age1 - age2 = ${age1 - age2}');
  print('age1 * age2 = ${age1 * age2}');

  // If you divide any number by any other number the result will be of 'double' type.
  print('age1 / age2 = ${age1 / age2}');

  // If you want to get 'integer' division then use 'truncating division' operator.
  print('age1 ~/ age2 = ${age1 ~/ age2}');

  // Even for 'double' operands, truncating division will produce integer result.
  print('20.14 ~/ 9.23 = ${20.14 ~/ 9.23}');

  print('\nUnary operators :-');
  int myNum = 10;
  print('myNum = $myNum');

  print('\n--myNum = ${--myNum}');
  print('myNum = $myNum');

  print('\nmyNum-- = ${myNum--}');
  print('myNum = $myNum');

  print('\n++myNum = ${++myNum}');
  print('myNum = $myNum');

  print('\nmyNum++ = ${myNum++}');
  print('myNum = $myNum');

  // The unary '++' operator will modify the operator, but unary '!' negation operator will not modify the operator.  
  const double pi = 3.14;
  print('\npi = $pi');

  // Even following code will not work as it will raise compile time error.
  try{
    // pi++;
  }catch(e){
    print('Unary ++ operator on const values is not supported');
  }

  const bool done = true;
  print('done = $done');
  print('!done = ${!done}');

  // Unary bitwise complement prefix operator 
  print(1);   // (0000 0000) (0000 0000) (0000 0000) (0000 0000)
  print(~1);  // (1111 1111) (1111 1111) (1111 1111) (1111 1110) This is 2's complement form and it represents 2.

  // Unary negation operators do not modify the variables that they are operating upon.
  print('myNum = $myNum');
  print('-myNum = ${-myNum}');
  print('-(-myNum) = ${-(-myNum)}');

  // Binary infix operators 
  print('\n Binary infix operator - ');
  const int percentage = 70;
  print('percentage       := $percentage');
  print('percentage + 21  := ${percentage + 21}');  
  print('percentage - 21  := ${percentage - 21}');  
  print('percentage * 21  := ${percentage * 21}');  
  print('percentage / 21  := ${percentage / 21}');  
  print('percentage ~/ 21 := ${percentage ~/ 21}');  
  print('percentage % 21  := ${percentage % 21}');  

  print('\n Comparison Operators');
  print('percentage       := $percentage');
  print('percentage == 21 := ${percentage == 21}');  
  print('percentage != 21 := ${percentage != 21}');  
  print('percentage < 21  := ${percentage < 21}');  
  print('percentage > 21  := ${percentage > 21}');  
  print('percentage <= 21 := ${percentage <= 21}');  
  print('percentage >= 21 := ${percentage >= 21}');  

  print('\n Bitwise Infix Operators');
  const int age = 12;
  print('age       := $age');
  print('Bitwise AND - age & 10  := ${age & 10}');
  print('Bitwise OR  - age | 10  := ${age | 10}');
  print('Bitwise XOR - age ^ 10  := ${age ^ 10}');
  print('Shift Left  - age << 1  := ${age << 1}');
  print('Shift Right - age >> 1  := ${age >> 1}');

  // If any of the operand of the '+' operator is 'double', the result will be 'double'
  int John = 23;
  double total = John + 2.3;
  print('John  = $John');
  print('total = $total');

  print('Hello' '2');

  // Compound Operators
  print('\n Compound Operators');
  double myAge = 33;
  print('myAge = $myAge');
  print('myAge = 35  := ${myAge = 35}');
  
  print('\n myAge += 10 := ${myAge += 10}');
  print(' myAge = $myAge');
  
  print('\n myAge -= 10 := ${myAge -= 10}');
  print(' myAge = $myAge');

  print('\n myAge *= 10 := ${myAge *= 10}');
  print(' myAge = $myAge');
  
  print('\n myAge /= 10 := ${myAge /= 10}');
  print(' myAge = $myAge');

  int myAge1 = 33;
  print('\n myAge1 &= 10 := ${myAge1 &= 10}');
  print(' myAge1 = $myAge1');

  print('\n myAge1 |= 2 := ${myAge1 |= 2}');
  print(' myAge1 = $myAge1');
  
  print('\n myAge1 ^= 10 := ${myAge1 ^= 10}');
  print(' myAge1 = $myAge1');
  
  // The compound operator '??=' will assign the rhs value to the lhs variable only if it is null.
  String? status;
  status ??= 'unmarried';
  print('The status is - $status ');
  status ??= 'married';
  print('The status is - $status ');
}
