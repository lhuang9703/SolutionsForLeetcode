# number : 129

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
    int result = 0;
    
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
    
    void dfs(TreeNode* root, int val) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            result += (val + root->val);
            return;
        }
        else {
            dfs(root->left, (val + root->val) * 10);
            dfs(root->right, (val + root->val) * 10);
            return;
        }
    }
};
