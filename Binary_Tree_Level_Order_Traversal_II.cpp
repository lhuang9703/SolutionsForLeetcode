// Source : https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
// Number : 107
// Author : HL
// Date   : 2018-09-25
// Kill   : 100.00%

/********************************************************************************** 
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> v;
        queue<TreeNode*> q;
        TreeNode* p;
        int s, i;
        
        if (root == NULL)
            return result;
        
        q.push(root);
        while (!q.empty()) {
            s = q.size();
            for (i = 0; i < s; i++) {
                p = q.front();
                q.pop();
                v.push_back(p->val);
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            result.push_back(v);
            v.clear();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
