

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

    di c ={}
    my_dict={"Car1 " : "Audi"  , "Car2 " : "BMW" , "Car3 " : " M e r ci di e s Benz "}
    for x in my_dict :
    print ( x )
    Car1
    Car2
    Car3

Tuples
===============================================================================

Tuples are used to store multiple items in a single variable. A tuple is a
collection which is ordered and unchangeable.

.. code:: python

    my_tuple=tuple ( )
    my_tuple=(" Krish " , "Ankur" , " John " )
    
    
Numpy
===============================================================================

NumPy is a Python library used for working with arrays.It provides a high-performance multidimensional array object, and tools for working with these arrays.
  
.. code:: python

      import numpy as np
      my_lst1=[1,2,3,4,5]
      my_lst2=[2,3,4,5,6]
      my_lst3=[9,7,6,8,9]
      arr=np.array([my_lst1,my_lst2,my_lst3])
      print(arr)
  
output

.. code:: python

      array([[1, 2, 3, 4, 5],
             [2, 3, 4, 5, 6],
             [9, 7, 6, 8, 9]])
    
