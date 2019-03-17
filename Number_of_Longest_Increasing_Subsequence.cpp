# number : 673

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int length = (int)nums.size();
        if (length <= 0)
            return 0;
        //dp[i]记录截止到下标i的最长递增子序列的序列长度
        int *dp = new int[length];
        //dp2[i]记录截止到下标i的最长递增子序列的序列个数
        int *dp2 = new int[length];
        int max = 1;
        for (int i = 0; i < length; i++)
        {
            dp[i] = 1;
            dp2[i] = 1;
        }
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        max = dp[i] > max ? dp[i] : max;
                        dp2[i] = dp2[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                        dp2[i] += dp2[j];
                }
            }
        }
        int result = 0;
        for (int i = 0; i < length; i++)
            if (dp[i] == max)
                result += dp2[i];
        return result;
    }
};
