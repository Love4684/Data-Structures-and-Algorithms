
.. contents::
   :local:
   :depth: 3

Remove duplicates from a given string
=====================================
.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {int hash[123] = {0};
         string s, result = "";
         cin >> s;
         for (int i = 0; i < s.size(); ++i)
         {
            if(hash[s[i]] == 0)
            {
               hash[s[i]] = 1;
               result += s[i];
            }
         }
         cout << result;
      }
      
      
      
input

.. code:: c++

      retyyrtywyss


output

.. code:: c++

     retyws

Given an array A[] and a number x, check for pair in A[] with sum as x
=========================================================================

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;

      void findpair(std::vector<int> v, int sum)
      {
          unordered_set<int> s;
          for (int i = 0; i < v.size(); ++i)
          {
              int temp = sum-v[i];
              if(s.find(temp) != s.end())
                  cout << temp << " " << v[i] << endl;
              s.insert(v[i]);
          }
      }

      int main()
      {
         std::vector<int> v = {1, 4, 45, 6, 10, 8};
         int sum = 16;
         findpair(v, sum);
         return 0;
      }
