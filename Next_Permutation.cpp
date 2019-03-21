# number : 31

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int index;
        /* 从右往左找第一个非降序的数 */
        for (index = nums.size() - 2; index != -1; index--)
        {
            if (nums[index] < nums[index + 1])
                break;
        }
        /* 降序序列直接按升序排序返回 */
        if (index == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        /* 将找到的数与它右边数中从右往左第一个比它大的数交换 */
        int temp = nums[index];
        for (int i = nums.size() - 1; i > index; i--)
        {
            if (nums[index] < nums[i])
            {
                nums[index] = nums[i];
                nums[i] = temp;
                break;
            }
        }
        sort(nums.begin() + index + 1, nums.end());
        return;
    }
};
