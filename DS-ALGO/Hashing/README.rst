
.. contents::
   :local:
   :depth: 3

Remove duplicates from a given string
=====================================
.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {
         string s, result = "";
         cin >> s;
         map<char, int> map;
         for (int i = 0; i < s.size(); ++i)
         {
             if(map[s[i]] == 0)
             {
              result += s[i];
              map[s[i]] = 1;
             }
         }
         cout<<result;
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

`Longest Consecutive Sequence <https://leetcode.com/problems/longest-consecutive-sequence/>`_
==================================

.. code:: c++

      class Solution {
      public:
          int longestConsecutive(vector<int>& nums) {
              unordered_set<int> numsSet;
              for (int el: nums) numsSet.insert(el);

              int count = 0, maxCount = 0;
              for (auto el: numsSet) {
                  if (numsSet.count(el-1)== 0) 
                  {
                      int startEl = el;
                      count = 1;

                      while (numsSet.count(startEl + 1) > 0) {
                          count++;
                          startEl++;
                      }
                      maxCount = max(maxCount, count);
                  }
              }
              return maxCount;
          }
      };


`Subarray Sum Equals K <https://leetcode.com/problems/subarray-sum-equals-k/>`_
==================================

.. code:: c++

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            if(mp.find(sum-k) != mp.end()){
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
