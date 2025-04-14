
void main(List<String> args){

  final Vehicle truck = Vehicle(numWheels: 4);
  print(truck);

  final Car car = Car();
  print(car);

  final Bike bike = Bike();
  print(bike);

  final Bicycle bicycle = Bicycle();
  print(bicycle);
}

class Vehicle {
  final int numWheels;
  const Vehicle({required this.numWheels});

  @override
  String toString () {
    if(runtimeType == Vehicle){
      return '$runtimeType has $numWheels wheels';
    }else{
      // you can call the methods of the parent class using 'super'
      return super.toString();
    }
  }
}

class Car extends Vehicle {
  Car(): super(numWheels: 2);
}

class Bike extends Vehicle {
  Bike(): super(numWheels: 2);
}

class Bicycle extends Vehicle {
  Bicycle(): super(numWheels: 2);
}