/*Count Complete Tree Nodes

Solution
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Solution 1: Using the property of complete binary tree.
/*Introduction to complete binary tree
A CBT is a tree which is atleast filled completely upto N-1 levels and at
the last level the nodes are filled as much as it can from left to right.
Some CBTs are perfect binary tree as well that is they are completely filled in the last level 
as well.
*/

/*Approach here:
there are two cases:
case 1:It is a PBT;
So for that we will check left and right level count if they are equal then count will 
be 2^left_count -1;

case 2: else if it is a cbt then count will be achieved by 
recursively calling

1+countNodes(root->left) + countNodes(root->right);
so here we are going to each node and checking for the two cases
and then value is returned to current node and we add 1 because we have to add current node as well.
*/

/*
Time Complexity:
here it will be O(log2(2n+1)*log(n+1))
which is O(logN * logN)
Total nodes - (2N+1)
Internal nodes - N
leaf nodes - N+1
total levels = log2(2n+1)
*/

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
public:
    int countNodes(TreeNode* root) {
            if(!root)
                    return 0;
            TreeNode *l = root->left;
            TreeNode *r = root->right;
            int left_count = 1;
            int right_count = 1;
            while(l)
            {
                    l = l->left;
                    left_count++;
            }
            while(r)
            {
                    r = r->right;
                    right_count++;
            }
            
            if(left_count==right_count)
            {
                    return pow(2,left_count) -1;
            }
            
            return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};



//Solution 2 : Using post order traversal and count variable.
//Time complexity : O(n);
class Solution {
        
public:
    int countNodes(TreeNode* root) {
            //vector<int> v1;
           int count = 0;
            postOrder(root,count);
            return count;
    }
        
private:
        void postOrder(TreeNode* root,int& v1)
        {
                if(root==NULL)
                        return;
                postOrder(root->left,v1);
                postOrder(root->right,v1);
                v1++;
        }
        
        
};