// Source : https://leetcode-cn.com/problems/unique-binary-search-trees/description/
// Number : 96
// Author : HL
// Date   : 2018-09-15
// Kill   : 100.00%

/********************************************************************************** 
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
**********************************************************************************/

class Solution {
public:
    int numTrees(int n) {
        int *arr = new int[n+1];
        arr[0] = 1;
        arr[1] = 1;
        for (int k = 2; k <= n; k++) {
            int temp = 0;
            for (int i = 0; i <= k - 1; i++) {
                temp += arr[i] * arr[k - 1 - i];
            }
            arr[k] = temp;
        }
        
        return arr[n];
    }
};
