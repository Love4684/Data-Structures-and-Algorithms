

.. contents::
   :local:
   :depth: 3


C++ Adjacency Matrix Representation
==================================

.. code:: c++

      #include <bits/stdc++.h>
      using namespace std;

      int main() {
         int n, m;
         cin >> n >> m; 

         // declare the adjacent matrix 
         int adj[n+1][n+1]; 

         // take edges as input 
         for(int i = 0;i<m;i++) {
             int u, v; 
             cin >> u >> v;
             adj[u][v] = 1; 
             adj[v][u] = 1; 
         }
         return 0;
      }
      
C++ Adjacency List Representation
==================================      

.. code:: c++

      #include <bits/stdc++.h>
      using namespace std;

      int main() {
         int n, m;
         cin >> n >> m; 

         // declare the adjacent matrix 
         vector<int> adj[n+1]; 

         // take edges as input 
         for(int i = 0;i<m;i++) {
             int u, v; 
             cin >> u >> v;
             adj[u].push_back(v); 
             adj[v].push_back(u); 
         }
         return 0;
      }

`number-of-connected-components-in-an-undirected-graph <https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/>`_
===============================================================================

.. code:: c++

`Course Schedule <https://leetcode.com/problems/course-schedule/>`_
===============================================================================

.. code:: c++


`Possible Bipartition <https://leetcode.com/problems/possible-bipartition/>`_
===============================================================================

.. code:: c++

`Minimum Height Trees <https://leetcode.com/problems/minimum-height-trees/>`_
===============================================================================

.. code:: c++
