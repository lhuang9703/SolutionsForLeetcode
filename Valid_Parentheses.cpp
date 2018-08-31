// Source : https://leetcode-cn.com/problems/valid-parentheses/description/
// Number : 20
// Author : HL
// Date   : 2018-08-31
// Kill   : 84.36%

/********************************************************************************** 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
**********************************************************************************/

class Solution {
public:
    bool isValid(string s) {
        if(s == "")
            return true;
        else if(s.size() % 2 != 0)
            return false;
        else{
            stack<char> sta;
            for(int i = 0; i < s.size(); i++){
                switch(s[i]){
                    case '(':
                        sta.push(s[i]);
                        break;
                    case '[':
                        sta.push(s[i]);
                        break;
                    case '{':
                        sta.push(s[i]);
                        break;
                    case ')':
                        if(sta.empty())
                            return false;
                        if(sta.top() == '('){
                            sta.pop();
                            break;
                        }
                        else
                            return false;
                    case ']':
                        if(sta.empty())
                            return false;
                        if(sta.top() == '['){
                            sta.pop();
                            break;
                        }
                        else
                            return false;
                    case '}':
                        if(sta.empty())
                            return false;
                        if(sta.top() == '{'){
                            sta.pop();
                            break;
                        }
                        else
                            return false;
                }
            }
            if(sta.empty())
                return true;
            else
                return false;
        }
    }
};
