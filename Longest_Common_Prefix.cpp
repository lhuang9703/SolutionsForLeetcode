// Source : https://leetcode-cn.com/problems/longest-common-prefix/description/
// Number : 14
// Author : HL
// Date   : 2018-08-31
// Kill   : 15.66%

/********************************************************************************** 
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
**********************************************************************************/

#include<string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string result = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string re = "";
            int j = result.size();
            int k = strs[i].size();
            int lenth = j < k ? j : k;
            for(int t = 0; t < lenth; t++){
                if(result[t] == strs[i][t])
                    re += result[t];
                else
                    break;
            }
            result = re;
        }
        return result;
    }
};
