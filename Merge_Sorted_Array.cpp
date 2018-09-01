// Source : https://leetcode-cn.com/problems/merge-sorted-array/description/
// Number : 88
// Author : HL
// Date   : 2018-09-01
// Kill   : 100.00%

/********************************************************************************** 
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
**********************************************************************************/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        int i = m + n;
        int it1 = m - 1, it2 = n - 1;
        while(it1 >= 0 && it2 >= 0){
            if(nums1[it1] > nums2[it2]){
                nums1[i-1] = nums1[it1];
                it1--;
            }
            else{
                nums1[i-1] = nums2[it2];
                it2--;
            }
            i--;
        }
        if(it1 < 0)
            for(; it2 >= 0; it2--)
                nums1[it2] = nums2[it2];
        return;
    }
};
