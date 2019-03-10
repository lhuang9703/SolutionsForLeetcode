# number:80

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        int length = nums.size();
        if (length == 0)
            return 0;
        if (length <= 2)
            return length;
        int changeIndex = length - 1;
        for (int i = 2; i <= changeIndex; i++)
        {
            if (nums[i] == nums[i-2])
            {
                int temp = nums[i];
                for (int j = i + 1; j <= changeIndex ; j++)
                    nums[j-1] = nums[j];
                nums[changeIndex--] = temp;
                i--;
            }
        }
        return changeIndex + 1;
    }
};
