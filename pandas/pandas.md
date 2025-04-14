# Pandas 
- It is powerful open-source tool built in python, developed initially by Wes McKinney in 2008 and was joined Chang in 2012.
- Used for data analysis and manipulation In statistics, finance, Neuroscience, Economics, web analytics, advertising etc.
- Pandas work with data sets, cleanse them and makes them relevant for data science.
- Pandas can insert or delete columns from a data frame (i.e. table) or group them. 
- Pandas can read or load datasets in Excel, CSV, Jason, XML formats.
- Pandas is used to clean the wrong format data, remove duplicates, handle missing data in the form of NaN, NA, NaT and do other tasks.

## Installation 
1. Install Python, Pip and Numpy first and then install Pandas

    ```bash 
    pip install pandas                      # Installing pandas with pip.
    python -m pip install --upgrade pip     # First upgrade pip, if you encounter any issues while installing pandas using pip.
    pip install pandas==2.1.2               # Install specific version of pandas.
    conda install pandas=2.1.2              # Install specific version of pandas with conda installer.
    ```
2. Anaconda distribution already comes with Pandas pre-installed.
3. `Miniconda` is a minimal installer for conda, which includes only the conda package manager and Python.

## Pandas Data Structures

  | Data Structure  | Dimensions  | Description  | 
  | ----------------| ----------- | ------------ | 
  | Series          | 1           | A one-dimensional labeled homogeneous array, size immutable.|  
  | DataFrame       | 2           | A two-dimensional labeled, size-mutable tabular structure with potentially heterogeneously typed columns.|

- Note 
  
  ```
  Series    - Size immutable however values are mutable, homogeneous data. 
  DataFrame - Size mutable
  ```

## Series 
- one-dimensional labeled array that can hold any data type. 
- It can store integers, strings, floating-point numbers, etc. 
- Each value in a Series is associated with a label (index), which can be an integer or a string.
  
  ```python
  import pandas as pd

  data = ['Steve', '35', 'Male', '3.5']
  series = pd.Series(data, index=['Name', 'Age', 'Gender', 'Rating'])
  print(series)
  ```