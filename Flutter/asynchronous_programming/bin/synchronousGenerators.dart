
void main(List<String> args) {
  for(final String name in getNames()){
    print(name);
  }

  print('\n -- Printing only names --');
  for(final String name in getNames1()){
    print(name);
  }

  print('\n-- Take only 3 --');
  for(final String name in getNames1().take(3)){
    print(name);
  }

  print('\n-- Synchronous Generator for getting List content --');
  for(final String name in getNamesFromList().take(4)){
    print(name);
  }
}

Iterable<String> getNames() sync* {
  print('Generating Ram');
  yield 'Ram';
  print('Generating Shyam');
  yield 'Shyam';
  print('Generating Ganesh');
  yield 'Ganesh';
  print('Generating Rajesh');
  yield 'Rajesh';

  print('\n Printing more names ...');
  yield *getMoreNames();
}

Iterable<String> getMoreNames() sync* {
  print('Generating Krishna');
  yield 'Krishna';
  print('Generating Sudhir');
  yield 'Sudhir';
  print('Generating Raghu');
  yield 'Raghu';
}


Iterable<String> getNames1() sync* {
  yield 'Ram';
  yield 'Shyam';
  yield 'Ganesh';
  yield 'Rajesh';
  yield *getMoreNames1();
}

Iterable<String> getMoreNames1() sync* {
  yield 'Krishna';
  yield 'Sudhir';
  yield 'Raghu';
}

Iterable<String> getNamesFromList() sync* {
  final List<String> l = <String>['Krishna', 'Sudhir', 'Raghu', 'Ram', 'Dinesh', 'Sada'] ;
  yield *l;
}