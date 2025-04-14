import 'asynchronous_programming.dart' as asynchronous_programming;

void main(List<String> arguments) async {
  final String name1= getName();
  final String name2= getName();
  print(name1);
  print(name2);
  print('Hello world: ${asynchronous_programming.calculate()}!');

  // If following statement prints `Instance of 'Future<String>'` then it means that Future is not consumed yet.
  print(getNewUserName());

  // Using 'await' keyword resolves/consumes instance of the 'Future<String>'
  print(await getNewUserName());
  print(await getAddress());

  print(await getPhoneNumber());
  print(await getPhoneNumberNew());

  futureDelayed.then((String value) {
    print(value);       // Output: Hello
  }).catchError((error) {
    print(error);
  });

  print('Hello ');
  print(futureDelayed);

  print(getZipcode());
}

String getName() => 'Foo bar';

Future<String> getUserName() async {
  return 'John Doe';
}

// In Dart language, the arrow function should not use the 'return' keyword.
// Future<String> getNewUserName() async => return 'John Doe'; 
Future<String> getNewUserName() async => 'John Doe'; 

Future<String> getAddress() => Future.value('Main Road'); 

Future<String> futureDelayed = Future.delayed(Duration(seconds: 2), () => "Delayed Result");

Future<String> getPhoneNumber() => Future.delayed(
  const Duration(seconds: 2),
  () => '555-555-5555'                  // Using arrow function.s
);

Future<String> getPhoneNumberNew() => Future.delayed(
  const Duration(seconds: 2),
  () { return '555-555-5555';}          // Using inline callback function
);

Future<int> getZipcode() => Future.delayed(
  const Duration(seconds: 3),
  ()=> 123123
);
