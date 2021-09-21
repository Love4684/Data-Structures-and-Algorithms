

.. contents::
   :local:
   :depth: 3


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

`Longest Increasing Subsequence <https://leetcode.com/problems/longest-increasing-subsequence/>`_
===============================================================================

.. code:: c++


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

