// The enums should be of Pascal Case i.e. First char of every word should be
// capitalized.

enum AnimalType { rabbit, cat, dog }

enum Car {
  TeslaX (manufacturer: 'Tesla', model:'ModelX', year: 2020),
  TeslaY (manufacturer: 'Tesla', model:'ModelY', year: 2023);
  
  final String manufacturer;
  final String model;
  final int year;

  const Car({
    required this.manufacturer,
    required this.model,
    required this.year
  });

  @override
  String toString() => 'manufacturer : $manufacturer, model : $model, year : $year';
}

class Person{
  final String name;
  final Car car;

  const Person({
    required this.name,
    required this.car
  });
}

class Animal{
  final String name;
  final AnimalType type;

  const Animal({required this.name, required this.type});
}

AnimalType? fromStr({required String str}) {
  try{
    return AnimalType.values.firstWhere( (AnimalType e) => e.name == str); 
  }catch(e){
    return null;
  }
}

void main() {
  Animal woof = Animal(name: "woof", type: AnimalType.dog);
  if(woof.type == AnimalType.dog){
    print('Woof is a dog');
  }else{
    print('Woof is not a dog');
  }

  // If switch does not have a 'default' case then you need to cover all the cases.
  switch(woof.type){
    case AnimalType.rabbit:
      print('Woof is a rabbit!');
      break;
    case AnimalType.cat:
      print('Woof is a cat!');
      break;
    case AnimalType.dog:
      print('Woof is a dog!');
      break;
  }

  // You can have only one case of the enum covered and remaining can be kept as default.
  switch(woof.type){
    case AnimalType.cat:
      print('This is a cat!');
      break;
    default:
      print('This is not a cat!');
  }

  Person p = Person(name: 'John', car:Car.TeslaX);
  switch (p.car) {
    case Car.TeslaX:  
      print('The ${p.name} has a Tesla Model X car - ${p.car}');
    case Car.TeslaY:
      print('The ${p.name} has a Tesla Model Y car - ${p.car}');
  }

  // Creating an enum type from a string
  print('\n -- Printing values from the AnimalType -- ');

  print(AnimalType.values);
  print('AnimalType.cat                 :- ${AnimalType.cat}');
  print('AnimalType.cat.name            :- ${AnimalType.cat.name}');
  print('AnimalType.cat.name.toString() :- ${AnimalType.cat.toString()}');
  print('AnimalType.cat.hashCode        :- ${AnimalType.cat.hashCode}');

  print('\n -- Creating an enum type from a string -- ');
  print("fromStr(str: 'rabbit')         :- ${fromStr(str: 'rabbit')}");
  print("fromStr(str: 'cat')            :- ${fromStr(str: 'cat')}");
  print("fromStr(str: 'dog')            :- ${fromStr(str: 'dog')}");

  print('\n -- describe() function --');
  print("describe(fromStr(str: 'rabbit'))           :- ${describe(fromStr(str: 'rabbit'))}");
  print("describe(fromStr(str: 'cat'))              :- ${describe(fromStr(str: 'cat'))}");
  print("describe(fromStr(str: 'dog'))              :- ${describe(fromStr(str: 'dog'))}");
  print("describe(fromStr(str: 'horse'))            :- ${describe(fromStr(str: 'horse'))}");

  print('\n -- Falling through Enumeration Cases -- ');
  final Vehicles fourWheeler = Vehicles.Sedan;

  switch(fourWheeler){
    case Vehicles.Sedan:
    case Vehicles.Auto:
    case Vehicles.Bus:
      print('Most commonly used Vehicles for transport.');
      break;
    case Vehicles.Truck:
      print('Mostly used for transport');
  }

  
}

String describe(AnimalType? animal){
  switch(animal){
    case AnimalType.cat:
      return '${animal?.name} is of type $animal ';

    case AnimalType.dog:
      return '${animal?.name} is of type $animal ';

    case AnimalType.rabbit:
      return '${animal?.name} is of type $animal ';

    default:
      return 'This is a strange animal ';

  }
}

enum Vehicles {
  Sedan, Auto, Truck, Bus
}

