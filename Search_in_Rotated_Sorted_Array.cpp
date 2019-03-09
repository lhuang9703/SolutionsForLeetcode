# number:33

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        if (length == 0)
            return -1;
        int start = 0, end = length - 1;
        int result = -1;
        while (start <= end)
        {
            int middle = (start + end) / 2;
            if (nums[middle] == target)
            {
                result = middle;
                break;
            }
            if (nums[middle] >= nums[start])
            {
                if (nums[start] <= target && nums[middle] >= target)
                    end = middle;
                else
                    start = middle + 1;
            }
            else
            {
                if (nums[middle] <= target && nums[end] >= target)
                    start = middle;
                else
                    end = middle - 1;
            }
        }
        return result;
    }
};
