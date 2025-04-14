void main(List<String> args){
  print('\n ----- Control Flow ----- ');

  print('\n ----- In if-else ladder even if multiple conditions are true only first true condition will be executed -----');
  const String yourName = 'foo';
  const String myName = 'bar';

  if(yourName == myName) {
    print('Your name is same as mine');
  } else if(yourName == 'foo') {
    print('Your name starts with f');
  } else if(yourName == 'foo' && myName == 'bar') {
    print('Your name is "foo" and mine is "bar"');
  } else {
    print("Something else !");
  }

  print('\n ----- For Loops ----- ');
  const List<String> classRoom = <String>['foo', 'bar', 'Tom', 'Bob'];

  // for(;;){}  // This is a valid for loop code but will throw errors at runtime.
  print('\n -- Printing in the order --');
  for(int i = 0; i < classRoom.length; i++) {
    print(classRoom[i]);
  }

  print('\n -- Printing in reverse order --');
  for(int i = classRoom.length-1; i>=0; i-- ) {
    print(classRoom[i]);
  }

  print('\n -- Printing custom order --');
  for(int i = 0; i < classRoom.length-1; i += 2 ) {
    print(classRoom[i]);
  }

  print('\n -- Modern For Loops --');
  // Here in each iteration, new instance of 'name' variable is created so 'final'
  // keyword will not result in an error.
  for(final String name in classRoom){
    print(name);
  }

  // 'continue' will stop the execution of the current iteration immediately and will go to 
  // next iteration.
  print('\n -- Use of "continue" statement -- ');
  for(final String name in classRoom){
    if(name.startsWith('f')){
      print(name);
    }else {
      continue;
    }
  }

  // 'break' will stop the execution of the for loop and will exit the loop.
  print('\n -- Use of "break" statement -- ');
  for(final String name in classRoom){
    if(name.startsWith('T')){
      break;
    }
    print(name);
  }

  print('\n -- Reverse Printing modern for loop -- ');
  for(final String name in classRoom.reversed){
    print(name);
  }

  print('\n -- Printing Range in for loop -- ');
  for(int i in Iterable.generate(classRoom.length)){
    print(classRoom[i]);
  }

  print('\n -- Printing Range of numbers -- ');
  for(int i in Iterable.generate(10)){
    print(i);
  }

  print('\n -- Printing List with Range -- ');
  for(int i in Iterable.generate(classRoom.length)){
    print('$i - ${classRoom[i]}');
  }

  print('\n -- While loop --');
  final List<String> names = <String>['Tom', 'Nick', 'Harry', 'John', 'Sachin'];
  int counter = 0;
  while(counter < names.length){
    print('$counter - ${names[counter]}');
    counter++;
  }  

  print('\n ----- While loop - Different way of printing ----- ');
  counter = -1;
  while(++counter < names.length){
    print('$counter - ${names[counter]}');
  }  

  print('\n ----- While loop - Different way of printing ----- ');
  counter = 0;
  while(counter++ < names.length-1){
    print('$counter - ${names[counter]}');
  }  

  print('\n ----- While loop - printing in reverse ----- ');
  counter = names.length;
  while(counter-- > 1){
    print('$counter - ${names[counter]}');
  }  

  print('\n ----- While loop - printing in reverse 1 ----- ');
  counter = names.length-1;
  while(counter > 0){
    print('$counter - ${names[counter]}');
    counter--;
  }  

  print('\n ----- Do while loop - printing in reverse order ----- ');
  counter = names.length-1;
  do{
    print('$counter - ${names[counter]}');
    counter--;
  }while(counter >= 0);  

  print('\n ----- Do while loop - printing in the order ----- ');
  counter = 0;
  do{
    print('$counter - ${names[counter]}');
    counter++;
  }while(counter < names.length);

  print('\n ----- Do while loop - printing in the order ----- ');
  describe(1);
  describe(1.1);
  describe('Ram');
  describe(false);
  describe(<String, String>{'Earth':'Planet'});
  describe(<int> [1,2,3,4,5]);
  describe((1, 2, 3, 4, 5));

  
}

void describe<T>(T value){
  switch(T){
    case int:
      print('The value is an integer: $value');
      break;
    case double:
      print('The value is a double: $value');
      break;
    case String:
      print('The value is a string: $value');
      break;
    case bool:
      print('The value is a boolean: $value');
      break;
    case const(Map<String, String>):
      print('The value is a map: $value');
      break;
    case const(List<int>):
      print('The value is a List: $value');
      break;
    case const(Set<int>):
      print('The value is a Set: $value');
      break;
    default:
      print('The value is of unknown type: $value');
  }
}