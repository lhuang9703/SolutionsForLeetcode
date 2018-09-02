// Source : https://leetcode-cn.com/problems/symmetric-tree/description/
// Number : 101
// Author : HL
// Date   : 2018-09-02
// Kill   : 100.00%

/********************************************************************************** 
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        else
            return checkNode(root->left,root->right);
    }
    bool checkNode(TreeNode* left,TreeNode* right) {
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL || right == NULL)
            return false;
        else if(left->val == right->val && checkNode(left->left,right->right) && checkNode(left->right,right->left))
            return true;
        else
            return false;
    }
};
