#include <iostream>  // Header files for cin, cout functions
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int add_numbers(int a, int b){
  int sum = a + b;
  return sum;
}

int main(){
  /*
  // Printing some lines on output
  cout << "Hello Rakesh! Hope you are doing well!" << endl;
  cout << "Hello Rakesh! " << endl;
  cout << "Hello Rakesh! " << endl;
  cout << "Hello Rakesh! " ;
  cout << "Hello Rakesh! " << endl;
  cout << "Hello Rakesh! " << endl;
  */


  // This is single line comment
  /*
    This is 
    multiline comment
  */

  /*
  // Compiletime error
  //int val = 77/0;
  //cout << "\n This should have given divide by zero error. But, in latest compilers this is not raising any errors. \
  //            It is giving compile time warning. Val :- " << val << endl;
  */

  /*
  // Statements and Functions
  int number1 {3};
  int number2 {20};
  cout << "First number " << number1 << endl;
  cout << "Second number " << number2 << endl;

  int sum = number1 + number2;
  cout << "Sum = " << sum << endl;
  cout << "Sum = " << add_numbers(number1, number2) << endl;
  cout << "Sum = " << add_numbers(34, 56) << endl;
  */

  /*
  // Different output streams 
  cout << "Hello, world!" << endl;
  cerr << "std::cerr output: something went wrong!" << endl;
  clog << "std::clog output: This is log message !" << endl;
  return 0;
  */

  /*
  // Input data to the program  
  int age;
  std::string name;
  cout << "\n Please enter your name and age - " << endl;
  cin >> name >> age;
  cout << "Hello, " << name << "! You care " << age << " years old." << endl;
  */

  /*
  // Input data with spaces
  int age;
  std::string fullName;
  std::cout << "Please enter your full name - " << endl;
  std::getline(std::cin, fullName);
  std::cin >> age;
  std::cout << "Hello, "<< fullName << "! You are " << age << " years old. " << endl;
 */

  /*
  // Number system - All of the following represent number '15' but in different number systems.
	int num = 15;      				// decimals
	int num2 = 017;    				// octal - Numbers that start with zero i.e. '0'
	int num3 = 0x0F;   				// hexadecimal - Numbers that start with '0x'
	int num4 = 0x0f;   				// hexadecimal - Numbers that start with '0x'
	int num5 = 0b00001111;  	// binary -C++14 - Numbers that start with '0b'
  cout<< "num = "<< num << endl;
  cout<< "num2 = " << num2 << endl;
  cout<< "num3 = " << num3 << endl;
  cout<< "num4 = " << num4 << endl;
  cout<< "num5 = " << num5 << endl;
  */

  /*
  // Initializing integer Variables - braced initialization
			cout << "\n---------- braced variable initialization ---------" << endl;
      
      // Variable may contain some random garbage value. Warning
			int elephant_count;
			int lion_count {};  // Initializes the variable to 0
			int dog_count {10}; // Initializes the variable to 10
			int cat_count {15}; // Initializes the variable to 15
			
      // can use expression as initializer
			int domesticated_animals = {dog_count + cat_count}; 
			
      // won't compile, the expression in the braces uses undeclared variables
			// int bad_initialization = {doesnt_exist1 + doesnt_exist2};

			// 2.9 is of type double, with wider range than int. ERROR or Warning.
			// int narrowing_conversion {2.9};
      cout << "elephant_count = " << elephant_count  << endl;
      cout << "lion_count = " << lion_count << endl;
      cout << "dog_count = " << dog_count << endl;
      cout << "cat_count = " << cat_count << endl;
      cout << "domesticated_animals = " << domesticated_animals << endl;
      // cout << "narrowing_conversion = " << narrowing_conversion << endl;

  // Initializing integer Variables - functional variable initialization
  // In functional variable initialization we use parenthesis instead of curly braces for initialization.
			cout << "\n---------- functional variable initialization ---------" << endl;
      int apple_count(5);
      int orange_count(10);
      int fruit_count(apple_count + orange_count);
			
      // won't compile, the expression in the braces uses undeclared variables
      // int bad_initialization_count( doesnt_exist1 + doesnt_exist2 );
      
      // In case of functional initialization, rounding off will happen. Information lost, less safe than braced initialization.  
      int narrowing_conversion_functional(2.8);
      cout << "apple_count: " << apple_count << endl;
      cout << "orange_count: " << orange_count << endl;
      cout << "fruit_count: " << fruit_count << endl;
      
      // cout << "bad_initialization_count: " << bad_initialization_count << endl;
      cout << "narrowing_conversion_functional: " << narrowing_conversion_functional << endl;

  // Initializing integer Variables - assignment initialization
			cout << "\n---------- Integer variable initialization ---------" << endl;
      int bike_count = 2;
      int truck_count = 7;
      int vehicle_count = bike_count + truck_count ;
      int narrowing_conversion_assignment = 2.9;

      cout << "bike_count: " << bike_count << endl;
      cout << "truck_count: " << truck_count << endl;
      cout << "vehicle_count: " << vehicle_count << endl;
      cout << "narrowing_conversion_assignment: " << narrowing_conversion_assignment << endl;

  // sizeof() operator :-
			cout << "\n---------- Integer variable initialization ---------" << endl;
      cout << "sizeof(int)            : " << sizeof(int) << " bytes." << endl;
      cout << "sizeof(bike_count)     : " << sizeof(bike_count) << " bytes." << endl;
      cout << "sizeof(truck_count)    : " << sizeof(truck_count) << " bytes." << endl;

      cout << "\n ------------ 2 bytes -------------" << endl;
      cout << "sizeof(short)          : " << sizeof(short) << " bytes." << endl;
      cout << "sizeof(short int)      : " << sizeof(short int) << " bytes." << endl;
      cout << "sizeof(signed short)   : " << sizeof(signed short) << " bytes." << endl;
      cout << "sizeof(signed short int)   : " << sizeof(signed short int) << " bytes." << endl;
      cout << "sizeof(unsigned short)     : " << sizeof(unsigned short) << " bytes." << endl;
      cout << "sizeof(unsigned short int) : " << sizeof(unsigned short int) << " bytes." << endl;

      cout << "\n ------------ 4 bytes -------------" << endl;
      cout << "sizeof(int) : " << sizeof(int) << " bytes." << endl;
			cout << "sizeof(unsigned) : " << sizeof(unsigned) << " bytes." << endl;
			cout << "sizeof(unsigned int) : " << sizeof(unsigned int) << " bytes." << endl;
			cout << "sizeof(signed) : " << sizeof(signed) << " bytes." << endl;
			cout << "sizeof(signed int) : " << sizeof(signed int) << " bytes." << endl;

      cout << "\n ------------ 4 or 8 bytes -------------" << endl;
      cout << "sizeof(long) : " << sizeof(long) << " bytes." << endl;
			cout << "sizeof(long int) : " << sizeof(long int) << " bytes." << endl;
			cout << "sizeof(singed long) : " << sizeof(signed long) << " bytes." << endl;
			cout << "sizeof(signed long int) : " << sizeof(signed long int) << " bytes." << endl;
			cout << "sizeof(unsigned long) : " << sizeof(unsigned long) << " bytes." << endl;
			cout << "sizeof(unsigned long int) : " << sizeof(unsigned long int) << " bytes." << endl;

      cout << "\n ------------ 8 bytes -------------" << endl;
      cout << "sizeof(long long) : " << sizeof(long long) << " bytes." << endl;
			cout << "sizeof(long long int) : " << sizeof(long long int) << " bytes." << endl;
			cout << "sizeof(singed long long) : " << sizeof(signed long long) << " bytes." << endl;
			cout << "sizeof(signed long long int) : " << sizeof(signed long long int) << " bytes." << endl;
			cout << "sizeof(unsigned long long) : " << sizeof(unsigned long long) << " bytes." << endl;
			cout << "sizeof(unsigned long long int) : " << sizeof(unsigned long long int) << " bytes." << endl;
  */

  /*
  // ---------------- Declare and initialize Fractional/Floating Point numbers ------------------ 
    float number1 {1.12345546467467456};
    double number2 {1.423556567754534523};
    long double number3 {1.364545667567456345};
    std::cout << "number1: " << number1 << " sizeof(float): " << sizeof(number1) << " bytes." << endl; 
    std::cout << "number2: " << number2 << " sizeof(double): " << sizeof(number2) << " bytes." << endl; 
    std::cout << "number3: " << number3 << " sizeof(long double): " << sizeof(number3) << " bytes." << endl; 

    // float number23 {213345850}; // This will give narrowing conversion error as float can have precision of maximum 7 digits. 
                                // Mostly will give compiler error as we are using braced initialization

    float number25 (143556467); // If we use functional initialization, narrowing conversion error will not be caught at compile time
                                // and rounding will happen.
  */

  /*
  // -------------- Some additional operations with Floating Point Numbers ------------------------------
  cout << "----------- Floating Point operations generating infinity/NaN -------------------" << endl;
    float number5 {5.6};
    float number51 {-15.6};
    float number6 {};
    float number7 {};

    float result {number5/number6};
    float result1 {number51/number6};
    cout << number5   << " / " << number6 << " = " << result  << endl;
    cout << number51  << " / " << number6 << " = " << result1 << endl;
    cout << result    << " + " << number6 << " = " << result + number6 << endl;

    // NAN
    result = number6 / number7;
    cout << number6 << " / " << number7 << " = " << result << endl;

  
  // -------------- Some additional operations with Floating Point Numbers ------------------------------
  cout << "----------- Floating Point operations generating infinity/NaN -------------------" << endl;
    double dnumber5 {5.6};
    double dnumber6 {};
    double dnumber7 {};

    double dresult {number5/number6};
    cout << dnumber5 << " / " << dnumber6 << " = " << dresult << endl;
    cout << dresult << " + " << dnumber6 << " = " << dresult + dnumber6 << endl;

    // NAN
    dresult = dnumber6 / dnumber7;
    cout << dnumber6 << " / " << dnumber7 << " = " << dresult << endl;
  */

  /*
  // -------------- Suffixes while initializing Floating Point Numbers ------------------------------
	float num10 {1.12345678901234567890};
	float num11 {1.12345678901234567890f};
	double num22 {1.12345678901234567890};
	long double num30 {1.12345678901234567890};   // As '1.12345678901234567890' is not suffixed with 'L' it is assumed to be double 
                                                // and precision will be lost while storing the number itself.
	long double num31 {1.12345678901234567890L};  // As '1.12345678901234567890' is suffixed with 'L' precision is not lost.
	// long long double num32 {1.12345678901234567890L};  // You can not use two times 'long' along with double.

  cout << "num10: " << std::setprecision(30) << num10 << "  sizeof(num10) : " << sizeof(float) << endl;
  cout << "num11: " << num11 << "  sizeof(num11) : " << sizeof(float) << endl;
  cout << "num22: " << num22 << "  sizeof(num22) : " << sizeof(double) << endl;
  cout << "num30: " << num30 << "  sizeof(num30) : " << sizeof(long double) << endl;
  cout << "num31: " << num31 << "  sizeof(num31) : " << sizeof(long double) << endl;
  // cout << "num32: " << num32 << "  sizeof(num32) : " << sizeof(long long double) << endl;
  */

  /*
  // Float Problems
	// The precision of 'float' is too limited to handle lot of common applications.
		float num41 {1234567890.12345f};            // This will lead to narrowing conversion problems as the max precision 
                                                // 'float' supports is 7, after that garbage value will be printed.
		double num42 {1234567890.12345};            // precision upto 15 is supported after that garbage value will be printed. 
		long double num43 {1234567890.12345L};      // precision more than 15 is supported 

    cout << std::setprecision(25) <<  "num41 : " << num41 << endl;
    cout << "num42 : " << num42 << endl;
    cout << "num43 : " << num43 << endl;
  // 
  */

  /*
  // Boolean values 
  bool red_light { true };
  bool green_light = !red_light;

  if (green_light) {
    cout << " The light is green! " << endl;
  }
  else {
    cout << " The light is NOT green! " << endl;
  }

  if (red_light) {
    cout << " Please stop! You can not proceed with your vehicle." << endl;
  }
  else {
    cout << " Please proceed with your vehicle." << endl;
  }

  // sizeof boolean datatype
  cout << "\n---------- size of boolean data type -------- " << endl;
  cout << " sizeof(bool) = " << sizeof(bool) << " byte." << endl;

  // printing out bool
  // 0 - false
  // 1 - true
  cout << "\n---------- Printing boolean data type -------- " << endl;
  std::cout << " red_light : " << red_light << endl;
  std::cout << " green_light : " << green_light << endl;

  std::cout << std::boolalpha;
  std::cout << " red_light : " << red_light << endl;
  std::cout << " green_light : " << green_light << endl;
  // */

  /*
    // Characters and Text
  char a = 65;
  std::cout << "a = " << a << std::endl;
  std::cout << "sizeof(char) = " << sizeof(char) << " byte." << std::endl;
  std::cout << "value(a) = " << static_cast<int>(a) << std::endl;
  
  char character1 {'H'};
  char character2 {'E'};
  char character3 {'L'};
  char character4 {'L'};
  char character5 {'O'};
  cout << "character1 = " << character1 << endl;
  cout << "character2 = " << character2 << endl;
  cout << "character3 = " << character3 << endl;
  cout << "character4 = " << character4 << endl;
  cout << "character5 = " << character5 << endl;
  */

  /*
  // 'Auto' keyword in C++ 
  auto var1 {'a'};
  auto var2 {12};
  auto var3 {24.8f};
  auto var4 {12.2};
  auto var5 {128u};
  auto var6 {2345667ul};
  auto var7 {123456789012345l};
  auto var8 {123424565672441234ll};

  cout << " char          " << "sizeof(var1) = " << sizeof(var1) << endl; 
  cout << " signed int    " << "sizeof(var2) = " << sizeof(var2) << endl; 
  cout << " float         " << "sizeof(var3) = " << sizeof(var3) << endl; 
  cout << " double        " << "sizeof(var4) = " << sizeof(var4) << endl; 
  cout << " unsigned int  " << "sizeof(var5) = " << sizeof(var5) << endl; 
  cout << " unsigned long " << "sizeof(var6) = " << sizeof(var6) << endl; 
  cout << " long          " << "sizeof(var7) = " << sizeof(var7) << endl; 
  cout << " long long     " << "sizeof(var8) = " << sizeof(var8) << endl; 
  */

  /*
  // Assignments
  int var {22};   // declaration and initialization of a variable 'var'
  cout << "var = "  << var << endl;
  var = 44;       // assignment to a variable 'var'
  cout << "var = "  << var << endl;

  double var1 {56.44};   // declaration and initialization of a variable 'var1'
  cout << "var1 = "  << var1 << endl;
  var1 = 11.22;          // assignment to a variable 'var1'
  cout << "var1 = "  << var1 << endl;

  char var2 {'C'};   // declaration and initialization of a variable 'var2'
  cout << "var2 = "  << var2 << endl;
  var2 = 'Z';        // assignment to a variable 'var2'
  cout << "var2 = "  << var2 << endl;

  bool var3 {true}; // declaration and initialization of a variable 'var3'
  cout << std::boolalpha << "var3 = "  << var3 << endl;
  var3 = false;     // assignment to a variable 'var3'
  cout << "var3 = "  << var3 << endl;

  auto var4 {72u}; // auto declaration of variable 'var4' which is interpreted as unsigned
  cout << "var4 = " << var4 << endl;
  var4 = -22;     // assigning negative number to a unsigned variable 'var4' will lead to wrong interpretation of stored value 
  cout << "var4 = " << var4 << endl;  
  */

  /*
  // Basic Operations on data

  int var1 {11};
  int var2 {33};

  cout << "var1 = " << var1 << endl;
  cout << "var2 = " << var2 << endl;
  cout << "var1 + var2 = " << var1 + var2 << endl;
  cout << "var1 + var2 + var2 = " << var1 + var2 + var2 << endl;

  cout << "var1 - var2 = " << var1 - var2 << endl;
  cout << "var2 - var1 = " << var2 - var1 << endl;

  cout << "var1 * var2 = " << var1 * var2 << endl;
  cout << "var1 / var2 = " << var1 / var2 << endl;
  cout << "var2 / var1 = " << var2 / var1 << endl;

  cout << "var2 % var1 = " << var2 % var1 << endl;
  cout << "5 % 4 = " << 5 % 4 << endl;

  int a {6};
  int b {3};
  int c {8};
  int d {9};
  int e {3};
  int f {2};
  int g {5};

  int result = a + b * c -d/e -f +g;
  cout << "result : " << result << endl;

  result = a/b*c +d -e +f;
  cout << "result : " << result << endl;

  result = (a + b) * c - (d/e) -f + g;
  cout << "result : " << result << endl;

  // Prefix/Postfix increment/decrement
  cout << "\n ---------- Prefix/Postfix increment/decrement ----------- " << endl; 
  int value {5};
  value = value + 1;
  cout << "value : " << value << endl;
  
  value = value - 1;
  cout << "value : " << value << endl;

  cout << "\n ---------- Postfix increment/decrement ----------- " << endl; 
  cout << "value++ : " << value++ << endl;
  cout << "value : " << value << endl;
  
  cout << "value-- : " << value-- << endl;
  cout << "value : " << value << endl;

  cout << "\n ---------- Prefix increment/decrement ----------- " << endl; 
  cout << "++value : " << ++value << endl;
  cout << "value : " << value << endl;

  cout << "--value : " << --value << endl;
  cout << "value : " << value << endl;
  */

  /*
  // Compound Operations on data 
  int value {36};
  cout << "The value is : " << value << endl;

  value += 5;
  cout << "The value is (after +5): " << value << endl;

  value -= 5;
  cout << "The value is (after -5): " << value << endl;

  value *= 5;
  cout << "The value is (after *5): " << value << endl;

  value /= 5;
  cout << "The value is (after /5): " << value << endl;

  value %= 5;
  cout << "The value is (after %5): " << value << endl;
  */

  /*
  // Relational Operators

  int num1 {45};
  int num2 {60};

  cout << "num1: " << num1 << endl;
  cout << "num2: " << num2 << endl;

  cout << "\n-------- Comparing Values --------- " << endl;
  cout << std:: boolalpha;
  cout << "num1 < num2  : " << (num1<num2) << endl;
  cout << "num1 <= num2 : " << (num1 <= num2) << endl;
  cout << "num1 > num2  : " << (num1 > num2) << endl;
  cout << "num1 >= num2 : " << (num1 >= num2) << endl;
  cout << "num1 == num2 : " << (num1 == num2) << endl;
  cout << "num1 != num2 : " << (num1 != num2) << endl;
  */

  /*
  // Logical Operators

  bool a {true};
  bool b {false};
  bool c {true};

  cout << std::boolalpha;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  // AND: Evaluates to true when all operands are true. A single 'false' operand will cause entire expression to be false 
  cout << "\nBasic AND operations " << endl;
  cout << "a && b       : " << (a && b) << endl;
  cout << "a && c       : " << (a && c) << endl;
  cout << "a && b && c  : " << (a && b && c) << endl;

  // OR:  Evaluates to true when any single or both operand/s is/are true.
  cout << "\nBasic OR operations " << endl;
  cout << "a || b       : " << (a || b) << endl;
  cout << "a || c       : " << (a || c) << endl;
  cout << "a || b && c  : " << (a || b || c) << endl;

  // NOT: Negates the operand
  cout << "\nBasic NOT operations " << endl;
  cout << "!a : " << !a << endl;
  cout << "!b : " << !b << endl;

  // Combine Logical Operators in expression
  cout << "!(a && b) : " << !(a && b) << endl;

  int d{45};
  int e{20};
  int f{11};
  cout << "\nRelational and Logical operations on integers " << endl;
  cout << "d = " << d << endl;
  cout << "e = " << e << endl;
  cout << "f = " << f << endl;

  cout << "(d > e) && (d > f)   : " << ((d>e) && (d>f))<< endl; 
  cout << "(d == e) || (e <= f) : " << ((d==e)||(e==f)) << endl;
  cout << "(d < e) || (d > f)   : " << ((d < e) || (d > f)) << endl;
  cout << "(f > e) || (d < f)   : " << ((f > e) || (d < f)) << endl;
  cout << "(d > f) && (f <= d)  : " << ((d > f) && (f <= d)) << endl;
  cout << "(d > e) && (d <= f)  : " << ((d > e) && (d <= f)) << endl;
  cout << "(!a) && (d == e)     : "<< ((!a) && (d == e)) << endl;
  */

  /*
  // Output Formatting 
  // std::endl and "\n" are identical in result but implementations are quiet different. 
  cout << "Hello " << endl;
  cout << "World " << endl;
  cout << endl;

  cout << "Hello\n";
  cout << "World\n";

  // std::flush : flushes the output buffer to its final destination. After this std::flush, we are sure that at this 
  // line, the message has been sent to the stream. This might be important in some applications.
  std:: cout << "This is nice message ...." << std::endl << std::flush;

  // std::setw() : Adjusts the field with for the item about to be printed.
  // The setw() manipulator only affects the next value to be printed.
  cout << "Unformatted table : " << std::endl;
  cout << "Daniel" << " " << "Gray" << "25" << std::endl;
  cout << "Stanley" << " " << "Woods" << "33" << std::endl;
  cout << "Jordan" << " " << "Parker" << "45" << std::endl;
  cout << "Joe" << " " << "Ball" << "21" << std::endl;
  cout << "Josh" << " " << "Carr" << "27" << std::endl;
  cout << "Izaiah" << " " << "Robinson" << "29" << std::endl;

  cout << "\nFormatted table : " << std::endl;
  cout << std::setw(10)<< "Daniel" << " " << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl;
  cout << std::setw(10) << "Stanley" << " " << std::setw(10) << "Woods" << std::setw(5) << "33" << std::endl;
  cout << std::setw(10) << "Jordan" << " " << std::setw(10) << "Parker" << std::setw(5) << "45" << std::endl;
  cout << std::setw(10) << "Joe" << " " << std::setw(10) << "Ball" << std::setw(5) << "21" << std::endl;
  cout << std::setw(10) << "Josh" << " " << std::setw(10) << "Carr" << std::setw(5) << "27" << std::endl;
  cout << std::setw(10) << "Izaiah" << " " << std::setw(10) << "Robinson" << std::setw(5) << "29" << std::endl;

  cout << "\nFormatted table : " << std::endl;
  int col_width {20};
  cout << std::setw(col_width)<< "Daniel" << " " << std::setw(col_width) << "Gray" << std::setw(5) << "25" << std::endl;
  cout << std::setw(col_width) << "Stanley" << " " << std::setw(col_width) << "Woods" << std::setw(5) << "33" << std::endl;
  cout << std::setw(col_width) << "Jordan" << " " << std::setw(col_width) << "Parker" << std::setw(5) << "45" << std::endl;
  cout << std::setw(col_width) << "Joe" << " " << std::setw(col_width) << "Ball" << std::setw(5) << "21" << std::endl;
  cout << std::setw(col_width) << "Josh" << " " << std::setw(col_width) << "Carr" << std::setw(5) << "27" << std::endl;
  cout << std::setw(col_width) << "Izaiah" << " " << std::setw(col_width) << "Robinson" << std::setw(5) << "29" << std::endl;

  cout << "\nRight Justified table : " << std::endl;
  cout << std::right;
  cout << std::setw(col_width)<< "Daniel" << " " << std::setw(col_width) << "Gray" << std::setw(5) << "25" << std::endl;
  cout << std::setw(col_width) << "Stanley" << " " << std::setw(col_width) << "Woods" << std::setw(5) << "33" << std::endl;
  cout << std::setw(col_width) << "Jordan" << " " << std::setw(col_width) << "Parker" << std::setw(5) << "45" << std::endl;
  cout << std::setw(col_width) << "Joe" << " " << std::setw(col_width) << "Ball" << std::setw(5) << "21" << std::endl;
  cout << std::setw(col_width) << "Josh" << " " << std::setw(col_width) << "Carr" << std::setw(5) << "27" << std::endl;
  cout << std::setw(col_width) << "Izaiah" << " " << std::setw(col_width) << "Robinson" << std::setw(5) << "29" << std::endl;

  cout << "\nLeft Justified table : " << std::endl;
  cout << std::left;
  cout << std::setw(col_width)<< "Daniel" << " " << std::setw(col_width) << "Gray" << std::setw(5) << "25" << std::endl;
  cout << std::setw(col_width) << "Stanley" << " " << std::setw(col_width) << "Woods" << std::setw(5) << "33" << std::endl;
  cout << std::setw(col_width) << "Jordan" << " " << std::setw(col_width) << "Parker" << std::setw(5) << "45" << std::endl;
  cout << std::setw(col_width) << "Joe" << " " << std::setw(col_width) << "Ball" << std::setw(5) << "21" << std::endl;
  cout << std::setw(col_width) << "Josh" << " " << std::setw(col_width) << "Carr" << std::setw(5) << "27" << std::endl;
  cout << std::setw(col_width) << "Izaiah" << " " << std::setw(col_width) << "Robinson" << std::setw(5) << "29" << std::endl;

  cout << "\nTable with fill characters : " << std::endl;
  cout << std::left;
  cout << std::setfill('-'); // The fill character
  cout << std::setw(col_width)<< "Daniel" << " " << std::setw(col_width) << "Gray" << std::setw(5) << "25" << std::endl;
  cout << std::setw(col_width) << "Stanley" << " " << std::setw(col_width) << "Woods" << std::setw(5) << "33" << std::endl;
  cout << std::setw(col_width) << "Jordan" << " " << std::setw(col_width) << "Parker" << std::setw(5) << "45" << std::endl;
  cout << std::setw(col_width) << "Joe" << " " << std::setw(col_width) << "Ball" << std::setw(5) << "21" << std::endl;
  cout << std::setw(col_width) << "Josh" << " " << std::setw(col_width) << "Carr" << std::setw(5) << "27" << std::endl;
  cout << std::setw(col_width) << "Izaiah" << " " << std::setw(col_width) << "Robinson" << std::setw(5) << "29" << std::endl;

  cout << "\nInternal Justified : Sign is left justified, whereas data is right justified" << std::endl;
  double i{-23.34};
  cout << std::right;
  cout << std::setfill(' ');
  cout << std::setw(10) << i << std::endl;
  cout << std::internal;
  cout << std::setw(10) << i << std::endl;

  cout << "\n std::boolalpha and std::noboolalpha " << std::endl;
  bool condition = false;
  bool noCondition = true;

  cout << std::boolalpha;
  cout << " condition : " << condition << std::endl;
  cout << " noCondition : " << noCondition << std::endl;

  cout << noboolalpha;
  cout << " condition : " << condition << std::endl;
  cout << " noCondition : " << noCondition << std::endl;

  cout << "\n--- Show Positive Sign --- " << std::endl;
  int posNum {234};
  int negNum {-123};
  double dNum {2378.5980};

  cout << "posNum = " << posNum << std::endl;
  cout << "negNum = " << negNum << std::endl;
  cout << std::showpos << std::endl;
  cout << "posNum = " << posNum << std::endl;
  cout << "negNum = " << negNum << std::endl;
  cout << std::noshowpos << std::endl;      // This is default mode.
  cout << "posNum = " << posNum << std::endl;
  cout << "negNum = " << negNum << std::endl;

  cout << "\n ------ Printing numbers in different bases ------ ";
  cout << "\n ------ Show base -------- " << std::endl;
  cout << std::showbase;
  cout << std::dec << " posNum (dec) : " << posNum << std::endl;
  cout << std::oct << " posNum (oct) : " << posNum << std::endl;
  cout << std::hex << " posNum (hex) : " << posNum << std::endl;

  cout << "\n ------ noshowbase -------- " << std::endl;
  cout << std::noshowbase;
  cout << std::dec << " posNum (dec) : " << posNum << std::endl;
  cout << std::oct << " posNum (oct) : " << posNum << std::endl;
  cout << std::hex << " posNum (hex) : " << posNum << std::endl;

  cout << "\n Positive int in different bases " << std::endl;
  // cout << std::bin << " posNum (bin) : " << posNum << std::endl;  // There is not std::bin function available.
  cout << std::dec << " posNum (dec) : " << posNum << std::endl;
  cout << std::oct << " posNum (oct) : " << posNum << std::endl;
  cout << std::hex << " posNum (hex) : " << posNum << std::endl;

  cout << "\n Negative int in different bases " << std::endl;
  cout << std::dec << " negNum (dec) : " << negNum << std::endl;
  cout << std::oct << " negNum (oct) : " << negNum << std::endl;
  cout << std::hex << " negNum (hex) : " << negNum << std::endl;

  cout << "\n Negative int in different bases (std::uppercase) " << std::endl;
  cout << std::uppercase ;
  cout << std::dec << " negNum (dec) uppercase: " << negNum << std::endl;
  cout << std::oct << " negNum (oct) uppercase: " << negNum << std::endl;
  cout << std::hex << " negNum (hex) uppercase: " << negNum << std::endl;

  cout << "\n Double number in different bases " << std::endl; // Floating point numbers are represented differently and do not change as per base.
  cout << std::dec << " dNum (dec) : " << dNum << std::endl;
  cout << std::oct << " dNum (oct) : " << dNum << std::endl;
  cout << std::hex << " dNum (hex) : " << dNum << std::endl;

  // fixed and scientific notation for floating point values.
  double a { 3.14159265};
  double b { 2006.0};
  double c { 1.34e-10};

  cout << "\nDouble values (default: print scientific wherever necessary): " << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  cout << "\nDouble values (fixed): " << endl;
  cout << std::fixed;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  cout << "\nDouble values (scientific): " << endl;
  cout << std::scientific;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  cout << "\nDouble values (set to default): " << endl;
  cout.unsetf(std::ios::scientific | std::ios::fixed); // Hack
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  // setprecision() : the number of digits printed out for a floating point.
  a = 3.14159265358;
  std::cout << std::endl;
  std::cout << "a default precision(6) : " << a << endl;
  std::cout << std::setprecision(10);
  std::cout << "a setprecision(10)     : " << a << endl;
  std::cout << std::setprecision(20);
  std::cout << "a setprecision(20)     : " << a << endl;

  // showpoint() and noshowpoint(): show trailing zeros if necessary
  // Force output of the decimal point
  double d {32.12};
  double e {102.34};
  double f {12.0};
  int    g {234};
  cout << "\n------- showpoint and noshowpoint -------" << endl;
  cout << std::dec << std::endl;
  cout << "noshowpoint() default " << endl;
  cout << "d = " << d << endl;
  cout << "e = " << e << endl;
  cout << "f = " << f << endl;
  cout << "g = " << g << endl;

  cout << std::showpoint << std::endl;
  cout << "showpoint()" << endl;
  cout << "d = " << d << endl;
  cout << "e = " << e << endl;
  cout << "f = " << f << endl;
  cout << "g = " << g << endl;
  */

  /*
  // ------- Limits library to print range of data types ---------  
  cout << " The range of the 'char' is from " << std::numeric_limits<char>::min() <<  " to " 
        << std::numeric_limits<char>::max() << endl;

  cout << "\n The range of the 'short' is from " << std::numeric_limits<short>::min() <<  " to " 
        << std::numeric_limits<short>::max() << endl;
  cout << " The range of the 'unsigned short' is from " << std::numeric_limits<unsigned short>::min() <<  " to " 
        << std::numeric_limits<unsigned short>::max() << endl;

  cout << "\n The range of the 'int' is from " << std::numeric_limits<int>::min() <<  " to " 
        << std::numeric_limits<int>::max() << endl;
  cout << " The range of the 'unsigned int' is from " << std::numeric_limits<unsigned int>::min() <<  " to " 
        << std::numeric_limits<unsigned int>::max() << endl;

  cout << "\n --- min() for floating point numbers ---\n";
  cout << " The range of the 'float' is from " << std::numeric_limits<float>::min() <<  " to " 
        << std::numeric_limits<float>::max() << endl;
  cout << " The range of the 'double' is from " << std::numeric_limits<double>::min() <<  " to " 
        << std::numeric_limits<double>::max() << endl;
  cout << " The range of the 'long double' is from " << std::numeric_limits<long double>::min() <<  " to " 
        << std::numeric_limits<long double>::max() << endl;

  cout << "\n --- lowest() for floating point numbers - Gives actual smallest number possible ---\n";
  cout << " The range of the 'float' is from " << std::numeric_limits<float>::lowest() <<  " to " 
        << std::numeric_limits<float>::max() << endl;
  cout << " The range of the 'double' is from " << std::numeric_limits<double>::lowest() <<  " to " 
        << std::numeric_limits<double>::max() << endl;
  cout << " The range of the 'long double' is from " << std::numeric_limits<long double>::lowest() <<  " to " 
        << std::numeric_limits<long double>::max() << endl;

  cout << "\n The range of the 'long' is from " << std::numeric_limits<long>::min() <<  " to " 
        << std::numeric_limits<long>::max() << endl;
  cout << " The range of the 'unsigned long' is from " << std::numeric_limits<unsigned long>::min() <<  " to " 
        << std::numeric_limits<unsigned long>::max() << endl;

  cout << "\n The range of the 'long long' is from " << std::numeric_limits<long long>::min() <<  " to " 
        << std::numeric_limits<long long>::max() << endl;
  cout << " The range of the 'unsigned long long' is from " << std::numeric_limits<unsigned long long>::min() <<  " to " 
        << std::numeric_limits<unsigned long long>::max() << endl;

  // is_integer - returns true for all other inbuilt data types except floating point data types.
  cout << " is 'long int' an integer ? :- " << std::numeric_limits<long int>::is_integer << endl; 
  */

  /*
  // cmath functions. 
  double weight{7.7};

  //floor
  cout << weight << " Weight rounded to floor is : " << std::floor(weight) << endl;

  //ceil
  cout << weight << " Weight rounded to ceil is : " << std::ceil(weight) << endl;

  //abs
  int saving {-234};
  cout << "Abs of weight " << weight << " is : " << std::abs(weight) << endl;
  cout << "Abs of saving " << saving << " is : " << std::abs(saving) << endl;

  //exp - e = 2.17828
  double exponential = std::exp(10);
  std::cout << "The exponential exp(10) is : " << exponential << endl;

  //pow
  std::cout << "The 4th power of 3 is (3^4) = " << std::pow(3, 4) << endl;
  std::cout << "The Log of 10 to the base e is = " << std::log(10) << endl;
  std::cout << "The log of 10 to the base 10 is = " << std::log10(10) << endl;

  //sqrt
  std::cout << "The square root of 36 is = " << std::sqrt(36) << endl;

  //round
  std::cout << "3.654 is rounded to = " << std::round(3.654) << endl;
  std::cout << "2.5 is rounded to = " << std::round(2.5) << endl;
  std::cout << "2.4 is rounded to = " << std::round(2.4) << endl;
  */

  /*
  // Weird Integral Types
  short int a {23};
  short int b {54};

  char c1 {'a'};
  char c2 {'b'};

  // Even we are adding short ints of size 2 bytes each and chars of 1 byte each, 'res1' and 'res2' are interpreted as integers of 4 bytes each.
  auto res1 = a + b;
  auto res2 = c1 - c2;

  cout << " size of a = " << sizeof(a) << endl;
  cout << " size of b = " << sizeof(b) << endl;
  cout << " size of c1 = " << sizeof(c1) << endl;
  cout << " size of c2 = " << sizeof(c2) << endl;
  cout << " size of res1 = " << sizeof(res1) << endl;
  cout << " size of res2 = " << sizeof(res2) << endl;
  */

  /*
  // Conditional statements
  // if-else statements
  int num1 {23};
  int num2 {43};
  if (num1 < num2){
    cout << num1 << " is less than " << num2 << endl;
  }else{
    cout << num1 << " is greater than " << num2 << endl;
  }

  // else if clause
  const int Pen {10};       // All these values are made as 'constants' so as to use them inside 'case' statements in 'switch' statements.
  const int Marker {20};
  const int Eraser {30};
  const int Rectangle {40};
  const int Circle {50};
  const int Ellipse {60};

  int tool {Ellipse};
  if (tool == Pen){
    cout << "Pen is active." << endl;
  } else if (tool == Marker){
    cout << "Marker is active." << endl;
  } else if (tool == Eraser){
    cout << "Eraser is active." << endl;
  } else if (tool == Rectangle){
    cout << "Rectangle is active." << endl;
  } else if (tool == Circle){
    cout << "Circle is active." << endl;
  } else if (tool == Ellipse){
    cout << "Ellipse is active." << endl;
  }

  // Switch case
  switch (tool) {
    case Pen :
      cout << "Pen is active." << endl;
      break;
    case Marker :
      cout << "Line is active." << endl;
      break;
    case Eraser :
    case Rectangle :
    case Circle :
    case Ellipse :
      cout << "Drawing shapes .. " << endl;
      break;
    default :
      cout << " Default Case .. " << endl;
  }

  cout << "\n---------------- Ternary Operator ----------------" << endl;
  int max {};
  int first {23};
  int second {34};

  // Type 1 :-
  // max = first > second ? first : second;

  // Type 2 :-
  first > second ? max = first : max = second;

  cout << " first = " << first << endl;
  cout << " second = " << second << endl;
  cout << " max = " << max << endl;

  // Type 3 :- 
  max = first > second ? 100 : -23.5f; // Two option's do not have same type but they are convertible.
                                       // float type of option2 will be converted into int.
  cout << " max = " << max << endl;

  // Ternary initialization 
  bool fast = true;
  int speed {fast? 180: 60};
  cout << std::boolalpha << " fast = " << fast << " -> speed = " << speed << endl;
  */

  /*
  // Loops 
    cout << "\nFirst Loop: " << endl;
    for (unsigned int i{}; i < 10; i++){
      cout << i << ": I Love C++ " << endl;
    }

    cout << "\nSecond Loop: " << endl;
    for (unsigned int i{}; i < 10; ++i){
      cout << i << ": I Love C++ " << endl;
    }

    cout << "\nAccessing iterator outside Loop: " << endl;
    size_t j{};
    for (; j < 10; j++) {
      cout << " j = " << j << endl; 
    }
    cout << "The loop is done. The value of j = " << j << endl;

    // It is advised to not to use hard-coded values in loop conditions.
    cout << "\nUsing variable in loop condition: " << endl;
    size_t COUNT {10};
    for (int i{}; i < COUNT; i++){
      cout << i << ": I Love C++ " << endl;
    }

    cout << "\n------- while loop --------" << endl;
    const unsigned int COUNTER {10};
    size_t iter {};
    while(iter < COUNT){
      cout << "iter : " << iter << endl;
      iter++;
    }

    cout << "\n------- Do while loop --------" << endl;
    const int NEW_COUNTER {10};
    size_t i {0};
    do {
      cout << i <<" : " << " I Love C++ "<< endl;
      i++;
    }
    while(i < NEW_COUNTER);
    cout << "Loop Done " << endl;
  */

  /*
  // Arrays 
  // Declare array
  int scores [10]; // Junk data

  // Read Data
  cout << "scores[0]: " << scores[0] << endl;
  cout << "scores[1]: " << scores[1] << endl;

  // Read with loop
  cout << "\nRead array data with loop - All is garbage data" << endl;
  for (size_t i = 0; i <10; i++) {
    cout << " scores[" << i <<"] : " << scores[i] << endl;
  }

  cout << "\nInitialize some elements : " << endl;
  scores[0] = 100;
  scores[1] = 200;
  
  // Read with loop
  for (size_t i = 0; i <10; i++) {
    cout << " scores[" << i <<"] : " << scores[i] << endl;
  }

  // Declare and initialize an array at the same time
  cout << "\nDeclare and initialize an array at the same time" << endl;
  double salaries [5] {12.34, 164.56, 63.77, 99.03, 100.13 };
  for(size_t i = 0; i < 5; i++) {
    cout << " salaries[" << i << "] : " << salaries[i] << endl;
  }

  // If you do not initialize all the elements then the remaining elements are set to 0.
  cout << "\nUninitialized elements in an array are set to zero." << endl;
  double quantity [5] {12.34, 164.56 };
  for(size_t i = 0; i < 5; i++) {
    cout << " quantity[" << i << "] : " << quantity[i] << endl;
  }

  // Omit the array size when declaring and initializing it at the same time.
  cout << "\nInitializing an array without specifying its size and \n\
            iterating over the array using range based for loop." << endl;
  double ages [] {12, 16, 23, 34, 56};
  for(auto age: ages) {
    cout << " age : "  << age << endl;
  }

  // Read only arrays
  const double heights [] {12, 16, 23, 34, 56};
  // ages[0] = 23; This is not allowed as this is constant array.

  // Sum up marks array and store the result in sum 
  cout << "\nSum up 'marks' array and store the result in 'sum' variable. " << endl;
  int marks[] {1, 2, 3, 4, 5, 6};
  cout << " mark : ";
  for (auto mark: marks)
    cout << mark << " ";
  cout << endl;

  int sum {0};
  for (auto mark: marks)
    sum += mark;
  cout << " sum  : " << sum << endl;

  // Size of array
  cout << "\n--------- Size of array with std::size() ---------" << endl;
  int lengths[] {23, 45, 76, 88, 34, 46, 60};
  cout << " lengths size : " << std::size(lengths) << endl;
  for(size_t i = 0; i < std::size(lengths); i++){
    cout << " lengths[" << i << "] = " << lengths[i] << endl;
  }

  cout << "\n--------- Size of array with sizeof() ---------" << endl;
  cout << "sizeof(lengths) = " << sizeof(lengths) << endl;
  cout << "sizeof(lengths[0]) = " << sizeof(lengths[0]) << endl;
  cout << "lengths item count = " << sizeof(lengths)/sizeof(lengths[0]) << endl;
  */

  /*
  // Array of characters
  cout << "\n ------ Character Array ------- " << endl;
  char message [] {'H', 'E', 'L', 'L', 'O'};

  // Print character array using looping
  cout << "message : " ;
  for (auto c: message) {
    cout << c; 
  }
  // Modifying elements of character array.
  message[0] = 'C';
  cout << "\nModified message : ";
  for (auto c: message) {
    cout << c; 
  }
  // Directly printing character array will print some trailing garbage value.
  cout << "\nDirectly Printing message : " << message << endl;

  // Appending the '\0' to the character array will convert it to the string which can be printed.
  char message_str [] {'H', 'E', 'L', 'L', 'O', '\0'};
  cout << "message_str : " << message_str << endl;

  // If you specify the size of character array but initialize characters less than array size then 
  // compiler will automatically add trailing '\0' to the end of the character array.
  char message_str1 [8] {'H', 'E', 'L', 'L', 'O' };
  cout << "message_str1 : " << message_str1 << endl;

  // But if you do not specify the size while initializing character array and do not explicitly end 
  // character array with '\0' then compiler will not add '\0' at the end of the character array.
  char message_str2 [] {'H', 'E', 'L', 'L', 'O' };
  cout << "message_str2 : " << message_str2 << endl;
  
  cout << "\n ------ Literal C Strings ------- " << endl;
  // Literal C strings
  char message4[] {"Hello"};
  cout << "message4 : " << message4 << endl;
  cout << "size : " << std::size(message4) << endl;

  // spaces are allowed in literal strings
  char message5[] {"Hello, world!"};
  cout << "message5 : " << message5 << endl;
  cout << "size : "<< std::size(message5) << endl;

  // Direct printing of integer arrays is not supported. It will print starting address of the array.
  cout << "\n------- Direct printing of integer arrays is not supported --------- " << endl;
  int numbers[] {1, 2, 3, 4, 5, 6, 7, 8};
  cout << "numbers - " << numbers << endl;
  */

  /*
  // Bounds of an array
  // Reading and writing to the out of bound memory locations is allowed by C++ compiler but might result
  // in unexpected behaviour of your program or other programs. 
  int numbers[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "numbers[12] : " << numbers[12] << endl;

  numbers[12] = 123;
  std::cout << "numbers[12] : " << numbers[12] << endl;

  // Accessing extreme memory bounds of an array - will crash the program
  int nums[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  nums[1234123] = 10;
  cout << "nums[1234123] = " << nums[1234123] << endl;
  cout << "Program finished execution. " << endl;
  */

  /*
  // Pointers
  // Declare and initialize pointer
  int *p_number {}; // will initialize with nullptr
  double* p_fractional_number {}; 

  // Explicitly initialize pointer with nullptr
  int *p_number1 {nullptr}; 
  int *p_fractional_number1 {nullptr};

  // Pointers to different variables are of same size mostly 8 bytes.
  cout << "sizeof(int) : "<< sizeof(int) << endl;
  cout << "sizeof(int*) : "<< sizeof(int*) << endl;
  cout << "\nsizeof(double) : "<< sizeof(double) << endl;
  cout << "sizeof(double*) : "<< sizeof(double*) << endl;
  cout << "\nsizeof(p_number) : "<< sizeof(p_number) << endl;
  cout << "sizeof(p_fractional_number) : "<< sizeof(p_fractional_number) << endl;
  cout << "\nsizeof(long long) : "<< sizeof(long long) << endl;
  cout << "sizeof(long long*) : "<< sizeof(long long*) << endl;
  cout << "\nsizeof(unsigned long long) : "<< sizeof(unsigned long long) << endl;
  cout << "sizeof(unsigned long long*) : "<< sizeof(unsigned long long*) << endl;

  // It does not matter if you put * close to the data type or to the variable name. Compiler will not complain about it.
  int* p_number2 {};
  int * p_number3 {};
  int *p_number4 {};

  // storing address of a variable in pointer
  cout << "\n------- Store address of a variable in pointer ------- " << endl;
  int int_var {23};
  int *p_int_var {&int_var};

  cout << "int_var = " << int_var << endl;
  cout << "p_int_var (Address in memory) = " << p_int_var << endl;

  int int_var1 {45};
  p_int_var = &int_var1;

  cout << "int_var1 = " << int_var1 << endl;
  cout << "p_int_var (With different address in memory) = " << p_int_var << endl;

  // can not cross assign between pointers of different types
  int* p_int1 {nullptr};
  double d_var1 {45.21};
  //p_int1 = &d_var1;      // can not assign address of double variable to int pointer, compiler error.

  // Dereferencing a pointer.
  cout << "\n-------- Dereferencing a pointer --------  " << endl;
  int* p_int2 {nullptr};
  int p_data {456};
  
  p_int2 = &p_data;
  cout << "p_data = " << *p_int2 << endl; // dereferencing a pointer
  */

  /*
  // Character Pointers

  // pointer to char can be declared in same way as pointer to integer.
  cout << "\n-------- Pointers to char -------- " << endl;
  char *p_char {nullptr};
  char c_var1 {'A'};

  p_char = &c_var1;
  cout << "The value stored at p_char = " << *p_char << endl;

  char c_var2 {'B'};
  p_char = &c_var2;
  cout << "The value stored at p_char = " << *p_char << endl;

  // char pointers can also be initialized with C-String literals
  // char *p_char1 {"Hello"};       // Latest compilers are giving issue with this way of initialization.
                                    // as string literals are internally stored as an array of const char.

  const char *p_char2 {"Hello"};
  cout << "p_char2 = " << p_char2 << endl;                        // You can print entire string using p_char2. 
                                                                  // That is beauty of character pointers.
  cout << "\nThe value stored at p_char2 = " << *p_char2 << endl;

  // *p_char2 = 'B'; // Compiler will not allow modification of the character stored at p_char2 as it is const pointer.

  // If you want to modify the characters in string literal then use pure array.
  char p_char3 [] {"Hello World!"}; 
  cout << "p_char3 = " << p_char3 << endl;
  p_char3[0] = 'B';
  cout << "p_char3 after modification = " << p_char3 << endl;
  */

  /*
  // Heap Memory

  cout << " -------- Heap Memory -------- " << endl;
  // Following code will segmentation fault.
  cout << " Writing to uninitialized pointer through dereference is really BAD " << endl;
  int *p_pointer1;    // Contains junk address : Could be anything
  *p_pointer1 = 23;   // Writing into JUNK address : BAD !! 

  cout << endl; 
  cout << "p_pointer1 = " << p_pointer1 << endl;
  cout << "*p_pointer1 = " << *p_pointer1 << endl;

  // Following code will segmentation fault.
  int *p_pointer2{};
  int *p_pointer3{nullptr}; 
  cout << " Writing to nullptr memory << " << endl;

  *p_pointer2 = 45;
  *p_pointer3 = 34;
  cout << "p_pointer2  = " << p_pointer2 << endl;
  cout << "*p_pointer2 = " << *p_pointer2 << endl;
  cout << "p_pointer3  = " << p_pointer3 << endl;
  cout << "*p_pointer3 = " << *p_pointer3 << endl;
  */

  /*
  // Dynamic Heap Memory
  int *p_number4{nullptr};
  p_number4 = new int;    // Dynamically allocate Space for a single int on the heap.
                          // This memory belongs to a program from now on. The system can't use it for anything else until we return it.
                          // After this line executes, we will have a valid memory location allocated. 
                          // The size of allocated memory will be such that it can store the type pointed to by the pointer.

  *p_number4 = 23;    // Writing successfully into dynamically allocated memory.
  cout << endl;
  cout << "Dynamically allocating memory" << endl;
  cout << "*p_number4 = " << *p_number4 << endl;

  delete p_number4; // Return memory to the OS
  //*p_number4 = 70;  // Writing to deleted memory is wrong practice and will crash the program.
  //cout << "Done writing to deleted memory" << endl;

  p_number4 = nullptr; // It is good practice to reset the memory pointer.
  */
  
  /*
  // Dynamically initializing the pointers
  int *p_number4{new int};      // Memory is allocated within the access rights of the current program. 
  int *p_number5{new int(23)}; 	// Direct initialization method.
  int *p_number6{new int{23}};  // Uniform initialization method.

  cout << " ------------ Initialize with valid memory address at the time of declaration -------------" << endl;
  cout << "p_number4  = " << p_number4 << endl;
  cout << "*p_number4 = " << *p_number4 << endl;  // Junk Value but program will not crash.

  cout << "p_number5  = " << p_number5 << endl;
  cout << "*p_number5 = " << *p_number5 << endl;

  cout << "p_number6  = " << p_number6 << endl;
  cout << "*p_number6 = " << *p_number6 << endl;

  // Remember to release the memory
  delete p_number4;
  p_number4 = nullptr;

  delete p_number5;
  p_number5 = nullptr;

  delete p_number6;
  p_number6 = nullptr;

  // Can reuse pointers that were deleted earlier
  p_number4 = new int(88);
  cout << "*p_number4 : " << *p_number4 << endl;
  delete p_number4;
  p_number4 = nullptr;
  
  // Calling the delete function on same pointer twice is BAD! 
  p_number5 = new int(100);
  cout << "*p_number5 : " << *p_number5 << endl;
  delete p_number5;
  //delete p_number5;  // deleting same pointer twice will not be detected by compiler but lead to crashing of the program.

  cout << "Program ended successfully !! " << endl;
  */

  /*
  // Dangling Pointer
  // Case 1 : uninitialized pointer
  int *p_int;
  cout << endl;
  cout << "Case 1 : uninitialized pointer" << endl;
  cout << " p_int  : " << p_int << endl;
  //cout << "*p_int : " << *p_int << endl;       // Will lead to crash of the program.

  // Case 2 : deleted pointer
  cout << "\nCase 2 : Deleted Pointer " << endl;
  int *p_number{new int{34}};
  cout << " *p_number (before deleting): " << *p_number << endl;
  delete p_number;
  cout << " *p_number (After deleting): " << *p_number << endl;

  // Case 3 : Multiple Pointers pointing to the same memory location
  cout << "\nCase 3 : Multiple Pointers Pointing to the same memory location " << endl;
  int *p_number1{new int{99}};
  int *p_number2{p_number1};

  cout << " p_number1 : " << p_number1 << " -> " << *p_number1 << endl;
  cout << " p_number2 : " << p_number2 << " -> " << *p_number2 << endl;

  delete p_number1;

  // Now, p_number2 points to the deleted memory. Dereferencing it will lead to the undefined behavior: crash/garbage value or whatever.
  cout << " p_number2 (after deleting p_number1) : " << p_number2 << " -> " << *p_number2 << endl;

  // Solution 1 : uninitialized pointer
  int *p_int1 {};
  int *p_int2 {new int{33}};
  cout << endl;
  cout << "\nSolution 1 : Uninitialized pointer" << endl;
  
  //Check for nullptr before use
  if(p_int1 != nullptr){
    cout << " p_int1  : " << p_int1 << endl;
  }else{
    cout << "Invalid Address" << endl;
  }
  if(p_int2){
    cout << " p_int2 : " << p_int2 << endl;
  }else{
    cout << "Invalid Address" << endl;
  }

  // Solution 2 : Right after you call 'delete' on a pointer, remember to reset the pointer so that it doesn't point anywhere.
  cout << "\nSolution 2 : Reset Pointer after deleting it " << endl;
  int *p_number3{new int{34}};

  // Use the pointer as you want
  cout << " p_number3 : " << p_number3 << " -> " << *p_number3 << endl;
  delete p_number3;
  p_number3 = nullptr;

  // Check the pointer before dereferencing it.
  if(p_number3 != nullptr)
    cout << " *p_number3 (After deleting and resetting the pointer): " << *p_number3 << endl;
  else
    cout << " Invalid pointer." << endl;

  // Solution 3 : For multiple pointers pointing to the same memory location, make sure that there is a clear pointer (master pointer) 
  //              that owns the memory and is responsible for releasing the memory whenever necessary. Other pointers should only be 
  //              able to dereference when the master pointer is valid.

  cout << "\nSolution 3 : Make one pointer master pointer when multiple pointers point to same memory location " << endl;
  int *p_number4 {new int{56}};
  int *p_number5 {p_number4};

  cout << " p_number4 : " << p_number4 << " -> " << *p_number4 << endl;

  // Only use slave pointers when the master pointer is valid
  if (p_number4 != nullptr){
    cout << " p_number5 : " << p_number5 << " -> " << *p_number5 << endl;
  }

  delete p_number4;
  p_number4 = nullptr;

  if (p_number4 != nullptr){
    cout << " p_number5 : " << p_number5 << " -> " << *p_number5 << endl;
  }else{
    std::cerr << " WARNING: Trying to use invalid pointer!" << endl;
  }
  */
  
  /*
  // Handling 'new' operator failures

  // Try to allocate insanely huge array in one go. Unhandled new failure : crash	
  int* very_big_int_array {new int[1'000'000'000'000'000]};

  // Use a huge loop to try and exhaust the memory capabilities of your system. When new fails your program is going to 
  // forcefully terminate.

  for (size_t i{}; i < 1'000'000'000'000; i++){
    int* lots_of_ints2 {new int[1'000'000'000'000'000]};
  }
  cout << "Program successfully allocated memory on heap " << endl;

  // Method 1 : Handling allocation errors using Exception
  // Handle the problem in a way that makes sense for your program. For example if you were trying to allocate memory to 
  // store color information for your application, and application fails, you could opt out showing some feedback message 
  // to the user and rendering your app in black and white.
  for (size_t i{}; i < 100; i++){
    try{
      int* lots_of_ints2 {new int[1'000'000'000'000'000]};
    }catch(std::exception& e){
      cout << "Caught Exception Ourselves: " << e.what() << endl;
    }
  }
  cout << "Program successfully Ended! " << endl;

  // Method 2 : std::nothrow - Ideal when you do not want exceptions to be thrown when new() fails.
  for (size_t i{}; i < 100; i++){
      int* lots_of_ints2 {new(std::nothrow) int[1'000'000'000'000'000]};
      if(lots_of_ints2 == nullptr){
        cout << "Memory allocation Failed!" << endl;
      }
      else{
        cout << "Memory allocation Successful!" << endl;
      }
  }
  */

  /*
  // Null pointer safety.

	// Verbose nullptr check
	int *p_int{ new int{}};
	if(p_int != nullptr){
		cout << "p_int points to a VALID address : "<< p_int << endl;
	}else{
		cout << "p_int points to an INVALID address : "<< p_int << endl;
	}

	// Compact nullptr check - as pointer value is also convertible to boolean value for conditional checking.
	int *p_int1{ new int{}};
	if(p_int1){
		cout << "p_int points to a VALID address : "<< p_int << endl;
	}else{
		cout << "p_int points to an INVALID address : "<< p_int << endl;
	}

  // deletion operation on pointers do not require checking of nullptr.
  int *p_number1 {};
  delete p_number1;  // This will not cause any problem if p_number1 contains nullptr.

  // so no need to overdo something like this
  if(p_number1){
    delete p_number1;
    p_number1 = nullptr;
  }
  */

  /*
  // Memory Leaks 
  // Scenario 1 : Reassignment of stack address to active dynamic address pointer.
    int *p_num1{new int{34}}; // Points to some address lets call it address1.
    int number = 32;          // stored at address2.
    p_num1 = &number;         // Now, p_num1 points to address2. However, the address1 is still used by our 
                              // program. But, our program has lost access to that memory location.
    													// Memory has been leaked.

  // Scenario 2 : Double allocation to a pointer
    int *p_num2{new int{34}};   
    p_num2 = new int{44};      // memory with int{34} leaked.

	// Scenario 3 : Pointer in local scope
    {
      {
        int *p_number2 { new int{234}};
      }
      // 'p_number2' goes out of scope and memeory with int{234} gets leaked.
    }
  */

  /*
  // Dynamically allocated arrays
    size_t size {10};

    double *p_salaries { new double[size] };                              // 'p_salaries' array will contain garbage values.
    int *p_students    { new(std::nothrow) int[size]{} };									// 'p_students' array will contain 10 integer values initialized to 0.
    double *p_scores   { new(std::nothrow) double[size]{1, 2, 3, 4, 5}};  // 'p_scores' array will contain 10 double values. First 5 will be initialized as specified 
                                                                          // and remaining 5 will be initialized to 0.

    if(p_salaries){
      for(size_t i = 0; i < size; i++){
        // For printing array elements we can use regular array access notation, or pointer arithmetic syntax.
        cout << " p_salaries[" << i << "] : " << p_salaries[i] << " - " << *(p_salaries + i) << endl;
      }
    }

    cout << endl;
    if(p_students){
      for(size_t i = 0; i < size; i++){
        // For printing array elements we can use regular array access notation, or pointer arithmetic syntax.
        cout << " p_students[" << i << "] : " << p_students[i] << " - " << *(p_students + i) << endl;
      }
    }

    cout << endl;
    if(p_scores){
      for(size_t i = 0; i < size; i++){
        // For printing array elements we can use regular array access notation, or pointer arithmetic syntax.
        cout << " p_scores[" << i << "] : " << p_scores[i] << " - " << *(p_scores + i) << endl;
      }
    }

    double *students {new(std::nothrow) double[]{1.1, 2.2, 3.3, 4.4, 5.5, 6.6}};

    // std::size() operator will not work on pointers pointing to the dynamically allocated arrays
    cout << "Size of array students : " << std::size(students) << endl;

    // range based for loop will not work on pointers pointing to dynamically allocated arrays
    cout << "Content of students array : - " << endl;
    for (auto i: students){
      cout << " i : " << i << endl;
    }
  */

  /*
  // References in C++
    int int_val{23};
    double d_val{22.11};

    // int& ref_i; // This will throw error

    int& 		ref_to_int_val1 {int_val};   	// reference assigning through initialization
    int& 		ref_to_int_val2 = int_val;   	// reference assigning through assignment
    double& ref_to_d_val{d_val}; 		

    cout << "\n------- Values of all variables and their references ------------- " << endl;
    cout << " int_val         : " << int_val << endl;
    cout << " ref_to_int_val1 : " << ref_to_int_val1 << endl;
    cout << " ref_to_int_val2 : " << ref_to_int_val2 << endl;
    cout << " d_val           : " << d_val << endl;
    cout << " ref_to_d_val    : " << ref_to_d_val << endl;

    cout << "\n------- Address of variables and their references -------" << endl;
    cout << " &int_val         : " << &int_val << endl;
    cout << " &ref_to_int_val1 : " << &ref_to_int_val1 << endl;
    cout << " &ref_to_int_val2 : " << &ref_to_int_val2 << endl;
    cout << " &d_val           : " << &d_val << endl;
    cout << " &ref_to_d_val    : " << &ref_to_d_val << endl;

    cout << "\n------- size of variables and their references ------ " << endl;
    cout << " sizeof(int_val)         : " << sizeof(int_val) << endl;
    cout << " sizeof(ref_to_int_val1) : " << sizeof(ref_to_int_val1) << endl;
    cout << " sizeof(d_val)           : " << sizeof(d_val) << endl;
    cout << " sizeof(ref_to_d_val)    : " << sizeof(ref_to_d_val) << endl;

    cout << "\n------- Modifying the data through original variables --------" << endl;
    int_val = 111;
    d_val = 222.22;
    cout << " int_val          : " << int_val << endl;
    cout << " &int_val         : " << &int_val << endl;
    cout << " ref_to_int_val1  : " << ref_to_int_val1 << endl;
    cout << " &ref_to_int_val1 : " << &ref_to_int_val1 << endl;
    cout << " ref_to_int_val2  : " << ref_to_int_val2 << endl;
    cout << " &ref_to_int_val2 : " << &ref_to_int_val2 << endl;
    cout << " -------------------------" << endl;
    cout << " d_val            : " << d_val << endl;
    cout << " &d_val           : " << &d_val << endl;
    cout << " ref_to_d_val     : " << ref_to_d_val << endl;
    cout << " &ref_to_d_val    : " << &ref_to_d_val << endl;

    cout << "\n------- Modifying the data through reference variable --------" << endl;
    ref_to_int_val1 = 123;
    ref_to_d_val = 890.55;
    cout << " int_val          : " << int_val << endl;
    cout << " &int_val         : " << &int_val << endl;
    cout << " ref_to_int_val1  : " << ref_to_int_val1 << endl;
    cout << " &ref_to_int_val1 : " << &ref_to_int_val1 << endl;
    cout << " ref_to_int_val2  : " << ref_to_int_val2 << endl;
    cout << " &ref_to_int_val2 : " << &ref_to_int_val2 << endl;
    cout << " -------------------------" << endl;
    cout << " d_val            : " << d_val << endl;
    cout << " &d_val           : " << &d_val << endl;
    cout << " ref_to_d_val     : " << ref_to_d_val << endl;
    cout << " &ref_to_d_val    : " << &ref_to_d_val << endl;
  */

  /*
  // Comparing References to Pointers

  double d_val {23.54};
  double& ref_to_d_val {d_val};
  double *p_d_val {&d_val};

  cout << "\n---- Values ----" << endl;
  cout << " d_val        : " << d_val << endl;
  cout << " ref_to_d_val : " << ref_to_d_val << endl;
  cout << " p_d_val      : " << p_d_val << endl;
  cout << " *p_d_val     : " << *p_d_val << endl;

  // Writing through pointer
  cout << "\n---- Writing through pointer ----" << endl;
  *p_d_val = 25.55;
  cout << " d_val        : " << d_val << endl;
  cout << " ref_to_d_val : " << ref_to_d_val << endl;
  cout << " p_d_val      : " << p_d_val << endl;
  cout << " *p_d_val     : " << *p_d_val << endl;

  // writing through reference
  cout << "\n---- Writing through reference ----" << endl;
  ref_to_d_val = 23.33;
  cout << " d_val        : " << d_val << endl;
  cout << " ref_to_d_val : " << ref_to_d_val << endl;
  cout << " p_d_val      : " << p_d_val << endl;
  cout << " *p_d_val     : " << *p_d_val << endl;

  double other_double_val {300.8};

  // The following thing works but it does not make 'ref_to_d_val' refer to 'other_double_val' 
  // It will just copy the value of 'other_double_val' into 'ref_to_d_val'.
  cout << "\n---- Assigning 'other_double_val' variable to 'ref_to_d_val' just copies the value ----" << endl;
  cout << " ref_to_d_val (old): " << ref_to_d_val << endl;
  ref_to_d_val = other_double_val;
  cout << " other_double_val  : " << other_double_val << endl;
  cout << " ref_to_d_val (New): " << ref_to_d_val << endl;

  // If you change the 'ref_to_d_val' now, 'other_double_val' will remain unchanged proving that
  // 'ref_to_d_val' was not referencing 'other_double_val' 
  cout << "\n---- Changing 'ref_to_d_val' does not affect 'other_double_val' variable ----" << endl;
  ref_to_d_val = 1111.2222;
  cout << " other_double_val (old) : " << other_double_val << endl;
  cout << " ref_to_d_val           : " << ref_to_d_val << endl;
  cout << " other_double_val (New) : " << other_double_val << endl;
  */

  /*
  // 	Const and Non-Const references
  cout << "\n---- Non-Const references ----" << endl;
  int age {70};
  int& ref_age {age};

  cout << " age     = " << age << endl;
  cout << " ref_age = " << ref_age << endl;

  cout << "\n---- Modifying 'age' using its reference ----" << endl;
  ref_age = 40;
  cout << " age     = " << age << endl;
  cout << " ref_age = " << ref_age << endl;

  cout << "\n---- Const references ----" << endl;
  int score{99};
  const int& ref_score {score};

  cout << " score     = " << score << endl;
  cout << " ref_score = " << ref_score << endl;

  cout << "\n---- Modifying 'score' using its const reference is not possible ----" << endl;
  //ref_score = 40;    // Trying to modify 'score' using its reference is not possible
  score = 18;          // However, we can modify original variable. As it is not const but its reference is.
  cout << " score     = " << score << endl;
  cout << " ref_score = " << ref_score << endl;

  cout << "\n ---- Simulating const reference behavior using pointers ----" << endl;
  int* const p_score {&score};
  cout << " *p_score = " << *p_score << endl;
  // p_score++; // Modifying 'p_score' is not possible because of const keyword.
  cout << " *p_score = " << *p_score << endl;

  cout << "\n ---- Const Pointer to Const variable ----" << endl;
  const int pi{3};
  const int* const p_pi{&pi};

  cout << " pi = " << pi << endl;
  cout << " *p_pi = " << *p_pi << endl;

  //pi++;   // Modifying 'pi' is not possible because it is const int.
  //p_pi++; // Modifying 'p_pi' is not possible because it is const pointer.
  */

  /*
  // Character Manipulation and strings

  cout << "\n ------- isalnum() --------" << endl;
  cout << std::boolalpha << " std::isalnum('c') = " << std::isalnum('c') << std::endl; 
  cout << std::boolalpha << " std::isalnum('0') = " << std::isalnum('0') << std::endl; 
  cout << std::boolalpha << " std::isalnum('@') = " << std::isalnum('@') << std::endl; 

  cout << "\n ------- isalpha() --------" << endl;
  cout << std::boolalpha << " std::isalpha('c') = " << std::isalpha('c') << std::endl; 
  cout << std::boolalpha << " std::isalpha('X') = " << std::isalpha('X') << std::endl; 
  cout << std::boolalpha << " std::isalpha('0') = " << std::isalpha('0') << std::endl; 
  cout << std::boolalpha << " std::isalpha('@') = " << std::isalpha('@') << std::endl; 

  cout << "\n ------- isblank() --------" << endl;
  cout << std::boolalpha << " std::isblank('c') = " << std::isblank('c') << std::endl; 
  cout << std::boolalpha << " std::isblank(' ') = " << std::isblank(' ') << std::endl; 

  cout << "\n ------- islower() --------" << endl;
  cout << std::boolalpha << " std::islower('a') = " << std::islower('a') << std::endl; 
  cout << std::boolalpha << " std::islower('A') = " << std::islower('A') << std::endl; 

  cout << "\n ------- isupper() --------" << endl;
  cout << std::boolalpha << " std::isupper('a') = " << std::isupper('a') << std::endl; 
  cout << std::boolalpha << " std::isupper('A') = " << std::isupper('A') << std::endl; 

  char thought[] = " The C++ Language is one of the most used Languages on the plane";
  int upper_count{0};
  int lower_count{0};
  for(auto u: thought){
    if(std::isupper(u))
      upper_count++;
    if(std::islower(u))
      lower_count++;
  }
  cout << "\n statement = " << thought << std::endl;
  cout << " Found " << upper_count << " upper case characters and "<< lower_count << " lower case characters in statement." << endl;
  cout << "\n ------- isdigit() --------" << endl;
  cout << std::boolalpha << " std::isdigit('0') = " << std::isdigit('0') << std::endl; 
  cout << std::boolalpha << " std::isdigit('A') = " << std::isdigit('A') << std::endl; 

  int digit_count{0};
  char statement[] {"Mr Ramanath has 223 cows. That a lot of cows! Exclaimed the kid. "};
  for(auto c: statement) {
    if(std::isdigit(c))
      digit_count++;
  }
  cout << "\n statement: " << statement << endl;
  cout << " The statemnt has " << digit_count << " no of digits. " << endl;

  cout << "\n ------- toupper() --------" << endl;
  cout << std::boolalpha << " std::toupper('a') = " << std::toupper('a') << std::endl; 
  cout << std::boolalpha << " std::toupper('A') = " << std::toupper('A') << std::endl; 

  char predicate[] {"Sun rises in the East."}; 
  char up_predicate[std::size(predicate)];
  char lo_predicate[std::size(predicate)];
  for(size_t i{}; i< std::size(predicate); i++ ){
    up_predicate[i] = std::toupper(predicate[i]);
    lo_predicate[i] = std::tolower(predicate[i]);
  }
  cout << "\n predicate = " << predicate << endl;
  cout << " up_predicate = " << up_predicate << endl;
  cout << " lo_predicate = " << lo_predicate << endl;
  */

  /*
  // C-String manipulation

  // strlen()
  std::cout << "\n----- strlen()-----\n"  << endl; 
  char message [] {"Earth is round in shape."};
  const char* p_message {"Earth is round in shape."}; // Array decays into pointer when we use char*.

  // char* p2 {"Hello, world!"};         // This will throw a warning stating that converting string constant to char* is forbidden. 

  std::cout << " message   = " << message << endl;
  std::cout << " p_message = " << p_message << endl;
  std::cout << "\n The no of characters in 'message' is   = " << strlen(message) << endl;
  std::cout << " The no of characters in 'p_message' is = " << strlen(p_message) << endl;

  std::cout << "\n The size of 'message' is   = " << sizeof(message) << endl;  // Returns size of 'message' in terms of bytes.
  std::cout << " The size of 'p_message' is = " << sizeof(p_message) << endl; // Returns size of char* pointer.

  // strcmp() - int strcmp(const char* a, const char* b)
  // Returns negative number if lhs appears before rhs lexicographically, '0' if both are equal and positive number if lhs appears lexicographically after rhs.
  std::cout << "\n----- strcmp()-----\n"  << endl; 
  const char* str1{"albama"};
  const char* str2{"blbama"};
  std::cout << " strcmp(" << str1 << " , " << str2 << ") = " << strcmp(str1, str2) << endl;

  str1 = "albama";
  str2 = "Albama";
  std::cout << " strcmp(" << str1 << " , " << str2 << ") = " << strcmp(str1, str2) << endl;

  str1 = "Albama";
  str2 = "Albama";
  std::cout << " strcmp(" << str1 << " , " << str2 << ") = " << strcmp(str1, str2) << endl;

  str1 = "Albcma";
  str2 = "Albama";
  std::cout << " strcmp(" << str1 << " , " << str2 << ") = " << strcmp(str1, str2) << endl;

  // strncmp() - int strcmp(const char* a, const char* b, std::size_t count)
  // Same as strcmp() function, however compares only first 'n' number of characters as specified by 'count'.

  std::cout << "\n----- strcmp()-----\n"  << endl; 
  str1 = "albama";
  str2 = "blbama";
  std::cout << " strncmp(" << str1 << " , " << str2 << ", 3) = " << strncmp(str1, str2, 3) << endl;

  str1 = "albama";
  str2 = "Albama";
  std::cout << " strncmp(" << str1 << " , " << str2 << ", 8) = " << strncmp(str1, str2, 8) << endl;

  // strchr() - Returns a pointer to the first occurrence of the character
  std::cout << "\n----- strchr()-----\n"  << endl; 
  const char* str3 {"To be or not To be, That is The question."};
  char target = 'T';
  unsigned int iterations{0};
  unsigned int count{0};

  const char* result = str3;

  std::cout << " str3   = " << str3 << endl;
  while( (result = strchr(result, target)) != nullptr){
    std::cout << " Found target : "<< target << ", starting at - " << result << endl;
    result++;
    count++;
    iterations++;
  }
  std::cout << "\n Took " << iterations << " iterations to find all the targets - "<< target << ", in the string. " << endl;

	//strrchr() - Return pointer to last occurrence of input character.
  std::cout << "\n----- strrchr() -----\n"  << endl; 
  const char* str4 {"/home/user/Jack/Downloads/Resume.pdf"};
  char* res;

  res = strrchr(str4, '/');
  std::cout << " The latest downloaded item is : " << ++res << endl;

  // Declaring a constant C-string using pointer
  std::cout << "\n----- Declaring a constant C-string using pointer -----\n"  << endl; 
  const char* const s = "This is an example of a constant C-string.";
  std::cout << " This is a constant string declared using a pointer :- " << s << endl;
  //s[0] = 't';  // This operation is not allowed as this is a constant string
  */

  /*
  // C-string concatenation and copying

  // std::strcat()
  std::cout << "\n----- std::strcat() -----\n"  << endl; 
  char dest[50] {"Hello, "};
  char src[50] {"World!"};
  std::strcat(dest, src);
  std::cout << " The destination string after concatenation = " << dest << endl;

  std::cout << "\n----- More std::strcat() -----\n"  << endl; 
  char* dest1 = new char[30]{'F', 'i', 'r', 'e', 'l', 'o', 'r', 'd', '\0'};
  char* src1 = new char[30]{',', ' ', 'T', 'h', 'e', ' ', 'P', 'h', 'e', 'n', 'i', 'x', ' ', 'K', 'i', 'n', 'g', '!', '\0'};
  std::cout << "strlen(dest1) = " << strlen(dest1) << endl;
  std::cout << "dest1 = " << dest1 << endl;
  std::cout << "\nstrlen(src1) = " << strlen(src1) << endl;
  std::cout << "src1 = " << src1 << endl;
  std::cout << "\nConcatenating .... " << endl;
  std::strcat(dest1, src1);

  std::cout << "dest1 = " << dest1 << endl;
  std::cout << "strlen(dest1) = " << strlen(dest1) << endl;

  // std::strncat(dest, src, n) :- Concatenates first n characters from src to the first n characters of dest modifying the destination 
  // and finally creates a copy of resultant destination string and returns its pointer.
  std::cout << "\n----- std::strncat() -----\n"  << endl; 
  char destination[60]{"Hi there, "};
  char source[40] {" will you please give me a Pen? "};
  size_t n = 10;

  const char* result;
  std::cout << " destination  = " << destination << endl;
  std::cout << " source       = " << source << endl;
  result = std::strncat(destination, source, n);
  std::cout << " std::strncat(destination, source, " <<  n <<") = " << result << endl;
  std::cout << "\n &result[0] = " << &result << ",   &destination[0] = " << &destination << endl;

  std::cout << "\n destination  = " << destination << endl;
  std::cout << " source       = " << source << endl;
  std::cout << " std::strncat(destination, source, 15) = " <<  std::strncat(destination, source, 15) << endl;

  // std::strcpy
  // char* strcpy (char* dest, const char* source) - Copies string from 'source' to 'dest' and also returns as a result.

  std::cout << "\n----- std::strcpy() -----\n"  << endl; 
  const char* src4 {"God is Great"};
  char* dest4 = new char[strlen(src4) + 1];       // +1 for null terminator. Contains garbage values as we have not initialized the string.
  std::cout << "\n Before Copying ------" << endl;
  std::cout << " src4    = " << src4 << std::endl;
  std::cout << " dest4   = " << dest4 << std::endl;

  char* result4 = std::strcpy (dest4, src4);

  std::cout << "\n After Copying ------" << endl;
  std::cout << " src4    = " << src4 << std::endl;
  std::cout << " dest4   = " << dest4 << std::endl;
  std::cout << " result4 = " << result4 << std::endl;


  // std::strncpy
  // char* strncpy (char* dest, const char* src, size_t count) - Copies first 'count' number of characters from from 'src' to 'dest' string and also 
  // returns a char* pointer to the copy of a result string.

  std::cout << "\n----- std::strncpy() -----\n"  << endl; 
  const char* src5 {"God is Great"};
  char dest5[] = {' ', 'a', 'n', 'd', ' ', 'm', 'e', 'r', 'c', 'i', 'f', 'u', 'l', '\0'};       // +1 for null terminator. Contains garbage values as we have not initialized the string.
  std::cout << "\n Before Copying ------" << endl;
  std::cout << " src5    = " << src5 << std::endl;
  std::cout << " dest5   = " << dest5 << std::endl;

  char* result5 = std::strncpy (dest5, src5, 5);

  std::cout << "\n After Copying ------" << endl;
  std::cout << " src5    = " << src5 << std::endl;
  std::cout << " dest5   = " << dest5 << std::endl;
  std::cout << " std::strncpy(dest5, src5, 5) = " << result5 << std::endl;
  */

  /*
  // Introducing std::string 
  std::string full_name;                   											// Empty string
  std::string planet {"Earth! The planet where sky is blue."}; 	// Initialize with string literal.
  std::string quote ("Humanity is best religion."); 	          // Another way of initializing the string literal.
	std::string preferred_planet {planet}; 												// Initialize with other existing string.
	std::string message{"Hello, world!", 8}; 											// Initialize with part of string literal. Contains 'Hello, w', Copies 8 characters.
	std::string weird_message (3, 'e'); 													// Initialize with multiple copies of char. Here, 'eeee'
	std::string greeting {"Welcome, Home!"}; 
	std::string say_welcome {greeting, 0, 7};                     // Initialize with part of existing string, starting at index 0 and taking 7 characters.

  cout << " full_name         : " << full_name << endl;
  cout << " planet            : " << planet << endl;
  cout << " quote             : " << quote << endl;
  cout << " preferred_planet  : " << preferred_planet << endl;
  cout << " message           : " << message << endl;
  cout << " weird_message     : " << weird_message << endl;
  cout << " say_welcome       : " << say_welcome << endl;

  // Changing the string at runtime. You can store strings bigger than the string used while initializing.
  cout << "\n ----- Modifying C-string at runtime -----" << endl;
	greeting = "Welcome, Home! Please enjoy your stay here. If you need any help do not forget to call on the number mentioned there."; 
  cout << " greeting          : " << greeting << endl;

  // Changing the string pointed by a character pointer, will create memory leaks.
  cout << "\n ----- Modifying std::string at runtime -----" << endl;
  const char* str {"Sky is very cloudy. Today might rain heavily."};
  str = "whoa! It started raining.";                                 //  The old string literal is still consuming memory but is not accessible - Memory leak
	cout << " str   : " << str << endl;					

  std::string s_str = "Weather is sunny today.";
  s_str = "I am feeling very happy.";             // This will not create memory leak
  cout << " s_str : " << s_str << endl;
  */



  return 0;
}
