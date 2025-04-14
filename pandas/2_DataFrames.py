import pandas as pd
import numpy as np

# Sample DataFrame
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
    'Age': [25, 30, 35, 40, np.nan],
    'Gender': ['F', 'M', 'M', 'M', 'F'],
    'Score': [85, 90, 95, 80, 70]
}

df = pd.DataFrame(data)

'''
### 🔹 0. Creating DataFrame ###
print("\n-------------------- 0. Creating DataFrames --------------------")
print('\n DataFrame with default indices as row names - \n ')
print(df)

# Giving custom names to each row of the DataFrame while creating it.
print('\n DataFrame with custom indices as row names - \n ')
df_with_custom_row_names = pd.DataFrame(data, index=['RollNo 1', 'RollNo 2', 'RollNo 3', 'RollNo 4', 'RollNo 5'])
print(df_with_custom_row_names)

# Changing column names of existing DataFrame.
print('\n Change the column names of a DataFrame - \n ')
df_with_custom_column_names =  df.copy()                                 # Make a copy of the original DataFrame
df_with_custom_column_names.columns = ['Full Name', 'Years Old', 'Sex', 'Marks']
print(df_with_custom_column_names)

data_list_2d = [
    ["Alice", 25, "F", 85],
    ["Bob", 28, "M", 90],
    ["Charlie", 30, "M", 88],
    ["Dave", 32, "M", 78],
    ["Eve", 27, "F", 95]
]

# Please note the difference between the data arrangement when the DataFrame is created from Dictionary Vs 2 dimensional list.
print('\n Creating Pandas DataFrame from Python 2D List - \n ')
df_from_list = pd.DataFrame(data_list_2d, index=['Student 1', 'Student 2', 'Student 3', 'Student 4', 'Student 5'], columns=['Name', 'Age', 'Gender', 'Marks'])
print(df_from_list)

### 🔹 1. Basic Information ###
print("\n-------------------- 1. Basic Information --------------------")
# summary of dataframes shows index type, column names and their types and NaNs, memory usage.   
print("\n 🌎 df.info():")
df.info()

# Returns a tuple (rows, columns) representing the dimensions of the DataFrame
print("\n 🌎 df.shape:", df.shape)

# Returns the total number of elements (cells) in the DataFrame. (rows * columns)
print("\n 🌎 df.size:", df.size)

# Returns an index object containing the column names of the DataFrame.
print("\n 🌎 df.columns:", df.columns)

# Returns the index labels (row labels) of the DataFrame.
print("\n 🌎 df.index:", df.index)

# Returns the data type (dtype) of each column in the DataFrame.
print("\n 🌎 df.dtypes:\n", df.dtypes)

print("\n 🌎 Number of Dimensions in DataFrame df.ndim : ", df.ndim)
print("\n 🌎 df['Name'].dtypes : ", df['Name'].dtypes)
print("\n 🌎 df['Age'].dtypes  : ", df['Age'].dtypes)


### 🔹 2. Viewing Data ###
print("\n-------------------- 2. Viewing Data --------------------")

# Returns the first n rows of the DataFrame defaults to 5.
print("\n 🌎 df.head(3) : \n\n", df.head(3))

# Returns the last n rows of the DataFrame defaults to 5.
print("--------------------------")
print("\n 🌎 df.tail(2) : \n\n", df.tail(2))

# Returns a random sample of n rows from the DataFrame.
print("--------------------------")
print("\n 🌎 df.sample(3) : \n\n", df.sample(3))

# Print Transpose of a DataFrame 
print("--------------------------")
print("\n 🌎 Transpose of the DataFrame :\n\n", df.T)


### 🔹 3. Accessing Data ###
print("\n-------------------- 3. Accessing Data -------------------- ")

# Extracts the entire column named 'Age' as Pandas Series
print("\n ------- Accessing a column as Pandas Series ------- \n")
print("\n 🌎 df['Age'] as Series :\n", df['Age'])

# Extracts the entire column named 'Age' as Pandas DataFrame
print("\n ------- Accessing a column as Pandas DataFrame ------- \n")
print("\n 🌎 df[['Age']] as DataFrame :\n", df[['Age']])

# Extracts multiple columns as new DataFrame
print("\n ------- Accessing multiple columns using column labels as Pandas DataFrame ------- \n")
print("\n 🌎 df[['Name', 'Score']]:\n", df[['Name', 'Score']])

print("\n -------- Accessing multiple columns using range of indices -------- \n") 
print(df[df.columns[0:3]])

# Returns the row where index = 0, uses label-based indexing
print("\n -------- Accessing rows with index -------- \n") 
print("\n 🌎 df.loc[0]:\n", df.loc[0])

print("\n -------- Fetches the 3rd row (0-based index, 2) -------- \n")
print(" 🌎 df.iloc[2]:\n", df.iloc[2])

print("\n -------- Fetches 0th, 1st rows based on index -------- \n")
print(" 🌎 df.iloc[0:2]:\n", df.iloc[0:2])

print("\n -------- Accessing 0th and 2nd rows -------- \n")
print(" 🌎 df.iloc[[0,2]]:\n", df.iloc[[0,2]])

# Retrieves the value at row index 1 and column 'Name'
print("\n 🌎 df.loc[1, 'Name']:\n", df.loc[1, 'Name'])

print("\n -------- Displaying columns in DataFrame ---------")
for col in df:
  print(col)

print("\n -------- Printing contents of each column in DataFrame ---------")
for col in df:
  print(df[col])
  print("  -------------  ")

'''

print("\n-------------------- 3.1. Adding Column to DataFrame --------------------")
print("\n -------- Adding column to the DataFrame Insert Method ---------")
print("\n Original DataFrame :- \n ") 
print(df)

df.insert(2, 'city', ['Uri', 'Chandigad', 'Kanchi', 'Trichi', 'Bhopal'])
print("\n Updated DataFrame :- \n ") 
print(df)

# Assign method will add column to the end of the DataFrame 
print("\n -------- Adding column to the DataFrame Assign Method ---------")
df = df.assign(Roll_Number = [101, 102, 103, 104, 105])
print("\n Updated DataFrame :- \n ") 
print(df)

'''
print("\n-------------------- 3.2. Deleting Column from DataFrame --------------------")
df = df.drop('Roll_Number', axis = 'columns')
print("\n DataFrame after deleting column 'Roll_Number' :- \n ") 
print(df)

print("\n DataFrame after deleting column 'city' :- \n ") 
df = df.drop('city', axis = 1)
print(df)

print("\n-------------------- 3.2. Deleting Rows from DataFrame --------------------")
print("\n DataFrame after deleting Row 4 :- \n ") 
df = df.drop(4, axis = 'index')
print(df)

print("\n DataFrame after deleting Row 3 :- \n ") 
df = df.drop(3, axis = 0)
print(df)

print("\n-------------------- 3.3. Iterate Over Rows --------------------")
print("\n                 ---- iterrows() ---- \n")
for row in df.iterrows():
  print(row)
  print(" ------ \n")

print("\n                 ---- itertuples() ---- \n")
for row in df.itertuples():
  print(row)
  print(" ------ \n")

print("\n-------------------- 3.4. Iterate Over Columns --------------------")
print("\n                 ---- items() ---- \n")
for ColName, ColContent in df.items():
  print(ColName)
  print(" ---")
  print( ColContent )

### 🔹 4. Filtering Data ###
print("\n-------------------- 4. Filtering Data --------------------")

# Returns filtered DataFrame, all rows where the column Score > 80.
print("\n 🌎 df[df['Score'] > 80]:\n", df[df['Score'] > 80])

# Multiple conditions - Extracts rows where both conditions are true: Age > 25, Gender is Male ('M')
print("\n 🌎 df[(df['Age'] > 25) & (df['Gender'] == 'M')]:\n", df[(df['Age'] > 25) & (df['Gender'] == 'M')])

### 🔹 5. Missing Values Handling ###
print("\n-------------------- 5. Missing Values Handling --------------------")
# Returns a Boolean DataFrame indicating True where values are NaN
print("\n 🌎 df.isna():\n", df.isna())

# Similar to df.isna(), but returns 'True' where values are not missing (present).
print("\n 🌎 df.notna():\n", df.notna())

# Replace all NaN values with 0, inplace=True parameter modifies the original DataFrame.
df.fillna(0, inplace=True)
print("\n 🌎 df after df.fillna(0):\n", df)

# Removes all rows that contain at least one NaN value, 'inplace=True' updates the original dataframe.
df.dropna(inplace=True)
print("\n 🌎 df after df.dropna():\n", df)

### 🔹 6. Sorting & Ranking ###
print("\n-------------------- 6. Sorting & Ranking --------------------")

# Sorts the entire DataFrame based on the "Score" column in ascending order default (ascending = True) 
print("\n 🌎 df.sort_values(by='Score'):\n", df.sort_values(by='Score'))

# Sort by Score (desc), then Age (asc)
print("\n 🌎 df.sort_values(by='Age', ascending=False):\n", df.sort_values(by='Age', ascending=False))

# Assigns a rank to each value in numerical columns.
# Smallest value gets rank 1, and the largest gets the highest rank.
# If multiple values are the same, they get the average rank.
print("\n 🌎 df.rank():\n", df.rank())


### 🔹 7. Unique & Duplicates ###
print("\n-------------------- 7. Unique & Duplicate Values --------------------")
# Returns a NumPy array of unique values from the "Gender" column.
print("\n 🌎 df['Gender'].unique():\n", df['Gender'].unique())

# Returns the number of unique values in the "Gender" column. Useful for counting categories in a dataset.
print("\n 🌎 df['Gender'].nunique():", df['Gender'].nunique())

# Returns a boolean Series, marking duplicate rows as True. Helps identify exact duplicate rows.
print("\n 🌎 df.duplicated():\n", df.duplicated())

# Removes duplicate rows from the DataFrame. 'inplace=True' modifies the DataFrame directly.
df.drop_duplicates(inplace=True)
print("\n 🌎 df after df.drop_duplicates():\n", df)

### 🔹 8. Aggregation & Statistics ###
print("\n-------------------- 8. Aggregation & Statistics --------------------")
# count, mean, std, 25%(median of first half), 50%(median of whole), 75%(median of second half), max
print("\n 🌎 df.describe():\n", df.describe())

# Computes the mean (average) for each numeric column. 
# 'numeric_only=True' ensures non-numeric columns are ignored.
print("\n 🌎 df.mean():\n", df.mean(numeric_only=True))

# Computes the median (middle value when sorted) for numeric columns. Less sensitive to outliers than the mean.
print("\n 🌎 df.median():\n", df.median(numeric_only=True))

# Computes the variance of numeric columns. Variance measures the spread of data (higher variance = more spread).
print("\n 🌎 df.var():\n", df.var(numeric_only=True))

# Computes the sum of each column. For numeric columns, it adds the values. 
# For string columns, it concatenates values.
print("\n 🌎 df.sum():\n", df.sum())

### 🔹 9. Grouping & Pivoting ###
print("\n-------------------- 9. Grouping & Pivoting --------------------")

# Groups the DataFrame based on the 'Gender' column. Calculates the mean of the 'Score' column for each gender.
# The result is a grouped Series.
print("\n 🌎 df.groupby('Gender')['Score'].mean():\n", df.groupby('Gender')['Score'].mean())

# Groupby 'Gender' and then take 'Mean' of all numeric columns
print("\n 🌎 df.groupby('Gender').mean(numeric_only=True) \n")
print(df.groupby('Gender').mean(numeric_only=True)) 

# Groupby multiple columns ('Gender' and 'Age') and then take 'Sum' of the 'Score' column.
print("\n 🌎 df.groupby(['Gender', 'Age'])['Score'].sum(): \n")
print(df.groupby(['Gender', 'Age'])['Score'].sum())  # Multi-level grouping

# Creates a pivot table that organizes and aggregates data.
# Groups by 'Gender' (rows) and calculates the mean of the 'Score' column.
# Equivalent to groupby but more flexible (supports multiple aggregations and multi-indexing).
print("\n 🌎 df.pivot_table(values='Score', index='Gender', aggfunc=np.mean):\n", df.pivot_table(values='Score', index='Gender', aggfunc=np.mean))

### 🔹 10. String Operations ###
print("\n-------------------- 10. String Operations --------------------")

# Converts all letters in the 'Name' column to uppercase.
df['Name'] = df['Name'].str.upper()
print("\n 🌎 df after df['Name'].str.upper():\n", df)

# Replaces all occurrences of 'A' with '@' in the Name column.
df['Name'] = df['Name'].str.replace('A', '@', regex=False)

# Returns a Boolean Series indicating if each name contains the letter 'A'.
print("\n 🌎 df after df['Name'].str.replace('A', '@'):\n", df)
print("\n 🌎 df['Name'].str.contains('A'):\n", df['Name'].str.contains('A'))

### 🔹 11. Apply & Lambda ###
print("\n-------------------- 11. Apply & Lambda --------------------")
# The 'apply()' function applies the specified function to each element in the 'Age' column.
# and adds an additional column 'Age_Squared' to the DataFrame.
df['Age_Squared'] = df['Age'].apply(lambda x: x**2)
print("\n 🌎 df after df['Age_Squared']:\n", df)

# The map() function applies a given function to each element of the Series, modifying each value.
df['Score'] = df['Score'].map(lambda x: x + 5)
print("\n 🌎 df after df['Score'].map(lambda x: x + 5):\n", df)

### 🔹 12. Merging & Joining ###
print("\n-------------------- 12. Merging & Joining [Join appends columns] --------------------")
# A second DataFrame 'df2' is created with Name and Salary columns.
# Merge df with df2 on 'Name', on='Name': The merge is based on the 'Name' column.
# how='left': This performs a LEFT JOIN, meaning: All rows from df are kept, If there is a matching Name in df2, 
# the Salary column is added. If there is no match, 'NaN' is inserted.

df2 = pd.DataFrame({'Name': ['Alice', 'Bob'], 'Salary': [50000, 60000]})
df_merge = df.merge(df2, on='Name', how='left')
print("\n 🌎 df.merge(df2, on='Name'):\n ", df_merge)

df3 = pd.DataFrame({'City': ['Pune', 'Delhi', 'New York', 'London', 'Los Angeles']})
print("\n 🌎 df3 : \n ", df3)

# Join appends columns form one DataFrame to the columns of another.
df4 = df.join(df3)
print("\n 🌎 The join of df2 and df3 is : \n", df4)

### 🔹 13. Concatenation ###
print("\n-------------------- 13. Concatenation [appends rows] --------------------")
# Creates a new DataFrame 'df3' with two new rows (Frank and Grace). Concatenate df and df3
# pd.concat([df, df3]): Merges df and df3 by stacking rows on top of each other.
# ignore_index=True: Resets the index to ensure sequential numbering.

df3 = pd.DataFrame({'Name': ['Frank', 'Grace'], 'Age': [28, 32], 'Gender': ['M', 'F'], 'Score': [75, 85]})
df_concat = pd.concat([df, df3], ignore_index=True)
print("\n 🌎 df after concatenation:\n", df_concat)

# If you want to add columns instead of rows.
# df_col_concat = pd.concat([df, df3], axis=1)

### 🔹 14. Reset & Set Index ###
print("\n-------------------- 14. Reset & Set Index --------------------")
# Resets the index to sequential integers (0, 1, 2, ...).
# drop=True: Drops the old index instead of adding it as a new column.
# Returns a new DataFrame (does not modify 'df' in place unless inplace=True is used).

df_reset = df.reset_index(drop=True)
print("\n 🌎 df.reset_index():\n", df_reset)

### 🔹 15. Export & Import ###
print("\n-------------------- 15. Export & Import --------------------")
# Saves the DataFrame 'df' as a CSV file named "data.csv".
# index=False: Prevents writing the index column in the file.
# If index=True, the index will be included in the CSV.
print("\n ----- Exporting to CSV file -----")
df.to_csv("data.csv", index=False)
print("\n 🌎 DataFrame exported to 'data.csv'")

print("\n ----- Importing from CSV file -----")
# Indexing a column values at the time of import will allow us to access the rows 
# directly through the column values. Pandas allows duplicate values inside index columns.
df_csv = pd.read_csv("data.csv", index_col='Name')
print("\n new_df - \n", df_csv )

print("\n ---- Alice Details ----")
print(df_csv.loc['Alice'])

print("\n ----- Exporting to Excel file -----")
df.to_excel("data.xlsx", index=False)
print("\n 🌎 DataFrame exported to 'data.xlsx'")

print("\n ----- Importing to Excel file -----")
df_excel = pd.read_excel("data.xlsx")
print("\n df_excel - \n", df_excel)

### 🔹 16. Working with Dates ###
print("\n-------------------- 16. Working with Dates --------------------")

# pd.to_datetime([...])
# Converts the given list of date strings into Pandas datetime objects.
# This enables advanced date operations like extracting years, months, weekdays, etc.
# The converted dates are stored in the 'Date' column of the DataFrame.
# df['Date'].dt.day - Extracts the day (1-31) from the datetime column.

df['Date'] = pd.to_datetime(['2024-03-20', '2024-03-21', '2024-03-22', '2024-03-23', '2024-03-24'])
print("\n 🌎 df with Dates:\n", df)
print("\n 🌎 df['Date'].dt.day:\n", df['Date'].dt.day)


### 🔹 17. Rolling & Expanding Operations ###
print("\n-------------------- 17. Rolling & Expanding Operations --------------------")
# rolling(window=2).mean() :-
#   Creates a moving window of size 2 and computes the mean for that window.
#   The first value is 'NaN' because there is no previous value to compute a rolling average.
#
# expanding().sum() :-
#   Computes a cumulative sum from the start of the series to the current value.
#   Unlike rolling, the window starts from index 0 and keeps expanding as it progresses.

print("\n 🌎 df['Score'].rolling(window=2).mean():\n", df['Score'].rolling(window=2).mean())
print("\n 🌎 df['Score'].expanding().sum():\n", df['Score'].expanding().sum())

'''