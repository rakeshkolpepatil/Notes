import 'package:collection/collection.dart';

void main(List<String> args){
  final Set<String> names = <String>{'Foo', 'Bar', 'Baz', 'Qux'};
  print(names);

  // Sets will have only one instance of the variable.
  names.add('Tom');
  names.add('Tom');
  names.add('Tom');
  names.add('Nick');
  names.add('Nick');
  names.add('Nick');
  print(names);

  // However, lists can have multiple copies.
  final List<String> myClass = <String>['John', 'John', 'Sachin', 'Sachin', 'Ram', 'Ram'];
  print(myClass);

  print('\n-- Spread Operator --');
  final Set<String> mySet = <String>{...myClass};
  print(mySet);
  print(<String>{...mySet});

  // Hash codes determine whether an item can appear twice in a set or not.
  print('\n-- Hash Code --');
  final String stud1 = 'Foo';
  final String stud2 = 'Foo';
  final String stud3 = 'foo';

  print('stud1.hashCode - ${stud1.hashCode}');
  print('stud2.hashCode - ${stud2.hashCode}');
  print('stud3.hashCode - ${stud3.hashCode}');

  print('\n-- contains() function --');
  if(names.contains('Tom')){
    print('"names" contains "Tom"');
  }else{
    print('"names" does not contains "Tom"');
  }

  // Two lists containing identical elements are equal only if they are defined as constants.
  const List<int> constList1 = <int>[1, 2, 3, 4];
  const List<int> constList2 = <int>[1, 2, 3, 4];
  if(constList1 == constList2){
    print('constList1 is equal to constList2');
  }else{
    print('constList1 is not equal to constList2');
  }

  // Two lists containing identical elements are not equal (using "==" operator) as they are defined as final Lists.
  final List<int> finalList1 = <int>[1, 2, 3, 4];
  final List<int> finalList2 = <int>[1, 2, 3, 4];
  if(finalList1 == finalList2){
    print('finalList1 is equal to finalList2');
  }else{
    print('finalList1 is not equal to finalList2');
  }

  // Two sets containing identical elements are equal (using "==" operator) only if they are defined as constants.
  const Set<int> constSet1 = <int>{1, 2, 3, 4};
  const Set<int> constSet2 = <int>{1, 2, 3, 4};
  if(constSet1 == constSet2){
    print('constSet1 is equal to constSet2');
  }else{
    print('constSet1 is not equal to constSet2');
  }

  // Two sets containing identical elements are not equal (using "==" operator) as they are not defined as constants.
  final Set<int> finalSet1 = <int>{1, 2, 3, 4};
  final Set<int> finalSet2 = <int>{1, 2, 3, 4};
  if(finalSet1 == finalSet2){
    print('finalSet1 is equal to finalSet2');
  }else{
    print('finalSet1 is not equal to finalSet2');
  }

  final Set<int> tempSet1 = <int>{2, 4, 3, 1};
  final Set<int> tempSet2 = <int>{1, 2, 3, 4};
  if(finalSet1 == finalSet2){
    print('tempSet1 is equal to tempSet2');
  }else{
    print('tempSet1 is not equal to tempSet2');
  }

  print('\n-- Comparing "Sets" Using "SetEquality" Operator --');
  SetEquality<int>().equals(finalSet1, finalSet2) ? print('finalSet1 is equal to finalSet2') : print('finalSet1 is not equal to finalSet2');
  SetEquality<int>().equals(constSet1, constSet2) ? print('constSet1 is equal to constSet2') : print('constSet1 is not equal to constSet2');
  SetEquality<int>().equals(tempSet1, tempSet2) ? print('tempSet1 is equal to tempSet2') : print('tempSet1 is not equal to tempSet2');
  ListEquality<int>().equals(finalList1, finalList2) ? print('finalList1 is equal to finalList2') : print('finalList1 is not equal to finalList2');
  ListEquality<int>().equals(constList1, constList2) ? print('constList1 is equal to constList2') : print('constList1 is not equal to constList2');


  print('\n-- Implementing the set equality for custom Objects Example 1 -- ');
  Person p1 = Person(name : 'Tom', age: 12);
  Person p2 = Person(name : 'Tom', age: 12);

  // Even though the content of persona1 and persona2 are same Dart does not understand them as same because
  // we have not implemented the function
  final Set<Person> team = <Person>{p1, p2};
  print(team);

  // If you want use the custom class inside a set() then you need to implement in getter function hashCode.
  print(p1.hashCode);
  print(p2.hashCode);

  print('\n-- Implementing Partial set equality for custom Objects Example 2 -- ');
  print('-- Even though the Dog objects has same hashCode they are not same as we have not overloaded "==" operator --');
  Dog d1 = Dog(name : 'Tom', age: 12);
  Dog d2 = Dog(name : 'Tom', age: 12);
  
  // Even though we have implemented the hashCode functions, and the 'hashCode' of both the Dog variables is same 
  // Dart will not consider them as same until we override the method '=='. 
  print('d1.hashCode - ${d1.hashCode}');
  print('d2.hashCode - ${d2.hashCode}');

  final Set<Dog> kennel = <Dog>{d1, d2};
  print(kennel);

}

class Dog{
  final String name;
  final int age;
  Dog({required this.name, required this.age});

  @override
  String toString(){ return 'Dog - $name $age';}

  @override
  int get hashCode => Object.hash(name, age);
}

class Person{
  final String name;
  final int age;

  Person({required this.name, required this.age});

  @override
  String toString(){ return 'Person - $name $age';}

  // Just because the hash value of the object is same that does not mean that the two objects are equal in Dart, 
  // we need to implement the '==' method to compare two objects. This method will be used while comparing the objects in the set. 
  @override
  int get hashCode => Object.hash(name, age);

  @override
  bool operator ==(Object other) {
    if (identical(this, other) || 
      (other is Person && name == other.name && age == other.age)){
        return true;
      }
    else {
      return false;
    }
  }
}