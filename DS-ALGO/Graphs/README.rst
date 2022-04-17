

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
              for(int i = 1;i<=V;i++) {
               if(!vis[i]) dfs(i, vis, adj, storeDfs); 
          }
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
      
      
`Detect cycle in an undirected graph <https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#>`_
==================================

.. code:: c++

      class Solution {

      public:
          bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
              vis[node] = 1; 
              for(auto it: adj[node]) {
                  if(!vis[it]) {
                      if(checkForCycle(it, node, vis, adj)) 
                          return true; 
                  }
                  else if(it!=parent) 
                      return true; 
              }

              return false; 
          }
      public:
         bool isCycle(int V, vector<int>adj[]){
             vector<int> vis(V+1, 0); 
             for(int i = 0;i<V;i++) {
                 if(!vis[i]) {
                     if(checkForCycle(i, -1, vis, adj)) return true; 
                 }
             }

             return false; 
         }
      };

`Detect cycle in a directed graph <https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1>`_
==================================

.. code:: c++

      class Solution {
      private:
          bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
              vis[node] = 1; 
              dfsVis[node] = 1; 
              for(auto it : adj[node]) {
                  if(!vis[it]) {
                      if(checkCycle(it, adj, vis, dfsVis)) return true;
                  } else if(dfsVis[it]) {
                      return true; 
                  }
              }
              dfsVis[node] = 0; 
              return false;
          }
      public:
         bool isCyclic(int N, vector<int> adj[]) {
            int vis[N], dfsVis[N]; 
            memset(vis, 0, sizeof vis); 
            memset(dfsVis, 0, sizeof dfsVis); 

            for(int i = 0;i<N;i++) {
                if(!vis[i]) {
                    // cout << i << endl; 
                    if(checkCycle(i, adj, vis, dfsVis)) {
                        return true; 
                    }
                }
            }
            return false; 
         }
      };
      

`Bipartite Graph(BFS) <https://practice.geeksforgeeks.org/problems/bipartite-graph/1>`_
==================================

.. code:: c++

      bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
          queue<int>q;
          q.push(src); 
          color[src] = 1; 
          while(!q.empty()) {
              int node = q.front(); 
              q.pop();

              for(auto it : adj[node]) {
                  if(color[it] == -1) {
                      color[it] = 1 - color[node]; 
                      q.push(it); 
                  } else if(color[it] == color[node]) {
                      return false; 
                  }
              }
          }
          return true; 
      }
      bool checkBipartite(vector<int> adj[], int n) {
          int color[n];
          memset(color, -1, sizeof color); 
          for(int i = 0;i<n;i++) {
              if(color[i] == -1) {
                  if(!bipartiteBfs(i, adj, color)) {
                      return false;
                  }
              }
          }
          return true; 
      }

`Bipartite Graph(DFS) <https://practice.geeksforgeeks.org/problems/bipartite-graph/1>`_
==================================

.. code:: c++

      bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
          for(auto it : adj[node]) {
              if(color[it] == -1) {
                  color[it] = 1 - color[node];
                  if(!bipartiteDfs(it, adj, color)) {
                      return false; 
                  }
              } else if(color[it] == color[node]) return false; 
          }
          return true; 
      }
      bool checkBipartite(vector<int> adj[], int n) {
          int color[n];
          memset(color, -1, sizeof color); 
          for(int i = 0;i<n;i++) {
              if(color[i] == -1) {
                  color[i] = 1;
                  if(!bipartiteDfs(i, adj, color)) {
                      return false;
                  }
              } 
          }
          return true; 
      }


`Topological sort(DFS) <https://practice.geeksforgeeks.org/problems/topological-sort/1>`_
==================================

.. code:: c++

      class Solution{
          void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
              vis[node] = 1; 

              for(auto it : adj[node]) {
                  if(!vis[it]) {
                      findTopoSort(it, vis, st, adj); 
                  }
              }
              st.push(node); 
          }
         public:
         vector<int> topoSort(int N, vector<int> adj[]) {
             stack<int> st; 
             vector<int> vis(N, 0); 
             for(int i = 0;i<N;i++) {
                 if(vis[i] == 0) {
                     findTopoSort(i, vis, st, adj); 
                 }
             }
             vector<int> topo;
             while(!st.empty()) {
                 topo.push_back(st.top()); 
                 st.pop(); 
             }
             return topo; 

         }
      };


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

`Reorder Routes to Make All Paths Lead to the City Zero <https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/>`_
===============================================================================

.. code:: c++

`Minimum Height Trees <https://leetcode.com/problems/minimum-height-trees/description/>`_
===============================================================================

.. code:: c++



