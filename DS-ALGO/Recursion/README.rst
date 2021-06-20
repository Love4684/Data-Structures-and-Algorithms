
.. contents::
   :local:
   :depth: 3

Program to Check if a Given String is Palindrome
===============================================================================

.. code:: c++

    #include<bits/stdc++.h>
    using namespace std;
    bool ispalindrome(string str, int l, int r)
    {
        if(l>=r)
            return true;
        if(str[l] != str[r])
            return false;
        return ispalindrome(str, l+1, r-1);
    }
    int main()
    {
        string str = "abcdcba";
        bool x = ispalindrome(str, 0, str.length()-1);
        x ? cout << "palindrome" : cout << "not palindromr";
        return 0;
    }

Print all subsequences of a string
===============================================================================

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      void powerset(string str, int i, string cstr)
      {
      if(str.length() == i)
      {
          cout << cstr << endl;
          return;
      }
      powerset(str, i+1, cstr + str[i]);
      powerset(str, i+1, cstr);
      }
      int main()
      {
          string str = "abc";
          powerset(str, 0, "");
      }

output

.. code:: c++

      abc
      ab
      ac
      a
      bc
      b
      c

Write a program to print all permutations of a given string
===============================================================================

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      void permutation(string str, int l, int r)
      {
          if(l == r)
          {
              cout << str << endl;
              return;
          }
          for (int i = l; i <= r; ++i)
          {
              swap(str[l], str[i]);
              permutation(str, l+1, r);
              swap(str[l], str[i]);

          }
      }

      int main()
      {
          string str = "ABC";
          permutation(str, 0, str.size()-1);
      }
      
.. code:: c++

      ABC
      ACB
      BAC
      BCA
      CBA
      CAB

`Count all possible paths from top left to bottom right of a mXn matrix <https://www.hackerrank.com/challenges/balanced-brackets/problem>`_
===============================================================================   

.. code:: c++

      #include <bits/stdc++.h>
      using namespace std;
      int numberofways(int m, int n)
      {
          if(m == 1 || n == 1)
              return 1;
          return numberofways(m-1, n) + numberofways(m, n-1);
      }
      int main()
      {int m, n;
          cin >> m >> n;
          int x = numberofways(m, n);
          cout << x;
          return 0;
      }
      
output

.. code:: c++
   6
