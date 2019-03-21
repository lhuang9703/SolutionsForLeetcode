# number : 34

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.size() <= 0)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int left = binarySearchFirst(nums, target);
        int right = binarySearchLast(nums, target);
        result.push_back(left);
        result.push_back(right);
        return result;
    }
    int binarySearchFirst(vector<int> &nums, int target) {
        int left_index = 0, right_index = nums.size() - 1;
        while (left_index < right_index)
        {
            int middle_index = (left_index + right_index) / 2;
            if (nums[middle_index] < target)
                left_index = middle_index + 1;
            else if (nums[middle_index] > target)
                right_index = middle_index - 1;
            else if (nums[middle_index] == target)
            {
                if (middle_index == 0 || nums[middle_index - 1] < target)
                    return middle_index;
                else
                    right_index = middle_index - 1;
            }
        }
        if (left_index == right_index && nums[left_index] == target)
            return left_index;
        else
            return -1;
    }
    int binarySearchLast(vector<int> &nums, int target) {
        int left_index = 0, right_index = nums.size() - 1;
        while (left_index < right_index)
        {
            int middle_index = (left_index + right_index) / 2;
            if (nums[middle_index] < target)
                left_index = middle_index + 1;
            else if (nums[middle_index] > target)
                right_index = middle_index - 1;
            else if (nums[middle_index] == target)
            {
                if (middle_index == nums.size() - 1 || nums[middle_index + 1] > target)
                    return middle_index;
                else
                    left_index = middle_index + 1;
            }
        }
        if (left_index == right_index && nums[left_index] == target)
            return left_index;
        else
            return -1;
    }
};
