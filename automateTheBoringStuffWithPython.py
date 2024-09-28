l = 'Ram'*5
print(l)

try:
  print('Shyam'*'ram')
except Exception:
  print('Multiplying a word with word is not supported')

try:
  print('Shyam'*3.2)
except Exception:
  print('Multiplying a word with float is not supported')
finally:
  print('\n These are different operations on strings')
print('---------------------------------------')

print(str(23))
print(int('-23'))
print(float('23.455'))

try:
  print(int('-23.23'))
except Exception:
  print('int() can not handle float values')

print('---------------------------------------')
try:
  print( 23 == '23')
  print( 23 == 00023.000)
finally:
  print('Integer and String Values can not be compared')
  print('Integer and float values can be compared with each other')

bacon = 20
print(bacon + 1)

print('spam' + 'spamspam')
print('spam'*3)

print('int(), float(), str() are the three functions to get integer, float and str values')