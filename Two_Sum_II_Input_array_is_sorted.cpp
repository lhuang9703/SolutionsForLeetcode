// Source : https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
// Number : 167
// Author : HL
// Date   : 2018-09-03
// Kill   : 100.00%

/********************************************************************************** 
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
**********************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0,j = (int)numbers.size() - 1;
        while(i < j){
            if(numbers[i] + numbers[j] == target)
                break;
            else if(numbers[i] + numbers[j] < target)
                i++;
            else
                j--;
        }
        vector<int> result;
        result.push_back(i+1);
        result.push_back(j+1);
        return result;
    }
};
