
.. contents::
   :local:
   :depth: 3


`A - Frog 1 <https://atcoder.jp/contests/dp/tasks/dp_a>`_
==================================

.. code:: c++

    #include <bits/stdc++.h>
    using namespace std;
    const int N = 1e5 + 10;
    int dp[N];
    int h[N];
    int fog(int n)
    {
      int cost = INT_MAX;
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];
    cost = min(cost, (fog(n-1) + abs(h[n-1] - h[n-2])));
    if(n>2)
      cost = min(cost, (fog(n-2) + abs(h[n-1] - h[n-3])));

    return dp[n] = cost;
    }
    int main()
    {
      memset(dp, -1, sizeof(dp));
      int n;
      cin >> n;
    for (int i = 0; i < n; ++i)
    {
      cin >> h[i];
    }
      int ans = fog(n);
      cout << ans;
    }
    
`B - Frog 2 <https://atcoder.jp/contests/dp/tasks/dp_b>`_
==================================

.. code:: c++

    #include <bits/stdc++.h>
    using namespace std;
    const int N = 1e5 + 10;
    int dp[N];
    int h[N];
    int k;
    int fog(int n)
    {
      int cost = INT_MAX;
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    for (int i = 1; i <= k; ++i)
    {
      if(n-i >= 0)
    cost = min(cost, (fog(n-i) + abs(h[n] - h[n-i])));
    }
    return dp[n] = cost;
    }
    int main()
    {
      memset(dp, -1, sizeof(dp));
      int n;
      cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
      cin >> h[i];
    }
      int ans = fog(n-1);
      cout << ans;
    }
