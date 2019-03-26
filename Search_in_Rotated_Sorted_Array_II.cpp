# number : 81

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int length = (int)nums.size();
        if (length <= 0)
            return false;
        int index = -1;
        for (int i = 0; i < length - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                index = i;
                break;
            }
        }
        cout << index;
        if (index == -1)
            return binarySearch(nums, target);
        else
        {
            vector<int> num1(nums.begin(), nums.begin() + index + 1);
            vector<int> num2(nums.begin() + index + 1, nums.end());
            return (binarySearch(num1, target) || binarySearch(num2, target));
        }
    }
    bool binarySearch(vector<int>& nums, int target) {
        int length = (int)nums.size();
        if (length <= 0)
            return false;
        int low = 0, high = length - 1, middle;
        while (low <= high)
        {
            middle = (low + high) / 2;
            if (nums[middle] == target)
                return true;
            else if (nums[middle] > target)
                high = middle - 1;
            else
                low = middle + 1;
        }
        return false;
    }
};
