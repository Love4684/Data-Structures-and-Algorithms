.. contents::
   :local:
   :depth: 3

MCQ
===============================================================================

Q. 1
===============================================================================

.. code:: c++

      #include <bits/stdc++.h>
      using namespace std;
      int main() {
         string str;
         vector<string> v;
         vector<vector<string> > ac;

         while(getline(cin, str))
         { 
             v.push_back(str);
         }

         int sz = v.size();
         for(int i = 0; i < sz; i++)
         {   vector<string> temp;
            stringstream ss(v[i]);
             string word;
             while (ss >> word) {
                 temp.push_back(word);
             }
             ac.push_back(temp);
         }
         map<string, set<string> > mapOfSet;
         for(int i = 0; i < sz-1; i++)
         {
            int n = ac[i].size();
            for(int j = 1; j < n; j++)
            {
                mapOfSet[ac[i][0]].insert(ac[i][j]);
            }
         }
         set<string> ans, temp;
         int x = mapOfSet[ac[sz-1][0]].size();
         ans = mapOfSet[ac[sz-1][0]];
         temp = ans;
         for(auto d : temp)
            ans.insert(mapOfSet[d].begin(), mapOfSet[d].end());
         for(auto p : ans)
         cout<<p;
         return 0;
      }



