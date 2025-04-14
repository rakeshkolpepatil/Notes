

void main(List<String> args) {

  // Lists are generated upfront while iterables are evaluated lazily as and when required.
  // This is because Dart's iterables are lazy. They do not compute their values until they are explicitly accessed.
  // Explanation of Lazy Evaluation
  // When you create an iterable using Iterable.generate(), it defines a generator function that produces values on demand. 
  // Each time you request an element from the iterable (e.g., by iterating over it or printing it), the generator function is 
  // invoked to produce the next value.

  print('\n -- As we are using all the elements in iterable, it generates everything --');
  final Iterable<String> iterable = Iterable.generate(20, (int i){
    print('$i got called.');
    return 'John $i';
  });

  for(String it in iterable){
    print(it);
  }

  print('\n -- Iterable generates only those elements that are requested. --');
  for(String it in iterable.take(2)){
    print(it);
  }

  print("\n-- Iterable.generate() function is called for each time the iterable is accessed --");
  print(iterable);

  print('\n -- List and Iterables --');
  // The map() function on the List will return the Iterable in Dart

  List<String> names = <String>['Tom', 'Nick', 'Harry', 'Bob'];

  Iterable<String> namesUpper = names.map((String s){
    print('map called for "$s"');
    return s.toUpperCase();
  });

  print('-- Prints just 2 values form the iterable and map() function on the names will be called only 2 times. --');
  for(String ss in namesUpper.take(2)) {
    print(ss);
  }

  
}