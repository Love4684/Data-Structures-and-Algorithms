

.. contents::
   :local:
   :depth: 3

Fibonacci numbers
===============================================================================


.. code:: c++

      #include <bits/stdc++.h>
      using namespace std;
      const int N = 1e5 + 10;
      int dp[N];
      int fib(int n)
      {
      if(n == 0) return 0;
      if(n == 1) return 1;
      if(dp[n] != -1) return dp[n];
      return dp[n] = fib(n-1) + fib(n-2);

      }
      int main()
      {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        int ans = fib(n);
        cout << ans;
      }





0-1 Knapsack
===============================================================================

Recursion
.............

.. code:: c++

      #include <bits/stdc++.h>
      using namespace std;
      int knapSack(int W, int wt[], int val[], int n)
      {
          if (n == 0 || W == 0)
              return 0;
          if (wt[n - 1] > W)
              return knapSack(W, wt, val, n - 1);
          else
              return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
      }
      int main()
      {
          int val[] = { 60, 100, 120 };
          int wt[] = { 10, 20, 30 };
          int W = 50;
          int n = sizeof(val) / sizeof(val[0]);
          cout << knapSack(W, wt, val, n);
          return 0;
      }
      
Memoize recursive code
.............

.. code:: c++

      int knapSack(int w, int wt[], int val[], int n){
              vector<vector<int> > t(n+1, vector<int>(w+1, -1));
              return fun(w, wt, val, n, t);
          }
          int fun(int w, int wt[], int val[], int n, vector<vector<int>>& t) 
          { 

            if(n<=0 || w<=0) return 0;

            if(t[n][w] != -1) return t[n][w];

              if(wt[n-1] <= w){
              return  t[n][w] = max(val[n-1] + fun(w-wt[n-1], wt, val, n-1, t), 0+fun(w,wt,val,n-1, t));
              }

              else if(wt[n-1] > w){
              return  t[n][w] = 0 + fun(w,wt,val,n-1, t);
              }

          }



`Counting Bits <https://leetcode.com/problems/counting-bits/>`_
===============================================================================

.. code:: c++

      class Solution {
      public:
          vector<int> countBits(int num) {
              //mem[i] = No of 1s from 0 to number i
              vector<int> mem(num+1);
              mem[0] = 0;

              for(int i=1;i<=num;++i)
                  mem[i] = mem[i/2] + i%2;

              return mem;
          }
      };



`Coin Change <https://leetcode.com/problems/coin-change/>`_
===============================================================================

.. code:: c++

    int coinChange(vector<int>& coins, int amount) {
       int n=coins.size();
        int dp[amount+1];
        for(int i=0;i<=amount;i++)
            dp[i]=amount+1;
        //memset(dp,(amount),sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=amount;i++)
            for(int j=0;j<n;j++)
                if(coins[j]<=i)
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
        if(dp[amount]==amount+1)
            return -1;
        else
            return dp[amount];
    }


`Longest Increasing Subsequence(nlogn) <https://leetcode.com/problems/longest-increasing-subsequence/>`_
===============================================================================

.. code:: c++

      class Solution {
      public:
          int lengthOfLIS(vector<int>& nums) {
           vector<int> seq;
           seq.push_back(nums[0]);

           for (int i = 1; i < nums.size(); ++i)
           {
               if(nums[i] > seq.back())
               {
                  seq.push_back(nums[i]);
               }
               else
               {
                  int ind = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                  seq[ind] = nums[i];
               }
           }
              return seq.size();
          }
      };
      
n^2
.............

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;

      int main()
       {
           vector<int> v = {3, 5, 9, 7, 8};
           vector<int> dp(v.size(), 1);

           for (int i = 0; i < v.size(); ++i)
           {
               for (int j = 0; j < i; ++j)
               {
                   if(v[j] < v[i])
                   {
                      dp[i] = max(dp[i], dp[j]+1);
                   }
               }
           }
           for (auto it : dp)
           {
               cout << it << " ";
           }
           cout << endl <<  *max_element(dp.begin(), dp.end()) << endl;

           return 0;
      }      
      

`Word Break <https://leetcode.com/problems/word-break/>`_
===============================================================================

.. code:: c++

`Longest Common Subsequence <https://leetcode.com/problems/longest-common-subsequence/>`_
===============================================================================

.. code:: c++

`Regular Expression Matching <https://leetcode.com/problems/regular-expression-matching/>`_
===============================================================================

.. code:: c++


`Longest Palindromic Substring <https://leetcode.com/problems/longest-palindromic-substring/>`_
===============================================================================

.. code:: c++

`Best Time to Buy and Sell Stock with Transaction Fee <https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/>`_
===============================================================================

.. code:: c++

`Partition Equal Subset Sum (0/1 Knapsack) <https://leetcode.com/problems/partition-equal-subset-sum/>`_
===============================================================================

.. code:: c++

`House Robber III <https://leetcode.com/problems/house-robber-iii/>`_
===============================================================================

.. code:: c++

