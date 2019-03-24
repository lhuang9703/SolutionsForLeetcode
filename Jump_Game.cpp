# number : 55

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = (int)nums.size();
        if (length <= 0)
            return false;
        if (length == 1)
            return true;
        int *dp = new int[length];
        memset(dp, 0, sizeof(int) * length);
        dp[0] = 1;
        for (int i = 0; i < length - 1; i++)
        {
            /* 这个坐标从它左边是走不到的 */
            if (dp[i] == 0)
                continue;
            /* 当前坐标能走到终点 */
            if (i + nums[i] >= length - 1)
                return true;
            /* 当前坐标不能走到终点，则把它能走到的地方设为1 */
            else
            {
                int min = length - 1 < i + nums[i] ? length - 1 : i + nums[i];
                for (int j = i + 1; j <= min; j++)
                    dp[j] = 1;
            }
        }
        return false;
    }
};
