# number : 688

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if (K == 0)
            return 1.0;
        double **dp = new double*[N];
        double **dp2 = new double*[N];
        for (int i = 0; i < N; i++)
        {
            dp[i] = new double[N];
            dp2[i] = new double[N];
            for (int j = 0; j < N; j++)
            {
                dp[i][j] = 0.0;
                dp2[i][j] = 0.0;
            }
        }
        dp[r][c] = 1.0;
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                {
                    for (int m = j - 2; m <= j + 2; m++)
                        for (int n = k - 2; n <= k + 2; n++)
                        {
                            if (isOnBoard(N, m, n) && isMove(j, k, m, n))
                                dp2[m][n] += dp[j][k] / 8.0;
                        }
                }
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                {
                    dp[j][k] = dp2[j][k];
                    dp2[j][k] = 0.0;
                }
            
        }
        double result = 0.0;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                result += dp[j][k];
        return result;
    }
    //判断i，j坐标是否在棋盘上
    bool isOnBoard(int n, int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    //判断i，j坐标与r，c坐标是否互为下棋位
    bool isMove(int r, int c, int i, int j)
    {
        return (abs(i-r) == 2 && abs(j-c) == 1) || (abs(i-r) == 1 && abs(j-c) == 2);
    }
};
