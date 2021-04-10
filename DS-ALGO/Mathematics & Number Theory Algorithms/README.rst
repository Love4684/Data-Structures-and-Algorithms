
.. contents::
   :local:
   :depth: 3

MATH
===============================================================================

Count trailing zeroes in factorial of a number
-------------------------
.. code:: c++

    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int n = 10;  // 10! = 3,628,800
        int result = 0;
        for (int i = 5; i < n; i *= 5)
        {
            result += n/5;
        }
        cout << result;
        return 0;
    }

output

    2

Check if a number is Palindrome
-------------------------

.. code:: c++

