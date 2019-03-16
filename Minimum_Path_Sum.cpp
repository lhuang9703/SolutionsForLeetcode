# number : 64

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        if (n <= 0 || m <= 0)
            return 0;
        int **dp = new int*[n+1];
        for (int i = 0; i < n+1; i++)
            dp[i] = new int[m+1];
        for (int i = 0; i < n+1; i++)
            for (int j = 0; j < m+1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (i == 1 || j == 1)
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        return dp[n][m];
    }
};
