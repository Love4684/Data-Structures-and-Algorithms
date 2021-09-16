.. contents::
   :local:
   :depth: 3

`Indian Coin Change <https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/>`_
===============================================================================

.. code:: c++


    #include <bits/stdc++.h>
    using namespace std;

    vector<int> deno = { 1, 2, 5, 10, 20,
                50, 100, 500, 1000 };
    int n = deno.size();

    void findMin(int V)
    {
        sort(deno.begin(), deno.end());
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            while (V >= deno[i]) {
                V -= deno[i];
                ans.push_back(deno[i]);
            }
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
    int main()
    {
        int n = 93;
        cout << "Following is minimal"
            << " number of change for " << n
            << ": ";
        findMin(n);
        return 0;
    }
    // output : Following is minimal number of change for 93: 50 20 20 2 1 
    

`Fractional Knapsack <https://www.geeksforgeeks.org/fractional-knapsack-problem/>`_
===============================================================================    
    
.. code:: c++


      #include <bits/stdc++.h>
      using namespace std;

      #define vi vector<int>
      #define pii pair<int, int>
      #define vii vector<pii>
      #define rep(i,a,b) for (int i = a; i < b; ++i)
      #define ff first
      #define ss second
      bool compare(pii p1 , pii p2)
      {
          double v1 = (double) p1.ff/p1.ss;
          double v2 = (double) p2.ff/p2.ss;
          return v1 > v2;
      }
      signed main()
      {
          int w = 50;
          vii a = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
          int n = a.size();
          sort(a.begin(), a.end(), compare);
          int ans = 0;
          rep(i, 0, n)
          {
              if(w >= a[i].ss)
              {
                  ans += a[i].ff;
                  w -= a[i].ss;
                  continue;
              }
              double vpw = (double) a[i].ff/a[i].ss;
              ans += w*vpw;
              break;
          }
          cout << ans;
          return 0;
      }
      // output 240
    
