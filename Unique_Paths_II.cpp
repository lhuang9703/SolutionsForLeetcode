# number : 63

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = (int)obstacleGrid.size();
        int m = (int)obstacleGrid[0].size();
        if (m <= 0 || n <= 0)
            return 0;
        long long **dp = new long long*[n];
        for (int i = 0; i < n; i++)
            dp[i] = new long long[m];
        bool colFlag = false, rowFlag = false;
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[0][i] == 0 && colFlag == false)
                dp[0][i] = 1;
            else
            {
                dp[0][i] = 0;
                colFlag = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[i][0] == 0 && rowFlag == false)
                dp[i][0] = 1;
            else
            {
                dp[i][0] = 0;
                rowFlag = true;
            }
            cout<<dp[i][0]<<" ";
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
            {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else
                    dp[i][j] = 0;
            }
        return dp[n-1][m-1];
    }
};
