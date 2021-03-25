
.. contents::
   :local:
   :depth: 2
   
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

cpp code

Recursive implementation of Binary Search

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

Merge Sort
===============================================================================

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
===============================================================================

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


C++ What is OOP?
===============================================================================

The oops concept focuses on writing the reusable code. oops is about creating objects that contain both data and functions.

Class
------------

It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A class is like a blueprint for an object.

.. code:: c++

      class MyClass {       // The class
        public:             // Access specifier
          int myNum;        // Attribute (int variable)
          string myString;  // Attribute (string variable)
      };

Object
------------

Any entity that has state and behavior is known as an object. For example: chair, pen, table, keyboard, bike etc. 

Object
------------

.. code:: c++


      class MyClass {       // The class
        public:             // Access specifier
          int myNum;        // Attribute (int variable)
          string myString;  // Attribute (string variable)
      };

      int main() {
        MyClass myObj;  // Create an object of MyClass

        // Access attributes and set values
        myObj.myNum = 15; 
        myObj.myString = "Some text";

        // Print attribute values
        cout << myObj.myNum << "\n";
        cout << myObj.myString;
        return 0;
      }

Class Methods
------------

Methods are functions that belongs to the class.

Inside Example

.. code:: c++

      class MyClass {        // The class
        public:              // Access specifier
          void myMethod() {  // Method/function defined inside the class
            cout << "Hello World!";
          }
      };

      int main() {
        MyClass myObj;     // Create an object of MyClass
        myObj.myMethod();  // Call the method
        return 0;
      }

Outside Example

.. code:: c++

      class MyClass {        // The class
        public:              // Access specifier
          void myMethod();   // Method/function declaration
      };

      // Method/function definition outside the class
      void MyClass::myMethod() {
        cout << "Hello World!";
      }

      int main() {
        MyClass myObj;     // Create an object of MyClass
        myObj.myMethod();  // Call the method
        return 0;
      }
  
  
C++ Constructors
------------

A constructor in C++ is a special method that is automatically called when an object of a class is created. To create a constructor, use the same name as the class, followed by parentheses ():

The constructor has the same name as the class, it is always public, and it does not have any return value.

.. code:: c++

      class Car {        // The class
        public:          // Access specifier
          string brand;  // Attribute
          string model;  // Attribute
          int year;      // Attribute
          Car(string x, string y, int z) { // Constructor with parameters
            brand = x;
            model = y;
            year = z;
          }
      };

      int main() {
        // Create Car objects and call the constructor with different values
        Car carObj1("BMW", "X5", 1999);
        Car carObj2("Ford", "Mustang", 1969);

        // Print values
        cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
        cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
        return 0;
      }

C++ Access Specifiers
------------

In C++, there are three access specifiers:

public - members are accessible from outside the class
private - members cannot be accessed (or viewed) from outside the class
protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

C++ Encapsulation
------------

Binding (or wrapping) code and data together into a single unit is known as encapsulation. For example: capsule, it is wrapped with different medicines.

The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users. To achieve this, you must declare class variables/attributes as private (cannot be accessed from outside the class). If you want others to read or modify the value of a private member, you can provide public get and set methods.

It is considered good practice to declare your class attributes as private (as often as you can). Encapsulation ensures better control of your data, because you (or others) can change one part of the code without affecting other parts
Increased security of data

.. code:: c++

      #include <iostream>
      using namespace std;

      class Employee {
        private:
          // Private attribute
          int salary;

        public:
          // Setter
          void setSalary(int s) {
            salary = s;
          }
          // Getter
          int getSalary() {
            return salary;
          }
      };

      int main() {
        Employee myObj;
        myObj.setSalary(50000);
        cout << myObj.getSalary();
        return 0;
      }

The salary attribute is private, which have restricted access.

The public setSalary() method takes a parameter (s) and assigns it to the salary attribute (salary = s).

The public getSalary() method returns the value of the private salary attribute.

Inside main(), we create an object of the Employee class. Now we can use the setSalary() method to set the value of the private attribute to 50000. Then we call the getSalary() method on the object to return the value.

Abstraction
------------

Hiding internal details and showing functionality is known as abstraction. For example: phone call, we don't know the internal processing.

In C++, we use abstract class and interface to achieve abstraction.

C++ Inheritance
------------

When one object acquires all the properties and behaviours of parent object i.e. known as inheritance. It provides code reusability.

In C++, it is possible to inherit attributes and methods from one class to another. We group the "inheritance concept" into two categories:

derived class (child) - the class that inherits from another class
base class (parent) - the class being inherited from
To inherit from a class, use the : symbol.

In the example below, the Car class (child) inherits the attributes and methods from the Vehicle class (parent):

.. code:: c++

      // Base class
      class Vehicle {
        public:
          string brand = "Ford";
          void honk() {
            cout << "Tuut, tuut! \n" ;
          }
      };

      // Derived class
      class Car: public Vehicle {
        public:
          string model = "Mustang";
      };

      int main() {
        Car myCar;
        myCar.honk();
        cout << myCar.brand + " " + myCar.model;
        return 0;
      }
      
Why And When To Use "Inheritance"?

- It is useful for code reusability: reuse attributes and methods of an existing class when you create a new class.

C++ Polymorphism
------------

When one task is performed by different ways i.e. known as polymorphism. For example: to convince the customer differently, to draw something e.g. shape or rectangle etc.

In C++, we use Function overloading and Function overriding to achieve polymorphism.

For example, think of a base class called Animal that has a method called animalSound(). Derived classes of Animals could be Pigs, Cats, Dogs, Birds - And they also have their own implementation of an animal sound (the pig oinks, and the cat meows, etc.):

Example

.. code:: c++

      // Base class
      class Animal {
        public:
          void animalSound() {
          cout << "The animal makes a sound \n" ;
        }
      };

      // Derived class
      class Pig : public Animal {
        public:
          void animalSound() {
          cout << "The pig says: wee wee \n" ;
        }
      };

      // Derived class
      class Dog : public Animal {
        public:
          void animalSound() {
          cout << "The dog says: bow wow \n" ;
        }
      };
      
Now we can create Pig and Dog objects and override the animalSound() method:

.. code:: c++

      // Base class
      class Animal {
        public:
          void animalSound() {
          cout << "The animal makes a sound \n" ;
        }
      };

      // Derived class
      class Pig : public Animal {
        public:
          void animalSound() {
          cout << "The pig says: wee wee \n" ;
         }
      };

      // Derived class
      class Dog : public Animal {
        public:
          void animalSound() {
          cout << "The dog says: bow wow \n" ;
        }
      };

      int main() {
        Animal myAnimal;
        Pig myPig;
        Dog myDog;

        myAnimal.animalSound();
        myPig.animalSound();
        myDog.animalSound();
        return 0;
      }
      
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
