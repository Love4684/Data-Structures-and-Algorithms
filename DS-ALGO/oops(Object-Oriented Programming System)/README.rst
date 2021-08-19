
.. contents::
   :local:
   :depth: 3
  
C++ OOPs Concepts
===============================================================================


Object-Oriented Programming is a methodology or paradigm to design a
program using classes and objects. It simplifies the software development
and maintenance by providing some concepts defined below :

Object
------------
Object is a run-time entity. It is an instance of the class. An object can
represent a person, place or any other item. An object can operate on
both data members and member functions.

Class
------------

A class is like a blueprint for an object. It is a user-defined data type, which holds its own data members and member functions.
For
example, Human being is a class. The body parts of a human being are its
properties, and the actions performed by the body parts are known as
functions. The class does not occupy any memory space till the time an
object is instantiated.

Constructors
------------

A constructor in C++ is a special method that is automatically called when an object of a class is created.

Copy Constructor
------------

A copy constructor is a member function that initializes an object using another object of the same class.

.. code:: c++

      #include <iostream>  
      using namespace std;  
      class A  
      {  
         public:  
          int x;  
          A(int a)                // parameterized constructor.  
          {  
            x=a;  
          }  
          A(A &i)               // copy constructor  
          {  
              x = i.x;  
          }  
      };  
      int main()  
      {  
        A a1(20);               // Calling the parameterized constructor.  
       A a2(a1);                //  Calling the copy constructor.  
       cout<<a2.x;  
        return 0;  
      }  
      #outpu 20
      
      


Four pillars of OOP
===============================================================================

1. Inheritance
------------

When one object acquires all the properties and behaviours of parent object i.e. known as inheritance. It provides code reusability. It is used to achieve runtime polymorphism.

2. Polymorphism
------------

When one task is performed by different ways i.e. known as polymorphism. For example: to convince the customer differently, to draw something e.g. shape or rectangle etc.

In C++, we use Function overloading and Function overriding to achieve polymorphism.

.. code:: c++

      #include<iostream>
      using namespace std;

      int main(){
          // Polymorphism
          //  - one name and multiple forms
          //  - eg. Function overloading, operator overloading
          //  - eg. Virtual Functions
          /*
          Polymorphism in C++ can be of two types:
          1. Compile time polymorphism -> Static Polymorphism implies that the call to a function is resolved at compile time.
             Compile time polymorphism in C++ is acheived using:
              1.1 - Function overloading
              1.2 - Operator Overloading
          2. Run time polymorphism -> Runtime polymorphism is also known as dynamic polymorphism or late binding.
             Run time polymorphism in C++ is acheived using:
              2.1 - Virtual functions

              */
          return 0;
      }
      
Function overloading
....................

Function overloading is a feature of object oriented programming where two or more functions can have the same name but different parameters.
 
.. code:: c++

      #include<iostream>
      using namespace std;

      int sum(float a, int b){
          cout<<"Using function with 2 arguments"<<endl;
          return a+b;
      }

      int sum(int a, int b, int c){
          cout<<"Using function with 3 arguments"<<endl;
          return a+b+c;
      }

      // Calculate the volume of a cylinder
      int volume(double r, int h){
          return(3.14 * r *r *h);
      }

      // Calculate the volume of a cube
      int volume(int a){
          return (a * a * a);
      }

      // Rectangular box
      int volume (int l, int b, int h){
          return (l*b*h);
      }

      int main(){
          cout<<"The sum of 3 and 6 is "<<sum(3,6)<<endl;
          cout<<"The sum of 3, 7 and 6 is "<<sum(3, 7, 6)<<endl;
          cout<<"The volume of cuboid of 3, 7 and 6 is "<<volume(3, 7, 6)<<endl;
          cout<<"The volume of cylinder of radius 3 and height 6 is "<<volume(3, 6)<<endl;
          cout<<"The volume of cube of side 3 is "<<volume(3)<<endl;
          return 0;
      }

Operator Overloading
....................

In C++, we can make operators to work for user defined classes. This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading.

Following is the list of operators that cannot be overloaded.

.. code:: c++

   . (dot) 
   :: 
   ?: 
   sizeof 

.. code:: c++

      #include<iostream>
      using namespace std;

      class Complex {
      private:
         int real, imag;
      public:
         Complex(int r = 0, int i =0) {real = r; imag = i;}

         // This is automatically called when '+' is used with
         // between two Complex objects
         Complex operator + (Complex const &obj) {
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
         }
         void print() { cout << real << " + i" << imag << endl; }
      };

      int main()
      {
         Complex c1(10, 5), c2(2, 4);
         Complex c3 = c1 + c2; // An example call to "operator+"
         c3.print();
      }

Function Overriding
....................

If derived class defines same function as defined in its base class, it is known as function overriding in C++. It is used to achieve runtime polymorphism.


.. code:: c++

      #include <iostream>  
      using namespace std;  
      class Animal {  
          public:  
      void eat(){    
      cout<<"Eating...";    
          }      
      };   
      class Dog: public Animal    
      {    
       public:  
       void eat()    
          {    
             cout<<"Eating bread...";    
          }    
      };  
      int main(void) {  
         Dog d = Dog();    
         d.eat();  
         return 0;  
      }  

output

.. code:: c++

      Eating bread...

Virtual Functions
....................

A member function in the base class which is declared using virtual keyword is called virtual functions. They can be redefined in the derived class.

.. code:: c++

      #include<iostream>
      using namespace std;

      class BaseClass{
          public:
              int var_base=1;
              virtual void display(){
                  cout<<"1 Dispalying Base class variable var_base "<<var_base<<endl;
              }
      };

      class DerivedClass : public BaseClass{
          public:
                  int var_derived=2;
                  void display(){
                      cout<<"2 Dispalying Base class variable var_base "<<var_base<<endl;
                      cout<<"2 Dispalying Derived class variable var_derived "<<var_derived<<endl;
                  }
      };

      int main(){
          BaseClass * base_class_pointer;
          BaseClass obj_base;
          DerivedClass obj_derived;

          base_class_pointer = &obj_derived;
          base_class_pointer->display();
          return 0;
      }

output

.. code:: c++

      2 Dispalying Base class variable var_base 1
      2 Dispalying Derived class variable var_derived 2

Abstract Class and Pure Virtual Function
....................

An interface describes the behavior or capabilities of a C++ class without committing to a particular implementation of that class.

The C++ interfaces are implemented using abstract classes.

.. code:: c++

      Abstract Class is a class which contains atleast one Pure Virtual function in it.
      A class is abstract if it has at least one pure virtual function. 
      Classes inheriting an Abstract Class must provide definition to the pure virtual function, otherwise they will also become abstract class.

.. code:: c++

      #include<iostream>
      using namespace std;

      class Base
      {
      int x;
      public:
         virtual void fun() = 0;
         int getX() { return x; }
      };

      // This class inherits from Base and implements fun()
      class Derived: public Base
      {
         int y;
      public:
         void fun() { cout << "fun() called"; }
      };

      int main(void)
      {
         Derived d;
         d.fun();
         return 0;
      }

output

.. code:: c++

      fun() called

3. Abstraction
------------

Hiding internal details and showing functionality is known as abstraction. For example: phone call, we don't know the internal processing.

In C++, we use abstract class and interface to achieve abstraction.

4. Encapsulation
------------

Binding code and data together into a single unit is known as encapsulation. For example: capsule, it is wrapped with different medicines.

Generic Functions using Template
==========================================

Advantage of OOPs
==========================================

OOPs makes development and maintenance easier.

OOPs provide data hiding whereas in Procedure-oriented programming language a global data can be accessed from anywhere.

Difference between Private and Protected
------------
Private
.......

Only the member functions or the friend functions are allowed to access the private data members of a class.

Protected
.......

The class member declared as Protected are inaccessible outside the class but they can be accessed by any subclass(derived class) of that class.


‘this’ Pointer :
------------

.. code:: c++

      this is a keyword that refers to the current instance of the
      class. There can be 3 main uses of ‘this’ keyword:
      1. It can be used to pass the current object as a parameter to
      another method
      2. It can be used to refer to the current class instance variable.
      3. It can be used to declare indexers.

Global variables
------------
Global variables are created when the program starts, and destroyed when it ends.

`Differences between pointers and references in C++ <https://www.educative.io/edpresso/differences-between-pointers-and-references-in-cpp>`_
------------

pointer
.......

A pointer in C++ is a variable that holds the memory address of another variable.

reference
.......

A reference is an alias for an already existing variable. Once a reference is initialized to a variable, it cannot be changed to refer to another variable. Hence, a reference is similar to a const pointer.

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
      
2) Static Function Members & Static Variables 
....................

Static Function Members :- By declaring a function member as static, you make it independent of any particular object of the class. A static member function can be called even if no objects of the class exist and the static functions are accessed using only the class name and the scope resolution operator ::.

.. code:: c++

      #include <iostream>

      using namespace std;

      class Box {
         public:
            static int objectCount;

            // Constructor definition
            Box(double l = 2.0, double b = 2.0, double h = 2.0) {
               cout <<"Constructor called." << endl;
               length = l;
               breadth = b;
               height = h;

               // Increase every time object is created
               objectCount++;
            }
            double Volume() {
               return length * breadth * height;
            }
            static int getCount() {
               return objectCount;
            }

         private:
            double length;     // Length of a box
            double breadth;    // Breadth of a box
            double height;     // Height of a box
      };

      // Initialize static member of class Box
      int Box::objectCount = 0;

      int main(void) {
         // Print total number of objects before creating object.
         cout << "Inital Stage Count: " << Box::getCount() << endl;

         Box Box1(3.3, 1.2, 1.5);    // Declare box1
         Box Box2(8.5, 6.0, 2.0);    // Declare box2

         // Print total number of objects after creating object.
         cout << "Final Stage Count: " << Box::getCount() << endl;

         return 0;
      }

output

.. code:: c++

      Inital Stage Count: 0
      Constructor called.
      Constructor called.
      Final Stage Count: 2
      
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
