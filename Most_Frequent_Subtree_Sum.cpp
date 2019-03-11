# number : 508

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        int maxNumber = 0;
        if (root == NULL)
            return result;
        int temp = sumOfNode(root);
        map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
            if (it->second > maxNumber)
                maxNumber = it->second;
        for (it = mp.begin(); it != mp.end(); it++)
            if (it->second == maxNumber)
                result.push_back(it->first);
        return result;
    }
    int sumOfNode(TreeNode* root) {
        int sum = 0;
        if (root->left == NULL && root->right == NULL)
            sum = root->val;
        else if (root->left == NULL)
            sum = sumOfNode(root->right) + root->val;
        else if (root->right == NULL)
            sum = sumOfNode(root->left) + root->val;
        else
            sum = sumOfNode(root->left) + sumOfNode(root->right) + root->val;
        mp[sum] += 1;
        return sum;
    }
private:
    map<int, int> mp;
};
