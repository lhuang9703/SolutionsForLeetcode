# number : 120

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = (int)triangle.size();
        if (rows <= 0)
            return 0;
        int index = 0;
        int *dp = new int[rows+1];
        memset(dp, 0, sizeof(int)*(rows+1));
        for (int i = rows - 1; i >= 0; i--)
        {
            int cols = (int)triangle[i].size();
            if (cols <= 0)
                return 0;
            for (int j = 0; j < cols; j++)
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
        }
        return dp[0];
    }
};
