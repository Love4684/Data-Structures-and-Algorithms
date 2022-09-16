
.. contents::
   :local:
   :depth: 3


Maximum occurring character (if it's more than two return 0)
===============================================================================

.. code:: c++

    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {string s = "bsabsnsnnnbb";
    char ch;
    int curmax = 0;
    int count = 0;
    map<char, int> map;
    for (auto i : s)
    {
        map[i]++;
    }
    for(auto it : map)
    {
        if(it.second > curmax)
        {
            ch = it.first;
            curmax = it.second;
        }
    }
    for(auto itr : map)
    {
        if(itr.second == curmax)
        {
            count++;
        }
        if(count > 1)
        { 
            curmax = 0;
            break;
        }
    }
    cout << ch << " " << curmax;
        return 0;
    }
