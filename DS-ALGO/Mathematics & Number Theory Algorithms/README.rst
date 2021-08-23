
.. contents::
   :local:
   :depth: 3


MATH
===============================================================================

Factorial
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
      
      
trailing zeroes in factorial
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

Palindrome 
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

Prime
------------------

.. code:: c++

      #include <bits/stdc++.h>  
      using namespace std;  
      int main()  
      {  
        int n, i, m=0, flag=0;  

        cin >> n;   
        for(i = 2; i <= sqrt(n); i++)  
        {  
            if(n % i == 0)  
            {  
                cout<<"Number is not Prime."<<endl;  
                flag=1;  
                break;  
            }  
        }  
        if (flag==0)  
            cout << "Number is Prime."<<endl;  
        return 0;  
      }  

.. code:: c++

      // C++ program to check whether a mumber
      // is prime or not using recursion
      #include <iostream>
      using namespace std;

      // function check whether a number
      // is prime or not
      bool isPrime(int n)
      {
         static int i = 2;

         // corner cases
         if (n == 0 || n == 1) {
            return false;
         }

         // Checking Prime
         if (n == i)
            return true;

         // base cases
         if (n % i == 0) {
            return false;
         }
         i++;
         return isPrime(n);
      }

      // Driver Code
      int main()
      {

         isPrime(35) ? cout << " true\n" : cout << " false\n";
         return 0;
      }

      // This code is contributed by yashbeersingh42



Armstrong
------------------

.. code:: c++

      #include <bits/stdc++.h>
      using namespace std;
      int main()
      {int n, d, r, sum=0, x;
          cin >> x;
          n = x;
          d = log10(n) + 1;
          for (int i = 0; i < d; ++i)
          {
             r = n%10;
             sum += pow(r, d);
             n /= 10;
          }
          if(sum == x)
              cout << "amstrong";
          else
              cout << "not amastrong";
      }


Sieve of Eratosthenes.
-------------------------

Given a number n, print all primes smaller than or equal to n

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;

      int main()
       {
           int arr[100] = {0};
           int n = 30;
           for (int i = 2; i*i < n; ++i)
           {
               for (int j = i*i; j < n; j+=i)
               {
                   if(arr[j] == 0)
                   {
                      arr[j] = 1;
                   }
               }
           }
           for (int i = 2; i < n; ++i)
           {
               if(arr[i] == 0)
                  cout << i << " ";
           }
           return 0;
      }

output

.. code:: c++

      2 3 5 7 11 13 17 19 23 29 
      
      

`Count ways to distribute m items among n people <https://www.geeksforgeeks.org/count-ways-to-distribute-m-items-among-n-people/>`_
-------------------------

.. code:: c++      

      #include <bits/stdc++.h>
      using namespace std;
      int binomial_coefficient(int n, int r)
      {
          int res = 1;

          if (r > n - r)
              r = n - r;

          for (int i = 0; i < r; ++i) {
              res *= (n - i);
              res /= (i + 1);
          }

          return res;
      }
      int calculate_ways(int m, int n)
      {
          if (m < n)
              return 0;

          // ways  -> (n+m-1)C(m-1)
          int ways = binomial_coefficient(n + m - 1, n - 1);
          return ways;
      }

      int main()
      {
          // m represents number of mangoes
          // n represents number of people
          int m = 7, n = 5;

          int result = calculate_ways(m, n);
          printf("%d\n", result);

          return 0;
      }
      
`Distribute N candies among K people <https://leetcode.com/problems/distribute-candies-to-people/>`_
-------------------------
      
