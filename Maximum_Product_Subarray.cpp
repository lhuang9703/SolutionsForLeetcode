# number : 152

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        int length = (int)nums.size();
        if (length <= 0)
            return 0;
        int *dpMax = new int[length];
        int *dpMin = new int[length];
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        for (int i = 1; i < length; i++)
        {
            int maxP = dpMax[i-1] * nums[i];
            int minP = dpMin[i-1] * nums[i];
            int maxNum = Max(maxP, minP, nums[i]);
            int minNum = Min(maxP, minP, nums[i]);
            dpMax[i] = maxNum;
            dpMin[i] = minNum;
            if (maxNum > result)
                result = maxNum;
        }
        return result > dpMax[0] ? result : dpMax[0];
    }
    int Max(int a, int b, int c)
    {
        if (a > b)
            return a > c ? a : c;
        else
            return b > c ? b : c;
    }
    int Min(int a, int b, int c)
    {
        if (a < b)
            return a < c ? a : c;
        else
            return b < c ? b : c;
    }
};
