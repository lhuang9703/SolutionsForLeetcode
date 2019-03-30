# number : 106

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorder_length = inorder.size();
        int postorder_length = postorder.size();
        if (inorder_length != postorder_length)
            return NULL;
        return build(0, inorder_length - 1, postorder_length - 1, inorder, postorder);
    }
    TreeNode* build(int in_start, int in_end, int post_start, vector<int>& inorder, vector<int>& postorder) {
        if (in_start > in_end)
            return NULL;
        TreeNode *root = new TreeNode(postorder[post_start]);
        int index;
        for (index = in_start; index <= in_end; index++)
        {
            if (inorder[index] == postorder[post_start])
                break;
        }
        root->left = build(in_start, index - 1, post_start - 1 - (in_end - index), inorder, postorder);
        root->right = build(index + 1, in_end, post_start - 1, inorder, postorder);
        return root;
    }
};
