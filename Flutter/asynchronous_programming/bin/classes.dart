

void main(List<String> args){
  // Classes are blueprint of information or logic.
  final Person p1 = Person(name: 'John', age: 23);
  print(p1);
  print('----------------------------------');

  final Person p2 = Person.foo(name: 'Jane');
  print(p2);
  print('----------------------------------');

  final Person p3 = Person.def();
  print(p3);
  print('----------------------------------');

  final Person p4 = Person.another(name: 'Ramesh', age: 100);
  print(p4);
  print('----------------------------------');

  print('\n -- Both arguments are Optional -- ');
  final Person p5 = Person.opti();
  print(p5);
  print('----------------------------------');

  final Person p6 = Person.opti(name: 'John');
  print(p6);
  print('----------------------------------');


  final Person Jill = Person.opti(name: 'Jill', age:60);
  print(Jill);
  print('----------------------------------');
}

class Person{
  final String name;
  final int age;

  // This is const constructor as it takes constant strings as arguments and constructs a const object of Person type. 
  const Person({required this.name, required this.age});

  // Following 'Person.foo' and 'Person.def' are named constructors.
  Person.foo({required this.name}): age = 30;

  Person.def(): name= 'Rahul', age = 30;

  // Another way of defining constructor. 
  Person.another({required String name, required int age}):
    name = name, age = age;
  
  Person.opti({String? name, int? age}):
    name = name?? 'Bob',
    age = age?? 20;
  
  @override
  String toString() => 'Hello, I am $name and I am $age years old';
}