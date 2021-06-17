
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

`Two Sum <https://leetcode.com/problems/two-sum/>`_
=========================================================================

.. code:: c++

      vector<int> twoSum(vector<int>& nums, int target) {
              vector<int> ans;
              unordered_map<int, int> map;
          for (int i = 0; i < nums.size(); i++)
          {
              int temp = target - nums[i];

              if (map.find(temp) != map.end())
              {   ans.push_back(map[temp]);
                  ans.push_back(i);
                  return ans;
              }
              map[nums[i]] = i;
          }
              return ans;
          }
