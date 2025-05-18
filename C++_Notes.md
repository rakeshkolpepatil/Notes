
#	C++ Programming Course - Beginner to Advanced 

[Video](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=2254s)

## 1 Setting up different C++ compilers in VScode.
- There are multiple compilers for C/C++ such as gcc/g++, clang/clang++, MSVC, Apple Clang, NVIDIA HPC C++, Intel C++ etc.

- You can visit this website - 'https://en.cppreference.com/w/cpp/compiler_support' to get details about which compiler supports which features of the C++ language.

- In this course we will be mainly using 'GCC' compiler.

- Download and install the C++ compilers from here - https://winlibs.com/. This will install gcc, g++, clang, clang++ compilers

- To install microsoft's `gcc/g++` compiler, known as `'MSVC compiler'` follow these steps  
  1. Install `community edition of visual studio editor`, MSVC compiler will get installed automatically.  
  2. Open `'Developer PowerShell for VS 2020'` or `'Developer Command prompt for VS 2020'` which has all the variables set for using microsoft compiler.  
  3. Execute `'cl.exe'` command which will give you version of microsoft compiler

- Thus we have installed all the 3 compilers for C++ language viz Mingw, Msvc and Clang llvm.

- Setting the compiler inside vscode editor to compile C++ programs.  
    1. Click `Terminal` Tab (from Top Ribbon) -> `Configure Tasks` -> select the `C++ compiler` of your choice.  
    2. `.vscode` folder will get created with `tasks.json` file inside.  
    3. In `task.json` file, inside `'args'` add `'-std=c++20'` this argument.  
    
- Compiling the given `.cpp` program 
  1. Select `'main.cpp'` file and go to `'Terminal'` from file menu, select option `'Run Task'`, select the compiler. 
  2. This will create 'main.exe' file. 

- In `'tasks.json'` file, modify `'args'` to following, so that it will compile all the `.cpp` files in workspace directory.
  ```Json
  'tasks' : [
    {
      "args": [
        "-g",
        "-std=c++20",
        "${workspaceFolder}\\*.cpp",
        "-o",
        "${fileDirname}\\output.exe"
      ]
    }
  ]
  ```

- Compiling the program using `microsoft compiler`
  1. Open the project directory inside `'Developer Powershell for VS 2020'` and open the directory in vscode using command `'code .'`
  2. Now, you can see that `'cl.exe'` command is available in the terminal.
  3. Now, follow the same steps as used while compiling using `g++` or `clang++ compiler`.
  4. Change the MSVC configuration from `tasks.json` to match below -
    ```json
        {
          "type": "cppbuild",
          "label": "Build with MSVC",
          "command": "cl.exe",
          "args": [
                "/Zi",
                "/std:c++latest",
                "/EHsc",
                "/Fe:",
                "${fileDirname}\\output.exe",
                "${workspaceFolder}\\*.cpp"
          ],
          "options":{
            "cwd":"${fileDirname}"
          },
          "problemMatcher":[
            "$msCompile"
          ],
          "group":"build",
          "detail": "compiler: cl.exe"
        }
    ```

- If the files to be compiled with `'MSVC'` compiler are in dropbox or any auto-syncing software, please pause syncing to avoid errors while compiling the files.

- Program to check whether `C++-20` is supported by the compiler or not. It should print '0'

  ```cpp
  int main(){
    auto result = (10 <=> 20) > 0;    // This syntax is used to check whether C++-20 is supported or not.
    std::cout << result << std::endl;
  }
  ```

- Setting up VScode configuration for C++ - 
  1. Go to command pallet - `C/C++: Edit Configurations (UI)` 
  2. Here you can configure `compiler path`, `compiler arguments`, `C/C++ standard` etc
  3. Video - https://www.youtube.com/watch?v=8jLOx1hD3_o&t=2254s Timestamp - 53.00 Minutes 

- Setting up compiler on Linux  
  1.  sudo apt-get install gcc-12  
      sudo apt-get install g++-12  
      sudo apt-get install gdb  
      sudo apt-get install clang-18  
      sudo apt-get install clang++-18  

  2.  In this course, in Linux, we are going to install only g++ and clang++ compilers.
  3. 	All these softwares are installed inside /usr/bin directory
  4.  If you want to install multiple versions of the gcc on linux you can use 'homebrew' package manager.
  5. 	Download ".deb" package from the VScode website and install.

- All this information can be found in details section of C/C++ extension page.
-	The project that currently we set, we will use this to create new projects so that we need not set the compilers 
  in each project again and again.

- There are few websites where you can compile your C/C++ programs online 
  1. `Wandbox` - You can choose compiler versions, C++ versions and share the code  
  2. `Coliru`   
  3. `Compiler Explorer`    


##	Chapter 2: Diving in (1:43:01)
- `#include <iostream>` - This is the library that makes std::cout and std::cin functions available in C++ programs.
- `#include` statements do not need `';'` at the end.
- Statements in the `main` function are run from top to bottom and the program exits when `'}'` of main function is executed.

  ```cpp
  // This is single line comment in C++
  /*
    This is 
    multiline comment
  */
  ```
- `Multiline`/`Block` comments can not be nested

###	Errors 
#### 1. Compilation Errors
- Compilation will fail. 
- Compiler will point out syntax errors.
    
    ```TEXT
    e.g. - 'missing semicolon ';' error'
    ```

#### 2. Runtime Error
- Program will crash at runtime

#### 3. Warnings 
- Program compiles successfully, but compiler gives warnings regarding possible chances of program failure at runtime.

###	Statements and functions 
- A statement is a **basic unit of computation** in a C++ program
- Every **C++ program is a collection of statements** organized in a certain way to achieve some goal.

- Statements end with `;`
- Statements are executed from top to bottom when program is run.
- Execution continues until there is a statement that causes the program to terminate, or run another sequence of statements.
- `'Function'` is like a machine which takes some input (arguments) and gives an output.

  ```C++
  returnType FunctionName (arguments)
  {
    statements
    return variable
  }
  ```
- Function needs to be defined before it is used/called.
- You can define a number and initialize it as follows:

  ```cpp
    int i = 10;
    int i {10};
  ```

###	Input and Output
- In the following statement, the data `"Hi Rakesh"` is sent from the program to the standard output stream (`std::cout`), which typically displays text on the console.
  
  ```cpp
  std::cout << "Hi Rakesh"; 
  ```
### Common I/O Streams in C++
- C++ provides different I/O stream objects for different types of console input and output:
  
  ```cpp
  std::cout  // Standard output (for general messages), printing to console
  std::cin   // Standard input (for reading user input), reading from console
  std::cerr  // Standard error (for displaying error messages), 
  std::clog  // Standard log (for diagnostic/logging messages)
  ```
- Using separate output streams **allows programs and developers to distinguish between normal output, error messages, and logs**. 

- For example, in a terminal or logging system, errors (`std::cerr`) can be redirected separately from standard output (`std::cout`).	
- There are these many ways of printing because different programs format these output streams differently.
- These are the different ways of conveying the messages and intent behind them to the user.

### Chaining `std::cin` and `std::cout`  
- You can chain multiple inputs and outputs in a single statement

- Note: Chaining works left to right. Each input operator (>>) reads one token (space-separated word) at a time.

    ```cpp
    int age;
    std::string name:
    cin >> name >> age;
    cout << "Hello, " << name << "! You care " << age << " years old." << endl;
    ```

- When reading input with `std::cin`, spaces act as delimiters. So `std::cin >> name` will only read up to the first space.
- To capture full lines (including spaces), use `std::getline`
  
  ```cpp
  std::cout << "\n Please enter your full name "<< std::endl;
  std::getline(std::cin, name);
  ```

- If `std::getline` is used immediately after `std::cin >>`, use `std::cin.ignore()` before `std::getline()` to consume the leftover newline

  ```cpp
  std::cin.ignore(); 						// consume leftover newline
  std::getline(std::cin, fullName);
  ```

- You can span `cout` or `cin` statements over multiple lines for clarity like below

  ```cpp
  cout << "Hello, " << name << "! You care " 
       << age << " years old." 
       << endl;
  ```

- Line breaks in code **don’t affect** how the output is displayed; only the presence of `\n` or `std::endl` does.

###	C++ Program Execution Model and Memory Model
- The C++ program is compiled into binary file which is loaded into RAM and executed by CPU by reading from RAM.

## C++ core language Vs Standard library Vs STL
- **C++ core language features define** how **variables**, **statements** or **functions** should be defined.

- **STL** is a part of the **C++ standard library** but it is a collection of container types. 
- It contains set of types which allows us to store collections, algorithms that work on these collections, and have specialized types called iterators.
- STL is specialized part of standard C++ library.

### 1. C++ Core Language
- Defines the syntax and semantics of the C++ language (e.g., how to declare **variables**, **write functions**, **control flow statements** like `if`, `while`, `for`, etc.).
- Covers fundamental types (`int`, `char`, `bool`, etc.), `pointers`, `references`, `functions`, `templates`, and `basic memory management`.

### 2. Standard Library
- A collection of **ready-to-use classes** and **functions** built on top of the core language.

- Includes
  1. I/O libraries (`iostream`, `fstream`, etc.)
  
  2. String and character manipulation (`<string>`, `<cstring>`)
  3. Math utilities (`<cmath>`)
  4. Time functions, and more.

### 3. STL (Standard Template Library)
- A major subset of the C++ standard library.
- Composed of 
  
  1. **Containers** -  
    `vector`, `list`, `deque`, `set`, `map`, etc.
  
  2. **Algorithms** -  
    `sort()`, `find()`, `accumulate()`, etc.
  
  3. **Iterators** -  
    Bridge between algorithms and containers.
  
  4. STL allows generic programming through templates.

### Fundamental Data Types in C++
  
-  Use `auto` keyword, when type inference makes code clearer, especially with iterators or complex types.

-
  |Type     |	Description                               |
  |-------- |	------------------------------------------|
  |`int`    |	Integer (whole numbers)                   |
  |`float`  |	Floating-point number (single-precision)  |
  |`double` |	Double-precision floating-point number    |
  |`char`   |	Character data                            |
  |`bool`   |	Boolean values (true / false)             |
  |`void`   |	No value / used in function return        |
  |`auto`   |	Automatically deduce type (C++11+)        |


## Number system in C++
  ```cpp
  int num = 15;                     // Decimals
  int num2 = 014;                   // Octal (prefix 0)
  int num3 = 0x23;                  // Hexadecimal (prefix 0x)
  int num4 = 0b000010101;           // Binary (prefix 0b) C++14 or later 
  cout<< "num = "<< num << endl;
  cout<< "num2 = " << num2 << endl;
  cout<< "num3 = " << num3 << endl;
  cout<< "num4 = " << num4 << endl;
  ```
- In computer, all the data is represented by a bunch of grouped cells `0's` and `1's` in memory.

- As the range of your data grows so does the number of digits you need to represent the data in the memory.
- `Hexadecimal system` makes it easier for humans to handle streams of data with `0's` and `1's`.
- `Hexadecimal` is preferred for compact binary representation (1 hex digit = 4 bits).
- `Octal` was historically used, but it's largely obsolete today. 

## `int` and Integer Initialization

- A **variable** is a **named memory location** used to store a specific type of data.
- **Declaring** a variable means requesting the operating system to allocate memory for that variable of the specified type.
- The `int` type in C++ is used to store **integers** (i.e., whole numbers, both positive and negative, including zero).  

- An `int` variable typically occupies **4 bytes** (32 bits) of memory on most modern systems, but the size can vary depending on the system and compiler.

### Initializing integer Variables - braced initialization (Uniform Initialization - C++11)

- Use **braced initialization** to prevent **narrowing conversions** and **uninitialized variables**.

  ```cpp
  // Variable may contain some random garbage value. Warning

  int elephant_count;           // May contain garbage value
  int lion_count {};            // Initializes the variable to 0
  int dog_count {10};           // Initializes the variable to 10
  int cat_count {15};           // Initializes the variable to 15

  // can use expression as initializer
  int domesticated_animals = {dog_count + cat_count};        // OK

  // won't compile, the expression in the braces uses undeclared variables
  int bad_initialization = {doesnt_exist1 + doesnt_exist2}   // ❌ x and y undeclared – compile-time error

  // 2.9 is of type double, with wider range than int. ERROR or Warning.
  int narrowing_conversation {2.9}                           // ❌ Compiler error/warning (loss of data)
  ```

### Initializing integer Variables - functional variable initialization
- In functional variable initialization we use parenthesis instead of curly braces for initialization.

- `⚠️ No narrowing check here` – **functional** and **assignment initialization allow implicit narrowing.**

  ```cpp
  int apple_count(5)
  int orange_count(10)
  int fruit_count(apple_count + orange_count)
  int bad_initialization_count( doesnt_exist1 + doesnt_exist2 )

  // The float number will be rounded to '2'
  int narrowing_conversation_functional(2.8)
  ```

### Initializing integer Variables - assignment initialization
- **Assignment initialization allow implicit narrowing**.
  
  ```cpp        
  cout << "\n---------- Integer variable initialization ---------" << endl;
  int bike_count = 2;
  int truck_count = 7;
  int vehicle_count = bike_count + truck_count ;

  // The float number will be rounded to '2'
  int narrowing_conversion_assignment = 2.9;     // ✅ Allowed – value becomes 2 (data loss)
  ```

### `sizeof()` function returns the size of the argument in bytes
- `sizeof()` returns the number of bytes occupied by a **type** or **variable**.
- Use it to write portable code, especially in low-level or embedded C++.

  ```cpp 
  std::cout << "Size of int: " << sizeof(int) << " bytes\n";
  std::cout << "Size of double: " << sizeof(double) << " bytes\n";
  ```

### Integer modifiers
- C++ provides type modifiers to control the size and range of integer types. 
- These modifiers are applied only to integral types (like `int`, `short`, `long`), **not to floating-point types**.

- **signed int**   
  ```cpp
  range: -2^(n-1) to (2^(n-1))-1
  ```

- **unsigned int** 
  ```
  range: 0 to (2^n)-1
  ```

- 2 Bytes (Typically 16 bits)
  ```cpp
  short, 
  short int, 
  signed short,
  signed short int,
  unsigned short, 
  unsigned short int,
  ```

- 4 Bytes (Typically 32 bits)
  ```cpp
  int,
  unsigned, 
  unsigned int,
  signed, 
  signed int,
  ```

- 4 or 8 Bytes (Platform dependent)
  ```cpp
  long,
  long int,
  singed long,
  signed long int,
  unsigned long,
  unsigned long int,
  ```

- 8 Bytes (Typically 64 bits)
  ```cpp
  long long,
  long long int,
  signed long long,
  signed long long int,
  unsigned long long,
  unsigned long long int,
  ```

- These type modifiers are applicable only to integral type: those in which you can store integer numbers.
- `From C++14` or newer compilers, `apostrophes` (`'`) can be used to improve the readability of large numeric literals.
  
  ```cpp
  long long int a = 100'000'000'000'000;
  ```

## Fractional Numbers/ Floating Point Numbers
- **Used to represent real numbers (numbers with fractional parts) in C++**

- There are 3 types of fractional numbers

  |Type          | Typical Size |	Precision (total digits in number ) |	Notes               |
  |------------- | ------------ | ----------------------------------- |-------------------  |
  |`float`       | 4 bytes      |	~7 digits                           | Single precision    |
  |`double`      | 8 bytes      |	~15 digits                          | Double precision    |
  |`long double` | 12/16 bytes  |	15+ digits                          | Extended precision  |

### Declaration and Initialization of floating point variables
- 
  ```cpp
  float number1 {1.12345546467467456f};            // 'f' is optional but clarifies it's float
  double number2 {1.423556567754534523};
  long double number3 {1.364545667567456345L};     // 'L' for long double

  std::cout << "sizeof float: " << sizeof(number1) << endl;
  std::cout << "sizeof double: " << sizeof(number2) << endl;
  std::cout << "sizeof long double: " << sizeof(number3) << endl; 

  std::cout << "number1 - " << number1 << endl;
  std::cout << "number2 - " << number2 << endl;
  std::cout << "number3 - " << number3 << endl; 
  ```

### Scientific Notation (Exponential Form) 
- Use `e` or `E` to represent powers of 10. 

- scientific notation - `e8` means `10^8`, `e-11` means `10^-11`
- The `number5`, `number6` and `number7` are roughly the same.
  
  ```cpp
  double number5 {192400023};
  double number6 {1.92400023e8};   // 1.92400023 × 10^8
  double number7 {1.924e8};
  ```

- The **number8** and **number9** are roughly the same.
  
  ```cpp
  double number8 {0.00000000003948};
  double number9 {3.948e-11};
  ```

- **IEEE 754 standard** is followed to **represent the floating point numbers in binary format**.

- Narrowing errors happen **when user tries to assign bigger numbers than those supported by the data type**.
- Precision for `float` should be 7 digits i.e. it can handle at max 7 digits including before and after decimal point.
- `double` can handle 15 digits precision safely 
- `long double` can handle 15+ digits precision safely (varies by compiler)

  ```cpp
  // This will give narrowing conversion error as float can have precision of maximum 7 digits. 
  // Mostly will give compiler error as we are using braced initialization
  float number23 {213345850};        // Error or warning: narrowing conversion (too large)

  // If we use functional initialization, narrowing conversion error will not be caught at compile time
  // and rounding will happen.
  float number25 (143556467);        // May round/truncate, no compile-time warning
  ```

### `std::setprecision()` Vs `std::setfixed`
1. When you use `std::setprecision()` on its own, it sets the total number of significant digits to be displayed for floating-point numbers. This means the precision includes both the digits before and after the decimal point.
  
2. When you combine `std::setprecision()` with `std::fixed`, the `setprecision` value now controls the number of digits after the decimal point, rather than the total number of significant digits.
  
3. `#include <iomanip>` - **Do not forget to add this** library if you want to use **setprecision()** function.

    ```cpp
    #include <iostream>
    #include <iomanip>

    int main() {
      double num = 123.456789;

      // Without std::fixed (using significant digits)
      std::cout << "Without std::fixed:" << std::endl;
      std::cout << std::setprecision(5) << num << std::endl;  							// Significant digits

      // With std::fixed (using digits after the decimal point)
      std::cout << "With std::fixed:" << std::endl;
      std::cout << std::fixed << std::setprecision(5) << num << std::endl;  // Digits after the decimal point

      return 0;
    }
    // Output :
    //         Without std::fixed:
    //         123.46
    //         With std::fixed:
    //         123.45679
    ```	

### `Special Behavior of Floating Point Numbers (vs Integers)`
There are few things that you can do with floating point numbers that can not be done with integers such as

#### 1. Diving by zero -  
- In integer arithmetic, division by zero causes a runtime error or crash.
- In floating-point arithmetic, dividing by zero yields Infinity (positive or negative):
  
  ```cpp
  n(floating point number)/0 = (+/-) Infinity  
  
  // If the n is positive we get '+ve' infinity else if the n is negative we get '-ve' infinity
  double n1 = 5.0;
  double n2 = -5.0;

  std::cout << n1 / 0.0 << std::endl;  // Outputs: inf
  std::cout << n2 / 0.0 << std::endl;  // Outputs: -inf
  ```
-  The result depends on the sign of the numerator.


#### 2. Zero Divided by Zero  
- This operation is undefined in mathematics.
- In C++, when using floating-point types, this yields `NaN` (Not a Number), not a crash:
- A `0` floating point number can be divided by another `0` floating point number. 

  ```cpp
  double zero = 0.0;
  std::cout << zero / zero << std::endl;  // Outputs: nan
  ```

### Type Suffixes for Floating-Point Literals
- If no suffix is used, a floating-point literal is considered a double by default.
- You must use suffixes to specify the intended type explicitly.

  |Suffix  |	Type        |	Example                   |
  |------- |------------- |---------------------------|
  |   f    |	float	      | float num = 3.14f;        |
  | (none) |	double      |	double num = 3.14;        |
  |    L   |	long double	| long double num = 3.14L;  |

- Double data type works very well in many situations, so it is more often used.

  ```cpp
  float num1 {1.123456789010f};
  float num2 {1.1234567890190};     // No suffix is used, so '1.12345678901d234567890' is considered as 'double'     

  double num3 {1.12345678901890};   // No suffix is used so the number is assumed as 'double' and anyways we want it to be double.

  long double num4 {1.12345678901890L};
  long double num5 {1.123456789017890};   // No suffix is used, so '1.12345678901d234567890' is considered as 'double' 
  ```	
- Narrowing warnings/errors occur when using braced initialization with a double literal assigned to a float.

### Float Precision Issues
- `float` provides only about 7 digits of precision.
- This precision is too limited to handle lot of common applications.
- Using values with more digits can result in narrowing conversions or truncated data.
  
  ```cpp
  // This will lead to narrowing conversion problems as the max precision 'float' supports is 7.
  float  num4 {1234567890.12345f}   // May lose precision — only 7 digits preserved
  double num5 {1234567890.12345}    // More accurate — up to ~15 digits preserved
  ```
- Prefer double for most real-number calculations unless memory or speed constraints demand float.

## Booleans: `true` / `false`
- A Boolean is a data type that can hold only two possible values: `true` or `false`.
- In C++, the type is declared as:

  ```cpp
  bool flag = true;
  ```

- A bool typically occupies 1 byte (8 bits) in memory, even though it only needs 1 bit to store its value.
- Though a byte of memory can store 256 different values, storing just two is a waste of resources especially in case of devices with hard memory constraints, such as embedded devices.
- ⚠️ This can lead to memory inefficiency on devices with limited resources (e.g. embedded systems).
- Techniques such as bit-fields and bit manipulation can be used to pack multiple boolean values into a single byte.
- When printing a boolean:

  - By default, true prints as 1 and false as 0:

    ```cpp
    std::cout << true << " " << false << std::endl;  // Output: 1 0
    ```

  - Use std::boolalpha to print true / false as text:

    ```cpp
    std::cout << std::boolalpha;
    std::cout << true << " " << false << std::endl;  // Output: true false
    ```

- Similarly, you can revert to numeric output using std::noboolalpha.


## Characters
- are defined by 'char' keyword
  ```cpp
  char letter = 'A';
  ```

- A single char occupies `1 byte` in memory allowing it to store '256' values in total (0 to 255). 
- This is based on 'ASCII' encoding where each combination of 8 bits in a byte represents a separate character.

### ASCII Basics
- ASCII maps numeric codes to characters (e.g., `65` = `'A'`, `97` = `'a'`, `48` = `'0'`).
- You can assign a numeric value to a `char` and print it
- You can also print the ascii value associated with the character by using 'static_cast' method.
  
  ```cpp
  char a = 65;
  std::cout << "a = " << a << std::endl;                                   // Output: a = A
  std::cout << "ASCII value of a = " << static_cast<int>(a) << std::endl;  // Output: 65
  ```  

### Unicode & UTF-8
- `ASCII` only supports English characters and basic symbols.
- For international characters (e.g., Hindi, Marathi, Japanese), we use `Unicode encodings` like `UTF-8`.
- `UTF-8` is a variable-length encoding system that can store thousands of characters (emojis, scripts, symbols) and is widely used in modern applications.
- ⚠️ To handle non-ASCII characters in C++, you may need:
  - `wchar_t` or `char16_t`, `char32_t` for wide characters.
  - Proper console/font support.
  - String literals like `u8"…"`, `u"…"`, or `U"…"`.
  - `std::wstring`, `std::u16string`, etc.


## `std::string` vs `std::string_view`  
- In C++, both `std::string` and `std::string_view` are used to represent sequences of characters. 
- However, they differ significantly in `ownership`, `mutability`, `performance`, and use cases.

1. `std::string`  
    
    |  Aspect				 |	Description                                                      |
    |--------------------|----------------------------------------------------------------------------------------------------------------------------------|
    |  Definition				 |	A dynamically allocated, mutable string class that manages its own memory.                                                      |
    |  Ownership				 |	`'std::string'` owns the string data it holds. When you create a `'std::string'`, it allocates memory to store the characters.          |
    |  Mutability				 |	`Fully mutable` - You can modify the contents of a `'std::string'` (e.g., append, erase, replace characters).                                               |
    |  Memory Management |	Performs dynamic memory allocation and deallocation. Copies involve deep copying of the string data.                                                              |
    |  Performance			 |	Since it involves dynamic memory allocation, it can be `relatively slower`, especially when copying or passing strings by value.  Use references (`const std::string&`) for performance. |
    |  Use Case					 |	Use `'std::string'` when you need to own and modify the string, or when you need to store a string for a longer duration.         |
    

2. `std::string_view` 
    
    |	Aspect					     | Description.                                        |
    |----------------------| ----------------------------------------------------|
    |	Definition					 | A lightweight, non-owning read-only view of a character sequence — typically over a std::string, C-string, or character array. Introduced in C++17.                                        |
    |	Ownership						 | `'std::string_view'` does not own the string data. It simply points to an existing character sequence, meaning it references memory owned by someone else.  |
    |	Mutability					|	`Immutable` - You cannot modify the contents of a `'std::string_view'`. It is a `read-only` view.                                                                                    |
    |	Memory Management    |  `No Memory Allocation or Deallocation`. `'std::string_view'` does not allocate or manage memory, making it lightweight and efficient for passing around string data without copying.                         |
    |	Performance					 | Much faster than `'std::string'` when passing or using substrings since it avoids memory allocation and copying.                                                     |
    |	Safety							 | You must be cautious when using `'std::string_view'` to ensure the underlying data it references remains valid during the lifetime of the `'string_view'`. If the underlying string is destroyed, the `'string_view'` becomes a dangling reference.                                                                             |
    |	Use Case						 | Use `'std::string_view'` when you need to efficiently pass or access a string without copying, especially for temporary operations, string parsing, or read-only scenarios. |

3. `Key Differences`  

    |	Aspect								| `std::string `                            | `std::string_view`                    |
    |-----------------------|-------------------------------------------|--------------------------------       |
    |	Ownership							| Owns the string data											| Does not own the string data          |
    |	Mutability						| Mutable																		| Immutable                             |
    |	Memory Management			| Manages Allocation and Deallocation 			| No memory allocation                  |
    |	Performance						| Can be slower due to allocation						| Lightweight and efficient             |
    |	Safety								| Safe, self-contained											| Risky if used after source is invalidated, dangling refs  |
    |	Use Case							| When you need to own/modify	strings				| When only viewing or parsing strings  |

    ```cpp
    #include <iostream>
    #include <string>
    #include <string_view>

    int main() {
        std::string str = "Hello, world!";
        // std::string (owns and manages the string)
        std::string str_copy = str;
        str_copy[0] = 'h';  									                          // Can Mutate the string
        std::cout << "Modified copy: " << str_copy << std::endl;        // Output - Modified copy: hello, world!
    
        // std::string_view (non-owning view)
        std::string_view str_view = str;
        std::cout << "View of original: " << str_view << std::endl;     // View of original: Hello, world!

        // Modifying original affects the view
        str[7] = 'B';
        std::cout << "View after modifying original: " << str_view << std::endl;
                                                                        // View after modifying original: Hello, Borld!
        // Danger: If str goes out of scope, view becomes invalid!
        return 0;
    }
    ```

  -	In above example:
      
    `'str_copy'` is a deep copy of the string and can be modified.
    `'str_view'` is a non-owning view of the original `'str'`, and changes to `'str'` would reflect in `'str_view'`, but you cannot modify `'str_view'` itself.

### Important Notes on std::string_view
- Does not perform bounds checking — slicing outside valid range is undefined behavior.
- Be careful not to return or store a `string_view` referencing a local `std::string` (which will go out of scope).
- Use `std::string_view` in APIs where:
  - Performance is critical
  - You want to accept inputs from different sources (`std::string`, `C-string`, etc.)
  - You don't need to modify the string


## `std::string` vs `std::string_view` vs `char*`

### `Comparison Table`

  | Feature / Aspect      | `std::string`                        | `std::string_view`                      | `const char*` (C-style string)            |
  |----------------------|--------------------------------------|-----------------------------------------|-------------------------------------------|
  | **Ownership**         | Owns the string data                 | Does not own                            | Does not own                              |
  | **Mutability**        | Mutable                              | Immutable (read-only view)              | Mutable (but should treat `const char*` as immutable) |
  | **Null-termination**  | Not required                         | Not required                            | Required (`\0` marks end of string)       |
  | **Memory Management** | Handles allocation/deallocation      | No allocation                           | Must be managed manually (prone to leaks) |
  | **Safety**            | Safe and RAII-compliant              | Dangerous if original data goes out of scope | Dangerous if memory is not properly managed |
  | **Performance**       | Slower than `string_view` due to copying | Very fast (no copy)                   | Fast (if managed carefully)               |
  | **Interoperability**  | Can be converted to/from C-strings   | Can view C-strings or `std::string`     | Low-level C functions                     |
  | **Best Use Case**     | When you need ownership or mutation  | When passing substrings or read-only views | Interfacing with C APIs or legacy code   |

### `std::string_view` and `Substrings`
- `std::string_view` makes it **extremely easy to create substrings** without copying memory, unlike `std::string::substr` which allocates a new string.

### ✅ Example: Efficient Substring with `string_view`

```cpp
#include <iostream>
#include <string_view>

int main() {
    std::string_view text = "Hello, World!";
    
    // Create a substring (view of first 5 characters)
    std::string_view hello = text.substr(0, 5);
    
    std::cout << "Substring: " << hello << std::endl; // Output: Hello
}
```
- 🔍 `substr(start, length)` returns a new view, not a new string.
- ✅ No memory is copied or allocated — it just adjusts internal pointers.

### ⚠️ Caution with `string_view` and Lifetimes

```cpp
std::string_view create_view() {
    std::string local = "temporary";
    return std::string_view(local);  // ❌ BAD! local is destroyed at end of function
}
```
- The returned `string_view` becomes a **dangling reference**.
- ✅ Always make sure the source string **outlives** the `string_view`.


### ✅ Safe Interoperability
  ```cpp
  void print_message(std::string_view msg) {
      std::cout << msg << std::endl;
  }

  int main() {
      print_message("Hello from C-string");         // const char*
      print_message(std::string("Hello string"));   // std::string
  }
  ```
- You can **safely accept multiple string types** as parameters with `std::string_view`.


## 'auto' keyword
- The `auto` keyword tells the compiler to automatically deduce the variable’s data type based on the initializer value.
- This improves readability and helps avoid verbose type declarations, especially with complex types.

### Type Deduction Rules:
- If an integer literal is assigned, auto deduces it as int (which is signed by default).
- If a floating-point literal is assigned (e.g., 1.23), it is deduced as double by default.
- Use `suffixes` to influence type deduction:

  |Literal  | Suffix  | Deduced Type        |
  |-------  | ------- | ------------------  |
  | 1.0f    | f       | float               |
  | 10u     | u       | unsigned int        |
  | 100l    | l       | long int            |
  | 100ll   | ll      | long long int       |
  | 100ul   | ul      | unsigned long int   |
  | 100ull  | ull     | unsigned long long  |

- default of integer is 'signed integer'
- default of floating point is 'double'
  ```cpp
  auto x = 42;        // int
  auto y = 3.14;      // double
  auto z = 3.14f;     // float
  auto u = 42u;       // unsigned int
  auto l = 100l;      // long int
  auto ll = 100ll;    // long long int
  ```

## Variable Assignments in C++
- Declaration and Initialization
  ```cpp
  int var {22}        // declaration and initialization of a variable 'var'
  std::cout << "var = "  << var << endl;
  ```

- Re-assignment 
  ```cpp
  var = 44            // Reassign a new value to var
  ```

- Important Note on Type Safety
  ```cpp
  auto var {212u};                // Deduces 'var' as unsigned int

  var = -45;                      // Assigning a negative value to unsigned int
                                  // No compiler error, but behavior is undefined or wraps around

  std::cout << var << std::endl;  // Will show a large value (due to wrap-around)
  ```
- Always use types explicitly or ensure correctness when using `auto`, especially with suffixes that change signedness.

## Basic Operations in C++
- (`+`) Addition, (`-`) Subtraction, (`*`) Multiplication, (`/`) Division, (`%`) Modulus - remainder for integers. 
- (`*`) Mul, (`/`) Div, (`%`) Mod operations have higher precedence than Plus, Minus
- Precedence determines which operation should be performed first.
- Associativity determines evaluation order when operators have the same precedence.
- 🔗 Operator precedence chart:  
👉 cppreference.com - [Operator Precedence]( https://en.cppreference.com/w/cpp/language/operator_precedence)
- Brackets are used to perform low precedence operations before higher precedence operations i.e. to override precedence and improve readability.
  
  ```cpp
  (a+b) / (c-d)
  ```

- Compound Assignment operators - `+=`, `-=`, `*=`, `/=`, `%=` which are equivalent to `val = val + x`
- Relational operators  
  - `<` - Less Than
  - `>` - Greater Than
  - `<=` - Less Than Equal To
  - `>=` - Greater Than Equal To
  - `==` - Equal To
  - `!=` - Not Equal To 

  ```cpp
  cout << "num1 < num2 :" << num1<num2 << endl;     // This will throw error as '<<' will take precedence 
                                                    // over '<' operator.
  cout << "num1 < num2 :" << (num1<num2) << endl;
  ```
- Logical Operators  
  - `&&` - Logical AND    
  - `||` - Logical OR   
  - `!` - Logical NOT  

  ```cpp
  bool result = (x > 10) && (y < 5);    // Logical Operators.  
  ```

## 🖨️ Output Formatting in C++
- In C++, two main headers/libraries are used for output formatting:
  - `#include <ios>`      – for stream format flags
  - `#include <iomanip>`  – for manipulators like setw, setprecision, etc.

### 🔁 Stream Manipulators  
- |     Manipulator                    | Description                                                                |
  |----------------------------------  | ---------------------------------------------------------------------------|
  |`std::endl`                         | Outputs a newline (`\n`) and flushes the output buffer.                    |
  |`std::flush`                        | Forces immediate flush of the output buffer without newline.               |
  |`std::showpos / std::noshowpos`     | Shows or hides the `+` sign for positive numbers.                          |
  |`std::dec, std::hex, std::oct`      | Sets number base (decimal, hexadecimal, octal).                            |
  |`std::showbase / std::noshowbase`   | Shows base prefix like `0x` for hex, `0` for octal.                        |
  |`std::uppercase / std::nouppercase` | Outputs `hex/scientific` exponents in uppercase.                           |
  |`std::boolalpha / std::noboolalpha` | Controls boolean output: `true/false` vs. `1/0`.                           |
  |`std::fixed`                        | Prints `floating-point` numbers in `fixed-point notation`.                 |
  |`std::scientific`                   | Prints `floating-point` numbers in `scientific notation`.                  |
  |`std::showpoint / std::noshowpoint` | Forces decimal point and trailing zeros for floats.                        |
  |`std::cout.unsetf(std::ios::fixed \| std::ios::scientific)`| prints the floating point numbers in default format |

### 🎯 Field Width, Precision, and Justification
- 
  | Manipulator            | Description                                                                              |
  |---------------------   | -----------------------------------------------------------------------------------------|
  | `std::setprecision(n)` | Sets total number of significant digits for floating-point output. Default is 6.         |
  | `std::setw(n)`         | Sets the width of the next field to `n` characters. Affects only the next value to be printed. |
  | `std::setfill(c)`      | Fills empty space in setw() with character `c`.                                          | 
  | `std::left`            | `Left-justifies` output in the field.                                                    |
  | `std::right`           | `Right-justifies` output in the field.                                                   |
  | `std::internal`        | Puts sign to the left and number to the right (for signed numeric fields).               |

  ```cpp
  #include <iostream>
  #include <iomanip>   // for manipulators like setw, setprecision

  int main() {
      int num = 255;
      double pi = 3.14159;
      bool flag = true;

      std::cout << "=== Base Representations ===" << std::endl;
      std::cout << std::showbase << std::uppercase;

      std::cout << "Decimal   : " << std::dec << num << std::endl;
      std::cout << "Hex       : " << std::hex << num << std::endl;
      std::cout << "Octal     : " << std::oct << num << std::endl;

      std::cout << std::nouppercase << std::noshowbase;  // Reset uppercase and showbase

      std::cout << "\n=== Boolean Output ===" << std::endl;
      std::cout << std::boolalpha << "boolalpha: " << flag << std::endl;
      std::cout << std::noboolalpha << "noboolalpha: " << flag << std::endl;

      std::cout << "\n=== Floating-point Format ===" << std::endl;
      std::cout << std::fixed << "Fixed: " << std::setprecision(4) << pi << std::endl;
      std::cout << std::scientific << "Scientific: " << pi << std::endl;
      std::cout.unsetf(std::ios::fixed | std::ios::scientific);
      std::cout << "Default: " << pi << std::endl;

      std::cout << std::showpoint;
      double shortPi = 3.1;
      std::cout << "With showpoint (3.1): " << shortPi << std::endl;

      std::cout << std::noshowpoint;

      std::cout << "\n=== Sign Display ===" << std::endl;
      std::cout << std::showpos;
      std::cout << "+Positive: " << 42 << ", -Negative: " << -42 << std::endl;
      std::cout << std::noshowpos;

      std::cout << "\n=== Justification and Field Width ===" << std::endl;
      std::cout << std::setw(10) << std::setfill('.') << std::left << "Left" << std::endl;
      std::cout << std::setw(10) << std::setfill('-') << std::right << "Right" << std::endl;
      std::cout << std::setw(10) << std::setfill('*') << std::internal << -123 << std::endl;

      std::cout << "\n=== Flushing and Newline ===" << std::endl;
      std::cout << "This will be flushed now." << std::flush;
      std::cout << "\nThis will be printed after endl." << std::endl;

      return 0;
  }
  ```
  ```mathematica
  --------------------- Output ----------------------------

  === Base Representations ===
  Decimal   : 255
  Hex       : 0XFF
  Octal     : 0377
  
  === Boolean Output ===
  boolalpha: true
  noboolalpha: 1
  
  === Floating-point Format ===
  Fixed: 3.1416
  Scientific: 3.1416E+00
  Default: 3.14159
  With showpoint (3.1): 3.10000
  
  === Sign Display ===
  +Positive: +42, -Negative: -42
  
  === Justification and Field Width ===
  Left...... 
  -----Right
  *-123*****
  
  === Flushing and Newline ===
  This will be flushed now.
  This will be printed after endl.
  ```

## `#include <limits>`
- This library is used to get range of any given datatype.
- The `<limits>` header provides a standardized way to access properties (such as min, max, etc.) of fundamental data types.
- Key Members of `std::numeric_limits<T>`

  ```cpp
  #include <iostream>
  #include <limits>

  int main() {
      std::cout << "int min     : " << std::numeric_limits<int>::min() << "\n";      // For int: Most negative number
      std::cout << "int max     : " << std::numeric_limits<int>::max() << "\n";      // For int: Largest number
      std::cout << "int lowest  : " << std::numeric_limits<int>::lowest() << "\n";   // Same as min() for int

      std::cout << "float min   : " << std::numeric_limits<float>::min() << "\n";    // Smallest positive value (not most negative!)
      std::cout << "float lowest: " << std::numeric_limits<float>::lowest() << "\n"; // Most negative finite value
      std::cout << "float max   : " << std::numeric_limits<float>::max() << "\n";    // Maximum finite value

      std::cout << std::boolalpha;
      std::cout << "Is long int an integer? " << std::numeric_limits<long int>::is_integer << "\n";
  }
  ```

Notes:
- `min()`
  - For integral types: minimum (most negative for signed types)
  - For floating-point types: smallest positive normalized value

- `lowest()`
  - For integral types: same as `min()`
  - For floating-point types: most negative finite value

- `max()`: Largest finite representable value
- `is_integer`: Returns `true` if the type is an integer type, `false` otherwise

## `<cmath>` library
- The <cmath> library provides mathematical functions. Here's a reference for commonly used ones:

  ```cpp
  #include <cmath>
  #include <iostream>

  int main() {
      std::cout << "floor(8.6)    = " << std::floor(8.6) << "\n";
      std::cout << "ceil(8.1)     = " << std::ceil(8.1) << "\n";
      std::cout << "abs(-8.6)     = " << std::abs(-8.6) << "\n";
      std::cout << "exp(2)        = " << std::exp(2) << "  // e^2\n";
      std::cout << "pow(3, 4)     = " << std::pow(3, 4) << "\n";
      std::cout << "log(34)       = " << std::log(34) << "  // natural log\n";
      std::cout << "log10(1000)   = " << std::log10(1000) << "\n";
      std::cout << "round(34.754) = " << std::round(34.754) << "\n";
      std::cout << "round(2.4)    = " << std::round(2.4) << "\n";
      std::cout << "sqrt(49)      = " << std::sqrt(49) << "\n";
  }
  ```
- Common Functions Summary  

  | Function | Description                  |
  | ---------| -----------------------------|
  | floor(x) | Largest integer ≤ x          |
  | ceil(x)  | Smallest integer ≥ x         |
  | abs(x)   | Absolute value               |
  | exp(x)   | e^x                          |
  | pow(x,y) | x^y                          |
  | log(x)   | Natural logarithm (base e)   |
  | log10(x) | Base 10 logarithm            |
  | round(x) | Rounds to nearest integer    |
  | sqrt(x)  | Square root                  |
  
  ```cpp
  floor(8.6)     = 8
  ceil(8.1)      = 9
  abs(-8.6)      = 8.6
  exp(5)         ≈ 148.413 (i.e., e^5)
  pow(3,6)       = 729
  log(34)        ≈ 3.526 (natural logarithm, base e)
  log10(23)      ≈ 1.361 (base 10 logarithm)
  round(34.754)  = 35
  round(2.4)     = 2
  sqrt(49)       = 7
  ```
    
## Weird Integral types
- Integral types of size less than 4 bytes do not support arithmetic operations. 
- Compiler smartly converts them into int data types which is of 4 bytes.  
- `char` and `short int` do not support arithmetic operations.
- Similarly, integral types of size less than 4 bytes also do not support bitwise operations and same behavior can also be observed in case of other operations.

### Promotion of Small Integral Types
- In C++, arithmetic and bitwise operations on small integral types like `char` and `short` promote them to `int` before the operation.

  ```cpp
  char c1 = 100;
  char c2 = 30;
  auto result = c1 + c2; // Promoted to int

  short s1 = 2000;
  short s2 = 3000;
  auto sum = s1 + s2;     // Also promoted to int

  std::cout << "Type of result: " << typeid(result).name() << "\n"; // usually "i" = int
  ```
- Why This Matters ?  
  - You can perform `arithmetic` and `bitwise` operations on `char` and `short`, but behind the scenes, the compiler promotes them to `int`.
  - This is known as `"integral promotion"` and helps avoid `overflows` in tiny types like char.

## Conditional Statements
    
### Switch statement
  1. The break statement after each case is crucial. It prevents fallthrough—where execution continues into subsequent cases even after a match.

  2. Only Integral types: `int`, `char`, `short int`, `long int` etc. and enums are allowed as a condition in case statements. 
  
  3. The `case` labels must be `constant expressions`, which means they can be `literals` or `const/constexpr variables`.

  ```cpp
  switch (value) {
  case 1:
    std::cout << "One\n";
    break;
  case 2:
    std::cout << "Two\n";
    break;
  default:
    std::cout << "Other\n";
  }
  ```
### Ternary Operator  
- A compact if-else expression that returns either option1 or option2 depending on the boolean result of condition.
- Both options should be of the same or compatible types.
  
  ```cpp
  result = (condition)? TrueOption1: FalseOption
  ```

### Loops
- All the loops have following components:
  1. Iterator/Counter Variable
  2. Starting value
  3. Test condition
  4. Update Expression (Increment/Decrement)
  5. Loop Body
      
    ```cpp
    for (int i{}; i < 10; i++){
      cout << "I Love C++ " << endl;
    }
    
    for (int i{}; i < 10; ++i){
      cout << "I Love C++ " << endl;
    }
    
    for (size_t i{}; i < 10; ++i){
      cout << "I Love C++ " << endl;
    }
    ```   
- Use `++i` instead of `i++` for slightly better performance with non-primitive types.

### `'size_t'` 
- `size_t` is not a type in C++.
- It is just an alias for `'unsigned int'` or `'unsigned long'`. 
- It is generally used inside loop iterators, specifying sizes of the things etc. especially all the things that can not have negative values.
      
### scope of iterator / Loop Variable 

  ```cpp
  int main(int argc, char** argv) {
    for (size_t i = 0; i < 10; i++) {
      // i is valid to use within the boundaries of {} here.
      cout << "i is usable here, the value is " << i << endl;
    }
    // If you try to access 'i' here you will get an error. 'i' does not exist in functional scope of 'main' function.
    return 0;
  }

  size_t j{};
  for (; j < 10; j++) {
    cout << " j =" << j << endl; 
  }
  cout << " The loop is done. The value of j = " << j << endl;
  ```

- It is advised to not to use hard-coded values in loop conditions.
- Using named constants improves readability and maintainability.

  ```cpp
  size_t COUNT {10};
  for (int i{}; i < COUNT; i++){
    cout << "I Love C++ " << endl;
  }
  ```

### while loop
  ```cpp
  const unsigned int COUNTER {10};
  size_t iter {};
  while(iter < COUNT){
    cout << "iter : " << iter << endl;
    ++iter;
  }
  ```

### do while loop
- It will execute the loop body at least once.
  
  ```cpp
  const int COUNT {10};
  size_t i {0};
  do {
    cout << i <<" : " << " I Love C++ "<< endl;
    i++;
  }
  while(i < COUNT);
  ```

## 3. Arrays
- Arrays are contiguous collections of elements of the same data type.
- Array elements are accessed using zero-based indexing.
  
  ```cpp
  int arr[10];                                          // Declare an array of size 10 (elements uninitialized)

  //Declare and initialize an array. Array size is automatically deduced by compiler.
  double salaries[] {12.6, 143.4, 145.44, 67.0, 134}    
  
  int arr[6] {2, 4, 7}                               // remaining elements are initialized to zero.
  
  const double heights [] {12, 16, 23, 34, 56};      // Read only arrays.
  
  std::size(arr)                                     // Returns the number of elements in array. (C++17)
  sizeof(arr)/sizeof(arr[0])                         // Returns the number of elements. Works in all versions.
  ```  

- Range based for loop
  ```cpp
  double ages [] {12, 16, 23, 34, 56};
  for(auto age: ages) {
    cout << " age : "  << age << endl;
  }        
  ```

### What is difference between `char s[]` and `char *s` in C ?

  |Syntax              | Meaning                                                                                        |
  |--------------------| -----------------------------------------------------------------------------------------------|
  |char s[] = "hello"; | Array of characters terminated by `'\0'`. Stored in stack. `sizeof(s) == 6` (5 chars + '\0')   |
  |char* s = "hello";  | Pointer to string literal. Stored in read-only memory. `sizeof(s) == 8` on 64-bit and `4 on 32-bit` (pointer size) |

- arr[0] and 0[arr] are same as both get translated to *(arr +0)

### Arrays of characters
- Character arrays are not always printable as strings unless terminated with '\0'. 
  ```cpp
  char message[5] {'H', 'E', 'L', 'L', 'O'};
  cout << "\nmessage : ";
  for (auto c: message) {
    cout << c; 
  }
  cout << " size : " << std::size(message);
  ```
- Strings are nothing but the character arrays that end with null characters i.e. `'\0'`

- Following may print garbage after `'O'` as no null-terminator.  
  ```cpp
  char message_str2 [] {'H', 'E', 'L', 'L', 'O' };
  cout << "message_str2 : " << message_str2 << endl;
  ```

- compiler will automatically fill remaining elements with `'\0'` in character array
  ```cpp
  char message_str1 [8] {'H', 'E', 'L', 'L', 'O' };
  cout << "message_str1 : " << message_str1 << endl;
  ```

- Will print proper string as we added `'\0'` at the end explicitly.
  ```cpp
  char message_str [] {'H', 'E', 'L', 'L', 'O', '\0'};
  cout << "message_str : " << message_str << endl;
  ```

### 🧵 Literal C-Style Strings
- ✅ String literals automatically include the `'\0'`.
  ```cpp
  char message4[] {"Hello"};
  cout << "message4 : " << message4 << endl;
  cout << "size : " << std::size(message4) << endl;

  // spaces are allowed in literal strings
  char message5[] {"Hello, world!"};
  cout << "message5 : " << message5 << endl;
  cout << "size : "<< std::size(message5);
  ```

### ⚠️ Printing Arrays
- Only character arrays with `'\0'` can be printed directly, integer arrays will give compile time error.
  
  ```cpp
  int numbers[] {1, 2, 3, 4, 5, 6, 7, 8};
  std::cout << "numbers - " << numbers << std::endl;
  // ❌ Will print memory address, not contents.
  ```
- Use a loop to print elements of non-character arrays.
      
### 🚧 Array Bounds and Memory Safety
- If you want to modify the data out of the bounds of an array, program might get crashed, as the memory that you are trying to access might be of another program or of operating system etc.
- Reading or writing the data at locations out of the bounds of an array is allowed by C++ compiler, but might read the garbage data or might write to the memory locations owned by other programs. This can corrupt the data used by other programs.
- Accessing out-of-bounds elements is undefined behavior.
- C++ compilers do not enforce bounds checking.
  
  ```cpp
  int numbers[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "numbers[12] : " << numbers[12] << endl;  // Garbage or crash
  numbers[12] = 123;                                     // May corrupt memory or crash
  std::cout << "numbers[12] : " << numbers[12] << endl;
  ```

- If you go really crazy and use memory locations to far fetched than the array bounds, the C++ compiler will compile the program without any error but program will crash during runtime.
    
  ```cpp 
  int numbers[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  numbers[1234123] = 10;                                 // Runtime crash likely
  cout << "numbers[1234123] = " << numbers[1234123] << endl;
  ```

## 4. Pointers
- In C++, all variables reside at specific memory addresses.
- A pointer is a special type of variable that stores the memory address of another variable.
- Pointers are denoted using the `*` symbol after the data type.
  
  ```cpp
  int*, char*, double*, float*, long int* etc.
  ```

- You can also have pointers to user-defined types like struct, class, etc.  

### 🛠 Declaring Pointers
  
  ```cpp
  int* p_number{};               // can only store an address of an int.  
  double* p_fractional_number{}; // can only store an address of a double.
  ```

- Initializing a pointer explicitly to `nullptr`
- `nullptr` means that the pointer is not pointing to any memory location.
  
  ```cpp
  int* p_number1{nullptr};
  int* p_fractional_number1{nullptr};
  ```
- All pointers have the same size on a given architecture (typically 4 bytes on 32-bit, 8 bytes on 64-bit) as they only save the memory address.
- However, a pointer can store memory address of a variable whose type is same as itself.

### 📌 Pointer Syntax Variants
- Position of `'*'` symbol while declaring the pointer does not matter
  
  ```cpp
  int*  p_number2 {nullptr};
  int * p_number3 {nullptr};
  int  *p_number4 {nullptr};          // All work same, but *p_number4 is easier to understand in case of
                                      // multiple variables.

  // 'p_number5' is a pointer but 'other_int_var' is a normal int variable.
  int* p_number5 {}, other_int_var{}; 
  ```

### Assigning Address to Pointer
  
  ```cpp
  int int_var{23};
  int *p_int{&int_var}; // The address of & operator is used to get address of the variable and store it in the pointer variable.
  ```

### Dereferencing a Pointer

  ```cpp
  int int_var{23};
  int *p_int{&int_var}; 
  cout << "int_var = " << *p_int << endl; // dereferencing a pointer variable
  ```
        
### Pointers to characters
- pointer to `char` can be declared in same way as pointer to `integer`.
  
  ```cpp
  char *p_char {nullptr};
  char c_var1 {'A'};
  p_char = &c_var1;
  ```

### 📣 Printing Strings via Character Pointers
- You can print entire string using `p_char2`. That is beauty of character pointers.
- 🔥 This works because string literals are null-terminated character arrays ('\0' at the end).
  
  ```cpp 
  const char *p_char2 {"Hello"};
  cout << "p_char2 = " << p_char2 << endl;                          // Prints entire string.                
  cout << "\nThe value stored at p_char2 = " << *p_char2 << endl;   // Prints first character of the string.
  ```

### ✏️ Modifying Character Arrays
- If you want to modify characters, use a mutable character array instead of a string literal.
- ⚠️ String literals (const char*) are stored in read-only memory, and modifying them leads to undefined behavior.

  ```cpp
  char p_char3 [] {"Hello World!"}; 
  cout << "p_char3 = " << p_char3 << endl;
  p_char3[0] = 'B';
  cout << "p_char3 after modification = " << p_char3 << endl;
  ```

### ❌ Example: Modifying a String Literal (Leads to Undefined Behavior)
- On many systems, string literals are stored in read-only memory (part of the .rodata section).
- Trying to write to that memory (e.g., str[0] = 'M') may cause:
  - A segmentation fault
  - A runtime crash
  - Or sometimes it may just seem to work, which is dangerous because it hides the bug.

  ```cpp
  #include <iostream>

  int main() {
      const char* str = "Hello";  // "Hello" is stored in read-only memory

      std::cout << "Original string: " << str << std::endl;

      // Attempt to modify the string literal
      str[0] = 'M';  // ❌ UNDEFINED BEHAVIOR!

      std::cout << "Modified string: " << str << std::endl;

      return 0;
  }
  ```

## 5. Virtual Memory
- A Virtual Memory is a trick that fools your program to think that it is the only program that is running on your OS and all the memory resources belong to it.
- Virtual memory is a technique that gives each program the illusion that it has the entire memory space to itself.
- Each program runs as a separate process, and each process gets a virtual address space from 0 - (2^N-1) where: 
  - `N = 32` on 32 bit systems 
  - `N = 64` on 64 bit systems.

- Therefore, 
  
  ```cpp
  Real Memory Size    = Size of physical RAM 
  Virtual Memory Size = (2^N) - 1
  ```
- Not all parts of a program are loaded into memory at once. Only the required parts (currently being executed) are loaded into RAM by the CPU and MMU (Memory Management Unit).
- This efficient memory usage allows better performance and multitasking.
- The MMU maps virtual addresses to physical addresses behind the scenes.
- The memory map is the standard format defined by the OS. All the programs written for that OS must confirm it. 
- It is actually divided into sections -
  
  ```txt
    System
    Stack  - Stores local variables, function call frames.
    Heap   - Used for dynamic memory allocation at runtime.
    Data   - Stores global and static initialized variables.
    Text   - Stores compiled program code (instructions).
  ```

## 6. Dynamic Memory Allocation

- Stack
  1. Memory is limited and automatically managed.
  2. Lifetime is tied to the scope of the variable.
  3. You don’t control the allocation/deallocation manually.

- Heap
  1. Also limited in size.
  2. The developer has full control over allocation and deallocation.
  3. Memory is managed using `new` and `delete` operators.
      
    ```cpp
     #include <iostream>
     int main(int argc, char** argv)
     {
       {
         int local_scope_var {33};       // Automatically allocated on stack.
         int *local_ptr_var = new int;   // Allocated on heap.
       }                                 // scope of variable "local_scope_var" dies here.  
       return 0;
     } 	                                 // 'heap_ptr' must be deleted explicitly before program ends.
    ```

- Accessing memory via an uninitialized or deleted pointer won't cause a compile-time error but can cause runtime failure.
- Always initialize, and later reset or delete, your pointers properly.

### Allocating and Releasing Heap Memory
    ```cpp
    int *p_number{nullptr};
    p_number = new int;   				// Contains a junk value by default.
    delete p_number;							// The memory that 'p_number' points to is freed but pointer itself still holds the address
                                  // of that memory location.

    p_number = nullptr;  					// Good practice to avoid dangling pointer

    int *p_number5{new int(23)}; 	// Direct initialization method.

    int *p_number6{new int{23}};  // Uniform initialization method.
    ```

### Double delete is Dangerous!
- Calling 'delete' twice on a pointer twice will lead to undefined behavior leading to crashing the program and should be avoided in any case.

  ```cpp
  int* p_number = new int(42);
  delete p_number;
  delete p_number;        // ❌ Undefined behavior (program may crash)
  ```
But: If the pointer is set to `nullptr` after deleting the memory it was pointing to, deleting it again is `safe but it is unnecessary`.
  ```cpp
  int* p_number = new int(42);    // Dynamically allocate memory
  delete p_number;                // Free the memory
  p_number = nullptr;             // Set pointer to nullptr

  delete p_number;        // ✅ Safe: Deleting nullptr does nothing
  ```
- It's important to note that you should only use `delete` on pointers that `were dynamically allocated using new`. 
- Attempting to delete a pointer that was not dynamically allocated or attempting to delete the same memory twice can lead to undefined behavior and potential crashes.

- Additionally, it's crucial to ensure that you have a matching `delete` or `delete[]` (for arrays) for every `new` or `new[]` in your code. 
- Failing to do so can result in memory leaks, where dynamically allocated memory is not properly freed, leading to a gradual increase in memory usage over time.

### Dangling pointer  
- A dangling pointer points to memory that is no longer valid. 
- Trying to dereference or use it will result in undefined behavior.
- Following 3 types of behavior will lead to creation of dangling pointers 
  1. Uninitialized pointer
  2. Deleted Pointer
  3. Multiple Pointers pointing to same memory location (and one gets deleted)
  
- Solution to the dangling pointer problem
  - Always initialize pointers
  - Set pointers to `nullptr` after deleting.
  - If multiple pointers point to the same memory, clearly define ownership and avoid double deletion.

## `'new'` Operator Failure
- The `'new'` operator rarely fails in practice. 
- Many programs assume that new always successfully allocates memory and do not check for allocation failure.
- However, in memory-intensive applications or on memory-constrained systems, failed allocations can be catastrophic and must be handled gracefully.

  ```cpp
  // Try to allocate insanely huge array in one go.
  // Likely to crash or terminate the program	
  
  int* very_big_int_array {new int[1'000'000'000'000'000'000'000'000'000]};

  // Repeated allocations in a loop to exhaust system memory. 
  // Eventually leads to failure and termination.
  
  for (size_t i{}; i < 1'000'000'000'000; i++){
    int* lots_of_ints {new int[1'000'000'000'000'000}};
  }
  ```

### Handling new failures
- There are two ways to handle memory allocation failures:

1. Using try-catch block (throws `std::bad_alloc`) 
    
    ```cpp 
    #include <iostream>
    #include <new>

    try {
        int* data = new int[1'000'000'000];
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
    ```
2. Using `std::nothrow` (returns `nullptr` instead of throwing exception)
  
    ```cpp
    #include <iostream>
    #include <new>

    int* data = new(std::nothrow) int[1'000'000'000];
    if (!data) {
        std::cerr << "Memory allocation failed using nothrow!" << std::endl;
    }
    ```

### Null Pointer safety
- Null pointer safety means ensuring that your pointer is pointing to a valid memory address before using or dereferencing it.
- Accessing or deleting a null pointer is safe, but dereferencing a null pointer leads to undefined behavior (usually a crash).

  ```cpp
  int* p_int = new int{};

  if (p_int) {  // Or: if (p_int != nullptr)
      std::cout << "p_int points to a VALID address: " << p_int << std::endl;
  } else {
      std::cout << "p_int points to an INVALID address (nullptr)." << std::endl;
  }
  ```

- Calling `delete` on a `nullptr` is safe

  ```cpp
  int* p_number = nullptr;
  delete p_number;  // ✅ Safe. No effect, no crash.
  ``` 
- Therefore, you don't need to check for nullptr before calling delete. This is redundant: 
  ```cpp
  if(p_number){
    delete p_number;
    p_number = nullptr;
  }
  ```
- Instead, this is sufficient 
  ```cpp
  delete p_number;       // Safe even if p_number is nullptr
  p_number = nullptr;    // Good practice to avoid dangling pointers
  ```

### `Delete` Vs `Free`
#### 🔹 `delete` (`C++ keyword`)
- Used to `deallocate memory` allocated with `new`.
- `Automatically calls the destructor of the object` (for class types).
- Syntax:

  ```cpp
  int* ptr = new int;
  delete ptr;  // For single object

  int* arr = new int[10];
  delete[] arr;  // For arrays
  ```

#### 🔹 `free` (`C function from <cstdlib>`)
- Used to deallocate memory allocated with `malloc()`, `calloc()`, or `realloc()`.
- Does not call destructors – it just frees raw memory.
- Syntax:

  ```cpp
  int* ptr = (int*)malloc(sizeof(int));
  free(ptr);
  ```

#### 🧠 Key Differences
|Feature	              | delete / delete[]	         | free()                         |
|-----------------------| ---------------------------| -------------------------------|
|Language origin	      | C++	                       | C (also usable in C++)         |
|Paired with	          | new / new[]	              |  malloc(), calloc(), realloc()  |
|Destructor called?	    | ✅ Yes	                   | ❌ No                          |
|Overloadable by class?	| ✅ Yes (operator delete)	 | ❌ No                          |
|Type-safe?	            | ✅ Yes	                   | ❌ No                          |
|Use for arrays?	      | Use delete[]	             |Same function free()            |

#### 🚫 Mixing `new`/`delete` with `malloc`/`free`
- You should never mix them:

  ```cpp
  int* a = new int;
  // free(a);    ❌ Wrong: use delete
  delete a;     ✅

  int* b = (int*)malloc(sizeof(int));
  // delete b;   ❌ Wrong: use free
  free(b);      ✅
  ```
## Memory Leaks
- A memory leak occurs when dynamically allocated memory is not properly released, and the program loses access to it.
- Memory leaks are problematic, especially for long-running programs, as they lead to inefficient memory use and eventual crashes or slowdowns.
- Common causes of memory leaks:
  
### 1. Reassignment of stack address to active dynamic address pointer.

  ```cpp
  int *p_num {new int{34}};     // Points to heap memory ('address1').
  int number = 32;              // 'number' variable is stored on stack ('address2').

  p_num = &number;              // Now points to stack memory, heap memory at address1 is leaked

  //	(Solution) :- 
  int *p_num{new int{34}}; 
  int number = 32;          

  delete p_num;                 // Release the memory pointed by 'p_num1' before assigning new value to it.
  p_num = &number;         
  ```

### 2. Double allocation without freeing the previous one

  ```cpp
  int *p_num {new int{34}};   
  p_num = new int{44};          // memory with int{34} leaked.
  
  // (Solution) :-
  int *p_num{new int{34}};
  delete p_num;                 // Release the memory pointed by 'p_num1' before Reassignment.
  p_num = new int{44};          // memory with int{34} leaked.
  ```

### 3. Pointer in local scope i.e. Nested scope with dynamically allocated memory 
- Whenever a pointer in an local scope is assigned a memory address and if this memory is not released before the pointer goes out of scope, a memory leak is created.
  
  ```cpp
  #include <iostream> 
  int main(int argc, char *argv){
    {
      int *p_number { new int{234}};
    }
    // 'p_number' goes out of scope and memory with int{234} gets leaked.
    return 0;
  }
  // (Solution) :-
  #include <iostream> 
  int main(int argc, char *argv){
    {
      int *p_number { new int{234}};
      delete p_number;
    }
    return 0;
  }
  ```

### Dynamically Allocated Arrays
- Arrays can be allocated on the heap using `new` operator. 
- Use `std::nothrow` to prevent exceptions on allocation failure.
- Different ways of dynamic array allocation -

  ```cpp
  // For static arrays this variable should be of type 'const size_t' unless that compiler will throw an error.
  size_t size {10};                                                   

  // 'p_salaries' array will contain garbage values.
  double *p_salaries { new double[size] };                            
  
  // 'p_students' array will contain 10 integer values initialized to 0.
  int *p_students  { new(std::nothrow) int[size]{} };									
  
  // 'p_scores' array contains 10 double values. First 5 will be initialized as specified and remaining 5 will be initialized to 0.
  double *p_scores { new(std::nothrow) double[size]{1, 2, 3, 4, 5}};  
                                                                      

  if(p_salaries){
    for(size_t i = 0; i < size; i++){
      // For printing array elements we can use regular array access notation, or pointer arithmetic syntax.
      cout << " p_salaries[" << i << "] : " << p_salaries[i] << " - " << *(p_salaries + i) << endl;
    }
  }
  ```

- Releasing the dynamically allocated memory for arrays
  
  ```cpp
  delete[] p_salaries; 
  p_salaries = nullptr;

  delete[] p_students; 
  p_students = nullptr;

  delete[] p_scores; 
  p_scores = nullptr;
  ```

### `Static` Vs `Dynamic` Arrays
- `Dynamically allocated arrays` are managed through `pointers`. 
- They do not support `std::size()` or `range-based for loops`.
- Pointers and arrays are different thus the `'std::size'` operator will not work on pointers pointing to the dynamically allocated arrays. 
- Also, these pointers do not have properties of an array, so range based for loops will not work on these pointers.
  
  ```cpp
  double *students {new(std::nothrow) double[]{1.1, 2.2, 3.3, 4.4, 5.5, 6.6}};

  // std::size() operator will not work on pointers pointing to the dynamically allocated arrays
  cout << "Size of array students : " << std::size(students) << endl;      // Error: std::size doesn't work on pointers    

  // range based for loop will not work on pointers pointing to dynamically allocated arrays
  cout << "Content of students array : - " << endl;
  for (auto i: students){                           // Undefined behavior  
    cout << " i : " << i << endl;
  }
  ```
- ❗ Avoid using std::size() and range-based for loops with raw pointers.

## References
- Declaring and using the references

  ```cpp
  int int_val{23};
  double d_val{22.11};

  int& 		r_int_val_1 {int_val};   	// reference assigning through initialization
  int& 		r_int_val_2 = int_val;   	// reference assigning through assignment
  double& r_d_val{d_val}; 			
  ```
- References must be initialized when declared.
- You cannot create an uninitialized reference.
- You need to declare and initialize references in single line. If you just declare the reference but do not initialize it then compiler will throw compile time error.
  
  ```cpp
  int& ref_i;                           // ❌ Compilation error
  ```

- If you modify the data through reference then the original variable will get modified and vice versa is also true as both are pointing to the same memory location.

  ```cpp
  r_int_val_1 = 50;
  std::cout << int_val << '\n';         // Output: 50
  ```

### References Vs Pointers
- References 
  1. References do not need dereferencing for reading or writing the values stored in it.
  2. Must be initialized while declaring 
  3. Once initialized, they can not be changed to refer to another object.

- Pointers
  1. Must undergo referencing or dereferencing to access the value they point to.
  2. Can be reassigned to point to another location.
  3. Can be declared un-initialized (will contain garbage addresses if not explicitly set).

- References behave like constant pointers but they have a much friendlier syntax.

  ```cpp
  double d_data = 10.5;
  double other_d_data = 20.5;
  
  double* const const_p_d_val = &d_data; // constant pointer to double
  // const_p_d_val = &other_d_data;     ❌ Error: cannot reassign a const pointer

  double& ref_d_val = d_data;     // reference to double
  // ref_d_val = other_d_data;    ✅ This copies the value of `other_d_data` into `d_data`, not reassignment of reference
  ```

### Const and Non-Const references

✅ Non-const Reference:
- Can be used to modify the original variable it refers to.

✅ Const Reference:
- Used to access the original variable without modifying it.
- Often used for read-only access or to avoid unnecessary copying (especially for large objects).
  
  ```cpp
  int score = 99;
  const int& ref_score = score; // Cannot modify score through ref_score
  ```

- Const Pointers (for comparison)

  ```cpp
  int score = 99;

  // Constant pointer (cannot point elsewhere, but can modify value)
  int* const p_score = &score;
  *p_score = 100;                 // ✅ Allowed
  // p_score = &other;            ❌ Error

  // Constant pointer to constant data (cannot change pointer or value)
  const int pi = 3;
  const int* const p_pi = &pi;
  // *p_pi = 4;                   ❌ Error
  // p_pi = &other_pi;            ❌ Error
  ```

### `int* const` Vs `const int*`
```cpp
int score = 99;

int* const p_score1 = &score;    // This is a constant pointer to a non-const int.
const int* p_score2 = &score;    // This is a pointer to a const int.
```
#### 1. `int* const p_score1 = &score;`
- This is a constant pointer to a non-const int.

- ✅ You can modify the value being pointed to:

  ```cpp
  *p_score1 = 100;  // OK
  ```
- ❌ You cannot change where the pointer points:

  ```cpp
  int another = 50;
  p_score1 = &another;  // ❌ Error: p_score1 is const
  ```
- Think of it like:
🔒 Pointer is const, 🔓 Data is modifiable

#### 2. `const int* p_score2 = &score;`  
- This is a pointer to a const int.

- ❌ You cannot modify the value via the pointer:

  ```cpp
  *p_score2 = 100;  // ❌ Error: value is const
  ```

- ✅ ou can change where the pointer points:

  ```cpp
  int another = 50;
  p_score2 = &another;  // OK
  ```
- Think of it like:
🔓 Pointer is modifiable, 🔒 Data is const

#### 🔁 Quick Summary
- 
  |Declaration | Can change value? | Can change pointer?|
  |------------| ----------------- | -------------------|
  |int* const p_score1 | ✅ Yes | ❌ No|
  |const int* p_score2 | ❌ No | ✅ Yes|

- You can combine both for complete const-ness:
  ```cpp
  const int* const p_score3 = &score;
  // ❌ Cannot change *p_score3
  // ❌ Cannot change p_score3
  ```

## 6.	Character manipulation and Strings
- `#include <cctype> `- include this library for character manipulation
- C-style strings (character arrays) are not easy or convenient to work with. 
  - You must manually manage their size and ensure they are null-terminated `\0`.
  - They lack built-in methods for string manipulation.
- C++ provides `std::string` class, which builds on top of character arrays and offers a much more easier interface string handling.

### STL functions for manipulating characters (from `<cctype>`) -
  
  ```CPP
  std::isalnum(c);   // Checks if c is alphanumeric (a-z, A-Z, 0-9)
  std::isalpha(c);   // Checks if c is an alphabet (a-z, A-Z)
  std::isblank(c);   // Checks if c is a blank space (' ')
  std::isupper(c);   // Returns true if c is an uppercase letter
  std::islower(c);   // Returns true if c is a lowercase letter
  std::toupper(c);   // Converts c to uppercase
  std::tolower(c);   // Converts c to lowercase
  ```

## 7.	C-string manipulation
- `#include <cstring>` – Include this header to use standard C-string manipulation functions.
- To store a string into a pointer, you must declare a `'const char*'` pointer. 
- The `'char*'` type pointer will not work.
  
  ```CPP
  const char* s = "This is a string.";                  // correct
  char* s1 = "Assigning a string into a char* pointer." // Warning: conversion from string literal to 'char*'
  ```

- To declare a `constant C-string` using a pointer :

  ```CPP
  const char* const s = "This is a constant string.";
  //s[0] = 't';                                         // Error: Cannot modify a constant string
  ```
### `char*` Vs `const char*`
- In C++, the difference between `char*` and `const char*` lies in whether or not you are allowed to modify the data being pointed to.

#### `1. char* — Pointer to modifiable character data`
- This means you can modify the characters at the memory address pointed to (`thought it is dangerous`).

  ```cpp
  char* str = "Hello";      // ❌ This is actually dangerous!
  str[0] = 'h';             // trying to change 'H' to 'h' — Undefined Behavior!
  ```
- The reason this is dangerous is because, string literals like "Hello" are typically stored in read-only memory. 
- Modifying them via `char*` is undefined behavior.

- ✅ A safer way to use `char*` if you want modifiable data:

  ```cpp
  char str[] = "Hello";     // this is an array (copy of the literal)
  str[0] = 'h';             // OK, now it's 'hello'
  ```


#### `2. const char* — Pointer to read-only character data`
- You cannot modify the characters. This is typically used for string literals and function parameters that shouldn't be changed.

  ```cpp
  const char* str = "Hello";
  str[0] = 'h';             // ❌ Compiler error: modifying const data
  ```
- ✅ This is the correct way to point to string literals:

  ```cpp
  const char* message = "Welcome";
  ```

#### ✅ 1. Function accepting `char*` (`modifiable`)
- Use when the function modifies the string data.
  
  ```cpp
  void toUpperCase(char* str) {
      while (*str) {
          *str = toupper(*str);
          ++str;
      }
  }

  int main() {
      char name[] = "john";             // modifiable array
      toUpperCase(name);
      std::cout << name << std::endl;   // Output: JOHN
  }
  ```
- If you passed a string literal (e.g., `"john"`) instead of `char[]`, it would crash because literals are not modifiable.

#### ✅ 2. Function accepting `const char*` (`read-only`)
- Use when the function only reads the string.

  ```cpp
  void greet(const char* name) {
      std::cout << "Hello, " << name << "!" << std::endl;
  }

  int main() {
      greet("Alice");  // string literal
      char username[] = "Bob";
      greet(username); // also valid
  }
  ```
- Compiler will protect you from accidentally modifying the string inside greet().

#### ✅ 3. Array of characters vs Pointer to characters
-
  ```cpp
  char arr[] = "Hi";       // array of characters (modifiable)
  const char* ptr = "Hi";  // pointer to string literal (read-only)
  ```

#### Differences:
-
  | Expression	      | Type	  | Modifiable?  | 	Memory Allocation      |
  | ---------------   |-------  | -----------  | 	---------------------- |
  | `char arr[]`	    | Array	  | ✅          |  Stack, copy of literal  |
  | `const char* ptr`	| Pointer	| ❌	         |  `Read-only` memory        |

- You can even pass both to the same function:

  ```cpp
  void print(const char* msg) {
      std::cout << msg << std::endl;
  }

  int main() {
      char arr[] = "Good";
      const char* ptr = "Morning";

      print(arr);                 // fine
      print(ptr);                 // fine
  }
  ```

#### 🚫 Trying to Modify `const char*`
-
  ```cpp
  void unsafe(const char* str) {
      str[0] = 'X';               // ❌ Compiler error
  }
  ```
#### ✅ Use `const` as much as possible for safety
- 
  ```cpp
  void logMessage(const char* msg) {
      std::cout << "[LOG]: " << msg << std::endl;
  }
  ```
- This way, users of your function know that you're not going to change their data.

#### 🧠 Summary
-  
  |Type	         | What it means	                 | Can modify?  |	Used for                                 |
  |------------  | --------------------------------| -------------|	----------------------------             |
  |`char*`	     | Pointer to modifiable char data |	✅	        |   Mutable strings but not safe to change. |
  |`const char*` | 	Pointer to read-only char data |	❌       	| String literals, safe params              |
  |`const []`    | 	Modifiable local copy          |	✅	       	| Safe to change content                    |

- If you try to modify `const char*` data, you'll get a compiler error. 
- If you use `char*` on string literals, the program might crash at runtime due to `undefined behavior`.


### `Strlen()` Vs `sizeof()`
1. `strlen()` 
  - Returns the number of characters in a `C-string` (`excluding the null terminator`).

    ```cpp
    char message [] {"Earth is round."};
    cout << " The no of characters in 'message' is = " << strlen(message) << endl;    // Outputs 15
    ```

  - Also works on decayed arrays
      
    ```cpp
    const char* p_message {"Earth is round in shape."}; // Array decays into pointer when we use 'const char*'.
    cout << " The no of characters in 'message' is = " << strlen(p_message) << endl;  // Outputs 15
    ```

2. `sizeof()`  
  - Returns the total number of bytes, including the null terminator. And as `1 character` is of `1 byte`, it can be used to get number of characters in the string. 
  - Only gives correct string length if used on an actual array (not a pointer).

    ```cpp
    char message [] {"Earth is round in shape."};
    // Returns size of 'message' in terms of bytes. Outputs 16 (includes '\0')
    cout << " The no of characters in 'message' is = " << sizeof(message) << endl;    
    
    // Array decays into pointer when we use 'const char*'.
    const char* p_message {"Earth is round in shape."}; 	
    
    // Returns size of 'const char*' pointer. Outputs 8 (pointer size on 64-bit systems)
    cout << " The no of characters in 'message' is = " << sizeof(p_message) << endl;  
    ```

### Common C-string Functions
1. `strcmp()`  
    
    ```cpp
    int strcmp(const char* a, const char* b)
    ```
    - Compares two strings `lexicographically`.
    - Returns:
      - `Negative` if `a < b`
      - `0` if `a == b`
      - `Positive` if `a > b`
    - Note: Lexicographically, `uppercase` letters come before `lowercase` letters.

2. `strncmp()`   
    
    ```cpp
    int strncmp(const char* a, const char* b, size_t size)
    ```
    - Same as `strcmp()` function, however compares only first `'n'` number of characters as specified by `'size'`.

3. `strchr()`  
    
    ```cpp
    const char* strchr(const char* str, int ch);
    ```
    - Return pointer to first occurrence of `ch` in `str`.

4. `strrchr()`  
    ```cpp
    const char* strrchr(const char* str, int ch);
    ```
    - Return pointer to last occurrence of `ch` in `str`.

##	C-String Concatenation and Copying (C++)
- All these functions work on null-terminated character arrays (C-strings) from `<cstring>` (aka `<string.h>` in C).
  
  ```cpp
  #include <cstring>
  ```
### 🔗 `std::strcat(dest, src)`

- Syntax 

    ```cpp
    char* strcat(char* dest, const char* src);
    ```
- Appends the contents of `src` to the end of `dest`.
- The `dest` string must have enough space to hold both its original contents and the contents of `src`.
- The resulting `dest` string is null-terminated.
- Because of these serious limitations, that you yourself need to keep track of the `size` of the first string, many compilers do not even allow to use this function.
- Returns a pointer to `dest`.
    - ❗ Undefined behavior if the `dest` buffer is not large enough.
    - ⚠️ Not recommended in modern C++ — use `std::string` for safety.

### 🔐 `std::strncat(dest, src, count)`
- Syntax 
  
    ```cpp
    char* strncat(char* dest, const char* src, std::size_t count);
    ```
- Appends up to `count` characters from `src` to the end of `dest`.
- Ensures no more than `count` characters from `src` are appended.
- The `dest` string must still have enough space for:
  - its original contents
  - `count` characters
  - and the null terminator `(\0)`
- Returns a pointer to `dest`.
- 🧠 Unlike `strncpy`, this function always `null-terminates` the result.

### 📋 `std::strcpy(dest, src)`
- Syntax 

  ```cpp
  char* strcpy(char* dest, const char* src);
  ```
- Copies the entire null-terminated string from `src` to `dest`.
- The `dest` buffer must be large enough to hold all characters plus the null terminator `\0`.
- Returns a pointer to `dest`.
- `❗` Undefined behavior if `src` is larger than `dest`.

### ✂️ `std::strncpy(dest, src, count)`
- Syntax
  
  ```cpp
  char* strncpy(char* dest, const char* src, std::size_t count);
  ```
- Copies up to `count` characters from `src` to `dest`.
- If `src` is shorter than `count`, the rest of `dest` is filled with null characters.
- If `src` is longer than or equal to `count`, the result may not be null-terminated!
- Returns a pointer to `dest`.
- ⚠️ Often misunderstood. You must manually null-terminate `dest` if needed.

### 🚫 Why are these considered unsafe?
- They do not do bounds checking.
- Easy to cause `buffer overflows` or `undefined behavior`.
- Use `std::string`, `std::strncat`, or `std::copy` alternatives in modern C++.

## ✅ Modern C++ String Handling (Using `std::string`)
- 🛡️ `std::string` is safe, flexible, and easier to use. 
- It manages memory for you and prevents common bugs like `buffer overflows`.

#### 🔗 Concatenation (Instead of strcat / strncat)
- Easy and readable.
  
  ```cpp
  std::string a = "Hello, ";
  std::string b = "World!";
  std::string result = a + b;        // "Hello, World!"
  ```
- No need to pre-allocate buffer size.
- Automatically handles null-termination.

#### 📋 Copying (Instead of strcpy / strncpy)
- Simple assignment.
- Safe — no need to manage length or memory.
  
  ```cpp
  std::string original = "Sample";
  std::string copy = original;       // Deep copy
  ```

#### ✂️ Substring Copy (Instead of strncpy)
- substr(pos, len) gives you a slice of the string.
  
  ```cpp
  std::string s = "Example";
  std::string sub = s.substr(0, 3); // "Exa"
  ```

#### 🧾 Comparison Table
-
  | Operation     	| C-style	                 | Modern C++ (std::string)	      | Safety Level  |
  |-----------------| -------------------------|--------------------------------|-------------- |
  | Concatenation	  | `strcat(dest, src)`	     | `a + b` or `a.append(b)`	      | ✅ Safe       |
  | Bounded concat	| `strncat(dest, src, n)`	 | `a += b.substr(0, n)`	        | ✅ Safe       |
  | Copy	          | `strcpy(dest, src)`	     | `copy = original`	            | ✅ Safe       |
  | Bounded copy	  | `strncpy(dest, src, n)`	 | `copy = original.substr(0, n)`	| ✅ Safe       |
  | Length	        | `strlen(s)`	             | `s.length()` or `s.size()`	    | ✅ Safe       |
  | Comparison	    | `strcmp(a, b)`	         | `a == b`	                      | ✅ Safe       |

#### 💡 Why prefer `std::string` ?
- Memory-safe (automatic resizing)
- Cleaner syntax
- Standard functions like `find()`, `replace()`, `substr()`, `append()`
- Works well with STL containers and algorithms


## 8.	Introducing `std::string` 
- The `C-strings` whether defined staticly on the stack or dynamically on the heap, have a few drawbacks:  
  - You must manually track the `size` of the string.
  - You must ensure the null terminator `('\0')` is present at the end

- The best part of `std::string` is that it can grow automatically and we need not worry about its size.

- The `std::string` class in C++ overcomes these issues:
  - It automatically manages memory and size.
  - It provides built-in methods for string manipulation.
  - It can grow and shrink dynamically.

### Declaring and using `std::string`
- 
  ```CPP
  #include <string>

  std::string full_name;                                        // Empty string
  std::string planet {"Earth! The planet where sky is blue."};  // Initialized with a string literal.
  std::string preferred_planet {planet};                        // Copy initialization from another std::string.

  std::string message{"Hello, world!", 8};                      // Initialized with first 8 characters : "Hello, w"

  std::string weird_message (3, 'e');           // Initialize with multiple copies of char. Here, 'eeee'
  std::string weird_message {3, 'e'};           // Invalid syntax: uses initializer list, not supported here

  std::string greeting {"Welcome, Home!"}; 
  std::string say_welcome {greeting, 0, 7};     // Extracts "Welcome" (7 characters starting at index 0).
  ```

### Memory Safety with `std::string`
- When using `C-style` strings (`const char*`), reassigning the pointer can cause memory leaks if the original memory was dynamically allocated and not properly deallocated.
- `std::string` handles memory automatically and prevents such leaks during reassignment.

  ```cpp
  const char* str {"Sky is very cloudy. Today might rain heavily."};
  str = "Whoa! It started raining.";  // OK for const char* but memory leak if original was from dynamic allocation
                                      // In this case tere was no memory leak.
  ```
- 💡 Example of memory leak while using C-strings 
  - If the original string was dynamically allocated, like this:

    ```cpp
    char* str = new char[100];
    strcpy(str, "Sky is very cloudy...");

    str = "Whoa! It started raining.";      // ❌ Memory leak! You lost access to the dynamically allocated memory.
    ```
  - Here, you allocated memory using `new[]`, and then reassigned the pointer `str` without calling `delete[]` first. 
  - That means the originally allocated memory is now unreachable, which is `a classic memory leak`.

- ✅ With std::string, memory is automatically cleaned up:

  ```cpp
  std::string str {"Sky is very cloudy. Today might rain heavily."};
  str = "Whoa! It started raining.";        // Safe reassignment, old memory is freed
  ```

- ✅ Summary:

  |Code Example 	                            | Memory Leak?	 |  Why                                |
  |-----------------------------------------  |----------------|------------------------------------ |
  |`const char* str = "..."`	                | ❌ No	       | String literal in static memory     |
  |`char* str = new char[100]; str = "...";`	| ✅ Yes	       | Dynamically allocated memory lost   | 

##	One Definition Rule (ODR) 
- The One Definition Rule in C++ states that entities (variables, functions, classes, etc.) must have only one definition across the entire program, although declarations can appear in multiple places.
- Applies to:
  1. Free-standing variables
  2. Functions
  3. Classes and structs
  4. Class member functions
  5. Class static member variables

- Key Notes:
1. **A definition** provides full details of an entity (e.g., allocating storage for a variable or providing a function body).
2. **A declaration** introduces an entity but doesn’t allocate storage or define behavior (e.g., extern int x; or a function prototype).

- Only exception to this rule is `'class'` definitions. There can be multiple definitions of a Class, however there should be only one definition per translation unit.

#### Variables and ODR
- Variables must be defined only once across the entire program (including all `.cpp` files).
- Multiple declarations are allowed, but only one definition.

  ```cpp
  // OK: declaration (no memory allocation)
  extern double weight;

  // Only ONE definition allowed (allocates memory)
  double weight {}; 
  ```

#### Classes and ODR
- You can define a `class` or `struct` multiple times, but only once per translation unit (source file after preprocessing).
- All definitions must be identical; otherwise, it violates ODR.

  ```cpp
  // In file1.cpp and file2.cpp — both are OK if identical
  class Point {
      int x;
      int y;
  };
  ```

#### Functions and ODR
- A `function` can be declared multiple times, but it must have only one definition in the entire program.
- Each function in C++ should have unique signature. The function signature comprises of 'function name' and it's parameters.
- Function signature = function name + parameter types (not return type).
- Overloading is allowed based on different signatures.

  ```cpp
  int add(int a, int b);     // Declaration
  int add(int a, int b) {    // Definition — must be only one
      return a + b;
  }
  ```
#### Function Parameters and Scope
- Parameters passed by value are local copies inside the function. Modifications do not affect original variables.

  ```cpp
  double increment_multiply(double a, double b) {
      std::cout << "Before increment: a = " << a << ", b = " << b << "\n";
      double result = (++a) * (++b);
      std::cout << "After increment: a = " << a << ", b = " << b << "\n";
      return result;
  }
  ```
#### Function Declaration (Prototype)
- A function must be declared before it is used. Otherwise the compilation will fail.
- The function definition also acts as a declaration if placed before its usage.

  ```cpp
  int max(int a, int b);      // Declaration (Prototype)
  // or
  int max(int, int);          // Valid: parameter names optional
  ```

#### Function Definition
- Function is a reusable piece of code that can take number of optional inputs and produce some desirable output.

  ```cpp 
  return_type function_name (parameter1, parameter2, ...){
    // operations
    return return_type;
  }
  ```
- variables can be defined only once.

  ```cpp
  int max(int a, int b) {
      return (a > b) ? a : b;
  }
  ```
    
## ❓ Does the function signature in C++ include the return type?
- 🚫 No, the return type is not considered part of the function signature in C++.

#### ✅ C++ Function Signature Definition:
- A function’s signature in C++ consists of:

  1. The function name
  2. The number and types of parameters (including const qualifiers on reference types)
  3. Parameter order matters
  4. Default values and return type are NOT part of the signature

  ```cpp
  int add(int a, int b);         // OK
  float add(int a, int b);       // ❌ Error! Redefinition — same signature as above
  Even though one returns int and the other float, both have the same signature:
  add(int, int)
  ```

#### 🧠 Why not include return type?
- C++ requires functions to be distinguished by their parameter list only — return type overloading is not allowed, because the compiler can’t resolve which version to call when there's ambiguity:

  ```cpp
  auto x = add(1, 2); // Which 'add' to call? Can't be resolved by return type.
  ```

#### ✅ But what about const?
- const on parameters passed by reference is part of the signature.

  ```cpp
  void foo(int& a);
  void foo(const int& a); // ✅ Different signature — allowed
  ```

## Functions across multiple files - Compilation model revisited.
1. Compiler Converts C++ program into binary file which can be executed on computer.
2. Compiler steps 
    1. **Preprocessing** 
        - Pastes content of the header files into the program to be compiled.
        - When you are using standard library headers, please use angular brackets whereas when you are using your own defined headers, use double quotes. 
          ```cpp
          #include <iostream>
          #include "compare.h"
          ```
    2. These preprocessed files are known as translation units. (TU)
    3. Compiler generates an object file for each translation unit separately.
    4. Linker 
        1. Linker links all these separate binary files or object files into single exe file which we execute on computer.
        2. The linker searches for Function definitions on in all translation units (.cpp) files in the project. 
        3. The definition does not have to live in the same .cpp file with the same name as the header.

#### Some common Linker Errors 
1. `ld returned 1 exit status` 
    - This is the linker error you should be looking for. 'ld' is the name of the linker that GCC uses.

2. `LNK2019: unresolved external symbol` 
    - This is the linker error given by MSVC compiler.

                      
## Pass By Value
### 1. Pass By Value  
- When arguments are passed by value, a copy of each variable is made and passed into the function.
- Changes to the parameters inside the function do not affect the original variables.

  ```cpp
  void update(int x) {
      x = 10;            // Only modifies the local copy
  }
  ```
### 2. Pass By Pointer  
- When arguments are passed by pointer, the memory address of the original variable is passed to the function.
- Changes made using the pointer affect the original variable.

  ```cpp
  void update(int* x) {
      *x = 10;           // Dereference and modify original
  }
  ```
### 3. Pass By Reference   
- When passed by reference (int& x), the parameter is an alias for the original variable.
- Any modification directly affects the original variable.
- No dereferencing is needed (unlike pointers).

  ```cpp
  void update(int& x) {
      x = 10;            // Directly modifies original
  }
  ```

### 📤 Getting Output from Functions
You can return results from functions in several ways:

#### 1. Return by Value
- Returns a copy of a value.
- The most common and intuitive way of returning results.
- Return value optimization (RVO) is usually applied by the compiler.
- In modern compilers, `Return by value` is commonly optimized out by the compiler whenever possible and the function is modified behind your back to `Return by reference` to avoid unnecessary copies

  ```cpp
  int add(int a, int b) {
      return a + b;  // Returned by value
  }
  ```

#### 2. Output Parameters (Return by Reference or Pointer)
- Useful when you need to return multiple values or want to avoid copying large objects.
- The function modifies arguments passed by reference or pointer.

  ```cpp
  void compute(int a, int b, int& sum, int& diff) {
      sum = a + b;
      diff = a - b;
  }
  ```
- Prefer passing by reference over pointer in C++ for output parameters, as references are safer and syntactically cleaner.

#### 📥 Input Parameters & `const` Keyword
- Input parameters **that should not be modified** inside the function should be passed using `const`.

- Options:
  - `const int& param` — pass-by-reference to const (efficient for large objects).
  - `const int* param` — pointer to const.
  - `int* const param` — const pointer (can't be changed to point elsewhere).
  - `const int* const param` — const pointer to const data.

  ```cpp
  void printMessage(const std::string& message) {
      std::cout << message << std::endl;  // Safe read-only access
  }
  ```
## Return Value Optimization (RVO)
```cpp
#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name) : name_(name) {
        std::cout << "Constructor called for " << name_ << std::endl;
    }

    Person(const Person& other) {
        std::cout << "Copy constructor called for " << other.name_ << std::endl;
        name_ = other.name_;
    }

    ~Person() {
        std::cout << "Destructor called for " << name_ << std::endl;
    }

private:
    std::string name_;
};

Person createPerson() {
    return Person("Alice");  // This would normally return a temporary object
}

int main() {
    Person p = createPerson();  // Return value optimization (RVO) may eliminate copy here
    return 0;
}
```
### 🧠 What’s Happening:
- Without RVO, this code would:
  - Construct a temporary `Person` object inside `createPerson()`.
  - Copy it to `p` using the copy constructor.
- With RVO, the compiler optimizes out the copy, and constructs `Person("Alice")` directly in `p`'s memory location.

### 📝 Output with RVO (expected):
```rust
Constructor called for Alice
Destructor called for Alice
```
### 📝 Output without RVO (e.g., if forced off):
```rust
Constructor called for Alice
Copy constructor called for Alice
Destructor called for Alice
Destructor called for Alice
```
### 🔧 Forcing Copy (Disabling RVO):
- You can disable RVO by returning a named local variable instead:

  ```cpp
  Person createPerson() {
      Person temp("Alice");  // Named local variable
      return temp;           // No RVO, copy constructor is called
  }
  ```
- Now the compiler must call the copy constructor (or move constructor if available).

##	Function Overloading
- Function overloading allows multiple functions with the same name but different parameter lists (signatures).
- Return type alone cannot be used to distinguish overloaded functions.  

  ```cpp
  int max(int x, int y);
  //double max(int x, int y);                 // Can not overload on return type. Compiler Error.
  double max(double x, double y);
  std::string max(const std::string& x, const std::string& y);
  ```

- ✅ Overloading is allowed with -
  1. Order of parameters.
  2. Number of parameters.
  3. Types of the parameters.

    ```cpp
    int sum(int a, int b);
    int sum(int a, int b, int c);           // different number
    float sum(float a, float b);            // different types
    int sum(int b, double a);               // different order/types
    ```
- ❌ Not Allowed:
  - Overloading with only different return types:

    ```cpp
    int max(int a, int b);
    // double max(int a, int b);   // ❌ Error: Same signature
    ```
- ⚠️ Ambiguity in Overloading
  - If there is ambiguity with type of parameters of the overloaded functions, no function will be called, and compiler will raise an ambiguity error.
  - In this scenario you need to type cast the parameters explicitly or check whether you have the version of the overloaded function for the parameters you are sending.

    ```cpp
    // Overloaded functions
    void print(int x);
    void print(double x);
    
    // Call
    print(3.0f);  // May cause ambiguity: float is between int and double
    ```

## Lambda Functions
- Lambda functions (or lambda expressions) are a feature in C++ used to define anonymous functions — functions without a name.
- They are useful for short-lived operations, especially with STL algorithms (like `std::sort`, `std::for_each`, etc.), and for keeping code concise and readable.

### 🔧 General Syntax 

```cpp
[capture list] (parameters) -> return_type{
  // Function body
}
```
- `capture list`: Defines which variables from the surrounding scope are accessible inside the lambda.
- `parameters`: Function arguments (can be omitted if none).
- `return_type`: (Optional) Use `->` to explicitly specify the return type.
- The body contains the actual logic.

### 📌 Basic Example (Named Lambda)
```cpp
auto func = [](){
  std::cout << "This is a lambda function." << std::endl;
};
func();          // Calling of lambda function.
```

### 📌 Immediately Invoked Lambda Expression (Anonymous)
```cpp
[](){
  std::cout << "Hello world!" << std::endl;
}();            // Called immediately after definition
```

### 📌 Lambda with Parameters
```cpp
[](double a, double b){
  std::cout << " a + b : " << (a + b) << std::endl;
}(10.1, 23.3);
```	
### 📌 Lambda with Return Value    
```cpp 
auto result = [](double a, double b) -> double{
  return a + b;
}(10.1, 23.3);
std::cout << " result = " << result << std::endl;
```

### 📌 Lambda with Explicit Return Type Conversion
- lambda function that takes arguments and returns the result, explicitly specifying the return type. 
- The 'int' return type will convert the output type to 'int' irrespective of the argument type.

  ```cpp
  auto result = [](double a, double b) -> int{
    return a + b;        // Result will be implicitly cast to int
  }(10.1, 23.3);
  std::cout << " result (as int) = " << result << std::endl;
  ```
### 📌 Inline Lambda Expression Inside std::cout  
- Print the result of the lambda function directly
 
  ```cpp
  std::cout << " result = " << [](double a, double b)-> double{
    return a + b;
  }(2.3, 4.5) << std::endl;

  // OR Without explicitly specifying the type of the result.

  std::cout << " result = " << [](double a, double b){
    return a + b;
  }(2.3, 4.5) << std::endl;
  ```

### 📌 Capturing Variables

```cpp 
int a = 10, b = 20;

// Capture by value
auto sum1 = [a, b]() {
    return a + b;
};

// Capture all by value
auto sum2 = [=]() {
    return a + b;
};

// Capture by reference
auto sum3 = [&a, &b]() {
    a += 1;
    b += 1;
    return a + b;
};

// Capture all by reference
auto sum4 = [&]() {
    a *= 2;
    b *= 3;
    return a + b;
};
```

## 9. Capture Lists in Lambda Functions
- By default, the body of a lambda function does not have access to variables defined outside its scope.
- Capture lists are used to give lambdas access to surrounding variables — either by value or by reference.  

### Syntax 
  ```cpp
  [capture list] (parameters) -> return_type {
      // body
  };
  ```
- Example   
  ```cpp
  double a{10};
  double b{20};

  auto func = [a, b] () {
    std::cout << " a + b = "<< a+b << endl;
  };
  func();
  ```

### 1. Capture by Value 
- Variables are copied into the lambda.
- Changes made inside the lambda do not affect the original variables.
- What we have in the lambda function is a copy.

  ```cpp
  cout << "\n --- capture by value --- \n";
  int c{54};

  // The value of variable 'c' at previous line of code will be passed by value to capture list.
  auto func1 = [c](){     
    std::cout << "First lambda func: c = "<< c << endl;
  };
  
  for(size_t i = 0; i < 5; i++){
    std::cout << "Outside loop: c = "<< c << endl;
    func1();
    ++c;
  }
  
  auto func2 = [c](){    // The value of variable 'c' at previous line of code will be passed by value to capture list.
    std::cout << "\nSecond lambda func: c = "<< c << endl;
  };
  func2();
  ```
- 💡 Output:
  ```r
   --- capture by value ---
  Outside loop: c = 54
  First lambda func: c = 54
  Outside loop: c = 55
  First lambda func: c = 54
  Outside loop: c = 56
  First lambda func: c = 54
  Outside loop: c = 57
  First lambda func: c = 54
  Outside loop: c = 58
  First lambda func: c = 54
  
  Second lambda func: c = 59
  ```

### 2. Capture by reference 
- What we have in the lambda function is actual reference.

  ```cpp
  cout << "\n---  capturing by reference ---" << std::endl;
  int d{54};
  
  auto func1 = [&d](){    // reference is passed in capture list, so whenever 'd' is modified it is visible in lambda function.
    std::cout << "Inner value: d = "<< d << endl;
  };

  for(size_t i = 0; i < 3; i++){
    std::cout << "Outer value: d = "<< d << endl;
    func1();
    ++d;
  }

  auto func2 = [&d](){    // reference is passed in capture list, so whenever 'd' is modified it is visible in lambda function.
    std::cout << "\nfun2 lambda func: d = "<< d << endl;
  };	
  func2();
  ```
- 💡 Output:
  ```r
  --- Capture by Reference ---
  Outer value: d = 54
  Inner value: d = 54
  Outer value: d = 55
  Inner value: d = 55
  Outer value: d = 56
  Inner value: d = 56

  fun2 lambda func: d = 57
  ```

### 3. Capture All by Value (`[=]`)
- Capture entire context from outside of lambda function to its inside

  ```cpp
  cout << "\n--- capturing All by value ---" << std::endl;
  int c{54};
  int d{5};
  auto func1 = [=](){     // The '=' sign inside capture list means that entire context is available inside lambda function by value.
                          // capture all by value (read-only copies)
    std::cout << "Inside lambda func: c = "<< c << ", d = " << d << endl;
    // ++c;               // ❌ Error: increment of read-only variable  
    // ++d;               // ❌ Error: increment of read-only variable
  };

  for(size_t i = 0; i < 5; i++){
    std::cout << "Outer value: c = "<< c << endl;
    func1();
    ++c;
  }
  ```
- 💡 Output:
  ```r
  --- capturing All by value ---
  Outer value: c = 54, d = 5
  Inside lambda func: c = 54, d = 5
  Outer value: c = 55, d = 6
  Inside lambda func: c = 54, d = 5
  Outer value: c = 56, d = 7
  Inside lambda func: c = 54, d = 5
  Outer value: c = 57, d = 8
  Inside lambda func: c = 54, d = 5
  Outer value: c = 58, d = 9
  Inside lambda func: c = 54, d = 5
  ```
#### Mutable lambda 
- still capture by value, but allow modifying the local copy

  ```cpp
  cout << "\n--- capturing All by value ---" << std::endl;
  int c{54};
  int d{5};
  auto func1 = [=]() mutable {     // The '=' sign inside capture list means that entire context is available inside lambda function by value.
                          // capture all by value (read-only copies)
    std::cout << "Inside lambda func: c = "<< c << ", d = " << d << endl;
    ++c;               
    ++d;               
  };

  for(size_t i = 0; i < 5; i++){
    std::cout << "Outer value: c = "<< c << endl;
    func1();
    c+=2;
  }  
  ```
- 💡 Output:
  ```r
  --- capturing All by value ---
  Outer value: c = 54
  Inside lambda func: c = 54, d = 5
  Outer value: c = 56
  Inside lambda func: c = 55, d = 6
  Outer value: c = 58
  Inside lambda func: c = 56, d = 7
  Outer value: c = 60
  Inside lambda func: c = 57, d = 8
  Outer value: c = 62
  Inside lambda func: c = 58, d = 9
  ```

### 4. Capture All by Reference 
- Capture entire context from outside of lambda function to its inside by reference
  
  ```cpp
  cout << "\n--- Capturing All by Reference ---\n";
  int c{4};

  auto func1 = [&](){     // The '&' sign inside capture list means that entire context is available inside lambda function by reference.
    std::cout << "First lambda func: c = "<< c << endl;
  };

  for(size_t i = 0; i < 5; i++){
    std::cout << "Outer value: c = "<< c << endl;
    func1();
    c = c+2;
  }

  [&](){
    std::cout<< "\nSecond lambda function: c " << c;
  }();
  ```
- 💡 Output:
  ```r
  --- Capturing All by Reference ---
  Outer value: c = 4
  First lambda func: c = 4
  Outer value: c = 6
  First lambda func: c = 6
  Outer value: c = 8
  First lambda func: c = 8
  Outer value: c = 10
  First lambda func: c = 10
  Outer value: c = 12
  First lambda func: c = 12
  
  Second lambda function: c 14
  ```

### 5. Mixed Capture Example
- capture by both value and reference.
  
  ```cpp
  int a = 1, b = 2;
  
  auto func = [a, &b]() {
      std::cout << "Inside lambda: a = " << a << ", b = " << b << std::endl;
      // ++a; // Cannot modify a (it's a copy)
      ++b;   // Modify original b
  };
  
  func();
  std::cout << "After lambda: b = " << b << std::endl;
  ```
- 💡 Output:
  ```python
  Inside lambda: a = 1, b = 2
  After lambda: b = 3
  ```
## 10. Function Templates
- `Function templates` are blueprints for generating functions. They are not actual functions until instantiated by the compiler.
- The compiler generates a concrete version of the function, called a `template instantiation`, by replacing the template parameters with the types used in a function call.
- The real C++ function generated by the compiler is called a 'Template instance'.
- Syntax
  
  ```cpp
  template <typename T>
  T maximum(T a, T b) {
      return (a > b) ? a : b;
  }
  ```
- Example 
  ```cpp
  int x = 10, y = 20;
  std::cout << maximum(x, y);  // Compiler generates maximum<int>(int, int)
  ```
- Real function declarations and definitions aka template instances are created when you call the function with arguments.
- If the template parameters are of the same type `(T,T)`, then the arguments you call the function with must also match, or else you get a compiler error.
- Template instances won't always do what you want. A good example is when you call out maximum function with pointers. 
- If the parameters must be of the same type (e.g., T, T), then arguments passed must match in type, otherwise you get a compiler error or an implicit conversion (if possible).
- Function templates require the operations used in the function body (like >) to be supported by the argument types.
- Avoid using raw pointers directly with templates unless you're sure the operation makes sense with them.
- You can use tools like `cppinsights.io` to visualize how template functions are instantiated and converted to real functions by the compiler.

### Template Type Deduction and Explicit Arguments

- When calling a function template, the compiler usually deduces the template type from the arguments.
- You can explicitly specify the template argument type, which is helpful in some cases.

  ```cpp
  template <typename T>
  T maximum(T a, T b) {
      return (a > b) ? a : b;
  }
  
  double c = 22.11, d = 10.11;
  std::string e = "Hello", f = "World";
  
  auto res1 = maximum(c, d);               // Deduces T as double
  auto res2 = maximum<std::string>(e, f);  // Explicitly specifies T as std::string

  maximum<double> (c, e);                  // Compiler error will be thrown as for parameter 'e', conversion from 'std::string' to
                                           // 'double' is not possible.  
  ```

- If the function arguments are of different types, and implicit conversion is possible, the compiler will perform it.
- If conversion is not possible, you'll get a `compile-time error`.
- You can guide or override the compiler’s deduction using explicit template arguments.

###  Template specialization
- Template specialization allows you to override or tailor the implementation of a template for specific types.
- Use this when the generic version doesn't behave as needed for certain types.
- Example : Specializing for `const char*`

  ```cpp
  template <typename T>
  T maximum(T a, T b) {
      return (a > b) ? a : b;
  }
  
  // Template specialization for const char*
  template <>
  const char* maximum<const char*>(const char* a, const char* b) {
      return (std::strcmp(a, b) > 0) ? a : b;
  }
  
  const char* s1 = "apple";
  const char* s2 = "banana";
  std::cout << maximum(s1, s2);  // Output: banana
  ```

- 🔸 Notes
  - Specializations must match the full template signature.
  - For custom types, you may specialize the function to handle comparison, logging, etc.

## 11. Static Asserts - C++11 feature
- `A static assert` is a way to perform compile-time assertions. 
- It ensures that certain conditions are met during compilation, preventing the program from compiling if the condition is false. 
- This is useful for catching errors early.
- Syntax   
  
  ```cpp
  static_assert(condition, message);
  ```
    -	condition	: A constant expression that is evaluated at compile time.
    -	message		: A string that gets displayed if the assertion fails.
                 If the condition evaluates to false, the compiler throws an error with the provided message.
- Example
  ```cpp
  static_assert(sizeof(int) == 4, "Size of int must be 4 bytes.");
  
  // If the size of int is not 4 bytes on a given platform, this will cause a compilation error with the message 
  // "Size of int must be 4 bytes."

  // Use in templates
  template <typename T>
  void process(T val) {
      static_assert(std::is_integral<T>::value, "T must be an integral type");
      // logic...
  }
  ```

🔸 Use Cases for static_assert
  - Enforcing type requirements in templates (e.g., `std::is_integral<T>`).
  - Checking for platform-specific assumptions (e.g., byte sizes).
  - Validating constexpr values at compile time.
  - Preventing use of unsupported features on certain platforms or compilers.

## 12. Type Traits 
- Header: `#include <type_traits>`
- Type traits are a collection of templates provided in the <type_traits> header that allow you to query or modify types at compile time. 
- They are used for type introspection and type transformations, helping to write more flexible and generic code.
- Purpose
  -  Type traits are compile-time templates that allow type introspection and type transformation. They are essential in template metaprogramming and generic programming.

###  Some of the common type traits are
  
  ```cpp
  std::is_integral<T>::value        // Checks if T is an integral type.
  std::is_floating_point<T>::value  // Checks if T is a floating-point type.
  std::is_same<T1, T2>::value       // Checks if T1 and T2 are the same type.
  std::is_const<T>::value           // Checks if T is a const type.
  ```

### Example : Type Detection
  ```cpp
  #include <iostream>
  #include <type_traits>

  template <typename T>
  void checkType() {
      if (std::is_integral<T>::value) {
        std::cout << "T is an integral type.\n";
      } else if (std::is_floating_point<T>::value) {
          std::cout << "T is a floating-point type.\n";
      } else {
          std::cout << "T is neither integral nor floating-point.\n";
      }
  }

  int main() {
      checkType<int>();         // Outputs: T is an integral type.
      checkType<double>();      // Outputs: T is a floating-point type.
      checkType<std::string>(); // Outputs: T is neither integral nor floating-point.
  }
  ```

### Type Transformations Traits 
- In addition to type checks, you can also perform type transformations using type traits.

  ```cpp
  std::remove_const<T>	: Removes the const qualifier from T.
  std::add_pointer<T>		: Adds a pointer to T.
  ```

#### Example: Type Transformation
  ```cpp
  #include <iostream>
  #include <type_traits>

  int main() {
      using T = const int;
      using NoConst = std::remove_const<T>::type;      // NoConst is int
      std::cout << std::is_same<NoConst, int>::value ; // Outputs: 1 (true)
  }
  ```

## 13. Concepts - C++20 feature
- Heder: `#include <concepts>`
- `'Concepts'` is one of the important features of C++20.
- `'Concepts'` are compile-time constraints on template parameters. 
- Using `'Concepts'` we can specify that our function template should only be called with `integer`, `double` or `string` data types and if this is violated compiler error is generated.	
- Both `'char'` and `'int'` are of integral type.

#### Basic Concept Syntax Variants
  ```cpp 
  // Syntax 1
  template <typename T>
  requires std::integral<T>
  T add(T a, T b) {
      return a + b;
  }
  
  // Syntax 2
  template <std::integral T>
  T add(T a, T b) {
      return a + b;
  }
  
  // Syntax 3
  auto add(std::integral auto a, std::integral auto b) {
      return a + b;
  }
  
  // Syntax 4
  template <typename T>
  T add(T a, T b) requires std::integral<T> {
      return a + b;
  }
  ```

## 14. Custom Concepts
- Header file  

  ```cpp
  #include <type_traits>   // For std::is_integral_v<T>;
  ```
- Following are different ways to create/define concepts
- Please note that, if we use `'require'` keyword just once then the compiler will only check for the syntax but it will not enforce the semantic meaning of that statement

  - syntax 1  
    
    ```cpp
    template <typename T>
    concept myIntegral = std::is_integral_v<T>;    // Just makes sure that the arguments are of integral type.
    ```		
  - syntax 2  
    In this syntax, if we do not pass the template parameters of type which are not compatible or do not support multiplication operation, the concept will fail.
    
    ```cpp
    template <typename T>
    concept multipliable = requires(T a, T b){
      a * b;                                       // Just makes sure that the syntax is valid.  
    };
    ```
  
  - syntax 3  
    If the template parameter does not support increment/decrement operations the compilation will fail.
  
    ```cpp			
    template <typename T>
    concept Incrementable = requires(T a){
      a+=1;                                           // Just makes sure that the syntax is valid.
      a++;
      ++a;
    };
    ```			

- Following are different ways of using concepts
  
  ```cpp
  // Type 1 
  template <typename T>
  requires MyIntegral<T> 
  T add1( T a, T b){
    return a + b;
  }

  // Type 2
  template <MyIntegral T>
  T add2 (T a, T b){
    return a + b;
  }

  // Type 3
  auto add3(MyIntegral auto a, MyIntegral auto b){
    return a + b;
  } 

  // Type 4 
  // The following syntax will make sure that whatever parameter is passed to the function 'fun1', it has to 
  // be compatible with syntax of '+=', prefix/postfix '++' operators.
        
  template <Incrementable T>
  fun1(T a){
    return a+100;
  };
  ```

## 15. `requires` clause - In Depth
- The `requires` clause can define four types of requirements.

### 1. Simple Requirements (Syntax-only checks) 
  
  ```cpp
  template <typename T>
  concept TinyType = requires (T a) {
      sizeof(a);                       // Only checks if sizeof(a) is valid syntax
  };
  ```

### 2. Nested requirements (Semantic checks)
    
  ```cpp
  template <typename T>
  concept TinyType = requires (T a){
    sizeof(a);                 // Simple requirements only check syntax. Checks whether sizeof() operator can be used on 'T'
    requires sizeof(a) <= 4;   // Nested requirements : also checks for the condition.
  }                            // Ensures size is actually <= 4 bytes
  ```

### 3. Compound requirements (With return type checks)
    
  ```cpp
  template <typename T>
  concept Addable = requires (T a, T b){
    {a + b} -> std::convertible_to<int>;     // Checks if 'a + b' is a valid syntax and the result is convertible to 'int'. 
  }
  ```
        
### 4. Type requirements  
   
  ```cpp
  // These are advanced type of requirements. These are not discussed in this course.
  requires typename std::iterator_traits<T>::value_type;
  ```

## 16. Combining Concepts
### Combining with Logical Operators
- Concepts can be combined with logical operators `&&` and `||`.
  
  ```cpp
  // Defining the concept
  template <typename T>
  concept TinyType<T> =  requires (T a){
    sizeof(T);
    requires sizeof(T) <= 4:
  }

  // Combining Concepts - The argument should be either of integral or of floating point type
  template <typename T> 
  T func (T x) requires std::integral<T> || std::floating_point<T> {
    std::cout << " x is either integral or floating-point type !" << std::endl;
  }

  // Combining concepts - The argument should be both integral and less than or equal to 4 bytes in size.
  template <typename T>
  T func(T a) requires std::integral<T> && requires (T a){
                                              sizeof(a);
                                              requires sizeof(a) <= 4;
                                            }
  {
    std::cout << "a is an integral type with <= 4 bytes.\n";
    return 2*a;
  }
  ```

### Concepts with `auto` (C++20)
- This syntax constraints the `auto` parameters you pass in to comply with the `std::integral` concept
  
  ```cpp
  std::integral auto add (std::integral auto a, std::integral auto b){
    return a + b;
  }
  ```

## 17. `'Class'` in C++
### What is a Class?
- A class is a user-defined type in C++ that acts as a blueprint for creating objects.
- It encapsulates `data (member variables)` and `behavior (member functions)` into a single unit.
- By default, all members of a class are private unless explicitly specified otherwise.

### Access Specifiers
- private: Members are accessible `only within` the class.
- public: Members are accessible from `outside` the class.
- protected: (covered later in inheritance) `accessible to the class and derived classes`.
- Unless explicitly specified the members of the class are private by default.
- ⚠️ All members are accessible to other members within the class, regardless of access specifier.

  ```cpp
  class Example {
  private:
      int x;  // Not accessible from outside
  
  public:
      void setX(int value) {
          x = value;  // Accessible within the class
      }
  };
  ```
### Rules about Member Variables
- Member variables can be:
  - Raw stack variables (like `int x;`)
  - Pointers (like `int* p;`)

- Member variables cannot be references (like `int& ref;`) unless initialized in constructors, because references must be initialized at the time of declaration.

### Member Functions
- Functions defined inside a class are called `methods`.
- Methods can access all members of the class (public/private).
- Functions can be defined:
  - Inside the class (implicitly inline)
  - Outside the class using the scope resolution operator `::`

- Everything after the `'public'` keyword is public until next `'private'` keyword.

## Constructors 

### What is a Constructor?
- A constructor is a special function that :
  - Gets called automatically when an object is created.
  - Is used to initialize member variables.

### Constructor Properties
1. Has no return type, not even `void`
2. Has the same name as the class
3. Can be overloaded (multiple constructors with different parameter lists)
4. Is usually public
5. Can be default, parameterized, or delegating

  ```cpp
  class Person {
  public:
      std::string name;
      int age;
  
      Person() : name("Unknown"), age(0) {}                    // Default constructor
      Person(std::string name, int age) : name(name), age(age) {} // Parameterized constructor
  };
  ```

### Getters and Setters Methods
- Public member functions, defined by the user, that get or set private member variables of the class.
- Promote encapsulation and data hiding.
  
  ```cpp 
  class BankAccount {
  private:
      double balance;
  
  public:
      void setBalance(double b) { balance = b; }
      double getBalance() const { return balance; }
  };
  ```

### Splitting Classes Across Multiple Files
#### Best Practices
- Use `#ifndef`, `#define`, `#endif` (include guard) in `.h` file to avoid multiple inclusion.
- It is best practice to use '#ifndef' statement at the beginning of the header file to avoid multiple definitions if the header files is included in multiple files.
  ```cpp		
  #ifndef CYLINDER_H
    #define CYLINDER_H
  #endif
  ```
- 
  ```cpp
  // Cylinder.h
  #ifndef CYLINDER_H
  #define CYLINDER_H
  
  class Cylinder {
      // declarations
  };
  
  #endif
  ```

#### File Structure
- `.h` file : Declarations of class, members, and methods.
- `.cpp` file : Definitions of class methods.
- By convention, the corresponding header file (`.h`) and `.cpp` files have same names.

💡 Keeping declarations and definitions separate improves code organization, compilation time, and debugging.

## Copy Constructor 
A copy constructor is a special constructor used to create a new object as a copy of an existing object.

### 🧠 Why Do We Need a Copy Constructor?
- When you:
  - `Pass an object by value`,
  - `Return an object by value` from a function,
  - Or explicitly copy-construct an object like: `MyClass obj2 = obj1;`

- C++ needs to know how to copy the object, and it uses the copy constructor for this purpose.

### 🧱 Syntax of Copy Constructor
- It takes a const reference to an object of the same class.
  ```cpp
  ClassName(const ClassName& other);
  ```
- This prevents infinite recursion and unnecessary copies.

### ✅ Example of Copy Constructor
  
  ```cpp
  #include <iostream>
  #include <cstring>
  
  class Person {
  private:
      char* name;
  
  public:
      // Constructor
      Person(const char* initName) {
          name = new char[strlen(initName) + 1];
          strcpy(name, initName);
      }
  
      // Copy Constructor
      Person(const Person& other) {
          std::cout << "Copy constructor called!\n";
          name = new char[strlen(other.name) + 1];
          strcpy(name, other.name);  // Deep copy
      }
  
      // Destructor
      ~Person() {
          delete[] name;
      }
  
      void showName() const {
          std::cout << "Name: " << name << std::endl;
      }
  };
  
  int main() {
      Person p1("Alice");
      Person p2 = p1; // Copy constructor is called
  
      p1.showName();
      p2.showName();
  
      return 0;
  }
  ```

### 🔍 Types of Copy
  
  | Type	        | Explanation                                                                                                                  |
  | --------------| -----------------------------------------------------------------------------------------------------------------------------|
  | Shallow Copy	| Copies the pointer, not the actual content. Both objects point to the same memory. Dangerous for dynamic memory.             |
  | Deep Copy	    | Allocates new memory and copies the actual content, not just the pointer. Safe and preferred for objects with dynamic memory.|

### 🧠 When Should You Define a Custom Copy Constructor?
- You should define your own copy constructor when:
  - Your class allocates dynamic memory (e.g., using `new`).
  - Your class manages resources like `file handles`, `sockets`, etc.
  - `The default copy constructor would result in a shallow copy, which could cause problems like double deletion`.

### 🤖 Default Copy Constructor
- If you don’t define a copy constructor, the compiler automatically creates one that performs a shallow copy:

  ```cpp
  Person p2 = p1;  // Compiler-generated copy constructor if not defined
  ```

### ⚠️ Common Issues Without a Proper Copy Constructor
- `Double-free errors` : Both original and copied object point to the same memory.
- `Memory leaks` : If deep copy is not done properly.
- `Undefined behavior` : Especially with classes managing external resources.

### ✅ Best Practices
- Always use `const reference` in copy constructor parameter.
- If you define a custom `destructor`, consider also defining a `copy constructor` and `copy assignment operator` (Rule of Three).
- Prefer `std::string`, `std::vector`, etc. to avoid manual memory management.
  
## Class Object Creation (Stack vs Heap)
- The Cylinder class variables can be defined in two ways: one on stack and another on heap.
  
  ```cpp
  Cylinder c1(10, 20);                   // Stack allocation
  Cylinder* c2 = new Cylinder(10, 20);   // Heap allocation (requires manual deletion)
  ```
- Accessing Members
  - Stack: `c1.volume();`
  - Heap: `c2->volume();` or `(*c2).volume();`
- 🧽 Don't forget to `delete c2`; when done to avoid memory leaks!          


## 🧱 1. Copy Constructor vs. Copy Assignment Operator
- Both are used to copy one object into another, but they are called in different situations and serve different purposes.

### 🔄 Copy Constructor
- Purpose: Creates a new object as a copy of an existing object.
- Syntax:

  ```cpp
  ClassName(const ClassName& other);
  ```
- When it's called:
  - When an object is initialized from another object:
    
    ```cpp
    MyClass obj1 = obj2;    // copy constructor
    MyClass obj2(obj1);     // copy constructor
    ```
  - When an object is passed by value to a function
  - When an object is returned by value from a function

### 📝 Copy Assignment Operator
- Purpose: Assigns the contents of one already-existing object to another.
- Syntax:

  ```cpp
  ClassName& operator=(const ClassName& other);
  ```
- When it's called:
  - When an object has already been created, and we use = to assign a value:

    ```cpp
    MyClass a, b;
    a = b;  // copy assignment operator
    ```

### ⚖️ Comparison Table

- 
  | Feature          | Copy Constructor	                  | Copy Assignment Operator                       |
  | -----------------| ---------------------------------- | -----------------------------------------------|
  | Purpose	         | Initializes a new object	          | Assigns data to an existing object             |
  | Called When	     | Object is created from another	    | Object is assigned after creation              |
  | Syntax	         | ClassName(const ClassName& other)	| ClassName& operator=(const ClassName& other)   |
  | Memory Handling	 | Typically allocates new resources	| Should release old resources and copy new      |
  | Return Type	     | No return type	                    | Returns a reference to *this                   |


## 📐 2. The Rule of Three
If your class manages a resource (like dynamically allocated memory), you should explicitly define:
1. `Destructor` – to free the resource.
2. `Copy Constructor` – to make a deep copy.
3. `Copy Assignment Operator` – to assign correctly and safely.

💡 If you define any one of the three, you should usually define all three.

### 🚀 Example: Rule of Three
  ```cpp
  #include <iostream>
  #include <cstring>
  
  class Person {
  private:
      char* name;
  
  public:
      // Constructor
      Person(const char* n) {
          name = new char[strlen(n) + 1];
          strcpy(name, n);
      }
  
      // Copy Constructor
      Person(const Person& other) {
          name = new char[strlen(other.name) + 1];
          strcpy(name, other.name);
      }
  
      // Copy Assignment Operator
      Person& operator=(const Person& other) {
          if (this != &other) {
              delete[] name;  // release existing resource
              name = new char[strlen(other.name) + 1];
              strcpy(name, other.name);
          }
          return *this;
      }
  
      // Destructor
      ~Person() {
          delete[] name;
      }
  
      void show() const {
          std::cout << name << std::endl;
      }
  };
  ```

## 🧠 3. Rule of Five (C++11 and Later)
In modern C++ (C++11 and beyond), if your class manages resources, you might also need to define:
  
  4. `Move Constructor`
  5. `Move Assignment Operator`

These are for efficient transfer of resources from temporary (rvalue) objects.

#### ✨ Why?
Because copying can be expensive, especially with large objects. Moving means transferring ownership without copying data.

### 🔥 Rule of Five Example
```cpp
class Person {
private:
    char* name;

public:
    // Constructor, Copy Constructor, Assignment, Destructor (same as above)

    // Move Constructor
    Person(Person&& other) noexcept {
        name = other.name;
        other.name = nullptr;
    }

    // Move Assignment Operator
    Person& operator=(Person&& other) noexcept {
        if (this != &other) {
            delete[] name;
            name = other.name;
            other.name = nullptr;
        }
        return *this;
    }

    ~Person() {
        delete[] name;
    }
};
```

## 🧊 Rule of Zero (Modern C++ Best Practice)
In modern C++, try to avoid writing any of the five if possible.

Instead, use standard library classes like `std::string`, `std::vector`, `std::unique_ptr`, which manage resources safely.

```cpp
class Person {
private:
    std::string name;  // No need to define copy/move/destructor manually
};
```
If your class only uses `RAII-compliant` types (which manage themselves), the compiler-generated versions of the "Big Five" are enough.

### Summary
-
  |Rule	          | When to Use                                                                                                        |
  |---------------| -------------------------------------------------------------------------------------------------------------------|
  |Rule of Three	| When your class manages resources manually (via new, file handles, etc.)                                           |
  |Rule of Five   | In C++11+, define move constructor & move assignment if your class is performance-critical and deals with temporary objects|
  |Rule of Zero	  | Preferred in modern C++. Use standard containers and smart pointers that handle resources automatically            |

## Destructors
- Destructor is a special method that gets called automatically when object is destroyed.
- Used for resource cleanup (e.g., releasing heap memory).
- Has same name as class but prefixed with a tilde `~`.
- Takes no arguments and has no return type.
- A class can have only one destructor, and it cannot be overloaded.
  
  ```cpp
  ~Cylinder() {
      std::cout << "Destructor called!\n";
  }
  ```
- Destructors are called when 
  1. Local stack object goes out of scope (dies)
  2. When a heap object is deleted using `delete` keyword.
  
- Destructor is also called at weird places 
  1. When an object is passed by value to a function
  2. When a local object is returned from a function (for some compilers)

### Constructor and	Destructors Call Order
- Constructors are called in the same order in which the objects are declared However destructors are called in the reverse order in which the objects are declared.

  ```cpp 
  int main() {
      Cylinder c1;
      Cylinder c2;
      // c1 constructor -> c2 constructor
      // main ends
      // c2 destructor -> c1 destructor
  }
  ```

## The `'this'` Pointer
- It is a hidden pointer available in all non-static member functions of each class.
- The `'this'` pointer contains the address of the current object for which the method is being executed i.e. it points to the current object invoking the method.
- `'this'` pointer is also available for constructors and destructors.
- Helps resolve naming conflicts and allows method chaining.
- Chained calls using this pointer
  
  ```cpp
  // ------------------------ Chained calls using pointers -------------------------
  Dog* set_name(std::string_view name){
    //name = name;        // This will do nothing, we need to use 'this' pointer.
    this->name = name;
    return this;
  }

  Dog* set_breed(std::string_view breed){
    this->breed = breed; 
    return this;
  }
  Dog d1;
  d1.set_name("Puppy")->set_breed("Indian")->set_age(4);

  // ------------------------ Chained calls using References -------------------------
  // Setter Functions using References
  Dog& set_name(std::string_view name){
    //name = name;        // This will do nothing, we need to use 'this' pointer.
    this->name = name;
    return *this;
  }

  Dog& set_breed(std::string_view breed){
    this->breed = breed; 
    return *this;
  }

  Dog& set_age(int age) {
    this->age = age;
    return *this;
  }
  
  // Chained calls using references
  Dog d2;
  d2.set_name("Puppy").set_breed("Indian").set_age(4);
  ```

### `'this'` pointer chaining 
#### ✅ Case 1: Chaining with Objects (non-pointers)
- If you're working with stack-allocated objects or just objects in general, you use reference (Dog&):
  ```cpp
  Dog d1;
  d1.set_name("Puppy").set_breed("Indian").set_age(4);
  ```
- Setter definition:
  ```cpp
  Dog& set_name(std::string_view name) {
      this->name = name;
      return *this; // Return a reference to the current object
  }
  ```
- 🔁 This allows method chaining using dot (.) operator.

#### ✅ Case 2: Chaining with Pointers (heap-allocated objects)
- If you're working with pointers, you return the this pointer itself:

  ```cpp
  Dog* d2 = new Dog();
  d2->set_name("Tommy")->set_breed("Labrador")->set_age(3);
  ```
- Setter definition:
  ```cpp
  Dog* set_name(std::string_view name) {
      this->name = name;
      return this; // Return the pointer to the current object
  }
  ```
- 🔁 This allows chaining using arrow (->) operator.

#### 👇 Bonus Tip
- If you want both styles to work, you can just use reference style, since it also works on pointer dereference:

  ```cpp
  (*d2).set_name("Tommy").set_breed("Labrador");
  ```
- But if your design always returns `Dog&`, then you must dereference a pointer object manually — so it’s more common to define two overloads (advanced usage) if needed.


## `'struct'` Vs `'class'` 
- Similar to `'class'` keyword `'struct'` keyword is used to create user defined types.
- Only difference: Default access modifier
  - `class` : members are private by default
  - `struct` : members are public by default

- `'struct'` are commonly used where all the members need to be public by default

  ```cpp
  struct Point {
    double x;
    double y;
  }
  
  class PointClass {
    double x;  // private by default
    double y;
  };
  ```
- Also, `structs` are usually used when we want to declare just public variables but we do not want to declare public methods.

###  Size of Class Objects
- The size of a class object is primarily determined by the sum of the sizes of its non-static member variables.
- Member functions do not contribute to the size of a class object. They are shared across all instances and reside in code (text) memory, not per-object memory.
- Static member variables are also not included in the object size; they exist independently of any object.

✅ Important Considerations
- `std::string` is itself a class. It typically contains internal pointers to a dynamically allocated character buffer.
  - Therefore, when a class contains a std::string, its size usually corresponds to the size of the internal pointer(s), not the string data itself.
  
- Due to padding and alignment rules, the size of a class object may be larger than the sum of its members.
  - Sometimes, because of the phenomenon called 'Boundary Alignment' the size of the class object is more than the cumulative size of the member variables.
  - Compilers store member variables at addresses which are multiples of 4, so in case if the data type is of size less than 4 bytes then the variables are aligned at addresses which are multiple of 4 resulting in some memory gaps, which increases the size of objects.

💡 Example
  
  ```cpp
  #include <iostream>
  #include <string>
  
  class MyClass {
      char a;          // 1 byte
      int b;           // 4 bytes (aligned)
      std::string str; // usually 24 bytes on most 64-bit systems (size of internal pointers)
  };
  
  int main() {
      std::cout << "Size of MyClass: " << sizeof(MyClass) << std::endl;
      return 0;
  }
  ```
- Even though the raw size of members may appear small, sizeof(MyClass) may be larger due to:
  - alignment
  - padding
  - internal layout of std::string (which includes pointers, size, capacity, etc.)

## `'const'` Member Functions
- In C++, a constant member function is a function that does not modify any member variables of the class. 
- It is declared by adding the const keyword after the function declaration. 
- Constant functions can only call other constant member functions and cannot modify the object's state.
- This is enforced by the compiler — you cannot change member variables (unless they are marked `mutable`) inside a `const` function.
  
###	Syntax
  
  ```cpp
  Return_type function_name() const;
  ```
### Example 

  ```cpp
  #include <iostream>

  class Example {
  public:
      Example(int x) : data(x) {}
  
      // Constant function declaration
      int getData() const {
          return data;
      }
    
      // Non-constant function (can modify class members)
      void setData(int x) {
          data = x;
      }
    
  private:
      int data;
  };

  int main() {
    Example e(10);
    std::cout << "Initial Data: " << e.getData() << std::endl;  // ✅ Allowed: Calls constant function getData()
  
    e.setData(20);                                              // ✅ Allowed: modifies object
    std::cout << "Updated Data: " << e.getData() << std::endl;

    const Example ce(30);
    std::cout << ce.getData() << std::endl;      // ✅ Allowed on const object
    // ce.setData(40);                           // ❌ Error: cannot call non-const function on const object
  
    return 0;
  }
  ```

- Key Points:
  1. The `constant` member functions can be called on both `constant` and `non-constant` objects
  2. `Non-constant` functions cannot be called on `const` objects.
  3. Helps enforce read-only behavior when working with const objects or APIs.
  
    ```cpp
    // Example with const Object:
      const Example e(10);
      std::cout << e.getData() << std::endl;  	// This works since getData() is const
      // e.setData(20);  												// Error: setData is not const, so cannot be called on a const object
    ```

- A constant member function ensures immutability, making it safer to use in situations where the object's state should not be modified.

### ⚠️ Notes:
- A const member function can still modify variables marked with the mutable keyword.
- Example:

  ```cpp
  class Logger {
  public:
      void log() const {
          ++log_count;             // Allowed because 'log_count' is mutable
      }
  
  private:
      mutable int log_count = 0;
  };
  ```

## Difference between `'friend'` function and `'member'` Function in C++
- In C++, both `friend functions` and `member functions` can access and manipulate class data.
- However, they have distinct differences in how they interact with class members, how they are called, and their purpose.

### Key Differences

  |	Feature											|	Member Function																									        |		Friend Function                                                                     |
  | --------------------------- | ----------------------------------------------------------------        | --------------------------------------------------------------------------------------|
  |	Definition Location					|	Defined inside the class body (or outside with class scope resolution). |  Defined outside the class but declared as a `friend` inside the class.               |
  |	Access to Members						|	Can access all members (`public`, `protected`, and `private`)           |  Can access all members (`public`, `protected`, `private`) of the class where it is   |
  |															|	of its own class.                                                       |  declared a friend, but it's not part of the class itself.                            |
  |	Calling Syntax							|	Called using an object of the class                                     |  Called like a normal function, with the object(s) passed as argument(s)              |
  |															|	e.g.- `obj.memberFunction()`.                                           |  e.g. `friendFunction(obj)`.                                                          |
  |	Association with Class			|	Part of the class. Can directly manipulate members via                  |  Not a member of the class. It gets special access of private and protected members   |
  |															|	implicit `this` pointer.                                                |  via `friend` declaration but has not `this` pointer.                                 |
  |	Purpose / Usage							|	Best when the function logically belongs to the class and               |  Best for operations that require access to private members of multiple classes or for|
  |															|	operates on its internal data.                                          |  operator overloading where it's awkward to make the function a member.               |
  |	Inheritance									|	Can be inherited by derived classes.                                    |  Cannot be inherited, because it is not part of the class itself.                     |
  |	Scope Resolution						|	Can be called on an object directly (implicit `this` pointer).          |  Must be called explicitly with the object(s) passed as an argument.                  |
  | `'this'` pointer						|	Has access to the this pointer.                                         |  Does not have access to this, since it is not a class member.                        |

### 🧪 Code Illustration
  
  ```cpp
  #include <iostream>
  class MyClass;
  
  void showData(const MyClass& obj); // Forward declaration of friend function
  
  class MyClass {
  private:
      int data;
  
  public:
      MyClass(int val) : data(val) {}
  
      void display() const { // Member function
          std::cout << "Inside member function: data = " << data << std::endl;
      }
  
      // Declare friend function
      friend void showData(const MyClass& obj);
  };
  
  // Friend function definition (outside the class)
  void showData(const MyClass& obj) {
      std::cout << "Inside friend function: data = " << obj.data << std::endl;
  }
  
  int main() {
      MyClass obj(42);
  
      obj.display();        // Member function call
      showData(obj);        // Friend function call
  
      return 0;
  }
  ```

## 18. Inheritance
- Inheritance is a core feature of object-oriented programming in C++.
- It allows one class (`derived class`) to inherit properties and behaviors (data and functions) from another class (`base class`).
- Helps in `building new types based on existing ones`, facilitating code reuse and hierarchical design.
- Inheritance `enables extensibility and polymorphism` in object-oriented systems.

### `Public` Inheritance 
- Syntax: 
  
  ```cpp
  class Derived : public Base
  ```
- Behavior:
  - `public` members of the base class remain `public` in the derived class.
  - `protected` members of the base class remain `protected` in the derived class.
  - `private` members of the base class are `not accessible directly` by the derived class.

- Friend functions of the derived class can only access what the derived class can access — `not the private members of the base class`.

#### Example:
  ```cpp
  class Person {
  public:
      int m1;
  protected:
      int m2;
  private:
      int m3;
  };
  
  class Player : public Person {
  public:
      void show() {
          m1 = 1;   // OK
          m2 = 2;   // OK
          // m3 = 3; // Error: private member of base class
      }
  };
  ```
📝 Note: In public inheritance, the "is-a" relationship holds: `Player is a Person`.

### 📙 `Protected` Inheritance
- Syntax: 
  
  ```cpp
  class Derived : protected Base
  ```
- Behavior:
  - `public` and `protected` members of the base class become `protected` in the derived class.
  - `private` members are still not accessible.
- `Outside` the derived class, `inherited members` are not accessible at all.

#### Example:
  ```cpp
  class Person {
  public:
      int m1;
  protected:
      int m2;
  private:
      int m3;
  };
  
  class Player : protected Person {
  public:
      void show() {
          m1 = 1;   // OK (inherited as protected)
          m2 = 2;   // OK
          // m3 = 3; // Error
      }
  };
  
  int main() {
      Player p;
      // p.m1 = 10; // Error: m1 is protected in Player
  }
  ```
📝 Note: This mode is useful when you don’t want the base class’s public interface to be accessible to the users of the derived class.

### `Private` Inheritance   
- Syntax: 

  ```cpp
  class Derived : private Base
  ```
- Behavior :
  - `public` and `protected` members of the base class become `private` in the derived class.
  - `private` members remain inaccessible as usual.

- The `inherited members cannot` be accessed from outside the derived class, not even as `protected`.

#### Example:
  ```cpp
  class Person {
  public:
      int m1;
  protected:
      int m2;
  private:
      int m3;
  };
  
  class Player : private Person {
  public:
      void show() {
          m1 = 1;   // OK (now private in Player)
          m2 = 2;   // OK
          // m3 = 3; // Error
      }
  };
  
  int main() {
      Player p;
      // p.m1 = 10; // Error: m1 is private in Player
  }
  ```
📝 Note: Use private inheritance when the derived class needs to reuse the implementation of the base class but does not want to expose the base interface.

- In any type of inheritance, 'private' members of base class are never accessible in member functions of the derived classes.

### ❗ Key Points

- In all forms of inheritance, the private members of the base class are never directly accessible in the derived class.

- However, private members can still be accessed by friend functions or via public/protected getters/setters if provided.

- Think of inheritance in terms of:
  - `Public inheritance` : "is-a" relationship

  - `Protected/Private inheritance` : "implemented-in-terms-of" relationship (more about internal use)


## 🔁 Resurrecting members back in scope

- In C++, when a derived class defines a member function/variable with the same name as one in the base class, the base class member is hidden (a phenomenon known as `name hiding` or `member overshadowing`).

- To `bring back` or `"resurrect"` base class members that are hidden due to inheritance, C++ provides two main mechanisms:
  1. The scope resolution operator (::)
  2. The `using` declaration

- Resurrecting a overloaded member function is also possible.
- ⚠️ Note: You cannot resurrect private members of the base class directly in the derived class. Only public and protected members can be brought into scope.


### 1. Using the Scope Resolution Operator  
- You can explicitly qualify the base class member using scope resolution operator (::), `BaseClass::member()` syntax to access it from within the derived class.

  ```cpp
  #include <iostream>

  class Base {
  public:
      void display() const {
          std::cout << "Base class display()" << std::endl;
      }
  };
  
  class Derived : public Base {
  public:
      void display() const {
          std::cout << "Derived class display()" << std::endl;
      }
      
      void callBaseDisplay() {
          Base::display();  	  // Resurrects Base class's display()
      }
  };
  
  int main() {
      Derived obj;
      obj.display();         	  // Calls Derived class's display()
      obj.callBaseDisplay();    // Calls Base class's display()
      return 0;
  }
  
  // Output:
  // 		Derived class display()
  // 		Base class display()
  ```
  
  -	In this example: The display() method in the derived class overshadows the one in the base class.
  - By explicitly using Base::display(), we `"resurrect"` the base class method and call it within the derived class.

### 2. Using the `using` Declaration:

- The `using` declaration can be placed inside the derived class to bring one or more base class members (functions or variables) into the scope of the derived class.
 
  ```cpp
  #include <iostream>

  class Base {
  public:
      void display() const {
          std::cout << "Base class display()" << std::endl;
      }
    
      void show() const {
          std::cout << "Base class show()" << std::endl;
      }
  };

  class Derived : public Base {
  public:
      using Base::display;  // Resurrect Base::display() 
  
      void display() const {
          std::cout << "Derived class display()" << std::endl;
      }
    
      void show() const {
          std::cout << "Derived class show()" << std::endl;
      }
  };

  int main() {
      Derived obj;
      obj.display();  			// Calls Derived's display(), Base::display() also in scope
      obj.Base::display();  // Explicit call to Base's display() (resurrected using scope resolution)
      obj.show();     			// Calls Derived's show()
      return 0;
  }

  // Output:
  // 		Derived class display()
  // 		Base class display()
  // 		Derived class show()
  ```
- In this example: 
  - By adding `using Base::display;`, we bring the base class's `display()` function into the derived class's scope, so it can be accessed without the explicit scope resolution operator.
  - The derived class still has its own display() method, but the base class version can also be called by explicitly qualifying it `using Base::display()`.

### 🧠 Key Takeaways
- Name hiding occurs when a derived class defines a member function or variable with the same name as one in the base class.
- Base class members can be resurrected in the derived class using:
  - The scope resolution operator (Base::member) — explicit but useful.
  - The `using` declaration — cleaner syntax, especially useful for function overloads.

- The `using` declaration can also be used to resurrect overloaded functions from the base class.

### ⚠️ Additional Notes:
- If the base class function is overloaded (i.e., multiple versions with different parameters), all overloads are hidden in the derived class when any function with the same name is declared in the derived class.
- You can resurrect all overloads at once using using.

- Example:
  ```cpp
  class Base {
  public:
      void func(int) {}
      void func(double) {}
  };
  
  class Derived : public Base {
  public:
      using Base::func;  // Brings all overloads of func into scope
  
      void func(char) {} // Adds a new overload, does not hide existing ones
  };
  ```

## 🧱 Constructors and Inheritance in C++

### Default Constructors with Inheritance

- In C++, when a class inherits from a base class, the `base class constructor is always executed first`, followed by the `derived class constructor`.

- In the case of multi-level inheritance, constructors are called in the order from the **top-most base class** down to the **most derived class**.

- If a base class does not have a default constructor (i.e., constructor without arguments), then the derived class must explicitly call a base class constructor in its initializer list.

- It is good practice to provide a **default constructor** for any class intended to be a base class to ensure derived classes can be constructed easily.

- While building an object of the derived class, the object of the innermost base class will be constructed first and layer by layer object of the derived class will be constructed.

- Constructor call order for this hierarchy :

  ```cpp
  class A { /* base */ };
  class B : public A { /* derived from A */ };
  class C : public B { /* derived from B */ };
  ```

- When you instantiate C, the constructor order is:

  ```scss
  A() → B() → C()
  ```

### Custom Constructors with Inheritance

- If the base class only has parameterized constructors, then you must call it explicitly from the derived class using the constructor initializer list.

  ```cpp
  class Base {
  public:
      Base(int x) { std::cout << "Base constructor: " << x << "\n"; }
  };
  
  class Derived : public Base {
  public:
      Derived(int x) : Base(x) {
          std::cout << "Derived constructor\n";
      }
  };
  ```
- Private members of the base class cannot be accessed directly in the derived class constructor body or initializer list. 
- Use the base constructor or getters/setters if necessary.

###  Copy Constructors with Inheritance

- When writing a copy constructor for a derived class, you should explicitly call the base class's copy constructor.
- This ensures that the base part of the object is copied correctly.
- You can directly pass an object of the derived class to the base class copy constructor, compiler will smartly copy the data 
  related to the base class from derived class object. 

#### `🚫 Incorrect (Accessing private data directly)` 
- Problem with not using copy constructor of the base class and trying to directly initialize the base class object -

  ```cpp
  Engineer::Engineer(const Engineer& source)
    : Person(source.m_full_name, source.m_age, source.m_address),  // ❌ 'm_address' is private
      contract_count(source.contract_count)
  {
    std::cout << "Engineer Copy Constructor Called." << std::endl;
  }
  ```
- ❌ This may cause a compiler error if the base class members are private or protected.
  1. In above code, we are not using the copy constructor of the `'Person'` class.
  2. `'m_address'` is private to the `'Person'` class and can not be accessed directly form outside the class. This will lead to compiler error.
  3. We could even use the getter method for the `'m_address'` but this will go against the design guidelines.

#### `✅ Correct` 
-
  ```cpp
  Engineer::Engineer(const Engineer& source)
    : Person(source),  // Use Person's copy constructor
      contract_count(source.contract_count)
  {
      std::cout << "Engineer Copy Constructor Called.\n";
  }
  ```
- `✔` This ensures the entire base class state is copied properly.


### Inheriting Constructors (C++11 and Above)
- You can inherit constructors from a `base class` using the `using` keyword.
- If the `'Person'` class is the base class and `'Engineer'` class is the inherited class, then base class constructor is inherited to derived class as follows -

  ```cpp
  class Person {
    public:
      Person(const std::string& name, int age, const std::string& address);
  };

  class Engineer : public Person{
    using Person::Person;    					// Inherit Person's constructor.
  };
  ```
- As a result of base class constructor inheritance, the compiler will generate following code -
  ```cpp
  Engineer (const std::string& fullname, int age, const std::string& address)
          : Person(fullname, age, address)
          {

          }
  ```
- This allows Engineer objects to be created using Person constructors:

  ```cpp
  Engineer e("John", 30, "NY");
  ```
- Inheriting the base constructor will initialize only base class related members.


  
#### ⚠ Important Points:
1. Copy constructors are not inheritable and you will get compiler error if you try to do that. Mostly we do not need to inherit copy constructors as compiler will automatically insert copy constructors.

2. Inherited constructors are base constructors. These base constructors do not have knowledge of the derived class. Any member of the derived class will just contain junk or whatever default value it is initialized with.

3. Constructors are inherited with whatever access specifier they had in base class (e.g. `public`, `protected`).

4. On the top of inherited constructors you can add your own functionality to properly initialize derived member variables.

5. Inheriting constructors adds a level of confusion to your code, as it is not clear which constructor is building your object. It is recommended to avoid them and only use this feature if no other option is available.

#### 🧠 Example:
  ```cpp
  class Engineer : public Person {
      using Person::Person;  // Inherit all Person constructors
  
  public:
      Engineer(const Engineer& source);  // Custom copy constructor
      ~Engineer();
  
  protected:
      int contract_count{0};
  };
  ```

#### ➤ Compiler will implicitly provide:
  ```cpp
  Engineer(const std::string& name, int age, const std::string& address)
      : Person(name, age, address) {}
  ```

### ✅ Summary Table
-  
  | Feature	                             | Description                                                  |
  | -------------------------------------|------------------------------------------------------------- |
  | Default constructor in inheritance	 | Base class constructor is called first, followed by derived. |
  | Custom constructor	                 | Use initializer list to call base constructor.               |
  | Copy constructor	                   | Use base class's copy constructor explicitly.                |
  | Constructor inheritance	             | Use `using Base::Base;` to inherit base class constructors.  |
  | Access to base private members	     | Not allowed directly; use base class constructor or getter.  |
  | Copy constructor inheritance	       | ❌ Not allowed; define your own copy constructor.            |

## Inheritance the Destructors

- In inheritance, destructors are called in reverse order of constructors:
  - First, the derived class's destructor is called.
  - Then, the base class's destructor is called.
- This ensures that the derived part is cleaned up before the base part, maintaining proper resource management.

  ```cpp
  #include <iostream>
  
  class Base {
  public:
      Base() { std::cout << "Base constructor\n"; }
      ~Base() { std::cout << "Base destructor\n"; }
  };
  
  class Derived : public Base {
  public:
      Derived() { std::cout << "Derived constructor\n"; }
      ~Derived() { std::cout << "Derived destructor\n"; }
  };
  
  int main() {
      Derived d;
      return 0;
  }
  ```
- Output:

  ```kotlin
  Base constructor
  Derived constructor
  Derived destructor
  Base destructor
  ```

- ✅ Tip: Always declare base class destructors as virtual if the class is intended to be inherited, to ensure proper destruction through base pointers:

  ```cpp
  class Base {
  public:
      virtual ~Base() { std::cout << "Base destructor\n"; }
  };
  ```

## Reused Symbols in Inheritance
- If you define a member in a derived class with same name as that in the base class, C++ will give preference to the member defined in the derived class i.e. members in child class are going to hide the members in the parent class — even if the signatures differ.
- This is called name hiding, not function overriding.
- You can also access the same name member from base class by making use of scope resolution operator. But the condition is that this member variable should be accessible from the derived class.

  ```cpp
  class Base {
  public:
      void display(int x) { std::cout << "Base display(int): " << x << "\n"; }
  };
  
  class Derived : public Base {
  public:
      void display() { std::cout << "Derived display()\n"; }
  };
  
  int main() {
      Derived d;
      d.display();         // Calls Derived's version
      // d.display(10);    // ❌ Error: Base::display(int) is hidden
  }
  ```

- ✅ To bring the hidden base class member into the derived class scope, use the `using` declaration:

  ```cpp
  class Derived : public Base {
  public:
      using Base::display;  // Bring all overloads of Base::display into scope
      void display() { std::cout << "Derived display()\n"; }
  };
  ```

- Now both versions of `display()` can be called:

  ```cpp
  d.display();      // Derived display()
  d.display(10);    // Base display(int): 10
  ```

### ✅ Summary
-
  | Feature	                  | Behavior                                                            |
  |---------------------------| --------------------------------------------------------------------|
  | Destructor order	        | Called in reverse: Derived → Base                                   |
  | Base class destructor	    | Should be `virtual` for proper cleanup via base pointers            |
  | Name hiding	              | Derived members with same name as base hide the base version        |
  | Access hidden base member	| Use `using Base::member;` or `Base::member()` with scope resolution |


## 19. Polymorphism
- Polymorphism allows a base class pointer or reference to access derived class objects and call their overridden methods dynamically.
- Polymorphism enables the C++ users to create an array of base class pointer or references type and store the derived class objects in it.
- Using polymorphism, we can create functions that can accept pointers/references of the base class type and accept all the derived class objects, so that we need not create separate functions to accept objects of each derived class.

### `'Static'` Binding (Early Binding) with base class pointer
- Static binding is the default behavior when functions are not marked virtual.
- Static binding is the default behavior that we get, when we have a method with same name in all the inherited classes.
- The function to be invoked is determined at compile time based on the type of the pointer or reference, not the actual object it points to.
- In Static binding, if we define a pointer of base class and store objects of inherited classes in that pointer, then irrespective of the type of an object stored, the method of the base class will be called always.

  ```cpp
  Shape   shape1("shape1");
  Oval    oval1(2, 3.4, "Oval1");
  Circle  circle1(2, "circle1");

  std::cout << "Calling methods through pointers (Static Binding)" << std::endl;

  Shape* shape_ptr = &shape1;
  shape_ptr->draw();            // We wish for Shape::draw() to be called and compiler will also call the same Shape::draw() method.
  
  Shape* shape_ptr = &Oval1;
  shape_ptr->draw();          // We wish for Oval::draw() to be called but compiler will look at the 'Shape*' pointer 
                              // type and call 'Shape::draw()' method.
                
  Shape* shape_ptr = &Circle1;
  shape_ptr->draw();          // We wish for Circle::draw() to be called but compiler will look at the 'Shape*' pointer 
                              // type and call 'Shape::draw()' method.
  ```

- `'static binding'` is a bad design, as we need to have separate function for each object type, if we use base class type pointer to store objects of derived classes in it and want to call 'draw()' method of those particular classes.

- Because of static binding we can not have single collection for all the inherited class objects. We need to create separate arrays/collection for each inherited class objects.

- 🔴 Static binding limits polymorphic behavior and can lead to design limitations, especially when handling diverse derived types via base pointers.

  ```CPP
  Circle circle_array[] {circle1, Circle(10.3, "circle2"), Circle(20.3, "circle3") };
  Oval   oval_array[] 	{oval1, 	Oval(2.2, 3.3, "oval2"), Oval(2.2, 3.3, "oval3") };
  ```

### 'Dynamic' binding ('Late' binding) - with Virtual functions.
- Dynamic binding occurs when a function is declared with the virtual keyword in the base class.

- The actual function to invoke is determined at runtime based on the type of the object being pointed to, not the pointer type.

- In dynamic binding, the base class pointer can be used to store the objects of the derived classes and when virtual function is invoked using this pointer, the function related to the object class will be called instead of calling the function depending on the type of the pointer.

- Dynamic binding will not work if the method is not defined as virtual. The base class type of pointer, will only be able to call the methods of the derived class objects which are of virtual type.

  ```cpp
  class Shape {
  public:
      virtual void draw() const {
          std::cout << "Shape::draw()" << std::endl;
      }
  };
  
  class Oval : public Shape {
  public:
      void draw() const override {
          std::cout << "Oval::draw()" << std::endl;
      }
  };
  
  class Circle : public Oval {
  public:
      void draw() const override {
          std::cout << "Circle::draw()" << std::endl;
      }
  };
  
  // Usage
  Shape* ptr = new Circle();
  ptr->draw();  // Outputs: Circle::draw()
  ```
#### Accessing Non-Virtual Members
- Base class pointers cannot access members exclusive to derived classes unless those members are virtual or accessed through downcasting.
- Example of compiler error due to accessing non-virtual method:

  ```CPP
  Shape* raw_ptr;
  raw_ptr = &oval1;
  // raw_ptr->get_x_rad();     // get_x_rad() is not a virtual method, so pointer of base class will not be able to access it. Compiler Error.
  ```

### Size of Polymorphic Objects and vtable Overhead
- Dynamic binding is not free, we need to pay in terms of memory to achieve dynamic binding. C++ stores some information in 'virtual tables' to resolve function calls dynamically.									
- When a class contains at least one virtual function, the compiler adds a hidden pointer (commonly known as the `vptr`) to the class pointing to a `vtable` (virtual table).
- Each polymorphic class has a vtable storing function pointers to its virtual functions.
- ⚠️ Because of the `vptr`, polymorphic objects are slightly larger than non-polymorphic ones.

### Object Slicing   
- Occurs when a derived-class-object is assigned to the base-class type variable (not pointer or reference), the derived part is sliced off, and only base part is copied into that variable.  
- So, calling of virtual methods on the base-class type variable will result in invoking of base class method.
  
  ```CPP	
  Circle c3(3.4, "circle3");
  Shape  s3 = c3;              // Only 'Shape-class' part of the 'circle' object will be assigned to the 's3' object.
  s3.draw();                   // Calls Shape::draw(), not Circle::draw()
  ```
- 🔴 Avoid passing objects by value if polymorphic behavior is expected — use references or pointers instead.

### Summary of Polymorphism Concepts
-
  | Concept	                | Static Binding	          |  Dynamic Binding                  |
  | ------------------------| ------------------------- | ----------------------------------|
  | Keyword	                | None	                    |  `virtual`                          |
  | Resolution Time	        | Compile-time	            |  Run-time                         |
  | Method Invoked By	      | Pointer type	            |  Object type                      | 
  | Supports Polymorphism	  | ❌ No	                   | ✅ Yes                           | 
  | Cost	                  | No extra memory	           | Extra memory for vtable and vptr |
  | Object Slicing Safe?	  | ❌ (slices derived parts) | ✅ if using pointers/references  |

## Arrays of References in C++ 
- C++ does not allow arrays of references directly.
- This restriction arises from the nature of references themselves, which are aliases, not objects and do not occupy storage space like regular variables do. 
- Here’s a detailed explanation:

- Why Arrays of References Are Illegal
  - **`References as Aliases`**  
    A reference in C++ acts as an `alias` for another variable. When you declare a reference, it must be initialized 
    to refer to an existing object, but it does not itself create a new object or allocate storage. Therefore, you 
    cannot create an array that consists of references, as there would be no storage allocated for the references themselves.

  - **`C++ Standard Specifications`**	  
    According to the C++ standard, an object is defined as a region of storage. Since a reference does not have its own storage, attempting to declare an array of references leads to a compilation error. 
    
- For instance, the following code will not compile:
  
  ```CPP 
  int a = 1, b = 2, c = 3;
  // int& arr[] = {a, b, c}; 	// Error: illegal array of references ❌ Compilation error
  ``` 
- This is because 'arr' is expected to be an array of objects, but 'references' do not qualify as objects.

### Workarounds for Arrays of References

#### 1. Using `std::reference_wrapper`  
- This approach effectively simulates an array of references while adhering to the language's constraints.

  ```cpp 
  #include <iostream>
  #include <functional>     // for std::reference_wrapper
  
  int main() {
      int a = 1, b = 2, c = 3;
      std::reference_wrapper<int> arr[] = {std::ref(a), std::ref(b), std::ref(c)};
  
      for (auto& ref : arr) {
          std::cout << ref.get() << " "; 			// Outputs: 1 2 3
      }
  
      return 0;
  }
  ``` 

#### 2. Structs as Workarounds 
- Another method involves using a struct that contains a reference as a member. 
- You can then create an array of such structs:
      
  ```cpp
  struct RefWrapper {
      int& ref;
  };

  int main() {
      int x = 10, y = 20;
      RefWrapper refs[] = { {x}, {y} };    // Now refs[0].ref refers to x and refs[1].ref refers to y.
  }
  ```
  
## 20. 'smart pointers' in C++

- Smart pointers are wrapper classes in C++ that automatically manage the lifetime of dynamically allocated objects.
- Introduced in C++11, smart pointers eliminate manual memory management errors such as memory leaks, dangling pointers, and double deletions.
- The Standard Library offers several types of smart pointers:
  - `std::unique_ptr`
  - `std::shared_ptr`
  - `std::weak_ptr` (used with `shared_ptr`)
  - `std::auto_ptr` (deprecated in C++11 and removed in C++17)

### 1. ` std::unique_ptr `
- A `'unique_ptr'` is a smart pointer that owns and manages a dynamically allocated object, and ensures exclusive ownership. 
- This means that only one `'unique_ptr'` can point to a given object at a time. 
- Once the `'unique_ptr'` is destroyed / goes out of scope, the memory allocated for the object is automatically released (freed).

- Key Properties:
  
  1. **`Exclusive ownership`**  
    Only one `unique_ptr` can own a resource at any time.
  
  3. **`Move-Only Semantics`**  
    Cannot be copied, but can be moved, which transfers the ownership to another `unique_ptr`.
  
  5. **`Automatic Destruction`**  
    Resource is destroyed when the owning unique_ptr is destroyed or reset.

#### Example 

  ```cpp
  #include <iostream>
  #include <memory>    // For 'std::unique_ptr'

  class MyClass {
  public:
      MyClass() {  std::cout << "MyClass Constructor" << std::endl; }

      ~MyClass() {  std::cout << "MyClass Destructor" << std::endl; }
    
      void display() {  std::cout << "Displaying MyClass" << std::endl; }
  };

int main() {
      std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();  // Create unique_ptr
  
      ptr1->display();  		// Use unique_ptr
  
      // std::unique_ptr<MyClass> ptr2 = ptr1;  					// Error: copy not allowed
      std::unique_ptr<MyClass> ptr2 = std::move(ptr1);  	// OK: Move ownership to ptr2
      
      if (!ptr1) {
          std::cout << "ptr1 is now nullptr after moving ownership." << std::endl;
      }
    
      ptr2->display();  		// Use ptr2 now
      return 0;  						// MyClass is automatically destroyed when ptr2 goes out of scope
  }

  // Output:
  //        MyClass Constructor
  //        Displaying MyClass
  //        ptr1 is now nullptr after moving ownership.
  //        Displaying MyClass
  //        MyClass Destructor
  ```

- Explanation:
  - The `unique_ptr` ensures that only one smart pointer owns the object at any time. 
  - When `ptr1` is moved to `ptr2`, `ptr1` becomes a `nullptr`, and `ptr2` now owns the object. 
  - The destructor is automatically called when the `unique_ptr` goes out of scope.

### 2. `std::shared_ptr`
- A `shared pointer` is a smart pointer that allows multiple ownership of the same object.
- Internally uses `reference counting` to track how many shared_ptrs share the resource.
- The object is destroyed only when the last shared_ptr owning it is destroyed.

- Key Properties:
  1. **`Shared ownership`**  
    Multiple `shared_ptr`'s can point to the same resource.
  
  2. **`Reference Counting`**  
    Memory is released only when the reference count reaches zero.
  
  3. **`Thread-Safe Reference Count`**  
    Reference updates are thread-safe.

#### Example 
  ```cpp
  #include <iostream>
  #include <memory>    // For 'std::shared_ptr'

  class MyClass {
  public:
    MyClass() { std::cout << "MyClass Constructor\n"; }
    ~MyClass() { std::cout << "MyClass Destructor\n"; }
    void display() const { std::cout << "Displaying MyClass\n"; }
  };

  int main() {
      std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();  					// Create shared_ptr

      {
          std::shared_ptr<MyClass> ptr2 = ptr1;  															// ptr2 shares ownership with ptr1
          std::cout << "Reference count: " << ptr1.use_count() << std::endl;  // Output: 2

          ptr2->display();
      }  // ptr2 goes out of scope, reference count decreases

      std::cout << "Reference count after ptr2 goes out of scope: " << ptr1.use_count() << std::endl;  // Output: 1

      ptr1->display();
      return 0;  								// MyClass is destroyed when the last shared_ptr (ptr1) goes out of scope
  }

  //	Output:
  //					MyClass Constructor
  //					Reference count: 2
  //					Displaying MyClass
  //					Reference count after ptr2 goes out of scope: 1
  //					Displaying MyClass
  //					MyClass Destructor
  ```

- Explanation:
  - `ptr1` and `ptr2` both share ownership of the MyClass object.
  - The reference count increases as more `shared_ptr` instances point to the object (via use_count()).
  - Once `ptr2` goes out of scope, the reference count drops to 1.
  - When `ptr1` goes out of scope at the end of main(), the reference count drops to 0, and the object is automatically deleted.

### Comparison of `unique_ptr` and `shared_ptr`  

-   |	Feature							|	`std::unique_ptr`																					|	`std::shared_ptr`                                             |
    |	------------------- |-----------------------------------------------------------|-------------------------------------------------------------- |
    |	Ownership						|	Exclusive (only one pointer can own the object).          |	Shared (multiple pointers can own the same object).           |
    |	Copyable						|	❌ Not copyable (only movable)														 |	✅ Copyable (reference count increases)                     |
    | Thread Safety       |	No internal thread safety	                                | Thread-safe reference count                                   |
    |	Memory Management 	|	Automatically deletes object when owner is destroyed or reset  |  Deletes object when last reference is destroyed         |
    |	Overhead						|	Very lightweight (no reference count).									  | Slight overhead ( reference count tracking )                  |
    |	Use Cases 					|	For unique resource ownership 											      |	For shared ownership scenarios                                |

-  When to Use 
     - Use std::unique_ptr when you want exclusive ownership of a resource and don't want to share it with other parts of the code.
  - Use std::shared_ptr when you need shared ownership and expect multiple parts of your code to share and manage the same resource. 
  - However, be mindful of the slight overhead due to reference counting.

### When to Use Each :
- Use `std::unique_ptr` :
  - When you want strict ownership semantics (RAII).
  - For performance-sensitive code where copying is unnecessary.
  - For implementing move-only semantics in classes.

- Use `std::shared_ptr` :
  - When you need to share ownership across multiple scopes or functions.
  - When objects outlive the scope they were created in and are accessed from multiple places.
  - Be mindful of circular references, which can cause memory leaks.

### Additional Notes
- `std::make_unique` vs direct new:
  - Prefer `std::make_unique<T>()` over `unique_ptr<T>(new T)`:
    - Safer (avoids potential memory leaks in expression evaluation).
    - Cleaner and more efficient (especially in exception scenarios).

- `std::weak_ptr` (Overview):
  - Used with `shared_ptr` to break circular references.
  - Does not increase the reference count.
  - Must be converted to `shared_ptr` via `lock()` to access the resource.

### 3. `std::weak_ptr`  

- A weak pointer is a smart pointer that holds a non-owning ("weak") reference to an object managed by `std::shared_ptr`.
- It **does not contribute to the reference count**.
- Used mainly to **prevent circular references**, which can cause memory leaks.

#### Key Properties
1. **Non-owning** :   
  Does not extend the lifetime of the object.

2. **Used with `shared_ptr`** :  
  Created from a `shared_ptr`.

3. **Must use `.lock()`** :  
  To access the object, convert it to a `shared_ptr` with `lock()`, which returns a valid `shared_ptr` if the object still exists, or `nullptr` if it was destroyed.

#### Example: Avoiding Circular Reference

  ```cpp
  #include <iostream>
  #include <memory>
  
  class B;                       // Forward declaration
  
  class A {
  public:
      std::shared_ptr<B> b_ptr;  // A owns B
      ~A() { std::cout << "A destroyed\n"; }
  };
  
  class B {
  public:
      std::weak_ptr<A> a_ptr;    // Use weak_ptr to avoid circular reference
      ~B() { std::cout << "B destroyed\n"; }
  };
  
  int main() {
      std::shared_ptr<A> a = std::make_shared<A>();
      std::shared_ptr<B> b = std::make_shared<B>();
  
      a->b_ptr = b;
      b->a_ptr = a;  // weak_ptr: does not increase reference count
  
      return 0;
  }
  
  // Output:
  // A destroyed
  // B destroyed
  ```
- If `b->a_ptr` were a `shared_ptr`, the reference count would never reach zero due to mutual ownership, causing a memory leak.

### Smart Pointers with Inheritance
- When using smart pointers with **polymorphic types**, always ensure the **base class destructor** is `virtual`, especially when deleting through a base class pointer.

- #### Example : Virtual Destructors and Polymorphism
  ```cpp
  #include <iostream>
  #include <memory>
  
  class Base {
  public:
      Base() { std::cout << "Base Constructor\n"; }
      virtual ~Base() { std::cout << "Base Destructor\n"; }  // Must be virtual
  };
  
  class Derived : public Base {
  public:
      Derived() { std::cout << "Derived Constructor\n"; }
      ~Derived() { std::cout << "Derived Destructor\n"; }
  };
  
  int main() {
      std::unique_ptr<Base> ptr = std::make_unique<Derived>();
      // Correctly calls Derived and then Base destructor
  
      return 0;
  }
  
  // Output:
  // Base Constructor
  // Derived Constructor
  // Derived Destructor
  // Base Destructor
  ```

- Without the virtual destructor, only the Base destructor would be called, causing resource leaks or undefined behavior.

### Summary of Best Practices

- ✅ Prefer `std::make_unique` and `std::make_shared` over raw `new`.

- ✅ Use `unique_ptr` when ownership is exclusive.

- ✅ Use `shared_ptr` when ownership needs to be shared.

- ✅ Use `weak_ptr` to observe a `shared_ptr` without preventing object destruction.

- ✅ Always use `virtual` destructors for polymorphic base classes.

- ⚠️ Be cautious of circular references with `shared_ptr`.

## Polymorphic objects stored in Collections 

### References and Arrays
- C++ References are not left assignable (reassignable), i.e. once a reference is initialized to an object, it cannot be changed to refer to another object.
- In C++, references are not reassignable—once a reference is initialized to an object, it cannot be changed to refer to another object.
- Attempting to "reassign" a reference actually modifies the object it refers to, not the reference itself.
- You cannot create an array of references, because references do not occupy independent storage and cannot be default-initialized like objects or pointers.

### Object Slicing in Arrays
- When derived class objects are stored in an array of base class type (by value), only the base class portion is copied, and the derived part is sliced off—this is known as object slicing.
- As a result, virtual functions will not behave polymorphically, because the derived part no longer exists in the base-class copy.

  ```cpp
  Circle circle1(3.14, "circle1");
  Oval   oval1(6.6, 4.5, "oval1");
  Circle circle2(10, "circle2");
  Oval   oval2(2.2, 4.4, "oval2");
  Circle circle3(8, "circle3");
  Oval   oval3(1.1, 9.9, "oval3");
  
  // Object slicing occurs here
  Shape shape_array[] = {circle1, circle2, circle3, oval1, oval2, oval3};
  for (Shape& shape : shape_array) {
      shape.draw();  // Will call Shape::draw(), not Circle/Oval::draw()
  }
  ```

### Raw Pointers with Polymorphism
- Virtual functions in C++ are designed to work properly when accessed through base class pointers or references.
- This allows true polymorphic behavior, where the actual method invoked depends on the dynamic type of the object, not the static type of the pointer.

  ```cpp
  std::cout << "\n------------------ Polymorphism using Raw Pointers -------------------\n";
  
  Shape* s_ptr[] = {&circle1, &circle2, &circle3, &oval1, &oval2, &oval3};
  
  for (Shape* ptr : s_ptr) {
      std::cout << "\nInside array: sizeof(*ptr) : " << sizeof(*ptr) << std::endl;
      ptr->draw();  // Correctly resolves to derived class draw() due to virtual dispatch
  }
  ```

### Smart Pointers with Polymorphism
- Smart pointers like `std::shared_ptr` and `std::unique_ptr` can also be used to store polymorphic objects without slicing.
- This is especially useful in modern C++ as it provides **automatic memory management** and ensures no **memory leaks**.

  ```cpp
  std::cout << "\n------------------ Polymorphism using Smart Pointers -------------------\n";
  
  std::shared_ptr<Shape> sha_ptr_arr[] = {
      std::make_shared<Circle>(20, "circle20"),
      std::make_shared<Circle>(30, "circle30"),
      std::make_shared<Oval>(10, 20, "oval12"),
      std::make_shared<Oval>(20, 30, "oval23")
  };
  
  for (const auto& s : sha_ptr_arr) {
      s->draw();  // Correctly calls draw() of derived class due to virtual functions
  }
  ```
### `"Override"` keyword  
- The `'override'` keyword in C++ inheritance, is used to indicate that a member function in a derived class is meant to override a virtual function in a base class. 

- This provides better compile-time checking and helps avoid mistakes such as misspelling the function name or mismatching the function signature.
      
- Benefits of override:
  
  1. **Compile-time safety** :  
  The compiler checks if a function is correctly overriding a virtual function. If the base class function is not virtual, or if the signatures don’t match, the compiler will throw an error.

  2. **Error prevention** :  
  Without override, a mistake like a misspelled function name or mismatched parameter list would silently define a new function in the derived class, leading to unexpected behavior.

- Example 🧮 
  ```cpp
  class Shape {
  public:
      virtual void draw() const {
          std::cout << "Drawing Shape\n";
      }
  };
  
  class Circle : public Shape {
  public:
      void draw() const override {  // Correct override
          std::cout << "Drawing Circle\n";
      }
  };
  ```
- It is always advised to use the 'override' keyword while declaring virtual functions to explicitly tell the compiler that we want to override the method from base class with exact signature with the method in derived class.  

## Overloading, Overriding and hiding  

### Overriding
- Occurs when a virtual function in a base class is **redefined** in a derived class with the **same signature**.
- Virtual dispatch ensures that the derived version is called when accessed through a base pointer or reference.

### Overloading
- Overloading occurs **when multiple functions have the same name** but different parameter types or counts **within the same scope**.

### Name Hiding
- If a derived class **declares a function with the same name as a function in the base class**, the base class versions become **hidden**, even if their signatures differ.
- You must bring base class overloads into scope using a `using` declaration if you want to retain access.

  ```cpp
  class Shape {
  public:
      virtual void draw() const {
          std::cout << "Shape::draw()\n";
      }
  
      virtual void draw(int) const {
          std::cout << "Shape::draw(int)\n";
      }
  };
  
  class Oval : public Shape {
  public:
      using Shape::draw;  // Prevent hiding of base class overloads
  
      void draw() const override {
          std::cout << "Oval::draw()\n";
      }
  };
  ```

### Slicing and Virtual Functions
- If you assign a derived class object by value to a base class variable, the derived part is sliced, and only base class functions can be called—even if they're virtual.

  ```cpp
  Circle c1(4.4, "circle1");
  Shape s1 = c1;    // Object slicing occurs
  s1.draw();        // Calls Shape::draw(), not Circle::draw()
  ```

## Inheritance and Polymorphism at different levels  

- If a class contains **at least one virtual function**, it's good practice to declare its **destructor** as `virtual`. 
- This ensures proper destruction of derived objects when deleted via base class pointers.

- You cannot store a base class object in a pointer to a derived class:

  ```cpp
  Base b;
  Derived* d_ptr = &b;    // ❌ Invalid: Base-to-Derived conversion is not allowed
  ```

- However, you can store a derived class object in a pointer to a base class:

  ```cpp
  Derived d;
  Base* b_ptr = &d;       // ✅ Valid: Polymorphic behavior via base pointer
  ```

- When you create an array of derived class pointers, you cannot store a pointer to a base class object:

  ```cpp
  Base b;
  Derived* arr[] = { &b };  // ❌ Error
  ```

- **Polymorphic behavior works only when accessed through base class pointers or references**. 
- If you have a base class object (not a reference or pointer), the virtual mechanism is bypassed due to object slicing.
- If a polymorphism is created in derived class then it is not available in the base class objects.

## Inheritance and Polymorphism with Static Members
- **Static members** are shared across all instances of a class, including derived classes.
- They are **inherited**, but they are not tied to any specific object, so they `do not participate in polymorphism`.
- Static members can be accessed using either the base or derived class name:

  ```cpp
  class Base {
  public:
      static int count;
  };
  
  class Derived : public Base {};
  
  int Base::count = 0;
  
  Base::count = 5;
  Derived::count = 10;  // Same static variable, shared across the hierarchy
  ```

## The `'final'` specifier in Inheritance 

### 1. Preventing Method Overriding with `final`
- You can prevent further overriding of a **virtual function** by marking it `final` in a derived class:

  ```cpp
  class Feline {
  public:
      virtual void run() const {
          std::cout << "Feline::run()\n";
      }
  };
  
  class Dog : public Feline {
  public:
      void run() const override final {
          std::cout << "Dog::run() called\n";
      }
  };
  
  class Bulldog : public Dog {
  public:
      void run() const override {  // ❌ Compilation error: run() is final in Dog
      }
  };
  ```
- The `run()` method can not be overrided in derived classes of 'Dog' class as it is declared as `'final'`.

### 2. Preventing Inheritance with final
- Marking a class final prevents it from being inherited.

  ```cpp
  class Cat final: public Feline{
      public:
          Cat() = default;
      
          // Although virtual, miaw() cannot be overridden since Cat is final
          virtual void miaw() const{
            std::cout << "Cat::miaw() called for Cat. " << m_description << std::endl;
          }
      
          // As the following run() method is declared as 'override'. It is overriding the virtual method 
          // from 'Feline' class, so it is useful.
          virtual void run() const override{
            std::cout << "Cat::run() called\n"; 
          }
  };
  
  // As 'Cat' class is declared as 'final', no other class can be inherited from 'Cat' class.
  // ❌ Error: Cannot inherit from final class 'Cat'
  class PersianCat : public Cat {};  // Compilation error
  ```
          
### Example of `final lone` class.

  ```cpp
  class Plane final {
    public:
      Plane() = default;
  };
  
  // ❌ Error: Cannot derive from final class 'Plane'
  class FighterJet : public Plane {
  public:
      FighterJet() = default;
  };
  ```

### 4. Interaction Between `virtual` and `final`
- The `virtual` keyword indicates that a function **can be overridden** in derived classes.
- The `final` keyword means **no further overriding** is allowed.
- While these seem contradictory, they are often used **together** when you want a derived class to override a function, but disallow further overrides:

  ```cpp
  class Base {
  public:
      virtual void foo() const;
  };
  
  class Intermediate : public Base {
  public:
      void foo() const override final;  // Override allowed here, but no further
  };
  ```
- In such cases, `final` takes precedence and prevents further specialization beyond the current level.

## Virtual Functions with Default Arguments

- **Default arguments** are resolved **at compile time**, based on the static type of the pointer or reference used to call the function.

- **Virtual function dispatch** (i.e. dynamic binding of the actual function implementation) happens at runtime, based on the **dynamic type** of the object.

- This mismatch between **compile-time default arguments** and **runtime function dispatch** can lead to **unexpected behavior** when using **default arguments** with **virtual functions**.
- Therefore, **using default arguments with virtual functions is discouraged**, as it can produce confusing or erroneous results.
- Default arguments with virtual functions can be very confusing. They are best if avoided.

### 🔍 Example
  ```cpp
  #include <iostream>

  class Base {
  public:
      Base();
      ~Base();
      
      virtual double add(double a = 5, double b = 5) const {
          std::cout << "Base::add() called\n";
          return a + b + 1;
      }
  };
  
  class Derived : public Base {
  public:
      Derived();
      ~Derived();
      
      double add(double a = 10, double b = 10) const override {
          std::cout << "Derived::add() called\n";
          return a + b + 2;
      }
  };
  
  int main() {
      Derived d;
      Base* ptr = &d;
      std::cout << ptr->add() << "\n";  // Output: Derived::add() called, but uses default args from Base!
  }
  ```

### ⚠️ Output Explanation:
- `ptr->add()` calls the Derived version of `add()` due to virtual dispatch.
- However, the default arguments `(5, 5)` are used — because `ptr` is of static type `Base*`.
- Result = `5 + 5 + 2 = 12`


### **💡 Recommendation**: 
- Avoid default arguments in virtual functions. Prefer overloading or separate named methods for default behavior.


## Virtual destructors 

- In a polymorphic base class, the destructor should always be declared `virtual` to ensure proper cleanup of derived objects through base class pointers.

- Without a virtual destructor, deleting a derived object through a base pointer results in **undefined behavior** — typically, **only the base class destructor is called**, causing **resource leaks** or **incomplete destruction**.
- If we do not make the destructor virtual, then compiler is going to use static binding for resolving which destructor method to be called.
- In this case, if we use a **base pointer** to store **an derived class object** then compiler will call the destructor method of the base class for destroying the derived class object which is wrong.
- If we call a destructor **using a base class pointer** which is storing an **derived class object** then C++ standard says that the behavior will be undefined.

### 🔍 Example
  ```cpp
  #include <iostream>
  
  class Animal {
  public:
      virtual ~Animal() { std::cout << "Animal destructor\n"; }
  };
  
  class Feline : public Animal {
  public:
      ~Feline() { std::cout << "Feline destructor\n"; }
  };
  
  class Dog : public Feline {
  public:
      ~Dog() { std::cout << "Dog destructor\n"; }
  };
  
  int main() {
      Animal* animal = new Dog();
      delete animal;  // Calls Dog -> Feline -> Animal destructors (in this order)
  }
  ```
### ⚠️ If destructors are not virtual:
- Then only Animal's destructor will be called when delete animal is executed.

  ```cpp
  class Animal {
  public:
      ~Animal() { std::cout << "Animal destructor\n"; }  // Not virtual
  };
  ```
- Destructors for Dog and Feline will not be called ⇒ Memory/resource leak

### ✅ Rule: 
- If a class has at least one virtual function, make its destructor virtual — even if it's empty or defaulted.


## `Dynamic_cast<>()` in C++

### What is dynamic_cast?
- `dynamic_cast` is a C++ operator that performs **safe downcasting** between pointers or references in a polymorphic **class hierarchy** (i.e., at least one virtual function in the base class).

- Using dynamic cast we are able to convert any base class pointer to the derived class object pointer and use it as an raw object pointer.
- Using dynamic cast we convert the base class pointer to the derived class object and access non polymorphic methods.
- It enables **runtime type checking**, ensuring that the cast is valid, and **returns** `nullptr` (for pointers) if the cast fails.
- Usually, dynamic casting is done in functions which accept a base class pointer.
- Here is our class hierarchy
  
    ```
    Animal - Feline - Dog
    ```

- If an Animal class pointer is pointing to the 'Feline' class object then this pointer can be dynamically casted to Feline class pointer but can not be cast into 'Dog' class pointer.


### Key Features
- Used to safely cast a base class pointer/reference to a derived class type.

- Works only with polymorphic types (i.e. the base class must have at least one virtual method).
- Can also be used with references, but will throw a std::bad_cast exception if the cast fails.
- Dynamic cast enables following two facilities -
  1. Transforming from base class pointer/reference to derived class pointer/reference, at runtime.
  2. Makes it possible to call non polymorphic methods on derived pointer/references.

### 🧱 Class Hierarchy Example
  ```cpp
  #include <iostream>
  #include <memory>
  #include <typeinfo>
  
  class Animal {
  public:
      virtual void speak() const {
          std::cout << "Animal speaks\n";
      }
      virtual ~Animal() = default;
  };
  
  class Feline : public Animal {
  public:
      void speak() const override {
          std::cout << "Feline meows\n";
      }
      void purr() const {
          std::cout << "Feline purrs\n";
      }
  };
  
  class Dog : public Animal {
  public:
      void speak() const override {
          std::cout << "Dog barks\n";
      }
      void wagTail() const {
          std::cout << "Dog wags tail\n";
      }
  };
  ```

### 🎯 Using dynamic_cast with Pointers
  ```cpp
  void checkAnimal(Animal* animal_ptr) {
      if (Feline* feline_ptr = dynamic_cast<Feline*>(animal_ptr)) {
          std::cout << "This is a Feline.\n";
          feline_ptr->purr(); // Call method specific to Feline
      } 
      else if (Dog* dog_ptr = dynamic_cast<Dog*>(animal_ptr)) {
          std::cout << "This is a Dog.\n";
          dog_ptr->wagTail(); // Call method specific to Dog
      } 
      else {
          std::cout << "Unknown Animal type.\n";
      }
  }
  ```
### 📦 Main Usage
  ```cpp
  int main() {
      Animal* a1 = new Feline();
      Animal* a2 = new Dog();
  
      checkAnimal(a1);
      checkAnimal(a2);
  
      delete a1;
      delete a2;
      return 0;
  }
  ```

### ❗ Important Notes
- `dynamic_cast` works **only with polymorphic types** (i.e., classes with at least one virtual function).
- If you use `dynamic_cast` with **non-polymorphic types**, you will get a **compile-time error**.
- This **will not work for inbuilt data** types like `char`, `int`, `double` etc.
- **Avoid overusing** `dynamic_cast`. It can be a code smell. Instead, prefer using **virtual functions** to achieve polymorphic behavior.
- Overusing, down casts is a sign of bad design, if you find yourself doing this a lot to call non polymorphic methods on derived objects, may be you should make that function polymorphic in the first place. 

### ✅ Summary
-
  | Cast Type	          | Description                                                          |
  | -----------------   | -------------------------------------------------------------------- |
  | `dynamic_cast`	    | Safe downcast with runtime check (works only with polymorphic types) |
  | `static_cast`	      | No runtime check, faster, but unsafe if cast is incorrect            |
  | `reinterpret_cast`	| Bit-level casting; very unsafe and implementation-defined            |
  | `const_cast`	      | Used to add or remove `const` qualifier                                |

- 🔒 Use `dynamic_cast` when you must determine the actual derived type at runtime, but use **virtual functions** whenever possible for extensibility and maintainability.

## 🛑 Never Call Virtual (Polymorphic) Functions from Constructors or Destructors
### 🔁 Constructor and Destructor Call Order
  ```text
  Base Constructor
  Derived Constructor
     // Use constructed object
  Derived Destructor
  Base Destructor
  ```
### ⚠️ Why Avoid Calling Virtual Functions from Constructors or Destructors?
- When a constructor or destructor is running, the virtual table (vtable) of the most derived class is not fully set up (in the constructor) or already torn down (in the destructor).

- As a result, calls to virtual functions inside constructors or destructors will not resolve to derived class overrides. They will be statically bound to the currently executing class.

### 🧠 Key Takeaways
- No dynamic dispatch during base constructor or base destructor.
- If a base constructor calls a virtual method, it will only invoke the version defined in the base class—even if a derived override exists.
- Similarly, if a base destructor calls a virtual function, it won't reach any override in the derived class, since the derived portion of the object has already been destroyed.
- ✅ If you need polymorphic behavior, call the virtual method after construction is complete, typically outside the constructor.

## 🧱 Pure Virtual Functions and Abstract Classes
### 🎯 What is a Pure Virtual Function?
- A **pure virtual function** is declared using the `= 0` syntax:
 
  ```cpp
  class Shape {
  public:
      virtual void draw() const = 0; // Pure virtual
  };
  ```

### 📌 Abstract Classes
- A class becomes an **abstract class** if it has **at least one pure virtual function**.
- You **cannot create objects** of an abstract class. Doing so results in a **compile-time error**.
- Any derived class **must override all pure virtual functions** from its base abstract class. If it doesn't, it also remains abstract.

### 🧱 Constructors and Pure Virtual Functions
- You **can define a constructor** in an abstract class.
- However, you **cannot call a pure virtual function from the abstract class’s constructor**, because the derived class portion is not yet constructed.
- The constructor of an abstract class is used by deriving class to build up the base part of the object.

## 🔌 Abstract Classes as Interfaces
### 💡 Interface Concept in C++
- An abstract class with :
  - **Only pure virtual functions**
  - **No data members** ... can be used as an interface, similar to `Java` or `C#`.

### 📌 Purpose of Interfaces
- An interface defines `a contract` — a set of behaviors or specification of something that must be implemented by any derived class.
- It provides a clean way to model **polymorphism** without enforcing implementation.
- An interface is a thing that we can attach to a data type to give it a super power or features that they originally did not have.

### 📦 Example of an Interface
  ```cpp
  class Drawable {                    // 'Drawable' is an interface.
  public:
      virtual void draw() const = 0;
      virtual ~Drawable() = default;
  };
  
  class Circle : public Drawable {    // 'Circle' is a concrete class implementing the interface.
  public:
      void draw() const override {
          std::cout << "Drawing a circle\n";
      }
  };
  ```
#### 📢 Think of interfaces as `capabilities` you can attach to types — similar to giving an object a "superpower" by ensuring it follows a specific behavioral contract.


## 21. typeid() in C++
- In C++, the `typeid` operator is part of the **Run-Time Type Information (RTTI)** system.
- It is used to determine the **type of an expression** at runtime.
- The result of `typeid` is a reference to a `const std::type_info` object, defined in the `<typeinfo>` header.

### ✅ Key Features of `typeid`:
  1. Can be used to query the type of **built-in** and **user-defined** types.
  2. Especially useful with **polymorphic types** (classes with virtual functions) to get the dynamic type of an object.
  3. It is especially useful when working with polymorphism to determine the dynamic type of a base class pointer/reference when pointing to a derived class object.
  4. Returns a `std::type_info` object which can be queried using `.name()`.
  5. Supports type comparisons using `==` and `!=` operators.


###	Syntax 
 
  ```cpp
  typeid(expression)
  ```

### Requirements:
1. If the expression is **not polymorphic** (i.e., does not involve virtual functions), `typeid` returns the **static type** (the type determined at compile-time).

2. If the expression is polymorphic (involving virtual functions) and evaluated through a **pointer or reference**, `typeid` returns the **dynamic type** (the type determined at runtime).


### Example 1: Basic Usage

  ```cpp
  #include <iostream>
  #include <typeinfo>  // Required for typeid and std::type_info

  int main() {
      int a = 5;
      double b = 3.14;

      std::cout << "Type of a: " << typeid(a).name() << std::endl;
      std::cout << "Type of b: " << typeid(b).name() << std::endl;

      return 0;
  }
  ```
#### Output (compiler-specific) :  
  ```pgsql
  Type of a: i  // 'i' represents int
  Type of b: d  // 'd' represents double
  
  // The output format for the type name (name()) is implementation-specific, so the exact string you get may vary between compilers.
  ```

### Example 2: 	`typeid` with Polymorphism

  ```cpp
  // typeid is often used with polymorphic types (classes with virtual functions) to determine the dynamic type of an object.

  #include <iostream>
  #include <typeinfo>  // Required for typeid and std::type_info
  
  class Base {
  public:
      virtual ~Base() {}  // Necessary for RTTI to work correctly
  };
  
  class Derived : public Base {};
  
  int main() {
      Base* basePtr = new Derived();
  
      // Static type: the type that the pointer is declared as
      std::cout << "Static type of basePtr: " << typeid(basePtr).name() << std::endl;
  
      // Dynamic type: the actual type of the object the pointer is pointing to
      std::cout << "Dynamic type of *basePtr: " << typeid(*basePtr).name() << std::endl;
  
      delete basePtr;
      return 0;
  }
  ```
#### Output (compiler-specific):
  ```pgsql
    Static type of basePtr: P4Base  			// 'P4Base' represents pointer to Base
    Dynamic type of *basePtr: 7Derived  	// '7Derived' represents Derived
  ```
- In this example:
  - typeid(basePtr)  returns the static type, which is Base*.
  - typeid(*basePtr) returns the dynamic type (Derived), because basePtr is actually pointing to a Derived object.

### Example 3: Comparing Types
  
  ```cpp
  #include <iostream>
  #include <typeinfo>

  int main() {
      int a = 10;
      double b = 10.5;
      
      if (typeid(a) == typeid(b)) {
          std::cout << "a and b are of the same type" << std::endl;
      } else {
          std::cout << "a and b are of different types" << std::endl;
      }
    
    return 0;
  }
  ```
#### Output  
  ```pgsql
	a and b are of different types
  ```

### 🔍 Notes and Caveats of `typeid` :
#### 1. Polymorphic Types    	
- When used with polymorphic types (i.e., types that have at least one virtual function), typeid returns the dynamic type of the object.
- If a Base class pointer points to a Derived class object, `typeid(*ptr)` will return Derived, if Base has a virtual function.

#### 2. Non-polymorphic Types   
- If no virtual function is defined, the type is evaluated statically (at compile time).

#### 3. Return Type: 
- The result of `typeid` is an object of type `std::type_info&`. 
- It has the following useful methods:
  - `.name()` - returns an implementation-specific string representation of the type.
- Operators such as '==' and '!=' can be used to compare two std::type_info objects 

  ```cpp
  if (typeid(*ptr1) == typeid(Derived)) { ... }
  ```

#### 4. Compiler-Dependent Output
- The string returned by `.name()` is not standardized and may vary between compilers (e.g., GCC, MSVC, Clang).
- To get a human-readable string, demangling might be required (platform-specific).


### Use Cases of typeid:
1. **Polymorphism**  
  When working with base class pointers that may point to derived class objects, typeid allows you to query the actual type of the object.
    
2. **Debugging and Logging**  
  You can use typeid to log or display the types of variables or objects during development.
    
3. **Generic Programming**  
  In template-based code, typeid can be used to query types for debugging or conditional logic based on types.
    
4. **Sanity Checks**  
  Avoid incorrect casting or use of objects by confirming type at runtime.

### ✅ Demangled Example of typeid with Polymorphism
```cpp
#include <iostream>
#include <typeinfo>
#include <cxxabi.h>     // Required for abi::__cxa_demangle
#include <memory>       // For smart pointer to manage demangled name buffer

class Base {
public:
    virtual ~Base() {}  // Required for RTTI
};

class Derived : public Base {};

std::string demangle(const char* mangled_name) {
    int status = 0;
    char* demangled = abi::__cxa_demangle(mangled_name, nullptr, nullptr, &status);
    
    // Wrap the raw pointer in a smart pointer to avoid memory leaks
    std::unique_ptr<char, void(*)(void*)> result(demangled, std::free);
    
    return (status == 0 && demangled != nullptr) ? result.get() : mangled_name;
}

int main() {
    Base* ptr = new Derived();

    // Static type (of the pointer)
    std::cout << "Static type: " << demangle(typeid(ptr).name()) << std::endl;

    // Dynamic type (of the actual object)
    std::cout << "Dynamic type: " << demangle(typeid(*ptr).name()) << std::endl;

    delete ptr;
    return 0;
}
```

#### 🔍 Output (on GCC/Clang)
```bash
Static type: Base*
Dynamic type: Derived
```

#### 📝 Notes:
- The function `abi::__cxa_demangle()` is part of the Itanium C++ ABI and is available in GCC and Clang, but not in MSVC.
- We wrap the returned `char*` in a `std::unique_ptr` with `std::free` as the deleter to ensure no memory leaks.

