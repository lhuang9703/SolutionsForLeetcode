# number : 75

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = (int)nums.size();
        if (length <= 0)
            return;
        int left = 0, right = length - 1, current = 0;
        while (current <= right)
        {
            if (nums[current] == 2)
            {
                swap(current, right, nums);
                right--;
            }
            else if (nums[current] == 0 && left < current)
            {
                swap(current, left, nums);
                left++;
            }
            else     
                current++;
        }
    }
    void swap(int i, int j, vector<int>& nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};
