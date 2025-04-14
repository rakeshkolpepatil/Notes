
  ### <span style="color: #e1881c">  4. Collections  </span>
  
  #### <u> `4.1 Records ` </u>
  Records are a new feature introduced in Dart 3, designed to provide a lightweight and flexible way to group multiple values together without the need to define a dedicated class. They are particularly useful for returning multiple values from functions and for creating simple data structures.

  ### Characteristics of Records
  - **Anonymous**: Records do not have a specific name associated with them, which allows for quick and temporary data structures.
  - **Immutable**: Once created, the values in a record cannot be changed. This immutability ensures that records maintain a consistent state throughout their lifetime.
  - **Aggregate Type**: Records can bundle multiple values of different types into a single object, making them a fixed-size and heterogeneous alternative to lists or maps.

  ### Syntax and Usage

  #### Creating Records
  Records are defined using parentheses `()` and can contain both positional and named fields. Here are some examples -
  1. **Positional Record**
     ```dart
     var record = (1, 'a', 2.0);
     ```
  2. **Named Record**
     ```dart
     var record = (number: 1, string: 'a', float: 2.0);
     ```
  3. **Mixed Record**
     ```dart
     var record = (1, string: 'a', 2.0);
     ```

  #### Accessing Record Values
  You can access the values in a record using either positional or named access:
  - **Positional Access**:
    ```dart
    var record = (1, 'a', 2.0);
    print(record.$1);     // output: 1
    print(record.$2);     // output: a
    ```

  - **Named Access**:
    ```dart
    var record = (number: 1, string: 'a', float: 2.0);
    print(record.number);   // output: 1
    print(record.string);   // output: a
    ```

  #### Destructuring Records
  Dart allows destructuring of records, enabling you to unpack values into separate variables in one line
  ```dart
  final (number, string, float) = record;
  ```

  ### Practical Applications of Records
  1. **Returning Multiple Values** - Functions can return records to provide multiple outputs without needing complex data structures.
      ```dart
      (int min, int max) findMinMax(List<int> numbers) {
          int min = numbers.reduce((a, b) => a < b ? a : b);
          int max = numbers.reduce((a, b) => a > b ? a : b);
          return (min, max);
      }
      ```

  2. **Using Records in Data Structures** - Records can be used as types in other data structures or as parameters.
     ```dart
     typedef Card = (Suit, Rank);
     ```

  3. **Equality and Hashing**: Dart automatically implements `==` and `hashCode` for records based on their structure and values, allowing easy comparison between records.

### Conclusion

Records in Dart offer an efficient way to manage data by allowing developers to bundle multiple values together seamlessly. Their anonymous nature, immutability, and ability to return multiple values from functions enhance code clarity and type safety while reducing the need for boilerplate code associated with classes. This feature is expected to significantly improve how Dart applications are structured and written in the future [1][2][3].

Citations
  1. https://www.sandromaglione.com/articles/records-and-patterns-dart-language
  2. https://www.darttutorial.org/dart-tutorial/dart-record/
  3. https://www.dhiwise.com/post/dart-records-maximizing-performance-through-data-organization

  #### <u> `4.2 Lists` </u>
  - A List in Dart is an ordered group of objects, similar to arrays in other programming languages. 
  - Lists can contain elements of any type, including simple variables or complex objects. 
  - The elements in a List are indexed, meaning each element can be accessed via its position in the sequence, starting from index 0.

    ```dart
    void main() {

      // Example 1: add(value)
      var numbers = [1, 2, 3];
      numbers.add(4);             // Adds the value 4 to the end of the list; Output: [1, 2, 3, 4]

      // Example 2: addAll(iterable)
      numbers.addAll([5, 6]);     // Adds multiple values [5, 6] to the end; Output: [1, 2, 3, 4, 5, 6]

      // Example 3: asMap()
      var letters = ['a', 'b', 'c'];
      var map = letters.asMap();  // Converts the list to a Map with indices as keys; Output: {0: 'a', 1: 'b', 2: 'c'}

      // Example 4: cast<T>()
      var mixedList = [1, 'two', 3];
      // var intList = mixedList.cast<int>();   // Uncommenting this will throw an error since 'two' is not an 'int'

      // Example 5: clear()
      numbers.clear();                          // Removes all elements from the list; Output: []

      // Example 6: contains(value)
      numbers = [1, 2, 3];
      bool hasTwo = numbers.contains(2);        // Checks if the value '2' is in the list; Output: true

      // Example 7: elementAt(index)
      var secondElement = numbers.elementAt(1); // Accesses the element at index '1'; Output: 2

      // Example 8: every(test)
      bool allEven = numbers.every((n) => n % 2 == 0);      // Checks if all elements are even; Output: false

      // Example 9: firstWhere(test)
      var firstEven = numbers.firstWhere((n) => n.isEven);  // Finds the first even number in the list; Output: 2

      // Example 10: fold(initialValue, combine)
      var sum = numbers.fold(0, (prev, element) => prev + element); 
      // Sums all elements starting from initial value '0'; Output: sum is now '6'

      // Example 11: forEach(action)
      numbers.forEach((n) => print(n));                   // Executes a function for each element (prints each number)

      // Example 12: getRange(start, end)
      var sublist = [10,20,30,40].getRange(1,3).toList(); // Retrieves elements from index '1' to '3' (exclusive); Output: [20, 30]


       // Example13:indexOf(value)
       int index= numbers.indexOf(2); 
       // Returns the index of the first occurrence of value '2'; Output: index is now '1';

       // Example14:indexWhere(test)
       int indexOfFirstGreaterThan15 = numbers.indexWhere((n)=> n>15); 
       // Returns the index of the first element greater than '15'; Output will be '-1' since no element satisfies the condition.

       // Example15: insert(index,value)
       var list = [1, 3];
       list.insert(1, 2); 
       // Inserts value '2' at index '1'; Output becomes [1, 2, 3]

       // Example16: insertAll(index ,iterable)
       list.insertAll(0, [0]); 
       // Inserts multiple values from list [0] at index '0'; Output becomes [0, 1, 2, 3]

       // Example17: join(separator)
       var words= ['Hello' ,'World'];
       String sentence= words.join(' '); 
       print(sentence); 
       // Joins all elements into a single string separated by a space; Output is "Hello World"

       // Example18: remove(value)
       list.remove(2); 
       // Removes the first occurrence of value '2'; Output becomes [0, 1, 3]

       // Example19: removeAt(index)
       int removedValue= list.removeAt(0); 
       print(removedValue);
       // Removes and returns the element at index '0'; removedValue will be '0'; list becomes [1, 3]

       //Example20 : removeWhere(test)
        list.removeWhere((n)=> n<0);
        print(list);
        // Removes all elements that satisfy the condition (n <0); list will remain unchanged since no element satisfies the condition.

        //Example21 : setAll(index ,iterable)
        var newList=['a','b','c','d'];
        newList.setAll(0, ['x','y']);
        print(newList);
        // Replaces elements starting at index '0' with new values ['x', 'y']; newList becomes ['x','y','c','d']

        /// Properties Examples ///

        // Property: first
        int firstElement= numbers.first; 
        // Returns the first element in the list; Output depends on current state of numbers.

        // Property: isEmpty
        var emptyList= [];
        bool result= emptyList.isEmpty; 
        // Checks if the list is empty; Output will be 'true'.

        // Property: isNotEmpty
        var nonEmptyList= ['a'];
        bool resultNotEmpty= nonEmptyList.isNotEmpty; 
        // Checks if there are any elements in the list; Output will be 'true'.

        // Property: length
        int length= nonEmptyList.length; 
        // Returns the number of elements in the list; Output will be '1'.

        // Property: last
        String lastElement= nonEmptyList.last; 
        // Returns the last element in the list; Output will be 'a'.

        // Property: reversed
        Iterable reversedList= nonEmptyList.reversed; 
        // Provides an iterable with elements in reverse order; Output will be an iterable containing ['a'].

        // Method 1: Using forEach to iterate
        print("Using forEach:");
        reversedList.forEach((element) {
          print(element); // Prints each element in reverse order
        });

        // Method 2: Using a for loop to iterate
        print("Using for loop:");
        for (var element in reversedList) {
          print(element); // Prints each element in reverse order
        }

        // Creating a new list from the reversed iterable using toList()
        var reversedList = originalList.reversed.toList();

        // Creating a new list from the reversed iterable
        var reversedList = List.from(originalList.reversed);

        // Property: single
        var singleItemList= ['only one'];
        String singleItem= singleItemList.single; 
        // Returns the only element in the list if it has exactly one element; Output will be 'only one'.
      }   
    ```

  #### <u> `4.3 Sets ` </u>
  - In Dart, a Set is an unordered collection of unique items. 
  - Sets are particularly useful when you need to ensure that no duplicate values are stored and when the order of elements is not important. 
  - They provide efficient operations for adding, removing, and checking for the existence of elements.
  
  #### Characteristics of Sets
  - **Unordered**\
    The elements in a set do not have a specific order.

  - **Unique Elements**\
    A set cannot contain duplicate values.

  - **Dynamic Size**\
    Sets can grow and shrink as needed.

    
    ```dart
    void main() {
      // Example 1: Creating an empty set and adding elements
      var fruits = <String>{};                    // Create an empty set
      fruits.add('apple');                        // Add 'apple' to the set
      fruits.add('banana');                       // Add 'banana'
      print('Fruits after adding: $fruits');      // Output: {apple, banana}

      // Example 2: Adding multiple elements at once
      fruits.addAll({'orange', 'grape'});         // Add multiple elements
      print('Fruits after adding more: $fruits'); // Output: {apple, banana, orange, grape}

      // Example 3: Removing an element
      fruits.remove('banana');                    // Remove 'banana' from the set
      print('Fruits after removal: $fruits');     // Output: {apple, orange, grape}

      // Example 4: Checking if an element exists
      bool hasApple = fruits.contains('apple');   // Check if 'apple' is in the set
      print('Contains apple? $hasApple');         // Output: true

      // Example 5: Clearing the set
      fruits.clear();                             // Remove all elements from the set
      print('Fruits after clearing: $fruits');    // Output: {}

      // Example 6: Length and empty check
      var moreFruits = {'apple', 'banana'};
      print('Number of fruits: ${moreFruits.length}');  // Output: 2
      print('Is the set empty? ${moreFruits.isEmpty}'); // Output: false

      // Example 7: Union of sets
      var setA = {1, 2, 3};
      var setB = {3, 4, 5};

      var unionSet = {...setA, ...setB};          // Union operation using spread operator
      print('Union of sets A and B: $unionSet');  // Output: {1, 2, 3, 4, 5}

      // Example 8: Intersection of sets
      var intersectionSet = setA.intersection(setB);            // Intersection operation
      print('Intersection of sets A and B: $intersectionSet');  // Output: {3}

      // Example 9: Difference of sets
      var differenceSet = setA.difference(setB);                    // Difference operation
      print('Difference of sets A and B (A - B): $differenceSet');  // Output: {1, 2}
    }
    ```

  #### <u> `4.4 Maps ` </u>
  - In Dart, a Map is a collection of `key-value` pairs where each `key` is unique, and each key is associated with exactly one value. 
  - This structure allows for efficient data retrieval based on keys, making maps a powerful tool for organizing and managing data.
  - No restrictions on the type of data that is stored.
  - Can mutate their size based on requirements
  - all keys must be unique     

  - Characteristics of Maps
    - **Key-Value Pairs**\
      Each entry in a map consists of a key and its associated value.

    - **Unique Keys**\
      Keys must be unique within the map; however, values can be duplicated.

    - **Dynamic Size**\
      Maps can grow and shrink as needed.

    ```dart
    void main() {

      // Example 1: Creating an empty map and adding key-value pairs
      var gifts = <String, String>{};       // Create an empty map
      gifts['first'] = 'partridge';         // Add key-value pair
      gifts['second'] = 'turtledoves';      // Add another pair
      print('Gifts after adding: $gifts');  // Output: {first: partridge, 
                                            //          second: turtledoves}

      // Example 2: Adding multiple key-value pairs at once
      gifts.addAll({
        'third': 'golden rings',
        'fourth': 'calling birds'
      });                                       // Add multiple pairs at once
      print('Gifts after adding more: $gifts'); // Output: {first: partridge, 
                                                //          second: turtledoves, 
                                                //          third: golden rings, 

      // Example 3: Checking for keys and values
                                                //          fourth: calling birds}
      bool hasFirstKey = gifts.containsKey('first');    // Check if 'first' exists
      bool hasDoveValue = gifts.containsValue('doves'); // Check if any value contains 'doves'

      print('Contains "first" key? $hasFirstKey');    // Output: true
      print('Contains value "doves"? $hasDoveValue'); // Output: false

      // Example 4: Removing a key-value pair
      gifts.remove('first');                // Remove entry with key 'first'
      print('Gifts after removal: $gifts'); // Output: {second: turtledoves, third: golden rings, fourth: calling birds}

      // Example 5: Clearing the map
      gifts.clear();                          // Remove all entries from the map
      print('Gifts after clearing: $gifts');  // Output: {}

      // Example 6: Length and empty check
      var moreGifts = {'first': 'partridge'};

      print('Number of gifts: ${moreGifts.length}');            // Output: Number of gifts: 1
      print('Is the map empty? ${moreGifts.isEmpty}');          // Output: Is the map empty? false
      print('Is the map non-empty? ${moreGifts.isNotEmpty}');   // Output: Is the map non-empty? true

      // Example 7: Iterating over a map
      moreGifts.forEach((key, value) {
        print('$key: $value');        // Prints each key-value pair
                                      // Output:
                                      // first: partridge
      });

      // Example 8: Accessing keys and values
      var keys = moreGifts.keys;      // Get all keys
      var values = moreGifts.values;  // Get all values

      print('Keys: $keys');           // Output: Keys: (first)
      print('Values: $values');       // Output: Values: (partridge)
    }
    ```

  #### <u> `4.5 Queue ` </u>
  - In Dart, a Queue is a collection that follows the `First-In-First-Out (FIFO)` principle, meaning the first element added to the queue will be the first one to be removed. 
  - This data structure is particularly useful in scenarios such as `task scheduling`, `breadth-first search` algorithms, and managing resources in a controlled manner.
  
  #### Characteristics of Queues
  - **FIFO Order**\
    The first element added is the first to be removed.

  - **Dynamic Size**\
    Queues can grow and shrink as needed.

  - **No Random Access**\
    Elements cannot be accessed by index like in lists; they must be added or removed from the ends.
    
    ```dart
    import 'dart:collection';

    void main() {
      // Example 1: Creating a queue and adding elements
      Queue<int> myQueue = Queue<int>(); // Create an empty queue

      myQueue.add(10); // Add 10 to the end of the queue
      myQueue.add(20); // Add 20 to the end
      myQueue.add(30); // Add 30 to the end

      print('Queue after adding elements: $myQueue'); // Output: (10, 20, 30)

      // Example 2: Removing elements
      String removedItem = myQueue.removeFirst();     // Removes the first element (10)
      print('Removed: $removedItem');                 // Output: Removed: 10
      print('Queue after removal: $myQueue');         // Output: (20, 30)

      // Example 3: Checking length and empty status
      print('Is queue empty? ${myQueue.isEmpty}');    // Output: false
      print('Length of queue: ${myQueue.length}');    // Output: Length of queue: 2

      // Example 4: Iterating over a queue
      myQueue.add(40);                                // Add another element for demonstration
      myQueue.forEach((element) {
        print('Element in queue: $element');          // Output: prints each element in order
      });                                             // Output:
                                                      // Element in queue: 20
                                                      // Element in queue: 30
                                                      // Element in queue: 40

      // Example 5: Adding elements to both ends
      myQueue.addLast(40);                            // Adds 'Second Last' at the end
      myQueue.addFirst(10);                           // Adds 'First' at the front

      print('Queue after adding to both ends: $myQueue'); 
      // Output: Queue after adding to both ends: (10, 20, 30, 40)
    }
    ```

  #### <u> `4.6 Spread Operators ` </u>
  - Dart supports the spread operator (...) and the null-aware spread operator (...?) in list, 
    map, and set literals. 
  - Spread operators provide a concise way to insert multiple values into a collection.
  - spread operator (...) to insert all the values of a list into another list 
    
    ```dart 
    var list = [1, 2, 3];
    var list2 = [0, ...list];
    assert(list2.length == 4);
    ```

  - If the expression to the right of the spread operator might be null, you can avoid 
    exceptions by using a null-aware spread operator (...?)

    ```dart
    var list2 = [0, ...?list];
    assert(list2.length == 1);
    ```

  - Usage of spread operator 
    ```dart
      void main() {
      // Combining Lists
      var list1 = [1, 2, 3];
      var list2 = [4, 5, 6];
      var combinedList = [...list1, ...list2];
      print('Combined List: $combinedList');    // Output: [1, 2, 3, 4, 5, 6]

      // Adding Elements to Lists
      var numbers = [2, 3, 4];
      var newNumbers = [1, ...numbers];
      print('New Numbers: $newNumbers');        // Output: [1, 2, 3, 4]

      // Combining Maps
      var map1 = {'a': 'apple', 'b': 'banana'};
      var map2 = {'c': 'cherry', 'd': 'date'};
      var combinedMap = {...map1, ...map2};
      print('Combined Map: $combinedMap');      // Output: {a: apple, b: banana, c: cherry, d: date}

      // Adding Elements to Maps
      var countries = {'USA': 'Washington D.C.', 'France': 'Paris'};
      var newCountries = {'Germany': 'Berlin', ...countries};
      print('New Countries: $newCountries');    // Output: {Germany: Berlin, USA: Washington D.C., France: Paris}

      // Combining Sets
      Set<int> setA = {1, 2, 3};
      Set<int> setB = {3, 4, 5};
      Set<int> combinedSet = {...setA, ...setB};
      print('Combined Set: $combinedSet');      // Output: {1, 2, 3, 4, 5}

      // Null-aware Spread Operator
      List<int>? nullableList;
      var listWithNullCheck = [0, ...?nullableList];
      print('List with Null Check: $listWithNullCheck'); // Output: [0]

      // Inserting Elements Conditionally, It can also be used to conditionally insert elements based on the 
      // existence of other collections.
      List<String> friendsA = ['Alice', 'Bob'];
      List<String>? friendsB;
      var allFriends = [...friendsA, ...(friendsB ?? [])];
      print('All Friends: $allFriends'); // Output: [Alice, Bob]
    }
    ```

  #### <u> `4.7 Control-flow Operators ` </u>
  - Dart offers `collection if` and `collection for` for use in `list`, `map`, and `set` literals. 
  - You can use these operators to build collections using `conditionals (if)` and `repetition (for)`.
  - Here's an example of using `collection if` to create a list with three or four items in it:    

    ```dart
    // If 'promoActive' is true, the string 'Outlet' will be included in the list.
    var nav = ['Home', 'Furniture', 'Plants', if (promoActive) 'Outlet'];
    ```

  - Dart also supports if-case inside collection literals:
    
    ```dart
    var nav = ['Home', 'Furniture', 'Plants', if (login == 'Manager') 'Inventory'];
    ```
  
  - Here's an example of using `collection for` to manipulate the items of a list before adding them to 
    another list:
    
    ```dart 
    var listOfInts = [1, 2, 3];
    var listOfStrings = ['#0', for (var i in listOfInts) '#$i'];
    // The final value of `listOfStrings` will be - ['#0', '#1', '#2', '#3']

    // Checks if the second element (index 1) of 'listOfStrings' is equal to the string '#1'.
    assert(listOfStrings[1] == '#1');
    ```

  ### <u> `4.7 Typedefs ` </u>
  In Dart, a **typedef** is a way to create an alias for a function type. This feature enhances code readability and allows developers to define function signatures that can be reused throughout the codebase. While Dart encourages the use of inline function types, typedefs remain useful for defining complex function signatures and improving code organization.

  #### Key Features of Typedefs
  - **Function Signature Definition**: A typedef allows you to specify a function's parameters without including the return type. This helps in defining what kinds of functions can be assigned to a variable.
  - **Code Reusability**: By using typedefs, you can refer to a function type multiple times, reducing redundancy and enhancing maintainability.
  - **Type Safety**: Typedefs ensure that functions conform to specified parameter types, helping catch errors at compile time.

  #### Syntax of Typedefs
  The syntax for defining a typedef is as follows
  ```dart
  typedef AliasName = FunctionType;
  ```

  For example, if you want to define a `typedef` for a function that takes two integers and returns nothing, you would write
  ```dart
  typedef MathOperation = void Function(int, int);
  ```

  ### Assigning Functions to Typedef Variables
  Once a `typedef` is defined, you can assign functions that match its signature to variables of that typedef type. Here’s an example:

  ```dart
  typedef MathOperation = void Function(int, int);

  void sum(int a, int b) {
    print("Sum: ${a + b}");
  }

  void subtract(int a, int b) {
    print("Difference: ${a - b}");
  }

  void main() {
    MathOperation operation = sum;    // Assigning the sum function
    operation(5, 3);                  // Outputs: Sum: 8

    operation = subtract;             // Reassigning to the subtract function
    operation(5, 3);                  // Outputs: Difference: 2
  }
  ```

  ### Using Typedefs as Function Parameters
  `Typedefs` can also be used as parameters in other functions. This allows for higher-order functions that accept other functions as arguments.

  ```dart
  typedef MathOperation = void Function(int, int);

  void performOperation(MathOperation operation, int a, int b) {
    operation(a, b);
  }

  void main() {
    performOperation(sum, 10, 5);       // Outputs: Sum: 15
    performOperation(subtract, 10, 5);  // Outputs: Difference: 5
  }
  ```

  ### Conclusion
  `Typedefs` in Dart provide a powerful way to manage function types by creating aliases that enhance code clarity and maintainability. They allow developers to define reusable and type-safe function signatures that can be utilized throughout their applications. While inline function types are often preferred for simplicity, typedefs remain an important feature for more complex scenarios.

  ### Citations:
  1. https://www.tutorialspoint.com/dart_programming/dart_programming_typedef.htm
  2. https://www.geeksforgeeks.org/typedef-in-dart/
  3. https://www.javatpoint.com/dart-typedef
  4. https://mobikul.com/typedef-in-dart-programming-language/
  5. https://dart.dev/language/typedefs
  6. https://itnext.io/what-is-typedef-in-flutter-dart-c297a921d6c2?gi=a57ab4e774dc
  7. https://www.codingninjas.com/studio/library/dart-typedef
  8. https://stackoverflow.com/questions/12545762/what-is-a-typedef-in-dart


  ### <u> `4.8 Generics ` </u>
  `Generics` in Dart are a powerful feature that allows developers to write flexible, reusable, and type-safe code. By enabling functions, classes, and interfaces to operate on different data types while maintaining type safety, generics help create more versatile and maintainable applications.

  ### Key Features of Generics
  - **Type Safety**: Generics enforce type constraints on collections and functions, ensuring that only specified types can be used. This reduces runtime errors and enhances code reliability.
  - **Code Reusability**: By allowing the same code to work with different data types, generics minimize code duplication and improve maintainability.
  - **Flexibility**: Generics enable the creation of data structures and algorithms that can handle various data types without sacrificing type safety.

  ### Syntax of Generics

  The syntax for defining generics involves using angle brackets (`<>`) to specify type parameters. Here’s how it works:
  1. **Generic Class**:
     ```dart
     class Box<T> {
         T item;
         Box(this.item);
     }
     ```

  2. **Generic Function**:
     ```dart
     T first<T>(List<T> items) {
         return items[0];
     }
     ```

  3. **Generic Collection**:
     ```dart
     List<int> numbers = [1, 2, 3];
     Set<String> names = {'Alice', 'Bob'};
     Map<String, int> ages = {'Alice': 30, 'Bob': 25};
     ```

  ### Examples of Generics in Dart

  #### Generic Classes
  A generic class allows you to define a class with a placeholder for the data type:

  ```dart
  class Pair<K, V> {
      K key;
      V value;

      Pair(this.key, this.value);
  }

  void main() {
      var pair = Pair<int, String>(1, 'one');
      print('Key: ${pair.key}, Value: ${pair.value}');
  }
  ```

  #### Generic Functions

  Generic functions can accept parameters of various types:

  ```dart
  T getLast<T>(List<T> items) {
      return items.last;
  }

  void main() {
      var lastNumber = getLast<int>([1, 2, 3]);
      var lastString = getLast<String>(['a', 'b', 'c']);
      print('Last Number: $lastNumber');        // Outputs: Last Number: 3
      print('Last String: $lastString');        // Outputs: Last String: c
  }
  ```

  #### Generic Collections
  Dart's built-in collections like `List`, `Set`, and `Map` utilize generics to ensure type safety:
  - **Generic List**:
    ```dart
    List<String> fruits = ['Apple', 'Banana', 'Cherry'];
    ```

  - **Generic Set**:
    ```dart
    Set<int> uniqueNumbers = {1, 2, 3};
    ```

  - **Generic Map**:
    ```dart
    Map<String, double> prices = {'Apple': 1.5, 'Banana': 0.5};
    ```

  ### Conclusion
  Generics in Dart provide a robust mechanism for creating type-safe and reusable components. By allowing developers to define functions and classes that can operate on various data types while ensuring type safety, generics enhance code readability and maintainability. This feature is essential for building scalable applications that require flexibility in handling different data types without compromising on safety or performance.

  ### Citations:
  1. https://www.geeksforgeeks.org/dart-generics/
  2. https://www.javatpoint.com/dart-generics
  3. https://www.scaler.com/topics/flutter-tutorial/generics-in-dart/
  4. https://www.dhiwise.com/post/supercharge-your-flutter-apps-with-dart-generics
  5. https://www.tutorialspoint.com/dart_programming/dart_programming_generics.htm
  6. https://blog.stackademic.com/dart-generics-t-e6fd98e20d07?gi=756c7b9a38d5
  7. https://medium.flutterdevs.com/explore-generics-in-dart-flutter-6dd62b6f3ed4
  8. https://www.codevscolor.com/dart-generics


## What is difference between unmodifiableListView and cost list in Dart language ?

  Here's a breakdown of the differences between `List.unmodifiable()`, `UnmodifiableListView`, and `const List` in Dart:

**1. `List.unmodifiable(list)`**

*   Creates a new `List` object that is a copy of the original list [1].
*   The created copy cannot be mutated [1].
*   Mutating the original `List` will not affect the copy [1].
*   It's always safe because it is not a view and actually creates a new list [2].

**2. `UnmodifiableListView(list)`**

*   Creates an unmodifiable *view* of another `List`[3][6]. It's a wrapper around the original `List`[1].
*   It doesn't create a new list; it just provides a read-only view of the original[7].
*   Changes to the original `List` *are* reflected in the `UnmodifiableListView` [1][3][6].
*   Attempts to modify the `UnmodifiableListView` will result in an error [3][6].
*   Faster than `List.unmodifiable` because it doesn't copy the list [2].

**3. `const List`**

*   Creates a list that is compile-time constant [4].
*   The list and its elements must be known at compile time [4].
*   Cannot be modified after creation [4].
*   The VM actually uses the same class for both const lists and unmodifiable lists [4].
*   There is no difference between a const list object and a list created using `List.unmodifiable`[4]. They're instances of the same implementation class [4].

**In Summary:**

| Feature            | `List.unmodifiable(list)`          | `UnmodifiableListView(list)`   | `const List`             |
| ----------------   | -----------------------------------| ------------------------------ | ------------------------ |
| **Creation**       | Creates a new copied list [1]      | Creates a view (wrapper) of the original list[1][3]  | Creates a compile-time constant list [4]                                 |
| **Mutability**     | Cannot be modified [1]             | Cannot be modified through the view [3][6]            | Cannot be modified [4]                   |
| **Original List**  | Modifications to the original list do NOT affect the new list [1] | Modifications *to* the original list *are* visible through the unmodifiable list view [1][3][6] | N/A       |
| **Performance**    | Slower (due to copying) [2]        | Faster (no copying)[2]  | N/A |
| **Safety**         | Always safe [2]                     | Modifications to the original list will affect the view [2] | Safe (as it's immutable at compile time) [4]             |
| **Implementation** | Creates a new unmodifiable list [1] | Wraps an existing list [1][3]      | Same implementation class as `List.unmodifiable()`[4]   |

**When to use which:**

*   Use `List.unmodifiable()` when you need a completely independent, immutable copy of a list [1].  Changes to the original list should not affect the unmodifiable list.
*   Use `UnmodifiableListView()` when you want a fast, read-only view of an existing list, and you're okay with the view reflecting changes made to the original list [1][3][6]. This is useful for preventing modification through a specific interface while still allowing the original list to be updated elsewhere. It's good for encapsulation and safety [8].
*   Use `const List` when you need a list that is known at compile time and will never change [4]. This is useful for constants and improving performance.

Citations:
1. https://stackoverflow.com/a/61404767
2. https://pub.dev/documentation/elemental/latest/elemental/UnmodifiableListFromIList-class.html
3. https://api.dart.dev/dart-collection/UnmodifiableListView-class.html
4. https://stackoverflow.com/questions/65015226/whats-the-difference-between-a-const-list-and-unmodifiable-list
5. https://github.com/dart-lang/sdk/issues/30519
6. https://api.flutter.dev/flutter/dart-collection/UnmodifiableListView-class.html
7. https://dart.academy/immutable-data-patterns-in-dart-and-flutter/
8. https://github.com/filiph/state_experiments/issues/5

## Cascade Operator 
The cascade operator (`..`) in Dart is particularly useful when you want to perform multiple operations on the same object without repeatedly referencing that object. Here’s an example where the cascade operator is preferred over traditional method chaining:

### Example: Using the Cascade Operator

Suppose you have a class `Person` that has several properties and methods. You want to create an instance of `Person` and set multiple properties in a concise manner.

```dart
class Person {
  String? name;
  int? age;

  void greet() {
    print('Hello, my name is $name and I am $age years old.');
  }
}

void main() {
  // Using the cascade operator
  var person = Person()
    ..name = 'Alice'
    ..age = 30
    ..greet();      // Output: Hello, my name is Alice and I am 30 years old.
}
```

### Why Use the Cascade Operator?

1. **Conciseness** \
  The cascade operator allows you to set multiple properties and call methods on the same object without repeating the object reference. This makes the code cleaner and easier to read.

2. **Avoiding Temporary Variables**\
  You don’t need to create a temporary variable to hold the reference to the object. The cascade operator handles it for you.

3. **Fluent Interface**\
  It promotes a fluent interface style, making it clear that these operations are related to the same object.

### Comparison with Method Chaining

If you were to use method chaining instead, you would have to write:

```dart
void main() {
  var person = Person();
  person.name = 'Alice';
  person.age = 30;
  person.greet();     // Output: Hello, my name is Alice and I am 30 years old.
}
```

While this works, it requires more lines of code and is less visually appealing than using the cascade operator.

### Conclusion

In scenarios where you need to perform multiple operations on a single object, using the cascade operator (`..`) is preferred over method chaining because it enhances readability, reduces redundancy, and allows for a more fluid coding style.

### Citations:
1. https://www.youtube.com/watch?v=cZsbNeh3FB8
2. https://dart.dev/language/operators
3. https://dev.to/ranggakd/cascade-notation-and-fluent-interface-in-dart-3gc7
4. https://www.youtube.com/watch?v=z0DsnQeQn6k
5. https://stackoverflow.com/questions/17025769/how-do-method-cascades-work-exactly-in-dart
6. https://dart.dev/tools/linter-rules/cascade_invocations
7. https://www.linkedin.com/pulse/mastering-dart-cascades-write-cleaner-code-method-hector-waldmann-g8z5f
8. https://www.tutorialspoint.com/cascade-notation-in-dart-programming



## Method Chaining vs. Cascade Operator
### Version 1:
```dart
final result4 = { 
  for(final String char in s.split('')) 
    'abc'.contains(char) ? null : char 
}.where((e) => e != null)
  .toList()
  .join('');
```

### Version 2:
```dart
final result4 = { 
  for(final String char in s.split('')) 
    'abc'.contains(char) ? null : char 
}.where((e) => e != null)
  ..toList()
  ..join('');
```

### Key Differences:

1. **Method Chaining vs. Cascade Operator**:
   - **Version 1** uses standard method chaining. Each method (`where`, `toList`, `join`) is called in sequence, and the return value of each method is passed to the next.
   - **Version 2** uses the cascade operator (`..`). This operator allows you to call multiple methods on the same object without having to repeat the object reference. However, it does not change the return value of the last method in the chain.

2. **Return Value**:
   - In **Version 1**, the final expression evaluates to a `String` because `join('')` returns a string that concatenates all elements of the list.
   - In **Version 2**, while it appears similar, the use of cascade means that `toList()` and `join('')` are called on the result of `where`, but since they are chained with `..`, the overall expression still returns the original set (the result of `where`). The final output will not be a string, and you won't get a concatenated result as intended.

3. **Final Result**:
   - **Version 1** correctly produces a string by filtering out nulls and joining remaining characters.
   - **Version 2** would likely lead to an error or unexpected behavior because it doesn't return what you might expect (a concatenated string). The cascade operator does not change what is returned from `where`.

### Conclusion

In summary, **Version 1** is correct and will give you a string with characters from `s` that are not in `'abc'`. **Version 2**, on the other hand, will not work as intended due to how method chaining and cascading operate in Dart. If you want to achieve the desired result of filtering and joining characters into a string, you should use Version 1.

Citations:
1. https://fluttermaster.com/method-chaining-using-cascade-in-dart/
2. https://www.ictdemy.com/software-design/design-patterns/method-chaining-and-method-cascading
3. https://www.youtube.com/watch?v=qq_OwBIZei4
4. https://news.dartlang.org/2012/02/method-cascades-in-dart-posted-by-gilad.html
5. https://dart.dev/effective-dart/design
6. https://dart.dev/tools/linter-rules/avoid_returning_this
7. https://stackoverflow.com/questions/55802431/how-to-write-chain-functions-dart
8. https://github.com/dart-lang/dart_style/issues/756
