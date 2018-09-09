// Source : https://leetcode-cn.com/problems/count-primes/description/
// Number : 204
// Author : HL
// Date   : 2018-09-09
// Kill   : 21.53%，86.60%

/********************************************************************************** 
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
**********************************************************************************/

class Solution {
public:
    int countPrimes(int n) {
        // 隔数判断法
        // if(n <= 2)
        //     return 0;
        // else if(n == 3)
        //     return 1;
        // else{
        //     int count = 0,k,t;
        //     for(k=3; k<n ; k+=2){
        //         count++;
        //         for(t=3; t<=sqrt(k); t+=2)
        //             if(k%t == 0){
        //                 count--;
        //                 break;
        //             }
        //     }
        //     return count+1;//把2这个质数加进去
        // }
        
        // 厄拉多塞筛法
        bool *arr = new bool[n];
        arr[1] = false;
        arr[2] = true;
        int i,j;
        for(i=3; i<n; i++){
            if(i%2 == 0)
                arr[i] =false;
            else
                arr[i] = true;
        }
        for(i=3; i<n; i+=2){
            if(arr[i]){
                for(j=2; i*j<n; j++)
                    arr[i*j] = false;
            }
        }
        int count = 0;
        for(i=1; i<n; i++)
            if(arr[i])
                count++;
        delete arr;
        return count;
    }
};
