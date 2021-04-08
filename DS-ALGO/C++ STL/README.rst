
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

          cout << "lower of 100 = " <<*lower << " " << "and uper of 100 = " << *upper << endl;



          cout << "frequency of 100 = " << count(A.begin(), A.end(), 100) << endl;

          cout << "lower index 100 = " << (lower - A.begin() + 1) << endl;
          cout << "upper index 100 = " << (upper - A.begin() + 1) << endl;

          cout << "frequency of 100 = " << upper - lower << endl;

          cout << "size of vector = " << A.size() << endl;

          for(auto it : A) cout <<  it << " ";

              cout << endl ;

          for(auto it : A) cout << count(A.begin(), A.end(), it) << " ";


      }
      
output

.. code:: c++

lower of 100 = 100 and uper of 100 = 123
frequency of 100 = 4
lower index 100 = 6
upper index 100 = 10
frequency of 100 = 4
size of vector = 10
1 2 4 5 7 100 100 100 100 123 
1 1 1 1 1 4 4 4 4 1 
