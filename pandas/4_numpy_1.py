
import numpy as np 

'''
print("\n ------ 1. Create NumPy Arrays ------- \n ")

print( "\n --- Create a 1D array from a tuple --- \n ")
np_array1 = np.array((1, 2, 3, 4, 5, 6, 7))
print(" np_array1 - ", np_array1)
print("type(np_array1) - ", type(np_array1))

print( "\n --- Create a 1D array from a list --- \n ")
np_array2 = np.array([1, 2, 3, 4, 5, 6, 7])
print(" np_array2 - ", np_array2)
print("type(np_array2) - ", type(np_array2))

print( "\n --- Create a 2D array from a list --- \n ")
np_array3 = np.array([[1, 2, 3, 4], [ 4, 5, 6, 7]])
print(" np_array3 - \n", np_array3)
print("type(np_array3) - ", type(np_array3))


print("\n ------ 2. Dimensions in NumPy Array ------- \n ")

n = np.array(1)

np_array1 = np.array((1, 2, 3, 4, 5, 6, 7))
np_array2 = np.array([1, 2, 3, 4, 5, 6, 7])
np_array3 = np.array([[1, 2, 3, 4], [ 4, 5, 6, 7]])

print("\n Zero dimensional array : n.ndim = ", n.ndim )

print(" np_array1.ndim = ", np_array1.ndim )
print(" np_array2.ndim = ", np_array2.ndim )
print(" np_array3.ndim = ", np_array3.ndim )

print("\n ------ 3. Create NumPy Array with zeros ------- \n ")
n_zeros = np.zeros([2, 3])
print("\n n_zeros (1d - 1x3) array = \n", np.zeros(3))
print("\n n_zeros (1d - 3x1) array = \n", np.zeros([3,1]))
print("\n n_zeros (1d - 3x1) array = \n", np.zeros((3,1)))
print("\n n_zeros (2d - 2x3) array = \n", n_zeros)

n_zeros_2 = np.zeros([4, 4])
print("\n n_zeros_2 (2d - 4x4) array = \n", n_zeros_2)

print("\n ------ 3.1 Create NumPy Array with ones ------- \n ")
print("\n ones (1d - 1x3) array = \n", np.ones(3))
print("\n ones (1d - 3x1) array = \n", np.ones((3,1)))
print("\n ones (1d - 3x1) array = \n", np.ones([3,1]))
print("\n ones (1d - 3x3) array = \n", np.ones([3,3]))


print("\n ------ 3.2 Create uninitialized NumPy Array ------- \n ")
print("\n Uninitialized (1d - 1x3) array = \n", np.empty(3))
print("\n Uninitialized (1d - 3x1) array = \n", np.empty((3,1)))
print("\n Uninitialized (1d - 3x1) array = \n", np.empty([3,1]))
print("\n Uninitialized (1d - 3x3) array = \n", np.empty([3,3]))

print("\n ------ 3.3 Create Identity Matrix in NumPy ------- \n ")
print("\n Identity (1d - 1x3) Matrix = \n", np.eye(3)  )
print("\n Identity (1d - 3x1) Matrix = \n", np.eye(3,1))
print("\n Identity (1d - 1x3) Matrix = \n", np.eye(1,3))

print("\n Identity (2d - 3x3,0 ) Matrix = \n", np.eye(3,3,0) )
print("\n Identity (2d - 3x3,1 ) Matrix = \n", np.eye(3,3,1) )
print("\n Identity (2d - 3x3,-1) Matrix = \n", np.eye(3,3,-1))

# Create an array with values from 0 to 10 with step 2
print("\n np.arange(0, 10, 2)  = ", np.arange(0, 10, 2) )  
print(np.arange(0, 23, 3))

# Create an array with 5 values evenly spaced between 0 and 1
print("\n np.linspace(0, 1, 5) = ", np.linspace(0, 1, 5))  
print(np.linspace(0, 1, 10))

# Create coordinate matrices
print("\n np.meshgrid(np.arange(3), np.arange(3)) = \n", np.meshgrid(np.arange(3), np.arange(3)) )



print("\n ------ 4. Data Types Supported by NumPy Array ------- \n ")
print(\'''
  Following Data Types are supported by NumPy Array
      b - boolean,
      u - unsigned integer,
      f - float,
      c - complex float,
      i - integer,
      o - object,
      S - string
      U - unicode string,
      m - timedelta
      M - datetime
      \''')

np_s1 = np.array(["a", "b", "c", "d", "e"])
np_s2 = np.array(["ab", "bc", "cd", "de", "ef"])
np_s3 = np.array(["abc", "bcd", "cde", "def", "efg"])

print(" np_s1.dtype - ", np_s1.dtype)       # U - means Unicode and 1 means max 1 characters input
print(" np_s2.dtype - ", np_s2.dtype)       # U - means Unicode and 2 means max 2 characters input
print(" np_s3.dtype - ", np_s3.dtype)       # U - means Unicode and 3 means max 3 characters input

np_array1 = np.array((1, 2, 3, 4, 5, 6, 7))

np_s4 = np.array(["abc", "bcd", "cde", "def", "efg"], dtype= 'S3')
print(" np_s4.dtype - ", np_s4.dtype)                 # S - means String and 3 means max 3 characters input

np_bool = np.array([True, False, True, False, True], dtype= 'b')
print(" np_bool.dtype - ", np_bool.dtype)             # S - means String and 3 means max 3 characters input

np_string = np_bool.astype('S')
print(" np_string.dtype - ", np_string.dtype)         # S - means String and 4 means max 4 characters input
print("\n np_string - ", np_string)

np_unicode = np_bool.astype('U')
print(" np_unicode.dtype - ", np_unicode.dtype)       # U - means Unicode String and 4 means max 4 characters input
print(" np_unicode - ", np_unicode)                 

np_unicode1 = np_array1.astype('U')
print("\n np_unicode1.dtype - ", np_unicode1.dtype)   # i - means Integer
print(" np_unicode1 - ", np_unicode1)

print("\n ------ 5. NumPy Array Indexing ------- \n ")
np_array1 = np.array((0, 1, 2, 3, 4, 5, 6, 7))
print(" np_array1         :- ", np_array1)
print(" np_array1[0]      :- ", np_array1[0])
print(" np_array1[-1]     :- ", np_array1[-1])
print(" np_array1[-2]     :- ", np_array1[-2])
print(" np_array1[-1:-5]  :- ", np_array1[-1:-5])
print(" np_array1[-5:-1]  :- ", np_array1[-5:-1])
print(" np_array1[::-1]   :- ", np_array1[::-1])
print(" np_array1[::2]    :- ", np_array1[::2])

print(np_array1.astype('bool'))
print(np_array1[::2])

print("\n -- Flip np_array1 elements in reverse order -- ")
flipped_arr = np.flip(np_array1)  

print(" flipped np_array1 - ", flipped_arr)
print(np.flip(np_array1))

np_2d = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])

print("\n np_2d - \n", np_2d)

print("\n np_2d[0, 0] - ", np_2d[0, 0])
print(" np_2d[0, 1] - ", np_2d[0, 1])
print(" np_2d[0, 2] - ", np_2d[0, 2])
print(" np_2d[0, 3] - ", np_2d[0, 3])

print(" np_2d[1, 0] - ", np_2d[1, 0])
print(" np_2d[1, 1] - ", np_2d[1, 1])
print(" np_2d[1, 2] - ", np_2d[1, 2])
print(" np_2d[1, 3] - ", np_2d[1, 3])


np_3d = np.array([[[1, 2, 3, 4], [5, 6, 7, 8]], [[1, 2, 3, 4], [5, 6, 7, 8]] ])

print("\n np_3d - \n", np_3d)

print(" np_3d[0, 0, 0] - ", np_3d[0, 0, 0])
print(" np_3d[0, 0, 1] - ", np_3d[0, 0, 1])
print(" np_3d[0, 0, 2] - ", np_3d[0, 0, 2])
print(" np_3d[0, 0, 3] - ", np_3d[0, 0, 3])
print(" np_3d[0, 0, -1] - ", np_3d[0, 0, -1])   # Accessing last element of the 1st row of 1st 2d array


print("\n ------ 6. Array Slicing ------- \n ")

np_2d = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
np_array1 = np.array((0, 1, 2, 3, 4, 5, 6, 7))

print("\n np_2d - \n", np_2d)
print("\n np_2d [0, 2:4] - \n", np_2d[0, 2:4])
print("\n np_2d [0:2, 2:4] - \n", np_2d[0:2, 2:4])
print("\n np_2d [1:, 2:] - \n", np_2d[1:, 2:])            # Print from index 1 to end and from index 2 to end
print("\n np_2d [:1, :2] - \n", np_2d[:1, :2])            # Print from beginning to index 1, and from beginning to index 2
print("\n np_array1[0:6:2] - \n", np_array1[0:6:2])       # print np_array1 with step size 2

print("\n np_2d [0:2, 0:4:2] - \n", np_2d[0:2, 0:4:2])

print("\n         ------ 6. NumPy Array Shape ------- \n ")
# In Python NumPy, the number of elements in each dimension of the array is called the shape.

np_2d = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
np_array1 = np.array((0, 1, 2, 3, 4, 5, 6, 7))
np_array2 = np.array([1, 2, 3, 4, 5, 6, 7])
np_array3 = np.array([[1, 2, 3, 4], [ 4, 5, 6, 7]])
np_3d = np.array([[[1, 2, 3, 4], [5, 6, 7, 8]], [[1, 2, 3, 4], [5, 6, 7, 8]] ])

print(" np_2d.shape - ", np_2d.shape)
print(" np_array1.shape - ", np_array1.shape)
print(" np_array2.shape - ", np_array2.shape)

np_zero = np.array((1))
print("\n --- Zero Dimension Array: --- ")
print(" np_zero.ndim - " , np_zero.ndim)
print(" np_zero.shape - ", np_zero.shape)

print("\n --- Two Dimension Array: --- ")
print(" np_array3.ndim - " , np_array3.ndim)
print(" np_array3.shape - ", np_array3.shape)

print("\n --- Three Dimension Array: --- ")
print(" np_3d.ndim - " , np_3d.ndim)
print(" np_3d.shape - ", np_3d.shape)

print("\n        ------ 7. NumPy Array ReShape ------- \n ")
print("\n --- Flattening 3d array - 'np_3d' to 1d array - 'np_1d' --- ")

np_3d = np.array([[[1, 2, 3, 4], [5, 6, 7, 8]], [[1, 2, 3, 4], [5, 6, 7, 8]] ])
np_1d = np_3d.reshape(16)
print("\n  np_1d = ", np_1d)

print("\n --- Converting 1d array - 'np_1d' to 2d array --- ")
np_reshaped_2d = np_1d.reshape(2, 8)
print("\n np_reshaped = \n", np_reshaped_2d)

np_reshaped_1d = np_reshaped_2d.reshape(-1)               # meaning 'NumPy' will determine the size automatically.
print("\n np_reshaped_1d = \n", np_reshaped_1d)

print("\n        ------ 8. Iterate NumPy Array ------- ")

np_array1 = np.array((0, 1, 2, 3, 4, 5, 6, 7))
np_array3 = np.array([[1, 2, 3, 4], [ 4, 5, 6, 7]])
np_3d = np.array([[[1, 2, 3, 4], [5, 6, 7, 8]], [[1, 2, 3, 4], [5, 6, 7, 8]] ])

print("\n --- Iterate 1d Array --- ")
for i in np_array1:
  print(i)

print("\n np_array1.size  = ", np_array1.size)
print(" np_array1.shape   = ", np_array1.shape)
print(" np_array1.ndim    = ", np_array1.ndim)

print("\n --- Iterate 2d Array --- ")
for i in np_array3:
  print(i)

print("\n --- Iterate 2d Array each element --- ")
for i in np_array3:
  for j in i:
    print(j, end=' ')
  print()

print("\n np_array3.size  = ", np_array3.size)
print(" np_array3.shape   = ", np_array3.shape)
print(" np_array3.ndim    = ", np_array3.ndim)

print("\n --- Iterate 3d Array --- ")
for i in np_3d:
  print(i)

print("\n --- Iterate 3d Array each element --- ")
for i in np_3d:
  for j in i:
    for k in j:
      print(k, end=' ')
    print()
  print("")

print(" np_3d.size  = ", np_3d.size)
print(" np_3d.shape = ", np_3d.shape)
print(" np_3d.ndim  = ", np_3d.ndim)

print("\n        ------ 9. Join NumPy Array ------- ")

n1 = np.array([1, 2, 3])
n2 = np.array([4, 5, 6])

print("\n -- Transpose n1 matrix -- ")
print("n1.T = ", n1.T)                              # Transpose operation does not have any effect on 1D array as there is no 
                                                    # second dimension  

n_concat = np.concatenate((n1, n2))
print("\n n_concat (1d) = \n", n_concat)

n1 = np.array([[1, 2], [3, 4]])
n2 = np.array([[5, 6], [7, 8]])

n_concat = np.concatenate((n1, n2), axis=0)
print("\n n_concat (2d) (axis 0 - column wise) = \n", n_concat)

n_concat = np.concatenate((n1, n2), axis=1 )
print("\n n_concat (2d) (axis 1 - row wise)    = \n", n_concat)

n_concat = np.concatenate((n1.T, n2.T))
print("\n n_concat (2d) Transposed = \n", n_concat)

print("\n             --- Stack method - 1d array ---")
n1 = np.array([1, 2, 3])
n2 = np.array([4, 5, 6])

print("\n n1 = ", n1)
print(" n2 = ", n2)
print("\n np.stack((n1, n2), axis=0) \n ", np.stack((n1, n2), axis=0))
print("\n np.stack((n1, n2), axis=1) \n ", np.stack((n1, n2), axis=1))

'''

print("\n             --- Stack method - 2d array ---")

n1 = np.array([[1, 2], [3, 4]])
n2 = np.array([[5, 6], [7, 8]])

print("\n n1 = \n", n1)
print("\n n1.shape = ", n1.shape)

print("\n n2 = \n", n2)
print("\n n2.shape = ", n2.shape)

np_stack_0 = np.stack((n1, n2), axis=0)
print("\n np.stack((n1, n2), axis=0) \n ", np_stack_0)
print("\n np_stack_0.shape = ", np_stack_0.shape)

np_stack_1 = np.stack((n1, n2), axis=1)
print("\n np.stack((n1, n2), axis=1) \n ", np_stack_1)
print("\n np_stack_1.shape = ", np_stack_1.shape)


'''
print("\n             --- hstack() method - 1d array ---")

n1 = np.array([1, 2, 3])
n2 = np.array([4, 5, 6])

print("\n n1 = ", n1)
print("\n n1.shape = ", n1.shape)
print("\n n2 = ", n2)
print("\n n2.shape = ", n2.shape)

np_hstack_1d = np.hstack((n1, n2))
print("\n np.hstack((n1, n2)) \n ", np_hstack_1d)
print("\n np_hstack_1d.shape = ", np_hstack_1d.shape)

print("\n             --- hstack() method - 2d array ---")

n1 = np.array([[1, 2], [3, 4]])
n2 = np.array([[5, 6], [7, 8]])

print("\n n1 = \n", n1)
print("\n n1.shape = ", n1.shape)
print("\n n2 = \n", n2)
print("\n n2.shape = ", n2.shape)

np_hstack_2d = np.hstack((n1, n2))
print("\n np.hstack((n1, n2)) \n ", np_hstack_2d)
print("\n np_hstack_2d.shape = ", np_hstack_2d.shape)

print("\n             --- vstack() method - 1d array ---")

n1 = np.array([1, 2, 3])
n2 = np.array([4, 5, 6])

print("\n n1 = ", n1)
print("\n n1.shape = ", n1.shape)

print("\n n2 = ", n2)
print("\n n2.shape = ", n2.shape)

np_vstack_1d = np.vstack((n1, n2))
print("\n np_vstack_1d  = \n ", np_vstack_1d )
print("\n np_vstack_1d.shape = ", np_vstack_1d.shape)

print("\n             --- vstack() method - 2d array ---")

n1 = np.array([[1, 2], [3, 4]])
n2 = np.array([[5, 6], [7, 8]])

print("\n n1 = \n", n1)
print("\n n1.shape = ", n1.shape)

print("\n n2 = \n", n2)
print("\n n2.shape = ", n2.shape)

np_vstack_2d = np.vstack((n1, n2))
print("\n np.vstack((n1, n2)) \n ", np_vstack_2d)
print("\n np_vstack_2d.shape = ", np_vstack_2d.shape)

print("\n             --- dstack() method - 1d array ---")

n1 = np.array([1, 2, 3])
n2 = np.array([4, 5, 6])

print("\n n1 = ", n1)
print("\n n1.shape = ", n1.shape)

print("\n n2 = ", n2)
print("\n n2.shape = ", n2.shape)

np_dstack_1d = np.dstack((n1, n2))
print("\n np_dstack_1d = \n ", np_dstack_1d )
print("\n np_dstack_1d.shape = ", np_dstack_1d.shape)

print("\n             --- dstack() method - 2d array ---")

n1 = np.array([[1, 2], [3, 4]])
n2 = np.array([[5, 6], [7, 8]])

print("\n n1 = \n", n1)
print("\n n1.shape = ", n1.shape)

print("\n n2 = \n", n2)
print("\n n2.shape = ", n2.shape)

np_dstack_2d = np.dstack((n1, n2))
print("\n np_dstack_2d = \n ", np_dstack_2d )
print("\n np_dstack_2d.shape = ", np_dstack_2d.shape)

print("\n             --- column_stack() method - 1d array ---")

n1 = np.array([1, 2, 3])
n2 = np.array([4, 5, 6])

print("\n n1 = ", n1)
print("\n n1.shape = ", n1.shape)

print("\n n2 = ", n2)
print("\n n2.shape = ", n2.shape)

np_dstack_1d = np.dstack((n1, n2))
print("\n np_dstack_1d = \n ", np_dstack_1d )
print("\n np_dstack_1d.shape = ", np_dstack_1d.shape)

print("\n             --- column_stack() method - 2d array ---")

n1 = np.array([[1, 2], [3, 4]])
n2 = np.array([[5, 6], [7, 8]])

print("\n n1 = \n", n1)
print("\n n1.shape = ", n1.shape)

print("\n n2 = \n", n2)
print("\n n2.shape = ", n2.shape)

np_col_stack_2d = np.column_stack((n1, n2))
print("\n np_dstack_2d = \n ", np_col_stack_2d )
print("\n np_dstack_2d.shape = ", np_col_stack_2d.shape)

'''