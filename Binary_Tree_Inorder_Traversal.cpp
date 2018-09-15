// Source : https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
// Number : 94
// Author : HL
// Date   : 2018-09-15
// Kill   : 100.00%, 100.00%

/********************************************************************************** 
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        // 递归
//         vector<int> result, temp;
//         vector<int>::iterator it;
//         if (root == NULL)
//             return result;
        
//         temp = inorderTraversal(root->left);
//         for (it = temp.begin(); it != temp.end(); it++) {
//             result.push_back(*it);
//         }
//         result.push_back(root->val);
//         temp = inorderTraversal(root->right);
//         for (it = temp.begin(); it != temp.end(); it++) {
//             result.push_back(*it);
//         }
        
//         return result;
        
        // 迭代
        vector<int> result;
        if (root == NULL)
            return result;
        
        stack<TreeNode*> s;
        TreeNode *p = root;
        
        while (p != NULL) {
            s.push(p);
            p = p->left;
        }
        
        while (!s.empty()) {
            p = s.top();
            result.push_back(p->val);
            s.pop();
            p = p->right;
            while(p != NULL) {
                s.push(p);
                p = p->left;
            }
        }
        
        return result;
    }
};
