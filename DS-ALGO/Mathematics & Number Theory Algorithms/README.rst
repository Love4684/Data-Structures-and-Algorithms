
.. contents::
   :local:
   :depth: 3

MATH
===============================================================================

Count trailing zeroes in factorial of a number
-------------------------
.. code:: c++

    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int n = 10;  // 10! = 3,628,800
        int result = 0;
        for (int i = 5; i < n; i *= 5)
        {
            result += n/5;
        }
        cout << result;
        return 0;
    }

output

.. code:: c++

    2

Check if a number is Palindrome 
-------------------------

using string

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {
          string s = "112233445566778899000000998877665544332211";
          int flag = 0;
          int n = s.length();
          for (int i = 0; i < n/2; ++i)
          {
              if(s[i] != s[n-i-1])
               {  flag = 1;
                  break;
               }
          }

      if(flag == 1) 
          cout << "not a palindrom";
      else
          cout << "palindrom";
      return 0;
      }
      
output

.. code:: c++

      palindrom
      
using number

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {
         int num = 345633;
         int n = num;
         int r, sum = 0;

         while(n > 0)
         {
          r = n%10;
          sum = 10*sum + r;
          n /= 10;
         }

          cout << " The reverse of the number is: " << sum << endl;

         if(n == num)
          cout << "palindrom";
          else
              cout << "not palindrom";
      return 0;
      }

output

.. code:: c++

      The reverse of the number is: 336543
      not palindrom
