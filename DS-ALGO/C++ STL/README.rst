
.. contents::
   :local:
   :depth: 3

vector
===============================================================================

vector
--------------

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {
          vector <int> A = {2, 4, 7, 5 , 1};
          sort(A.begin(), A.end());   //O(NlogN) sorting

          bool present = binary_search(A.begin(), A.end(), 7); //True
          present = binary_search(A.begin(), A.end(), 3);      //False

          A.push_back(100);
          present = binary_search(A.begin(), A.end(), 100);

          A.push_back(100);
          A.push_back(100);
          A.push_back(100);
          A.push_back(123);


          auto lower = lower_bound(A.begin(), A.end(), 100);   // >=
          auto upper = upper_bound(A.begin(), A.end(), 100);   // >

          // 1 2 4 5 7 100 100 100 100 123

          cout << *lower << " " << *upper << endl;

          cout << (lower - A.begin() + 1) << endl;
          cout << (upper - A.begin() + 1) << endl;

          cout << upper - lower << endl;

      }
      
output

.. code:: c++

    100 123
    6
    10
    4
