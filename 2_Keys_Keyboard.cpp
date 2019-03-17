# number : 650

class Solution {
public:
    int minSteps(int n) {
        int *dp = new int[n+1];
        memset(dp, 0, sizeof(int) * (n+1));
        for (int i = 2; i <= n; i++)
        {
            //先按质数对待，质数等于本身，若为合数之后会进行更新
            dp[i] = i;
            //minNumber保存当为合数时通过其各因数得来的次数最小值
            int minNumber = INT_MAX;
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    if (j + dp[i/j] < minNumber)
                        minNumber = j + dp[i/j];
                }
            }
            if (minNumber < i)
                dp[i] = minNumber;
        }
        return dp[n];
    }
};
