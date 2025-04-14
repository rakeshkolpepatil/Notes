
void main(List<String> args){
  String s = 'abrakadabra';
  String? result = filterAbForLoop(s);
  print('result: $result');
  print('s: $s');

  print('\n-------- filterAbFunction ---------');
  print('filterAbFunction: ${filterAbFunction(s)}');

  print('\n-------- filterAbSetComprehension ---------');
  filterAbSetComprehension(s);

  print('\n ----- List Comprehension -----');
  List<int> numbers = <int>[for (int i = 0; i <10; i++) i ];
  print('numbers :- $numbers');

  List<int> evenNumbers = <int>[for (int i = 0; i <10; i++) if(i%2 == 0) i ];
  print('evenNumbers :- $evenNumbers');
  
  List<int> oddNumbers = <int>[for (int i = 0; i <10; i++) if(i%2 != 0) i ];
  print('oddNumbers :- $oddNumbers');

  Iterable<int> oddNumbersWithFunction = <int>[for (int i = 0; i <10; i++) i].where((int e) => e%2 !=0 );
  print('oddNumbersWithFunction - $oddNumbersWithFunction');

  print('\n ----- Set Comprehension -----');
  Set<int> setComprehension = <int>{for (int i = 0; i <10; i++) i};
  print('setComprehension :- $setComprehension');

  print('\n ----- Map Comprehension -----');
  Map<int, int> mapComprehension = <int, int>{for (int i = 0; i <10; i++) i:i*i};
  print('mapComprehension :- $mapComprehension');

}

String? filterAbForLoop(String s){
  for(final String char in s.split('')){
    if(char == 'a' || char == 'b'){
      s = s.replaceFirst(RegExp(char.toString()), '');
    }
  }
  return s;
}

String? filterAbFunction(String s){
  String result = s.replaceAll('a', '').replaceAll('b', '');
  print( s.split('').map((String x)=>x.toUpperCase()).toSet() );
  return result;
}

void filterAbSetComprehension(String s){
  print('\n --- Inside function filterAbSetComprehension ---');
  final Set<String?> result = <String?>{ for(final String char in s.split('')) 'abc'.contains(char) ? null : char };
  print('result: $result');

  final Set<String?> result1 = <String?>{ for(final String char in s.split('')) 'abc'.contains(char) ? null : char }
  ..removeAll(<Object?>[null]);
  print('result1: $result1');

  final Set<String?> result2 = <String?>{ for(final String char in s.split('')) 'abc'.contains(char) ? null : char }
  ..removeAll(<Object?>[null])
  ..toList();
  print('result2: $result2');

  final Set<String?> result3 = <String?>{ for(final String char in s.split('')) 'abc'.contains(char) ? null : char }
  ..removeAll(<Object?>[null])
  ..toList()
  ..join('');
  print('result3: $result3');

  final String result4 = <String?>{ for(final String char in s.split('')) 'abc'.contains(char) ? null : char }.where((String? e)=> e != null)
  .toList()
  .join('');
  print('result4: $result4');
}

