
.. contents::
   :local:
   :depth: 3

STL
===============================================================================

vector
===============================================================================

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
      
Vector of Pairs
-------------- 

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;

      void printvec(vector<pair<int , int>> &v)

      { v.push_back({3, 5});
          for (int i = 0; i < v.size(); ++i)
          {

              cout << v[i].first << " " << v[i].second << endl;
          }
      }
      int main()
      {
          vector<pair<int, int>> v;
          // v = {{2, 3}, {4, 5}, {7, 6}};
          int n;
          cin >> n;
          for (int i = 0; i < n; ++i)
          {   int x, y;
              cin >> x >> y;
              v.push_back({x, y});
          }
          printvec(v);
      }

input

.. code:: c++

      3
      5 1
      10 3
      20 4


output

.. code:: c++

      5 1
      10 3
      20 4
      3 5

Vector of vector
-------------- 

.. code:: c++


Map
===============================================================================

Counting frequencies of array elements
-------------- 

.. code:: c++
      
      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {int arr[] = { 10, 20, 20, 10, 10, 20, 5, 20 };
      int n = sizeof(arr)/sizeof(arr[0]);
          map <int, int> m ;

          for (int i = 0; i < n; ++i)
          {
                      m[arr[i]]++;
          }

          for(auto x : m) cout << x.first << " " << x.second <<  endl;
      }
      
output

.. code:: c++

      5 1
      10 3
      20 4

for string
-------------- 

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {
         map< string, int> m;
         int n; cin >> n;
         for (int i = 0; i < n; ++i)
         {
             string s; cin >> s;
             m[s]++; 
         }
         for(auto pr : m)
          cout << pr.first << " " << pr.second << endl;
      }


 input
 
.. code:: c++

       5
      sed
      drw
      sed
      drw
      drw


output

.. code:: c++

      drw 3
      sed 2

Non-Repeating Element
-------------- 

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {
          vector<int> v = { 9, 4, 9, 6, 7, 4};
          map<int, int> m;
          for (int i = 0; i < v.size(); ++i)
          {
              m[v[i]]++;
          }
          for(auto x : m)
          {
              if(x.second == 1)
              {
                  cout << x.first;
                   break;
              }
          }
      }

output

.. code:: c++

     6

unordered_map
===============================================================================

Counting frequencies of array elements
-------------- 

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {
         unordered_map< int, int> m;
         int n; cin >> n;
         for (int i = 0; i < n; ++i)
         {
             int temp; cin >> temp;
             m[temp]++; 
         }
         for(auto pr : m)
          cout << pr.first << " " << pr.second << endl;
      }

input

.. code:: c++

      8
      10 20 20 10 10 20 5 20 
      
outut

.. code:: c++

      5 1
      10 3
      20 4


set
===============================================================================

rmove dupicate
-------------- 


.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {
         set<int> s;
         int n; cin >> n;
         for (int i = 0; i < n; ++i)
         {
             int temp; cin >> temp;
             s.insert(temp);
         }
         for(auto pr : s)
          cout << pr << " ";
          cout << endl;

         for (auto it = s.begin() ; it != s.end(); it++)
         {
             cout << *it << " ";
         }
      }
      
input

.. code:: c++

      8
      10 20 20 10 10 20 5 20 

output

.. code:: c++

      5 10 20 
      5 10 20 

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {int arr[6] = {4, 2, 3, 3, 2, 4 };
         set<int> s;
         for (int i = 0; i < 6; ++i)
         {
            s.insert(arr[i]);
         }
         for(auto pr : s)
          cout << pr << " ";
          cout << endl;
      }
      
output

.. code:: c++

      2 3 4 
      
      
Remove duplicates from a given string
------------
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
