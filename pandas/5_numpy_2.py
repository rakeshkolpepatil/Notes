import numpy as np 

print("\n           ------ 1. Split NumPy Arrays - 1d ------- \n ")

np_1d = np.array((1, 2, 3, 4, 5, 6, 7, 8, 9))   # Odd number of elements
# np_1d = np.array((1, 2, 3, 4, 5, 6, 7, 8))    # Even number of elements

'''
print("np_array1 - ", np_1d)
np_split_1d = np.array_split(np_1d, 2)

print("\nArray after splitting i.e. returns 2 arrays : ")
for i in np_split_1d:
  print(i)

print("\nAccessing individual arrays after split ")
print(" Array 1 : ", np_split_1d[0])
print(" Array 2 : ", np_split_1d[1])

np_1d = np.array((1, 2, 3, 4, 5, 6, 7, 8))    # Even number of elements
np_split_1d_2 = np.array_split(np_1d, 3)

print("\nArray after splitting i.e. returns 3 arrays : ")
for i in np_split_1d_2:
  print(i)

print("\n np_split_1d_2 : ", np_split_1d_2 )
print("\n np_split_1d_2 : ", type(np_split_1d_2) )

print("\n           ------ 2. Split NumPy Arrays - 2d ------- \n ")

n1 = np.array([[1, 2, 3, 4, 5], [3, 4, 6, 7, 8]])

n1_split = np.split(n1, 2)

print("\n After splitting a 2 dimensional array i.e. returns 2 arrays : ")

print(" Array 0 :", n1_split[0])
print(" Array 1 :", n1_split[1])


print("\n           ------ 3. Search NumPy Arrays  ------- \n ")
n = np.array([0, 1, 2, 3, 0, 1, 2, 3, 0])
print("\n n = ", n)

res = np.where(n == 0)    # Search where value 0 is present inside the np array n.
print("\n res = ", res)

print("\n           ------ 4. Sort NumPy Arrays  ------- \n ")
n = np.array([0, 1, 2, 3, 0, 1, 2, 3, 0])
print("\n Unsorted Array n     :- ", n)
print(" Sorted int Array n   :- ", np.sort(n))

print("\n -- Get indices that would sort n1 -- ")
n_argsort = np.argsort(n)         
print("\n np.argsort(n)  :- ", n_argsort) 

n = np.array(["Java", "java", "Kotlin", "C++", "Ruby", "Go", "swift"])
print("\n Unsorted Array n     :- ", n)
print(" Sorted str Array n   :- ", np.sort(n))

n = np.array([[31, 22, 34, 14, 57], [3, 54, 677, 72, 68]])
print("\n Unsorted 2d Array n :- \n", n)
print("\n Sorted 2d Array n   :- \n", np.sort(n))


print("\n          ------ 5. Axis in NumPy Arrays  ------- \n ")
n = np.array([[31, 22, 34, 14, 57], [3, 54, 677, 72, 68], [1, 45, 67, 33, 3276]])

print("\n Original Array n :- \n", n)

print("\n Minimum value with Axis 0 (Vertical Axis)    : ", n.min(axis = 0))
print(" Minimum value with Axis 1 (Horizontal Axis)  : ", n.min(axis = 1))

print("\n          ------ 6. Intersection of NumPy Arrays  ------- \n ")

n1 = np.array([11, 0, 1, 2, 3, 4, 5, 6, 7])
n2 = np.array([7, 2, 1, 2, 9, 10, 11, 12])

res = np.intersect1d(n1, n2)
print("Intersection is finding the common elements between two arrays - ")
print("Intersection of n1 and n2 (sorted automatically): ", res)

n1 = np.array([[0, 1, 2, 3], [4, 5, 6, 7]])
n2 = np.array([[8, 9, 1], [11, 6, 13]])

res = np.intersect1d(n1, n2)
print("Intersection is finding the common elements between two arrays - ")
print("Intersection of n1 and n2 (sorted automatically): ", res)


print("\n          ------ 7. Difference between NumPy Arrays  ------- \n ")
n1 = np.array([0, 1, 2, 3, 4, 5, 6, 7])
n2 = np.array([4, 5, 6, 7, 11, 12])

print("Subtract the common elements from the first array and display rest ")
res = np.setdiff1d(n1, n2)
print("Set difference of n1 and n2 : ", res)

res = np.setdiff1d(n2, n1)
print("Set difference of n2 and n1 : ", res)

print("\n          ------ 8. Arithmetic Operations on NumPy Arrays  ------- \n ")
n1 = np.array([0, 1, 2, 3, 4, 5, 6, 7])
n2 = np.array([4, 5, 6, 7, 11, 12, 14, 65])

print("np.sum([n1, n2])           : ", np.sum([n1, n2])         )
print("np.sum([n1, n2], axis = 0) : ", np.sum([n1, n2], axis=0) )
print("np.sum([n1, n2], axis = 1) : ", np.sum([n1, n2], axis=1) )

print("np.add(n1, n2)             : ", np.add(n1, n2)         )
print("np.subtract(n1, n2)        : ", np.subtract(n1, n2)    )
print("np.multiply(n1, n2)        : ", np.multiply(n1, n2)    )
print("np.divide(n1, n2)          : ", np.divide(n1, n2)      )

print("\n          ------ 8.1 Polynomial Roots NumPy Arrays  ------- \n ")
coefficients = [1, -5, 6]           # Represents 'x^2 - 5x + 6'
roots = np.roots(coefficients)
print("Roots:", roots)

coefficients = [1, -6, 11, -6]      # Represents 'x^3 - 6x^2 + 11x - 6'
roots = np.roots(coefficients)
print("Roots:", roots)

coefficients = [1, 2, 5]            # Represents x^2 + 2x + 5
roots = np.roots(coefficients)
print("Roots:", roots)

'''

print("\n          ------ 9. Scaler Operations on NumPy Arrays  ------- \n ")
print("Perform operations on each element of the array ")
n1 = np.array([0, 1, 2, 3, 4, 5, 6, 7])
n2 = np.array([4, 5, 6, 7, 11, 12, 14, 65])

print(" n1                : ", n1 )        
print(" n2                : ", n2 )        

print("\n n1 + 10           : ", n1 + 10 )        
print(" n2 + 5            : ", n2 + 5  )        

print("\n n1 - 10           : ", n1 - 10 )        
print(" n2 - 5            : ", n2 - 5  )        

print("\n n1 * 10           : ", n1 * 10 )        
print(" n2 * 5            : ", n2 * 5  )        

print("\n n1 / 10           : ", n1 / 10 )        
print(" n2 / 5            : ", n2 / 5  )        

print("\n np.add(n1, 1)       : ", np.add(n1, 1))       # Add 1 to each element of n1     
print("\n np.multiply(n1, 2)  : ", np.multiply(n1, 2))  # Multiply each element of n1 by 2       
print("\n np.sqrt(n1, 2)      : ", np.sqrt(n1))         # Compute square root of each element in n1
print("\n np.sin(n1)          : ", np.sin(n1))          # Compute sine of each element in n1

'''
print("\n          ------ 9.1  Linear Algebra in NumPy Arrays  ------- \n ")
mat1 = np.array([[1, 2], [3, 4]])   # Define a 2x2 matrix
print("\n mat1 = \n", mat1)

mat_inv = np.linalg.inv(mat1)       # Compute the inverse of mat1
print("\n Inverse of matrix 'mat1' : mat_inv = \n", mat_inv)

mat_det = np.linalg.det(mat1)       # Compute the determinant of mat1
print("\n Determinant of matrix 'mat1' : mat_det = \n", mat_det)

mat_eig = np.linalg.eig(mat1)       # Compute the eigenvalues and eigenvectors of mat1
print("\n Eigenvalues of matrix 'mat1' : mat_eig.eigenvalues  = \n", mat_eig.eigenvalues)
print("\n Eigenvalues of matrix 'mat1' : mat_eig.eigenvectors = \n", mat_eig.eigenvectors)

print()
print("\n          ------ 10. Statistical Operations on NumPy Arrays  ------- \n ")
n1 = np.array([0, 1, 2, 3, 4, 5, 6, 7])
n2 = np.array([4, 5, 6, 7, 11, 12, 14, 65])

print("\n n1          : ", n1 )        
print(" n2          : ", n2 )        

# Compute mean of arr1
print("\n n1.mean()   : ", np.mean(n1))        
print(" n2.mean()   : ", np.mean(n2))        

# Compute median of arr1
print("\n n1.median() : ", np.median(n1))        
print(" n2.median() : ", np.median(n2))        

# Compute standard deviation of arr1
print("\n n1.std()    : ", np.std(n1))        
print(" n2.std()    : ", np.std(n2))        

# Compute variance of arr1
var_val = np.var(n1)  
print("\n np.var(n1)    : ", np.var(n1))        

# Compute 50th percentile (median) of arr1
percentile_val = np.percentile(n1, 50)  
print("\n np.percentile(n1, 25)   : ", np.percentile(n1, 25))        
print(" np.percentile(n1, 50)   : ", np.percentile(n1, 50))        
print(" np.percentile(n1, 75)   : ", np.percentile(n1, 75))        

print("\n          ------ 11. Random numbers in NumPy  ------- \n ")
from numpy import random

print("\n --- Get random number from 0 to 5 --- ")
n = random.randint(5)
print("\n Random number between 0 and 5 : ", n)

n = random.randint(10, size=10)
print("\n The array of size 10 filled with random numbers till 10 :- ", n)


l = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
n = random.choice(l)
print("\n list = ", l)
print("\n Select a random number from the list : ", n)

print("\n --- Generate a 3x3 array of random values between 0 and 1 uniform distribution --- ")
print("\n np.random.rand(3, 3) - \n", random.rand(3, 3) )

print("\n --- Generate a 3x3 array of random values from a normal distribution ---  ")
print("\n np.random.randn(3, 3) = \n", random.randn(3, 3) )   

print("\n --- Generate a 2x2 array of random integers between 1 and 10 --- ")
print("\n np.random.randint(1, 10, (2, 2)) = \n" , random.randint(1, 10, size=(2, 2))  ) 

print("\n --- Randomly choose 3 values from the list --- ")
print(" np.random.choice([1, 2, 3, 4], 3) = ", random.choice([1, 2, 3, 4], 3) )

print("\n")

print("\n          ------ 12. 'Logs' in NumPy  ------- \n ")

n = random.randint(10, size=4)
print("\n Random number between 0 and 5 : ", n)
print("\n Random number between 0 and 5 : ", n)

print("\n The log2 of numpy array  - ",  np.log2(n))
print("\n The log10 of numpy array - ", np.log10(n))

print("\n          ------ 12. LCM, HCF, GCD in NumPy  ------- \n ")
a = 2
b = 8
print(" GCD(a, b) / HCF(a, b) = ", np.gcd(a, b))
print(" LCM(a, b)             = ", np.lcm(a, b))

print("\n          ------ 13. Bitwise Operations  -------  ")

print("\n -- Perform bitwise AND operation between 5 and 3 -- ")
bitwise_and_res = np.bitwise_and(5, 3)  
print(" np.bitwise_and(5, 3) : ", bitwise_and_res )

print("\n -- Perform bitwise OR operation between 5 and 3 --")
bitwise_or_res = np.bitwise_or(5, 3)  
print(" np.bitwise_or(5, 3) : ", bitwise_or_res )

print("\n -- Perform bitwise XOR operation between 5 and 3 --")
bitwise_xor_res = np.bitwise_xor(5, 3)  
print(" np.bitwise_xor(5, 3) : ", bitwise_xor_res )

print("\n -- Perform bitwise NOT operation on 5 --")
bitwise_not_res = np.bitwise_not(5)  
print(" np.bitwise_not(5) : ", bitwise_not_res )
'''

print()
