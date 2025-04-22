# 🧰 STL Overview
- STL (Standard Template Library) provides generic and reusable class templates and functions.
- Divided into `Containers`, `Algorithms`, `Iterators`, `Function Objects`, `Allocators`, and `Adapters`.

## 📦 Containers
- Containers store collections of objects.
- Three types:
  1. **Sequence containers** – linear data : `vector`, `deque`, `list`
  2. **Associative containers** – sorted data : `set`, `map`, `multiset`, `multimap`
  3. **Unordered containers** – hashed data : `unordered_set`, `unordered_map`, etc.

##  `std::vector`
### ✅ Key Features 
- Dynamic array (`resizable`)
- Fast random access : `O(1)`
- Insert/remove at end : `O(1) amortized`
- Insert/remove at middle/start : `O(n)`

### 🧱 Declaration

```cpp
std::vector<int> v;                    // empty vector
std::vector<int> v(5);                 // 5 default-initialized elements
std::vector<int> v(5, 10);             // 5 elements with value 10
std::vector<int> v2 = {1, 2, 3};       // initializer list
```
- The `std::vector<int>` creates a vector of size 5, and initializes all elements to 0.
  
  ```cpp
  std::vector<int> v(5);
  ```
#### 🔍 Why?
- `std::vector<int> v(5);`

  - Creates a vector of 5 ints, **value-initialized** (because `int` is a built-in type). 
  - Built-in types like `int` are **zero-initialized** when value-initialized. 
  - So the content is: [0, 0, 0, 0, 0].

### 🔁 Iteration

```cpp
for(int i : v) { }                                 // range-based
for(auto it = v.begin(); it != v.end(); ++it) { }  // iterator
```

### ⚙️ Capacity vs Size
- **size** = number of actual elements
- **capacity** = number of allocated slots (may be more than size)

### 🧠 Tips
- Vectors store elements **contiguously** in memory.
- Prefer `emplace_back()` over `push_back()` for `efficiency` (constructs in-place).
- Inserting at the middle or beginning is inefficient – use `deque` or `list` for frequent such ops.
- In Vector, `.at()` is Safe where as `[]` is unsafe memory access.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30};

    // size(): returns the number of elements
    std::cout << "Size: " << v.size() << std::endl;
    // Output: Size: 3

    // capacity(): returns the allocated storage size (may be >= size)
    std::cout << "Capacity: " << v.capacity() << std::endl;
    // Output (may vary): Capacity: 3

    // empty(): checks whether the container is empty
    std::cout << "Is empty? " << std::boolalpha << v.empty() << std::endl;
    // Output: Is empty? false

    // push_back(): adds an element at the end
    v.push_back(40);
    std::cout << "After push_back(40): ";
    for (int i : v) 
      std::cout << i << " ";
    std::cout << std::endl;
    // Output: After push_back(40): 10 20 30 40 

    // pop_back(): removes the last element
    v.pop_back();
    std::cout << "After pop_back(): ";
    for (int i : v) 
      std::cout << i << " ";
    std::cout << std::endl;
    // Output: After pop_back(): 10 20 30 

    // front(): returns reference to the first element
    // back(): returns reference to the last element
    std::cout << "Front: " << v.front() << ", Back: " << v.back() << std::endl;
    // Output: Front: 10, Back: 30

    // at(i): returns element at position i (with bounds checking) safe memory access
    std::cout << "Element at index 1: " << v.at(1) << std::endl;
    // Output: Element at index 1: 20

    // operator[]: returns element at position i (no bounds checking) unsafe memory access
    std::cout << "Element at index 2 using []: " << v[2] << std::endl;
    // Output: Element at index 2 using []: 30

    // insert(): inserts element before specified position
    v.insert(v.begin() + 1, 15);
    std::cout << "After insert at index 1: ";
    for (int i : v) 
      std::cout << i << " ";
    std::cout << std::endl;
    // Output: After insert at index 1: 10 15 20 30 

    // erase(): removes element at specified position
    v.erase(v.begin() + 2);
    std::cout << "After erase at index 2: ";
    for (int i : v) 
      std::cout << i << " ";
    std::cout << std::endl;
    // Output: After erase at index 2: 10 15 30 

    // resize(): resizes vector to contain n elements; fills with value if growing
    v.resize(5, 99);
    std::cout << "After resize to 5: ";
    for (int i : v) 
      std::cout << i << " ";
    std::cout << std::endl;
    // Output: After resize to 5: 10 15 30 99 99 

    // shrink_to_fit(): requests reduction of capacity to fit size
    v.shrink_to_fit();
    std::cout << "After shrink_to_fit(), Capacity: " << v.capacity() << std::endl;
    // Output (may vary): After shrink_to_fit(), Capacity: 5

    // swap(): exchanges the contents with another vector
    std::vector<int> v2 = {1, 2, 3};
    v.swap(v2);
    std::cout << "After swap with v2, v: ";
    for (int i : v) std::cout << i << " ";
    std::cout << "\nAfter swap with v2, v2: ";
    for (int i : v2) std::cout << i << " ";
    std::cout << std::endl;
    // Output:
    // After swap with v2, v: 1 2 3 
    // After swap with v2, v2: 10 15 30 99 99 

    // clear(): removes all elements
    v.clear();
    std::cout << "After clear(), size: " << v.size() << ", Is empty? " << v.empty() << std::endl;
    // Output: After clear(), size: 0, Is empty? true

    return 0;
}
```

### Iterate over `std::vector` using iterators in C++

  ```cpp
  #include <iostream>
  #include <vector>
  
  int main() {
      std::vector<int> numbers = {10, 20, 30, 40, 50};
  
      std::cout << "Iterating using iterator: ";
      // begin() returns iterator to the first element
      // end() returns iterator to one-past-the-last element
      for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
          std::cout << *it << " ";  // Dereference iterator to get value
      }
      std::cout << std::endl;
  
      std::cout << "Iterating using const_iterator (read-only): ";
      for (std::vector<int>::const_iterator it = numbers.cbegin(); it != numbers.cend(); ++it) {
          std::cout << *it << " ";
      }
      std::cout << std::endl;
  
      std::cout << "Reverse iteration using reverse_iterator: ";
      for (std::vector<int>::reverse_iterator rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
          std::cout << *rit << " ";
      }
      std::cout << std::endl;
  
      std::cout << "Range-based for loop (internally uses iterators): ";
      for (int val : numbers) {
          std::cout << val << " ";
      }
      std::cout << std::endl;
  
      return 0;
  }
  ```
- ✅ Output:
  
  ```pgsql
  Iterating using iterator: 10 20 30 40 50 
  Iterating using const_iterator (read-only): 10 20 30 40 50 
  Reverse iteration using reverse_iterator: 50 40 30 20 10 
  Range-based for loop (internally uses iterators): 10 20 30 40 50 
  ```

##  `std::list`

### ✅ Key Features of std::list
- **Doubly Linked List**: Each element points to both the next and previous elements.
- **Efficient Insertion/Deletion**: Constant time (`O(1)`) insertion and deletion at any position (given iterator).
- **No Random Access**: Unlike `vector`, it doesn't support direct access via index (`lst[2]` is invalid).
- **Bidirectional Iterators**: Supports forward and backward traversal.
- **Stable Iterators**: Inserting or removing elements does not invalidate iterators (except erased ones).

### 🧾 Different Ways to Declare and Initialize a `list`

```cpp
#include <list>

// Empty list of integers
std::list<int> lst1;

// List initialized with 5 default-initialized elements (0s for int)
std::list<int> lst2(5); // {0, 0, 0, 0, 0}

// List initialized with 4 elements, all set to 100
std::list<int> lst3(4, 100); // {100, 100, 100, 100}

// List initialized from an array
int arr[] = {10, 20, 30};
std::list<int> lst4(arr, arr + 3); // {10, 20, 30}

// List initialized using initializer list
std::list<int> lst5 = {1, 2, 3, 4, 5};

// List initialized by copying another list
std::list<int> lst6(lst5);

// List initialized using move constructor
std::list<int> lst7(std::move(lst6));
```

### 💡 Tips for Using `std::list` Effectively

1. **Use `list` when frequent insertions/deletions in the middle or front/back are needed**.
    - `push_front`, `push_back`, `insert`, and `erase` are efficient.

2. **Avoid `list` when you need random access.**
    - If you often need to access `i-th` element, use `vector` or `deque` instead.

3. **Always sort before using `merge()` or `unique()`**.
    - These functions assume the list is sorted. Otherwise, the results are unpredictable.

4. **Use `remove()` to delete by value**.
    - This is simpler than manually searching and erasing values.

5. **Splice content between lists without copying.**
    - `splice()` moves elements between lists in constant time.

6. **Prefer using iterators** to navigate and manipulate elements.
    - Especially for `insert()` and `erase()`.

7. **Use `reverse()` when order needs to be reversed in-place efficiently**.
    - `std::reverse()` from `<algorithm>` won't work with `std::list` since it requires random access.


```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {10, 20, 30};

    lst.push_back(40);    // Adds 40 at the end
    lst.push_front(5);    // Adds 5 at the beginning
    // List: 5 10 20 30 40

    std::cout << "After push_back & push_front: ";
    for (int val : lst) std::cout << val << " "; std::cout << "\n";
    // Output: 5 10 20 30 40

    lst.pop_back();       // Removes last element (40)
    lst.pop_front();      // Removes first element (5)
    // List: 10 20 30

    std::cout << "After pop_back & pop_front: ";
    for (int val : lst) std::cout << val << " "; std::cout << "\n";
    // Output: 10 20 30

    auto it = lst.begin();
    std::advance(it, 1);  // Move iterator to second element
    lst.insert(it, 25);   // Insert 25 before second element
    // List: 10 25 20 30

    std::cout << "After insert at position 2: ";
    for (int val : lst) std::cout << val << " "; std::cout << "\n";
    // Output: 10 25 20 30

    it = lst.begin();
    std::advance(it, 2);  // Move iterator to third element (20)
    lst.erase(it);        // Erase 3rd element (20)
    // List: 10 25 30

    std::cout << "After erase at position 3: ";
    for (int val : lst) std::cout << val << " "; std::cout << "\n";
    // Output: 10 25 30

    lst.remove(25);       // Removes all elements equal to 25
    // List: 10 30

    std::cout << "After remove(25): ";
    for (int val : lst) std::cout << val << " "; std::cout << "\n";
    // Output: 10 30

    lst.reverse();        // Reverses the list
    // List: 30 10

    std::cout << "After reverse(): ";
    for (int val : lst) std::cout << val << " "; std::cout << "\n";
    // Output: 30 10

    lst.sort();           // Sorts the list in ascending order
    // List: 10 30

    std::cout << "After sort(): ";
    for (int val : lst) std::cout << val << " "; std::cout << "\n";
    // Output: 10 30

    std::list<int> lst2 = {100, 200};
    lst.merge(lst2);      // Merges lst2 into lst (both must be sorted)
    // List: 10 30 100 200

    std::cout << "After merge with {100, 200}: ";
    for (int val : lst) std::cout << val << " "; std::cout << "\n";
    // Output: 10 30 100 200

    std::list<int> dupList = {10, 20, 20, 30, 30, 30, 40};
    dupList.unique();     // Removes consecutive duplicates
    // List: 10 20 30 40

    std::cout << "After unique() on {10,20,20,30,30,30,40}: ";
    for (int val : dupList) std::cout << val << " "; std::cout << "\n";
    // Output: 10 20 30 40

    std::list<int> list1 = {1, 2, 3};
    std::list<int> list2 = {10, 20, 30};

    // Splice all elements of list2 into list1 before position 'it'
    // list1.splice(it, list2); inserts all elements of list2 into list1 before iterator it.
    list1.splice(list1.begin()+1, list2);
    
    // Output the lists after splicing
    std::cout << "list1 after splice: ";
    for (int val : list1) std::cout << val << " ";
    std::cout << "\n";
                                    // Output: list1 after splice: 1 10 20 30 2 3 

    std::cout << "list2 after splice: ";
    for (int val : list2) std::cout << val << " ";
    std::cout << "\n";
                                    // Output: list2 after splice: 
                                    // list2 becomes empty.
    return 0;
}
```

## `std::deque` (Double-Ended Queue) 

### 🔑 Key Features
- Sequence container allowing **fast insertions and deletions at both ends**.

- Random access supported (like vector).
- Internally implemented as a **set of chunks** to efficiently manage both front and back.
- Slower than `vector` for accessing elements due to non-contiguous memory, but faster for push/pop at both ends.
- Does not invalidate iterators on push/pop at either end (unlike `vector` which invalidates on reallocation).


### 🛠️ Declaration Examples
```cpp
std::deque<int> dq1;                    // Empty deque
std::deque<int> dq2(5);                 // 5 default-initialized elements (0s)
std::deque<int> dq3(5, 10);             // 5 elements with value 10
std::deque<int> dq4 = {1, 2, 3, 4};     // Initialization using initializer list
```

### ✅ Common Methods with Examples and Comments
```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {10, 20, 30};

    dq.push_front(5);   // Adds 5 at the beginning
    dq.push_back(40);   // Adds 40 at the end

    dq.pop_front();     // Removes the first element (5)
    dq.pop_back();      // Removes the last element (40)

    std::cout << "Front: " << dq.front() << "\n";   // Access first element
    std::cout << "Back: " << dq.back() << "\n";     // Access last element

    dq.insert(dq.begin() + 1, 25);                  // Inserts 25 at position 1
    dq.erase(dq.begin());                           // Erases the first element

    std::cout << "Size: " << dq.size() << "\n";     // Returns number of elements

    dq.clear();                                     // Removes all elements from deque

    // Output current deque state
    std::cout << "Deque after clear: ";
    for (int num : dq) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}

/*
Output:
        Front: 20
        Back: 30
        Size: 3
        Deque after clear:
*/
```

### 🔁 Iterating Over a Deque
```cpp
std::deque<int> dq = {10, 20, 30};

for (auto it = dq.begin(); it != dq.end(); ++it)
    std::cout << *it << " ";  // 10 20 30

for (int val : dq)
    std::cout << val << " ";  // 10 20 30
```

### 💡 Tips
- Use `deque` when you need **frequent insertions/removals at both ends**.
- Prefer `vector` when you only need to **insert/remove at the back** and want better cache performance.
- Avoid inserting/removing in the **middle** frequently — `list` is better for that.

## `std::set` 

### 🔑 Key Features
- **An associative container** that stores **unique elements** in a **sorted order**.
- Elements are automatically sorted based on the **comparison operator** (default: `<`).
- **No duplicate values allowed**.
- Based on **balanced binary search tree** (typically `Red-Black Tree`).
- Provides **logarithmic time** complexity for `insert`, `erase`, and `find` operations.
- Iterators are bidirectional (`std::set<T>::iterator`).

### 🛠️ Declaration Examples
```cpp
std::set<int> s1;                  // Empty set of int
std::set<int> s2 = {4, 1, 3, 2};   // Elements will be stored in sorted order: 1, 2, 3, 4
std::set<std::string> names;       // Set of strings
```

### ✅ Common Methods with Examples, Comments & Outputs
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {10, 20, 30};

    s.insert(25);  // Inserts 25 into the set
    s.insert(20);  // No effect, 20 already exists (duplicates not allowed)

    s.erase(10);   // Removes element with value 10

    auto it = s.find(30); // Returns iterator to 30 if found, else s.end()
    if (it != s.end()) std::cout << "Found: " << *it << "\n"; // Found: 30

    std::cout << "Size: " << s.size() << "\n"; // Returns number of elements

    s.clear(); // Removes all elements

    std::cout << "Empty? " << (s.empty() ? "Yes" : "No") << "\n"; // Yes

    return 0;
}

/*
Output:
Found: 30
Size: 3
Empty? Yes
*/
```

### 🔁 Iterating Over a `Set`
```cpp
std::set<int> s = {5, 2, 8, 1};

// Ascending order by default
for (auto it = s.begin(); it != s.end(); ++it)
    std::cout << *it << " "; // 1 2 5 8

// Range-based loop
for (int val : s)
    std::cout << val << " "; // 1 2 5 8
```

### 🧠 Tips and Tricks
- Want descending order? Use:
  ```cpp
  std::set<int, std::greater<int>> s; // Sorts in descending order
  ```

- Insert returns a pair:
  ```cpp
  auto result = s.insert(10);
  if (!result.second) std::cout << "Duplicate not inserted.\n";
  ```

- Set does not allow modification of existing elements via iterator. You must erase and reinsert.

### 📌 Use Cases
- Store unique values in sorted order.
- Remove duplicates from a collection.
- Efficient membership testing (`find()` is faster than linear search).


## `std::unordered_set` 

### 🔑 Key Features
- Stores **unique elements** in **no particular order**.

- Uses a **hash table** internally (not a tree like `std::set`).
- Offers **average constant time** (`O(1)`) complexity for **insertion**, **deletion**, and **lookup**.
- Fast and efficient for membership testing and lookup.
- Requires `#include <unordered_set>`.

### 🛠️ Declaration Examples
```cpp
std::unordered_set<int> uset;                  // Empty set of integers
std::unordered_set<std::string> words = { "apple", "banana", "cherry" }; // Initialized set
```

### ✅ Common Methods with Examples, Comments & Outputs
```cpp
#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> uset;

    uset.insert("apple");    // Inserts "apple"
    uset.insert("banana");   // Inserts "banana"
    uset.insert("cherry");   // Inserts "cherry"
    uset.insert("apple");    // Duplicate, ignored

    std::cout << "Size: " << uset.size() << "\n"; // Size: 3

    // Check presence of element
    if (uset.find("banana") != uset.end())
        std::cout << "banana is present\n"; // banana is present

    uset.erase("banana");   // Erases "banana" if it exists

    std::cout << "After erase, size: " << uset.size() << "\n"; // 2

    // Check if set is empty
    std::cout << "Empty? " << (uset.empty() ? "Yes" : "No") << "\n"; // No

    // Clear all elements
    uset.clear();
    std::cout << "Size after clear: " << uset.size() << "\n"; // 0

    return 0;
}

/*
Output:
Size: 3
banana is present
After erase, size: 2
Empty? No
Size after clear: 0
*/
```

### 🔁 Iterating Over an `unordered_set`
```cpp
std::unordered_set<int> uset = { 1, 3, 5, 7, 9 };

for (const auto& val : uset)
    std::cout << val << " ";

// Output (order is not guaranteed):
// 9 1 3 5 7  <-- (order may vary)
```

### 🧠 Tips and Tricks
- **Duplicates are ignored** automatically.
- If you insert an existing element, nothing happens.
- Use `.find()` to check existence **without modifying** the set.
- Use `.count(x)` if you just want a quick `0` or `1` result :

  ```cpp
  if (uset.count("apple")) { /* exists */ }
  ```

- Custom types can be stored, but you must provide `std::hash` and `==` functions.

### 📌 Use Cases
- Fast element existence checks.
- Removing duplicates.
- Set operations (like union, intersection — but manual implementation required).
- Useful for solving algorithm problems involving unique items.


## `std::map`

### 🔑 Key Features:
- Stores **key-value pairs** in **sorted order** by key.
- **Unique keys only**.
- Underlying data structure: **Self-balancing BST** (usually Red-Black Tree).
- **Logarithmic time** complexity for `insert`, `find`, and `erase`.
- **Keys are sorted in ascending order by default**.

### 🧠 Use Cases:
- Associating a value with a unique key.
- Efficient lookup, insertion, deletion with ordered keys.
- When key ordering matters (use `unordered_map` if it doesn’t).

### 🛠️ Common Member Functions:
- 
  | Function	       | Description                                   |
  | ---------------- | --------------------------------------------- |
  | `insert({k, v})` | Inserts a key-value pair                      |
  | `at(k)`	         | Returns value for key k; throws if not found  |
  | `operator[]`	   | Access or insert value for a key              |
  | `find(k)`	       | Returns iterator to key k or end() if not found |
  | `count(k)`	     | Returns 1 if key exists, else 0               |
  | `erase(k)`	     | Removes element with key k                    |
  | `size()`	       | Returns number of elements                    |
  | `clear()`	       | Removes all elements                          |
  | `empty()`	       | Checks if container is empty                  |
  | `begin(), end()` | Iterators for traversal                       |

### 📦 Declaration Styles:
```cpp
std::map<int, std::string> m1;                       // empty map
std::map<int, std::string> m2 = {{1, "a"}, {2, "b"}}; // initializer
std::map<int, std::string> m3(m2);                    // copy constructor
```

### 🧪 Example Code with Comments and Output:

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // operator[]: Inserts or updates a key
    myMap[1] = "Apple";
    myMap[3] = "Banana";
    myMap[2] = "Cherry";
    // Map now: {1: Apple, 2: Cherry, 3: Banana}

    std::cout << "Initial map:\n";
    for (const auto& [k, v] : myMap)
        std::cout << k << " => " << v << "\n";
    // Output:
    // 1 => Apple
    // 2 => Cherry
    // 3 => Banana

    // at(k): Access value (throws if key not present)
    std::cout << "Element at key 2: " << myMap.at(2) << "\n";
    // Output: Cherry

    // insert({k,v}): Insert new key-value pair
    myMap.insert({4, "Date"});
    // Map now: {1,2,3,4}

    // find(k): Check existence
    if (myMap.find(3) != myMap.end())
        std::cout << "Key 3 found: " << myMap[3] << "\n";
    // Output: Key 3 found: Banana

    // count(k): Returns 1 if key exists
    std::cout << "Count of key 5: " << myMap.count(5) << "\n";
    // Output: 0

    // erase(k): Removes key
    myMap.erase(2);
    std::cout << "After erasing key 2:\n";
    for (const auto& [k, v] : myMap)
        std::cout << k << " => " << v << "\n";
    // Output:
    // 1 => Apple
    // 3 => Banana
    // 4 => Date

    // size()
    std::cout << "Size: " << myMap.size() << "\n";
    // Output: 3

    // empty()
    std::cout << "Is empty? " << (myMap.empty() ? "Yes" : "No") << "\n";
    // Output: No

    // clear()
    myMap.clear();
    std::cout << "After clear, size: " << myMap.size() << "\n";
    // Output: 0

    return 0;
}
```

### 🧠 Tips:
- Use `map` when:
  - You need **ordered keys**.
  - You want **fast search/insert/delete** with **unique keys**.
- Prefer **unordered_map** for faster (`avg O(1)`) access when **order doesn't matter**.
- `operator[]` will **insert** the key with default value if it doesn’t exist.


## `std::unordered_map` 

### 🔑 Key Features
- An **associative container** that stores elements in **key-value pairs** (`std::pair<const Key, T>`).
- Keys are **unique**.
- **No sorting order** — elements are stored based on **hash values**.
- Provides **average constant time** (`O(1)`) for `insertions`, `deletions`, and `lookups`.
- Backed by a **hash table** internally.
- Requires `#include <unordered_map>`.

### 🛠️ Declaration Examples
```cpp
std::unordered_map<int, std::string> umap;               // Empty map with int keys, string values
std::unordered_map<std::string, int> wordCount = {
    {"apple", 2},
    {"banana", 5}
};
```

### ✅ Common Methods with Examples, Comments & Outputs
```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> umap;

    umap["apple"] = 3;   // Insert key "apple" with value 3
    umap["banana"] = 5;  // Insert key "banana" with value 5
    umap["apple"] = 4;   // Overwrites the value of "apple" to 4

    umap.insert({"orange", 7}); // Insert using insert()

    umap.erase("banana"); // Removes the key "banana" from the map

    // Access element
    std::cout << "apple: " << umap["apple"] << "\n"; // apple: 4

    // Check if key exists
    if (umap.find("grape") == umap.end())
        std::cout << "grape not found\n"; // grape not found

    std::cout << "Size: " << umap.size() << "\n"; // Size: 2

    umap.clear(); // Removes all elements

    std::cout << "Empty? " << (umap.empty() ? "Yes" : "No") << "\n"; // Yes

    return 0;
}

/*
Output:
apple: 4
grape not found
Size: 2
Empty? Yes
*/
```

### 🔁 Iterating Over an `unordered_map`
  ```cpp
  std::unordered_map<std::string, int> umap = {
      {"cat", 1}, {"dog", 2}, {"bird", 3}
  };
  
  for (auto& pair : umap)
      std::cout << pair.first << " => " << pair.second << "\n";
  
  /*
  Output (order may vary):
  dog => 2
  bird => 3
  cat => 1
  */
  ```

### 🧠 Tips and Tricks
- Keys must be **hashable**. Custom types as keys require defining `std::hash` specialization.
- If you use `[]` on a missing key, it **creates a default-initialized value**.

  ```cpp
  std::cout << umap["missing"];   // Adds "missing" with value 0
  ```
- For safe access without modifying the map, use `.at()`:
  
  ```cpp
  std::cout << umap.at("apple");  // Throws std::out_of_range if not found
  ```

### 📌 Use Cases
- Fast lookup with arbitrary keys (e.g. string, int).
- Count frequency of elements (`map[element]++`).
- Grouping, mapping, or categorization tasks.

## `std::multimap`

### 🔑 Key Features
- Stores **key-value pairs**, like a `map`.
- **Allows duplicate keys**.
- **Sorted** based on key using internal **balanced BST (Red-Black Tree)**.
- Each insertion of a duplicate key creates a new element in the container.
- Requires `#include <map>`.

### 🛠️ Declaration Examples
```cpp
std::multimap<int, std::string> mm;  // Empty multimap
std::multimap<int, std::string> mm2 = { {1, "A"}, {2, "B"}, {1, "C"} };  // With duplicates
```

### ✅ Common Methods with Examples, Comments & Outputs
```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<int, std::string> mm;

    mm.insert({1, "Apple"});    // Insert (1, "Apple")
    mm.insert({2, "Banana"});   // Insert (2, "Banana")
    mm.insert({1, "Avocado"});  // Duplicate key allowed

    std::cout << "Size: " << mm.size() << "\n"; // Size: 3

    // Find first element with key 1
    auto it = mm.find(1);
    if (it != mm.end())
        std::cout << "Found key 1: " << it->second << "\n"; // Apple (first match)

    // Iterate all elements with key 1
    auto range = mm.equal_range(1);
    std::cout << "All values for key 1:\n";
    for (auto i = range.first; i != range.second; ++i)
        std::cout << i->second << "\n";  // Apple, Avocado

    mm.erase(2); // Erase all elements with key 2

    std::cout << "Size after erase: " << mm.size() << "\n"; // 2

    return 0;
}

/*
Output:
Size: 3
Found key 1: Apple
All values for key 1:
Apple
Avocado
Size after erase: 2
*/
```

### 🔁 Iterating Over a `multimap`
```cpp
for (const auto& [key, value] : mm)
    std::cout << key << " => " << value << "\n";

// Output:
// 1 => Apple
// 1 => Avocado
```

## `std::unordered_multimap` 

### 🔑 Key Features
- Stores **key-value pairs** with **duplicate keys allowed**.
- **Unordered**, internally uses a **hash table**.
- Faster average access time (`O(1)`) but no key order guarantee.
- Requires `#include <unordered_map>`.

### 🛠️ Declaration Examples
```cpp
std::unordered_multimap<int, std::string> umm;
std::unordered_multimap<int, std::string> umm2 = { {1, "X"}, {2, "Y"}, {1, "Z"} };
```

### ✅ Common Methods with Examples, Comments & Outputs
```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_multimap<int, std::string> umm;

    umm.insert({1, "Red"});
    umm.insert({2, "Blue"});
    umm.insert({1, "Green"});  // Duplicate key

    std::cout << "Size: " << umm.size() << "\n"; // Size: 3

    // Find and iterate all entries with key 1
    auto range = umm.equal_range(1);
    std::cout << "Values with key 1:\n";
    for (auto it = range.first; it != range.second; ++it)
        std::cout << it->second << "\n";  // Red, Green (order may vary)

    umm.erase(2);  // Remove all elements with key 2

    std::cout << "Size after erase: " << umm.size() << "\n"; // 2

    return 0;
}

/*
Output:
        Size: 3
        Values with key 1:
        Red
        Green
        Size after erase: 2
*/
```

### 🔁 Iterating Over an `unordered_multimap`
```cpp
for (const auto& [key, value] : umm)
    std::cout << key << " => " << value << "\n";

// Output (order is not guaranteed):
// 1 => Red
// 1 => Green
```

### ⚡ Tips for Using `multimap` and `unordered_multimap`
- 
  | Feature	                | `multimap`	                 | `unordered_multimap`            |
  | ----------------------- | ---------------------------- | ------------------------------- |
  | Duplicate Keys	        | ✅ Yes	                      |  ✅ Yes                        |
  | Key Order Maintained	  | ✅ Yes (sorted)	            | ❌ No                          |  
  | Lookup Performance	    | O(log n)	                   |   O(1) average, O(n) worst-case |
  | Underlying Structure	  | Balanced BST	               |  Hash Table                     |
  | Best Use Case	          | Ordered data with duplicates |	Fast access with duplicates    |

## `std::multiset` 

### 🔑 Key Features
- A sorted associative container that allows duplicate elements.
- Internally implemented as a balanced binary search tree (Red-Black Tree).
- Elements are always stored in sorted order.
- Elements are immutable (no direct modification after insertion).
- Requires `#include <set>`.

### 🛠️ Declaration Examples
```cpp
std::multiset<int> ms;                            // Empty multiset
std::multiset<int> ms2 = {4, 2, 3, 2, 5};         // With duplicate elements
```

### ✅ Common Methods with Examples, Comments & Output
```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> ms = {5, 10, 5, 20, 10};

    // insert(val): Insert element (duplicates allowed)
    ms.insert(15);
    ms.insert(10);
    // Elements: 5 5 10 10 10 15 20

    std::cout << "Initial multiset: ";
    for (int x : ms) std::cout << x << " ";
    std::cout << "\n"; 
    // Output: 5 5 10 10 10 15 20

    // count(val): Count how many times 10 appears
    std::cout << "Count of 10: " << ms.count(10) << "\n"; 
    // Output: 3

    // find(val): Get iterator to first 15
    auto it = ms.find(15);  
    std::cout << "Found element using find(): " << *it << "\n";
    // Output: 15

    // erase(val): Erase ALL occurrences of 5
    ms.erase(5);
    std::cout << "After erasing all 5s: ";
    for (int x : ms) std::cout << x << " ";
    std::cout << "\n";
    // Output: 10 10 10 15 20

    // insert duplicate for demonstration
    ms.insert(20); ms.insert(20); // Now 3x 20s

    // erase(it): Erase only ONE occurrence of 20
    it = ms.find(20);
    if (it != ms.end()) ms.erase(it);
    std::cout << "After erasing one 20: ";
    for (int x : ms) std::cout << x << " ";
    std::cout << "\n";
    // Output: 10 10 10 15 20 20

    // size(): Total number of elements
    std::cout << "Size: " << ms.size() << "\n"; 
    // Output: 6

    // empty(): Check if multiset is empty
    std::cout << "Is empty? " << (ms.empty() ? "Yes" : "No") << "\n";
    // Output: No

    // clear(): Remove all elements
    ms.clear();
    std::cout << "After clear(), size: " << ms.size() << "\n";
    // Output: 0

    return 0;
}
```

### 🔁 Iterating Over a `multiset`
```cpp
for (auto it = ms.begin(); it != ms.end(); ++it)
    std::cout << *it << " ";
// Output (always sorted):
// 20 30 40 40 40
```

### ✂️ Erasing Only One Occurrence of a Value
```cpp
auto it = ms.find(40);  // Finds the first 40
if (it != ms.end())
    ms.erase(it);       // Erases only one occurrence
```

### ⚡ Tips for Using multiset
- Use `count(val)` before `erase(val)` if you only want to delete under a condition.
- Cannot modify elements directly — erase and reinsert to "modify".
- All elements are automatically **sorted**, no need to call `sort()`.

## `std::unordered_multiset` 

### 🔑 Key Features:
- Stores **unordered** collection of elements.
- **Duplicates are allowed** (unlike `unordered_set`).
- Elements are **not sorted**, but organized into **hash buckets**.
- Offers **average constant time** complexity for `insert`, `find`, `erase`.

### 🧠 Use Cases:
- When **duplicates** are needed and **order doesn't matter**.
- Great for **counting frequencies** or **multi-key hashing** without sorting.

### 🛠️ Common Member Functions:
- 
  | Function	        | Description                          |
  | ----------------- |--------------------------------------|
  | `insert(val)`	    | Inserts a value (allows duplicates)  |
  | `find(val)`	      | Finds one occurrence of a value      |
  | `count(val)`	    | Returns count of given value         |
  | `erase(val)`	    | Removes all occurrences of the value |
  | `erase(it)`	      | Removes one element at iterator `it` |
  | `size()`	        | Returns number of elements           |
  | `clear()`	        | Erases all elements                  | 
  | `empty()`	        | Checks if container is empty         |
  | `begin(), end()`	| Iterators for traversal              |

### 📦 Different Ways to Declare:
```cpp
std::unordered_multiset<int> ums1;                        // empty
std::unordered_multiset<std::string> ums2 = {"a", "b"};   // init list
std::unordered_multiset<int> ums3(ums1);                  // copy
```

### 🧪 Example Code with Comments and Output:
```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums = {5, 10, 5, 20};

    // insert(val): Add more elements
    ums.insert(10);
    ums.insert(15);
    ums.insert(20);
    // Elements (unordered): {5, 5, 10, 10, 15, 20, 20}

    std::cout << "Initial unordered_multiset: ";
    for (int x : ums) std::cout << x << " ";
    std::cout << "\n";
    // Output (unordered): 20 20 5 5 10 10 15  (order may vary)

    // count(val): Count duplicates
    std::cout << "Count of 10: " << ums.count(10) << "\n"; 
    // Output: 2

    // find(val): Get iterator to one occurrence
    auto it = ums.find(5);
    if (it != ums.end()) {
        std::cout << "Found 5 using find(): " << *it << "\n";
    }
    // Output: 5

    // erase(val): Erase all 5s
    ums.erase(5);
    std::cout << "After erasing all 5s: ";
    for (int x : ums) std::cout << x << " ";
    std::cout << "\n";
    // Output (unordered): 20 20 10 10 15

    // erase(it): Erase one element (e.g., one 20)
    it = ums.find(20);
    if (it != ums.end()) ums.erase(it);
    std::cout << "After erasing one 20: ";
    for (int x : ums) std::cout << x << " ";
    std::cout << "\n";
    // Output (unordered): 20 10 10 15

    // size()
    std::cout << "Size: " << ums.size() << "\n";
    // Output: 5

    // empty()
    std::cout << "Is empty? " << (ums.empty() ? "Yes" : "No") << "\n";
    // Output: No

    // clear()
    ums.clear();
    std::cout << "After clear(), size: " << ums.size() << "\n";
    // Output: 0

    return 0;
}
```

## `std::stack` 

### 🔑 Key Features 
- **LIFO (Last In, First Out)** data structure.
- Built on top of other containers like `deque` (default), `vector`, or `list`.
- Only allows access to the **top element**.

### 🧠 Use Cases
- Function call management (call stacks).
- Reversing data.
- Backtracking problems (DFS, undo features, etc).

### 📦 Declaration Styles:
```cpp
std::stack<int> s1;                      // empty stack of ints
std::stack<std::string> s2;              // stack of strings
std::stack<int, std::vector<int>> s3;    // stack backed by vector
```

### 🛠️ Common Member Functions
- 
  | Function	    | Description                           |
  | ------------- | --------------------------------------|
  | push(val)	    | Pushes element to top of stack        |
  | pop()	        | Removes top element                   |
  | top()	        | Returns reference to top element      |
  | size()	      | Returns number of elements            |
  | empty()	      | Returns true if stack is empty        |
  | emplace(args)	| Constructs and inserts element at top |
  | swap(s)	Swaps | contents with another stack           |

### 🧪 Example Code with Output in Comments
```cpp
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::string> st;

    // push(): Add elements to the top
    st.push("first");
    st.push("second");
    st.push("third");

    // Stack now: top -> "third", "second", "first"

    std::cout << "Top element: " << st.top() << "\n";
    // Output: Top element: third

    // pop(): Remove the top element
    st.pop();  // removes "third"
    std::cout << "Top after pop: " << st.top() << "\n";
    // Output: Top after pop: second

    // emplace(): In-place construction
    st.emplace("emplaced");  // acts like push but constructs in-place
    std::cout << "Top after emplace: " << st.top() << "\n";
    // Output: Top after emplace: emplaced

    // size(): Number of elements in stack
    std::cout << "Size: " << st.size() << "\n";
    // Output: Size: 3

    // empty(): Check if stack is empty
    std::cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << "\n";
    // Output: Is stack empty? No

    // swap(): Swap with another stack
    std::stack<std::string> temp;
    temp.push("A");
    temp.push("B");

    st.swap(temp);  // now st has B -> A
    std::cout << "Top after swap: " << st.top() << "\n";
    // Output: Top after swap: B

    return 0;
}
```

### ⚠️ Tips:
- **No direct iteration** is allowed in `std::stack`. Use a loop that pops elements if you want to access all.
- Prefer `deque` or `vector` when you need random access or iteration.
- `top()` is unsafe if the stack is empty — check `empty()` before calling it.

## `std::queue`

### 🔑 Key Features:
- **FIFO (First In, First Out)** data structure.

- Built on top of containers like `deque` **(default)** or `list`.
- You can access only the **front** and **back**.

### 📦 Declaration:
```cpp
std::queue<int> q;                      // queue of integers
std::queue<std::string> q2;             // queue of strings
std::queue<int, std::list<int>> q3;     // using list as underlying container
```

### 🛠️ Common Member Functions:
- 
  |Function	      | Description                              | 
  |-------------- | -----------------------------------------|
  |push(val)	    | Adds element to the back                 |
  |emplace(args)	| Constructs and adds element to the back  |
  |pop()	        | Removes element from the front           |
  |front()	      | Accesses the front element               |
  |back()	        | Accesses the back element                |
  |size()	        | Returns the number of elements           |
  |empty()	      | Checks if the queue is empty             |
  |swap(q2)	      | Swaps contents with another queue        |

### 🧪 Example Code with Output in Comments
```cpp
#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> q;

    // push(): Add elements to the back
    q.push("apple");
    q.push("banana");
    q.push("cherry");

    // Queue: front -> "apple", "banana", "cherry" <- back

    std::cout << "Front: " << q.front() << "\n";
    // Output: Front: apple

    std::cout << "Back: " << q.back() << "\n";
    // Output: Back: cherry

    // pop(): Remove front element
    q.pop();  // removes "apple"
    std::cout << "Front after pop: " << q.front() << "\n";
    // Output: Front after pop: banana

    // emplace(): Construct in-place and push to back
    q.emplace("dragonfruit");
    std::cout << "Back after emplace: " << q.back() << "\n";
    // Output: Back after emplace: dragonfruit

    // size(): Number of elements
    std::cout << "Size: " << q.size() << "\n";
    // Output: Size: 3

    // empty(): Check if empty
    std::cout << "Is empty? " << (q.empty() ? "Yes" : "No") << "\n";
    // Output: Is empty? No

    // swap(): Swap with another queue
    std::queue<std::string> temp;
    temp.push("x");
    temp.push("y");

    q.swap(temp);
    std::cout << "Front after swap: " << q.front() << "\n";
    // Output: Front after swap: x
    std::cout << "Back after swap: " << q.back() << "\n";
    // Output: Back after swap: y

    return 0;
}
```

### ⚠️ Tips:
- No direct iteration is allowed. Use a loop that pops elements if needed.
- Useful in **BFS algorithms**, **producer-consumer problems**, and **order processing**.
- `front()` and `back()` are **unsafe** if the queue is empty — check `empty()` before using them.


## `std::priority_queue` 

### 🔑 Key Features:
- Implements a Max-Heap by default (largest element at top).

- Provides constant time access to the largest element.
- Underlying container is typically vector.
- Can be customized to work as Min-Heap or with custom types.

### 📦 Declaration:
```cpp
std::priority_queue<int> pq;                              // max-heap (default)
std::priority_queue<int, std::vector<int>, std::greater<>> min_pq; // min-heap
```

### 🛠️ Common Member Functions:
-
  | Function	      | Description                                |
  | --------------- | ------------------------------------------ |
  | `push(val)`	    | Adds element and maintains heap property   |
  | `emplace(args)`	| Constructs in-place and pushes             |
  | `top()`	        | Returns top element (max or min depending) |
  | `pop()`	        | Removes the top element                    |
  | `empty()`	      | Checks if empty                            |
  | `size()`	      | Returns number of elements                 |
  | `swap(q2)`	    | Swaps contents with another queue          |

### 🧪 Example Code with Output
```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // For std::greater

int main() {
    // Max-Heap (default behavior)
    std::priority_queue<int> pq;

    pq.push(30);      // insert 30
    pq.push(10);      // insert 10
    pq.push(50);      // insert 50
    pq.push(20);      // insert 20

    std::cout << "Max-Heap Top: " << pq.top() << "\n";  
    // Output: Max-Heap Top: 50

    pq.pop();  // remove top (50)
    std::cout << "Top after pop: " << pq.top() << "\n"; 
    // Output: Top after pop: 30

    std::cout << "Size: " << pq.size() << "\n";         
    // Output: Size: 3

    std::cout << "Is empty? " << (pq.empty() ? "Yes" : "No") << "\n"; 
    // Output: Is empty? No

    // Min-Heap using std::greater
    std::priority_queue<int, std::vector<int>, std::greater<>> min_pq;
    min_pq.push(30);
    min_pq.push(10);
    min_pq.push(50);
    min_pq.push(20);

    std::cout << "Min-Heap Top: " << min_pq.top() << "\n";  
    // Output: Min-Heap Top: 10

    min_pq.pop(); // remove 10
    std::cout << "Min-Heap Top after pop: " << min_pq.top() << "\n";  
    // Output: Min-Heap Top after pop: 20

    // Using emplace
    min_pq.emplace(5);
    std::cout << "Top after emplace(5): " << min_pq.top() << "\n";  
    // Output: Top after emplace(5): 5

    return 0;
}
```

### ⚠️ Tips:

- **No direct iteration** over a priority queue. You must pop to access elements.

- To use with custom structs or classes, define `operator<` or a **custom comparator**.

- Ideal for problems involving **greedy algorithms, Dijkstra's shortest path**, etc.

## `std::bitset` 

### 🔑 Key Features:
- Represents a fixed-size sequence of N bits.

- Allows **bit manipulation** using convenient methods and operators.
- Operates on **compile-time fixed size** (unlike `vector<bool>`).

### 📦 Declaration:
```cpp
std::bitset<8> b1;               // 00000000 - all bits are 0
std::bitset<8> b2(42);           // 00101010 - initialized with number
std::bitset<8> b3("1100");       // 00001100 - initialized from string
```

### 🛠️ Common Member Functions
- 
  | Function	    | Description                       |
  |---------------|-----------------------------------|
  | `set()`	      | Sets all bits to 1                |
  | `set(pos)`	  | Sets bit at pos to 1              |
  | `reset()`	    | Sets all bits to 0                |
  | `reset(pos)`	| Resets bit at pos                 |
  | `flip()`	    | Flips all bits                    |
  | `flip(pos)`	  | Flips bit at pos                  |
  | `test(pos)`	  | Returns true if bit at pos is 1   |
  | `any()`	      | Returns true if any bit is 1      |
  | `none()`	    | True if all bits are 0            |
  | `count()`	    | Returns number of set bits (1s)   |
  | `to_ulong()`	| Converts to unsigned long         |
  | `to_string()`	| Returns string representation     |
  | `operator[]`	| Access individual bit             |

### 🧪 Example Code with Output:
```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> b1;                      // 00000000
    std::bitset<8> b2(42);                  // 00101010
    std::bitset<8> b3("1100");              // 00001100

    std::cout << "b1: " << b1 << "\n";      // Output: 00000000
    std::cout << "b2: " << b2 << "\n";      // Output: 00101010
    std::cout << "b3: " << b3 << "\n";      // Output: 00001100

    b2.set(0);  // Set bit at position 0
    std::cout << "b2 after set(0): " << b2 << "\n";  // Output: 00101011

    b2.reset(1);  // Reset bit at position 1
    std::cout << "b2 after reset(1): " << b2 << "\n";  // Output: 00101001

    b2.flip(2);  // Flip bit at position 2
    std::cout << "b2 after flip(2): " << b2 << "\n";  // Output: 00101101

    std::cout << "b2.test(3): " << b2.test(3) << "\n"; // Output: 1
    std::cout << "b2.any(): " << b2.any() << "\n";     // Output: 1
    std::cout << "b1.none(): " << b1.none() << "\n";   // Output: 1
    std::cout << "b2.count(): " << b2.count() << "\n"; // Output: 4

    std::cout << "b2.to_ulong(): " << b2.to_ulong() << "\n"; // Output: 45
    std::cout << "b2.to_string(): " << b2.to_string() << "\n"; // Output: 00101101

    std::cout << "b2[2]: " << b2[2] << "\n"; // Access individual bit → Output: 1

    return 0;
}
```

### ⚠️ Tips:

- Size of `std::bitset<N>` must be known at **compile-time**.

- For dynamic size, use `std::vector<bool>` or `boost::dynamic_bitset`.
- Bits are indexed **from right to left**, with `0` being the least significant bit.
- Can be used in **bitmasking problems**, **flags**, or **space-optimized logic**.


## `std::bitset` in C++ Detailed

### 🔎 What Is It?
- `std::bitset<N>` represents a **fixed-size sequence of N bits**.
- Optimized for **bit-level manipulation**: setting, resetting, flipping, counting bits.

- Size is known at **compile time** and cannot be resized.

### 🔑 Key Features
-
  | Feature	                 |  Description                                                      |
  | -----------------------  | ------------------------------------------------------------------|
  | Compile-time fixed size	 |  Template argument `N` determines number of bits.                   |
  | Bit access by index	     |  Use `bitset[i]`, just like an array (returns a proxy object).      |
  | Bit operations	         |  Supports bitwise ops: `&`, `                                       |
  | Counting bits	           |  Functions like `count()`, `all()`, `any()`, `none()` available.    |
  | String/Number support	   |  Construct from string or integer, and convert back to them.        |
  | Highly efficient	       |  Ideal for solving bitmasking problems and memory-efficient flags.  |

### 📦 Declaration
```cpp
#include <bitset>

std::bitset<8> bits;                       // 00000000
std::bitset<8> bits2("10110011");          // From binary string
std::bitset<8> bits3(0xA);                 // From integer (0xA = 00001010)
```

### 🛠️ Common Member Functions
-
  | Function	    |  Description                                 |
  | ------------- | ---------------------------------------------|
  | `set()`	      |  Sets all bits to 1                          |
  | `set(pos)`	  |  Sets bit at `pos` to 1                      |
  | `reset()`	    |  Clears all bits to 0                        |
  | `reset(pos)`	|  Clears bit at `pos`                         |
  | `flip()`	    |  Flips all bits                              |
  | `flip(pos)`	  |  Flips bit at `pos`                          |
  | `test(pos)`	  |  Returns true if bit at `pos` is set         |
  | `any()`	      |  Returns true if **any** bit is set          |
  | `none()`	    |  Returns true if **no** bits are set         |
  | `all()`	      |  Returns true if **all** bits are set        |
  | `count()`	    |  Returns number of bits set (1s)             |
  | `to_ulong()`	|  Converts bitset to unsigned long            |
  | `to_ullong()`	|  Converts bitset to unsigned long long       |
  | `to_string()`	|  Converts bitset to string of `'0'` and `'1'`|
  | `size()`	    |  Returns total number of bits                |

### ⚠️ Limitations
- Size must be known at compile time (use `vector<bool>` or `dynamic_bitset` for dynamic size).

- Bit indexing throws `std::out_of_range` if out of bounds.

### 🧪 Example Code with Output
```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> bits("10110011");

    std::cout << "Original bits:        " << bits << "\n";

    bits.set(0);   // Set LSB to 1
    std::cout << "After set(0):         " << bits << "\n";

    bits.reset(1); // Reset 2nd bit (from right)
    std::cout << "After reset(1):       " << bits << "\n";

    bits.flip(2);  // Flip 3rd bit
    std::cout << "After flip(2):        " << bits << "\n";

    std::cout << "Bit at index 4:       " << bits.test(4) << "\n";      // true/false

    std::cout << "Any bits set?:        " << bits.any() << "\n";        // 1 (true)
    std::cout << "All bits set?:        " << bits.all() << "\n";        // 0 (false)
    std::cout << "None bits set?:       " << bits.none() << "\n";       // 0 (false)

    std::cout << "Total 1's:            " << bits.count() << "\n";      // Count of set bits
    std::cout << "Bitset size:          " << bits.size() << "\n";       // Always 8

    std::cout << "To ulong:             " << bits.to_ulong() << "\n";   // Decimal form
    std::cout << "To string:            " << bits.to_string() << "\n";  // String "10110011"

    return 0;
}

/*
Output:
Original bits:        10110011
After set(0):         10110011
After reset(1):       10110001
After flip(2):        10110101
Bit at index 4:       0
Any bits set?:        1
All bits set?:        0
None bits set?:       0
Total 1's:            5
Bitset size:          8
To ulong:             181
To string:            10110101
*/
```

### ✅ When to Use
- Use `bitset<N>` when:
  - Size is fixed and known at compile time.
  - You need fast bit operations and compact storage.
  - Ideal for bitmasking problems in competitive programming.

- For runtime-sized bit sequences, use `std::vector<bool>` or Boost’s `dynamic_bitset`.


## `std::array` 

### 🔑 Key Features:
- Fixed-size **container** (like C-style arrays) but **with STL support**.
- Safer than raw arrays – supports bounds checking and standard container operations.

- Part of `<array>` header (C++11 and later).
- Size must be known at compile time.

### 📦 Declaration:
```cpp
std::array<int, 5> arr1;                      // Uninitialized (default values)
std::array<int, 5> arr2 = {1, 2, 3, 4, 5};    // Initialized
std::array<int, 5> arr3{};                    // Zero-initialized
```

### 🛠️ Common Member Functions
- 
  | Function	       | Description                                    |
  | ---------------- | -----------------------------------------------|
  | `at(i)`	         | Access with bounds checking (throws exception) |
  | `operator[]`	   | Access without bounds checking                 |
  | `front()`	       | First element                                  |
  | `back()`	       | Last element                                   |
  | `size()`	       | Number of elements                             |
  | `fill(val)`	     | Assigns all elements with value val            |
  | `swap(arr2)`	   | Swaps contents with another array              |
  | `begin(), end()` |	Iterators for STL algorithms                  |
  | `data()`	       | Returns pointer to underlying array            |

### 🧪 Example Code with Output:
```cpp
#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {10, 20, 30, 40, 50};

    std::cout << "arr[2]: " << arr[2] << "\n";         // Access via operator[] → Output: 30
    std::cout << "arr.at(3): " << arr.at(3) << "\n";   // Access with bounds check → Output: 40

    std::cout << "Front: " << arr.front() << "\n";     // First element → Output: 10
    std::cout << "Back: " << arr.back() << "\n";       // Last element → Output: 50

    std::cout << "Size: " << arr.size() << "\n";       // Output: 5

    arr.fill(100);                                     // Fill all with 100
    std::cout << "After fill: ";
    for (int x : arr) std::cout << x << " ";           // Output: 100 100 100 100 100
    std::cout << "\n";

    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    arr.swap(arr2);                                    // Swap with arr2
    std::cout << "After swap with arr2: ";
    for (int x : arr) std::cout << x << " ";           // Output: 1 2 3 4 5
    std::cout << "\n";

    int* ptr = arr.data();                             // Pointer to raw array
    std::cout << "Pointer value: " << *ptr << "\n";    // Output: 1

    return 0;
}
```

### ⚠️ Tips:
- Unlike `std::vector`, `std::array` has **fixed size** known at compile time.
- Use `arr.at(i)` for **safe access** with bounds checking.

- Can be used with all standard algorithms (sort, find, etc.).
- Supports aggregate initialization (`= {1, 2, 3}`).

## `std::vector<bool>`

### 🔎 What Is It?
- A specialized version of std::vector that stores bool values efficiently by packing them as bits instead of separate bytes.
- Optimized for memory, but behaves slightly differently from std::vector<T>.

### 🔑 Key Features
Feature	Description
Feature	Description
Bit-packed	Stores values as bits (1 bit per bool), unlike other vector<T> types.
Proxy reference	Returns a proxy object, not a real bool& reference.
Space-efficient	Memory optimization — 8x smaller than vector<char> for boolean data.
Slower access	Due to proxy-based element access.
Caution with addresses	You cannot take address of an element using &vec[i].

### 📦 Declaration
```cpp
std::vector<bool> flags(5);                     // Vector of 5 `false` values
std::vector<bool> bits = {true, false, true};   // Initialized vector
```

### 🛠️ Common Functions
-
  | Function	       | Description                        |
  | -----------------|----------------------------------- |
  | `push_back(val)` | Adds a bool value                  |
  | `pop_back()`	   | Removes last element               |
  | `operator[]`	   | Access element (returns proxy)     |
  | `size()`	       | Number of elements                 |
  | `at(i)`	         | Bounds-checked access              |
  | `flip()`	       | Flip all bits (C++23)              |
  | `resize(n)`	     | Resize vector                      |
  | `assign(n, val)` |	Fill vector with n copies of val  |

### ⚠️ Caveats
- Cannot take address of an element (`&vec[i]`) – returns proxy object.

- Avoid passing individual elements to functions expecting `bool&`.
- If heavy use of element references is needed, prefer `std::vector<char>` or `std::bitset`.

### 🧪 Example Code with Output
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<bool> bits = {true, false, true, false};

    bits.push_back(true);                         // Add true at the end
    std::cout << "After push_back: ";
    for (bool b : bits) std::cout << b << " ";    // Output: 1 0 1 0 1
    std::cout << "\n";

    bits[1] = true;                               // Modify second element
    std::cout << "After setting bits[1] = true: ";
    for (bool b : bits) std::cout << b << " ";    // Output: 1 1 1 0 1
    std::cout << "\n";

    bits.pop_back();                              // Remove last element
    std::cout << "After pop_back: ";
    for (bool b : bits) std::cout << b << " ";    // Output: 1 1 1 0
    std::cout << "\n";

    std::cout << "Access via at(2): " << bits.at(2) << "\n"; // Output: 1

    bits.assign(4, false);                        // Fill with 4 false values
    std::cout << "After assign(4, false): ";
    for (bool b : bits) std::cout << b << " ";    // Output: 0 0 0 0
    std::cout << "\n";

    return 0;
}
```

### ✅ When to Use:
- Use `vector<bool>` when:
  - You need space optimization for large arrays of flags.
  - You don't need to pass individual elements by reference.
- Use `vector<char>` or `bitset` if:
  - You need performance and element references.
  - Size is fixed at compile-time → use `std::bitset`.


# STL Algorithms

## 🔧 Non-Modifying Sequence Algorithms
- These algorithms inspect elements without altering them.

### 1. `std::all_of`, `std::any_of`, `std::none_of`
- Check if all, any, or none of the elements satisfy a condition.

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> v = {2, 4, 6, 8};
  
      bool all_even = std::all_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
      bool any_even = std::any_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
      bool none_odd = std::none_of(v.begin(), v.end(), [](int i){ return i % 2 != 0; });
  
      std::cout << std::boolalpha;
      std::cout << "All even: " << all_even << "\n";
      std::cout << "Any even: " << any_even << "\n";
      std::cout << "None odd: " << none_odd << "\n";
  
      return 0;
  }
  ```

### 2. `std::for_each`
- Applies a function to each element in a range.

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> v = {1, 2, 3};
  
      std::for_each(v.begin(), v.end(), [](int &n){ n *= 2; });
  
      for (int n : v)
          std::cout << n << " "; // Output: 2 4 6
  
      return 0;
  }
  ```

### 3. `std::find`, `std::find_if`, `std::find_if_not`
- Search for elements matching a value or predicate.

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> v = {1, 3, 5, 7};
  
      auto it = std::find(v.begin(), v.end(), 5);
      if (it != v.end())
          std::cout << "Found: " << *it << "\n";
  
      return 0;
  }
  ```

## 🛠️ Modifying Sequence Algorithms
- These algorithms modify the elements in the range.
Cppreference

### 4. `std::copy`, `std::copy_if`, `std::copy_n`
- Copy elements from one range to another.
  
  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> src = {1, 2, 3, 4, 5};
      std::vector<int> dest;
  
      std::copy_if(src.begin(), src.end(), std::back_inserter(dest), [](int i){ return i % 2 == 0; });
  
      for (int n : dest)
          std::cout << n << " "; // Output: 2 4
  
      return 0;
  }
  ```

### 5. `std::transform`
- Applies a function to each element and stores the result.

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> v = {1, 2, 3};
      std::vector<int> result(v.size());
  
      std::transform(v.begin(), v.end(), result.begin(), [](int i){ return i * i; });
  
      for (int n : result)
          std::cout << n << " "; // Output: 1 4 9
  
      return 0;
  }
  ```

### 6. `std::replace`, `std::replace_if`
- Replace elements matching a value or predicate.

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> v = {1, 2, 3, 2, 4};
  
      std::replace(v.begin(), v.end(), 2, 5);
  
      for (int n : v)
          std::cout << n << " "; // Output: 1 5 3 5 4
  
      return 0;
  }
  ```

## 🔍 Searching and Sorting Algorithms
- These algorithms are used for searching and sorting operations.

### 7. `std::sort`, `std::stable_sort`
- Sort elements in ascending order.

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> v = {4, 2, 5, 1, 3};
  
      std::sort(v.begin(), v.end());
  
      for (int n : v)
          std::cout << n << " "; // Output: 1 2 3 4 5
  
      return 0;
  }
  ```

### 8. `std::binary_search`
- Check if an element exists in a sorted range.

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> v = {1, 2, 3, 4, 5};
  
      bool found = std::binary_search(v.begin(), v.end(), 3);
  
      std::cout << std::boolalpha << "Found 3: " << found << "\n"; // Output: true
  
      return 0;
  }
  ```

## 📊 Numeric Algorithms
- These algorithms perform numeric operations.

### 9. `std::accumulate`
- Compute the sum of elements.

  ```cpp
  #include <numeric>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> v = {1, 2, 3, 4, 5};
  
      int sum = std::accumulate(v.begin(), v.end(), 0);
  
      std::cout << "Sum: " << sum << "\n"; // Output: 15
  
      return 0;
  }
  ```

## 🧩 Partitioning Algorithms (continued)

### 10. `std::partition`, `std::stable_partition`
- Splits elements into two groups based on a predicate.

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> v = {1, 2, 3, 4, 5};
  
      std::partition(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
  
      for (int n : v)
          std::cout << n << " "; // Output might be: 2 4 3 1 5 (order of partitions not guaranteed)
  
      return 0;
  }
  ```

## Heap Algorithms

### 11. `std::make_heap`, `std::push_heap`, `std::pop_heap`, `std::sort_heap`
- Used to work with heaps (priority queues).

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>
  
  int main() {
      std::vector<int> heap = {3, 1, 4, 1, 5};
  
      std::make_heap(heap.begin(), heap.end());
      std::cout << "Max element: " << heap.front() << "\n"; // Output: 5
  
      heap.push_back(9);
      std::push_heap(heap.begin(), heap.end()); // Maintain heap after insertion
  
      std::pop_heap(heap.begin(), heap.end()); // Moves largest to the end
      heap.pop_back(); // Removes the largest
  
      std::sort_heap(heap.begin(), heap.end()); // Sorts the heap
  
      for (int n : heap)
          std::cout << n << " "; // Output: 1 1 3 4 5
  
      return 0;
  }
  ```

## Min/Max Algorithms

### 12. `std::min`, `std::max`, `std::min_element`, `std::max_element`
```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {10, 20, 30, 40};

    std::cout << "Min: " << *std::min_element(v.begin(), v.end()) << "\n"; // Output: 10
    std::cout << "Max: " << *std::max_element(v.begin(), v.end()) << "\n"; // Output: 40

    return 0;
}
```

## 📚 Set Algorithms (Sorted Ranges Only)

### 13. `std::set_union`, `std::set_intersection`, `std::set_difference`
```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {3, 4, 5, 6};
    std::vector<int> result;

    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
    for (int x : result)
        std::cout << x << " "; // Output: 1 2 3 4 5 6

    return 0;
}
```

## 🔁 Permutation Algorithms
### 14. `std::next_permutation`, `std::prev_permutation`
```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3};

    std::next_permutation(v.begin(), v.end()); // Changes to next lexicographical permutation
    for (int x : v)
        std::cout << x << " "; // Output: 1 3 2

    return 0;
}
```

## 🛠️ Utility Algorithms
### 15. `std::swap`, `std::iter_swap`, `std::reverse`
```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    int a = 5, b = 10;
    std::swap(a, b);
    std::cout << a << " " << b << "\n"; // Output: 10 5

    std::vector<int> v = {1, 2, 3};
    std::reverse(v.begin(), v.end());
    for (int x : v)
        std::cout << x << " "; // Output: 3 2 1

    return 0;
}
```

## 📋 Summary of STL Algorithm Categories
- 
  | Category	            |  Common Algorithms                                      |
  | -------------------   |  -------------------------------------------------------|
  | Non-Modifying	        |  `all_of`, `find`, `count`, `for_each`                  |
  | Modifying	            |  `copy`, `move`, `transform`, `replace`, `remove`       |
  | Sorting & Searching	  |  `sort`, `binary_search`, `lower_bound`, `equal_range`  |
  | Numeric	              |  `accumulate`, `inner_product`, `iota`                  |
  | Set	                  |  `set_union`, `set_difference`, `set_intersection`      |
  | Heap	                |  `make_heap`, `push_heap`, `pop_heap`, `sort_heap`      |
  | Min/Max	              |  `min`, `max`, `min_element`, `max_element`             |
  | Partitioning	        |  `partition`, `stable_partition`                        |
  | Permutations	        |  `next_permutation`, `prev_permutation`                 |
  | Utility	              |  `swap`, `reverse`, `fill`, `generate`, `unique`        |