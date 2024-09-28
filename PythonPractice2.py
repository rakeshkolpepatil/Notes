# --------------------------------------------------------------
# f-strings in Python - Format Strings in Python 
# --------------------------------------------------------------
'''
# Trick 1 - Format integers
n: int = 1000000
print(f'{n:,}')             # This will add ',' to the big number while printing it for the sake of readability.
print(f'{n:_}')             # This will add '_' to the big number while printing it for the sake of readability.

# Trick 2 - Format Float numbers
y = 31234.14159
print(f'{y:.3f}')
print(f'{y:.2f}')
print(f'{y:,.2f}')
print(round(y, 1))

# Trick 3 - Format Strings
x = 'Rakesh'
print(f'{x:^40}')
print(f'{x:<40}')
print(f'{x:>40}')

print(f'{x:,^40}')
print(f'{x:|<40}')
print(f'{x:_>40}')

# Trick 4 - Format Date and Time
from datetime import datetime
date = datetime.now()
print(f'{date:%y.%m.%d (%H:%M:%S)}')
print(f'{date:%yyyy.%mmd.%dd (%H:%M:%S)}')

# Trick 5 - Format expressions for ease of debugging
a: int = 100
b: int = 200
print(f'{a + b = }')       # This kind of string formatting helps in debugging
c: bool = 23
print(f'{bool(c) = }')
'''

# --------------------------------------------------------------
# 'match' case in Python
# --------------------------------------------------------------
'''
name = input('Please enter your name - ')
match name:
    case 'Harry' | 'Hermione' | 'Ron':
        print('Gryffindor')
    case 'Draco':
        print('Slytherin')
    case _ :
        print('Homeless')
'''

# --------------------------------------------------------------
#  try-except-else block
# --------------------------------------------------------------
'''
try:
    x = int(input("Enter a number: "))
except Exception as e:
    print('Encountered an unexpected error')
else:
    print(f'x is {x}')
'''

# --------------------------------------------------------------
#  47 String Methods - https://www.youtube.com/watch?v=bnSYeYFRCaA
# --------------------------------------------------------------
'''

# 1. capitalize() - capitalizes first letter of the string
print('\n---------------- capitalize() -----------------')
text: str = 'hello, how are you?'
print(text.capitalize())

# 2. casefold() - used to compare two strings irrespective of the case of the letters inside the string.
print('\n---------------- casefold() -----------------')
text1: str = 'MARio is A good boY'
text2: str = 'maRIO IS a GoOd BOy'
print(text1.casefold())
print(text2.casefold())

# 3. center() - arranges the string at the center of the bigger string
print('\n---------------- center() -----------------')
text1: str = 'Ram'
print(text1.center(50, ','))
print(text1.center(50, '-'))

# 4. count() - counts number of occurrences of the substring in the main string
print('\n---------------- count() -----------------')
text = 'hi hello hi hello hi hi hi'
print(text.count('hi'))

# 5. encode() - encodes the string in specified format
print('\n---------------- encode() -----------------')
text: str = 'Elon musk'
print(text.encode(encoding='UTF-8', errors='strict'))

# Encoding with a different encoding and error handling
text = "Hello, World! 你好"
encoded_text = text.encode('ascii', errors='replace')
print(encoded_text)  # Output: b'Hello, World! ??'

# 6. endswith() - Returns True or False depending on whether the string ends with given character
print('\n---------------- endswith() -----------------')
text: str = 'apple'
print(text.endswith(('e', 'a')))

# 7. expandtabs() - Expands tabs with the spaces that is specified in the argument
print('\n---------------- expandtabs() -----------------')
text: str = 'text1\ttext2\ttext3\ttext4\ttext5\ttext6'
print(text.expandtabs(5)) 

# 8. find() - Returns the first and the lowest occurrence of the string to be searched, returns '-1' if not found.
print('\n---------------- find() -----------------')
text: str = 'Remember to comment and subscribe !'
position: int = text.find('subscribe')
print(position)
print(text[position:])

# 9. format() - substitutes variables with values
print('\n---------------- format() -----------------')
text: str = '{Animal} is {Speaks}'
print(text.format(Animal='Dog', Speaks='Barking'))
print(text.format(Animal='Cat', Speaks='Meowing'))

text: str = '{} is good at {}'
print(text.format('Dog', 'Smelling'))

# 10. format_map() - Mapping the co-ordinates 
print('\n---------------- format_map() -----------------')
text: str = 'The co-ordinates of the location are x = {x}, y = {y}'
dict = {'x': 10.12, 'y': 13.13}
print(text.format_map(dict))

# 11. index() - returns the index of the 'search' string location in main string, returns 'error' if string not found
print('\n---------------- index() -----------------')
text: str = 'Astronaut landed on the moon safely'
print(text.index('moon'))
#print(text.index(' sun'))   # Throws error as 'sun' is not present in the text.

# 12. isalnum() - return True only if the string is made up of alphabets and digits or else returns false.
print('\n---------------- isalnum() -----------------')
text1: str = 'radheRadhe123'
text2: str = 'radheRadhe123!'
print(text1.isalnum())
print(text2.isalnum())

# 13. isalpha() - returns True only if the string is made up of just alphabets or else returns false.
print('\n---------------- isalpha() -----------------')
text1: str = 'radheRadhe123'
text2: str = 'radheRadhe'
print(text1.isalpha())
print(text2.isalpha())

# 14. isascii() - returns True only if the string is made up of all the ascii characters or else returns False.
print('\n---------------- isascii() -----------------')
text1: str = 'radhe!@#$%^&*()'
text2: str = 'Jenny©'
print(text1.isascii()) 
print(text2.isascii())

# 15. isdecimal() - returns True only if the string is made up of english digits 0-9 or else returns False.
print('\n---------------- isdecimal() -----------------')
text1: str = '1234'
text2: str = '1234ab'
print(text1.isdecimal())
print(text2.isdecimal())

# 16. isdigit() - returns True only if the string is made up of any type of digits but in English language only or else returns False.
print('\n---------------- isdigit() -----------------')
text1: str = '① ② ③ ④ ⑤ ⑥ ⑦ ⑧ ⑨ ⑩'
text2: str = '① ② ③ ④ ⑤ ⑥ ⑦ ⑧ ⑨ ⑩ 1432'
print(text1.isdigit())
print(text2.isdigit())

# 17. isnumeric() - returns True only if the string is made up of digits in any language, or else returns False.
print('\n---------------- isnumeric() -----------------')
text1: str = '①②③④⑤⑥⑦⑧⑨⑩'         # accepts single circled digits.
text2: str = '⓫⓫⓮⓯⓰⓱⓲⓳⓴'          # accepts filled digits .
text4: str = '⓵⓶⓷⓸⓹⓺⓻⓼⓽⓾' # accepts double rounded digits too.
text3: str = '一二三四五六七八九十' # This string contains the japanese symbols from 1 to 10.
print(text1.isnumeric())
print(text2.isnumeric())
print(text3.isnumeric())
print(text4.isnumeric())

# 18. isidentifier() - returns true if the string is a valid identifier i.e. it can be used for naming variable or a function
print('\n---------------- isidentifier() -----------------')
text1: str = 'my-var'
text2: str = 'my_func'
text3: str = '1my_func'
print(text1.isidentifier())
print(text2.isidentifier())
print(text3.isidentifier())

#19. islower() - returns True if the entire string is lowercased or else false
print('\n---------------- islower() -----------------')
text1: str = 'my-Var'
text2: str = 'mylar'
text3: str = 'cav-lar'
print(text1.islower())
print(text2.islower())
print(text3.islower())

#20. isprintable() - returns True only if the string does not contain any escape characters such as '\n', '\t', '\r'
print('\n---------------- isprintable() -----------------')
text1: str = 'Hi Dear\n How are you?'
print(text1.isprintable())
text2: str = 'Hi Dear\t How are you?'
print(text2.isprintable())
text3: str = 'Hi Dear\\ How are you?'
print(text3.isprintable())

#21. isspace() - returns True only if the string is made up of only spaces
print('\n---------------- isspace() -----------------')
text1: str = 'Hi Dear '
print(text1.isspace())
text2: str = '    '
print(text2.isspace())

#22. istitle() - returns True if first character of each word is upper cased.
print('\n---------------- isspace() -----------------')
text1: str = 'Shivaji - The King Of Deccan'
print(text1.istitle())
text2: str = 'Like king like subjects'
print(text2.istitle())


#23. isupper() - returns True if all characters in the string are upper cased.
print('\n---------------- isupper() -----------------')
text1: str = 'The King Of Deccan'
print(text1.isupper())
text2: str = 'GOOD LUCK!'
print(text2.isupper())
text3: str = 'wELLCOME'
print(text3.isupper())

#24. join() - joins the items of the iterable using the specified string
print('\n---------------- join() -----------------')
text1: str = ['Shivaji', 'The', 'King', 'Of', 'Deccan']
print('-'.join(text1))
print(' '.join(text1))

#25. ljust() - left justifies the string and fills the remaining space with specified characters
print('\n---------------- ljust() -----------------')
text1: str = 'The King is powerful'
print(text1.ljust(50, '*'))
print(text1.ljust(50, '-'))

#26. lower() - returns lowercased string
print('\n---------------- lower() -----------------')
text1: str = 'The King IS PowerfuL'
print(text1.lower())

#27. lstrip() - removes the specified string from the left side of the string
print('\n---------------- lstrip() -----------------')
text1: str = 'The The The King IS PowerfuL'
print(text1.lstrip('The'))
text2: str = 'The The The King IS PowerfuL'
print(text2.lstrip('The '))
text3: str = '     King IS PowerfuL'
print(text3.lstrip(' '))

#28, 29. maketrans() & translate() - maketrans() creates a mapping table and translate() converts the string using that table.
print('\n---------------- maketrans() and translate() -----------------')
text: str = 'This is Bacon Baby'
table = text.maketrans('B', '😄')
print(table)
print(text.translate(table))

#30. paritition() - split the string at given character/s
print('\n---------------- partition() -----------------')
text: str = 'a+b=c'
print(text.partition('='))
text: str = 'India is a continental country'
print(text.partition('con'))
print(text.partition('c'))     # partitions the string on first occurrence of 'c'

#31. removeprefix() - removes the specified part of the string from its prefix
print('\n---------------- removeprefix() -----------------')
text: str = 'InDependence is not good'
print(text.removeprefix('In'))
print(text.removeprefix('InDe'))

#32. removesuffix() - removes the specified part of the string from its suffix
print('\n---------------- removesuffix() -----------------')
text: str = 'Independent nations make progress and become developed nations.'
print(text.removesuffix('s.'))
print(text.removesuffix('nations'))
print(text.removesuffix('nations.'))

#33. replace() - substitute a occurrence of one string with another
print('\n---------------- replace() -----------------')
text: str = 'Andromeda is a spiral galaxy. Andromeda is a part of local galaxy cluster.'
print(text.replace('Andromeda', 'Milkyway'))        # Replace all the occurrences
print(text.replace('Andromeda', 'Milkyway', 1))     # Replace the first occurrence
print(text.replace('Andromeda', 'Milkyway', 2))     # Replace the first two occurrences
print(text.replace('Andromeda', 'Milkyway', 3))     # Replace the first three occurrences

#34. rfind() - searches the string from its right side for an argument string. Returns '-1' if not found.
print('\n---------------- rfind() -----------------')
text: str = 'Einstein was awarded Nobel Prize for his photoelectric effect discovery.'
print(text.rfind('dis'))
print(text.rfind('Eins'))
print(text.rfind('invention'))

#35. rindex() - searches the string from its right side for an argument string. Returns error if not found.
print('\n---------------- rindex() -----------------')
text: str = 'Einstein was awarded Nobel Prize for his photoelectric effect discovery.'
print(text.rindex('dis'))
print(text.rindex('Eins'))
try:
  print(text.rindex('invention'))
except Exception as e:
  print('Encountered the error: %s' % e)

#36. rjust() - justfies the string on right side
print('\n---------------- rjust() -----------------')
text: str = 'The End'
print(text.rjust(30, '-'))
print(text.rjust(30, '*'))

#37. rpartition() - Partition the string on the specified character but from right side
print('\n---------------- rpartition() -----------------')
text: str = 'The history repeats itself if lessons not learnt and not found'
print(text.partition('not'))
print(text.rpartition('not'))

#38. rsplit() - starts splitting the string from right side
print('\n---------------- rsplit() -----------------')
text: str = 'The history repeats itself if lessons not learnt and not found'
print(text.rsplit(sep=' '))
print(text.rsplit(sep=' ', maxsplit=3))

#39. split() - starts splitting the string from left side
print('\n---------------- split() -----------------')
text: str = 'The history repeats itself if lessons not learnt and not found'
print(text.split(sep=' '))
print(text.split(sep=' ', maxsplit=2))

#40. rstrip() - strip the text from right side of the string till the string to be searched is found.
print('\n---------------- rstrip() -----------------')
text: str = 'He is Mario Mario'
print(text.rstrip('Mario'))
text: str = 'He is Mario Mario'
print(text.rstrip('Mario '))

#41. splitlines() - splits the input string on escape characters and returns an array of strings
print('\n---------------- splitlines() -----------------')
text: str = 'Remember to comment! \n or else \n'
print(text.splitlines())
print(text.splitlines(keepends=True))
print(text.splitlines(keepends=1))

#42. startswith() - returns True if the string starts with input string
print('\n---------------- startswith() -----------------')
text: str = 'The Sun rises in the east.'
print(text.startswith('T'))
print(text.startswith('The'))
print(text.startswith('The '))

#43. strip() - strips the characters specified in the argument from the leading or trailing side of string.
#            - The order of characters in the input string doe not matter.
print('\n---------------- strip() -----------------')
text: str = '  The Sun rises in the east.  '
print(text.strip())
print(text.strip('  The'))
print(text.strip('east.'))
print(text.strip('east.T  '))

#44. swapcase() - changes the case of each character in the string
print('\n---------------- swapcase() -----------------')
text: str = '*  The Sun rises in the east.  *'
print(text.swapcase())
text: str = 'sUN rISES iN the EAST.  '
print(text.swapcase())

#45. title() - upper cases each first character of the word
print('\n---------------- title() -----------------')
text: str = '*  The Sun rises in the east.  *'
print(text.title())

#46. zfill() - Prefixes the string with zeros to make a string of specified length
print('\n---------------- zfill() -----------------')
text: str = 'The Sun rises in the east.*'
print(text.zfill(40))
'''

# ---------------------------------------------------------------
# statistics' module in Python 
# ---------------------------------------------------------------

'''
print('\n---------------- statistic module in Python -----------------')

import statistics
data1 = [10, 20, 30, 40, 50, 60]
data2 = [10, 200, 300, 40, 50]
print(f'{statistics.mean(data1) = }')
print(f'{statistics.mean(data2) = }')

print(f'\n{statistics.median(data1) = }')
print(f'{statistics.median(data2) = }')

data3 = [1, 2, 2, 3, 4]
print(f'\n{statistics.mode(data3) = }')               
print(f'{statistics.mode(data1) = }')               

print(f'{statistics.mean(data1) = }')
print(f'{statistics.mean(data2) = }')

print(f'\n{statistics.variance(data1) = }')
print(f'{statistics.variance(data2) = }')

print(f'\n{statistics.pstdev(data1) = }')
print(f'{statistics.pstdev(data2) = }')

print(f'\n{statistics.pstdev(data1) = }')
print(f'{statistics.pstdev(data2) = }')

print(f'\n{statistics.harmonic_mean(data1) = }')
print(f'{statistics.harmonic_mean(data2) = }')

print(f'\n{statistics.median_low(data1) = }')
print(f'{statistics.median_low(data2) = }')

print(f'\n{statistics.median_high(data1) = }')
print(f'{statistics.median_high(data2) = }')
'''

# ---------------------------------------------------------------
# 'requests' library in Python 
# ---------------------------------------------------------------
# Usage : python PythonPractive2.py weezer

'''
import sys
import json
import requests

response = requests.get('https://itunes.apple.com/search?entity=song&limit=1&term=' + sys.argv[1])
print(response.json())
print(json.dumps(response.json(), indent=2))
'''

# ---------------------------------------------------------------
# File 'I/O' in Python 
# ---------------------------------------------------------------

'''
l = ['Ram', 'Shyam', 'Tata', 'Bye Bye']
with open("names.txt", "w") as f:
    for item in l:
        f.write(item + "\n")
# (OR)

l = ['Ram', 'Shyam', 'Tata', 'Bye Bye']
f = open("names1.txt", "w") 
for item in l:
    f.write(item + "\n")
f.close()
'''

# ---------------------------------------------------------------
# csv reader/writer in Python 
# ---------------------------------------------------------------

'''
import csv

# ------- csv.reader()
with open('student.csv', 'r') as file:
    reader = csv.reader(file)
    for line in reader:
        if len(line):
            print(f"{line[0]} is from {line[1]}")

print()

# ------- csv.DictReader()
with open('student.csv', 'r') as file:
    reader = csv.DictReader(file)
    for line in reader:
        print(f"{line['Name']} lives in {line['Home']}")

# ------- csv.writer()
with open('student.csv', 'a') as file:
    writer = csv.writer(file)
    writer.writerow([])
    writer.writerow(['Rahul', 'UP'])

# ------- csv.DictWriter()
with open('student.csv', 'a') as file:
    writer = csv.DictWriter(file, fieldnames= ["Name", "Home"])
    writer.writerow({"Name":"Sachin", "Home":"MP"})
'''

# ---------------------------------------------------------------
# Walrus Operator (:=) in Python 
# ---------------------------------------------------------------
'''
import re
text: str = 'Dog, Barks'
reg = r'(.*),\s+(.*)'
if matches := re.search(reg, text):
    print(f'{matches.group(1)} is an animal which {matches.group(2)}.')
'''

# ---------------------------------------------------------------
# Getter/Setter functions in Python 
# ---------------------------------------------------------------
# Even following __init__() function will call the getter/setter functions to set the values of variables.
# This makes sure that all the updates to the member variables are done through the single route and this
# helps in enforcing rules for updating the variables.

'''
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
    print(stud.name)
    stud.name = "James"
    print(stud.name)

if __name__ == '__main__':
    main()
'''

# ---------------------------------------------------------------
# Class methods in Python 
# ---------------------------------------------------------------
'''
# Example 1
import random
class Hat:
    houses = ['Gryffindor', 'Hufflepuff', 'Ravenclaw', 'Slytherin' ]

    @classmethod
    def sort(cls, name):
        return f'{name} is in house {random.choice(cls.houses)}'
    
print(Hat.sort('Ralph'))

# Example 2
class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return (f'Student {self.name} is {self.age} years old.')

    @classmethod
    def get(cls):
        name = input('Enter student name - ')
        age = input('Enter student age - ')
        return cls(name, age)
    
def main():
    stud = Student.get()
    print(stud)

main()
'''

# ---------------------------------------------------------------
# Inheritance in Python 
# ---------------------------------------------------------------
'''
class Wizard:
    def __init__(self, name):
        if not name:
            raise ValueError('Name value missing')
        self.name = name

    def __str__(self):
        return f'My name is {self.name}'

class Student(Wizard):
    def __init__(self, name, house):
        super().__init__(name)
        self.house = house

class Professor(Wizard):
    def __init__(self, name, subject):
        super().__init__(name)
        self.subject = subject

wizard = Wizard('Albus')
stud = Student('Harry', 'Gryffindor')
prof = Professor('Severus', 'Defense against the dark arts')

print(wizard)
print(stud)
print(prof)
'''

# ---------------------------------------------------------------
# Operator Overloading in Python 
# ---------------------------------------------------------------
'''
class Vault:
    def __init__(self, galleons=0, sickles=0, knuts=0):
        self.galleons = galleons
        self.sickles = sickles
        self.knuts = knuts

    def __str__(self):
        return f'{self.galleons:>5.0f} Galleons, {self.sickles:>5.0f} Sickles, {self.knuts:>5.0f} Knuts'
    
    def __add__(self, other):
        return Vault(self.galleons + other.galleons, self.sickles + other.sickles, self.knuts + other.knuts)

    def __sub__(self, other):
        return Vault(self.galleons - other.galleons, self.sickles - other.sickles, self.knuts - other.knuts)

    def __mul__(self, other):
        return Vault(self.galleons * other.galleons, self.sickles * other.sickles, self.knuts * other.knuts)

    def __truediv__(self, other):
        return Vault(self.galleons / other.galleons, self.sickles / other.sickles, self.knuts / other.knuts)

    def __floordiv__(self, other):     
        return Vault(self.galleons // other.galleons, self.sickles // other.sickles, self.knuts // other.knuts)

    def __mod__(self, other):   
        return Vault(self.galleons % other.galleons, self.sickles % other.sickles, self.knuts % other.knuts)

    def __pow__(self, other):
        return Vault(self.galleons ** other.galleons/1e13, self.sickles ** other.sickles/1e13, self.knuts ** other.knuts/1e13)

    def __lt__(self, other):       
        return (self.galleons * 100 + self.sickles*10 + self.knuts) < (other.galleons*100 + other.sickles*10 + self.knuts)

    def __le__(self, other):      
        return (self.galleons * 100 + self.sickles*10 + self.knuts) <= (other.galleons*100 + other.sickles*10 + self.knuts)

    def __eq__(self, other):
        return (self.galleons * 100 + self.sickles*10 + self.knuts) == (other.galleons*100 + other.sickles*10 + self.knuts)

    def __ne__(self, other):   
        return (self.galleons * 100 + self.sickles*10 + self.knuts) != (other.galleons*100 + other.sickles*10 + self.knuts)

    def __gt__(self, other):  
        return (self.galleons * 100 + self.sickles*10 + self.knuts) > (other.galleons*100 + other.sickles*10 + self.knuts)

    def __ge__(self, other):
        return (self.galleons * 100 + self.sickles*10 + self.knuts) >= (other.galleons*100 + other.sickles*10 + self.knuts)

Potter = Vault(100, 50, 25)
Hermione = Vault(80, 40, 20)
print(Potter + Hermione)
print(Potter - Hermione)
print(Potter * Hermione)
print(Potter / Hermione)
print(Potter // Hermione)
print(Potter % Hermione)
#print(Potter ** Hermione)
print(Potter < Hermione)
print(Potter <= Hermione)
print(Potter == Hermione)
print(Potter != Hermione)
print(Potter > Hermione)
print(Potter >= Hermione)
'''

# ---------------------------------------------------------------
# 'Global' keyword in Python 
# ---------------------------------------------------------------
'''
# Example 1 - The following code will throw error as Updating global variable directly inside functions is not supported.
balance = 0

def main():
    print("Initial Balance = ", balance)
    deposit(500)
    withdraw(200)
    print("Final Balance = ", balance)

def deposit(amount):
    #print("Balance = ", balance)
    balance += int(amount)

def withdraw(amount):
    #print("Balance = ", balance)
    balance -= int(amount)

main()

# Example 2 - The solution to the above problem is to use global keyword inside function and make the global variable available locally.
balance = 0

def main():
    print("Initial Balance = ", balance)
    deposit(500)
    withdraw(200)
    print("Final Balance = ", balance)

def deposit(amount):
    global balance
    balance += int(amount)

def withdraw(amount):
    global balance
    balance -= int(amount)

main()
'''

# ---------------------------------------------------------------
# Constants in Python 
# ---------------------------------------------------------------
'''
TIMES = 3
def meaw(n):
  print('Meaw' * n)

meaw(TIMES)
'''

# ---------------------------------------------------------------
# Python documentation  
# ---------------------------------------------------------------
"""
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
"""

# ---------------------------------------------------------------
#   Python argparse module  
# ---------------------------------------------------------------
# Usage: python pythonPractice.py -h 
'''
import argparse
def main1():
    parser = argparse.ArgumentParser()
    parser.add_argument('-n', default=1, type=int, help='Number of time to Meow')
    args = parser.parse_args()
    for _ in range(args.n):
        print("Meow")
main1()
'''

# ---------------------------------------------------------------
#   "unpacking" in Python Module
# ---------------------------------------------------------------

def total(galleons, sickles, knuts):
  return (galleons* 17 + sickles) * 29 + knuts 

# Unpacking with the help of lists
coins = [100, 50, 75]
print(total(*coins))

# Unpacking with the help of dictionaries
coins1 = {"galleons": 100, "sickles": 50, "knuts": 75}
print(total(**coins1))

# ---------------------------------------------------------------
#   "map()" function in Python
# ---------------------------------------------------------------
mystr: str = 'hi how are you'
print( ''.join(map(str.upper, mystr)) )

# ---------------------------------------------------------------
#   Dictionary comprehension in Python
# ---------------------------------------------------------------
import pprint  # Preety Prints any complex data structure

# simple dictionary comprehension
print('\n------- Simple dictionary comprehension -------- ')
di = {x:x**2 for x in range(6)}
print(di)

# conditional dictionary comprehension
print('\n------- Conditional dictionary comprehension -------- ')
print( {item:value*2 for item, value in di.items() if item%2 == 0} )

# Reverse pairs in the dictionary - Inverting the dictionary
print('\n------- Inverted dictionary -------- ')
print({ value:item for item, value in di.items()})

# Nested dictionary comprehension
print('\n------- Nest dictionary -------- ')
ndict = { item:{'square':value, 'cube':item**3} for item, value in di.items()}
pprint.pprint(ndict)

# ---------------------------------------------------------------
#   'else' with loops in Python
# ---------------------------------------------------------------
print("\n------------------------- Python Loops with 'else' statement --------------------------------")
# Example 1:
i = 0
while i< 10:
    print(i, end=' ')
    if i == 5:
        break
    i+=1
else:
    print('Else Not Executed: as control came out of loop by executing "break" statement')
print() 

# Example 2:
i = 0
while i< 10:
    print(i, end=' ')
    if i == 20:
        break
    i+=1
else:
    print('Else Executed: as control came out of loop without executing "break" statement')


# Example 3:
for i in range(10):
    print(i, end=' ')
    if i == 6:
        break
else:
    print('Else Not Executed: as control came out of the loop by executing "break" statement')
print()

# Example 4:
for i in range(10):
    print(i, end=' ')
    if i == 12:
        break
else:
    print('Else Executed: as control came out of the loop without executing "break" statement')

# ---------------------------------------------------------------
#   'name mingling' in Python
# ---------------------------------------------------------------
print('\n------------------------- Python Name Mingling --------------------------------')
class Item:
    x = 10
    __p = 20

print(f'{Item.x = }')
try:
    print(f"{Item.__p}")
except Exception as e:
    print(e)
    print('Python has modified the name of "__p" variable to "_Item__p"')
finally:
    print(f"{Item._Item__p = }")
    
# ---------------------------------------------------------------
#   Extract int type values from a list of heterogeneous elements
# ---------------------------------------------------------------
# You can use type() function to get the data type of an element in the list.
print('\n------------------------- Extract int values from heterogeneous elements --------------------------------')
l1 = [1, 2, 'Jhalu', 'Shaalu', 'Maali', '2+3i', True, False, 3.1415, 11]
l2 = []
for i in l1:
    if type(i) == int:
        l2.append(i)
print(l1)
print(l2)

print('-------------- Using filter() function --------------------')
print( list(filter( lambda x: type(x) == int, l1)) )

    
# ---------------------------------------------------------------
#   Multiple Inheritance in Python
# ---------------------------------------------------------------
print('\n-------------- Multiple Inheritance in Python  --------------')
print('\n-------------- Example 1  --------------')
class A1:
    def __init__(self):
        print('A1 init method called')
class A2:
    def __init__(self):
        print('A2 init method called')
class A3:
    def __init__(self):
        print('A3 init method called')
class B(A1, A2, A3):
    def __init__(self):
        super().__init__()
        print('B init method called')

b = B()

# Example 2
print('\n-------------- Example 2  --------------')
# Base class 1
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def display_person_info(self):
        print(f"Name: {self.name}, Age: {self.age}")

# Base class 2
class Employee:
    def __init__(self, employee_id, salary):
        self.employee_id = employee_id
        self.salary = salary

    def display_employee_info(self):
        print(f"Employee ID: {self.employee_id}, Salary: ${self.salary}")

# Derived class using multiple inheritance
class Manager(Person, Employee):
    def __init__(self, name, age, employee_id, salary, department):
        # Initializing both parent classes
        Person.__init__(self, name, age)
        Employee.__init__(self, employee_id, salary)
        self.department = department

    def display_manager_info(self):
        self.display_person_info()
        self.display_employee_info()
        print(f"Department: {self.department}")

# Create an instance of Manager
manager = Manager("Alice", 35, "E123", 85000, "IT")

# Display manager information
manager.display_manager_info()
