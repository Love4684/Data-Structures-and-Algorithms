

.. contents::
   :local:
   :depth: 2

Python
============

Python is a general-purpose interpreted, interactive, object-oriented, and high-level programming language.

byte code.
============

Whenever the Python script compiles, it automatically generates a compiled code called as byte code.

Python Keywords
============

.. code:: python

      Python has a set of keywords that are reserved words that cannot be used as variable names, function names, or any other identifiers.
      In Python, keywords are case sensitive. There are 33 keywords in Python 3.7.
      
literals
============

.. code:: python

   literals is value which is given to a variable.

   String Literals

   Numeric Literals

   Boolean Literals

.. image:: https://github.com/Love4684/Data-Structures-and-Algorithms/blob/master/Python/media/py.png

Lists
===============================================================================

A list is a data structure in Python that is a mutable, or changeable, ordered
sequence of elements. Each element or value that is inside of a list is called
an item. Just as strings are defined as characters between quotes, lists are
defined by having values between square brackets [ ].

.. code:: python

    l s t . append ( [ " H ell o " , "World" ] )
    l s t . pop ( )

SETS
===============================================================================

A Set is an unordered collection data type that is iterable, mutable, and has
no duplicate elements. Python’s set class represents the mathematical notion
of a set.This is based on a data structure known as a hash table

.. code:: python


  set var = s e t ( )
  set var ={1 , 2 , 3 , 4 , 3}


Dictionaries
===============================================================================

A dictionary is a collection which is unordered, changeable and indexed. In
Python dictionaries are written with curly brackets, and they have keys and
values.

.. code:: python

   my_dict = {"fruits" : ("mango", "apple", "guava")} 
   
   my_dict
   {'fruits': ('mango', 'apple', 'guava')}
   
   my_dict.keys()
   dict_keys(['fruits'])
   
   my_dict.values()
   dict_values([('mango', 'apple', 'guava')])
   
   my_dict["fruits"]
   ('mango', 'apple', 'guava')
   
   tup = my_dict["fruits"]
   tup[0:2]
   ('mango', 'apple')
   
   dict = {"Car1 " : "Audi"  , "Car2 " : "BMW" , "Car3 " : " M e r ci di e s Benz "}
   for x in dict:
    print(x, dict[x])
    
   Car1  Audi
   Car2  BMW
   Car3   M e r ci di e s Benz 
   

Tuples
===============================================================================

Tuples are used to store multiple items in a single variable. A tuple is a
collection which is ordered and unchangeable.

.. code:: python

    my_tuple=tuple ( )
    my_tuple=(" Krish " , "Ankur" , " John " )

datetime   
===============================================================================
.. code:: python 

   from datetime import date
   my_date = date(1996, 12, 11)
   today = date.today()
   print("Date components", today.year, today.month, today.day)

Iterators and Generators  
===============================================================================


To create a Python iterator object, you will need to implement two methods in your iterator class.

__iter__: This returns the iterator object itself and is used while using the "for" and "in" keywords.

__next__: This returns the next value. This would return the StopIteration error once all the objects have been looped through.

Iterator uses iter() and next() functions

Every iterator is not a generator

.. code:: python

      iter_list = iter(['Geeks', 'For', 'Geeks'])
      print(next(iter_list))
      print(next(iter_list))
      print(next(iter_list))

output

.. code:: python

   Geeks
   For
   Geeks  

Generator functions are ordinary functions defined using yield instead of return. When called, a generator function returns a generator object
  
Generator uses yield keyword

Every generator is an iterator

.. code:: python

      def sq_numbers(n):
          for i in range(1, n+1):
              yield i*i


      a = sq_numbers(3)
  
      print("The square of numbers 1,2,3 are : ")
      print(next(a))
      print(next(a))
      print(next(a))

output

.. code:: python

      The square of numbers 1,2,3 are :  
      1
      4
      9

class
============

.. code:: python

      class human:
          name = None
          def get_name(self):
              print("enter the name")
              self.name = input()
          def put_name(self):
              print(self.name)

      h1 = human()
      h1.get_name()
      h1.put_name()
      print(h1.name)
      
output

.. code:: python

      enter the name
      ram
      ram
      ram
      
Pass
........

.. code:: python
     
   In Python, the pass keyword is used to execute nothing;     

Self
.........

The self keyword is used in the method to refer to the instance of the current class we are using.

.. code:: python

      class Employee:
          def printdetails(self):
              return f"The Name is {self.name}. Salary is {self.salary} and role is {self.role}"

      harry = Employee()
      harry.name = "Harry"
      harry.salary = 455
      harry.role = "Instructor"
      print(harry.printdetails())
      
output

.. code:: python

      The Name is Harry. Salary is 455 and role is Instructor

__init__() (Constructors)
.............................

Constructor in Python is used to assign values to the variables or data members of a class when an object is created.

.. code:: python

      class Employee:
          def __init__(self, aname, asalary, arole):
              self.name = aname
              self.salary = asalary
              self.role = arole

      harry = Employee("HARRY", 5000, "Instructor")
      print(harry.salary)
      
output

.. code:: python

      5000

Inheritance
..................

When one object acquires all the properties and behaviours of parent object i.e. known as inheritance. It provides code reusability.

It is used to achieve runtime polymorphism.

.. code:: python

      class Person(object):
          def __init__(self, name):
              self.name = name
          def getName(self):
              return self.name
          def isEmployee(self):
              return False

      class Employee(Person):
          def isEmployee(self):
              return True

      emp = Person("Geek1")
      print(emp.getName(), emp.isEmployee())

      emp = Employee("Geek2")
      print(emp.getName(), emp.isEmployee())
      
output

.. code:: python

      Geek1 False
      Geek2 True 

map():
============

A map function executes certain instructions or functionality provided to it on every item of an iterable.

.. code:: python

      syntax

      map(function, iterable) 

      Ex

      items = [1, 2, 3, 4, 5]
      a=list(map((lambda x: x **3), items))
      print(a)
      #Output: [1, 8, 27, 64, 125]
      
filter():
============

A filter function in Python tests a specific user-defined condition for a function and returns an iterable for the elements and values that satisfy the condition or, in other words, return true.

.. code:: python

      syntax

      filter(function, iterable)

      Ex

      a = [1,2,3,4,5,6]
      b = [2,5,0,7,3]
      c= list(filter(lambda x: x in a, b))
      print(c) # prints out [2, 5, 3]
      
reduce():
============

Reduce functions apply a function to every item of an iterable and gives back a single value as a resultant

.. code:: python

      syntax

      reduce(function, iterable)

      Ex

      from functools import reduce
      a=reduce( (lambda x, y: x * y), [1, 2, 3, 4] )
      print(a) 
      #Output: 24  
      
Dunder or magic methods
=======================

Dunder or magic methods in Python are the methods having two prefix and suffix underscores in the method name.



Pandas
===============================================================================

Pandas is a Python library. Pandas is used to analyze data.

.. code:: python

      Is there a correlation between two or more columns?
      What is average value?
      Max value?
      Min value?

Series
.........

A Pandas Series is like a column in a table. It is a one-dimensional array holding data of any type.

DataFrames
...........

A Pandas DataFrame is a 2 dimensional data structure, like a 2 dimensional array, or a table with rows and columns.

.. code:: python 

      import pandas as pd
      dt1 = {"Fruit_name" : ["mango", "apple", "guava"], "count" : [6, 4, 8]}
      pd.DataFrame(dt1)

      output

          Fruit_name	 count
      0	  mango	            6
      1	  apple    	    4
      2	  guava	            8

Pandas Read CSV
.................

.. code:: python 

      import pandas as pd
      df = pd.read_csv('data.csv')
      print(df.to_string()) 

      #use to_string() to print the entire DataFrame.
      
Pandas Read JSON 
................

.. code:: python 

      import pandas as pd
      df = pd.read_json('data.json')
      print(df.to_string()) 

      #JSON = Python Dictionary JSON objects have the same format as Python dictionaries.

Viewing the Data
...............

.. code:: python 

      import pandas as pd
      df = pd.read_csv('data.csv')
      print(df.head())
      
Info About the Data
...............

.. code:: python 

      print(df.info()) 
      
Cleaning Data
===============================================================================

Data cleaning means fixing bad data in our data set. Bad data could be:

Cleaning Empty cells
.............

.. code:: python 

      1. Remove all rows with NULL values:

      import pandas as pd
      df = pd.read_csv('data.csv')
      df.dropna(inplace = True)
      print(df.to_string())

      2. Replace Empty Values

      df.fillna(130, inplace = True)

Cleaning Data of Wrong Format
.............................

Cells with data of wrong format can make it difficult, or even impossible, to analyze data.
To fix it, you have two options: remove the rows, or convert all cells in the columns into the same format.

Wrong data
....................

"Wrong data" does not have to be "empty cells" or "wrong format", it can just be wrong, like if someone registered "199" instead of "1.99".

Duplicates
............

.. code:: python 

   df.drop_duplicates(inplace = True)
Data Correlations   
..........
The corr() method calculates the relationship between each column in your data set.

.. code:: python 

   df.corr()

Pandas - Plotting
...............

.. code:: python 

   import pandas as pd
   import matplotlib.pyplot as plt
   df = pd.read_csv('data.csv')
   df["Duration"].plot(kind = 'hist')
   plt.show()
   

Numpy
===============================================================================

NumPy is a Python library used for working with arrays.It provides a high-performance multidimensional array object, and tools for working with these arrays.
  
.. code:: python

      import numpy as np
      mt = np.array([[1, 2, 3, 4], [3, 4, 5, 6], [1, 2, 3, 4], [3, 4, 5, 6]])
      mt_mul = np.dot(mt, mt)
      mt_dia = np.diagonal(mt)
      
      a = np.zeros((4, 4))
      
      output
      
      array([[0., 0., 0., 0.],
       [0., 0., 0., 0.],
       [0., 0., 0., 0.],
       [0., 0., 0., 0.]])
       
.. code:: python

      import numpy as np
      lst1=[1,2,3]
      lst2=[2,3,4]
      a = np.sum((lst1, lst2), axis = 0)
      b = np.sum((lst1, lst2), axis = 1)
      print(a, b))
      
      output
      
      [3 5 7] [6 9]
      
     
Multiplication of two Matrices
===============================================================================

.. code:: python

      matrix1 = [[12,7,3], [4 ,5,6],[7 ,8,9]]
      matrix2 = [[5,8,1], [6,7,3], [4,5,9]]


      ans = np.zeros((3, 3))

      for i in range(3):
          for j in range(3):
              for k in range(3):
                  ans[i][j] += matrix1[i][k] * matrix2[k][j]

      print (ans)

      
      output
      
      [[114. 160.  60.]
      [ 74.  97.  73.]
      [119. 157. 112.]]
  

      
Remove Duplicates from a List
===============================================================================

.. code:: python

      def Remove(duplicate):
          final_list = []
          for num in duplicate:
              if num not in final_list:
                  final_list.append(num)
          return final_list

      duplicate = [2, 4, 10, 20, 5, 2, 20, 4]
      print(Remove(duplicate))

.. code:: python

      duplicate = [2, 4, 10, 20, 5, 2, 20, 4]
      print(list(set(duplicate)))


length of a string without using len()
=====================

.. code:: python

      a = "jhnfbdljfgf"
      count = 0
      for i in a:
          count=count + 1
      print(count)    

Replace odd number with -1
=====================

.. code:: python

      import numpy as np
      arr = np.arange(0,10)
      arr[arr%2 == 1] = -1
      arr

      otput

      array([ 0, -1,  2, -1,  4, -1,  6, -1,  8, -1])
      
Common value of two array
=====================

.. code:: python

      a = np.array([ 0, -1,  2, -1,  4, -1,  6, -1,  8, -1])
      b = np.array([ 5, 78,  2, 89,  4, 56,  6, -1,  8, -1])
      np.intersect1d(a, b)

      output

      array([-1,  2,  4,  6,  8])
      
      
Training And Testing Available Data
=====================

.. code:: python      

      import pandas as pd
      import numpy as np
      from sklearn import linear_model
      import matplotlib.pyplot as plt

      from sklearn.model_selection import train_test_split
      X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.3)

      from sklearn.linear_model import LinearRegression
      clf = LinearRegression()
      clf.fit(X_train, y_train)

      clf.predict(X_test)

      y_test

      clf.score(X_test, y_test)


