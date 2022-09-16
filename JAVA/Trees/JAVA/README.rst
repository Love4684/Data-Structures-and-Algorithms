

.. contents::
   :local:
   :depth: 3
   
   


Tree Traversals (Inorder, Preorder and Postorder)
===============================================================================

.. code:: JAVA

		import java.io.*;
		class JavaProgramming
		{	
		 static class Node
		{
		    int data;
		    Node left, right;
		    Node(int data)
		    {
			this.data = data;
			left = right = null;
		    }
		}
			static void inOrder(Node root) {
				if(root == null) return;

				inOrder(root.left);
				System.out.print(root.data+" ");
				inOrder(root.right);
			}

			static void preOrder(Node root) {
				if(root == null) return;
				System.out.print(root.data+" ");
				preOrder(root.left);
				preOrder(root.right);
			}

			static void postOrder(Node root) {
				if(root == null) return;

				postOrder(root.left);
				postOrder(root.right);
				System.out.print(root.data+" ");
			}

		      /*
			     1
			    /  \
			   2     3
			  / \   / \  
			 4   5 6   7

			 pre = NLR = 1 2 4 5 3 6 7
			 ino = LNR = 4 2 5 1 6 3 7
			 pos = LRN = 4 5 2 6 7 3 1
		      */

		public static void main(String args[])
		{
		    Node root = new Node(1);
		    root.left = new Node(2);
		    root.left.left = new Node(4);
		    root.left.right = new Node(5);
		    root.right = new Node(3);
		    root.right.left = new Node(6);
		    root.right.right = new Node(7);

			System.out.print("preorder : ");
			preOrder(root);
			System.out.print('\n' + "inOrder : ");
			inOrder(root);
			System.out.print('\n' +"postOrder : ");
			postOrder(root);      
		}					
		}



`Search a node in Binary Tree <https://www.geeksforgeeks.org/search-a-node-in-binary-tree/>`_
===============================================================================

.. code:: JAVA      

      import java.io.*;
      class JavaProgramming
      {	
       static class Node
      {
          int data;
          Node left, right;
          Node(int data)
          {
              this.data = data;
              left = right = null;
          }
      }
      static boolean ifNodeExists( Node node, int key)
      {
          if (node == null)
              return false;

          if (node.data == key)
              return true;

          boolean res1 = ifNodeExists(node.left, key);

          if(res1) return true;

          boolean res2 = ifNodeExists(node.right, key);

          return res2;
      }

      public static void main(String args[])
      {
          Node root = new Node(0);
          root.left = new Node(1);
          root.left.left = new Node(3);
          root.left.left.left = new Node(7);
          root.left.right = new Node(4);
          root.left.right.left = new Node(8);
          root.left.right.right = new Node(9);
          root.right = new Node(2);
          root.right.left = new Node(5);
          root.right.right = new Node(6);

          int key = 10;

          if (ifNodeExists(root, key))
              System.out.println("YES");
          else
              System.out.println("NO");
      }					
      }


      

`Maximum Depth of Binary Tree <https://leetcode.com/problems/maximum-depth-of-binary-tree/>`_
===============================================================================

.. code:: c++

    public int maxDepth(TreeNode root) {
        if(root==null) return 0;
        int maxLeft = maxDepth(root.left);
        int maxRight = maxDepth(root.right);
        return Math.max(maxLeft, maxRight)+1;
    }


`Binary Tree Level Order Traversal <https://leetcode.com/problems/binary-tree-level-order-traversal/>`_
===============================================================================

.. code:: c++

      class Solution {
      public:
          vector<vector<int>> levelOrder(TreeNode* root) {
              vector<vector<int>> ans; 
              if(root == NULL) return ans; 
              queue<TreeNode*> q; 
              q.push(root); 
              while(!q.empty()) {
                  int size = q.size();
                  vector<int> level; 
                  for(int i = 0;i<size;i++) {
                      TreeNode *node = q.front(); 
                      q.pop(); 
                      if(node->left != NULL) q.push(node->left); 
                      if(node->right != NULL) q.push(node->right); 
                      level.push_back(node->val); 
                  }
                  ans.push_back(level); 
              }
              return ans; 
          }
      };

`Binary Tree Zigzag Level Order Traversal <https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/>`_
===============================================================================

.. code:: c++

      class Solution {
      public:
      vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
              if (!root) return {};
              queue<TreeNode*> q;
              vector<vector<int> > ans;
              bool direction = false;
              q.push(root);
              while(!q.empty()) {
                  int sz = q.size();
                  vector<int> currLevel;
                  for (int i = 0 ; i < sz ; i++) {
                      TreeNode *currNode = q.front();
                      q.pop();
                      currLevel.push_back(currNode->val);
                      if (currNode->left) q.push(currNode->left);
                      if (currNode->right) q.push(currNode->right);
                  }
                  if (direction) {
                          reverse(currLevel.begin(),currLevel.end());
                  }
                  direction = !direction;
                  ans.push_back(currLevel);
              }
              return ans;
          }
      };

`Same Tree <https://leetcode.com/problems/same-tree/>`_
===============================================================================

.. code:: c++

      class Solution {
      public:
          bool isSameTree(TreeNode* p, TreeNode* q) {
              if(p==NULL && q==NULL)
                  return true;
              if(p==NULL || q==NULL)
                  return false;
              return ( p->val == q->val  && 
                       isSameTree( p->left, q->left ) && 
                       isSameTree( p->right, q->right )  );
          }
      };
      
`Subtree of Another Tree <https://leetcode.com/problems/subtree-of-another-tree/>`_
===============================================================================

.. code:: c++      
      
      public:
          bool isSameTree(TreeNode* p, TreeNode* q) {
              if(p==NULL && q==NULL)
                  return true;
              if(p==NULL || q==NULL)
                  return false;
              return ( p->val == q->val  &&
                               isSameTree( p->left, q->left ) &&
                               isSameTree( p->right, q->right )  );
          }
          bool isSubtree(TreeNode* root, TreeNode* subRoot) {
              if (!root) return false; // assumption: root is not empty
              return isSameTree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
          }
    

`Path Sum II <https://leetcode.com/problems/path-sum-ii/>`_
===============================================================================

.. code:: c++

      class Solution {
      public:

          void getAllPaths(TreeNode* root, int targetSum, vector<int> &path, vector<vector<int>> &paths){
              if(root==NULL) return;
              path.push_back(root->val);
              if(root->left==NULL and root->right==NULL and targetSum == root->val){
                  paths.push_back(path);
              }
              getAllPaths(root->left,targetSum-root->val, path, paths);
              getAllPaths(root->right,targetSum-root->val, path, paths);
              path.pop_back();
          }

          vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
              vector<vector<int>> paths;
              vector<int> path;
              getAllPaths(root, targetSum, path, paths);
              return paths;
          }
      };
      
      
      

`Binary Tree Longest Consecutive Sequence <https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/>`_
===============================================================================

.. code:: c++


`Binary Tree Maximum Path Sum <https://leetcode.com/problems/binary-tree-maximum-path-sum/>`_
===============================================================================

.. code:: c++


`Construct Binary Tree from Preorder and Inorder Traversal <https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/>`_
===============================================================================

.. code:: c++


`Populating Next Right Pointers in Each Node <https://leetcode.com/problems/populating-next-right-pointers-in-each-node/>`_
===============================================================================

.. code:: c++




Image of binary tree
=====================

.. code:: c++

      class Solution {
          void swap(TreeNode *curr)
          {
              if(!curr)
                  return;
              swap(curr->left);
              swap(curr->right);
              TreeNode *temp;
              temp = curr->left;
              curr->left = curr->right;
              curr->right = temp;
          }
      public:
          TreeNode* invertTree(TreeNode* root) {
              swap(root);     //Creates mirror image
              return root;
          }
      };

check bst or not
=====================

.. code:: c++

          public:
          bool check(TreeNode*root,long min,long max){
                if(root==NULL){
                    return true;
                }
                if(root->val<=min or root->val>=max){
                    return false;
                }
                return check(root->left,min,root->val) and check(root->right,root->val,max);
         }

          bool isValidBST(TreeNode* root) {
                 return check(root,LONG_MIN,LONG_MAX);
          }


`Time Needed to Inform All Employees <https://leetcode.com/problems/time-needed-to-inform-all-employees/>`_
=====================

.. code:: c++
