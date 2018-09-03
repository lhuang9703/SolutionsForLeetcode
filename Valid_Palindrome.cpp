// Source : https://leetcode-cn.com/problems/valid-palindrome/description/
// Number : 125
// Author : HL
// Date   : 2018-09-03
// Kill   : 97.93%

/********************************************************************************** 
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
**********************************************************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "")
            return true;
        int length = (int)s.size();
        int i = 0, j = length - 1;
        while(i < j){
            if(isalnum(s[i]) && isalnum(s[j])){
                if(tolower(s[i]) == tolower(s[j])){
                    i++;
                    j--;
                    continue;
                }
                else{
                    return false;
                }
            }
            else if(isalnum(s[i]) == false){
                i++;
                continue;
            }
            else if(isalnum(s[j]) == false){
                j--;
                continue;
            }
        }
        return true;
    }
};
