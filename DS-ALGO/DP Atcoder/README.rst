
.. contents::
   :local:
   :depth: 3


`A - Frog 1 <https://atcoder.jp/contests/dp/tasks/dp_a>`_
==================================

.. code:: c++

      #include<bits/stdc++.h>

      using namespace std;

      int main()
      {
         int n;
         cin>>n;
         vector<int> dp(n+1);
         dp[1]=0;
         std::vector<int> v(n+1);
         for(int i=1;i<=n;i++)
         {
            cin>>v[i];
         }
         dp[2]=abs(v[1]-v[2]);
         for(int i=3;i<=n;i++)
         {
            dp[i]=min(dp[i-2]+abs(v[i-2]-v[i]),dp[i-1]+abs(v[i-1]-v[i]));
         }
         cout<<dp[n]<<endl;
      }
    
`B - Frog 2 <https://atcoder.jp/contests/dp/tasks/dp_b>`_
==================================

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;

      int util(int n,int k,vector<int>& heights,vector<int>& dp)
      {
        if(n==0)
          return 0;
        if(dp[n]!=-1)
          return dp[n];

        int mini = INT_MAX;
        for(int j=1;j<=k;j++)
        {
          if(n-j>=0)
          {
            int cost = util(n-j,k,heights,dp) + abs(heights[n]-heights[n-j]);
            mini = min(mini,cost);
          }
        }

        return dp[n] = mini;

      }

      int main()
      {
        int n,k;
        cin>>n>>k;
        vector<int> heights(n);
        for(int i=0;i<n;i++)
         cin>>heights[i];

        vector<int> dp(n,-1);
        dp[0]=0;
        cout<<util(n-1,k,heights,dp); //n-1 for index use

        return 0;
      }
