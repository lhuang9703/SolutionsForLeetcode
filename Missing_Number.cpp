// Source : https://leetcode-cn.com/problems/missing-number/description/
// Number : 268
// Author : HL
// Date   : 2018-09-11
// Kill   : 96.88%，96.88%

/********************************************************************************** 
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
**********************************************************************************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 常规解法
        // int n = (int)nums.size();
        // int expectSum = ((n+1)*n)/2;
        // int actualSum = 0;
        // for(int i=0; i<n; i++)
        //     actualSum += nums[i];
        // return expectSum - actualSum;
        
        // 异或解法
        int n = (int)nums.size();
        int x=0, y=0;
        for(int i=0; i<n; i++)
            x ^= nums[i];
        for(int i=0; i<=n; i++)
            y ^= i;
        return x ^ y;
    }
};
