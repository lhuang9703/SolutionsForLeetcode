// Source : https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/description/
// Number : 230
// Author : HL
// Date   : 2018-11-14
// Kill   : 98.36%

/********************************************************************************** 
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int count = 0, result = -1;
        TreeNode *p = root;
        
        while (p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        
        while (!s.empty())
        {
            p = s.top();
            result = p->val;
            s.pop();
            count += 1;
            if (count == k)
                break;
            else
            {
                if (p->right != NULL)
                {
                    TreeNode *q = p->right;
                    while (q != NULL)
                    {
                        s.push(q);
                        q = q->left;
                    }
                }
            }
        }
        
        return result;
    }
};
