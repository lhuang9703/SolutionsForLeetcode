// Source : https://leetcode-cn.com/problems/invert-binary-tree/description/
// Number : 226
// Author : HL
// Date   : 2018-11-14
// Kill   : 100.00%

/********************************************************************************** 
Invert a binary tree.

Example:
Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1
**********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        
        TreeNode *p, *q;
        p = root->left;
        q = root->right;
        root->right = p;
        root->left = q;
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
