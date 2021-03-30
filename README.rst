
.. contents::
   :local:
   :depth: 3
   
Array in C++
===============================================================================

An Array is a data structure used to store blocks of information in contiguous
memory allocation. The data can be integer, strings, characters, class objects, etc.

Finding Max and Min element
------------

cpp code


.. code:: c++


      using namespace std;
      #include <bits/stdc++.h>

            int main()
            {
               int arr[5] = {4, 7, 6, 3, 9};
               int maxno = INT_MIN;
               int minno = INT_MAX;
               for(int i = 0; i < 5; i++)
               {
                  maxno = max(maxno, arr[i]);
                  minno = min(minno, arr[i]);

               }

               cout<<"min = "<< minno << endl << "max = "<< maxno;
               return 0;
            }

using STL

.. code:: c++

      using namespace std;
      #include <bits/stdc++.h>

      int main()
      {
         int arr[5] = {4, 7, 6, 3, 9};
         int maxno = *max_element(arr, arr + 5);
         int minno = *min_element(arr, arr + 5);

         cout<<"min = "<< minno << endl << "max = "<< maxno;
         return 0;
      }

using python

.. code:: python

      arr = [4, 7, 6, 3, 9]
      min(arr)
      max(arr)

Searching Algorithms
===============================================================================

Linear Search O(n)
------------

cpp code

.. code:: c++

      using namespace std;
      #include <bits/stdc++.h>

            int LinearSearch(int arr[], int size, int key)
            {
               for(int i = 0; i < size; i++)
               {
                  if(arr[i]==key)
                     return i;
               }
               return -1;
            }

            int main()
            {
               int arr[5] = {4, 7, 6, 3, 9};
               int key = 6;
               int index = LinearSearch(arr, 5, key);
               (index == -1) ? cout<< "key not found" :cout << "key present at index = " << index;
               return 0;
            }

using python

.. code:: python

      def LinearSearch(arr, size, key):
        for i in range(size):
          if arr[i] == key:
            return i
        return -1

      arr = [4, 7, 6, 3, 9]
      index = LinearSearch(arr, len(arr), 6)
      if index == -1:
        print ("key not found")
      else :
        print("key found at index = ", index)

Binary Search O(log n)
------------

T(n) = T(n/2) + c 

cpp code

Recursive implementation of Binary Search , it's work on sorted array

.. code:: c++

      using namespace std;
      #include <bits/stdc++.h>

            int BinarySearch(int arr[], int l, int r, int key)
            {
               if(r >= l)
               {
                  int mid = (r + l)/2;
                  if(arr[mid] == key)
                     return mid;
                  if(arr[mid] > key)
                     return BinarySearch(arr, l, mid-1, key);

                  if(arr[mid] < key)
                     return BinarySearch(arr, mid + 1, r, key);
               }
               return -1;
            }

            int main()
            {
               int arr[5] = {3, 4, 6, 7, 9};
               int key = 9;
               int index = BinarySearch(arr, 0, 4, key);
               (index == -1) ? cout<< "key not found" :cout << "key present at index = " << index;
               return 0;
            }

Iterative implementation of Binary Search

.. code:: cpp


      #include <bits/stdc++.h>
      using namespace std;
      int binarySearch(int arr[], int l, int r, int x)
      {
         while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
               return m;
            if (arr[m] < x)
               l = m + 1;
            else
               r = m - 1;
         }
         return -1;
      }

      int main(void)
      {
         int arr[5] = { 2, 3, 4, 10, 40 };
         int x = 10;
         int result = binarySearch(arr, 0, n - 1, x);
         (result == -1) ? cout << "not present"
                  : cout << "present at index " << result;
         return 0;
      }


Sorting sorting algorithms
===============================================================================


Merge Sort (O(n log n))
------------

Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
cpp code

.. code:: cpp

      #include <iostream>
      using namespace std;

      void merge(int arr[], int l, int mid, int r )
      {
          int n1 = mid - l + 1;
          int n2 = r - mid;
          int a[n1], b[n2];
          for(int i = 0; i < n1; i++) 
              a[i] = arr[l + i];
          for(int i = 0; i < n2; i++) 
              b[i] = arr[mid + i + 1];

          int i = 0;
          int j = 0;
          int k = l;
          while(i < n1 && j < n2)
          {
              if(a[i] <= b[j])
               {
                   arr[k] = a[i];
                      i++;
               }
              else
              {
                  arr[k] = b[j]; 
                  j++;
              }
              k++;
          } 
          while(i < n1)
          {
              arr[k] = a[i]; 
              i++ ; 
              k++;
          }
          while(j < n2)
          {
              arr[k] = b[j]; 
              j++; 
              i++;
          }
      }

      void mergesort(int arr[], int l, int r)
      {
          if(l >= r) 
          {
              return;
          }

              int mid = (l + r)/2;
              mergesort(arr, l, mid);
              mergesort(arr, mid + 1, r);
              merge(arr, l, mid, r);

      }
      int main()
      {
         int arr[5] = {9, 7, 5, 4, 3} ;
         mergesort(arr, 0, 4);
         for(int i = 0; i < 5; i++) 
          cout << arr[i] << " ";
      cout<<endl;
          return 0;
      }

QuickSort
------------
Worst-case (n²)

Average performance	O(n log n)

Best-case performance	O(n log n) 

QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 

cpp code

.. code:: cpp

    using namespace std;
    #include <bits/stdc++.h>
    int partition(int arr[], int l, int r)
    {
      int i=l-1;
      int pivot = arr[r];
      for(int j = l; j < r; j++)
      {
        if(arr[j] < pivot )
        {
          i++;
        swap(arr[i], arr[j]);
        }	

      }
      swap(arr[i+1], arr[r]);
      return i+1;
    }
    void quicksort(int arr[], int l, int r)
    {
      if(l < r)
      {
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
      }
    }
    int main(){
      int arr[5] = {4, 5, 3, 7, 8};
      quicksort(arr, 0, 4);
      for(int i = 0; i < 5; i++)
      {
        cout << arr[i] << " ";
      }
      return 0;
    }
    
python code

.. code:: python

      def partition(arr, l, r):
        i = l-1;
        pivot = arr[r]
        for j in range (l, r):
          if arr[j] < pivot :
            i = i + 1
            arr[i] , arr[j] = arr[j] , arr[i]
        arr[i+1], arr[r] = arr[r], arr[i+1]
        return i+1

      def Quicksort(arr, l, r):
        if l >= r :
          return
        if l < r :
          pi = partition(arr, l, r)
          Quicksort(arr, l, pi-1)
          Quicksort(arr, pi+1, r)

      arr = [9, 5, 6, 7, 3, 8, 2]
      n = len(arr)
      Quicksort(arr, 0, n-1)
      print(arr)



Bit Manipulation Algorithms
===============================================================================


Binary Number System
------------

.. image:: http://www.sciweavers.org/download/Tex2Img_1616342073.jpg


cpp code


.. code:: c++


C++ OOPs Concepts
===============================================================================


oops is about creating objects that contain both data and functions.

Object
------------

Any entity that has state and behavior is known as an object. For example: chair, pen, table, keyboard, bike etc. It can be physical and logical.

Class
------------

A class is like a blueprint for an object. It is a user-defined data type, which holds its own data members and member functions.

Inheritance
------------

When one object acquires all the properties and behaviours of parent object i.e. known as inheritance. It provides code reusability. It is used to achieve runtime polymorphism.

Polymorphism
------------

When one task is performed by different ways i.e. known as polymorphism. For example: to convince the customer differently, to draw something e.g. shape or rectangle etc.

In C++, we use Function overloading and Function overriding to achieve polymorphism.

Abstraction
------------

Hiding internal details and showing functionality is known as abstraction. For example: phone call, we don't know the internal processing.

In C++, we use abstract class and interface to achieve abstraction.

Encapsulation
------------

Binding code and data together into a single unit is known as encapsulation. For example: capsule, it is wrapped with different medicines.

Advantage of OOPs
------------

OOPs makes development and maintenance easier.

OOPs provide data hiding whereas in Procedure-oriented programming language a global data can be accessed from anywhere.

Why we need OOPs in Programming language?
------------

1. Duplicate code is a Bad.

2. Code will always be changed.

So, above statement proves, OOPs is provides code reusability which reduce the duplication of code because once you have duplicate code, you have make changes everywhere which leads to performance. Code can be changed anytime or requirement of application changed anytime so when you want to make changes in your application, OOPs makes it easier.

Structure vs class in C++
------------

1) Members of a class are private by default and members of a struct are public by default.

2) Both can have constructors, methods, properties, fields, constants, enumerations, events, and event handlers. 

struct for plain-old-data structures without any class-like features;

class when you make use of features such as private or protected members, non-default constructors and operators, etc.

.. code:: c++

    class Test {
        int x; // x is private
    };
    int main()
    {
      Test t;
      t.x = 20; // compiler error because x is private
      getchar();
      return 0;
    }
    
.. code:: c++
    
    #include <stdio.h>

    struct Test {
        int x; // x is public
    };
    int main()
    {
      Test t;
      t.x = 20; // works fine because x is public
      getchar();
      return 0;
    }

C++ Access Specifiers
------------

In C++, there are three access specifiers:

public - members are accessible from outside the class

private - members cannot be accessed (or viewed) from outside the class

protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

Types of Class Member Functions in C++
------------
Member functions are the functions, which have their declaration inside the class definition. The definition of member functions can be inside or outside the definition of class.

.. code:: c++

      class Cube
      {
          public:
          int side;
          int getVolume();
      };

      // member function defined outside class definition using the scope resolution ::
      int Cube :: getVolume()
      {
          return side*side*side;
      }

      int main()
      {
          Cube C1;
          C1.side = 4;    // setting side value
          cout<< "Volume of cube C1 = "<< C1.getVolume();
      }
      
      
1) Simple functions:
...................

These are the basic member function, which doesn’t have any special keyword like static etc as a prefix.

.. code:: c++

      return_type functionName(parameter_list)
      {
      function body;
      }
      
2) Static functions:
....................

Static is a keyword which can be used with data members as well as the member functions. These functions work for the class as whole rather than for a particular object of a class.

It can be called using the object and the direct member access . operator. But, its more typical to call a static member function by itself, using class name and scope resolution :: operator.

.. code:: c++

      class X
      {
       public:
       static void f(){};
      };

      int main()
      {
       X::f();   // calling member function directly with class name
      }
      
3) Const functions: 
...................

A function becomes const when const keyword is used in function’s declaration. The idea of const functions is not to allow them to modify the object on which they are called.

.. code:: c++

      #include<iostream>
      using namespace std;

      class Test {
          int value;
      public:
          Test(int v = 0) {value = v;}

          // We get compiler error if we add a line like "value = 100;"
          // in this function.
          int getValue() const {return value;}  
      };
      
4) Inline functions: 
....................

C++ provides inline functions to reduce the function call overhead. An inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call. This substitution is performed by the C++ compiler at compile time. Inline function may increase efficiency if it is small.

Some Important points about Inline Functions

We must keep inline functions small, small inline functions have better efficiency.

Inline functions do increase efficiency, but we should not make all the functions inline. Because if we make large functions inline, it may lead to code bloat, and might affect the speed too.

Hence, it is adviced to define large functions outside the class definition using scope resolution :: operator, because if we define such functions inside class definition, then they become inline automatically.

Inline functions are kept in the Symbol Table by the compiler, and all the call for such functions is taken care at compile time.

.. code:: c++

      #include <iostream>
      using namespace std;
      inline int cube(int s)
      {
         return s*s*s;
      }
      int main()
      {
         cout << "The cube of 3 is: " << cube(3) << "\n";
         return 0;
      } //Output: The cube of 3 is: 27
      
5) Friend function: 
....................

If a function is defined as a friend function in C++, then the protected and private data of a class can be accessed using the function. 
For accessing the data, the declaration of a friend function should be done inside the body of a class starting with the keyword friend.
A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class.

.. code:: c++

      #include <iostream>    
      using namespace std;    
      class Box    
      {    
          private:    
              int length;    
          public:    
              Box(): length(0) { }    
              friend int printLength(Box); //friend function    
      };    
      int printLength(Box b)    
      {    
         b.length += 10;    
          return b.length;    
      }    
      int main()    
      {    
          Box b;    
          cout<<"Length of box: "<< printLength(b)<<endl;    
          return 0;    
      }    

C++ Friend class
................

A friend class can access both private and protected members of the class in which it has been declared as friend.

.. code:: c++

      #include <iostream>  

      using namespace std;  

      class A  
      {  
          int x =5;  
          friend class B;           // friend class.  
      };  
      class B  
      {  
        public:  
          void display(A &a)  
          {  
              cout<<"value of x is : "<<a.x;  
          }  
      };  
      int main()  
      {  
          A a;  
          B b;  
          b.display(a);  
          return 0;  
      }  
      
When we make a class as friend, all its member functions automatically become friend functions.

Friend Functions is a reason, why C++ is not called as a pure Object Oriented language. Because it violates the concept of Encapsulation.

      
C++ Exceptions
--------------

.. code:: c++

      #include <iostream>
      using namespace std;

      int main() {
        try {
          int age = 15;
          if (age >= 18) {
            cout << "Access granted - you are old enough.";
          } else {
            throw (age);
          }
        }
        catch (int myNum) {
          cout << "Access denied - You must be at least 18 years old.\n";
          cout << "Age is: " << myNum;  
        }
        return 0;
      }

output

Access denied - You must be at least 18 years old.
Age is: 15
