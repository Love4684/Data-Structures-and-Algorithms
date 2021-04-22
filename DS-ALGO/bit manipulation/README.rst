
.. contents::
   :local:
   :depth: 3
   
Bit Manipulation Algorithms
===============================================================================

Binary Number System
--------------------

in decimal 

.. image:: https://github.com/Love4684/practice/blob/main/media/1.jpg

in octal

.. image:: https://github.com/Love4684/practice/blob/main/media/2.jpg

in hexadecimal

.. image:: https://github.com/Love4684/practice/blob/main/media/3.jpg

in binary

.. image:: https://github.com/Love4684/practice/blob/main/media/4.jpg

 
Conversion 
--------------------

   * Decimal to Binary: Performing Division by Two with Remainder (For integer part)
   
   
   Ex 1.  Converting decimal number 112 into binary number.
   

      +------------------+------------------+
      |      Division    |   Remainder (R)  |
      +==================+==================+
      |    112 / 2 = 56	 |  0               |
      +------------------+------------------+
      |     56 / 2 = 28	 |  0               |
      +------------------+------------------+
      |     28 / 2 = 14	 |  0               |
      +------------------+------------------+
      |      14 / 2 = 7	 |  0               |
      +------------------+------------------+
      |       7 / 2 = 3	 |  1               |
      +------------------+------------------+
      |       3 / 2 = 1	 |  1               |
      +------------------+------------------+
      |       1 / 2 = 0	 |  1               |
      +------------------+------------------+
      
Now, write remainder from bottom to up (in reverse order), this will be
1110000 which is equivalent binary number of decimal integer 112.

   * Ex 2. Convert decimal fractional number 0.8125 into binary number.
 

      +------------------+------------------+
      |  Multiplication  | Resultant integer|
      |                  |   part (R)       |
      +==================+==================+
      |0.81252 x 2=1.625 |  1               |
      +------------------+------------------+
      | 0.6252 x 2= 1.25 |  1               |
      +------------------+------------------+
      |  0.252 x 2= 0.50 |  0               |
      +------------------+------------------+
      |    0.52 x 2= 1.0 |  1               |
      +------------------+------------------+
      |        0 x 2 = 0 |  0               |
      +------------------+------------------+
      
      
Now, write these resultant integer part, this will be 0.11010 which is equivalent binary fractional number of decimal fractional 0.8125.

Subtraction of two Binary Numbers(2 - 3)
--------------------

.. image:: https://github.com/Love4684/practice/blob/main/media/5.png

Bitwise Complement Operator
--------------------

It is important to note that the bitwise complement of any integer N is equal to -(N + 1). For example,

Consider an integer 35. As per the rule, the bitwise complement of 35 should be -(35 + 1) = -36.

.. image:: https://github.com/Love4684/practice/blob/main/media/6.webp

.. code:: c++

      #include <iostream>

      int main() {
          int num1 = 35;
          int num2 = -150;
          cout << "~(" << num1 << ") = " << (~num1) << endl;
          cout << "~(" << num2 << ") = " << (~num2) << endl;

          return 0;
      }
      
Output

.. code:: c++

      ~(35) = -36
      ~(-150) = 149

Right Shift Operator x >> k
--------------------

remove k bit from left(Ex: One bit Right Shift 0011 >> 1 = 001)

.. image:: https://github.com/Love4684/practice/blob/main/media/7.webp

Left Shift Operator x << k
--------------------

add k bit zeros from left((Ex: One bit left Shift 0011 << 1 = 00110)

.. image:: https://github.com/Love4684/practice/blob/main/media/8.webp

.. code:: c++

      #include <iostream>

      int main() {
          int num = 212, i;
          cout << "Shift Right:" << endl;
          for (i = 0; i < 4; i++) {
              cout << "212 >> " << i << " = " << (212 >> i) << endl;
          }

          cout << "\nShift Left:" << endl;
          for (i = 0; i < 4; i++) {
              cout << "212 << " << i << " = " << (212 << i) << endl;
          }

          return 0;
      }

output

.. code:: c++

      Shift Right:
      212 >> 0 = 212
      212 >> 1 = 106
      212 >> 2 = 53
      212 >> 3 = 26

      Shift Left:
      212 << 0 = 212
      212 << 1 = 424
      212 << 2 = 848
      212 << 3 = 1696

Question
===============================================================================


Check if a Number is Odd or Even using Bitwise Operators.
--------------------

* As we know bitwise AND Operation of the Number by 1 will be 1, If it is odd because the last bit will be already set. Otherwise it will give 0 as output

* As we know bitwise XOR Operation of the Number by 1 increment the value of the number by 1 if the number is even otherwise it decrements the value of the number by 1 if the value is odd.

* As we know bitwise OR Operation of the Number by 1 increment the value of the number by 1 if the number is even otherwise it will remain unchanged.
     
.. code:: c++

      #include <iostream>
      using namespace std;
      int main()
      {int n=5;
      
      ((n&1)==0) ? cout<<"even " : cout<<"odd ";
     
      ((n ^ 1) == (n + 1)) ? cout<<"even " : cout<<"odd ";
      
      ((n | 1) > n) ? cout<<"even " : cout<<"odd ";
      }

output

.. code:: c++

      odd odd odd

swap two numbers without using a temporary variable
--------------------

.. code:: c++

      #include <bits/stdc++.h>
      using namespace std;

      int main()
      {
          int x = 10, y = 5;
          x = x ^ y; 
          y = x ^ y; 
          x = x ^ y;
          cout << "After Swapping: x =" << x << ", y=" << y;
          return 0;
      }
      
output

.. code:: c++

      After Swapping: x =5, y=10

Find value of k-th bit in binary representation
--------------------

.. code:: c++

      #include <iostream>
      using namespace std;
      int main()
      {
         int n = 7, k = 2;
         int x = (n & (1 << (k - 1)));  // value will be zero or non zero 
         cout << x << endl;
         int y = x >> k-1;
         cout << "kth bit = " << y;
          return 0;
      }

output

.. code:: c++

      2
      kth bit = 1

Set the K-th bit of a given number
--------------------

.. code:: c++

      #include <iostream>
      using namespace std;
      int main()
      {
          int n = 10, k = 3;
          int x = ((1 << k-1) | n);
          cout << x;
          return 0;
      }
      
output

.. code:: c++

      14

clear nth bit of a number
--------------------

.. code:: c++

      #include <iostream>
      using namespace std;
      int main()
      {
          int n = 13, k = 1;
          int x = (n & (~(1 << k-1)));
          cout << x;
          return 0;
      }

output 

.. code:: c++

      12

Count number of bits to be flipped to convert A to B
--------------------

.. code:: c++

      #include <iostream>
      using namespace std;
      int main()
      {
          int a = 10, b = 20;
          int x = a^b ;
          int count = 0;
          while(x > 0)
          {
              x &= (x-1);    // counting no of one
              count ++;
          }
          cout << count;
          return 0;
      }

output

.. code:: c++

      4
