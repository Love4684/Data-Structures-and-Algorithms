
.. contents::
   :local:
   :depth: 3


MATH
===============================================================================

Factorial of a number
-------------------------

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
       {      
           int n, result = 1;
              cin >> n;
              for(int i = 2; i <= n; i++)
              {
                  result *= i;
              }
              cout << result;
          return 0;
      }
      
      
 
Factorial of a large number
-------------------------

.. code:: c++
     
         #include<bits/stdc++.h>
         using namespace std;

         void find_fact(int n)
         {
             int carry=0,val;
             vector<int>v;
             v.push_back(n);
             for(int i = n-1;i>1;i--)
             {
                 for(int j=0;j<v.size();j++)
                 {
                     val = v[j]*i + carry;
                     v[j] = val%10;
                     carry = val/10;
                 }
                 while(carry)
                 {
                     v.push_back(carry%10);
                     carry=carry/10;
                 }
             }
             reverse(v.begin(),v.end());
             for(int i=0;i<v.size();i++)
                 cout << v[i];
         }
         int main()
          {      
              int n;
                 cin >> n;
                 find_fact(n);
             return 0;
         }      
      
      

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
