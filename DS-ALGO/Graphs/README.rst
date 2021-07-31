

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

Breadth First Search
==================================

.. image:: https://github.com/Love4684/Data-Structures-and-Algorithms/blob/master/DS-ALGO/Graphs/media/1.png


.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      class Solution {
      public:
          vector<int>bfsOfGraph(int V, vector<int> adj[]){
              vector<int> bfs; 
              vector<int> vis(V, 0); 
              queue<int> q; 
              q.push(2); // start traversal from vertex 2
              vis[2] = 1; 
              while(!q.empty()) {
                  int node = q.front();
                  q.pop(); 
                  bfs.push_back(node);             
                  for(auto it : adj[node]) {
                      if(!vis[it]) {
                          q.push(it); 
                          vis[it] = 1; 
                      }
                  }
              }        
              return bfs; 
          }
      };

      // { Driver Code Starts.
      int main(){

              int V, E;
              cin >> V >> E;
              vector<int> adj[V];

              for(int i = 0; i < E; i++)
              {
                  int u, v;
                  cin >> u >> v;
                  adj[u].push_back(v);
          //      adj[v].push_back(u); // uncomment this for undirected graoh 
              }
              Solution obj;
              vector<int>ans=obj.bfsOfGraph(V, adj);
              for(int i=0;i<ans.size();i++){
                  cout<<ans[i]<<" ";
              }
          return 0;
      }  

input

.. code:: c++

      4 6
      0 1
      0 2
      1 2
      2 0
      2 3
      3 3
      
output

.. code:: c++

      2 0 3 1 
      

`Depth First Search <https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#>`_
==================================

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      class Solution 
      {
          void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) 
          {
              storeDfs.push_back(node); 
              vis[node] = 1; 
              for(auto it : adj[node]) 
              {
                  if(!vis[it]) 
                  {
                      dfs(it, vis, adj, storeDfs); 
                  }
              }
          }
          public:
          vector<int>dfsOfGraph(int V, vector<int> adj[])
          {
              vector<int> storeDfs; 
              vector<int> vis(V, 0); 
              dfs(0, vis, adj, storeDfs); 
              return storeDfs; 
          }
      };

      int main()
      {
              int V, E;
              cin >> V >> E;
              vector<int> adj[V];
              for(int i = 0; i < E; i++)
              {
                  int u, v;
                  cin >> u >> v;
                  adj[u].push_back(v);
                  adj[v].push_back(u);
              }
              Solution obj;
              vector<int>ans=obj.dfsOfGraph(V, adj);
              for(int i=0;i<ans.size();i++)
              {
                  cout<<ans[i]<<" ";
              }
          return 0;
      } 

input

.. code:: c++

      5 4
      0 1 
      0 2
      0 3 
      2 4

output

.. code:: c++

      0 1 2 4 3 

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
