# number : 238

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1, right = 1, len = nums.size();
        vector<int> result(len, 1);
        for (int i = 0; i < len; i++) {
            result[i] = left;
            left *= nums[i];
        }
        for (int i = len - 1; i >=0; i--) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};
