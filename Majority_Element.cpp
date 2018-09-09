// Source : https://leetcode-cn.com/problems/majority-element/description/
// Number : 169
// Author : HL
// Date   : 2018-09-09
// Kill   : 98.11%

/********************************************************************************** 
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
**********************************************************************************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,result;
        map<int,int> mp;
        for(int i=0; i<(int)nums.size();i++)
            mp[nums[i]]+=1;
        for(map<int,int>::iterator it=mp.begin(); it!=mp.end();it++)
            if((*it).second>count){
                result=(*it).first;
                count=(*it).second;
            }
        return result;
    }
};
