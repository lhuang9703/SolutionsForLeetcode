// Source : https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
// Number : 114
// Author : HL
// Date   : 2018-10-11
// Kill   : 95.10%

/********************************************************************************** 
Given a binary tree, flatten it to a linked list in-place.
For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        
        TreeNode *p = root;
        while (p != NULL)
        {
            if (p->left != NULL)
            {
                TreeNode *lp = p->left;
                while (lp->right != NULL)
                {
                    lp = lp->right;
                }
                lp->right = p->right;
                p->right = p->left;
                p->left = NULL;
            }
            p = p->right;
        }
        
        return;
    }
};
