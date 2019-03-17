# number : 72

class Solution {
public:
    int minDistance(string word1, string word2) {
        int length1 = (int)word1.size(), length2 = (int)word2.size();
        if (length1 == 0 || word1 == "")
            return length2;
        if (length2 == 0 || word2 == "")
            return length1;
        int **dp = new int*[length1+1];
        for (int i = 0; i < length1 + 1; i++)
            dp[i] = new int[length2+1];
        for (int i = 0; i < length1 + 1; i++)
            for (int j = 0; j < length2 + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = (i == 0 ? j : i);
                else
                    dp[i][j] = 0;
            }
        for (int i = 1; i < length1 + 1; i++)
            for (int j = 1; j < length2 + 1; j++)
            {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = Min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            }
        return dp[length1][length2];
    }
    int Min(int a, int b, int c)
    {
        if (a < b)
            return a < c ? a : c;
        else
            return b < c ? b : c;
    }
};
