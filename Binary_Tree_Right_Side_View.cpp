# number : 199

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
    vector<int> result;
    
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            result.push_back(q.back()->val);
            int len = (int)q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left) { q.push(p->left); }
                if (p->right) { q.push(p->right); }
            }
        }
        return result;
    }
};
