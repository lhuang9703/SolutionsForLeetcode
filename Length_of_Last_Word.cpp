// Source : https://leetcode-cn.com/problems/length-of-last-word/description/
// Number : 58
// Author : HL
// Date   : 2018-09-01
// Kill   : 97.87%

/********************************************************************************** 
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
**********************************************************************************/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int flag = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] != ' ' && flag == 0){
                flag = 1;
                result += 1;
            }
            else if(s[i] != ' ' && flag == 1){
                result += 1;
            }
            else if(s[i] == ' ' && flag == 1)
                break;
        }
        return result;
    }
};
