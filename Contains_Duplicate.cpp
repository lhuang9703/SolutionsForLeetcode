// Source : https://leetcode-cn.com/problems/contains-duplicate/description/
// Number : 217
// Author : HL
// Date   : 2018-09-11
// Kill   : 46.31%，37.85%

/********************************************************************************** 
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
**********************************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 哈希解法
        // map<int,int> mp;
        // for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++)
        //     mp[*it]++;
        // for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
        //     if(it->second > 1)
        //         return true;
        // return false;
        
        // 集合解法
        set<int> s;
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++)
        {
            if(s.find(*it) != s.end())
                return true;
            else
                s.insert(*it);
        }
        return false;
    }
};
