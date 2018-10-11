
// Source : https://leetcode-cn.com/problems/path-sum-ii/description/
// Number : 113
// Author : HL
// Date   : 2018-10-11
// Kill   : 99.74%

/********************************************************************************** 
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        DFS(root, sum);
        
        return result;
    }
    
    void DFS(TreeNode* root, int sum) {
        if (!root)
            return;
        
        v.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (root->val == sum)
            {
                result.push_back(v);
            }
            v.pop_back();
            return;
        }
        int newSum = sum - root->val;
        DFS(root->left, newSum);
        DFS(root->right, newSum);
        v.pop_back();
        
        return;
    }
private:
    vector<vector<int>> result;
    vector<int> v;
};
