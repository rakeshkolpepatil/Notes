late String name;

void main(List<String> args){
  // If 'late' variables are making your code complicated then it means that 'late' variables should not be the
  // choice and you should use 'nullable' or 'non-nullable' variables instead.
  
  // 'late' variables must be initialized before they are used.
  print("\n----- 'late' variables must be initialized before they are used.  ----- ");
  try{
    print(name);
  }catch(e){
    print(e);
  }
  
  name = "late variable";
  print(name);

  // 'late' variables are initialized at the point where they are used.
  print("\n----- 'late' variables are initialized just before they are used.  ----- ");
  print('Before');
  late String name1 = provideName();
  print('After');
  print(name1);

  // 'late' variables in a class.
  print("\n----- 'late' variables in a class  ----- ");
  final Person p1 = Person();
  print('p1.age = ${p1.age}');
  // As 'description' is a late variable, it is assigned a value just before it is used.
  print('p1.description = ${p1.description}');

  // Variables that derive their value by doing some operation on 'late' variable should also be 'late'
  final Scientist s1 = Scientist();
  print('One s1.fullName = ${s1.fullName}');
  print('Two s1.fullName = ${s1.fullName}');
  print('Three s1.fullName = ${s1.fullName}');

  print('s1.firstName = ${s1.firstName}');
  print('s1.lastName = ${s1.lastName}');

  // late final variables can be assigned with value only once.
  Dog d1 = Dog();
  d1.desc = 'New Description';
  print(d1.desc);
  try{
    d1.desc = 'New Description';
    print(d1.desc);
  }catch(e){
    print(e);
  }

  // Dart analyzer will not be able to find out the error below where 'late final' variable is being assigned 
  // twice. So use 'late final' variables carefully. 
  late final bool bool teenager;
  const int age = 12;
  
  if(age >= 13 && age <= 19){
    teenager = true;
  } else if(age < 13){
    teenager = false;
  }

  try{
    teenager = false;
    print('teenager = $teenager');
  }catch(e){
    print(e);
  }

  // Assigning the late variable to the non-late variable will lead to immediately resolving of the late variable.
  print('\n----- Assigning late variable to a non-late variable -----');
  late final String car = getCar();
  final String fourWheeler = car;

  // 'late' instances should not be initialized in the constructors otherwise they will not be lazy as they will get 
  // resolved immediately after the object is created.
  print('\n----- "late" instances should not be initialized in the constructors -----');
  Student stud1 = Student(name: 'John');
  Student stud2 = Student(name: 'Jane');
  WrongImplementationClass wc = WrongImplementationClass(students: <Student>[stud1, stud2]);

  // 'late' variables are initialized where they are declared and not in the constructor.
  print('\n---- In correct implementation of the class, the late variables are initialized only when they are used.');
  CorrectImplementationClass cc = CorrectImplementationClass(students: <Student>[stud1, stud2]);
  print(cc.membersCount);

}

String getCar (){
  print('getCar() function called.');
  return 'Tata Tiago';
}

String provideName(){
  print('Function provideName is called !');
  return "Foo Bar";
}

class Person{
  final int age;
  late String description = descriptionFunction();
  Person({this.age = 18}){
    print('Person constructor is called.');
  }

  String descriptionFunction(){
    print('"descriptionFunction" function is called.');
    return 'Foo Bar';
  }
}

class Scientist {
  late String fullName = _getFullName();
  
  // Variables that derive their value by doing some operation on 'late' variable should also be 'late'
  late String firstName = fullName.split(' ').first; 
  late String lastName  = fullName.split(' ').last;
  
  Scientist ();
  
  String _getFullName(){
    print('_getFullName() function is called');
    return 'Satyendra Bose';
  }
} 

class Dog{
  late final String desc ;

  Dog();
}

class Student {
  String name;
  Student({required this.name}); 
}

class WrongImplementationClass{
  final Iterable<Student> students;
  late int membersCount;
  
  WrongImplementationClass({required this.students}){
    membersCount = getMemberCount();
  }

  int getMemberCount(){
    print('getMemberCount() function is called');
    return students.length;
  }
}


class CorrectImplementationClass{
  final Iterable<Student> students;
  late int membersCount = getMemberCount();
  
  CorrectImplementationClass({required this.students});
  
  int getMemberCount(){
    print('getMemberCount() function is called');
    return students.length;
  }
}