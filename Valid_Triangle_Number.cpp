# number : 611

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = len - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    result += right - left;
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return result;
    }
};
