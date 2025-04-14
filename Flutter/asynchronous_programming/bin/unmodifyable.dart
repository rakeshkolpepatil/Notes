import 'package:collection/collection.dart';

void main(List<String> args){
  print('\n                    -- Normal List --                             ');
  List<String> planets = <String>['Sun', 'Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune'];
  planets.add('Pluto');
  print(planets);

  print('\n              -- Unmodifiable List View --                        ');
  UnmodifiableListView<String> listViewPlanets = UnmodifiableListView<String>(planets);
  print(listViewPlanets);

  // UnmodifiableListView is unmodifiable, and modifying it will give an error.
  print('\n        -- Adding an element to Unmodifiable List View --         ');
  try{
    listViewPlanets.add('Alpha Centauri');
  }catch(e){
    print(e);
  }

  print('\n           -- Adding an element to List Constant --               ');
  const List<String> constDays = <String>['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'];
  print(constDays);
  try{
    constDays.add('Holiday');
  }catch(e){
    print(e);
  }

  print('\n             -- Simple map() can be modified --                   ');
  Map<int, String> myMap = <int, String>{1: 'Sun', 2: 'Mon', 3: 'Tue', 4: 'Wed', 5: 'Thu', 6: 'Fri'};

  myMap.addAll(<int, String>{7: 'Sat'});
  print(myMap);

  print('\n                    -- Unmodifiable Map View --                   ');
  print('         -- However, you can not modify unmodifiable map() -- \n');
  UnmodifiableMapView<int, String> myUnmodifiableMapView = UnmodifiableMapView<int, String>(myMap);
  print(myUnmodifiableMapView);
  try{
    myUnmodifiableMapView.addAll(<int, String>{7: 'Sat'});
  }catch(e){
    print(e);
  }

  print('\n                     -------- Notes -------- ');
  print('\nAll the collection data structures have their unmodifiable variants. ');
  print("""Dart does not have concept of private members inside a class. 
To make sure that some members are not modifiable outside the class, 
getter functions are implemented for those members that return unmodifiable variants. """);

  print('\n   -- Using List Views for encapsulation of private variables --');
  Person p1 = Person(name:'John', siblings: <Person>[]);
  print('p1.siblings - ${p1.siblings}');

  Person p2 = Person(name:'Doe', siblings: <Person>[p1]);
  print('p2.siblings - ${p2.siblings}');

  // 'Private' variables in Dart language are package scoped i.e. they are accessible inside the file.
  print('p2._siblings - ${p2._siblings}');
  try{
    p2.siblings?.add(Person(name:'Doe', siblings: <Person>[]));
  }catch(e) {
    print(e);
  }

  print('\n  -- However, you can still modify the private variable --     ');
  p2._siblings?.add(Person(name:'Ram', siblings: <Person>[]));
  print(p2._siblings); 
}

class Person{
  final String name;
  final List<Person>? _siblings;

  const Person({required this.name, required List<Person>? siblings}): _siblings = siblings;
  
  @override
  String toString() => 'name: $name, siblings: ${siblings.toString()}';

  UnmodifiableListView<Person>? get siblings =>
    _siblings == null ? null :  UnmodifiableListView<Person>(_siblings);
}
