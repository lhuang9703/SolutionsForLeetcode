// Source : https://leetcode-cn.com/problems/add-binary/description/
// Number : 67
// Author : HL
// Date   : 2018-09-15
// Kill   : 89.33%

/********************************************************************************** 
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
**********************************************************************************/

class Solution {
public:
    char addBit(char a, char b) {
        if (flag == 0) {
            if (a == '0' && b == '0')
                return '0';
            else if (a == '1' && b == '1') {
                flag = 1;
                return '0';
            }
            else
                return '1';
        } else if (flag == 1) {
            if (a == '0' && b == '0') {
                flag = 0;
                return '1';
            }
            else if (a == '1' && b == '1') {
                return '1';
            } 
            else {
                return '0';
            }
        }
    }

    string addBinary(string a, string b) {
        stack<char> sa, sb;
        string result = "";
        for (int i = 0; i < (int)a.size(); i++)
            sa.push(a[i]);
        for (int i = 0; i < (int)b.size(); i++)
            sb.push(b[i]);
        
        char c,d;
        while ((!sa.empty()) && (!sb.empty())) {
            c = sa.top();
            d = sb.top();
            sa.pop();
            sb.pop();
            result += addBit(c, d);
        }
        if (sa.empty() && (!sb.empty())) {
            while(!sb.empty()) {
                d = sb.top();
                sb.pop();
                result += addBit(d, '0');
            }
        } else if (sb.empty() && (!sa.empty())) {
            while (!sa.empty()) {
                c = sa.top();
                sa.pop();
                result += addBit(c, '0');
            }
        }
        if (flag == 1)
            result += '1';
        
        string re = "";
        int n = (int)result.size();
        for (int i = n-1; i >= 0; i--) {
            re += result[i];
        }
        
        return re;
    }
private:
    int flag = 0;
};
