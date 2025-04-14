import 'dart:io';

void main(List<String> args) {

  do{
    stdout.write('Enter your name or type "exit" : ' );
    String? name = stdin.readLineSync();
    if (name == null){
      print('Invalid name!');
      continue;
    }else if(name == "exit"){
      break;
    }

    switch(name.toLowerCase())
    {
      case 'john':
      case 'jane':
        print('Hi $name, You have a great name!');

      case 'Rakesh':
        continue sport;

      case 'Hardik':
        print('Hi $name, You are a great player!');

      // Here, 'sport' is a label and it can be used for jumping the
      // execution here.  
      sport:
      default:
        print('Hello $name!');
    }
  }while(true);

}