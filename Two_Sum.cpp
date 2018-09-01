// Source : https://leetcode-cn.com/problems/two-sum/description/
// Number : 1
// Author : HL
// Date   : 2018-08-31
// Kill   : 96.73%

/********************************************************************************** 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**********************************************************************************/

#include<map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        vector<int> result;
        map<int,int> nums_map;
        for(i = 0; i < nums.size(); i++){
            int num_to_find = target - nums[i];
            map<int,int>::iterator it = nums_map.find(num_to_find);
            if(it == nums_map.end()){
                nums_map.insert(pair<int,int>(nums[i],i));
            }
            else{
                result.push_back((*it).second);
                result.push_back(i);
                return result;
            }
            /*int k;
            for(k = i + 1; k < nums.size(); k++)
                if(nums[k] == num_to_find)
                    break;
            if(k != nums.size()){
                result.push_back(i);
                result.push_back(k);
                return result;
            }*/
        } 
    }
};
