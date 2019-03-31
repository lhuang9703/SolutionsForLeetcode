# number : 162

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        int length = (int)nums.size();
        int left = 0, right = length - 1, middle;
        while (left + 1< right)
        {
            middle = (left + right) / 2;
            if (nums[middle-1] <= nums[middle] && nums[middle+1] <= nums[middle])
                return middle - 1;
            else if (nums[middle-1] > nums[middle])
                right = middle;
            else
                left = middle;       
        }
        return nums[left] > nums[right] ? left : right;
    }
};
