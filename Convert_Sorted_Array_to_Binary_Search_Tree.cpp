// Source : https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
// Number : 108
// Author : HL
// Date   : 2018-09-25
// Kill   : 98.98%

/********************************************************************************** 
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = (int)nums.size();
        TreeNode *p, *l, *r;
        
        if (len == 0)
            return NULL;
        
        p = new TreeNode(nums[len/2]);
        vector<int> nums1(nums.begin(), nums.begin() + len / 2);
        l = sortedArrayToBST(nums1);
        vector<int> nums2(nums.begin() + len / 2 + 1, nums.end());
        r = sortedArrayToBST(nums2);
        p->left = l;
        p->right = r;
        
        return p;
    }
};
