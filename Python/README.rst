

.. contents::
   :local:
   :depth: 2
   
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
      1	  apple    	   4
      2	  guava	            8
 
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
     
Pass
============

.. code:: python
     
   In Python, the pass keyword is used to execute nothing;      
      

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

Self
============

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
============

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
============

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
      
