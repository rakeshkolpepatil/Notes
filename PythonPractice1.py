# ----------------- Check a number is between 5 & 20 and print various statements ----------------
'''
def process(n):
  if(n % 2 == 1):
    print('Weird')
  else:
    if(n>=2 and n<=5 or n>20 ):
      print('Not Weird')
    if(n>=6 and n<=20):
      print('Weird')

if __name__ == '__main__':
  n = int(input('Please enter a number \n'))
  print('Hi rakesh, you are so good and you have entered the number', n)
  process(n)

  print(*map( int, '12345'.split()))
  print(' '.join(*map( str, '12345'.split())) )
  print(' '.join(map( str, '12345'.split())) )
'''
# ----------------- Check a number is between 5 & 20 and print various statements end ----------------

# -------------------------- Singly Linked List Functions -------------------------------------
'''
class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

class sll:
  def __init__(self):
    self.head = None

  def add(self, data):
    n = Node(data)
    if(self.head == None):
      self.head = n
      return

    current = self.head
    while current.next != None:
      current = current.next

    current.next = n

  def delete(self, data):
    if(self.head == None):
      print('The singly linked list is empty')
      return

    if(self.head.data == data):
      self.head = self.head.next
      return

    myflag = False
    prev = None
    curr = self.head
    while curr != None:
      if(curr.data == data):
        prev.next = curr.next
        curr.next = None
        myflag = True
        return
      prev = curr
      curr = curr.next

    if(myflag == False):
      print('The specified data did not found in the list')

  def display(self):
    print('Printing Singly Linked List')
    current = self.head
    while current != None:
      print(current.data, end=' ')
      current = current.next
    print('\n')

if __name__ == '__main__':

  sl = sll()

  while True:
    print('1. Add new element')
    print('2. Delete an element')
    print('3. Display')
    print('4. Exit')
    n = input('Please enter your choice - ')

    if n == '1':
      d = input('Please enter an element - ')
      sl.add(d)
    elif n == '2':
      d = input('Please enter an element - ')
      sl.delete(d)
    elif n == '3':
      sl.display()
    elif n == '4':
      exit()

  # sl.add(1);
  # sl.add(2);
  # sl.add(3);
  # sl.add(4);
  # sl.add(5);
  # sl.add(6);
  # sl.delete(1);
  # sl.delete(3);
  # sl.delete(4);
  # sl.display();
'''
# ------------------------- Singly Linked List Functions End -------------------------------------

# ------------------------------- String Functions Start --------------------------------------
'''
s = 'Hello world program'
for x in s:
  print(x, end=' ')
print('\n')

print(s[0:-1])
print(s[-6:])
print(s[-5:-3])
print(s[-5::-1])
print(s[-2::-1])
print(s[-1::-1])
print('****************')

print(s.lower())
print(s.upper())
print(s.capitalize())
print(s.swapcase())
print(','.join(s))
print(','.join(s.split()))
print('****************')

s = '  Rakesh   '
print(s.lstrip())
print(s.strip())
print(s.rstrip())
print(s + ' Patil ')
print('1234'.isnumeric())
print('1'.isalnum())
print('1'.isalpha())
print('****************')

print(' Rakesh '.isupper())
print(' Rakesh '.islower())
print(' Rakesh '.istitle())
print('****************')

print(' Rakesh Patil '.find('Patil'))
print(len(' Rakesh Patil '))
print('****************')
print(f'This is my name -{s}')
print('   Rakesh Patil'.count('a'))
print('   Rakesh Patil'.startswith('  '))
print('   Rakesh Patil'.endswith(' l'))

print('****************')
print(l[0:])
print(l[0:-1])
print(l[::-1])
print(l[-5::-1])
s = 'rakesh_ravindra_patil'
print(s[::-1])
print(s[-5::-1])
print('****************')
'''
# ------------------------------  String Functions End  --------------------------------

# -------------------------- List Functions Start --------------------------------------
'''
# List functions
# List is a unordered mutable collection of items 

l = [1, 2, 3, 4, 5, 6, 7, 8, 9]
l2 = list(range(20))
print(l2)
print(l +l2)

print('****************')
print(l)
print(l[-1])
print(l[0:5])

for ind, item in enumerate(l):
  print(f'ind={ind} item={item}', end=' ')
print('\n')
print('------------------')

l.extend([15])
print(l)
l.append(10)
print(l)
l.extend([11, 12, 13, 14, 15, 16, 17, 18, 19])
print(l)
print('------------------')

print(l[0])
print(l[1])
print(l[2])
l.insert(1, -11)
print(l)

l.append(10)
print(l)
print(l.count(10))

print('****************')
print(l)
l.pop()
print(l)

print('****************')
print(l.pop(0))
print(l)
print(l.remove(-11))
print(l)
del l[0]
print(l)

print('****************')
l.reverse()
print(l)

l.sort()
print(l)
print(len(l))


print('****************')
l.clear()
print(l)

print('------- List Comprehension -----------')
l = [x for x in range(10) if x%2 == 0]
print(l)
l = [x**2 for x in range(10) if x%2 == 0]
print(l)
print(sorted(l, reverse=True))
print(sorted(l))
'''
# ------------------------------ List Functions End ------------------------------------ 

# ---------------------------- Tuple Functions Start ------------------------------------
'''
# Tuple is an ordered immutable collection of items.

t = (1, 2, 3, 1, 1, 4, 5, 6, 7, 8, 9)

print(len(t))
print(t.count(1))
print(t.index(1))
print(t[1:5])

for i in t:
  print(i, end='-')

for i in range(len(t)):
  print(t[i], end='-')

'''
# ------------------------------- Tuple Functions End ---------------------------------

# ---------------------------- Set Functions Start ------------------------------------
'''
# Set - unordered collection of unique items
s = set()
print(f'This is empty set -{s}')

s = set([x for x in range(20) if x%4 == 0])
print(f'This is set generated from list -{s}')

s = {1, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10}
print(s)
print('------------------')

print('The set is as follow :-')
print(s.add(1))
print(s)
print(s.add(-1))
print(s)
print('....................')
print(s.remove(-1))
print(s)
print('------------------')
s.discard(5)
print(s)
print('****************')

ss = {-1, -2, -3, -4, -5, 1, 2, 3, 4}
print(f"\nThe set s   - {s}")
print(f"The set ss  - {ss}")
print(f"Union of sets s and ss is                - {s.union(ss)}")
print(f"Difference of sets s and ss is           - {s.difference(ss)}")
print(f"Symmetric Difference of sets s and ss is - {s.symmetric_difference(ss)}")
print(f"Intersection of sets s and ss is         - {s.intersection(ss)} \n")
print(f"s.pop() :- {s.pop()}")
print(f"s.pop() :- {s.pop()}")
print(f"s.pop() :- {s.pop()}")
print(f"s.pop() :- {s.pop()}")
print(f"s.pop() :- {s.pop()}")

print('\n Iterating over the set s :-')
for i in s:
  print(i, end=' ')

print('\n')
print(f"Is 7 in the set s :- {7 in s}")
print(f"Is 1 in the set s :- {1 in s}")

s.clear()
print(f"\n The contents of the set s after clearing it :- { s }")
'''
# --------------------------- Set Functions End -------------------------------------

# --------------------- Deque Functions - Double Ended Queue in Python ----------
'''

from collections import deque

my_dq = deque([1, 2, 3, 4])
print(my_dq)

print('------------------')
my_dq.extend([5, 6])
print(my_dq)
my_dq.extendleft([-1, 0])
print(my_dq)
print('------------------')

print(my_dq.pop())
print(my_dq)
print(my_dq.popleft())
print(my_dq)
print('\n------------------')

temp = list(my_dq)
temp.pop(0)         # pop the item at specified index
my_dq = deque(temp)
print(my_dq)
print('------------------')

my_dq.insert(1, 0)
my_dq.insert(3, 2)
print(my_dq)
print('\n****************')

my_dq.rotate(1)
print(my_dq)
my_dq.rotate(-1)
print(my_dq)
print('\n****************')

my_dq.extend([1, 1])
print(my_dq)
print(my_dq.count(1))

print( 1 in my_dq)
print('\n------------------')

print('Printing my_dq by iterating over it :- ' )
for ele in my_dq:
  print(ele, sep=' ', end='\n')

print('\n------------------')
my_dq1 = deque(maxlen= 5)
my_dq1.extend([1, 2, 3, 4, 5, 6, 7, 8, 9])
print(my_dq1)
my_dq1.append(10)
print(my_dq1)
my_dq1.appendleft(-1)
print(my_dq1)

print('\n-------- Done ----------')
print(my_dq1.reverse()) 
print(my_dq1)

print(deque(list(my_dq1)[0:3]))
print(my_dq1.copy())

print(my_dq1.remove(9))
print(my_dq1)
print('\n-------- Done ----------')

print(my_dq1[1])
del my_dq1[1]
print(my_dq1)
'''
# --------------------- Deque Functions - Double Ended Queue in Python ----------

# --------------------------- Dictionary Functions Start -------------------------------------
'''
# Dictionary - Unordered collection or key-value pairs

my_dict = {}
print(f'My empty dictionary - {my_dict}')

my_dict = dict()
print(f'My empty dictionary - {my_dict}')

my_dict = dict(a=1, b=2, c=3, d=4)
print(f'My dictionary - {my_dict}')

my_dict = {'phy': 65, 'chem': 87, 'math': 89}
my_dict['coding'] = 200
print(f'My dictionary - {my_dict}')
print(f'Converting dictionary into string: {str(my_dict)}')
print('\n------------------')

print('Keys in my_dict')
for key in my_dict.keys():
  print(key, end=' ')

print('Values in my_dict')
for values in my_dict.values():
  print(values, end=' ')

print()
print('\n--------- Iterate Over Dictionary ---------')
for key, value in my_dict.items():
  print(f'key={key} value={value}')

for key in my_dict:
  print(f'key={key} value={ my_dict[key]}')
print('------------------')

my_dict.update({'eng':80, 'hist':60})
print(my_dict)

print('\n--------- Sorting ---------')
dict_keys = list(my_dict.keys())
dict_keys.sort()
for k in dict_keys:
  val = my_dict[k]
  print(f'{k}:{val}')

print('\n----- Sorting as per marks i.e. value ')
print(type(my_dict.items()))
print( dict(sorted(my_dict.items(), key= lambda item: item[1] )))
print('---------  ---------')

# my_dict.extend({'Bio':100})
print(f'The marks in Physics - {my_dict["phy"]}')
print(f'The marks in Physics - {my_dict.get("phy")}')

del my_dict['hist']
print(f'The dictionary after deleting History marks {my_dict}')

my_dict.popitem()
print(f'The dictionary after popping last item {my_dict }')

my_dict.pop('phy')
print(f'The dictionary after popping "phy" item {my_dict }')

my_dict.pop('chem')
print(f'The dictionary after popping "chem" item {my_dict }')

my_dict1 = {x:x**2 for x in range(5) if x %2 != 0}
print(my_dict1)

print(f'Is 3 in my_dict1 {3 in my_dict1.keys()}')
print(f'Is 2 in my_dict1 {2 in my_dict1}')
'''
# --------------------------- Dictionary Functions End -------------------------------------

# ---------------------- Flatten nested list --------------------
'''
# Solution 1
l = [1, [2, [3, 4], 5, 6], 7, 8]
print(str(l))
s = str(l)
l_one = [int(x) for x in s if x != '[' and x != ']' and x != ' ' and x != ',']
print(l_one)

# Solution 2
l = [1, [2, [3, 4], 5, 6], 7, 8]

def flatten(input_list):
  flattened_list = []
  for e in input_list:
    if isinstance(e, list):
      flattened_list.extend(flatten(e))
    else:
      flattened_list.append(e)
  return flattened_list

print(flatten(l))

'''
# ---------------------- Flatten nested list end --------------------

# ---------------------- Count Number of Words --------------------
'''
import string
print(string.punctuation)

print(f'The total number of True values is - {sum([True, False, False])}')
print(f'The total number of True values is - {sum([True, True, True])}')

s = "Geeksforgeeks, is best @# Computer Science Portal.!!!"

print('The total number of words in string s is - ', end=' ')
print( sum([ x.strip(string.punctuation).isalpha() for x in s.split() ]))

'''
# ------------------- Count Number of Words end --------------------

# ------------------- Regular Expression Start --------------------
'''
import re
# Sample text
text = "The rain in Spain falls mainly in the plain. Call 123-456-7890 for info."

# 1. re.match
match_result = re.match(r'The', text)
print("re.match result:", match_result.group() if match_result else "No match")
print("re.match result:", match_result if match_result else "No match")

# 1. re.search
match_result = re.search(r'The', text)
print("re.match result:", match_result.group() if match_result else "No match")
print("re.match result:", match_result if match_result else "No match")


# Example 1: Escaping backslashes
pattern_raw = r'\d+'  # Raw string: Matches one or more digits
pattern_non_raw = '\\d+'  # Non-raw string: Matches one or more digits

text = "There are 123 numbers here."

# Using raw string
result_raw = re.findall(pattern_raw, text)
print("Using raw string (r'\\d+'): ", result_raw)  # Output: ['123']

# Using non-raw string
result_non_raw = re.findall(pattern_non_raw, text)
print("Using non-raw string ('\\\\d+'): ", result_non_raw)  # Output: ['123']
print('\\\\\Hi Rakesh')

ma = re.search(r'[0-9]{4}', '1122223344')
print(ma)
'''
# ------------------- Regular Expression End --------------------

'''
s = 'HiHowareyou'
l = len(s)
print('length', l)
#for t in range(l):
#  print(s[t:l])
print(s[0:l+1])

for i, c in enumerate(s):
  print (i, c)
print('-----------------------')
for t in range(1, l):
  print(s[0:t])
'''

# ------------------- Cube Piling Problem --------------------
'''
def place(new_list, pile, n):
    #print(f'new_list-{new_list} pile-{pile} n-{n} typen-{type(n)}')
    if n == 0:
        return True
        
    left = int(new_list[0])
    right = int(new_list[n-1])
    
    if pile == '':
        top = (2**31 -1)
    else:
        top = int(pile[-1])

    if left > right:
        if left <= top:
            return place(new_list[1:n], pile+str(left), n-1)
        else:
            return False
    else:
        if right <= top:
            return place(new_list[0:n-1], pile+str(right), n-1)
        else:
            return False
        
if __name__ == '__main__':
    testcases = int(input())

    for _ in range(testcases):
        pile = ''
        n = int(input())
        ll = list(input().split())
        output = place(ll, pile, n)
        #print(f'output - {output}')
        if output:
            print('Yes')
        else:
            print('No')
'''
# ------------------- Cube Piling Problem end --------------------

# ------------------- Fibonacci Problem Using Generator Function --------------------
'''
def fibonacci():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b

# Usage example
if __name__ == '__main__':
    fib_gen = fibonacci()
    
    # Print the first 10 numbers in the Fibonacci series
    #while input():
    print(next(fib_gen))
    print(next(fib_gen))
    print(next(fib_gen))
    print(next(fib_gen))
    print(next(fib_gen))
    print(next(fib_gen))
'''
# ------------------- Fibonacci Problem Using Generator Function end --------------------

# ---------------------- Generate Fibonacci Sequence on demand --------------------
''' 
def fibonacci():
  a, b = 0, 1
  while True:
    yield a
    a, b = b, a + b

def main():
  gen_fib = fibonacci()
  print("\n Please enter to print next fib sequence or type 'Exit' to exit the program")
  
  while True:
    i = input().lower().strip()
    if i == 'exit':
      exit()
    else:
      print(next(gen_fib))

if __name__ == '__main__':
  main()
''' 
# ------------------- Generate Fibonacci Sequence on demand end --------------------

# --------------------- Sort a List without using Sort keyword --------------------
'''
mylist = [41, 2, 12, 6, 35, 8, 10, 1, 19] 
print(mylist)
n = len(mylist)

for i in range(n):
  index, smallest = i, mylist[i]
  for j in range(i+1, n):
    if smallest > mylist[j]:
      index, smallest = j, mylist[j]
  mylist[i], mylist[index] = mylist[index], mylist[i]

#for i in range(n):
#  for j in range(i+1, n):
#    print(i, j)
print(mylist)
# ------------------- Sort a List without using Sort keyword end --------------------
'''

# --------------------- Check string palindrome  --------------------
'''
def check_palindrome(s):
  n = len(s)
  print(f'String - {s}')
  i, j = 0, n-1
  while i <= j:
    if(s[i] == s[j]):
      i += 1
      j -= 1
      continue
    else:
      print('No! Its not a Palindrome! \n')
      return

  print('Yes! it is a palindrome! \n')

def check_palindrome1(s):
  print(s)
  rev_str = s[::-1]
  print(rev_str)
  if(s == rev_str):
    print('Palindrome! \n')
  else:
    print('Not Palindrome! \n')

def check_palindrome2(s):
  print('s - %s'%s)
  s_rev = ''.join(reversed(s))
  print('s_rev - %s'%s_rev)
  if s == s_rev:
    print('Palindrome! \n')
  else:
    print('Not Palindrome! \n')

if __name__ == '__main__':
  myStrings = ['aba', 'aaba', 'nayan', 'YaY', 'asbsds', 'asdasdfasdf', 'aycddcya', 'zdcpcdz']
  for str in myStrings:
    check_palindrome2(str)

'''
# --------------------- Check string palindrome end --------------------

# --------------------- Sorting Dictionary --------------------
'''
from collections import OrderedDict
my_dict = {'b': 3, 'a': 1, 'c': 2}

print('The sorted dict as per keys is - ')
sort_dict = { key:my_dict[key] for key in sorted(my_dict) }
print(sort_dict)

print('The sorted dict as per values is - ')
sort_dict_val = { key:val for key, val in sorted(my_dict.items(), key=lambda item: item[1]) }
print(sort_dict_val)

print(f'The my_dict.items() returns - {my_dict.items()} and its type is - {type(my_dict.items())})')

print(f'Sorted Dictionary using Ordered Dict - { OrderedDict(sorted(my_dict.items())) }')
print(f'Reverse Sorted Dictionary using Ordered Dict - { OrderedDict(sorted(my_dict.items(), reverse=True)) }')
print(f'Sorted Dictionary using Ordered Dict on Values - { OrderedDict(sorted(my_dict.items(), key=lambda item:item[1])) }')
print(f'Sorted Dictionary using Ordered Dict on Values Reverse - { OrderedDict(sorted(my_dict.items(), key=lambda item:item[1], reverse=True)) }')

'''
# --------------------- Sorting Dictionary End --------------------

# --------------------- Array Sum Problem --------------------
'''

ll = [8, 7, 2, 5, 3, 1]
k = 10 

d = {}
result = []
for i, num in enumerate(ll):
  if num in d.keys():
    result.append((d[num],i))
  else:
    d[k-num] = i

print(d)
print(result)
#'''
# --------------------- Array Sum Problem End --------------------

# --------------------- String Manipulation --------------------
'''
# Input = 'the sky is blue'
# Input = 'blue is sky the'
import re

str = 'the sky is blue'
print(' '.join(  str.split()[::-1] ))

# Input = "/*apples are & found% only @red & green"
# Output = "apples are & found only red & green"

str = "/*apples are & found% only @red & green"
print(re.sub(r'[/*$@%]','',str))

s_new =''
for s in str:
  if (s>='A' and s<='Z') or (s>='a' and s<='z') or (s == ' '):
    s_new = s_new + s
print(s_new)
'''
# --------------------- String Manipulation end --------------------

# ----------------------- Maximum Repeated Character in String without O(n2) complexity --------------------
'''
from collections import defaultdict
from collections import OrderedDict

s = 'itininiytnnhhn'
d = defaultdict(lambda: 0)
# OR
# d = defaultdict(int)

for c in s:
  d[c] += 1

maxkey, maxval = 0, 0
for key, val in d.items():
  if maxval < val:
    maxkey, maxval = key, val

sort_reverse = OrderedDict(sorted(d.items(), key=lambda x: x[1], reverse=True))

print(d)
print(f' maxkey-{maxkey}  maxval-{maxval}')
print(sort_reverse)

for ke,va in sort_reverse.items():
  print(f' key-{ke} va-{va}')
  break

'''
# -------------------------------- Maximum Repeated Character in String End --------------------

# -------------------------------- Find Max and Min value from list without max and min function --------------------
'''
ll = [ 23, 4, 1, 567, 234, 22, 46]
minval, maxval = 2**32, 0

for v in ll:
  if v < minval:
    minval = v
  if v > maxval:
    maxval = v 
print(minval, maxval)

print(min(ll), max(ll))
'''
# -------------------------------- Find Max and Min value from list without max and min function End --------------------

# -------------------------------- Print Prime Numbers From 100 to 200 --------------------
'''
print('The Prime numbers from 100 to 200 are :- ')
for n in range(101, 200, 2):
  flag = True
  for t in range(3, int(n/2), 2):
    if(n % t == 0):
      #print(f'n-{n} t-{t}')
      flag = False
      break
  if flag:
    print(n)
'''
# -------------------------------- Print Prime Numbers From 100 to 200 End --------------------

# ---------------------------------- Print List in reverse -----------------------------
'''
ll = [1, 2, 3, 4, 5, 6]
ll_size = len(ll)

for i in range(ll_size-1, -1, -1):
  print(ll[i])

print(ll[::-1])
'''
# ---------------------------------- Print List in reverse end -----------------------------

# ---------------------------------- Palindrome Check -----------------------------
s = 'madam'
'''
s_rev = str(''.join(reversed(s)))
print(s, s_rev)
if s== s_rev:
  print('True')
else:
  print('False')

my_list = [1, 2, 3, 4, 5]
print(list(reversed(my_list)))

my_tuple = ( 2, 3, 4, 5, 6)
print(tuple(reversed(my_tuple)))

my_dict = {'phy':10, 'chem':20, 'math':45, 'bio':33}
print({x:y for x,y in sorted( my_dict.items(), key=lambda x:x[0])})
print({x:y for x,y in sorted( my_dict.items(), key=lambda x:x[0], reverse=True)})
print({x:y for x,y in sorted( my_dict.items(), key=lambda x:x[1])})
print({x:y for x,y in sorted( my_dict.items(), key=lambda x:x[1], reverse=True)})

# set object is not reversible
my_set = {1, 2, 3, 4, 5, 6}
print(set(reversed(my_set)))

# dictionary object is not reversible
print(dict(reversed(my_dict)))
'''
# ------------------------------- Palindrome Check End -----------------------------

# --------------------------------- Print set of duplicates in a list -----------------------------
'''
my_list = [1, 2, 3, 4, 5, 6, 1, 2, 3]

# ------------ Approach 1
dup_set = set()
sorted_my_list = sorted(my_list)
print('sorted_my_list - ', sorted_my_list, ' len(sorted_my_list) - ', len(sorted_my_list))

for i, key in enumerate(sorted_my_list):
  #print(i, key)
  if i+1 < len(sorted_my_list) and key == sorted_my_list[i+1]:
    print(i, key)
    dup_set.add(key)
print(dup_set)

# ------------ Approach 2
dup_set = set()
for key in (my_list):
  if my_list.count(key) > 1:
    dup_set.add(key)
print(dup_set)

print(set([x for x in my_list if my_list.count(x) > 1]))

# ------------ Approach 3
from collections import defaultdict

mydef_dict = defaultdict(int)
for i in my_list:
  mydef_dict[i] += 1

dup_set = set()
for key in mydef_dict:
  if mydef_dict[key] > 1:
    dup_set.add(key)
print(dup_set)
'''
# ------------------------------- Print set of duplicates in a list End -----------------------------

# --------------------------------- Write a program for Binary Search -----------------------------
'''
def bin_search(ll, n):
  i, j = 0, len(ll)

  while i < j:
    m = (i+j)//2
    if n == ll[m]:
      print(f'Element {n} Found at index - ', m)
      return
    elif n > ll[m]:
      i = m
    else:
      j = m
  print(f'Element {n} Not Found !' )

if __name__ == '__main__':
  ll = [1, 34, 56, 60, 23, 58, 33, 100, 105]
  s_ll = list(sorted(ll))
  print(ll)
  print(s_ll)
  
  bin_search(s_ll, 34)
  bin_search(s_ll, 23)
  bin_search(s_ll, 58)
  bin_search(s_ll, 100)
  bin_search(s_ll, 105)
'''
# ------------------------------- Write a program for Binary Search End -----------------------------

# --------------------------------- Write a program for to plot a simple Bar chart  -----------------------------
'''
import matplotlib.pyplot as plt

category = ['Biscuit', 'Chocolate', 'Ice-cream', 'Bread']
values = [10, 26, 55 , 50]

plt.bar(category, values, color=['blue', 'green', 'red', 'purple'] )
plt.title('Shop Inventory')
plt.xlabel('Category')
plt.ylabel('Number of Items')

plt.show()
'''
# ------------------------------- Write a program for to plot a simple Bar chart End -----------------------------

# --------------------------------- Write a program to Extract Digits from a string  -----------------------------
'''
import re
s = 'artay12 4354 dgbi 24'

ma = re.findall(r'[0-9]', s)
print(''.join(ma))

print(''.join([c for c in s if c in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']]))    

print(''.join( filter(lambda x: x.isdigit(), s)))

str = "Hi I am Here. Do not ask know where I am"
for i in re.finditer("am", str):
  locTuple =  i.span()
  print(i.group(), locTuple)
'''
# ------------------------------- Write a program to Extract Digits from a string end  --------------------------

# --------------------------------- Split a string using newline delimiter  -----------------------------
'''
s = "Hi, Positive thinking is good for health. \n\
You are great. \n\
But, you also need to be rational too"

print(s.split('\n'))
'''
# ------------------------------- Split a string using newline delimiter end  -----------------------------

# -------------------------------- isinstance() Function  -----------------------------
'''
class Employee:
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

emp = Employee("Emma", 11000)
print(isinstance(emp, Employee))  # Output: True

#- Check if an object is an instance of a class or a subclass
class Manager(Employee):
    pass

manager = Manager("John", 15000)
print(isinstance(manager, Manager))     # Output: True
print(isinstance(manager, Employee))     # Output: True

#- Check if an object is an instance of a tuple of classes
print(isinstance(5, (int, float, str)))  # Output: True
'''
# ------------------------------- isinstance() Function end  -----------------------------

# --------------------------------- Python Inbuilt Functions  -----------------------------
'''
# Return the absolute value of a number
x = abs(-7.23) 
print(x)
print('-------------------------------------\n')

# Return the absolute value of a complex number:
x = abs(3+5j)
print(x)
print('-------------------------------------\n')

# Check if all items in a list are True:
mylist = [True, True, True]
x = all(mylist)
print(x)
print(all([False, True, True]))

# Check if any of the items in a list are True:
mylist = [False, True, False]
x = any(mylist)
print(x)
print(any([False, False, False]))

# Escape non-ascii characters: å will be replaced with \xe5
x = ascii("My name is Ståle")
print(x)

# Return the binary version of 36:
x = bin(36)
print(x)
print('-------------------------------------\n')

# Return the boolean value of 1:
x = bool(1)
print(x)
print(bool(None))
print(bool([]))
print(bool([None]))
print(bool({}))
print(bool({None}))
print(bool(()))
print(bool((None)))
print('-------------------------------------\n')

# The bytearray() function returns a bytearray object.
# It can convert objects into bytearray objects, or create empty bytearray object of the specified size.
# bytearray(x, encoding, error)

x = bytearray(4)
print(x)
print('-------------------------------------\n')

# Checks if a function is callable:
def x():
  a = 5
print(callable(x))
print('-------------------------------------\n')

# Get the character that represents the unicode 97:
x = chr(97)
for i in range(4050):
  print( f'{i}-{chr(i)}', end=', ')
#print(x)
print('\n-------------------------------------\n')

# Compile text as code, and the execute it:
x = compile('print(55)', 'test', 'eval')
exec(x)
print('-------------------------------------\n')

# The exec() function executes the specified Python code. The exec() function accepts large blocks of code, unlike the eval() 
# function which only accepts a single expression
x = 'name = "John"\nprint(name)'
exec(x)
print('-------------------------------------\n')

# Convert the number 3 and imaginary number 5 into a complex number:
x = complex(3, 5)
print(x)
print('-------------------------------------\n')


#Delete the "age" property from the "person" object:
class Person:
  name = "John"
  age = 36
  country = "Norway"
delattr(Person, 'age')
print('-------------------------------------\n')

# Create a dictionary containing personal information:
x = dict(name = "John", age = 36, country = "Norway")
print(x)
print('-------------------------------------\n')

# The dir() function returns all properties and methods of the specified object, without the values.
class Person:
  name = "John"
  age = 36
  country = "Norway"

print(dir(Person))
print('-------------------------------------\n')

# The divmod() function returns a tuple containing the quotient  and the remainder when argument1 (dividend) is divided by argument2 (divisor).
x = divmod(5, 2)
print(x)
print('\n-------------------------------------\n')

# The enumerate() function takes a collection (e.g. a tuple) and returns it as an enumerate object.
# The enumerate() function adds a counter as the key of the enumerate object.
x = ('apple', 'banana', 'cherry')
y = enumerate(x)
for i in y:
  print(i)
print('\n-------------------------------------\n')

# The eval() function evaluates the specified expression, if the expression is a legal Python statement, it will be executed.
x = 'print(55)'
eval(x)
print('\n-------------------------------------\n')


# The filter() function returns an iterator where the items are filtered through a function to test if the item is accepted or not.
# Filter the array, and return a new array with only the values equal to or above 18:

ages = [5, 12, 17, 18, 24, 32]

def myFunc(x):
  if x < 18:
    return False
  else:
    return True

adults = filter(myFunc, ages)

for x in adults:
  print(x)
print('-------------------------------------\n')

# The format() function formats a specified value into a specified format.
x = format(0.5, '%')
print(x)
print('-------------------------------------\n')

# The frozenset() function returns an unchangeable frozenset object (which is like a set object, only unchangeable).
# Freeze the list, and make it unchangeable:
mylist = ['apple', 'banana', 'cherry']
x = frozenset(mylist)
print(x)
print('-------------------------------------\n')

# The getattr() function returns the value of the specified attribute from the specified object.
# Get the value of the "age" property of the "Person" object:
class Person:
  name = "John"
  age = 36
  country = "Norway"

x = getattr(Person, 'age')
print(x)
print(Person.name)
print('-------------------------------------\n')

# A symbol table contains necessary information about the current program
# The globals() function returns the global symbol table as a dictionary.
x = globals()
print(x)
print('-------------------------------------\n')

# The hasattr() function returns True if the specified object has the specified attribute, otherwise False.
# Check if the "Person" object has the "age" property:
class Person:
  name = "John"
  age = 36
  country = "Norway"

x = hasattr(Person, 'age')
print(x)
print('-------------------------------------\n')

# hash() Returns the hash value of a specified object
print (hash(Person))
print('-------------------------------------\n')

# Executes the built-in help system
print(help(Person))
print('-------------------------------------\n')

# hex() Converts a number into a hexadecimal value
print(hex(10))

# Return the unique id of a tuple object:
x = ('apple', 'banana', 'cherry')
y = id(x)
print(y)
print('-------------------------------------\n')


# The isinstance() function returns True if the specified object is of the specified type, otherwise False.
# If the type parameter is a tuple, this function will return True if the object is one of the types in the tuple.
# Check if the number 5 is an integer:

x = isinstance(5, int)
print(x)
print(isinstance('Rakesh', str))
print(isinstance([ 'Rakesh', 'Rajesh', 'Ramesh'], list))
print(isinstance([ 1, 2, 3], list))
print(isinstance((1, 2, 3), tuple))
print(isinstance({1:'one', 2:'two', 3:'three'}, dict))
print(isinstance(set([1, 3, 5]), set))
print('-------------------------------------\n')

# The issubclass() function returns True if the specified object is a subclass of the specified object, otherwise False.
# Check if the class myObj is a subclass of myAge:

class myAge:
  age = 36
class myObj(myAge):
  name = "John"
  age = myAge

x = issubclass(myObj, myAge)
print(x)
print('-------------------------------------\n')

# The iter() function returns an iterator object.
# Create an iterator object, and print the items:

x = iter(["apple", "banana", "cherry"])
print(next(x))
print(next(x))
print(next(x))
print('-------------------------------------\n')


# The locals() function returns the local symbol table as a dictionary.
# A symbol table contains necessary information about the current program.
# Display the local symbol table:

x = locals()
print(x)
print('-------------------------------------\n')

# The map() function executes a specified function for each item in an iterable. The item is sent to the function as a parameter.
# Calculate the length of each word in the tuple:

def myfunc(n):
  return len(n)

x = map(myfunc, ('apple', 'banana', 'cherry'))
print(*x)
print('-------------------------------------\n')

# The max() function returns the item with the highest value, or the item with the highest value in an iterable.
# Return the largest number:

x = max(5, 10)
print(x)
print(max([1, 3, 6, 7, 0])) # List
print(max((1, 3, 6, 7, 0))) # tuple
print(max(set([1, 3, 6, 7, 0])) ) # set
print(max(dict({1:'one', 3:'three', 6:'six', 7:'seven', 0:'zero'})) ) # dict
print('-------------------------------------\n')


# The memoryview() function returns a memory view object from a specified object.
# Create and print a memoryview object:

x = memoryview(b"Hello")
print(x)

#return the Unicode of the first character
print(x[0])

#return the Unicode of the second character
print(x[1])
print('-------------------------------------\n')

# The next() function returns the next item in an iterator.
# Create an iterator, and print the items one by one:

mylist = iter(["apple", "banana", "cherry"])

x = next(mylist)
print(x)

x = next(mylist)
print(x)

x = next(mylist)
print(x)
print('-------------------------------------\n')

# The object() function returns an empty object.
# Create an empty object:

x = object()
print(x)
print('-------------------------------------\n')

# The oct() function converts an integer into an octal string.
# Octal strings in Python are prefixed with 0o.
# Convert the number 12 into an octal value:

x = oct(12)
print(x)
print('-------------------------------------\n')
# The open() function opens a file, and returns it as a file object.
# Open a file and print the content:

f = open("demofile.txt", "r")
print(f.read())
print('-------------------------------------\n')
'''
'''

# The ord() function returns the number representing the unicode code of a specified character.
# Return the integer that represents the character "h":

x = ord("h")
print(x)
print(ord('a'))
print('-------------------------------------\n')

# The pow() function returns the value of x to the power of y (xy).
# Return the value of 4 to the power of 3 (same as 4 * 4 * 4):
# If a third parameter is present, it returns x to the power of y, modulus z.

x = pow(4, 3)
print(x)
print('-------------------------------------\n')

# The reversed() function returns a reversed iterator object.
# Reverse the sequence of a list, and print each item:

alph = ["a", "b", "c", "d"]
ralph = reversed(alph)
for x in ralph:
  print(x)
print('-------------------------------------\n')

# The round() function returns a floating point number that is a rounded version of the specified number, with the specified number of decimals
# Round a number to only two decimals:

x = round(5.76543, 2)
print(x)
print(round(5.76543))
print('-------------------------------------\n')

# The setattr() function sets the value of the specified attribute of the specified object.
# Change the value of the "age" property of the "person" object:

import json
class Person:
  name = "John"
  age = 36
  country = "Norway"

setattr(Person, 'age', 40)
Person.age = 50
print(Person.__dict__)
#json.dumps(vars(Person))
#json.dumps(Person.__dict__)
print('-------------------------------------\n')

# The slice() function returns a slice object.
# A slice object is used to specify how to slice a sequence. You can specify where to start the slicing, and where to end. You can also specify the step, 
# which allows you to e.g. slice only every other item.
# Create a tuple and a slice object. Use the slice object to get only the two first items of the tuple:

# Syntax :=
# slice(start, end, step)

a = ("a", "b", "c", "d", "e", "f", "g", "h")
x = slice(2)
print(a[x])
print(a[slice(6)])

print('-------------------------------------\n')

# The sorted() function returns a sorted list of the specified iterable object.
# You can specify ascending or descending order. Strings are sorted alphabetically, and numbers are sorted numerically.
# Note: You cannot sort a list that contains BOTH string values AND numeric values.
# 
# Syntax :-
# sorted(iterable, key=key, reverse=reverse)
# Sort a tuple:

a = ("b", "g", "a", "d", "f", "c", "h", "e")
x = sorted(a)
print(x)

print('-------------------------------------\n')

# The sum() function returns a number, the sum of all items in an iterable.
# Add all items in a tuple, and return the result:
# Syntax :-
# sum(iterable, start)

a = (1, 2, 3, 4, 5)
x = sum(a)
print(x)
print('-------------------------------------\n')

# The super() function is used to give access to methods and properties of a parent or sibling class.
# The super() function returns an object that represents the parent class.
# Create a class that will inherit all the methods and properties from another class:

class Parent:
  def __init__(self, txt):
    self.message = txt

  def printmessage(self):
    print(self.message)

class Child(Parent):
  def __init__(self, txt):
    super().__init__(txt)

x = Child("Hello, and welcome!")
x.printmessage()

print('-------------------------------------\n')

# The tuple() function creates a tuple object.
# Create a tuple containing fruit names:

x = tuple(('apple', 'banana', 'cherry'))
print(x)
print('-------------------------------------\n')

# The type() function returns the type of the specified object
# Return the type of these objects:
a = ('apple', 'banana', 'cherry')
b = "Hello World"
c = 33

x = type(a)
y = type(b)
z = type(c)
print(x, y, z)
print(x == tuple)
print(y == str)
print(z == int)
print('-------------------------------------\n')

# The vars() function returns the __dict__ attribute of an object.
# The __dict__ attribute is a dictionary containing the object's changeable attributes.
# Note: calling the vars() function without parameters will return a dictionary containing the local symbol table.
# Return the __dict__ attribute of an object called Person:

class Person:
  name = "John"
  age = 36
  country = "norway"

x = vars(Person)
print(x)
print('-------------------------------------\n')


# The zip() function returns a zip object, which is an iterator of tuples where the first item in each passed iterator is paired together, 
# and then the second item in each passed iterator are paired together etc.
# Join two tuples together:
# If the passed iterables have different lengths, the iterable with the least items decides the length of the new iterator.

a = ("John", "Charles", "Mike")
b = ("Jenny", "Christy", "Monica", 'Radha')

x = zip(a, b)
print(*x)
print('-------------------------------------\n')

# Monkey Patching
class Test:
    def __init__(self, x):
        self.a = x
    def get_data(self):
        print('Some code to fetch data from the database')
    def f1(self):
        self.get_data()
    def f2(self):
        self.get_data()

t1 = Test(5)
t1.f1()
t1.f2()

def get_new_data(self):
    print('Some code to fetch new test data')

Test.get_data = get_new_data
print('After monkey patching ...')
t1.f1()
t1.f2()
print('-------------------------------------\n')
'''

# Identity Operators - Identity operators check whether two objects points to the same object or not. 
# They will return true for single value variables if values match but will return false for composite variables/collections 
# like lists even after contents match. However, for immutable objects like strings, tuples identity operator 
# returns True if contents match 
x = 5
y = 5
print('x:', x, ' y:', y)
print('x is y', x is y)
z = x
print('x is z', x is z)
print('id(x)', id(x))
print('id(y)', id(y))
print('id(z)', id(z))
print('--------------------------')

x = [1, 3, 5, 7]
y = [1, 3, 5, 7]
print('x:', x, ' y:', y)
print('x is y', x is y)
print('x == y', x == y)
print('id(x)', id(x))
print('id(y)', id(y))
print('--------------------------')

x = (1, 3, 5, 7)
y = (1, 3, 5, 7)
print('x:', x, ' y:', y)
print('x is y', x is y)
print('x == y', x == y)
print('id(x)', id(x))
print('id(y)', id(y))
print('--------------------------')

x = 'Rakesh'
y = 'Rakesh'
print('x:', x, ' y:', y)
print('x is y', x is y)
print('x == y', x == y)
print('-------------------------------------\n')

# Python Generator Functions
def isPrime(num):
  for i in range(2, num//2+1):
    if num%i == 0:
      return False
  return True

def generatePrimes(num_primes):
  n = 2
  while num_primes > 0:
    if isPrime(n):
      yield n
      num_primes -= 1
    n += 1
  return    

for it in generatePrimes(50):
  print(it, end=' ')
print('-------------------------------------\n')

# Python variable length arguments
def average(*t):
  total = sum(t)
  avg = total / len(t)
  print(avg)

average(10, 20, 30, 40, 50, 60)
average(1, 2, 3, 4, 5, 6)
average(1, 2, 3, 4)

s = 'Java is the best programming language'
print(s)
print(s[::-1])
print(s[:0:-1])
print(s[-3:0:-1])
print(s[2:6:])
print('-------------------------------------\n')

# Different ways of creating instance variables
class Test:
  def __init__(self):
    self.x = 5 # 1st method
  def f1(self):
    self.y = 7 # 2nd method
t1 = Test()
t2 = Test()
t1.f1()
t1.z = 10 # 3rd method
print(t1.__dict__) # prints all the instance variables in t1
print(t2.__dict__) # prints all the instance variables in t2
print('-------------------------------------\n')

# Different ways of lambda function creation
def add(a, b):
  return a+b 
f = lambda a, b: a+b
print(f(3, 6))

# Recursive lambda function
fact = lambda n: 1 if n == 0 else n*fact(n-1)
print(fact(4))
print(fact(5))
print((lambda a, b: a*b)(3,6))
print('-------------------------------------\n')

# What is list comprehension ?
print([ 2*i for i in range(6)])
print([ i  for i in [1,2,3,4,5,6,7,8,9,10,11,12,13,14] if i%2==0 ])
print('-------------------------------------\n')

# What is the use of split and join functions?
s = 'Hello Rakesh, hope you are doing good'
print(s.split(' '))
print(s.split())
print(' '.join(s.split()[::-1]))
print('-------------------------------------\n')

# Local vs global variables
x = 5 # global variable
def f():
  y = 10 # local variable
  print('x=%d, y=%d' % (x, y))
f()
print('x=%d' % (x)) # y is not accessible here
print('-------------------------------------\n')

# If you want to access only global variable inside a function, But here you will not be able to 
# create a local variable with name 'gx' in the same function
gx = 5 # global variable
def f():
  global gx
  gx = 10 # global variable
f()
print('The global gx=%d' % (gx)) 
print('-------------------------------------\n')

# If you want to access both global variables and local variables inside a function you need to 
# use globals() function which returns a dictionary of global variables.
t = 5
def f():
  t=7
  d = globals()
  print('The global t=%d' % (globals()['t']))
  print('The global t=%d' % (d['t']))
  print('The local t=%d' % (t))
f()
print('-------------------------------------\n')

# The type conversion functions 
x = 5
print(type(x))  # <class 'int'> is output
s1 = '123'
print(type(s1)) # <class 'str'> is output
print(x+int(s1))
print(str(x)+s1)
x=int('23')
a = float('23.34')
b = complex('2+3j')
c = bool('true')
d = bool('false')
e = bool('True')
f = str(12)
g = bin(25)
h = oct(30)
i = hex(25)
j = ord('A')
k = chr(97)
print(x, a, b, c, d, e, f, g, h, i, j, k, sep=' ')
print('-----------------------------------------------\n')

# Decorator Functions in python
def decor_result(result_func):
  def distinction(marks):
    for mark in marks:
      if mark >= 75:
        print('Distinction - %d'%(mark))
    result_func(marks)
  return distinction

@decor_result
def results(marks):
  for x in marks:
    if x >= 33:
      pass
    else:
      print('Failed')
      break
  else:
    print('Passed')
  print('-------------------\n')
  
results([60, 70, 80, 90, 75])
results([30, 70, 80, 90, 75])
results([70, 80, 90, 75, 14])
results([70, 80, 13, 90, 75])
print('-----------------------------------------------\n')

# Negative Indices in Python
l = [1, 2, 3, 4, 5, 6, 7]
print(l[-1])
print(l[-2])
print(l[-3])
s = 'RakeshPatil'
print(s[0::1])
print(s[0:len(s):1])
print(s[::-1])
print(s[:-len(s):-1])
print(s[:-len(s)-1:-1])
print('-----------------------------------------------\n')

# Iterators in Python
my_list = [1, 2, 3, 4, 5, 6, 7, 8]
it = iter(my_list)
while True:
  try:
    print(next(it))
  except StopIteration:
    break
#print(next(it))
#print(next(it))
#print(next(it))
print('-----------------------------------------------\n')

# Generator functions
def generate_evens(n):
  i = 0
  while n:
    yield 2*i
    i +=1
    n -=1
  return

def isprime(x):
  for i in range(2, x//2+1):
    if x%i == 0:
      return False
  return True

def generate_primes(n):
  i=2
  while n:
    if isprime(i):
      n -= 1
      yield i
    i += 1

evens = []
it = generate_evens(10)
while True:
  try:
    evens.append(next(it))
  except StopIteration:
    break
print(evens)

print('--------- Using for loop ---------\n')
for it in generate_evens(10):
  print(it, sep=' ')
print('--------- Primes ---------\n')

primes = []
for it in generate_primes(10):
  primes.append(it)
print(primes)
print('-----------------------------------------------\n')

# Difference between sorted() and sort() functions
lst = [45, 67, 33, 47, 37, 2, 1, 50, 90]
s_lst = sorted(lst)
print(lst)
print(s_lst)
print(type(s_lst))

print('--------- Tuple ---------\n')
tup = (26, 33, 87, 45, 39, 50, 90, 100)
s_tup = sorted(tup)
print(tup)
print(s_tup)
print(type(s_tup))

print('--------- sort() function ---------\n')
lst = [45, 67, 33, 47, 37, 2, 1, 50, 90]
s_lst = lst.sort()
print(lst)
print(s_lst)
print(type(s_lst))
print('-----------------------------------------------\n')

# Python Static Methods vs Instance Methods
# from typing import Self

from datetime import date
class Calculator:
  def __init__(self, version):  # This is instance method as we are referring to the 'self'     
    self.version = version

  def description(self):            # This is instance method as we are referring to the 'self'
    print(f'The current version of the calculator is {self.version}')

  @staticmethod                     # The 'static' keyword denotes that the following method is 'static' method
                                    # and its execution is not dependent on the instances of the class 
  def add_numbers(*numbers):  # This is static method 
    print( sum(numbers))

calc1 = Calculator(10)
calc2 = Calculator(20)

calc1.description()
calc2.description()

Calculator.add_numbers(10,20,30,40,50,60)
print('-----------------------------------------------\n')

print('--------------------------- Match Statement ----------------------\n')
x = input("Please enter your name - ")
match x:
  case 'Rakesh' | 'Ram' | 'Rajesh':
        print('Name starts with "R"')
  case 'Rohit':
        print("Welcome Rohit!")
  case _:
        print('Good Morning, Sir!')
print('------------------------ End Match Statement -----------------------\n')

print('------------------------ random library in python -----------------------\n')
import random 
print (random.choice([1, 2, 3, 4, 5]))
print (random.choice((88, 34, 76, 88)))
print (random.choice('Rakesh'))
print (random.randint(0,100))
l = [1, 2, 3, 4, 5]
random.shuffle(l)
print (l)
print('------------------------ End random library in python -----------------------\n')

print('------------------------ End Match Statement -----------------------\n')
# Python class methods 
from datetime import date
class Person:
  def __init__(self, name, age):
    self.name = name
    self.age = age
    
  def description(self):
    print(f'The {self.name} is {self.age} years old')

  @classmethod                      # The keyword 'classmethod' denotes that the following method is 'classmethod'
  def age_from_year(cls, name, birth_year):
    current_year = date.today().year
    age = current_year - birth_year
    return cls(name, age)

Rakesh = Person.age_from_year('Rakesh', 2000)
Rakesh.description()

# ------------------------------- Python Inbuilt Functions end  -----------------------------