// Source : https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
// Number : 124
// Author : HL
// Date   : 2018-09-16
// Kill   : 3.33%

/********************************************************************************** 
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
    int maxDownPath(TreeNode* root) {
        if (root == NULL)
            return 0;
        int result = root->val;
        int temp = max(maxDownPath(root->left), maxDownPath(root->right));
        if (temp > 0)
            result += temp;
        return result;
    }
    
    int maxCrossPath(TreeNode* root) {
        int cross_max = root->val;
        int cross_max_left = maxDownPath(root->left);
        int cross_max_right = maxDownPath(root->right);
        if (cross_max_left > 0)
            cross_max += cross_max_left;
        if (cross_max_right > 0)
            cross_max += cross_max_right;
        return cross_max;
    }
    
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left_max, right_max, cross_max;
        left_max = maxPathSum(root->left);
        right_max = maxPathSum(root->right);
        cross_max = maxCrossPath(root);
        if (root->right == NULL)
            right_max = INT_MIN;
        if (root->left == NULL)
            left_max = INT_MIN;
        
        int temp = max(left_max, right_max);
        return cross_max > temp ? cross_max : temp;
    }
};
