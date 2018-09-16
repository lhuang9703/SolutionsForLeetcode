// Source : https://leetcode-cn.com/problems/trapping-rain-water/description/
// Number : 42
// Author : HL
// Date   : 2018-09-16
// Kill   : 96.87%

/********************************************************************************** 
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
**********************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        if ((int)height.size() <= 2)
            return 0;
        int result = 0, left = 1, right = (int)height.size() - 2;
        int max_left = height[0], max_right = height[right + 1];
        while (left <= right) {
            if (max_left <= max_right) {
                if (height[left] >= max_left) {
                    max_left = height[left];
                } else {
                    result += max_left - height[left];
                }
                left++;
            } else {
                if (height[right] >= max_right) {
                    max_right = height[right];
                } else {
                    result += max_right - height[right];
                }
                right--;
            }
        }
        
        return result;
    }
};
