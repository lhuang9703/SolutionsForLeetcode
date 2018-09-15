// Source : https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
// Number : 95
// Author : HL
// Date   : 2018-09-15
// Kill   : 99.28%

/********************************************************************************** 
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> ToGenerateTrees(int begin, int end) {
        vector<TreeNode*> result;
        if (begin > end) {
            result.push_back(NULL);
            return result;
        } else if (begin == end) {
            TreeNode* p = new TreeNode(begin);
            result.push_back(p);
            return result;
        } else {
            for (int i = begin; i <= end; i++) {
                vector<TreeNode*> left = ToGenerateTrees(begin, i - 1);
                vector<TreeNode*> right = ToGenerateTrees(i + 1, end);
                for (int j = 0; j < (int)left.size(); j++) {
                    for (int k = 0; k < (int)right.size(); k++) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        result.push_back(root);
                    }
                }
            }
        }
        
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) {
            vector<TreeNode*> result;
            return result;
        }
        
        return ToGenerateTrees(1, n);
    }
};
