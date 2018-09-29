// Source : https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
// Number : 103
// Author : HL
// Date   : 2018-09-29
// Kill   : 98.70%

/********************************************************************************** 
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> v;
        queue<TreeNode*> q;
        TreeNode *p;
        int i, s, level = 0;
        
        if (root == NULL)
            return result;
        
        q.push(root);
        while (!q.empty())
        {
            s = q.size();
            for (i = 0; i < s; i++)
            {
                p = q.front();
                q.pop();
                v.push_back(p->val);
                if (p->left != NULL)
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
            if (level % 2 != 0)
                reverse(v.begin(), v.end());
            level++;
            result.push_back(v);
            v.clear();
        }
        
        return result;
    }
};
