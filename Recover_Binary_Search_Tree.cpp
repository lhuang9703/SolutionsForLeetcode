// Source : https://leetcode-cn.com/problems/recover-binary-search-tree/description/
// Number : 99
// Author : HL
// Date   : 2018-09-15
// Kill   : 69.83%

/********************************************************************************** 
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        
        stack<TreeNode*> s;
        TreeNode *p = root;
        
        while (p != NULL) {
            s.push(p);
            p = p->left;
        }
        
        while (!s.empty()) {
            p = s.top();
            mp[p->val] = p;
            result.push_back(p->val);
            s.pop();
            p = p->right;
            while(p != NULL) {
                s.push(p);
                p = p->left;
            }
        }
        
        return result;
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> v1 = inorderTraversal(root);
        vector<int> v2(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int num1, num2;
        for (int i = 0; i < (int)v1.size(); i++) {
            if (v1[i] != v2[i]) {
                num1 = v1[i];
                num2 = v2[i];
                break;
            }
        }

        TreeNode* p = mp[num1];
        TreeNode* q = mp[num2];
        
        p->val = num2;
        q->val = num1;
        
        return;
    }
private:
    map<int, TreeNode*> mp;
};
