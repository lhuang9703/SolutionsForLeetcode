# number : 647

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        int length = (int)s.size();
        if (length == 0)
            return result;
        int **dp = new int*[length];
        for (int i = 0; i < length; i++)
            dp[i] = new int[length];
        for (int i = 0; i < length; i++)
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = 0;
                if (i == j)
                {
                    dp[i][j] = 1;
                    result += 1;
                }
                else if (i - j == 1 && s[i] == s[j])
                {
                    dp[i][j] = 1;
                    result += 1;
                }
                else if (s[i] == s[j] && dp[i-1][j+1] == 1)
                {
                    dp[i][j] = 1;
                    result += 1;
                }
            }
        return result;
    }
};
