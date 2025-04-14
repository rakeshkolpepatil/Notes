import 'package:collection/collection.dart';

void main(List<String> args){
  print('\n        -- testBoolList() --');
  testBoolList();

  print('\n        -- testCanonicalizedMap() --');
  print('''Note :- CanonicalizedMap() is used where we need to have a custom criteria to determine whether keys 
should be included or excluded from the map. \n''');
  testCanonicalizedMap();

  print('\n        -- testCanonicalizedMapNew() --');
  testCanonicalizedMapNew();

  // Combined iterables are used in the same way as that of regular iterables.
  // They reflect the changes in the underlying iterables.
  print('\n        -- Combined Iterable --');
  testCombinedIterableView();

  print('\n        -- Combined List View --');
  testCombinedListView();

  print('\n        -- Combined Map View --');
  testCombinedMapView();

  print('\n        -- Map Merge --');
  testMapMerge();
}

void testBoolList() {
  BoolList l = BoolList(10, growable: true);
  print('l :- $l');

  if(l[3] == false){
    print('l[3] is false');
  }else{
    print('l[3] is true');
  }
}

void testCanonicalizedMap() {
  final Map<String, String> myMap = <String, String>{ 'one': 'uno',
    'two': 'dos',
    'three': 'tres',
    'four': 'quatro',
    'five': 'cinco'
  };

  final CanonicalizedMap<int, String, String> cannonMap = CanonicalizedMap.from(myMap, (String key){ return key.length;} );
  print('Keys are canonicalized by their length');
  print("cannonMap :- $cannonMap");
}

void testCanonicalizedMapNew() {
  final Map<String, int> myMap = <String, int>{
    'Marathi' : 88,
    'Physics' : 98,
    'Chemistry' : 100,
    'Bio' : 80,
    'Math' : 100
  };

  // The first character of keys is used for comparing uniqueness of the keys
  final CanonicalizedMap<String, String, int> myCanMap = 
  CanonicalizedMap<String, String, int>.from(myMap, (String key){ return key.split('').first ;});
  print('Keys are canonicalized by their first character');
  print('myCanMap :- $myCanMap');

}

void testCombinedIterableView(){
  final Iterable<String> one = <String>['1', '2', '3', '4'];
  final Iterable<String> two = <String>['one', 'two', 'three', 'four'];
  final List<String> three = <String>['1.1', '1.2', '1.3', '1.4'];

  final CombinedIterableView<String> combItView = CombinedIterableView<String>(<Iterable<String>>[one, two, three]);
  print('CombinedIterableView :- $combItView');
  print('CombinedIterableView.length :- ${combItView.length}');
  three.add('1.5');
  print('CombinedIterableView :- $combItView');
  print('CombinedIterableView.contains(1.1) :- ${combItView.contains('1.1')}');
  print('CombinedIterableView.contains(9)   :- ${combItView.contains(9)}');
}

void testCombinedListView(){
  final List<String> one = <String>['Tom', 'Nick', 'Harry'];
  final List<String> two = <String>['Sam', 'Jack', 'Jerry'];
  final List<String> three = <String>['John', 'Jose', 'Tarry'];

  final CombinedListView myView = CombinedListView(<List>[one, two, three]);
  print('myView :- $myView');
  print('myView.length :- ${myView.length}');
  one.add('Ram');
  print('myView :- $myView');

  // You can not modify the combinedListView 
  print('\nYou can not make any modifications to the combinedListView');
  try{
    myView.removeAt(0);
  }catch(e){
    print(e);
  }
}

void testCombinedMapView(){
  final Map<String, int>one = <String, int>{'one': 1, 'two': 2, 'three': 3};
  final Map<String, int>two = <String, int>{'one': 11, 'two': 22, 'six': 6};
  final Map<String, int>three = <String, int>{'seven': 7, 'six':66, 'nine': 9};

  final CombinedMapView<String, int> myMapView = CombinedMapView<String, int>(<Map<String, int>>[one, two, three]);
  print('\ncombinedMapView will have only one key, duplicate keys will not be inserted.');
  print('myMapView :- $myMapView');
  print('myMapView.length :- ${myMapView.length}');
  try{
    myMapView.addAll(<String, int>{'ten': 10});
  }catch(e){
    print(e);
  }

  print('\nHowever you can modify the individual maps and that will get reflected in the combinedMapView.');
  three.addAll(<String, int>{'ten':10});
  print('myMapView :- $myMapView');

  print('');
  print('myMapView[one] :- ${myMapView["one"]}');
  print('myMapView[nine] :- ${myMapView["nine"]}');
}

void testMapMerge() {
  final Map<String, Object>map1 = <String, Object>{
    'name': 'John 1', 
    'age': 20,
    'weight': 90
  };

  final Map<String, Object> map2 = <String, Object>{
    'name': 'John 2', 
    'age': 20,
    'Height': 90
  };

  final Map<String, Object> myMap = mergeMaps(map1, map2);
  print('myMap :- $myMap ' );

  print('\n Specifying the Custom Criteria when keys match ');
  final Map<String, Object> myMapNew = mergeMaps(map1, map2, value: (Object one, Object two) => one );
  print('myMapNew :- $myMapNew ' );
}