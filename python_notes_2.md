
# [Harvard CS50's Introduction to Programming with Python](https://www.youtube.com/watch?v=nLRL_NcnK-4&t=46858s) 

### [Video Link](https://www.youtube.com/watch?v=nLRL_NcnK-4&t=46858s)

## 1. Python Functions
  - Python Functions must be defined before their use (above the line of usage)
  - However, the following example will not throw any error as hello() function is not called until main() function is called
    and main() function is called at the end of the file.
    ```python
    def main():
      name = input('Please enter your name - ')
      hello(name)

    def hello(name):
      print('Hello, {name}!')

    main()
    ```

## 2. Conditional Statements

  ```python
  x = int(input('what is x ? '))
  y = int(input('what is y ? '))

  if x > y:
    print('x is greater than y')
  elif x < y:
    print('y is greater than x')
  else:
    print('x is equal to y')

  if 4 < x > 5:
    print('x is between 4 and 5')
  ```

## 3. match/Switch statement in Python 
  ```python
  name = input('Please enter your name - ')
  match name:
      case 'Harry' or 'Hermione' or 'Ron':
          print('Gryffindor')
      case 'Draco':
          print('Slytherin')
      case '_':
          print('Homeless')
  ```

## 4. `None` keyword
  - In Python, 'None' keyword is used to indicate absence of a value. 
  - It is somewhat equivalent of 'void' or 'null' in C++

## 5. `statistics` module in Python 
  - The statistics module in Python provides functions for calculating mathematical statistics of numeric data. 
  - Here are some examples of functions from the statistics module:

    ```python
    # 1. mean(data): Calculates the arithmetic mean (average) of the given data.

      import statistics
      data = [10, 20, 30, 40, 50]
      print(statistics.mean(data))            # Output: 30

    #2. median(data): Returns the median (middle value) of the data.

      import statistics
      data = [10, 20, 30, 40, 50]
      print(statistics.median(data))          # Output: 30

    #3. mode(data): Returns the most common data point from discrete or nominal data.

      import statistics
      data = [1, 2, 2, 3, 4]
      print(statistics.mode(data))            # Output: 2

    #4. stdev(data): Calculates the standard deviation of the given data, a measure of the amount of variation or dispersion.

      import statistics
      data = [10, 20, 30, 40, 50]
      print(statistics.stdev(data))           # Output: 15.811388300841896

    #5. variance(data): Returns the variance of the data, a measure of how far the data points are spread out.

      import statistics
      data = [10, 20, 30, 40, 50]
      print(statistics.variance(data))        # Output: 250.0

    #6. pstdev(data): Calculates the population standard deviation of the data.

      import statistics
      data = [10, 20, 30, 40, 50]
      print(statistics.pstdev(data))          # Output: 14.142135623730951

    #7. pvariance(data): Returns the population variance of the data.

      import statistics
      data = [10, 20, 30, 40, 50]
      print(statistics.pvariance(data))       # Output: 200.0

    #8. harmonic_mean(data): Calculates the harmonic mean of the data.

      import statistics
      data = [1, 2, 3, 4, 5]
      print(statistics.harmonic_mean(data))   # Output: 2.18978102189781

    #9. median_low(data): Returns the low median of the data (the smaller of the two middle values).

      import statistics
      data = [10, 20, 30, 40, 50]
      print(statistics.median_low(data))      # Output: 30

    #10. median_high(data): Returns the high median of the data (the larger of the two middle values).

      import statistics
      data = [10, 20, 30, 40, 50]
      print(statistics.median_high(data))     # Output: 30

    # These functions are very useful for performing basic statistical operations on data without needing to write the algorithms from scratch.
    ```

  ## 6. sys.argv in Python
  - In Python, sys.argv contains the list of command line arguments. sys.argv[0] contains the name of the script to be run. 
  - Subsequent elements are the additional arguments that are passed to the script.
    ```python
    import sys
    # Check if the correct number of arguments is provided
    if len(sys.argv) != 3:
        print("Usage: python greet.py <first_name> <last_name>")
        sys.exit(1)               # Exit the script with an error code

    # Retrieve the command-line arguments
    first_name = sys.argv[1]
    last_name = sys.argv[2]

    # Print a greeting message
    print(f"Hello, {first_name} {last_name}!")
    ```
  - Run following command on command line
    
    ```python
    python greet.py John Doe
    sys.exit()                    # will exit the program.
    len(sys.argv)                 # will return the number of arguments
    ```
  - Iterating over the arguments 
    
    ```python
    for arg in sys.argv[1:]
      print(arg)
    ```

  ## 7. 'requests' library in Python
  ```python
  import sys
  import requests
  import json
 
  response = requests.get('https://itunes.apple.com/search?entity=song&limit=1&term=' + sys.argv[1])
  print(response.json())
  print(json.dumps(response.json(), indent=2))    # json is a library which provides dumps() function which can be used 
                                                  # for pretty printing the json output data.
  ```

  ## 8. Library in Python
  - If you want to make a program as an library then you need to put all the function calls in that program inside the 
    "if __name__ == __main__:" block so that the these functions will not get called unnecessarily when the library is
    imported inside another program.

  ## 9. Unit Tests in Python
  - 'pytest' is a program that is used to run the test suite written in python.
  
    ```python
    # --------------- calculator.py --------------- 
      def main():
        x = int(input("What is x ?"))
        print('x Squared is ' + square(x))

      def square(x):
        return x*x 

      if __name__ == '__main__':
        main()  

    # --------------- test_calculator.py v1 - Trying to handle the exception on our own --------------- 
      from calculator import square
      def main():
        test_square()

      def test_square():
        try:
          assert square(1) == 1
        except AssertionError:
          print(" '1' squared is not equal to '1'")

        assert square(2) == 4
        assert square(-3) == 9

      if __name__ == '__main__':
        main()

    # --------------- test_calculator.py v2 - Single testcase encompassing all the tests --------------- 
      from calculator import square
      def main():
        test_square()

      def test_positive():
        assert square(0) == 0
        assert square(1) == 1
        assert square(3) == 9
        assert square(-1) == 1
        assert square(-2) == 4

      if __name__ == '__main__':
        main()

    # --------------- test_calculator.py v3 - Creating 3 different test cases --------------- 
      from calculator import square
      def main():
        test_square()

      def test_positive():
        assert square(1) == 1
        assert square(3) == 9

      def test_negative():
        assert square(-1) == 1
        assert square(-2) == 4

      def test_zero():
        assert square(0) == 0

      if __name__ == '__main__':
        main()

    # --------------- How to run tests --------------- 
      pytest test_calculator.py 
    ```

  ## 10. File I/O in Python
  - open() will open the file in specified path (by default the directory of the program file) and return the handle. 
    
    ```python 
    file = open("names.txt", "w")
    file.write("My First line")
    file.close()
    ``` 

  - There are three modes to open the file, a - append; w - write; and r - read mode.
  - Please note to close() the file explicitly.
  - If you want the file to get closed automatically after your work use 'with' syntax
    ```python
    with open("names.txt", "w") as file:
      file.write("My First line")

    (OR)
    l = ['Ram', 'Shyam', 'Tata', 'Bye Bye']
    f = open("names1.txt", "w") 
    for item in l:
        f.write(item + "\n")
    f.close()

    (OR) -- Reading text from the file
    l = []
    with open("names2.txt", "r") as file:
      for line in file:
        l.append(line.strip())
    
    for name in sorted(l) :
      print(f'Hello, {name}')
    ```
  - As soon as the control comes out of the scope of the 'with' block, file will get closed


  ## 11. Handling .csv files in Python
  - If students.csv file contains comma separated list of student names and their house names, this can be parsed as follows
    using file i/o 
    
    ```python
    with open('student.csv', 'r') as file:
      for line in file:
        name, house = line.strip().split(',')
        print(f'{name} lives in {house}')
    ```
  - csv reader approach
    ```python
    import csv
    with open('student.csv', 'r') as file:
      reader = csv.reader(file)
      for line in reader:
        if line.strip() :
          name, house = line[0], line[1]
          print(f'{name} lives in {house}')
    ```

  - csv DictReader - If first line of the csv file contains header names then 'DictReader' can be used which returns dictionary 
    for each line

    ```python 
    import csv
    with open('student.csv', 'r') as file:
      reader = csv.DictReader(file)
      for line in reader:
        print(f"{line['Name']} lives in {line['Home']}")
    ```

  - csv DictWriter - Makes it easy to write the data to a file in the form of a dictionary.
    ```python
    with open('student.csv', 'a') as file:
      writer = csv.DictWriter(file, fieldnames= ["Name", "Home"])
      writer.writerow({"Name":"Sachin", "Home":"MP"})
    ```
  ## 12. walrus operator (:=) in Python
  - Walrus operator identifier (:=) in Python, is used to assign the value of an expression to a variable and also check whether the assigned value is non zero or not.

    ```python
    import re
    text: str = 'Dog, Barks'
    reg = r'(.*),\s+(.*)'
    if res := re.search(text, reg)
      print(f"{res.group(1) is an animal which {res.group(2)}")
    ```

  ## 13. `classes` in Python
  
  -  '__init__()' method is used to initialize the class object also known as initialization of instance variables 

      ```python
      __init__(self, name, age):
        if not name:
          raise ValueError("Missing Name")
        if not 18 < age > 68:
          raise ValueError("Age not in the range [18, 68]") 
        self.age = age
        self.name = name
      ```
  
  -  **def __str__(self)**  
    The `__str__` method is a standard method which is called when we try to print the object with the help of just its name.
    By default it takes 'self' as the first argument
      
      ```python
        class Student:
          def __init__(self, name, age):
            self.name = name
            self.age = age

          def __str__(self):
            return f'{self.name} is a student and is {self.age} years old'
      ```

  ## 13. Getter, setter function in python -
  - Even through the Python language does not have the concept of private and public variables i.e. all the variables are public. there is a work around to hide variables and make them look private using decorators. 
  - Please note that python do not enforce privateness of the variables. 
  - It is just an honor system and is based on hiding real variable names form the user.
    
    ```python
    class Student:
      def __init__(self, name, age):
        self.name = name
        self.age = age

      @property                    # specifies to python that this is an getter function
      def name(self):
        return self._name

      @name.setter                 # specifies to python that this is a setter function
      def name(self, name):
        if not name in ['John', 'Jenny', 'James'] :
          raise ValueError('Name is not from specified set of names!')
        self._name = name
  
      @property                   # specifies to python that this is an getter function
      def age(self):
        return self._age

      @age.setter                 # specifies to python that this is a setter function
      def age(self, age):
        if 18 < age> 65:
          raise ValueError('Age is not in range')
        self._age = age

    def main():
      stud = Student('John', 32)

    if __name__ == '__main__':
      main()
    ```

  ## 14. Operator Overloading
  
  - Operator overloading allows custom objects to define the behavior of Python's built-in operators when they interact with instances of these custom objects. 
  
  - This makes it possible to use operators like +, -, *, and others with objects of a custom class, in a way that is intuitive and similar to how those operators are used with built-in types (like integers, strings, etc.).

  - Key Points:
    ```
    Magic Methods : Python provides special methods, also known as "magic methods" or "dunder methods" 
                  : (because they have double underscores before and after their names), that can be overridden to define how operators 
                  : behave with objects of a custom class.
    ```
  
  - Common Magic Methods for Operator Overloading:

    | Methods                   | Description                                                         |
    | --------------------------|-------------------------------------------------------------------  |
    | __add__(self, other)      | Defines the behavior of the + operator.                             |
    | __sub__(self, other)      | Defines the behavior of the - operator.                             |
    | __mul__(self, other)      | Defines the behavior of the * operator.                             |
    | __truediv__(self, other)  | Defines the behavior of the / operator.                             |
    | __floordiv__(self, other) | Defines the behavior of the // operator.                            |
    | __mod__(self, other)      | Defines the behavior of the % operator.                             |
    | __pow__(self, other)      | Defines the behavior of the ** operator.                            |
    | __lt__(self, other)       | Defines the behavior of the < (less than) operator.                 |
    | __le__(self, other)       | Defines the behavior of the <= (less than or equal to) operator.    |
    | __eq__(self, other)       | Defines the behavior of the == (equal to) operator.                 |
    | __ne__(self, other)       | Defines the behavior of the != (not equal to) operator.             |
    | __gt__(self, other)       | Defines the behavior of the > (greater than) operator.              |
    | __ge__(self, other)       | Defines the behavior of the >= (greater than or equal to) operator. |


  - **Example of Operator Overloading**  
  
    Let's define a simple class Vector that represents a vector in 2D space and overload some operators for it.

      ```python
        class Vector:
          def __init__(self, x, y):
              self.x = x
              self.y = y

          def __add__(self, other):
              return Vector(self.x + other.x, self.y + other.y)

          def __sub__(self, other):
              return Vector(self.x - other.x, self.y - other.y)

          def __mul__(self, scalar):
              return Vector(self.x * scalar, self.y * scalar)

          def __eq__(self, other):
              return self.x == other.x and self.y == other.y

          def __str__(self):
              return f"Vector({self.x}, {self.y})"

        # Creating two vectors
        v1 = Vector(2, 3)
        v2 = Vector(4, 1)

        # Using the overloaded + operator
        v3 = v1 + v2
        print(v3)         # Output: Vector(6, 4)

        # Using the overloaded - operator
        v4 = v1 - v2
        print(v4)         # Output: Vector(-2, 2)

        # Using the overloaded * operator
        v5 = v1 * 3
        print(v5)         # Output: Vector(6, 9)

        # Using the overloaded == operator
        print(v1 == v2)   # Output: False
    ```

  ## 15.  'Global' keyword in Python 
  - The global keyword in Python is used to declare that a variable inside a function is global, meaning it refers to a 
    variable that is defined outside of the function. Without the global keyword, a variable assigned within a function 
    is treated as a local variable by default.

  - Key Concepts:
    ```
    Global vs Local Variables:
    Global Variables  : These are variables that are defined outside any function, and they can be accessed from any function
                        within the same module.
    Local Variables   : These are variables that are defined within a function and can only be accessed inside that function.
    ```

  - Why Use global ?
    ```
    The global keyword is used when you need to modify a global variable inside a function. By default, if you assign a value 
    to a variable inside a function, Python treats that variable as a local variable. If you try to modify a global variable 
    without declaring it as global, Python will raise an error.
    ```

  - How global Works ?
    ```
    When you declare a variable as global inside a function, you're telling Python that the variable should not be treated as 
    local, but rather as a reference to the variable that exists in the global scope.
    ```
    ```python
    # Example 1: using the 'global' keyword
      x = 10  # Global variable

      def modify_global():
          global x                      # Declare x as global
          x = 20                        # Modify the global variable
          print(f"Inside function: x = {x}")

      modify_global()
      print(f"Outside function: x = {x}")

                                        # Output:
                                        # Inside function: x = 20
                                        # Outside function: x = 20

    # Example 2: Without using the 'global' keyword

      y = 5                             # Global variable

      def modify_local():
        y = 15                          # Local variable (does not affect the global y)
        print(f"Inside function: y = {y}")

      modify_local()
      print(f"Outside function: y = {y}")

                                        # Output:
                                        #   Inside function: y = 15
                                        #   Outside function: y = 5

    #  Multiple variables can also be declared as global at the same time
      global a, b                       # Declare both a and b as global
    ```
  
  ## 16. Constants in Python 
  - Python does not support constant keyword or variables.
  - By convention, the constant variable names contain all capital letters However it is not enforced by the Python, it means that these variables can be updated 
    
    ```python 
    TIMES = 3

    def meaw(TIMES):
      print('Meaw' * TIMES)

    meaw()
    ```

  ## 17. Python documentation  
  - This is how the functions in Python are documented
  
    ```python
    TIMES = 3
    def meaw(n: int) -> str:
      '''
        Meow n times
        :param n: number of times
        :type n: int
        :raise TypeError: if n is not an integer
        :return: A string of n meows, one per line
        :rtype: str
      '''
      print('Meaw' * n)

    meaw(TIMES)
    ```

  ## 18. Python argparse module  
  - The argparse module in Python is used for parsing command-line arguments. It allows you to define what arguments your 
    program requires, handles user input, and provides helpful error messages if the input is incorrect.

  - Detailed Example Using argparse
    Suppose we want to create a Python script that takes three arguments:
      1) A required positional argument: filename
      2) An optional argument with a flag:  --verbose (to print extra information)
      3) An optional argument with a value: --count (to specify the number of times a message should be printed)
      
      ```python
      import argparse
      
      # Create the parser
      parser = argparse.ArgumentParser(description="A simple script to demonstrate argparse.")
      
      # Add arguments
      parser.add_argument("filename", help="The name of the file to process.")
      parser.add_argument("--verbose", "-v", action="store_true", help="Increase output verbosity.")
      parser.add_argument("--count", "-c", type=int, default=1, help="Number of times to print the message.")
      
      # Parse the arguments
      args = parser.parse_args()
      
      # Use the arguments in the script
      if args.verbose:
          print(f"Verbose mode is on. Processing the file '{args.filename}'.")
      for i in range(args.count):
          print(f"Processing '{args.filename}'... (Iteration {i + 1})")
      if args.verbose:
          print("Processing complete.")
      ```
    
  - How to Run the Script ?
    Save the script as example.py and run it from the command line:
    ```
    1.  Without any optional arguments:  
          python example.py myfile.txt  
        Output:  
          Processing 'myfile.txt'... (Iteration 1)

    2.  With the --verbose flag:
          python example.py myfile.txt --verbose
        Output:
          Verbose mode is on. Processing the file 'myfile.txt'.
          Processing 'myfile.txt'... (Iteration 1)
          Processing complete.

    3)  With the --count argument:
          python example.py myfile.txt --count 3
        Output:
          Processing 'myfile.txt'... (Iteration 1)
          Processing 'myfile.txt'... (Iteration 2)
          Processing 'myfile.txt'... (Iteration 3)
          
    4)  With both --verbose and --count:
          python example.py myfile.txt --verbose --count 2
        Output:
          Verbose mode is on. Processing the file 'myfile.txt'.
          Processing 'myfile.txt'... (Iteration 1)
          Processing 'myfile.txt'... (Iteration 2)
          Processing complete.
    ```

  - Explanation of the Code  
    ```
        ArgumentParser    : Initializes the parser object.
        add_argument      : Defines the command-line arguments that the script accepts:
        "filename"        : A positional argument (required) that takes a string as the filename.
        "--verbose", "-v" : An optional flag that, if present, sets args.verbose to True.
        "--count", "-c"   : An optional argument that takes an integer value and defaults to 1 if not provided.
        parse_args        : Parses the command-line arguments and stores them in the args object.
        args.verbose      : This is True if the --verbose flag is provided.
        args.count        : This stores the integer value provided with the --count argument.
    
    This example demonstrates how to use argparse to handle both positional and optional command-line arguments in a 
    Python script.
    ```

  ## 19. `unpacking` in Python Module
  
  ```python 
  def total(galleons, sickles, knuts):
    return (galleons* 17 + sickles) * 29 + knuts 

  # Unpacking with the help of lists
  coins = [100, 50, 75]
  print(total(*coins))

  # Unpacking with the help of dictionaries
  coins1 = {"galleons": 100, "sickles": 50, "knuts": 75}
  print(total(**coins1))
  ```

  ## 20. `*args` and '**kwargs' in Python
  - The `*args` and `**kwargs` in Python are used to pass a variable number of arguments to a function.
  - `*args` allows you to pass a variable number of non-keyword arguments to a function and collects additional positional arguments into a tuple.

  - `**kwargs` allows you to pass a variable number of keyword arguments (i.e., arguments with names) to a function, collects additional keyword arguments into a dictionary.

  - You can use both together in a function definition, with `*args` appearing before `**kwargs`.

  - Example of `*args`
    
    ```python 
    # Let's create a function that can take any number of positional arguments and sums them up.

      def sum_numbers(*args):
        return sum(args)

      # Usage
      result = sum_numbers(1, 2, 3, 4)
      print(result)                   # Output: 10

      result = sum_numbers(5, 10, 15)
      print(result)                   # Output: 30

      # Explanation:
      #   - *args is a tuple of all the positional arguments passed to the function.
      #   - In the example above, sum_numbers(1, 2, 3, 4) passes four numbers as arguments, which are summed up inside the function.
    ```

    - Example of `**kwargs`
      ```python
      # Let's create a function that can accept any number of keyword arguments and print them.
      
      def print_details(**kwargs):
          for key, value in kwargs.items():
              print(f"{key}: {value}")

      # Usage
      print_details(name="John", age=30, city="New York")

      #  Output:
      #     name: John
      #     age: 30
      #     city: New York
      #
      #  Explanation:
      #     **kwargs is a dictionary of all the keyword arguments passed to the function.
      #     In the example above, print_details(name="John", age=30, city="New York") passes three keyword arguments. 
      #     The function then iterates over the dictionary and prints each key-value pair.
      ```

    - Combining `*args` and `**kwargs`  
      You can also combine *args and **kwargs in the same function to accept both positional and keyword arguments.
      
      ```python
      # Positional arguments
        def greet(*args, **kwargs):
          for name in args:
              print(f"Hello, {name}!")
      
      # Keyword arguments
        for key, value in kwargs.items():
          print(f"{key}: {value}")

      # Usage
        greet("Alice", "Bob", "Charlie", age=25, location="New York")

      #  Output:
      #     Hello, Alice!
      #     Hello, Bob!
      #     Hello, Charlie!
      #     age: 25
      #     location: New York
      ```