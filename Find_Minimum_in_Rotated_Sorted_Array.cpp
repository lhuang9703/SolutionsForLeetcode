# number : 153

class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = (int)nums.size();
        if (length <= 2)
            return length == 2 ? min(nums[0], nums[1]) : nums[0];
        if (nums[0] < nums[length - 1])
            return nums[0];
        int left = 0, right = length - 1, middle;
        while (left + 1 < right)
        {
            middle = (left + right) / 2;
            if (nums[middle] > nums[left])
                left = middle;
            else
                right = middle;
        }
        return nums[left] > nums[right] ? nums[right] : nums[left];
    }
};
