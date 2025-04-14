void main() {
  List<dynamic> dynamicList = <>[1, 2.2, 'three', true];
  List<int> intList = dynamicList.whereType<int>().toList();
  List<double> doubleList = dynamicList.whereType<double>().toList();
  List<String> stringList = dynamicList.whereType<String>().toList();
  List<bool> boolList = dynamicList.whereType<bool>().toList();

  print('Original list: $dynamicList');
  print('Integer list: $intList');
  print('Double list: $doubleList');
  print('String list: $stringList');
  print('Bool list: $boolList');

  // Example of cast<T>()
  // Example with potential error
  try {
    List<int> intListCast = dynamicList.cast<int>(); // Might throw an error at runtime
    print('Integer list (cast): $intListCast');
  } catch (e) {
    print('Error during cast: $e');
  }

  List<dynamic> dynamicList1 = <>[1, 2, 3, 4];
  try {
    List<int> intListCast = dynamicList1.cast<int>(); // Might throw an error at runtime
    print('Integer list (cast): $intListCast');
  } catch (e) {
    print('Error during cast: $e');
  }

  dynamic x = "123";
  String s = x as String;
  print(s); // Output: 123

  int y = 12;
  // print(y as String);

  dynamic p = 3.14;
  // print(p as int);

  List<String> stringListNew = dynamicList.map((e) => e.toString()).toList();
  print(stringListNew); // Output: [1, 2, 3]

}// end main function