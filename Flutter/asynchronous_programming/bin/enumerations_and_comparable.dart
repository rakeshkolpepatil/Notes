
import 'package:collection/collection.dart';

enum TeslaCars implements Comparable<TeslaCars>{
  teslaCarLarge(weight: 100),
  teslaCarSmall(weight: 70),
  teslaCarMini(weight: 50),
  teslaCarJumbo(weight: 150);

  final int weight;
  const TeslaCars({required this.weight});

  @override
  int compareTo(TeslaCars other) {
    return weight.compareTo(other.weight);
  }
}

void main(){
  print('''\n Note :-  While implementing enumerations with comparable create 
          a class of innumerable first and then convert that class into 
          enumeration for ease of writing code.''');

  print('\n -- Printing the enum without sorting --');
  print(TeslaCars.values);

  print('\n -- Printing the enum after sorting --');
  print(TeslaCars.values.sorted());

  print('\n -- Printing the enum after sorting different way --');
  print(<TeslaCars>[...TeslaCars.values]..sort());

  final List<TeslaCars> sortedEnum = <TeslaCars>[...TeslaCars.values]..sort();
  print(sortedEnum); 
}
