# Python Notes 

## 1. Installation 

1. For installing Python at `custom path` or on the server where you do not have the root permission

    `http://thelazylog.com/install-python-as-local-user-on-linux/`
  
1. If you are behind the proxy and want too install a package using pip

    ```bash
    pip install --proxy http://proxy-us.intel.com:911 numpy
    ```

2. The packages that you install using pip command are stored at location `/Python27/Lib/site-packages`

3. The python packages are published at website 
  
    ``` 
    'pypi.org' - Python package Index org
    ```
4. `pip` is a python package manager. It installs python packages through command line


## 2. File Handling

  1. For opening a file and reading it line by line.

      ```python
      fp = open(r'C:\Users\Ram\Desktop\tty.txt','r')
      for i in fp:
          print (i.strip())
      ```

  2. For opening a file and splitting it at a specific word to form records.
      ```python
      with open(r'C:\Users\Ram\Desktop\tty.txt') as f:
          for i in f.read().split("\nhere"):
              print (i + "\n----------")
      ```

## 3. Regular Expressions

  1) finding tokens having specified pattern from a string using regular expressions in python.

      ```python
      temp = re.findall(r'\d{1,3}', stringToBeSearched)
      # where temp is a list of all the tokens which match the specified pattern.
      ```

  2) To check whether the line contains a specific pattern use this one,

      ```python
      if re.search("hi","Hi I am here"):
        print ("hi is there in the sample string")   
      ```

  3) Print starting and ending indices from string where string "am" matches.
      ```python
      str = "Hi I am Here. Do not ask know where I am"
        for i in re.finditer("am", str):
          locTuple =  i.span()
          print(locTuple)
      
      # Returns the list of all the words from the input string str which start with S,h,m,p and follow with "at".
      re.findall("[Shmp]at",str)   
      
      # Returns the list of all the words from the input string str which start with any lower case alphabet followed by string "at".
      re.findall("[a-z]at", str)  

      # ^ symbol acts as negation. Words that do not start with characters 'm to z and followed by 'at'
      re.findall("[^m-z]at",str)   
      ```
  
  4) Type of a Variable -
    
      ```python
      print("The type of a variable x is = %s" %type(x)) 
      ```
## 4. Lists 
  - List is a class which is `Ordered` and `mutable collection of items.`
  - As List is a inbuilt class in Python language. 
  - It's name starts with small case `l`, whereas in Python, generally class names start with capital letter.
    
    ```python
    # This command will not copy the contents of list b to list a. It just copies value of 
    # pointer b to pointer a. So both are pointing to same list.
    
      List a,b
      a = b 	      
    ```
  - Copying the lists -
    
    ```python
    # Copy contents of list b to list a.
      a = list(b)
      a = b[:]	  
    
    # The method id() returns the id of the object, which is uniq in program and is generally 
    # memory address where the object is stored.
      print(id(a))		      

    # The range function returns the list object. It is fast way to create a list.
      years = range(1950, 2000, 10)
    ```
  
  - List Operations 
    
    ```python
    lst = [1, 2, 3, 4, 5]
    
    lst.append(6)                       # Add an item '6' at the end of the list
    
    lst.extend([7, 8, 9])               # Extend list by another list
    
    lst.insert(1, 0)                    # Insert item '0' at index '1' position of the list
    
    lst.remove(5)                       # Remove first occurrence of value '5'
    
    popped = lst.pop(5)                 # Remove and return an item at index '5'
    
    del lst[5]                          # Delete an item at index '5' from the list and do not return it.
    
    popped = lst.pop()                  # Remove and return last item
    
    index = lst.index(3)                # Return index of the first occurrence of the item '3'
    
    count = lst.count(2)                # Count occurrences of the item '2'
    
    lst.sort()                          # Sort the list, returns None
    lst.sort(reverse=True)              # Sort the list in reverse order, returns None
    
    lst.reverse()                       # Reverse the list, return None

    # Creation of lists
    lst1 = [1, 2, 3]                    # Creating a list
    lst2 = list(range(1, 4))            # Creating a list from a range
    lst3 = []                           # Empty list creation
  
    # Accessing elements
    print(lst1[0])                      # Output: 1 (accessing first element)
    print(lst1[-1])                     # Output: 3 (accessing last element)
    print(lst1[1:3])                    # Output: [2, 3] (slicing)
  
    # Adding elements
    lst1.append(4)                      # Append an element to the end
    print(lst1)                         # Output: [1, 2, 3, 4]
    lst1.insert(0, 0)                   # Insert an element at a specific index
    print(lst1)                         # Output: [0, 1, 2, 3, 4]
    lst1.extend([5, 6, 7])              # Extend list by appending elements from an iterable
    print(lst1)                         # Output: [0, 1, 2, 3, 4, 5, 6, 7]
  
    # Removing elements
    removed_element = lst1.pop()        # Removes and returns the last element
    print(removed_element, lst1)        # Output: the removed element, and the updated list
    lst1.remove(0)                      # Removes the first occurrence of a value
    print(lst1)                         # Output: [1, 2, 3, 4, 5, 6, 7]
    del lst1[1]                         # Removes an element by index
    print(lst1)                         # Output: [1, 3, 4, 5, 6, 7]
    lst1.clear()                        # Removes all elements
    print(lst1)                         # Output: []
  
    # List Operations
    lst1 = [1, 2, 3]
    lst2 = [3, 4, 5]
    concatenated_list = lst1 + lst2     # Concatenation of lists
    print(concatenated_list)            # Output: [1, 2, 3, 3, 4, 5]
    repeated_list = lst1 * 2            # Repetition of list elements
    print(repeated_list)                # Output: [1, 2, 3, 1, 2, 3]
  
    # Iteration
    for item in lst1:
        print(item)
    
                                        # Output:
                                        # 1
                                        # 2
                                        # 3
  
    # List Methods
    lst1.append(4)                      # Append an element to the end
    print(lst1)                         # Output: [1, 2, 3, 4]
    lst1.extend([5, 6, 7])              # Extend list by appending elements from an iterable
    print(lst1)                         # Output: [1, 2, 3, 4, 5, 6, 7]
    lst1.sort()                         # Sort the list in place
    print(lst1)                         # Output: [1, 2, 3, 4, 5, 6, 7]
    lst1.reverse()                      # Reverse the elements of the list in place
    print(lst1)                         # Output: [7, 6, 5, 4, 3, 2, 1]
    sorted_list = sorted(lst1)          # Return a new sorted list (does not modify original list)
    print(sorted_list)                  # Output: [1, 2, 3, 4, 5, 6, 7]
  
    # Copying a list
    lst2 = lst1.copy()                  # Creates a shallow copy of lst1
    print(lst2)                         # Output: [7, 6, 5, 4, 3, 2, 1]
  
    # List Comprehensions
    lst3 = [x for x in range(10) if x % 2 == 0]   # List comprehension
    print(lst3)                                   # Output: [0, 2, 4, 6, 8]

    # Creating a static matrix
    matrix = [
      [1, 2, 3, 4],
      [5, 6, 7, 8],
      [9, 10, 11, 12]
    ]

    # Creating matrix dynamically using for loops
    for i in range(rows):
      row = []
      for j in range(cols):
        row.append(int(input()))
      matrix.append(row)

    # Creating a matrix using List comprehension.
    # Create a 4x4 matrix with values equal to their column index
    matrix = [[col for col in range(4)] for row in range(4)]
    print("Matrix:", matrix)
                                        # Output: [[0, 1, 2, 3], [0, 1, 2, 3], [0, 1, 2, 3], [0, 1, 2, 3]]

    # Initializing an Empty or Zero Matrix - Using loops
    rows, cols = (3, 3)
    matrix = [[0 for _ in range(cols)] for _ in range(rows)]
    print("Zero Matrix:", matrix)
                                        # Output: [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

    # Accessing matrix elements
    print(matrix[1][0])                 # Output: 3

    # Modify element at row=0 (first row), col=1 (second column)
    matrix[0][1] = 99

    # Nested Lists
    nested = [[1, 2], [3, 4], [5, 6]]
    print(nested[0])                    # First inner list. Output - [1, 2]
    print(nested[1][1])                 # Second list, second element. Output - 4
    nested[2][0] = 50                   # [[1, 2], [3, 4], [50, 6]]

    # flatten 2-level nested lists
    flat = [item for sublist in nested for item in sublist] 

    # flatten lists that are nested till any level 
    def flatten(lst):
    result = []
    for item in lst:
        if isinstance(item, list):
            result.extend(flatten(item))
        else:
            result.append(item)
    return result
    ```

## 5. Tuples
  - They are Ordered, immutable collection of items and hence are hashable. 
  - Also tuple elements can not be deleted but entire tuple can be deleted.
  - Tuples are faster than lists.
  - Can be used in Hash Tables i.e. Dictionary when composite key is required.
    
    ```python
    directory[last,first] = number
      for last, first in directory:
        print first, last, directory[last, first]
    ```
  
  - Are instantiated using parenthesis and use comma to separate the members.
  
  - Tuple packing and unpacking
    
    ```python
    x = ("Guru99", 20, "Education")    # tuple packing
    (company, emp, profile) = x        # tuple unpacking
    ```
  
  - Tuples can be compared. First elements of both are compared if decision can be made then fine or else second and so on.
    
    ```python
    # Here, b is greater than a.
    a = (5,6)
    b = (6,4)
    ```
  
  - Tuple Slicing
    ```python
    x = (1,2,3,4)
    print(x[2:4])         # Output: (3, 4) 
    print(x[0:4])         # Output: (1, 2, 3, 4) 
    print(x[0:9])         # Output: (1, 2, 3, 4) 
    ```
  
  - Creation of tuples
    ```python
    t1 = (1, 2, 3)        # Creating a tuple
    t2 = 1, 2, 3          # Creating a tuple without parentheses
    t3 = (1,)             # Single-element tuple
    t4 = ()               # Empty tuple
    ```

  - Accessing Elements
    ```python
    print(t1[0])          # Output: 1
    print(t1[-1])         # Output: 3
    print(t1[1:3])        # Output: (2, 3)
    ```
  
  - Tuple Operations
    ```python
    t5 = (4, 5)
    t_concat = t1 + t5    # Concatenation: (1, 2, 3, 4, 5)
    t_repeated = t1 * 2   # Repetition: (1, 2, 3, 1, 2, 3)
    print(2 in t1)        # Membership: True
    print(4 in t1)        # Membership: False
    
    # Scalar +/- are not supported on tuples also - operation is not supported on tuples. 
    t5 + 2
    t5 - 2
    t5 - (2)
    ```
  
  - Iteration
    ```python
    for item in t1:
        print(item)
    # Output:
              1
              2
              3
    ```  
  - Built-in Functions
    - The `max`, `min`, `sum`, `len` functions can be used with list and tuples. 
    - while `count`, `index` are members of list and tuples 
      
      ```python
      print(len(t1))            # Length: 3
      print(max(t1))            # Maximum: 3
      print(min(t1))            # Minimum: 1
      print(sum(t1))            # Sum: 6

      t_count = (1, 2, 2, 3)
      print(t_count.count(2))   # Count: 2
      print(t1.index(2))        # Index: 1
      ```
  
  - Conversion

    ```python
    lst = [1, 2, 3]
    t_from_list = tuple(lst)    # List to Tuple: (1, 2, 3)
    lst_from_tuple = list(t1)   # Tuple to List: [1, 2, 3]
    ```
  - Unpacking

    ```python
    a, b, c = t1                # a = 1, b = 2, c = 3
    a, *b, c = (1, 2, 3, 4)     # a = 1, b = [2, 3], c = 4
    ```
  - Nesting
    ```python
    t_nested = (1, (2, 3), 4)   # Accessing nested tuple
    print(t_nested[1])          # Output: (2, 3)
    print(t_nested[1][0])       # Output: 2
    ```  
  - Comparisons
    ```python
    t1 = (1, 2, 3)
    t2 = (1, 2, 3)
    t3 = (1, 2, 4)
    print(t1 == t2)   # Equality: True
    print(t1 < t3)    # Lexicographical comparison: True
    ```
  - tuple or list or even dictionary can be used while returning multiple return values from a function

## 6. 'match' statement 
  - `match` statement is similar to `switch` statement in other programming languages.
  - In `match` statement, each option is denoted by keyword `case`
  - No need of adding `break` statement at the end of each case
  - The default case is handled by underscore i.e. `_`
  
    ```python
    x = input("Please enter your name:")
    match x:
      case 'Rakesh' | 'Ram' | 'Rajesh':
            print('Name starts with "R"')
      case 'Rohit':
            print("Welcome Rohit!")
      case _:
            print('Good Morning, Sir!')
    ```
### What is Guard ?
  - A guard is a condition you attach to a case in a match block using if, to further filter matches.
  - It works just like an if statement inside the case, allowing extra logic beyond structural matching.
  - Syntax 
  
    ```python
    match subject:
    case pattern if condition:
        # Block executed only if the pattern matches and condition is True
    ```
  - Examples - 
    
    ```python
    # 1. Using a guard with numeric conditions
    def check_number(n):
        match n:
            case _ if n < 0:
                print("Negative number")
            case _ if n == 0:
                print("Zero")
            case _ if 0 < n < 10:
                print("Single-digit positive number")
            case _:
                print("Other number")

    check_number(5)    # Single-digit positive number
    check_number(-3)   # Negative number

    # 2. Pattern matching with guard on types
    def describe(value):
        match value:
            case int() if value % 2 == 0:
                print("Even integer")
            case int():
                print("Odd integer")
            case str() if value.isupper():
                print("Uppercase string")
            case str():
                print("Regular string")
            case _:
                print("Something else")

    describe(4)         # Even integer
    describe("HELLO")   # Uppercase string

    # 3. Tuple pattern with guard
    def match_point(point):
        match point:
            case (x, y) if x == y:
                print("Point lies on the line y = x")
            case (x, y) if x == -y:
                print("Point lies on the line y = -x")
            case _:
                print("Random point")

    match_point((2, 2))    # y = x
    match_point((3, -3))   # y = -x

    # 4. Destructuring with guards
    def match_user(user):
        match user:
            case {"name": name, "age": age} if age >= 18:
                print(f"{name} is an adult.")
            case {"name": name, "age": age}:
                print(f"{name} is a minor.")
            case _:
                print("Invalid user object.")

    match_user({"name": "Alice", "age": 20})  # Adult
    match_user({"name": "Bob", "age": 15})    # Minor

    # 5. Using guards with OR (|) pattern
    def grade(score):
        match score:
            case s if s < 0 or s > 100:
                print("Invalid score")
            case s if s >= 90:
                print("Grade A")
            case s if s >= 80:
                print("Grade B")
            case s if s >= 70:
                print("Grade C")
            case _:
                print("Grade D or F")

    grade(85)   # Grade B

    # 6. Guard with class and attribute matching
    class Person:
        def __init__(self, name, age):
            self.name = name
            self.age = age

    def greet(person):
        match person:
            case Person(name=name, age=age) if age < 18:
                print(f"Hi {name}, you're a minor.")
            case Person(name=name, age=age) if age >= 18:
                print(f"Hello {name}, you're an adult.")

    greet(Person("Sam", 17))
    greet(Person("John", 22))
    ```

  ### Important Notes 
  - Guards are evaluated only if the pattern matches.
  - If the guard is `False`, Python moves to the next case.
  - Guards allow complex logic that can't be expressed in patterns alone.
  - You can use any expression in a guard: `comparisons`, `function calls`, `in checks`, etc.

## 7. Strings
  - In Python, strings are `immutable`, which means once they are created, their content cannot be changed or modified. 
  - This `immutability is a fundamental property of strings` in Python.   
  - Python `does not support character data type`. They are considered as the strings of size one.

  - String creation
    
    ```python
    # Define a string
    my_string = "Hello, World!"         
    
    # If you use double quotes for defining the string then do not use double quotes inside it.
    my_string = "Hello, 'Rakesh' "                   
    
    # If you want to use double quotes inside the string then escape them.
    my_string = "Hello, \"Rakesh\" "                 
    
    # Define an empty string
    empty_string = ""                                
    ```
  - Accessing characters and substrings
    ```python
    first_char     = my_string[0]                 # 'H'
    substring      = my_string[0:5]               # 'Hello'
    
    # String length
    length         = len(my_string)               # 13
    
    # String concatenation
    concatenated   = my_string + " How are you?"  # 'Hello, World! How are you?'
    
    print("Hello".replace('l','p'))               # Replace all 'l' with 'p'

    print("Hello".replace('l','p', 1))            # Replace first 'l' with 'p'

    # Sub-String 
    print(f'{"Rak" in "Rakesh" =}')               # True, sub-string 'Rak' present in 'Rakesh'

    # String repetition
    repeated       = my_string * 3                # 'Hello, World!Hello, World!Hello, World!'

    # fstring - String formatting
    # Any string that starts with 'f' is considered as a fstring.
    name           = "Alice"
    greeting       = f"Hello, {name}!"                 # 'Hello, Alice!'
    print("{} scored {} points.".format("Alice", 10))  # Output: Alice scored 10 points.

    # String methods
    upper_case  = my_string.upper()               # 'HELLO, WORLD!'
    lower_case  = my_string.lower()               # 'hello, world!'
    title_case  = my_string.title()               # 'Hello, World!'
    capitalized = my_string.capitalize()          # 'Hello, world!'
    capitalized = my_string.swapcase()            # 'hELLO, WORLD!'

    # Searching within a string - returns index at the start of substring or else -1
    found_index    = my_string.find("World")      # 7
    not_found      = my_string.find("Python")     # -1

    # Checks all the characters of the string are -
    is_alpha = my_string.isalpha()                # False (are all characters alphabetic)
    is_digit = my_string.isdigit()                # False (are all characters digits)
    is_alnum = my_string.isalnum()                # False (are all characters alphabetic and numeric)
    is_lower = my_string.islower()                # False (are all characters lower)
    is_upper = my_string.isupper()                # False (are all characters upper)
    is_upper = my_string.isspace()                # False (are all characters space characters)

    # String splitting
    split_string  = my_string.split(", ")         # ['Hello', 'World!']

    # Joining strings
    joined_string = ", ".join(split_string)       # 'Hello, World!'z

    # Stripping characters (by default strips white spaces if no character is specified)
    stripped  = "   Hello, World!   ".strip()     # 'Hello, World!'
    stripped  = "   Hello, World!!!!".strip('!')  # 'Hello, World'
    lstriped  = "   Hello, World!   ".lstrip()    # 'Hello, World!   '
    rstriped  = "   Hello, World!   ".rstrip()    # '   Hello, World!'

    # Replacing substrings
    replaced  = my_string.replace("World", "Python")  # 'Hello, Python!'

    # Checking prefix and suffix
    starts_with  = my_string.startswith("Hello")  # True
    ends_with    = my_string.endswith("World!")   # True

    # String reversing
    reversed_str = my_string[::-1]                # '!dlroW ,olleH'

    # Count occurrences
    count_o   = my_string.count('o')              # 2

    # Checking if a string is numeric
    is_numeric     = "12345".isnumeric()          # True
    is_not_numeric = "123abc".isnumeric()         # False

    # You can not modify a single character in a string, you need to convert string to list and then modify  
    # Modify first char of string "Hello" to "L"
    s = list("Hello")        
    s[0] = "L"
    mystr = ''.join(s)
    print(mystr)

    # Replacing a single char in a string using string splitting
    s = "hello"
    s = s[:1] + "a" + s[2:]                       # Replace 'e' with 'a'
    print(s)                                      # Output: hallo
    ```

## 8. fStrings - String Formatting in Python
  - Trick 1 - Format integers
    ```python
    # Underscores can be added to the lengthy numbers for more readability. They are ignored by compiler.
    n: int = 1_000_000_000              
    
    # In case of 'float' numbers, number of zeros after '1' can be specified after 'e' as a shortcut.
    n: float = 1e9                        
    
    # This will add 'underscores' to the big number while printing it for the sake of readability.
    print(f"{n:_}")                             
    
    # This will add ',' to the big number while printing it for the sake of readability.
    print(f"{n:,}")                             
    ```

  - Trick 2 - Format Float numbers
    ```python
    n: float = 3.14159                        
    print(round(n, 2))              # Will round the value of 'n' to 2 decimal places.
    print(f'n:.2f')                 # Will round the value of 'n' to 2 decimal places.
    print(f'n:.0f')                 # Will round the value so that no decimal digits.
    print(f'n:,.3f')                # Will round the value of 'n' to 3 decimal places and will add 'comma' 
                                    # to long numbers to make  it more readable.
    ```                                        
  - Trick 3 - Format Strings
    ```python
    x: str = 'Ram'
    print(f"{x:>30}")               # This will print 'Ram' and will align it to the right of the 30 character long imaginary string.

    print(f"{x:<30}")                                
    (OR) print(f"{x:30}")           # This will print 'Ram' and will align it to the left of the 30 character long imaginary string.

    print(f"{x:^30}")               # This will print 'Ram' and will align it to the center of the 30 character long imaginary string.

    print(f"{x:_^30}")                               
    (OR) print(f"{x:|^30}")         # This will print 'Ram' and will align it to the center of the 30 character long imaginary string. The blank spaces will be filled with either '_' or '|'
    ```

  - Trick 4 - Format Date and Time
    ```python
    from datetime import datetime
    now: datetime = datetime.now()
    print(f"{now:%y.%m.%d (%H:%M:%S)})    # Prints the current time in the format specified in format string.
    print(f"{now:%c}")                    # Prints the current time in the system specified format.
    print(f"{now:%I%P}")                  # Prints the current time in 12 hour am/pm format.
    ```

  - Trick 5 - From Python-3.8, you can use self-documenting expressions in f-strings for debugging.
    ```python
    a: int = 12
    b: int = 20
    print(f'{ a + b = }')           # Prints 'a + b = 32' as an output string. This kind of string formatting helps in debugging.  
    c: int = 12
    print(f'{ bool(c) = }')         # This will print 'bool(c) = True' as an output string.
    ```

  - Different ways of printing multiple variables (or string formatting) in print() statement in Python. 
    
    ```python
    a, b = (1, 2)
    
    print("a = {}, b = {} ".format(a, b))
    print("a = " + str(a) + ", b = " + str(b))
    print(f"a = {a},  b = {b}")
    
    # a single space is added around 'a' and 'b' automatically while printing
    print("a =", a, ", b = ", b)    

    Output : 
            a = 1, b = 2
            a = 1, b = 2
            a = 1,  b = 2
            a = 1 , b =  2
    ```

## 9. Dictionaries
   - They map hashable keys to arbitrary objects. The hashable means that mutable objects can not be used as keys in the dictionary.
	  
      ```python
      d = { 1     : 'First value'
            'key' : 'another value'
            '2'   : [1,2,3]
          }
  	  ```
  - Only one entry per key.
  - Key should be immutable object i.e. number, string or tuple.
  - Dictionary keys are case sensitives.
  - `Entries in Dictionaries are not stored in specific order`, so you might not get them in order while retrieving.
  - To add a new key value pair to dictionary.
    
    ```python
    d.update({'Key': value})
    ```
  
  - To make a Copy of dictionary "dict"
  
    ```python
    y =  dict.copy()
    ```
  
  - Dictionary method to get the value associated with the key '2'. Note that key is the value 2 along with single quotes.
    
    ```python
    
    # Creation of dictionaries
      d3 = {}                                      # Empty dictionary
      d1 = {'a': 1, 'b': 2, 'c': 3}                # Creating a dictionary
      d4 = dict()                                  # Another way to create an empty dictionary
      d2 = dict(a=1, b=2, c=3)                     # Creating a dictionary using the dict() class constructor. {'a': 1, 'b': 2, 'c': 3}
      d = dict(key=12 , other_key=[1,2,3])         # Creates a dictionary - {'key': 12, 'other_key': [1, 2, 3]}

    # Accessing Elements
      print(d1['a'])                               # Output: 1
      print(d1.get('b'))                           # Output: 2

      # If value is present for the key 'd', it will be returned or else 'default' will be returned. 
      print(d1.get('d', 'default'))                # Output: 'default'
      print(d1.get('e', 4))                        # Output: 4, as 'e' is not present in dict.

    # Adding and Updating Elements
      d1['d'] = 4                                  # Adding a new key-value pair
      d1['a'] = 10                                 # Updating an existing key-value pair
      print(d1)                                    # Output: {'a': 10, 'b': 2, 'c': 3, 'd': 4}
  
    # Removing Elements
      value = d1.pop('a')                          # Removes and returns the value of 'a'
      print(value)                                 # Output: 10
      print(d1)                                    # Output: {'b': 2, 'c': 3, 'd': 4}
      # Delete an element from dictionary
      del d1['b']                                  # Removes the key 'b' and its value
      print(d1)                                    # Output: {'c': 3, 'd': 4}
    
    # In Python 3.7 and later versions, dictionaries maintain insertion order, and the popitem() method removes and returns the last inserted key-value pair in Last In, First Out (LIFO) order. This means the most recently added element will be deleted when popitem() is called.

    # Before Python 3.7, dictionaries did not guarantee any specific order, and popitem() would remove an arbitrary key-value pair
      
      d1.popitem()                                 # Removes and returns the last key-value pair
      print(d1)                                    # Output: {'c': 3}
      d1.clear()                                   # Removes all elements
      print(d1)                                    # Output: {}

    
    # Dictionary Operations
      d1 = {'a': 1, 'b': 2, 'c': 3}
      d2 = {'d': 4, 'e': 5}
      d1.update(d2)                                # Updates d1 with key-value pairs from d2
      print(d1)                                    # Output: {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5}
      d1.update({'e': 55})                         # Updates d1 with key-value pair 'e': 55
      print(d1)                                    # Output: {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 55}

    # Iteration
      for key in d1:
          print(key)
      
        # Output:
        # a
        # b
        # c
        # d
        # e
      
      for key, value in d1.items():
          print(key, value)
      
        # Output:
        # a 1
        # b 2
        # c 3
        # d 4
        # e 5

    # Dictionary Methods
      keys = d1.keys()                             # Returns a view object of keys
      print(keys)                                  # Output: dict_keys(['a', 'b', 'c', 'd', 'e'])
      values = d1.values()                         # Returns a view object of values
      print(values)                                # Output: dict_values([1, 2, 3, 4, 5])
      items = d1.items()                           # Returns a view object of key-value pairs
      print(items)                                 # Output: dict_items([('a', 1), ('b', 2), ('c', 3), ('d', 4), ('e', 5)])

    # Sorting Dictionary elements
      Dict = {'Tim': 18,'Charlie':12,'Tiffany':22,'Robert':25}
      Students = list(Dict.keys())
      Students.sort()
      for S in Students:
          print(":".join((S,str(Dict[S]))))

    # Copying a Dictionary
      d3 = d1.copy()                               # Creates a shallow copy of d1
      print(d3)                                    # Output: {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5}
  
    # Length of dictionary
      print("Length of dictionary Dict is = %d " %len(Dict) )          
  
    # Converting a dictionary "Dict" in string format
      str(Dict)

    # Using dict.fromkeys()
      keys = ['a', 'b', 'c']
      d4 = dict.fromkeys(keys, 0)                  # Creates a new dictionary with keys from the list and all values set to 0
      print(d4)                                    # Output: {'a': 0, 'b': 0, 'c': 0}

    # Checking Membership
      print('a' in d1)                             # Output: True
      print('z' in d1)                             # Output: False

    # Dictionary Comprehensions
      d5 = {x: x**2 for x in range(5)}
      print(d5)                                    # Output: {0: 0, 1: 1, 2: 4, 3: 9, 4: 16}

    # Nested Dictionaries
      d6 = {'a': {'nested_a': 1}, 'b': {'nested_b': 2}}
      print(d6['a'])                               # Output: {'nested_a': 1}
      print(d6['a']['nested_a'])                   # Output: 1

    # Using setdefault() - Adds an element to dict if that element is not present or else does nothing
      d7 = {'a': 1, 'b': 2}
      d7.setdefault('c', 3)                        # Adds 'c' with value 3 if 'c' is not in the dictionary
      print(d7)                                    # Output: {'a': 1, 'b': 2, 'c': 3}
      d7.setdefault('a', 10)                       # Does nothing as 'a' is already in the dictionary
      print(d7)                                    # Output: {'a': 1, 'b': 2, 'c': 3}

    # Dictionary elements can not be accessed using positional indices such as 0,1,2,3,4 etc like list
      print({x:{x**2:x**3}  for x in range(10) if x%2 == 1})   
      # Creates Dictionary :- {1: {1: 1}, 3: {9: 27}, 5: {25: 125}, 7: {49: 343}, 9: {81: 729}}
      
    # Accessing Dictionary positionally will throw error.
      print({x:{x**2:x**3}  for x in range(4)}[3][0]) 
    ```

  ## 10. Dictionary Comprehension
  - Dictionary comprehensions in Python allow you to create dictionaries in a concise and readable way, similar to list comprehensions. 

  - Below are some examples to illustrate how dictionary comprehensions work.

    **1. Basic Dictionary Comprehension**
    - Let's create a dictionary where the keys are numbers from 1 to 5 and the values are their squares.
      
      ```python
        squares = {x: x**2 for x in range(1, 6)}
        print(squares)
      
        # Output:
        # {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}
      
        # Explanation:
        # - The comprehension {x: x**2 for x in range(1, 6)} iterates over the range 1 to 5.
        # - For each x, it sets the key as x and the value as x**2.
      ```

    **2. Dictionary Comprehension with Condition**  
    - Let's create a dictionary that only includes even numbers as keys and their squares as values.
   
      ```python
      even_squares = {x: x**2 for x in range(1, 11) if x % 2 == 0}
      print(even_squares)
      # Output:
      #   {2: 4, 4: 16, 6: 36, 8: 64, 10: 100}
      # Explanation:
      # - The comprehension {x: x**2 for x in range(1, 11) if x % 2 == 0} iterates over numbers 1 to 10.
      # - The condition if x % 2 == 0 filters out odd numbers, so only even numbers are included in the dictionary.
      ```
  
    **3. Using an Existing Dictionary**  
    - Let's say you have a dictionary of items and their prices in dollars, and you want to create a new dictionary with the prices converted to euros.
      
      ```python
      prices_in_dollars = {'apple': 1.5, 'banana': 0.5, 'cherry': 2.0}
      exchange_rate = 0.85  # 1 dollar = 0.85 euros

      prices_in_euros = {item: price * exchange_rate for item, price in prices_in_dollars.items()}
      print(prices_in_euros)
  
      # Output:
      # {'apple': 1.275, 'banana': 0.425, 'cherry': 1.7}
  
      # Explanation:
      # - The comprehension {item: price * exchange_rate for item, price in prices_in_dollars.items()} iterates over each key-value pair 
      #   in the prices_in_dollars dictionary.
      # - It converts the price to euros by multiplying it by the exchange_rate.
      ```

    **4. Inverting a Dictionary**  
    - Let's invert a dictionary, so that the original keys become the values and the original values become the keys.
     
      ```python
      original = {'a': 1, 'b': 2, 'c': 3}
      inverted = {value: key for key, value in original.items()}
      print(inverted)
      
      # Output:
      #   {1: 'a', 2: 'b', 3: 'c'}
      # Explanation:
      # - The comprehension {value: key for key, value in original.items()} swaps the keys and values of the original dictionary.
      ```

    **5. Nested Dictionary Comprehension**  
    - You can also use nested comprehensions for more complex structures. For example, let's create a dictionary where each key is a number from 1 to 3, and the value is another dictionary containing the square and cube of that number.
      
      ```python
      nested_dict = {x: {'square': x**2, 'cube': x**3} for x in range(1, 4)}
      print(nested_dict)

      # Output:
      #   {1: {'square': 1, 'cube': 1}, 2: {'square': 4, 'cube': 8}, 3: {'square': 9, 'cube': 27}}

      # Explanation:
      # - The outer comprehension {x: {'square': x**2, 'cube': x**3} for x in range(1, 4)} creates a dictionary where each key is x.
      # - The value for each key is another dictionary created by the inner comprehension, containing the square and cube of x.
      # - These examples demonstrate the flexibility and power of dictionary comprehensions in Python.
      ```
  
  ## 11. Sorting Dictionary 
  - Sorting by Keys   : Creates a new dictionary sorted by keys using dictionary comprehension.
    
    ```python
    sorted(my_dict)       # Returns a list of sorted keys from my_dict.
    ```
  - Sorting by Values : Creates a new dictionary sorted by values using dictionary comprehension with 
    
    ```python
    sorted(my_dict.items(), key=lambda item: item[1]).
    ```
  
  - Maintaining Order with OrderedDict:
    - Sorted by Keys    : Uses OrderedDict to maintain the order of keys.
    - Sorted by Values  : Uses OrderedDict to maintain the order of values.
  
  - While regular dictionaries in Python 3.7+ maintain insertion order, OrderedDict explicitly guarantees this behavior even in older Python versions (pre-3.7).
  
    ```python
    from collections import OrderedDict

    my_dict = {'b': 3, 'a': 1, 'c': 2}                                    # Original dictionary

    # Using sorted() on a dictionary returns a list of sorted keys
      sorted_keys = sorted(my_dict)
      print("Sorted keys:", sorted_keys)                                  # Output: ['a', 'b', 'c']

    # Sorting dictionary by keys using dictionary comprehension

      sorted_dict_by_keys = {key: my_dict[key] for key in sorted(my_dict)}
      print("Dictionary sorted by keys:", sorted_dict_by_keys)            # Output: {'a': 1, 'b': 3, 'c': 2}

    # Sorting dictionary by values using dictionary comprehension

      sorted_dict_by_values = {k: v for k, v in sorted(my_dict.items(), key=lambda item: item[1])}
      print("Dictionary sorted by values:", sorted_dict_by_values)        # Output: {'a': 1, 'c': 2, 'b': 3}

    # Sorting dictionary by values in reverse order using dictionary comprehension

      sorted_dict_by_values = {k: v for k, v in sorted(my_dict.items(), key=lambda item: item[1], reverse=True)}
      print("Dictionary sorted by values:", sorted_dict_by_values)        # Output: { 'b': 3, 'c': 2, 'a': 1,}

    # Using OrderedDict to maintain the sorted order by keys

      sorted_dict_by_keys_ordered = OrderedDict(sorted(my_dict.items()))
      print("OrderedDict sorted by keys:", sorted_dict_by_keys_ordered)   # Output: OrderedDict([('a', 1), ('b', 3), ('c', 2)])

    # Using OrderedDict to maintain the sorted order by values

      sorted_dict_by_values_ordered = OrderedDict(sorted(my_dict.items(), key=lambda item: item[1]))
      print("OrderedDict sorted by values:", sorted_dict_by_values_ordered)  # Output: OrderedDict([('a', 1), ('c', 2), ('b', 3)])
    ```

  ## 12. Default Dictionary 
  - When you access a key that doesn’t exist in the dictionary, `defaultdict` automatically creates it and assigns it a default value based on the factory function provided during initialization.
  - The factory function defines the default value for missing keys. Common examples include int, list, set, or custom functions.
  - The factory function should be passed without parentheses like `defaultdict(int)` and not like `defaultdict(int())`.
  - Unlike regular dictionaries, accessing a nonexistent key in a defaultdict will not raise a KeyError.

  ```python
  # Creating a defaultdict with int as the default factory. 
  # The term "default factory" in the context of defaultdict refers to the function that provides the default value for a key that does not exist in the dictionary. 
  # For example, 'int' is a factory function that returns 0, and 'list' is a factory function that returns an empty list ([]).

    from collections import defaultdict
  
    default_int_dict = defaultdict(int)
    print(default_int_dict['missing_key'])    # Output: 0 (default int value)

  # Instead of '0' as default value set '3' as a default value.  
    d = defaultdict(lambda: 3)
  
  # Setting up custom factory function
    def return_hello():
      return "Hello!"

    d = defaultdict(return_hello)

  # Creating a defaultdict with a lambda function as the default factory
    default_lambda_dict = defaultdict(lambda: 'default_value')
    print(default_lambda_dict['missing_key']) # Output: 'default_value'
  
  # Adding and updating elements
    default_int_dict['a'] += 1
    default_int_dict['b'] = 5
    print(default_int_dict)                   # Output: defaultdict(<class 'int'>, {'a': 1, 'b': 5})
  
  # Iterating through items
    default_int_dict['c'] = 2
    for key, value in default_int_dict.items():
        print(f"{key}: {value}")
      # Output:
      # a: 1
      # b: 5
      # c: 2

  # Grouping elements with defaultdict
    s = [('a', 1), ('b', 2), ('a', 3), ('b', 4), ('c', 5)]
    grouped = defaultdict(list)
    for k, v in s:
        grouped[k].append(v)
    print(grouped)                            # Output: defaultdict(<class 'list'>, {'a': [1, 3], 'b': [2, 4], 'c': [5]})
  ```
  
  ## 13. Sets
  - Sets are unordered and do not allow duplicate elements.
  - `{}` creates an empty dictionary, not an empty set. Use `set()` for an empty set.
  - Following symbols are used for denoting various set operations
      
    |  Symbol  |  Operation                 |
    | -------- | -------------------------  |
    |   `\|`   | Set Union                  |
    |   `&`    | Set intersection           |
    |   `-`    | Set Difference             |
    |   `^`    | Symmetric set Difference   |

  - Creation of sets
    
    ```python
    s1 = {1, 2, 3}                    # Creating a set directly
    s2 = set([1, 2, 3])               # Creating a set from a list
    s3 = set()                        # Empty set creation (note: {} creates an empty dictionary)
    s4 = set("hello")                 # Creating a set from a string (removes duplicates)
    print(s4)                         # Output: {'h', 'e', 'l', 'o'}
    ```
    
  - Adding elements
    
    ```python
    s1.add(4)                         # Adding a single element
    print(s1)                         # Output: {1, 2, 3, 4}
    
    s1.update([5, 6, 7])              # Adding multiple elements (can use any iterable)
    print(s1)                         # Output: {1, 2, 3, 4, 5, 6, 7}
    
    s1.update("abc")                  # Adding elements from a string (adds 'a', 'b', 'c')
    print(s1)                         # Output: {1, 2, 3, 4, 5, 6, 7, 'a', 'b', 'c'}
    ```
  
  - Removing elements
    - `pop()` removes and returns an arbitrary element because sets are unordered.
    - Use `discard()` instead of `remove()` to avoid errors when the element is absent.
    
    ```python
    # remove() throws an error if the key is not present 
    s1.remove(7)                      # Removing an element
    print(s1)                         # Output: {1, 2, 3, 4, 5, 6}
    
    # discard() does not throw an error if the element is not present 
    s1.discard(6)                     # Discarding an element
    print(s1)                         # Output: {1, 2, 3, 4, 5}

    removed_element = s1.pop()        # Removes and returns an arbitrary element
    print(removed_element, s1)        # Output: the removed element, and the updated set

    s1.clear()                        # Removes all elements from the set
    print(s1)                         # Output: set()
    ```

  - Set Operations
    - These operations return new sets; they do not modify the original sets unless you use methods like update().
    
    ```python
    s1 = {1, 2, 3}
    s2 = {2, 3, 4}

    union_set = s1.union(s2)                # Union of sets (all unique elements)
    print(union_set)                        # Output: {1, 2, 3, 4}

    intersection_set = s1.intersection(s2)  # Intersection of sets (common elements)
    print(intersection_set)                 # Output: {2, 3}

    difference_set = s1.difference(s2)      # Difference of sets (elements in s1 but not in s2)
    print(difference_set)                   # Output: {1}

    symmetric_difference_set = s1.symmetric_difference(s2)  # Symmetric difference (elements not common in both sets)
    print(symmetric_difference_set)                         # Output: {1, 4}
    ```

  - Set Methods
    ```python
    s1 = {1, 2, 3}
    s3 = {3, 4, 5}

    s1.update(s3)                     # Updates s1 with elements from s3
    print(s1)                         # Output: {1, 2, 3, 4, 5}
    ```
    
    ```python
    s1 = {1, 2, 3}
    s2 = {2, 3, 4}
    s2.intersection_update(s1)        # Updates s2 to intersection with s1
    print(s2)                         # Output: {2, 3}
    ```

    ```python
    s1 = {1, 2, 3}
    s3 = {3, 4, 5}
    s3.difference_update(s1)          # Updates s3 to difference with s1
    print(s3)                         # Output: {4, 5}
    ```

  - Membership check
    
    ```python
    print(2 in s1)                    # Output: True
    print(6 in s1)                    # Output: False

    s1[0]                             # subscript operators [] do not work with sets.

    # Other operations
    print(len(s1))                    # Output: Number of elements in s1

    # Copying a set
    s4 = s1.copy()                    # Creates a shallow copy of s1
    print(s4)                         # Output: {1, 2, 3, 4, 5}

    # Set Comprehensions
    even_numbers = {x for x in range(10) if x % 2 == 0}   # Set comprehension for even numbers
    print(even_numbers)                                   # Output: {0, 2, 4, 6, 8}
    ```

  ## 14. Frozen Set  
  
  - The frozenset is a built-in Python data type and is an immutable version of a regular set. 
  - Once created, its elements cannot be changed. 
  
  - Features  
    |   Feature         | Explanation                                                                                          |
    | ----------------- | ----------------------------------------------------------------------------------------------------------------|
    |   Immutability    | Unlike a set, a frozenset cannot be modified after creation.                                                    |
    |   Hashable        | Since frozensets are immutable, they can be used as keys in a dictionary or elements of another set.            |
    |   Unordered       | Elements in a frozenset are not stored in any particular order.                                                 |
    |   Unique Elements | Like sets, frozensets do not allow duplicate elements.                                                          |
    |   Set Operations  | Frozensets support all the standard set operations such as union, intersection, difference, and symmetric difference |

    ### Creating an empty frozenset
      ```python
        empty_fset = frozenset()
        print(empty_fset)                         # Output: frozenset()
    
      # Creating a frozenset from a list
        fset_from_list = frozenset([1, 2, 3, 4, 5])
        print(fset_from_list)                     # Output: frozenset({1, 2, 3, 4, 5})
              
      # Creating a frozenset from a tuple
        fset_from_tuple = frozenset((1, 2, 3, 4, 5))
        print(fset_from_tuple)                    # Output: frozenset({1, 2, 3, 4, 5})
      ```
    ### Basic operations on frozenset
      ```python  
        fset1 = frozenset([1, 2, 3, 4])
        fset2 = frozenset([3, 4, 5, 6])

      # Union
        union_fset = fset1 | fset2
        print(union_fset)                         # Output: frozenset({1, 2, 3, 4, 5, 6})

      # Intersection
        intersection_fset = fset1 & fset2
        print(intersection_fset)                  # Output: frozenset({3, 4})

      # Difference
        difference_fset = fset1 - fset2
        print(difference_fset)                    # Output: frozenset({1, 2})

      # Symmetric Difference
        symmetric_difference_fset = fset1 ^ fset2
        print(symmetric_difference_fset)          # Output: frozenset({1, 2, 5, 6})
      ```

    ### Methods of Frozenset
      ```python  
        fset = frozenset([1, 2, 3, 4, 5])
        other_set = {4, 5, 6, 7}

      # Copy 
      # copy(): Returns a shallow copy of the frozenset.
        copy_fset = fset.copy()
        print(copy_fset)                                                                      # Output: frozenset({1, 2, 3, 4, 5})

      # Difference 
      # difference(iterable): Returns the difference of the frozenset and the iterable.
        difference_fset = fset.difference(other_set)
        print(difference_fset)                                                                # Output: frozenset({1, 2, 3})

      # Intersection 
      # intersection(iterable): Returns the intersection of the frozenset and the iterable.
        intersection_fset = fset.intersection(other_set)
        print(intersection_fset)                                                              # Output: frozenset({4, 5})

      # Isdisjoint 
      # isdisjoint(iterable): Returns True if the frozenset has no elements in common with the iterable.
        is_disjoint = fset.isdisjoint(other_set)
        print(is_disjoint)                                                                    # Output: False

      # Issubset
      # issubset(iterable): Returns True if the frozenset is a subset of the iterable.
        is_subset = fset.issubset({1, 2, 3, 4, 5, 6})
        print(is_subset)                                                                      # Output: True

      # Issuperset
      # issuperset(iterable): Returns True if the frozenset is a superset of the iterable.
        is_superset = fset.issuperset({1, 2})
        print(is_superset)                                                                    # Output: True

      # Union
      # union(iterable): Returns the union of the frozenset and the iterable.
        union_fset = fset.union(other_set)
        print(union_fset)                                                                     # Output: frozenset({1, 2, 3, 4, 5, 6, 7})
      ```

  ## 15. Deque

  - `Double-ended queue`, allows appending and popping from both ends
  - It is part of the `collections` module and is highly versatile for `queue-like` operations.
  
    ```python
    from collections import deque

    # Deque creation
      my_deque = deque()                             # Create an empty deque
      my_deque_with_elements = deque([1, 2, 3])      # Create a deque with initial elements

    # Create a deque with a fixed maximum length
      fixed_size_deque = deque(maxlen=5)             # Automatically removes elements from the opposite end when full

    # Adding elements
      my_deque.append(4)                             # Add element to the right end (default behavior)
      my_deque.appendleft(5)                         # Add element to the left end


    # Add multiple elements to the right end
      my_deque.extend([6, 7, 8])

    # Add multiple elements to the left end (elements are added in reverse order of the iterable)
      my_deque.extendleft([9, 10])                   # Adds 10 first, then 9

    # Removing elements (on empty deque pop() and popleft() raise IndexError)
      right_elem = my_deque.pop()                    # Remove and return the rightmost element
      left_elem  = my_deque.popleft()                # Remove and return the leftmost element

    # Remove the first occurrence of a specific element (throws ValueError if not found)
      my_deque.remove(7)

    # Accessing elements
      first_elem = my_deque[0]                       # Access the first element
      last_elem  = my_deque[-1]                      # Access the last element

    # Deque length
      deque_length = len(my_deque)                   # Get the number of elements in the deque

    # Clearing the deque
      my_deque.clear()                               # Remove all elements from the deque

    # Extending the deque
      my_deque.extend([6, 7, 8])                     # Add multiple elements to the right end
      my_deque.extendleft([9, 10])                   # Add multiple elements to the left end (in reverse order)

    # Rotating the deque
      my_deque.rotate(1)                             # Rotate the deque to the right by n positions (positive n)
      my_deque.rotate(-2)                            # Rotate the deque to the left by n positions (negative n)

    # Inserting elements (throws IndexError if out of range)
      my_deque.insert(2, 11)                         # Insert element '11' at a specific position, here at index 2.

    # Counting elements
      count_7 = my_deque.count(7)                    # Count the number of occurrences of an element

    # Removing specific elements
      my_deque.remove(7)                             # Remove the first occurrence of an element

    # Reversing the deque
      my_deque.reverse()                             # Reverse the elements of the deque in place

    # Copying the deque
      deque_copy = my_deque.copy()                   # Create a shallow copy of the deque

    # Deque indexing and slicing (limited support)
      sliced_deque = deque(list(my_deque)[1:3])      # Get a slice of the deque

    # Maximum length
      fixed_size_deque = deque(maxlen=5)             # Create a deque with a maximum length
      fixed_size_deque.extend([1, 2, 3, 4, 5])       # Add elements to the fixed size deque
      fixed_size_deque.append(6)                     # Add element causing the leftmost element to be removed

    # Checking presence of elements
      is_in_deque = 4 in my_deque                    # Check if an element is in the deque

    # Iterating over the deque
      for elem in my_deque:                          # Iterate over elements in the deque
        print(elem)                                  # Print each element
    
    # Removing element from a specific index
      index_to_remove = 2                               # Index of the element to remove
      temp_list = list(my_deque)                        # Convert deque to list
      removed_element = temp_list.pop(index_to_remove)  # Remove element at the specific index
      my_deque = deque(temp_list)                       # Convert list back to deque
    ```

  ## 16. Python Operators
  
  |  Operator Type        | Description                                                                       |  
  |  -------------------- | ----------------------------------------------------------------------------------|
  |  Arithmetic Operators | `+`, `-`, `*`, `/`, `//`(Floor division), `%`(mod), `**`(Exponent)                |
  |  Logical Operators    | `not`, `and`, `or`                                                                |
  |  Membership Operators | `in`, `not` `in`                                                                  |
  |  Identity Operators   | `is`, `is not`                                                                    |
  |  Comparison Operators | `>`, `<`, `>=`, `<=`, `==`                                                        |
  |  Assignment Operators | `=`, `%=`, `/=`, `//=`, `+=`, `-=`, `*=`, `**=` (But unary operators `++` and `--` are not supported) |
  |  dir(a)               | This will list all the methods available for the object a                         | 

  ## 17. Lambda Functions

  - Usually functions are defined as follows -
    ```python
    def functionName (Arguments):
      line1
      line2
    ```

  - Lambda functions in Python are small anonymous functions defined using the lambda keyword. 

  - They can have any number of arguments but only one expression. The expression is evaluated and returned

  - Basic Lambda Function
    ```python
    add_ten = lambda x: x + 10
    print(add_ten(5))                               # Output: 15

    # --> Using Lambda in Higher-Order Functions
      nums = [1, 2, 3, 4]
  
    # --> map() - map returns a 'map' object, you need to convert it into your desired type
    #         - Also note that we just pass function name to the map without parenthesis. 
    doubled = list(map(lambda x: x * 2, nums))
    print(doubled)                                  # Output: [2, 4, 6, 8]
    mystr: str = 'hi how are you'
    print(*map(str.upper, mystr))

    # --> filter()  
    evens = list(filter(lambda x: x % 2 == 0, nums))
    print(evens)                                    # Output: [2, 4]
  
    # --> reduce()
    from functools import reduce
    product = reduce(lambda x, y: x * y, nums)
    print(product)                                  # Output: 24
  
    # --> Sorting with Lambda Functions
    points = [(1, 2), (4, 1), (5, 0), (10, -1)]
    sorted_points = sorted(points, key=lambda point: point[1])
    print(sorted_points)                            # Output: [(10, -1), (5, 0), (4, 1), (1, 2)]
  
    # --> Using Lambda with Custom Functions
    def apply_function(func, value):
        return func(value)
    result = apply_function(lambda x: x ** 2, 5)
    print(result)                                   # Output: 25
  
    # --> Using Lambda in Data Structures
    operations = [lambda x: x + 1, lambda x: x * 2, lambda x: x ** 2]
    for op in operations:
        print(op(5))
                                                    # Output: 6
                                                    #         10
                                                    #         25
    operation_dict = {
        'add': lambda x, y: x + y,
        'sub': lambda x, y: x - y,
        'mul': lambda x, y: x * y
    }
    print(operation_dict['add'](2, 3))              # Output: 5
    print(operation_dict['mul'](3, 4))              # Output: 12
  
    # --> Combining Multiple Lambda Functions
    add = lambda x, y: x + y
    multiply = lambda x, y: x * y
    combined = lambda x, y: add(multiply(x, y), 10)
    print(combined(2, 3))                           # Output: 16
    ```

  ## 18. `Pass` Keyword in Python 
  - The 'Pass'  keyword is used in places where syntactically a statement is expected but you do not have any statement to run right now.
  -  It is often used in function definitions, loops or conditional statements during development phases where you have not yet decided what the     function should do. 
  
      ```python
      def my_function():
        pass  # Placeholder for future code
      
      # Later, you can define the function's behavior
      def my_function():
          print("Function now does something!")
      ```

  ## 19. `random` module in Python 
  - 'random' is a module in Python, which provide functions for generating random numbers and doing random operations.
  - 'random.choice()' is a function which selects a random item from a sequence such as list, tuple or string provided as an argument to the random.choice() function
      ```python
      import random
      # Example 1: Random Choice from a List
        my_list = [1, 2, 3, 4, 5]
        random_element_list = random.choice(my_list)
        print(f"Random element from list: {random_element_list}")

      # Example 2: Random Choice from a String
        my_string = "hello"
        random_character = random.choice(my_string)
        print(f"Random character from string: {random_character}")

      # Example 3: Random Choice from a Tuple
        my_tuple = (10, 20, 30, 40, 50)
        random_element_tuple = random.choice(my_tuple)
        print(f"Random element from tuple: {random_element_tuple}")

      # Example 4: Random Choice from a List of Strings
        my_list_of_strings = ["apple", "banana", "cherry", "date"]
        random_string = random.choice(my_list_of_strings)
        print(f"Random string from list of strings: {random_string}")

      # Example with Error Handling
        empty_list = []
        try:
            random_element_empty = random.choice(empty_list)
            print(f"Random element from empty list: {random_element_empty}")
        except IndexError:
            print("Cannot choose from an empty sequence")

        # Sample Outputs:
        # Random element from list: 3
        # Random character from string: e
        # Random element from tuple: 40
        # Random string from list of strings: banana
        # Cannot choose from an empty sequence

      # --> random.randint(a, b)
      It will return a random integer number between a and b, where a and b are inclusive.

      # --> random.shuffle(l)
      It takes a list of values as an argument and shuffles them randomly inplace without returning it.
      ```

    ### More examples from 'random' module 
    
      ```python
      import random

      # Example 1: random.random()
      # Returns a random float number between 0.0 and 1.0
        random_float = random.random()
        print(f"random.random(): {random_float}")
                                                                      # Sample Output:
                                                                      # random.random(): 0.6394267984578837

      # Example 2: random.randint(a, b)
      # Returns a random integer N such that a <= N <= b
        random_int = random.randint(1, 10)
        print(f"random.randint(1, 10): {random_int}")
                                                                      # Sample Output:
                                                                      # random.randint(1, 10): 4

      # Example 3: random.uniform(a, b)
      # Returns a random float N such that a <= N <= b
        random_uniform = random.uniform(1.0, 10.0)
        print(f"random.uniform(1.0, 10.0): {random_uniform}")
                                                                      # Sample Output:
                                                                      # random.uniform(1.0, 10.0): 7.473209565777174

      # Example 4: random.choice(sequence)
      # Returns a random element from a non-empty sequence
        my_list = ['apple', 'banana', 'cherry', 'date']
        random_choice = random.choice(my_list)
        print(f"random.choice(my_list): {random_choice}")
                                                                      # Sample Output:
                                                                      # random.choice(my_list): cherry

      # Example 5: random.sample(population, k)
      # Returns a list of k unique elements chosen from the population sequence
        random_sample = random.sample(my_list, 2)
        print(f"random.sample(my_list, 2): {random_sample}")
                                                                      # Sample Output:
                                                                      # random.sample(my_list, 2): ['date', 'apple']

      # Example 6: random.shuffle(sequence)
      # Shuffles the sequence in place
        random.shuffle(my_list)
        print(f"random.shuffle(my_list): {my_list}")
                                                                      # Sample Output:
                                                                      # random.shuffle(my_list): ['cherry', 'banana', 'apple', 'date']

      # Example 7: random.gauss(mu, sigma)
      # Returns a random float from a Gaussian distribution with mean mu and standard deviation sigma
        random_gauss = random.gauss(0, 1)
        print(f"random.gauss(0, 1): {random_gauss}")
                                                                      # Sample Output:
                                                                      # random.gauss(0, 1): -1.620067301067623

      # Example 8: random.seed(a=None)
      # Initializes the random number generator with a seed
        random.seed(42) 
        random_seeded = random.random() 
        print(f"random.seed(42) followed by random.random(): {random_seeded}" )
                                                                      # Sample Output:
                                                                      # random.seed(42) followed by random.random(): 0.6394267984578837
      ```

  ## 20. 'sys' module Functions
  
  ```python
   import sys
   # Example 1: sys.version
   # Returns the version of the Python interpreter
     python_version = sys.version
     print(f"sys.version: {python_version}")             # sys.version: 3.8.5 (default, Jul 21 2020, 10:42:08) [Clang 10.0.0 ]

   # Example 2: sys.platform
   # Returns a string that identifies the operating system
     platform = sys.platform
     print(f"sys.platform: {platform}")                  # sys.platform: darwin

   # Example 3: sys.path
   # Returns the list of directories that the interpreter searches for modules
     path = sys.path
     print(f"sys.path: {path}")                          # sys.path: ['/usr/local/lib/python3.8', ..., '/usr/local/lib/python3.8/lib-dynload']

   # Example 4: sys.argv
   # Returns the list of command-line arguments passed to a Python script
     argv = sys.argv
     print(f"sys.argv: {argv}")                          # sys.argv: ['example_script.py']    

   # Example 5: sys.exit()
   # Exits from Python. The optional argument specifies the exit status or error message.
   # Note: Uncomment the following lines to see the effect. It will stop the script.
   # sys.exit("Exiting the script")                      

   # Example 6: sys.getsizeof()
   # Returns the size of an object in bytes
     size_of_list = sys.getsizeof([1, 2, 3])
     print(f"sys.getsizeof([1, 2, 3]): {size_of_list}")  # sys.getsizeof([1, 2, 3]): 80

   # Example 7: sys.stdin, sys.stdout, sys.stderr
   # Standard input, output, and error streams
     print("sys.stdin: Standard input stream")
     print("sys.stdout: Standard output stream")
     print("sys.stderr: Standard error stream")      
                                                     # sys.stdin : Standard input stream
                                                     # sys.stdout: Standard output stream
                                                     # sys.stderr: Standard error stream

   # Example 8: sys.modules
   # Returns a dictionary of all loaded modules
     modules = list(sys.modules.keys())[:5]          # Limiting to first 5 for brevity
     print(f"sys.modules: {modules}")                # sys.modules: ['sys', '__builtin__', '_imp', '_warnings', '_io']

  ```
  
  ## 21. More examples from 'statistics' library functions 

  ```python
    import statistics

    # Sample data
      data = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5]

    # Example 1: statistics.mean()
    # Calculates the mean (average) of the data
      mean_value = statistics.mean(data)
      print(f"statistics.mean(data): {mean_value}")            # statistics.mean(data): 3.090909090909091

    # Example 2: statistics.median()
    # Finds the median (middle value) of the data
      median_value = statistics.median(data)
      print(f"statistics.median(data): {median_value}")        # statistics.median(data): 3

    # Example 3: statistics.mode()
    # Identifies the most common value in the data
      mode_value = statistics.mode(data)
      print(f"statistics.mode(data): {mode_value}")            # statistics.mode(data): 4              

    # Example 4: statistics.stdev()
    # Computes the sample standard deviation of the data
      stdev_value = statistics.stdev(data)
      print(f"statistics.stdev(data): {stdev_value}")          # statistics.stdev(data): 1.1973672203238447

    # Example 5: statistics.variance()
    # Computes the sample variance of the data
      variance_value = statistics.variance(data)
      print(f"statistics.variance(data): {variance_value}")    # statistics.variance(data): 1.434782608695652

    # Example 6: statistics.harmonic_mean()
    # Calculates the harmonic mean of the data
      harmonic_mean_value = statistics.harmonic_mean(data)
      print(f"statistics.harmonic_mean(data): {harmonic_mean_value}")       # statistics.harmonic_mean(data): 2.4142011834319524

    # Example 7: statistics.median_high()
    # Finds the median of the data, or the higher of the two middle values if the list has an even number of elements
      median_high_value = statistics.median_high(data)
      print(f"statistics.median_high(data): {median_high_value}")           # statistics.median_high(data): 3

    # Example 8: statistics.median_low()
    # Finds the median of the data, or the lower of the two middle values if the list has an even number of elements
      median_low_value = statistics.median_low(data)
      print(f"statistics.median_low(data): {median_low_value}")             # statistics.median_low(data): 3

    # Example 9: statistics.median_grouped()
    # Finds the median of grouped continuous data, using interpolation
      median_grouped_value = statistics.median_grouped(data)
      print(f"statistics.median_grouped(data): {median_grouped_value}")     # statistics.median_grouped(data): 3.0

    # Example 10: statistics.pstdev() (Population Standard Deviation)
    # Computes the population standard deviation of the data
      pstdev_value = statistics.pstdev(data)
      print(f"statistics.pstdev(data): {pstdev_value}")          # statistics.pstdev(data): 1.1331154474650633

    # Example 11: statistics.pvariance() (Population Variance)
    # Computes the population variance of the data
      pvariance_value = statistics.pvariance(data)
      print(f"statistics.pvariance(data): {pvariance_value}")    # statistics.pvariance(data): 1.2830578512396693

    # Example 12: statistics.fmean() (Fast mean of float values)
    # Computes the fast mean of float values in the data
      fmean_value = statistics.fmean(data)
      print(f"statistics.fmean(data): {fmean_value}")            # statistics.fmean(data): 3.090909090909091
  ```

  ## 22. Enumerate Function 
  
  ```python
    # - Example 1: Basic Usage of enumerate()
      my_list = ['a', 'b', 'c', 'd']
      for index, value in enumerate(my_list):
          print(f"Index: {index}, Value: {value}")
      print()  # Blank line for separation
                                                                    # Output:
                                                                    # Index: 0, Value: a
                                                                    # Index: 1, Value: b
                                                                    # Index: 2, Value: c
                                                                    # Index: 3, Value: d
    # - Example 2: Enumerate with Custom Start Index
      my_tuple = ('apple', 'banana', 'cherry', 'date')

      for index, fruit in enumerate(my_tuple, start=1):
        print(f"Item {index}: {fruit}")
      print()  # Blank line for separation

                                                                    # Output:
                                                                    # Item 1: apple
                                                                    # Item 2: banana
                                                                    # Item 3: cherry
                                                                    # Item 4: date

    # - Example 3: Modifying Elements with enumerate()
      my_list = ['a', 'b', 'c', 'd']

      for index, value in enumerate(my_list):
        my_list[index] = value.upper()
      print()  # Blank line for separation
      print(my_list)                                                # Output: ['A', 'B', 'C', 'D']

    # - Example 4: Enumerate Object to List Conversion
      my_tuple = ('apple', 'banana', 'cherry', 'date')
      enumerated_list = list(enumerate(my_tuple))
      print(enumerated_list)
                                                                    # Output: [(0, 'apple'), (1, 'banana'), (2, 'cherry'), (3, 'date')]
  ```

  ## 23. isinstance() Function - checks if an object is an instance of a specified class or type. 
  - useful for type checking and object-oriented programming in Python.
      
      ```python
      # Check if a number is an integer
        x = isinstance(5, int)
        print(x)                          # Output: True

      # Check if a list is a list
        numbers = [1, 2, 3]
        result = isinstance(numbers, list)
        print(result)                     # Output: True

      # Check if a number is a string
        y = isinstance(5, str)
        print(y)                          # Output: False

      # Check if an object is an instance of a class
        class Employee:
            def __init__(self, name, salary):
                self.name = name
                self.salary = salary

        emp = Employee("Emma", 11000)
        print(isinstance(emp, Employee))  # Output: True

      # Check if an object is an instance of a class or a subclass
        class Manager(Employee):
            pass

        manager = Manager("John", 15000)
        print(isinstance(manager, Employee))     # Output: True

      # Check if an object is an instance of a tuple of classes
        print(isinstance(5, (int, float, str)))  # Output: True
      ```

  ## 24. strip() Function 

  ```python
    # The strip() function removes leading and trailing characters from a string.
    # By default, it removes whitespace (spaces, tabs, newlines, etc.).

        s = "   Hello, World!   "
        print(s.strip())  # Output: "Hello, World!" (removes leading and trailing whitespace)

      - You can specify a set of characters to remove as an argument to strip().
        s = "###Hello, World!###"
        print(s.strip("#"))  # Output: "Hello, World!" (removes leading and trailing '#')

      - You can specify multiple characters to remove.
        s = "@#Hello, World!#@"
        print(s.strip("@#"))  # Output: "Hello, World!" (removes leading and trailing '@' and '#')

      - string class contains 'string.punctuation' which lists all the punctuation characters
        import string
        print('Hey! Hope && you are doing good. -'.strip(string.puncutation))

      - strip() does not remove characters from the middle of the string.
        s = "##Hello, #World!##"
        print(s.strip("#"))  # Output: "Hello, #World!" (only leading and trailing '#' are removed)

    # Related functions:
      - lstrip() removes leading characters (from the left).
        s = "  Hello, World!  "
        print(s.lstrip())  # Output: "Hello, World!  " (removes leading whitespace)

      - rstrip() removes trailing characters (from the right).
        print(s.rstrip())  # Output: "  Hello, World!" (removes trailing whitespace)

      - s.replace('_', '')
        If you want to remove all the underscore characters from a string use 'replace' function 
  ```

  ## 25. isaplha() Function 
      
  ```python
      #- The isalpha() method checks if all characters in the string are alphabetic.
      #- Example 1: All alphabetic characters
        s1 = "HelloWorld"
        print(s1.isalpha())  # Output: True

      #- Example 2: Contains non-alphabetic characters (numbers)
        s2 = "Hello123"
        print(s2.isalpha())  # Output: False

      #- Example 3: Contains non-alphabetic characters (space)
        s3 = "Hello World"
        print(s3.isalpha())  # Output: False

      #- Example 4: Contains non-alphabetic characters (punctuation)
        s4 = "Hello!"
        print(s4.isalpha())  # Output: False

      #- Example 5: Empty string
        s5 = ""
        print(s5.isalpha())  # Output: False

      #- Example 6: Non-English alphabetic characters (Cyrillic)
        s6 = "Привет"
        print(s6.isalpha())  # Output: True

      #- Example 7: Non-English alphabetic characters (Chinese)
        s7 = "你好"
        print(s7.isalpha())  # Output: True
  ```

  ## 25. sum() Function 
  ```python
    # The sum() function calculates the sum of all items in an iterable.
    # Example 1: Summing a list of numbers
        numbers_list = [1, 2, 3, 4, 5]
        print(sum(numbers_list))      # Output: 15

    # Example 2: Summing with an initial value
        print(sum(numbers_list, 10))  # Output: 25 (10 + 1 + 2 + 3 + 4 + 5)

    # Example 3: Summing a tuple of numbers
        numbers_tuple = (1, 2, 3, 4, 5)
        print(sum(numbers_tuple))     # Output: 15

    # Example 4: Summing a set of numbers
        numbers_set = {1, 2, 3, 4, 5}
        print(sum(numbers_set))       # Output: 15

    # Example 5: Summing with non-number elements (raises TypeError)
        numbers_mixed = [1, '2', 3]
        try:
            print(sum(numbers_mixed))
        except TypeError as e:
            print(e)                  # Output: unsupported operand type(s) for +: 'int' and 'str'
  ```
  
  ## 26.  '++i' operation in Python 
  - Python does not support unary `--` and `++` operators
  - ++i in Python does not increment i; it is interpreted as +(+i) and leaves i unchanged.
  - Initial value of i
    i = 5

  - ++i in Python
    print(++i)                      # Output: 5  (The unary plus operators do not change the value)

  - Correct way to increment in Python
    i += 1
    print(i)                        # Output: 6  (i is incremented by 1)

  ## 27. Function Return Types in Python 
  - In Python, you can specify the return type of a function using type hints, which were introduced in PEP 484. 
  - Type hints provide a way to indicate the expected type of a function's return value, but they do not enforce these types at runtime. 
  - Instead, they serve as documentation and can be checked using static type checkers like 'mypy'.
  - To specify the return type of a function, you use the -> syntax followed by the type after the function's parameter list. Here are a few examples:
  - The typing module in Python provides a way to specify type hints for variables, function arguments, and return types. 
  - This improves code readability and helps tools like IDEs and linters to provide better support and error checking. 
  - Below is an explanation of each of the imported types along with examples of how they can be used.

      ```python
      from typing import List, Tuple, Optional, Union, Callable

      # Example 1: Basic Return Type
        def add(a: int, b: int) -> int:
            return a + b
            
      # Example 2: Returning None
        def print_message(message: str) -> None:
            print(message)

      # Example 3: Returning a List
        def get_numbers() -> List[int]:
            return [1, 2, 3, 4, 5]

      # Example 4: Returning a Tuple
        def get_user_info() -> Tuple[str, int]:
            return ("Alice", 30)

      # Example 5: Using Custom Types
        class User:
            def __init__(self, name: str, age: int):
                self.name = name
                self.age = age
        def get_user() -> User:
            return User("Bob", 25)

      # Example 6: Using Optional
        def find_item(items: List[str], item: str) -> Optional[str]:
            if item in items:
                return item
            return None

      # Example 7: Using Union
        def get_data(flag: bool) -> Union[str, int]:
            if flag:
                return "Data"
            else:
                return 42

      # Example 8: Using Callable
        def get_multiplier() -> Callable[[int], int]:
            def multiplier(x: int) -> int:
                return x * 2
            return multiplier

      # Usage:
        mypy filename.py            - This will display all the type errors in the program
      ```
  
  ## 28. Python Regular Expressions 

  - Regular expressions (regex) in Python are a powerful tool for matching patterns in text. They are handled through the re module. 
  - Here’s a comprehensive guide covering the main functionalities of regex with examples.

  - **Basic Concepts**  
    
      | Special Characters  | Description                                             |
      | ------------------- | ---------------------------------                       |
      |  .                  | Matches any character except newline                    |
      |  ^                  | Matches the start of the string                         |
      |  $                  | Matches the end of the string                           |
      |  *                  | Matches 0 or more repetitions of the preceding element  |
      |  +                  | Matches 1 or more repetitions of the preceding element  |
      |  ?                  | Matches 0 or 1 repetition of the preceding element; also used for non-greedy matching                   |
      |  {m}                | Matches repetitions of the preceding element exactly m times.                                           |
      |  {m,n}              | Matches repetitions of the preceding element from m-n times.                                            |
      |  []                 | Matches any one of the characters inside the brackets. Used to specify a character class.               |
      |  [^]                | Matches any one of the characters which are not inside the brackets. Used to specify a character class. |
      |  \|                 | Acts like a boolean OR. Matches either the expression before or the expression after the \|             |
      |  ()                 | Groups a pattern. Groups expressions and captures the matched text.                                     |
      |  \                  | Escapes special characters. Escapes a meta character, making it a literal character. Also used for special sequences like \d, \w, etc.|

  - **Character Classes**  
      
      |  Character Class  | Description                                                                     |
      | ----------------- | -----------------------------------------------------------------------------   |
      |  \A               | Matches the start of the string                                                 |
      |  \b               | Matches a word boundary                                                         |
      |  \B               | Matches a position that is not a word boundary                                  |
      |  \d               | Matches any digit (equivalent to [0-9])                                         |
      |  \D               | Matches any non-digit                                                           |
      |  \s               | Matches any whitespace character (spaces, tabs, line breaks)                    |
      |  \S               | Matches any non-whitespace character                                            |
      |  \w               | Matches any alphanumeric character plus underscore (equivalent to [a-zA-Z0-9_]) |
      |  \W               | Matches any non-alphanumeric character                                          |
      |  \Z               | Matches the end of the string                                                   |

  - **Functions in the re Module**  
  
      | RegEx Func  | Description                                                                 |
      | ----------- | ----------------------------------------------------------------------      |
      | re.match    | Checks for a match only at the beginning of the string.                     |
      | re.search   | Searches for the first occurrence of the pattern in the string.             |
      | re.findall  | Returns all non-overlapping matches of the pattern in the string.           |
      | re.finditer | Returns an iterator yielding match objects for all non-overlapping matches. |
      | re.sub      | Replaces occurrences of the pattern with a string.                          |
      | re.split    | Splits the string by occurrences of the pattern.                            |

  - **Assertions**  
      | Assertion  | Description                                                                                    |
      | ---------- | ---------------------------------------------------------------------------------------------- |
      |  (?=...)   | Positive lookahead assertion. Matches if ... matches next, but doesn’t consume any characters. |
      |  (?!...)   | Negative lookahead assertion. Matches if ... does not match next.                              |
      |  (?<=...)  | Positive lookbehind assertion. Matches if preceded by ... .                                    |
      |  (?<!...)  | Negative lookbehind assertion. Matches if not preceded by ... .                                |
      |  (?>...)   | Matches the following pattern in a possessive way, meaning it does not backtrack.              |
      |  (?:...)   | Groups a pattern. This is non capturing group.                                                 |

  ## Flags
  1. **re.IGNORECASE (OR) re.I**  
    - This flag tells the regex engine to ignore case of the character while matching the regex.
      ```python
      import re
      pattern = r"hello"
      text = "Hello world!"

      # Without IGNORECASE
      match = re.search(pattern, text)
      print(match)  # Output: None

      # With IGNORECASE
      match = re.search(pattern, text, re.IGNORECASE)
      print(match)  # Output: <re.Match object; span=(0, 5), match='Hello'>
      ```

  2. **re.MULTILINE (OR) re.M**  
    - This flag tells the regex engine that we want to match text over multiple lines. 
    - This flag changes the behavior of ^ and $ to match the start and end of each line in the string, not just the start and end of the entire string.
      ```python
      import re
      pattern = r"^hello"
      text = """hello world
      Goodbye world
      hello again"""

      # Without MULTILINE
      matches = re.findall(pattern, text)
      print(matches)  # Output: ['hello']

      # With MULTILINE
      matches = re.findall(pattern, text, re.MULTILINE)
      print(matches)  # Output: ['hello', 'hello']
      ```
        
  3. **re.DOTALL (OR) re.S**  
    - This flag tells the regex engine to match '.' with any character including new line character.
      ```python
      import re
      pattern = r"hello.*world"
      text = """hello
      world"""

      # Without DOTALL
      match = re.search(pattern, text)
      print(match)  # Output: None

      # With DOTALL
      match = re.search(pattern, text, re.DOTALL)
      print(match)  # Output: <re.Match object; span=(0, 11), match='hello\nworld'>
      ```    
    
  - When a pattern is not found in the string then these functions will return 'None' which can be used in 'if' statements.
      
      ```python
      import re

      # Sample text
        text = "The rain in Spain falls mainly in the plain. Call 123-456-7890 for info."

      # 1. re.match  - Checks if the string starts with the pattern r'The'. It does, so it returns a match object.
        match_result = re.match(r'The', text)
        print("re.match result:", match_result.group() if match_result else "No match")

      # 2. re.search - Looks for the first phone number pattern r'\d{3}-\d{3}-\d{4}'. It finds "123-456-7890".
        search_result = re.search(r'\d{3}-\d{3}-\d{4}', text)
        print("re.search result:", search_result.group() if search_result else "No match")

      # 3. re.findall - Finds all 4-letter words r'\b\w{4}\b' in the text. 
      #                 The result includes words like "rain", "call", "info".
        findall_result = re.findall(r'\b\w{4}\b', text)
        print("re.findall result:", findall_result)

      # 4. re.finditer -  Finds all occurrences of the word "in" and returns an iterator. 
      #                   Each match object provides the match and its position.
        finditer_result = re.finditer(r'\bin\b', text)
        print("re.finditer results:")
        for match in finditer_result:
          print(match.group(), "at position", match.span())

      # 5. re.sub - Replaces the phone number pattern with 'XXX-XXX-XXXX'.
        sub_result = re.sub(r'\d{3}-\d{3}-\d{4}', 'XXX-XXX-XXXX', text)
        print("re.sub result:", sub_result)

      # 6. re.split - Splits the text by any whitespace r'\s+', resulting in a list of words.
        split_result = re.split(r'\s+', text)
        print("re.split result:", split_result)
      ```

  - More examples:
    
    ```python
    # Using character classes
      char_class_result = re.findall(r'\d+', text)
      print("Character class \\d+ result:", char_class_result)

    # Using quantifiers
      quantifier_result = re.findall(r'\bin\b', text)
      print("Quantifier \\bin\\b result:", quantifier_result)

    # Using grouping
      grouping_result = re.search(r'(rain|Spain)', text)
      print("Grouping result:", grouping_result.group() if grouping_result else "No match")

    # Using special characters
      special_char_result = re.findall(r'\b\S+\b', text)
      print("Special characters \\b\\S+\\b result:", special_char_result)
    ```

  ## 29. Raw string vs Non-raw string examples
  - Always use raw strings (r'...') for regular expressions in Python.
  - Raw strings prevent backslashes from being interpreted as escape characters.
  - They improve readability and avoid common errors in regex patterns.
  - In Python strings, if you use multiple backslashes they will get interpreted as escape characters e.g. Try printing print('\\\\\Hi Rakesh')

    ```python
    import re

    # Example 1: Escaping backslashes
      pattern_raw = r'\d+'      # Raw string      : Matches one or more digits
      pattern_non_raw = '\\d+'  # Non-raw string  : Matches one or more digits

      text = "There are 123 numbers here."

    # Using raw string
      result_raw = re.findall(pattern_raw, text)
      print("Using raw string (r'\\d+'): ", result_raw)           # Output: ['123']
      
    # Using non-raw string
      result_non_raw = re.findall(pattern_non_raw, text)
      print("Using non-raw string ('\\\\d+'): ", result_non_raw)  # Output: ['123']

    # Example 2: Incorrect escaping without raw string
      pattern_incorrect = '\d+'  # Incorrect: Python interprets \d as an escape sequence

      try:
          result_incorrect = re.findall(pattern_incorrect, text)
          print(result_incorrect)
      except re.error as e:
          print("Error using incorrect escaping ('\\d+'): ", e)   # Output: Error: bad escape \d at position 0

    # Importance of raw strings for readability and correctness
    # Sample text
      text = "The rain in Spain falls mainly in the plain. Call 123-456-7890 for info."

    # Patterns with raw strings
      patterns = [
          r'\b\w{4}\b'            # Matches any 4-letter word
          r'\d{3}-\d{3}-\d{4}'    # Matches phone numbers in the format 123-456-7890
          r'\bin\b'               # Matches the word 'in' as a whole word
          r'\s+'                  # Matches one or more whitespace characters
          r'\b\S+\b'              # Matches words without any whitespace
          r'\\bin\\batch\\'       # Matches with the string '\bin\batch' 
      ]

    # Testing the patterns
      for pattern in patterns:
          result = re.findall(pattern, text)
          print(f"Pattern: {pattern} -> Matches: {result}")
    ```
  
  ## 30. group() method examples
  - group() method is used to retrive the matched substring from the input string
    
    ```python    
    import re

    # Example text
    text = "John Doe's phone number is 12345."
    
    # Define a regex pattern to extract the name and phone number
    pattern = r"(\w+) (\w+)'s phone number is (\d+)\."
    
    # Use re.search to find the first match
    match = re.search(pattern, text)
    
    if match:
        # Using group() to access matched groups
        print(match.groups())                   # A groups() expression returns a tuple containing all the subgroups of the match.
        full_match = match.group(0)             # entire match
        name = match.group(1)                   # first group (\w+)
        surname = match.group(2)                # second group (\w+)
        phone_number = match.group(3)           # third group (\d+)
       # Print results
        print("Full match:", full_match)
        print("Name:", name)
        print("Surname:", surname)
        print("Phone number:", phone_number)
    else:
        print("No match found")
    ```
  
  - groupdict()
    A groupdict() expression returns a dictionary containing all the named subgroups of the match, keyed by the subgroup name.
    
    ```python
    >>> m = re.match(r'(?P<user>\w+)@(?P<website>\w+)\.(?P<extension>\w+)','myname@hackerrank.com')
    >>> m.groupdict()
    {'website': 'hackerrank', 'user': 'myname', 'extension': 'com'}
    ```

  ## 31. Back referencing in Python regex
  - Back referencing in Python regex allows you to refer back to previously captured groups within the same regex pattern.
    
    ```python
    import re
    # Example text
    text = "aaa bbb ccc 111 222 333"

    # Define the regex pattern to match repeated alphanumeric sequences
    pattern = r"(\w)\1+"

    # Find all matches in the text
    matches = re.findall(pattern, text)

    # Print the matches
    print("Matches found:", matches)
    ```

  ## 32.  'Generator' Functions in Python
  - In Python, a generator function is a special type of function that returns an iterator. 
  - Instead of returning a single value, it uses the yield keyword to yield values one at a time, 
    pausing after each yield and resuming from where it left off when the next value is requested.
  - In short, generator functions return the result after each iteration of the loop instead of executing 
    all the iterations and returning the result in the end
  - This makes generators very memory efficient, especially for large data sets or streams of data.

  ### Key Features of Generator Functions
    
  |                     |                                                                                               |
  | ---------------     | ----------------------------------------------------------------------------------------------|
  | Lazy Evaluation     | Generators produce items only when requested, which can save memory.                          |
  | State Retention     | Generators maintain their state between yields, allowing them to resume where they left off.  |
  | Infinite Sequences  | Generators can produce infinite sequences because they yield one item at a time.              |
  | Single Iteration    | Generators can be iterated only once. After they are exhausted, they cannot be restarted.     |

  - Basic Generator Function
    
    ```python
    def simple_generator():
        yield 1
        yield 2
        yield 3

    # Usage of simple_generator
      gen = simple_generator()
      print(next(gen))                          # Output: 1
      print(next(gen))                          # Output: 2
      print(next(gen))                          # Output: 3
      # print(next(gen))                        # Uncommenting this line raises StopIteration
    ```

  - Generator for Fibonacci Sequence
    ```python
    def fibonacci():
        a, b = 0, 1
        while True:
            yield a
            a, b = b, a + b

    # Usage of fibonacci generator
    fib_gen = fibonacci()
    for _ in range(10):
        print(next(fib_gen))  # Outputs the first 10 Fibonacci numbers
    ```

  - Generator with `for` Loop
    ```python
    def countdown(n):
        while n > 0:
            yield n
            n -= 1

    # Usage of countdown generator
    for count in countdown(5):
        print(count)          # Outputs: 5, 4, 3, 2, 1
    ```
  - Sending Values to a Generator
    ```python
    def accumulator():
        total = 0
        while True:
            value = yield total
            if value is None:
                break
            total += value

    # Usage of accumulator generator
    gen = accumulator()
    print(next(gen))  # Initialize the generator, Output: 0
    print(gen.send(10))  # Send 10, Output: 10
    print(gen.send(20))  # Send 20, Output: 30
    gen.close()  # Close the generator
    ```
  - Generator Expressions
    ```python
    gen_expr = (x * x for x in range(10))
    for num in gen_expr:
      print(num)  # Outputs squares of numbers from 0 to 9
    ```

  - Chaining Generators
    ```python
    def generator_a():
        yield from range(3)

    def generator_b():
        yield from range(3, 6)

    def chain_generators():
        yield from generator_a()
        yield from generator_b()

    # Usage of chained generators
    for value in chain_generators():
        print(value)  # Outputs: 0, 1, 2, 3, 4, 5
    ```

  - Reading Large Files Efficiently
    
    ```python
    def read_large_file(file_path):
        with open(file_path) as file:
            while line := file.readline():
                yield line

    # Example function to process lines (dummy implementation)
    def process(line):
        print(line.strip())

    # Usage of read_large_file generator
    for line in read_large_file('large_file.txt'):
        process(line)  # Process each line without loading the whole file into memory
    ```

  ## 33. The 'reversed()' Function in Python

  - The reversed() function in Python is used to reverse the order of elements in a given sequence. 
  - It works with sequences like lists, tuples, and strings. 
  - It returns an iterator that accesses the given sequence in the reverse order, without modifying the original sequence.
    
    ```python
    # Reversing a list
      original_list = [1, 2, 3, 4, 5]
      reversed_list = list(reversed(original_list))
      print(reversed_list)                          # Output: [5, 4, 3, 2, 1]

    # Reversing a tuple
      original_tuple = (1, 2, 3, 4, 5)
      reversed_tuple = tuple(reversed(original_tuple))
      print(reversed_tuple)                         # Output: (5, 4, 3, 2, 1)

    # Reversing a string
      original_string = "hello"
      reversed_string = ''.join(reversed(original_string))
      print(reversed_string)                        # Output: "olleh"

    # Using reversed() in a loop
      for item in reversed([1, 2, 3, 4, 5]):
          print(item)
                                                    # Output:
                                                    # 5
                                                    # 4
                                                    # 3
                                                    # 2
                                                    # 1

    # Custom object with __reversed__() method
    class MyRange:
        def __init__(self, start, end):
            self.start = start
            self.end = end

        def __iter__(self):
            return iter(range(self.start, self.end))

        def __reversed__(self):
            return iter(range(self.end - 1, self.start - 1, -1))

    my_range = MyRange(1, 5)
    print(list(reversed(my_range)))  # Output: [4, 3, 2, 1]

    # Summary:
    # - reversed() returns an iterator that accesses the elements in reverse order.
    # - Works with lists, tuples, strings, and any custom object implementing __reversed__() or sequence protocol.
    ```

  ## 34.  The filter() Function in Python
  - The 'filter' function in Python is used to construct an iterator from elements of an iterable for which a function returns true.
  - Suppose we have a list of numbers and we want to filter out the even numbers from this list. Here's how you can do it using the filter function:
    
    ```python
    # Define a function that returns True if a number is even
      def is_even(number):
        return number % 2 == 0

    # List of numbers
      numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    # Use the filter function to get even numbers
      even_numbers = filter(is_even, numbers)

    # Convert the filter object to a list
      even_numbers_list = list(even_numbers)
      
    # Print the list of even numbers
      print(even_numbers_list)
    ```

  ## 35. try, except, raise and finally 
  - Exception Handling with try, except, else, and finally

      |                  |                                                                                                              |
      |  --------------  |  ------------------------------------------------------------------------------------------------------------|
      |  try Block       |   Code that might raise an exception is placed inside the try block.                                         |
      |  except Block    |   Code to handle the exception is placed inside the except block.                                            |
      |  else Block      |   Code that runs if no exception is raised is placed inside the else block.                                  |
      |  finally Block   |   Code that runs no matter what (whether an exception was raised or not) is placed inside the finally block. |
        
  1. Example of Raising Built-in Exceptions :-
    
      ```python
      def divide(a, b):
        if b == 0:
            raise ValueError("Cannot divide by zero.")
        return a / b

        try:
            result = divide(10, 0)
        except ValueError as e:
            print(e)                            # Output: Cannot divide by zero.
      ```

  2. Raising Custom Exceptions :-
      ```python 
      class CustomError(Exception):
          def __init__(self, message):
              self.message = message

          def check_value(x):
              if x < 0:
                  raise CustomError("Negative value error.")
              return x

          try:
              value = check_value(-10)
          except CustomError as e:
              print(e.message)                  # Output: Negative value error.
      ```

  3. Example of All Blocks :-
      ```python
      def divide(a, b):
          try:
              result = a / b
          except ZeroDivisionError as e:
              print(f"Error: {e}")
          else:
              print(f"Result: {result}")
          finally:
              print("Execution completed.")

      divide(10, 2)
                                                # Output:
                                                # Result: 5.0
                                                # Execution completed.

      divide(10, 0)
                                                # Output:
                                                # Error: division by zero
                                                # Execution completed.
      ```
  4.  Example of Multiple except Blocks :-
      ```python
      try:
          # Code that may raise an exception
          x = int(input("Enter a number: "))
          y = 10 / x
          print(f"The result is {y}")

      except ValueError:
          print("Invalid input! Please enter a valid number.")

      except ZeroDivisionError:
          print("Error! Division by zero is not allowed.")

      except Exception as e:
          print(f"An unexpected error occurred: {e}")
      ```

  5. Example of try-except-else Block :-
      ```python
      try:
          x = int(input("Enter a number: "))
      except Exception as e:
          print('Encontered an unexpected error')
      else:
          print(f'x is {x}')
      ```

  ## 36. Python Decorator 
  - A decorator is a function that takes another function and extends its behavior without explicitly modifying it. 
  - Decorators are often used in scenarios where cross-cutting concerns, such as logging, are needed.
        
    ```python    
    import functools
        
    # Basic decorator
      def my_decorator(func):
      @functools.wraps(func)
          def wrapper(*args, **kwargs):
              print("Before function call")
              result = func(*args, **kwargs)
              print("After function call")
              return result
          return wrapper
          
      @my_decorator
      def say_hello():
          print("Hello!")
          
          - Decorator with arguments
      def repeat(num_times):
      def decorator_repeat(func):
      @functools.wraps(func)
              def wrapper(*args, **kwargs):
                  for _ in range(num_times):
                      func(*args, **kwargs)
                      return wrapper
          return decorator_repeat
          
      @repeat(num_times=3)
      def greet(name):
      print(f"Hello, {name}!")
        
    # Class decorator
      def singleton(cls):
          instances = {}
          @functools.wraps(cls)
          def get_instance(*args, **kwargs):
          if cls not in instances:
                  instances[cls] = cls(*args, **kwargs)
              return instances[cls]
          return get_instance
          
      @singleton
      class MyClass:
          def __init__(self):
              print("Creating instance")
                
    # Multiple decorators
      def decorator_one(func):
          @functools.wraps(func)
          def wrapper(*args, **kwargs):
              print("Decorator One")
              return func(*args, **kwargs)
              return wrapper
          
              def decorator_two(func):
              @functools.wraps(func)
              def wrapper(*args, **kwargs):
              print("Decorator Two")
              return func(*args, **kwargs)
          return wrapper
          
      @decorator_one
      @decorator_two
      def say_goodbye():
          print("Goodbye!")
          
      say_hello()
                                                    # Output:
                                                    # Before function call
                                                    # Hello!
                                                    # After function call
            
      greet("Alice")
                                                    # Output:
                                                    # Hello, Alice!
                                                    # Hello, Alice!
                                                    # Hello, Alice!
            
      a = MyClass()
      b = MyClass()
      print(a is b)  # Output: True
            
      say_goodbye()
                                                    # Output:
                                                    # Decorator One
                                                    # Decorator Two
                                                    # Goodbye!
    ```
  -       
    | Decorator Type            |  Explanation                                                                                        |
    | --------------------------| -------------------------------------------------------------------------------------------------   |
    | Basic Decorator           |  my_decorator adds behavior before and after the 'say_hello' function call.                         |
    | Decorator with Arguments  |  repeat decorates greet to repeat the greeting three times.                                         |
    | Class Decorator           |  singleton ensures only one instance of MyClass is created.                                         |
    | Multiple Decorators       |  decorator_one and decorator_two both decorate say_goodbye, demonstrating the order of application. |


  ## 37. Abstraction in Python  
  - Abstraction is one of the four fundamental principles of Object-Oriented Programming (OOP). 
  - It refers to the concept of hiding the complex implementation details and showing only the essential features of an object. 
  - This helps in reducing complexity and allows the programmer to focus on interactions at a high level.

  ### Abstract Classes and Methods
  - In Python, abstraction can be achieved using abstract classes and abstract methods. 
  - An abstract class is a class that cannot be instantiated and often contains one or more abstract methods. 
  - These methods are declared, but contain no implementation. 
  - Abstract classes and methods are used to define a common interface for a group of subclasses.
    
  ### Using the abc Module
  - Python's abc module provides the infrastructure for defining abstract base classes (ABCs).

  - Defining an Abstract Class and Abstract Method
  - Here’s how you can define an abstract class and an abstract method in Python:
    1. Importing ABC and abstract method from abc module:
    2. Defining an Abstract Base Class (ABC):
    3. Defining Abstract Methods.
    
    ```python
    from abc import ABC, abstractmethod
  
    class Animal(ABC):
        @abstractmethod
        def sound(self):
            pass

        def sleep(self):
        print("This animal is sleeping")

    class Dog(Animal):
        def sound(self):
            print("Bark")

    class Cat(Animal):
        def sound(self):
            print("Meow")
            
    # Testing the classes
    # animal = Animal()   # This will raise an error because you can't instantiate an abstract class
    
    dog = Dog()
    dog.sound()           # Output: Bark
    dog.sleep()           # Output: This animal is sleeping

    cat = Cat()
    cat.sound()           # Output: Meow
    cat.sleep()           # Output: This animal is sleeping

    # Abstract Base Class (ABC) : Animal is defined with an abstract method sound that must be implemented by subclasses.
    # Concrete Subclasses       : Dog and Cat implement the sound method and inherit the sleep method.
    # Instantiation             : Animal cannot be instantiated directly. Instances of Dog and Cat can be created and used.
    ```

  ## 38.  Method Resolution Order (MRO) in Python
  - Method Resolution Order (MRO) is the order in which Python looks for a method in a hierarchy of classes. 
  - This is especially important in the context of multiple inheritance, where a class can inherit from multiple parent classes.

  - Python uses the C3 linearization algorithm (also known as C3 superclass linearization) to determine the MRO. 
  - The MRO ensures that a consistent and predictable method lookup order is followed.

 - MRO and super()  
    The MRO is used when the super() function is called to ensure that methods are called in the correct order, respecting the inheritance hierarchy.


  - Multiple inheritance
      
    ```python
      class A:
          def show(self):
              print("A")

      class B(A):
          def show(self):
              print("B")
              super().show()
              
      class C(A):
          def show(self):
              print("C")
              super().show()
              
      class D(B, C):
          def show(self):
              print("D")
              super().show()
              
      d = D()
      d.show()
                              # Output:
                              # D
                              # B
                              # C
                              # A
              
      print(D.__mro__)
                              # Output: (<class '__main__.D'>, <class '__main__.B'>, <class '__main__.C'>, <class '__main__.A'>, <class 'object'>)
              
      print(D.mro())
                              # Output: [<class '__main__.D'>, <class '__main__.B'>, <class '__main__.C'>, <class '__main__.A'>, <class 'object'>]
      ```
  - Singel Inheritance
    ```python
     class A:
         def show(self):
             print("A")
      class B(A):
         def show(self):
             print("B")
             super().show()
      b = B()
      b.show()
      
                              # Output:
                              #      B
                              #      A
    ```
  
  ## 39. Global Interpreter Lock (GIL) in Python
  - The Global Interpreter Lock (GIL) is a mutex that protects access to Python objects, preventing multiple threads from executing Python bytecode simultaneously. 
  - This lock is necessary because Python's memory management is not thread-safe.

  - Key Points about GIL
    1. **Concurrency**  
      GIL allows only one thread to execute Python code at a time even in a multi-threaded environment.

    2. **Performance**  
      The GIL can be a performance bottleneck in CPU-bound multi-threaded programs. However, I/O-bound programs can benefit from threading.

    3. **Implementation**  
      The GIL is specific to the CPython implementation of Python. Other implementations like Jython and IronPython do not have a GIL.

    ```python
    import threading
    import multiprocessing
    import time

    # CPU-bound task
      def cpu_bound_task():
          result = 0
          for i in range(10**6):
              result += i
          return result

    # I/O-bound task
      def io_bound_task():
          time.sleep(1)

    # CPU-bound task without threads
      start_time = time.time()
      cpu_bound_task()
      cpu_bound_task()
      print(f"CPU-bound task without threads: {time.time() - start_time:.2f} seconds")

    # CPU-bound task with threads
      start_time = time.time()
      thread1 = threading.Thread(target=cpu_bound_task)
      thread2 = threading.Thread(target=cpu_bound_task)
      thread1.start()
      thread2.start()
      thread1.join()
      thread2.join()
      print(f"CPU-bound task with threads: {time.time() - start_time:.2f} seconds")

    # I/O-bound task without threads
      start_time = time.time()
      io_bound_task()
      io_bound_task()
      print(f"I/O-bound task without threads: {time.time() - start_time:.2f} seconds")

    # I/O-bound task with threads
      start_time = time.time()
      thread1 = threading.Thread(target=io_bound_task)
      thread2 = threading.Thread(target=io_bound_task)
      thread1.start()
      thread2.start()
      thread1.join()
      thread2.join()
      print(f"I/O-bound task with threads: {time.time() - start_time:.2f} seconds")

    # CPU-bound task with multiprocessing
      start_time = time.time()
      process1 = multiprocessing.Process(target=cpu_bound_task)
      process2 = multiprocessing.Process(target=cpu_bound_task)
      process1.start()
      process2.start()
      process1.join()
      process2.join()
      print(f"CPU-bound task with multiprocessing: {time.time() - start_time:.2f} seconds")

    # Explanation:
      # 1. CPU-bound task without threads       : Runs sequentially.
      # 2. CPU-bound task with threads          : GIL prevents true parallelism, similar performance as sequential.
      # 3. I/O-bound task without threads       : Runs sequentially.
      # 4. I/O-bound task with threads          : Threads run concurrently, reducing total time.
      # 5. CPU-bound task with multiprocessing  : Processes run in parallel, bypassing the GIL.

      # Output Example:
      # CPU-bound task without threads        : 0.12 seconds
      # CPU-bound task with threads           : 0.14 seconds
      # I/O-bound task without threads        : 2.00 seconds
      # I/O-bound task with threads           : 1.00 seconds
      # CPU-bound task with multiprocessing   : 0.07 seconds
    ```

  ## 40. The 'with' Keyword in Python
  - The with keyword in Python is used to simplify exception handling and ensure that resources are properly managed. 
  - It is commonly used when dealing with file operations, but can also be used with other resource management scenarios such as locking, socket connections, etc.

  - Key Points
    
    1. **Context Managers**  
      The with keyword is used to create a context in which a context manager is active.
    
    2. **Resource Management**  
      Ensures that resources are properly acquired and released.
    
    3. **Automatic Cleanup**  
      Automatically handles cleanup actions, such as closing a file or releasing a lock, even if an error occurs within the block.

    ```PYTHON
    # Example: Using 'with' for file handling
    # Automatically closes the file after exiting the block
      with open('example.txt', 'w') as file:
          file.write('Hello, world!')

    # Custom Context Manager using a class
      class MyContextManager:
          def __enter__(self):
              print("Entering the context")
              return self

          def __exit__(self, exc_type, exc_value, traceback):
              print("Exiting the context")

      with MyContextManager() as manager:
          print("Inside the context")
    
    # Output:
    # Entering the context
    # Inside the context
    # Exiting the context

    # - Summary
    #   The with keyword        :   Simplifies resource management by ensuring proper acquisition and release.
    #   Context Managers        :   Objects that manage resources using __enter__ and __exit__ methods.
    #   Automatic Cleanup       :   Ensures resources like files are properly closed, even if errors occur.
    #   Custom Context Managers :   Can be created using classes or the contextlib module for more readable and maintainable code.
    ```

  ## 41. Static and class methods in Python
  - Both static and class methods are types of methods in Python classes, but they have different purposes and behaviors. Here's a detailed comparison:

  - Class Methods
    ```
      Decorator       : @classmethod
      First Parameter : The first parameter is always cls, which refers to the class itself, not the instance.
      Purpose         : Used to define methods that operate on the class itself, rather than instances of the class.
      Access          : Can access and modify class state that applies across all instances of the class.
                      : You do not need to instantiate the class to access the class method.
    ```

  - Static Methods
    ```
      Decorator       : @staticmethod
      First Parameter : No special first parameter (neither self nor cls).
      Purpose         : Used to define utility methods that perform a task in isolation and do not need access to class or instance data.
      Access          : Cannot access or modify the class state or instance state.
    ```  
      
    ```python
      class MyClass:
          class_variable = 0

          @classmethod
          def class_method(cls):
              cls.class_variable += 1
              print(f'Class variable is now {cls.class_variable}')

          @staticmethod
          def static_method(x, y):
              return x + y

      # Class Method Usage
      MyClass.class_method()  # Output: Class variable is now 1
      MyClass.class_method()  # Output: Class variable is now 2

      # Static Method Usage
      result = MyClass.static_method(5, 7)
      print(result)           # Output: 12

      # Summary:
      #   - Class Method    : Uses @classmethod, takes cls as first parameter, can modify class state.
      #   - Static Method   : Uses @staticmethod, takes no special first parameter, cannot modify class or instance state.
    ```
  
  ## 42. IPYTHON
 
  #### MAGIC FUNCTIONS 
  
  ```
    1. timeit                          →   This will run the code for bunch of times and will tell you how much time it took for execution.
    2. !ls                             →   This will execute shell command ls in python.
    3. %hist                           →   This will show history of commands issued.
    4. run some_file.py                →   Asks python to run the file some_file.py 
    5. %paste	                         →   This command will paste the contents of the clipboard.
    6. from itertools import product   →   Use this for taking cartesian product.
  ```

  ## 43. Exception Handling in Python | Python Tutorial - Day #36 CodeWithHarry 
  ```python
  try:
    for i in range(1,11):
      print(f'{int(a)} x {i} = {int(a)*i}')
  except Exception as e:
    print("Invalid Input!")

  # except block is executed only when there is an error. Execution of program does not halt it continues.
  # Handling multiple, standard errors in same try-except block.

  try:
    num = int(input("Enter an integer"))            
  except ValueError:
    print("Invalid Input!")
  except IndexError:
    print("Index Error")
  ```

  ## 44. Conda Virtual Environment Commands 

  ### 1. **Create Virtual environments using Anaconda and adding that virtual environment to the Jupyter Notebook.**  
    
  ```bash
  # It is recommended to install packages using conda and not using pip.
    
  conda create -n yourEnvName          
  (OR) conda create --name yourEnvName                          → Creates conda virtual environment with name 'yourEnvName'.
  (OR) conda create --name yourEnvName python=3.9 flask=2.1.3   → Creates conda virtual environment and install specified dependencies.
  
  conda activate yourEnvName             → Go to the virtual environment with name 'yourEnvName'.
  conda deactivate                       → Come out from the virtual environment with name 'yourEnvName'.
  conda install nameOfTheLibrary         → Install latest version of library with name 'nameOfTheLibrary'.
  conda install nameOfTheLibrary=2.1.3   → Install 2.1.3 version of library with name 'nameOfTheLibrary'.
  conda search nameOfTheLibrary          → Search the library with name 'nameOfTheLibrary'.
  conda list                             → Lists all the packages installed in the current conda virtual environment.
    
  conda env list                         
  (OR) conda info --envs                 → Lists all conda virtual environments on your system.
      
  All the dependencies of a virtual environment can be added inside a .yml file like below -
    1) vim requirements.yml  →  Open file
    2) Add following text to this file. 'name' is virtual environment name. Each dependency should have 2 leading spaces, 1 hyphen, 1 space 
        followed by dependency name and it's version.
          name: flask-app
            dependencies:
              - flash=2.1.3
    3) To update the environment with dependencies, issue following command which will install all the dependencies -
        conda env update --file requirements.yml

    4) Now, install ipkernal using following command 
        conda install ipykernel

    5) Now, add this virtual environment to the jupyter notebook
        → python -m ipykernel install --user --name=yourEnvName --display-name "Python (myenv)"

    6) Creating a new directory inside user's home directory viz '/home/rakesh/' for conda virtual environments and linking that directory with conda.
      → cd /home/rakesh/
      → mkdir conda-envs 
      → conda config --add /home/rakesh/conda-envs

    7) Default location where conda stores the environment variables -
      → /Users/$USERNAME/miniconda3/envs 
      → (or) C:\Users\$USERNAME\Anaconda3 

    8) jupyter-lab  → This is command to launch jupyter Lab from the terminal (or) from python virtual environment.
  ```
  
  ### 2. conda channels
  - In Conda, channels are locations (URLs or directories) where packages are stored and managed. 
  - When you install or update a package, Conda searches these channels to find the required package. 
  - Channels allow users to access curated and community-maintained repositories of software packages.
      
      ``` 
      default                 - channel is included by default in Conda installations, maintained by Anaconda, Inc., 
                              - and is curated for stability and compatibility
      conda-forge, bioconda   - channels maintained by the community and often contain newer or specialized packages
      ```

    - Channel Priority:
      1. Conda prioritizes higher-ranked channels when resolving package versions.
      2. You can configure strict channel priority to ensure that packages from lower-priority channels are ignored if they exist in higher-priority ones
      
      ```
      conda config --show channels
      conda config --add channels conda-forge           -> Add new channel, Adds 'conda-forge' to the list of channels.
      conda config --set channel_priority strict        -> Ensures that packages from higher-priority channels are always preferred
      conda install scipy -c conda-forge                -> Specify a channel for a single command using the -c option
      conda install scipy -c conda-forge -c defaults    -> Explicitly prioritize channels during installation, the first channel has the highest priority.
      conda config --prepend channels <channel>	        -> Add a channel with high priority globally.
      conda config --append channels <channel>	        -> Add a channel with low priority globally.
      conda config --show channels                      -> View your current channel configuration
      ```

  ### 3. To create a python virtual environment for a new project follow this video - https://www.youtube.com/watch?v=RUGm1Lwc55s
  -   
    ```bash
    Here, 'python -m venv' is a command for creating virtual environment where as 'venv' is the name of virtual environment which obviously you can change as per you and 'pathToYourPythonProject' is a directory inside which this environment is created.

    python -m venv pathToYourPythonProject/yourEnvironmentName 
    (OR) python -m venv yourEnvironmentName           →  If you are inside the project directory then issue this command.

    # Now, to select this virtual environment inside VS Code, follow following steps 

    1)  'ctrl+shift+p' (To Open command pallete) > Select Python Interpreter > Enter interpreter path > Find > Now, select the python from 
        the recently created virtual environment.(yourProjectFolder/venv/Scripts/Python)

    2)  Now, select 'command prompt' as your terminal type and issue following command in it :-
        'venv\Scripts\activate'      →  **** Note that you have to use 'backward Slash' in the besides command.

    3)  In case of 'Bash' terminal you need to issue following command -
        source ./localEnv/Scripts/activate     →  You will see your environment name within bracket once virtual env is activated.

    4)  Also, if you want to use 'Run' button for executing the program through command line then you can add path of 'python' script at the 
        beginning of the script as bash bang.

        #! C:\Users\rakes\PythonTutorialCodeWithHarry\venv\Scripts\python.exe
    ```
  
  ## 45. Flask command to run an app over an internet 
  
  ```
    python -m flash --app appFileName run --host=0.0.0.0  → Will give you an IP address where you can view your server or application. 
  ```

  ## 46. Python Built in Functions
  ```python
  abs()           :     Returns the absolute value of a number
  all()           :     Returns True if all items in an iterable object are true
  any()           :     Returns True if any item in an iterable object is true
  ascii()         :     Returns a readable version of an object. Replaces none-ascii characters with escape character
  bin()           :     Returns a binary version of a number
  bool()          :     Returns the boolean value of the specified object
                        The object will always return True, unless:
                          - The object is empty, like [], (), {}
                          - The object is False
                          - The object is 0
                          - The object is None

  bytearry()      :     Returns an array of bytes
  bytes()         :     Returns a bytes object
                        The bytes() function returns a bytes object.
                        It can convert objects into bytes objects, or create empty bytes object of the specified size.
                        The difference between bytes() and bytearray() is that bytes() returns an object that cannot be modified, 
                        and bytearray() returns an object that can be modified.

                        - Syntax
                          bytes(x, encoding, error)

  callable()      :     Returns True if the specified object is callable, otherwise False
  chr()           :     Returns a character from the specified Unicode code
  classmethod()   :     Converts a method into a class method
  
  compile()       :     Returns a specified source of an object, ready to be executed
  complex()       :     Return a complex number
  delattr()       :     Deletes the specified attribute (property or method) from the specified object
  dict()          :     Returns a dictionary (array)
  dir()           :     Returns a list of the specified object's properties and methods      '
                          - The dir() function returns all properties and methods of the specified object, without the values.

  divmod()        :     Returns the quotient and remainder when argument1 is divided by argument2
  enumerate()     :     Takes a collection (e.g. a tuple) and returns it as an enumerate object
  eval()          :     Evaluates and executes an expression

  exec()          :     Executes the specified code or object
                          - The exec() function executes the specified Python code.
                          - The exec() function accepts large blocks of code, unlike the eval() function which only accepts a single expression

  filter()        :     Use a filter function to exclude items in an iterable object
  float()         :     Returns a floating point number
  format()        :     Formats a specified value
  frozenset()     :     Returns a frozenset object
  getattr()       :     Returns the value of the specified attribute (property or method)
  globals()       :     Returns the current global symbol table as a directory
  hasattr()       :     Returns true if the specified object has the specified attribute (property/method)
  hash()          :     Returns the hash value of a specified object
  help()          :     Executes the built-in help system
  hex()           :     Converts a number into a hexadecimal value
  id()            :     Returns the id of the specified object
                          - The id() function returns a unique id for the specified object.
                          - All objects in Python has its own unique id.
                          - The id is assigned to the object when it is created.
                          - The id is the object's memory address, and will be different for each time you run the program.  '

  input()         :     Allowing the user input
  int()           :     Returns an integer number
  iter()          :     Returns an iterator object
  len()           :     Returns the length of the specified object
  list()          :     Returns a list
  locals()        :     Returns an updated dictionary of the current local symbol table
  map()           :     Returns the specified iterator with the specified function applied to each item
  max()           :     Returns the largest item in an iterable
  isinstance()    :     Returns True if a specified object is an instance of specified object
  issubclass()    :     Returns True if a specified class is a subclass of a specified object
  memoryview()    :     Returns a memory view object
  staticmethod()  :     Converts a method into static method
  min()           :     Returns the smallest item in an iterable
  next()          :     Returns the next item in an iterable
  object()        :     Returns a new object
  oct()           :     Converts a number into an octal
  open()          :     Opens a file and returns a file object
  ord()           :     Convert an iteger representing the Unicode of the specified character
  pow()           :     Returns the value of x to the power of y
  print()         :     Prints to the standard output device
  property()      :     Gets, sets, deletes a property
  range()         :     Returns a sequence of numbers, starting from 0 and increments by 1 (by default)
  repr()          :     Returns a readable version of an object
  reversed()      :     Returns a reversed iterator
  round()         :     Rounds a number
  set()           :     Returns a new set object
  setattr()       :     Sets an attribute (property/method) of an object
  slice()         :     Returns a slice object
  sorted()        :     Returns a sorted list
  str()           :     Returns a string object
  sum()           :     Sums the items of an iterator
  super()         :     Returns an object that represents the parent class
  tuple()         :     Returns a tuple
  type()          :     Returns the type of an object
  vars()          :     Return __dict__ property of an object
  zip()           :     Returns an iterator from two or more iterators
  ```