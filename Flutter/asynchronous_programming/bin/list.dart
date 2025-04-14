import 'dart:io';

void main(List<String> age){
  print('--------------------------------');
  print('-- Print list --');
  final List<String> names = <String>['Foo', 'Bar', 'Baz', 'Qux'];
  for(final String name in names){
    print(name);
  }
  print('--------------------------------');
  print('-- Print reversed list --');
  for(final String name in names.reversed){
    print(name);
  }

  print('--------------------------------');
  if(names.contains('Bar')){
    print('"names" list contains "Bar"');
  }
  
  print('\n-- Does "names" list contains "bar" -- ');
  if(!names.contains('bar')){
    print('"names" list does not contain "bar"');
  }

  print('\n-- Names Starting with "B" -- ');
  names.where((String name)=> name.startsWith('B')).forEach(print);
  print(names.where(startsWithB));
  print(names.where(startsWithB_Arrow));

  try{
    print(names[5]);
  }catch(e){
    print(e);
  }

  print('\n-- Print sublist -- ');
  names.sublist(2).forEach((String name) { stdout.write(name); stdout.write(' ');});
  print('');

  names.sublist(3).forEach(stdout.write);
  print('');

  names.sublist(1, 3).forEach((String name) { stdout.write(name); stdout.write(' ');});
  print('');

  final List<int> ages = <int>[10, 20, 30, 40];
  print(ages);
  ages.add(50);
  ages.add(60);
  print(ages);

  print('\n-- Match the lists --');
  const List<String> names1 = <String>['Foo', 'Bar', 'Baz', 'Quax'];
  const List<String> names2 = <String>['Foo', 'Bar', 'Baz', 'Quax'];
  if(names1 == names2){
    print('The lists "names1" and "names2" are equal.');
  }else{
    print('The lists "names1" and "names2" are not equal.');
  }

  // The two lists will be equal only if the contents match exactly.
  const List<String> names3 = <String>['Foo', 'Bar', 'Baz', 'Quax'];
  const List<String> names4 = <String>['foo', 'Bar', 'Baz', 'Quax'];
  if(names3 == names4){
    print('The lists "names3" and "names4" are equal.');
  }else{
    print('The lists "names3" and "names4" are not equal.');
  }

  // map() function.
  print('\n-- map() function on Lists, returns iterable --');
  print(<String>['foo', 'bar', 'baz'].map((String str)=> str.length));
  print(<String>['foo', 'bar', 'baz'].map((String str)=> str.toUpperCase()));

  print('\n-- map() function on Lists, print using "forEach()" --');
  <String>['foo', 'bar', 'baz'].map((String str)=> str.toUpperCase()).forEach(print);

  print('\n-- fold(), reduce entire array --');
  print(<int>{<int>[1, 2, 3].fold(0, (int sum, int i) =>  sum + i )});

  int result = <int>[1, 2, 3].fold(0, (int sum, int i) =>  sum + i );
  print('result = $result');

  String res = <String>['Ram', 'Shyam', 'Ramesh', 'Suresh'].fold('', (String result, String item)=> result.isEmpty ? item : '$result $item');
  print('res    = -$res-');

  String res1 = <String>['Ram', 'Shyam', 'Ramesh', 'Suresh'].fold('', (String result, String item)=> result.isEmpty ? item : '$result ${item.toUpperCase()}');
  print('res1   = -$res1-');


} // end main() function

bool startsWithB (String name){
  return name.startsWith('B');
}

bool startsWithB_Arrow (name) => name.startsWith('B');