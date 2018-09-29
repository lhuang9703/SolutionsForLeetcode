// Source : https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
// Number : 102
// Author : HL
// Date   : 2018-09-29
// Kill   : 99.93%

/********************************************************************************** 
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> v;
        vector<TreeNode*> vTreeNode;
        vector<TreeNode*>::iterator it;
        queue<TreeNode*> q;
        TreeNode *p;
        
        if (root == NULL)
            return result;
        
        vTreeNode.push_back(root);
        while (!vTreeNode.empty())
        {
            for (it = vTreeNode.begin(); it != vTreeNode.end(); it++)
            {
                q.push(*it);
            }
            vTreeNode.clear();
            while (!q.empty())
            {
                p = q.front();
                q.pop();
                v.push_back(p->val);
                if (p->left != NULL)
                    vTreeNode.push_back(p->left);
                if (p->right != NULL)
                    vTreeNode.push_back(p->right);
            }
            result.push_back(v);
            v.clear();
        }
        
        return result;
    }
};
