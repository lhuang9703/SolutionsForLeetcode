// Source : https://leetcode-cn.com/problems/balanced-binary-tree/description/
// Number : 110
// Author : HL
// Date   : 2018-09-25
// Kill   : 98.20%

/********************************************************************************** 
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
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
    int Max_Depth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(Max_Depth(root->left), Max_Depth(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        if (isBalanced(root->left) &&
            isBalanced(root->right) &&
            abs(Max_Depth(root->left) - Max_Depth(root->right)) <= 1)
            return true;
        else
            return false;
    }
};
