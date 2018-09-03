// Source : https://leetcode-cn.com/problems/single-number/description/
// Number : 136
// Author : HL
// Date   : 2018-09-03
// Kill   : 97.67%，48.16%

/********************************************************************************** 
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
**********************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 异或解法
        // int result = 0;
        // for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        //     result = result ^ (*it);
        // return result;
        
        // 哈希解法
        map<int,int> mp;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
            mp[(*it)] += 1;
        for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++)
            if((*it).second == 1)
                return (*it).first;
    }
};
