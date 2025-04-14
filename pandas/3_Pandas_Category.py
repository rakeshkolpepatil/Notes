''''
  The 'category' data type in Pandas is used for efficient storage and faster computations on categorical data, 
  such as labels or repeated values.
  1. You can convert a column or a Pandas Series into a categorical type.
  2. Pandas automatically identifies 3 unique categories: 'Blue', 'Green', and 'Red'.

  - Why use category for Gender?
  1. Takes less memory than object type.
  2. Faster grouping, sorting, and filtering.
  3. Ordered categories enable comparison 

  
'''
import pandas as pd  

print("\n  ------- 1. Creating a Series with Categorical Type -------- \n ")
colors = pd.Series(['Red', 'Green', 'Blue', 'Red', 'Blue'], dtype='category')
print(colors)
print("\n colors.dtype = ", colors.dtype)   # Pandas automatically identifies 3 unique categories: 'Blue', 'Green', and 'Red'.

print("\n -------- 2. Creating a DataFrame with Categorical Type Column -------- \n ")
data = {
  'Names'  : ["Rajesh", "Rakesh", "Ravina", "Riya", "Rushikesh"],
  'Gender' : pd.Categorical(['Male', 'Male', 'Female', 'Female', 'Male'], categories=['Male', 'Female'], ordered=True),
  'Age'    : [23, 45, 65,  34, 74],
  'City'   : ['Raigad', 'Pune', 'Raigad', 'Pune', 'Pune' ]
} 

df = pd.DataFrame(data)
print(df)
print("\n DataFrame dtypes :- \n", df.dtypes)


print("\n -------- 3. Ordered Categories -------- ")

sizes = pd.Categorical(['small', 'medium', 'large', 'xlarge', '2xlarge'], categories=['small', 'medium', 'large', 'xlarge', '2xlarge'],
                        ordered=True)
print("\n sizes = \n", sizes)
print("\n sizes isOrdered ? = ", sizes.ordered)


print("\n -------- 4. Changing Data Type of an Existing Column -------- ")
print("\n Data Type before update = ", df.dtypes)
df['City'] = df['City'].astype('category')
print("\n Data Type after update = ", df.dtypes)
print("n Please note that the data type of the 'City' column has been changed to category type.")


print("\n -------- 5. Checking & Manipulating Categories -------- ")
print("---- Get categories ----")
print("\n categories in colors Series : \n", colors.cat.categories)
print("\n categories in df DataFrame  : \n", df['Gender'].cat.categories)

print("\n---- Add categories ----\n")
colors = colors.cat.add_categories(["Yellow"])
print(" categories in colors Series : \n", colors.cat.categories)
df['Gender'] = df['Gender'].cat.add_categories("Other")
print("\n categories in df DataFrame  : \n", df['Gender'].cat.categories)

print("\n---- Remove categories ----\n")
colors = colors.cat.remove_categories(["Yellow"])
print(" categories in colors Series : \n", colors.cat.categories)
df['Gender'] = df['Gender'].cat.remove_categories("Other")
print("\n categories in df DataFrame  : \n", df['Gender'].cat.categories)

print("\n -------- 6. Sorting & Filtering Categorical Data -------- ")
print("\n In 'df' DataFrame, 'Gender' is a ordered Categorical data, so DataFrame can be sorted based on its values ")
print("\n DataFrame before Sorting : \n", df )
df = df.sort_values("Gender")
print("\n DataFrame after Sorting : \n", df )

print("\n -------- 7. Encoding Categories as Numeric Values -------- ")
print("\n ------ Getting numeric codes of categories -------- ")
print(df['Gender'].cat.codes)
df['Gender Codes'] = df['Gender'].cat.codes
print("\n Printing DataFrame with 'Gender' Codes \n", df)

print("\n Printing codes for colors Pandas Series ")
print(colors.cat.codes)