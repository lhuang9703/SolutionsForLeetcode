// Source : https://leetcode-cn.com/problems/count-and-say/description/
// Number : 38
// Author : HL
// Date   : 2018-08-31
// Kill   : 74.66%

/********************************************************************************** 
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
**********************************************************************************/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        else{
            string re = countAndSay(n-1);
            string result = "";
            int count = 1;
            char num = re[0];
            for(int i = 1; i < re.size(); i++){
                if(num != re[i]){
                    result += to_string(count);
                    result += num;
                    num = re[i];
                    count = 1;
                }
                else
                    count++;
            }
            result += to_string(count);
            result += num;
            return result;
        }
    }
};
