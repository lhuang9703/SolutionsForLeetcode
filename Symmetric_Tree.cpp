// Source : https://leetcode-cn.com/problems/symmetric-tree/description/
// Number : 101
// Author : HL
// Date   : 2018-09-02
// Kill   : 100.00%

/********************************************************************************** 
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        else
            return checkNode(root->left,root->right);
    }
    bool checkNode(TreeNode* left,TreeNode* right) {
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL || right == NULL)
            return false;
        else if(left->val == right->val && checkNode(left->left,right->right) && checkNode(left->right,right->left))
            return true;
        else
            return false;
    }
};


/* 非递归实现，层次遍历树并判断每层是否镜像对称 */
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        stack<TreeNode* > s;
        vector<int> v;
        TreeNode* p = root;
        queue<TreeNode* > q;
        q.push(p);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                p = q.front();
                if (p == NULL)
                    v.push_back(-1);
                else
                    v.push_back(p->val);
                q.pop();
                if (p != NULL)
                {
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            int left = 0, right = v.size() - 1;
            while (left <= right)
            {
                if (v[left] != v[right])
                    return false;
                else
                {
                    left++;
                    right--;
                }
            }
            v.clear();
        }
        return true;
    }
};
