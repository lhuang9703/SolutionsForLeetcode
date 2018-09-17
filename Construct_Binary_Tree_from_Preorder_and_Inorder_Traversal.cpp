// Source : https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// Number : 105
// Author : HL
// Date   : 2018-09-17
// Kill   : 87.28%

/********************************************************************************** 
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode* build(int prestart, int instart, int inend, vector<int>& preorder, vector<int>& inorder) {
        if (instart > inend) {
            return NULL;
        }
        TreeNode* p = new TreeNode(preorder[prestart]);
        int index;
        for (index = instart; index != inend; index++) {
            if (inorder[index] == preorder[prestart]) 
                break;
        }
        p->left = build(prestart + 1, instart, index - 1, preorder, inorder);
        p->right = build(index - instart + prestart + 1, index + 1, inend, preorder, inorder);
        return p;
    }
};
