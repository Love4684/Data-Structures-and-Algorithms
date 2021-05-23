
.. contents::
   :local:
   :depth: 3

Program to Check if a Given String is Palindrome
===============================================================================

.. code:: c++

    #include<bits/stdc++.h>
    using namespace std;
    bool ispalindrome(string str, int l, int r)
    {
        if(l>=r)
            return true;
        if(str[l] != str[r])
            return false;
        return ispalindrome(str, l+1, r-1);
    }
    int main()
    {
        string str = "abcdcba";
        bool x = ispalindrome(str, 0, str.length()-1);
        x ? cout << "palindrome" : cout << "not palindromr";
        return 0;
    }
