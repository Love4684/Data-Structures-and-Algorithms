
.. contents::
   :local:
   :depth: 3


pointer
===============================================================================

pointers are variable that stores address of the other variables.

.. code:: c++

      int i = 3; 

      // A pointer to variable i (or stores
      // address of i)
      int *ptr = &i; 

      // A reference (or alias) for i.
      int &ref = i; 

.. code:: c++

      #include <iostream>
      using namespace std;
      int main() {
         int *ip;
         int arr[] = { 10, 34, 13, 76, 5, 46 };
         ip = arr;
         for (int x = 0; x < 6; x++) {
            cout << *ip << endl;
            ip++;
         }
         return 0;
      }
      
References
=======================================

A reference variable is an alias, that is, another name for an already existing variable.      

.. code:: c++

      int a=10;
      int &p=a;  //it is correct
         but
      int &p;
       p=a;    // it is incorrect as we should declare and initialize references at single step.
