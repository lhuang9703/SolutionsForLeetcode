// Source : https://leetcode-cn.com/problems/3sum/description/
// Number : 15
// Author : HL
// Date   : 2018-10-16
// Kill   : 70.38%

/********************************************************************************** 
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
**********************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> s;
        vector<int> v;
        int n = INT_MAX, target;
        
        if ((int)nums.size() < 3)
            return result;
        
        sort(nums.begin(),nums.end());
        vector<int>::iterator it, it1, it2;
        
        for (it = nums.begin(); it != nums.end() - 2; it++)
        {
            if (*it == n)
                continue;
            else
            {
                n = *it;
                v.push_back(*it);
            }
            target = 0 - *it;
            it1 = it + 1;
            it2 = nums.end() - 1;
            while (it1 < it2)
            {
                if (*it1 + *it2 < target)
                    it1++;
                else if (*it1 + *it2 > target)
                    it2--;
                else
                {
                    v.push_back(*it1);
                    v.push_back(*it2);
                    s.insert(v);
                    v.pop_back();
                    v.pop_back();
                    it1++;
                    it2--;
                }
            }
            v.pop_back();
        }
        
        set<vector<int>>::iterator its;
        for (its = s.begin(); its != s.end(); its++)
            result.push_back(*its);
        
        return result;
    }
};
