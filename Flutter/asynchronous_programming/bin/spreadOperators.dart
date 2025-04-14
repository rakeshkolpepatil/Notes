
void main(List<String> args) {
  print('\n------------------------ addToArrayWrong ---------------------------------');
  addToArrayWrong();

  print('\n------------------------ addToArrayRight --------------------------------');
  addToArrayRight();
  
  print('\n------------------------ addToDictionaryWrong------------------------------');
  addToDictionaryWrong();
  
  print('\n------------------------ addToDictionaryRight ------------------------------');
  addToDictionaryRight();
}

void addToArrayWrong(){
  final List<String> name1 = <String>['a', 'b', 'c', 'd', 'e'];
  final List<String> name2 = <String>['x', 'y', 'z'];

  final List<String> wrongList = name1;
  wrongList.addAll(name2);

  print('name1 : $name1');
  print('name2 : $name2');

  print('''\n-- Modifying the "wrongList" will also result in the
    modification of the "name1" list. --''');
  print('wrongList - $wrongList');
}

void addToArrayRight(){
  final List<String> name1 = <String>['a', 'b', 'c', 'd', 'e'];
  final List<String> name2 = <String>['x', 'y', 'z'];

  // Using cascade Operator
  final List<String> rightList = <String>[...name1, ...name2];
  // final List<String> rightList = <String>[...name1, ...name2];
  // rightList.addAll(name2);

  print('name1 : $name1');
  print('name2 : $name2');
  print('rightList - $rightList');
}

void addToDictionaryWrong(){
  const  Map<String, Object> info = <String, Object>{
    'Name': 'John',
    'Age': 30,
    'City': 'New York'
  };

  final Map<String, Object> result = info;
  try{
    result.addAll(<String, Object>{'pincode': 234234});
  }catch(e){
    print(e);
  }
}

void  addToDictionaryRight(){
  const Map<String, Object> info = <String, Object>{
    'Name': 'John',
    'Age': 30,
    'City': 'New York'
  };

  final Map<String, Object> result = <String, Object>{...info};

  result.addAll(<String, Object>{'pincode': 234234});
  print('result - $result');

  final Map<String, Object> result1 = <String, Object>{...info}..addAll(<String, Object>{'pincode': 12343});
  print('result1 - $result1');
}