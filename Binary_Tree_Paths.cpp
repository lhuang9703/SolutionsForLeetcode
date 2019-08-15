# number : 257

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
    vector<string> result;
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return result;
        dfs(root, "");
        return result;
    }
    
    void dfs(TreeNode* root, string s) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            s += "->" + to_string(root->val);
            result.push_back(s.substr(2));
        }
        dfs(root->left, s + "->" + to_string(root->val));
        dfs(root->right, s + "->" + to_string(root->val));
    }
};
