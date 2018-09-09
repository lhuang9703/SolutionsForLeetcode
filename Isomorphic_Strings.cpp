// Source : https://leetcode-cn.com/problems/isomorphic-strings/description/
// Number : 205
// Author : HL
// Date   : 2018-09-09
// Kill   : 99.80%

/********************************************************************************** 
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
**********************************************************************************/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp,mp2;
        for(int i= 0; i<(int)s.size(); i++)
        {
            map<char,char>::iterator it = mp.find(s[i]);
            if(it == mp.end())
            {
                if(mp2.find(t[i]) != mp2.end())
                    return false;
                else
                {
                    mp.insert(pair<char,char>(s[i],t[i]));
                    mp2.insert(pair<char,char>(t[i],s[i]));
                }
            }
            else if(it->second != t[i])
                return false;
            else
                continue;
        }
        return true;
    }
};
