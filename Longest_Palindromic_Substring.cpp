// Source : https://leetcode-cn.com/problems/longest-palindromic-substring/description/
// Number : 5
// Author : HL
// Date   : 2018-09-17
// Kill   : 36.54%

/********************************************************************************** 
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"
**********************************************************************************/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size(), start = 0, maxLength = 1, i, j;
        vector<vector<int>> v(n, vector<int>(n, 0));
        
        if (n <= 1)
            return s;
        
        for (i = 0; i < n; i++) {
            v[i][i] = 1;
            if (i + 1 < n && s[i] == s[i + 1]) {
                v[i][i + 1] = 1;
                start = i;
                maxLength = 2;
            }
        }
        
        for (i = n - 1; i >= 0; i--) {
            for (j = i + 2; j < n; j++) {
                if (v[i + 1][j - 1] == 1 && s[i] == s[j]) {
                    v[i][j] = 1;
                    if (j - i + 1 > maxLength) {
                        start = i;
                        maxLength = j - i + 1;
                    }
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};
