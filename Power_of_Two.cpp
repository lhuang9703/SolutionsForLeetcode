// Source : https://leetcode-cn.com/problems/power-of-two/description/
// Number : 231
// Author : HL
// Date   : 2018-09-11
// Kill   : 99.53%

/********************************************************************************** 
Given an integer, write a function to determine if it is a power of two.
**********************************************************************************/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=1)
            return n==1 ? true : false;
        while(n>2){
            if(n%2 != 0)
                return false;
            n /= 2;
        }
        return true;
    }
};
