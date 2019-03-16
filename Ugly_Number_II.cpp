# number : 264

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)
            return 0;
        int *dp = new int[n];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++)
        {
            int minNumber = Min(dp[p2] * 2, dp[p3] * 3, dp[p5] * 5);
            dp[i] = minNumber;
            if (dp[p2] * 2 == minNumber)
                p2++;
            if (dp[p3] * 3 == minNumber)
                p3++;
            if (dp[p5] * 5 == minNumber)
                p5++;
        }
        return dp[n-1];
    }
    int Min(int a, int b, int c)
    {
        if (a < b)
            return a < c ? a : c;
        else
            return b < c ? b : c;
    }
};
