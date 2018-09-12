// Source : https://leetcode-cn.com/problems/3sum-closest/description/
// Number : 16
// Author : HL
// Date   : 2018-09-12
// Kill   : 93.91%

/********************************************************************************** 
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
**********************************************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i,length = (int)nums.size(),d = INT_MAX,sum=0;
        for(i=0; i<length-2; i++)
        {
            int *p = &nums[i+1],*q = &nums[length-1];
            while(p < q)
            {
                if(abs(nums[i]+*p+*q-target) < d)
                {
                    d = abs(nums[i]+*p+*q-target);
                    sum = nums[i]+*p+*q;
                }
                if(nums[i]+*p+*q == target)
                    return sum;
                else if(nums[i]+*p+*q < target)
                    p++;
                else
                    q--;
            }
        }
        return sum;
    }
};
