import pandas as pd 
import numpy as np

print("\n--------------------------------- Pandas Series -------------------------------")

# Creating a sample Series from a list of data
data = ["Raj", 23, 'Male', 89]
series = pd.Series(data)

data = [10, 20, 30, 40, 50, np.nan, 70, 80, 90, 100]
s = pd.Series(data)

data3 = ["Apple", "Ball", "Cat", "Dog", "Egg", "Fruit"]
custom_labels_s = pd.Series(data3, index=["A", "B", "C", "D", "E", "F"])

'''
print(" --- The data Series contains --- ")
print("\n series := \n", series)

print("\n --- The another data Series contains --- ")
# Creating a sample Series
print("\n s := \n ", s)

print("\n Data Series with custom labels : ")
print(custom_labels_s)

# --- 1. Basic Information ---
print("\n ------------------- 1. Basic Information ----------------------- ")

# Returns the data type of the elements in the Series. 
# If the Series contains mixed types (numbers and strings), it will return object.
print("\n 🌎 Data Type:", s.dtype)

# Returns the dimensionality of pandas Series. Always returns 1 as pandas Series is one dimensional.
print("\n 🌎 Series Dimensions:", s.ndim)

# Returns a tuple representing the dimensions of the Series. (numRows, numCols)
print("\n 🌎 Shape:", s.shape)                    

# Returns the total number of elements in the Series, including missing (NaN) values.
print("\n 🌎 Size:", s.size)                      

# Returns True if the Series has zero elements, otherwise False.
print("\n 🌎 Is Empty:", s.empty)                 

# Check for NaN values, Returns True if there are any missing (NaN) values in the Series, otherwise False.
# Helps identify if the Series needs handling for missing data
print("\n 🌎 Contains NaN:", s.hasnans)           
                                            
# Returns index labels of series.
print("\n 🌎 type(s.index):\n", type(s.index))
print("\n 🌎 Series Index :\n", s.index)

# Gives name to Series 
s.name = "MySeries"
print("\n 🌎 Series Name:", s.name)  
print("\n 🌎 Memory Usage:", s.memory_usage())  

print("\n 🌎 Basic info of the series : \n")
s.info()

# --- 2. Accessing & Indexing ---
print("\n -------------------- 2. Accessing & Indexing -------------------- ")
# Accessing first element
print("\n 🌎 Series : \n", s)

print("\n 🌎 First element:", s[0])               

# Access by position
print("\n 🌎 Element at index 2:", s.iloc[2])     

# Access by label
print("\n 🌎 Element at label '3':", s.loc[3])     

print("\n 🌎 Element at label 'A':", custom_labels_s.loc['A'])     

print("\n 🌎 Element at label 'B':", custom_labels_s.loc['B'])     

# First 3 elements, by default shows first 5 rows
print("\n 🌎 First 3 rows:\n", s.head(3))         

# Last 3 elements, by default shows last 5 rows
print("\n 🌎 Last 3 rows:\n", s.tail(3))     

# Print lines from index 0 till 3rd line.
print("\n 🌎 Print Lines from index 0 till 3 :\n", s.loc[0:3])          

# Print lines for index 0, 2 and 3.
print("\n 🌎 Print Lines for index 0, 2 and 3 :\n", s.loc[[0, 2, 3]])          


# --- 3. Aggregation & Descriptive Statistics ---
print("\n -------------------- 3. Aggregation & Descriptive Statistics -------------------- ")
print("\n 🌎 The s = \n", s)

print("\n 🌎 Sum:", s.sum())                      # Sum of all values, ignore NANs
print("\n 🌎 Mean:", s.mean())                    # Mean (ignores NaN), i.e. average of all values
print("\n 🌎 Median:", s.median())                # Median is middle value in sorted order
print("\n 🌎 Standard Deviation:", s.std())       # Standard deviation sqrt(sum((val-mean)^2)/N-1)
print("\n 🌎 Variance:", s.var())                 # Variance, which is square of standard deviation
print("\n 🌎 Min:", s.min())                      # Minimum value
print("\n 🌎 Max:", s.max())                      # Maximum value

# count, mean, std, 25%(median of first half), 50%(median of whole), 75%(median of second half), max
print("\n 🌎 Describe:\n", s.describe())          # Summary statistics

# --- 5. Handling Missing Values ---
print("\n -------------------- 4. Handling Missing Values -------------------- ")

# This function returns 'True' where values are 'NaN' and False where values are valid.
print("\n 🌎 Is NaN:\n", s.isna())                  # Boolean mask for NaN values
print("\n 🌎 Not NaN:\n", s.notna())                # Boolean mask for non-NaN values
print("\n 🌎 Drop NaN:\n", s.dropna())              # Remove NaN values

# Replace missing values with mean, median, or custom values
print("\n 🌎 Fill NaN with 0:\n", s.fillna(0))      # Replace NaN with a value

# Estimates missing values based on other values using linear interpolation.
print("\n 🌎 Interpolate NaN:\n", s.interpolate())  # Fill NaN values using interpolation



# --- 5. Combine Series ---
print("\n --------------------- 5. Combine Series ---------------------- ")

def MyComp1(x1, x2):
  if(x1 > x2):
    return x1
  else:
    return x2

def MyComp2(x1, x2):
  return x1, x2

s1 = pd.Series([1, 2, 3, 4, 5])
s2 = pd.Series([6, 7, 8, 9, 10])

s_result = s1.combine(s2, MyComp1)
print(s_result)

s_add = s1.add(s2)
print("\n s_add :- \n ", s_add)

print("\n ------ Arithmetic Operations --------")
print("\n 🌎 Addition (s1 + s2)         : \n", s1 + s2  )     # Add
print("\n 🌎 Subtraction (s1 - s2)      : \n", s1 - s2  )     # Subtract
print("\n 🌎 Multiplication (s1 * s2)   : \n", s1 * s2  )     # Multiply
print("\n 🌎 Division (s1 / s2)         : \n", s1 / s2  )     # Divide
print("\n 🌎 Floor Division (s1 // s2)  : \n", s1 // s2 )     # Floor Divide
print("\n 🌎 Modulus (s1 % s2)          : \n", s1 % s2  )     # Modulus
print("\n 🌎 Exponentiation (s1 ** s2)  : \n", s1 ** s2 )     # Power

print("\n ------ Comparison Operations --------")
print("\n 🌎 Greater than (s1 > s2)           :\n", s1 > s2)  
print("\n 🌎 Less than (s1 < s2)              :\n", s1 < s2)  
print("\n 🌎 Equal (s1 == s2)                 :\n", s1 == s2)  
print("\n 🌎 Not Equal (s1 != s2)             :\n", s1 != s2)  
print("\n 🌎 Greater than or equal (s1 >= s2) :\n", s1 >= s2)  
print("\n 🌎 Less than or equal (s1 <= s2)    :\n", s1 <= s2)  

s1_bool = pd.Series([True, False, True, False])
s2_bool = pd.Series([False, True, True, False])

print("\n ------ Logical Operations --------")
print("\n 🌎 Logical AND (s1 & s2)    :\n", s1_bool & s2_bool)  
print("\n 🌎 Logical OR (s1 | s2)     :\n", s1_bool | s2_bool)  
print("\n 🌎 Logical XOR (s1 ^ s2)    :\n", s1_bool ^ s2_bool)  
print("\n 🌎 Logical NOT (~s1)        :\n", ~s1_bool)  

print("\n ------ Combining and Merging --------")
print("\n 🌎 Concatenation      :\n", pd.concat([s1, s2]))    # Concatenating one series to another.
print("\n 🌎 Combine using max  :\n", s1.combine(s2, max))    # Element-wise max  
print("\n 🌎 Combine using min  :\n", s1.combine(s2, min))    # Element-wise min  
print("\n 🌎 Merge (Outer Join) :\n", s1.combine_first(s2))   # Fill NaN with values from s2  

print("\n ------ Adding Values to Series --------")
s1 = pd.Series([1, 2, 3, 4, 5])
print(s1)

new_s = pd.concat([s1, pd.Series([6, 7])], ignore_index=True)
print(new_s)

print("\n Appending at the end of the list ")
new_s[len(new_s)] = 8
print(new_s)

print("\n Appending at the end of the list ")
new_s.at[len(new_s)] = 9
print(new_s)

print("\n Appending at the end of the list ")
new_s.loc[len(new_s)] = 10
print(new_s)

# --- 6. Data Manipulation ---
print("\n --------------------- 6. Data Manipulation ---------------------- ")
print("\n 🌎 Multiply by 2:\n", s.apply(lambda x: x * 2))   # Apply function
print("\n 🌎 Add 1 to each element :\n", s.apply(lambda x: x + 1))   # Apply function
print("\n 🌎 Add 5:\n", s.map(lambda x: x + 5))             # Similar to apply
print("\n 🌎 Replace values:\n", s.replace({10: 100, 50: 500}))  
print("\n 🌎 Add 10:\n", s.add(10))                         # Add 10 to each element
print("\n 🌎 Subtract 5:\n", s.sub(5))                      # Subtract 5 from each element
print("\n 🌎 Multiply by 2:\n", s.mul(2))                   # Multiply each element by 2
print("\n 🌎 Divide by 2:\n", s.div(2))                     # Divide each element by 2
print("\n 🌎 Square each element:\n", s.pow(2))             # Square each element


# --- 7. Sorting & Ranking ---
print("\n -------------------- 7. Sorting & Ranking -------------------- ")
print("\n 🌎 Sort values:\n", s.sort_values())          # Ascending order
print("\n 🌎 Sort Descending:\n", s.sort_values(ascending=False))

# Assigns a rank to each value based on its position in ascending order.
# Handles duplicate values by assigning the average rank.
print("\n 🌎 Rank:\n", s.rank())                        # Rank of each value

# --- 8. Index Manipulation ---
print("\n -------------------- 8. Index Manipulation -------------------- ")
print("\n 🌎 Reset Index:\n",   s.reset_index(drop=True))  

# axis=0 for row labels, 1 for column labels (axis=1 not applicable for Series)
print("\n 🌎 Change Index:\n",  s.set_axis( range(3, len(s)+3), axis=0))  

# --- 9. String Operations (For String-Based Series) ---
print("\n -------------------- 9. String Operations (For String-Based Series) -------------------- ")
s_str = pd.Series(["apple", "banana", "cherry", "date"])
print("\n 🌎 s_str: \n", s_str)
print("\n 🌎 Uppercase:\n", s_str.str.upper())           # Converts all characters to uppercase	
print("\n 🌎 Lowercase:\n", s_str.str.lower())           # Converts all characters to lowercase	
print("\n 🌎 Title Case:\n", s_str.str.title())          # Converts first letter of each word to uppercase   

# checks if string contains 'a', returns boolean map
print("\n 🌎 Contains 'a':\n", s_str.str.contains("a"))   

# Replaces all occurrences of 'a' with '@'
print("\n 🌎 Replace 'a' with '@':\n", s_str.str.replace("a", "@"))

# Returns length of each string
print("\n 🌎 String Lengths:\n", s_str.str.len())

# split by space
print("\n 🌎 Split Strings:\n", s_str.str.split())  

# --- 10. Unique & Duplicate Values ---
print("\n -------------------- 10. Unique & Duplicate Values -------------------- ")
print("\n 🌎 Unique Values:\n", s.unique())           # Returns List of Unique values
print("\n 🌎 Number of Unique Values:", s.nunique())  # count number of unique values
print("\n 🌎 Duplicate Mask:\n", s.duplicated())      # Boolean mask of duplicates
print("\n 🌎 Remove Duplicates:\n", s.drop_duplicates())  # Remove duplicates keeping first occurrence

# --- 11. Value Counts & Grouping ---
print("\n --------------------  11. Value Counts & Grouping -------------------- ")

# counts the occurrences of each unique value in the Series and return series in descending order.
print("\n 🌎 Value Counts:\n", s.value_counts())       

# group the values in Series by result of 's % 2' and return sum of each series.
print("\n 🌎 Group by Even/Odd and Sum:\n", s.groupby(s % 2).sum())  

# --- 12. Rolling & Expanding Operations ---
print("\n -------------------- 12. Rolling & Expanding Operations -------------------- ")
# Creates a sliding window of size 3, moves over the Series, and computes the mean (average) 
# of the values inside that window.
print("\n 🌎 Rolling Mean (Window=3):\n", s.rolling(window=3).mean())  

# Unlike rolling(), which uses a fixed window, expanding() gradually includes more data
# as it moves forward.
print("\n 🌎 Expanding Sum:\n", s.expanding().sum())  

'''
# --- 13. Conversion ---
print("\n -------------------- 13. Conversion  -------------------- ")

# Converts all values in the Series to integers. If conversion fails, keep original values 
# instead of throwing an error.
print("\n 🌎 Convert to Integer:\n", s.astype(int, errors="ignore"))  

# convert Series to Python List
print("\n 🌎 Convert to List:\n", s.to_list())     

# convert Series to Python Dictionary
print("\n 🌎 Convert to Dictionary:\n", s.to_dict())  

# convert Series to Python DataFrame
print("\n 🌎 Convert to DataFrame:\n", s.to_frame())  

'''
'''