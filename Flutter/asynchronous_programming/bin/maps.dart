

void main(List<String> args){
// Both maps and sets are declared using curly braces however maps contain key-value pairs while sets contain only keys.
  final Map<String, Object> info = <String, Object>{
    'Name': 'John',
    'Age': 30,
    'City': 'New York'
  };

  print('\n -- Accessing data of map --');
  print(info['Name']);
  print(info['Age']);
  print(info['City']);
  print('--------------------------------');

  print('\n-- Accessing keys and values of map --');
  print(info.keys);
  print(info.values);
  print('--------------------------------');

  print('\n-- Accessing keys and values of map --');
  info.putIfAbsent('Height', ()=>150);
  print(info);
  print('--------------------------------');

  print('\n-- Modifying keys and values of map --');
  info['Height'] = 80;
  print(info);
  print('--------------------------------');

  print('\n-- Adding keys directly without checking the map --');
  // Directly assigning the key with weight will either add the key to the map if the key is absent or will modify the 
  // key if it is already present in the map.
  info['Weight'] = 80;
  info['Weight'] = 100;
  print(info);

  print('\n-- Iterating over the map --');
  for( MapEntry<String, Object>entry in info.entries){
    print('${entry.key} = ${entry.value}');
  }

  print('\n-- Checking whether map contains the key --');
  if(info.containsKey('Height')){
    print('Height is present in the map');
  }else{
    print('Height is not present in the map');
  }

  print('\n-- Directly accessing the keys without checking whether key is present in map or not --');
  print('\n-- accessing non existing keys will return null -- ');
  print("info['gender'] = ${info['gender']}");

  print('\n -- maps with integers as keys --');
  final Map<int, String> intMap = <int, String>{0:'zero', 1:'one', 2:'two', 3:'three', 4:'four', 5:'five'};
  print(intMap);
  print("intMap[0] - ${intMap[0]}");
  print("intMap[1] - ${intMap[1]}");

  
}