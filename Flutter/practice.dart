
enum Days {
  Sunday,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
}

void main(){

  /*
  // -------------------- 1. Basic input/output functionality -------------------- 
  print("Welcome to Dart World!");
  stdout.write("Welcome to Dart World! \n");
  var name = stdin.readLineSync(); 
  print('Welcome, $name');
  */ 

  /*
  // -------------------- 2. Dynamic allocation of memory - creating Human class object. -------------------- 
  var h1 = new Human();
  // In Dart, you can omit the new keyword without affecting the creation of class object.
  var h2 = Human();
  */

  /*
  // -------------------- 3. Declaration of Variables and different data types.-------------------- 
  int a;        // 'a' is Non nullable variable i.e. it can not be used until we assign some value to it.
  int? b;       // 'b' is nullable variable, can carry null values, so it can be used without assigning any value. 
  //print(a);   // 'a' can non be printed without assigning any value.

  a = 5;        // Initialization of variable 'a' i.e. the first time value is assigned to it. 
  print(a);
  
  a = 7;
  print(a);

  print(b);

  // inline declaration
  String name = 'India';
  print(name);

  // Using Very Large Integer Values with the help of 'BigInt' class. 
  BigInt bigValue = BigInt.parse('1234134123413412341234123413412341351234234523456');
  print(bigValue);

  // 'double' values
  double pi = 3.1412;
  print(pi);

  // 'num' class can be used for storing both integer and double values
  num x = 10;
  num y = 12.18;
  print(x);
  print(y);

  bool isLogin = false;
  print(isLogin);
  */

  /*
  // -------------------- 4. 'var' and 'dynamic' variables. -------------------- 
  // If a variable is declared using 'var' keyword and initialized in declaration itself then 
  // data type of the first assigned value will become the data type of the variable and 
  // assigning value of another data type will give errors. 
  var sub = "English";
  sub = "Marathi";
  //sub = 8;             // Error 

  // If a variable is declared using 'var' keyword without initializing immediately in the 
  // declaration then it will act as a 'dynamic' variable which can store values of any 
  // data type.
  var name;
  name = 'USA';
  name = 11;
  name = 3.14;

  // The variables declared using 'dynamic' keyword can store values of any data type.
  dynamic state = 10;
  state = 'Texas';
  state = true;
  */

  /*
  // -------------------- 5. Functions -------------------- 
  */

  var record1 = (1, 'a', 2.0); 
  print(record1.$1);      // output: 1
  print(record1.$2);      // output: a
  print(record1.$3);      // output: 2.0

  var record = (number: 1, string: 'a', float: 2.0);
  print(record.number);   // output: 1
  print(record.string);   // output: a
  print(record.float);    // output: 2.0

  /**
   * 6. Enums 
   */
    var today = Days.Friday;
    switch (today) {
        case Days.Sunday:
            print("Today is Sunday.");
            break;
        case Days.Monday:
            print("Today is Monday.");
            break;
        case Days.Tuesday:
            print("Today is Tuesday.");
            break;
        case Days.Wednesday:
            print("Today is Wednesday.");
            break;
        case Days.Thursday:
            print("Today is Thursday.");
            break;
        case Days.Friday:
            print("Today is Friday.");
            break;
        case Days.Saturday:
            print("Today is Saturday.");
            break;
    }

    print("\nPrinting days in Day"); 
    for(Days day in Days.values){
      print(day);
    }
} // End main()

class Human {
  // 'Human' class constructor
  Human();
}

