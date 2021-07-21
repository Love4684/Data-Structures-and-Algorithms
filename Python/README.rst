

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
      
      
