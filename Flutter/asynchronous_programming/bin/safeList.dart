
import 'dart:collection';

void main(List<String> args) {
  final List<String> names = <String>[];
  try{
    print('-- Accessing the "first", "last" or any element from an empty list will cause error. --'); 
    print(names[1]);
    print(names.last);
    print(names.first);
  }catch(e){
    print(e);
  }

  print('\n        -- SafeList --');
  SafeList<String> sl = SafeList<String>(absentValue: 'NOT_FOUND', defaultValue: 'DEFAULT', values: <String>['Bob', 'Steve']);
  print('sl.first  - ${sl.first} ');
  print('sl.last   - ${sl.last} ');
  print('sl[2]     - ${sl[2]} ');
  print('sl.length - ${sl.length} ');
  print('sl        - $sl');

  print('\n        -- Extending the length of the list using "length" parameter -- ');
  sl.length = 6;
  print('sl        - $sl');

  print('\n -- accessing out of bound elements --');
  print('sl[10] - ${sl[7]}');
  print('sl[10] - ${sl[10]}');
}

class SafeList<T> extends ListBase<T>{
  final List<T> _list;
  final T absentValue;
  final T defaultValue;

  SafeList(
    {
      required this.absentValue, 
      required this.defaultValue, 
      List<T>? values}
      ) : _list = values ?? <T>[];

  @override
  int get length => _list.length;

  @override
  T operator [](int index) => (index < length) ? _list[index] : absentValue;

  @override
  void operator []=(int index, T value) => _list[index] = value;
  
  @override
  set length(int newLen) {
    if(newLen < length) {
      length = newLen;
    }else{
      _list.addAll(List<T>.filled(newLen - _list.length, defaultValue));
    }
  }
  @override
  T get first => _list.isEmpty ? absentValue : _list.first;
  
  @override
  T get last => _list.isEmpty ? absentValue : _list.last;
}