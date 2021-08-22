.. contents::
   :local:
   :depth: 3

Indian Coin Change
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
