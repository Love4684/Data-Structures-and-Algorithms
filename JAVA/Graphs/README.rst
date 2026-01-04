 .. contents::
   :local:
   :depth: 3


Clone Graph
==================================

Problem Overview
----------------
Given a reference of a node in a **connected undirected graph**, return a **deep copy**
(clone) of the graph.

Each node contains:
- ``val`` : integer value of the node
- ``neighbors`` : list of connected nodes

Only **one node** (starting node) is provided, but since the graph is connected,
all nodes can be reached from it.

---

Why This Problem Is Tricky
--------------------------
- Graph can contain **cycles**
- Same node can be reached multiple times
- Simple recursion can cause **infinite loop**
- We must ensure **deep copy**, not shallow copy

To solve this safely, we use:
- **Graph traversal (DFS / BFS)**
- **HashMap** to track already cloned nodes

---

Node Definition
---------------
Each node represents a vertex in the graph.

.. code:: java

   class Node {
       public int val;
       public List<Node> neighbors;

       public Node(int val) {
           this.val = val;
           this.neighbors = new ArrayList<>();
       }
   }

Explanation:
- ``val`` → unique identifier of node
- ``neighbors`` → adjacent connected nodes
- ``neighbors`` is initialized to avoid NullPointerException

---

Key Idea (Most Important)
------------------------
We maintain a map:

``Map<OriginalNode, ClonedNode>``

Purpose:
- Avoid cloning same node multiple times
- Prevent infinite recursion in cyclic graphs

---

DFS Approach (Recursive)
------------------------

Algorithm
~~~~~~~~~
1. If node is ``null`` → return ``null``
2. If node already exists in map → return cloned node
3. Create new node (clone)
4. Store mapping (original → clone)
5. Recursively clone all neighbors
6. Return cloned node

Base Conditions
~~~~~~~~~~~~~~~
- ``node == null``
- ``node already present in map`` → recursion stops

DFS Code
~~~~~~~~

.. code:: java

   import java.util.*;

   class Solution {

       private Map<Node, Node> map = new HashMap<>();

       public Node cloneGraph(Node node) {
           if (node == null) return null;

           // Base condition: already cloned
           if (map.containsKey(node)) {
               return map.get(node);
           }

           Node clone = new Node(node.val);
           map.put(node, clone);

           for (Node neighbor : node.neighbors) {
               clone.neighbors.add(cloneGraph(neighbor));
           }

           return clone;
       }
   }

Time & Space Complexity
~~~~~~~~~~~~~~~~~~~~~~~
- Time: ``O(N + E)``
- Space: ``O(N)`` (map + recursion stack)

---

BFS Approach (Queue Based)
--------------------------

When to Use BFS
~~~~~~~~~~~~~~~
- Avoid recursion stack overflow
- Prefer iterative solution
- Level-by-level traversal

Algorithm
~~~~~~~~~
1. Clone starting node
2. Put it in map
3. Push original node into queue
4. While queue is not empty:
   - Pop node
   - For each neighbor:
     - If not cloned → clone and enqueue
     - Add neighbor clone to current clone

BFS Code
~~~~~~~~

.. code:: java

   import java.util.*;

   class SolutionBFS {

       public Node cloneGraph(Node node) {
           if (node == null) return null;

           Map<Node, Node> map = new HashMap<>();
           Queue<Node> queue = new LinkedList<>();

           Node cloneStart = new Node(node.val);
           map.put(node, cloneStart);
           queue.add(node);

           while (!queue.isEmpty()) {
               Node current = queue.poll();

               for (Node neighbor : current.neighbors) {

                   if (!map.containsKey(neighbor)) {
                       map.put(neighbor, new Node(neighbor.val));
                       queue.add(neighbor);
                   }

                   map.get(current).neighbors.add(map.get(neighbor));
               }
           }

           return cloneStart;
       }
   }

Complexity
~~~~~~~~~~
- Time: ``O(N + E)``
- Space: ``O(N)``

---

Example Graph
-------------

Graph structure:

::

   1 -- 2
   |    |
   4 -- 3

Adjacency list:

::

   1 -> [2, 4]
   2 -> [1, 3]
   3 -> [2, 4]
   4 -> [1, 3]

---

Test Input Construction (Java)
------------------------------

.. code:: java

   Node n1 = new Node(1);
   Node n2 = new Node(2);
   Node n3 = new Node(3);
   Node n4 = new Node(4);

   n1.neighbors.add(n2);
   n1.neighbors.add(n4);

   n2.neighbors.add(n1);
   n2.neighbors.add(n3);

   n3.neighbors.add(n2);
   n3.neighbors.add(n4);

   n4.neighbors.add(n1);
   n4.neighbors.add(n3);

   Node cloned = new Solution().cloneGraph(n1);

---

DFS vs BFS Summary
------------------

+----------------+-------------------+
| DFS            | BFS               |
+================+===================+
| Recursion      | Queue             |
+----------------+-------------------+
| Stack based    | Iterative         |
+----------------+-------------------+
| Risk of stack  | Safe for deep     |
| overflow       | graphs            |
+----------------+-------------------+

---

Interview One-Liners
--------------------
- *We use a HashMap to store original to cloned node mapping.*
- *DFS/BFS traversal ensures all nodes are visited exactly once.*
- *The map prevents infinite loops caused by cycles.*

---

Final Takeaway
--------------
Even though only **one node** is provided, the entire graph can be cloned
because the graph is **connected**.

**Core tools:**
- Graph traversal (DFS / BFS)
- HashMap (original → clone)

Once these two are clear, the problem becomes straightforward.
