// Source : https://leetcode-cn.com/problems/maximum-subarray/description/
// Number : 53
// Author : HL
// Date   : 2018-09-01
// Kill   : 97.44%

/********************************************************************************** 
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
**********************************************************************************/

class Solution {
public:
//     int maxCross(vector<int>& nums){
//         int left_max=-9999,left_sum=0;
//         for(int i = nums.size()/2;i >= 0;i--){
//             left_sum += nums[i];
//             if(left_sum > left_max)
//                 left_max = left_sum;
//         }
//         if(left_max == -9999)
//             left_max = 0;
//         int right_max=-9999,right_sum=0;
//         for(int i = nums.size()/2 + 1;i < nums.size();i++){
//             right_sum += nums[i];
//             if(right_sum > right_max)
//                 right_max = right_sum;
//         }
//         if(right_max == -9999)
//             right_max = 0;
//         if(left_max + right_max <left_max)
//             return left_max;
//         if(left_max + right_max <right_max && right_max != 0)
//             return right_max;
//         return left_max + right_max;
//     }
    
    int maxSubArray(vector<int>& nums) {
        //动态规划解法:O(n)
        int max_sub = nums[0];
        int length = nums.size();
        int* dp = new int[length];
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(dp[i-1] <= 0){
                dp[i] = nums[i];
            }
            else
                dp[i] = dp[i-1] + nums[i];
            if(dp[i] > max_sub){
                max_sub = dp[i];
            }
            
        }
        return max_sub;
        
        //分治解法
        // if(nums.size() == 1)
        //     return nums[0];
        // else{
        //     int mid = nums.size()/2;
        //     vector<int> num_left(mid),num_right(nums.size()-mid);
        //     copy(nums.begin(),nums.begin()+mid,num_left.begin());
        //     copy(nums.begin()+mid,nums.end(),num_right.begin());
        //     int left_max = maxSubArray(num_left);
        //     int right_max = maxSubArray(num_right);
        //     int cross_max = maxCross(nums);
        //     if(left_max > right_max && left_max > cross_max)
        //         return left_max;
        //     else if(right_max > left_max && right_max > cross_max)
        //         return right_max;
        //     else
        //         return cross_max;
        // }
    }
};
