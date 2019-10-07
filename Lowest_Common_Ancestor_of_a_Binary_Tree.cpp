# number : 236

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
    deque<TreeNode*> v1, v2;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        dfs(root, p, v1);
        dfs(root, q, v2);
        TreeNode* result = v1.front();
        while (!v1.empty() && !v2.empty()) {
            int t1 = v1.front()->val;
            int t2 = v2.front()->val;
            if (t1 == t2) {
                result = v1.front();
                v1.pop_front();
                v2.pop_front();
            }
            else
                break;
        }
        return result;
    }
    
    bool dfs(TreeNode *root, TreeNode *node, deque<TreeNode*>& v) {
        if (!root)
            return false;
        v.push_back(root);
        if (root == node)
            return true;
        if (dfs(root->left, node, v))
            return true;
        if (dfs(root->right, node, v))
            return true;
        v.pop_back();
        return false;
    }
};
