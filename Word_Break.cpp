# number : 139

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int length = (int)s.size();
        int *dp = new int[length];
        memset(dp, 0, sizeof(int)*length);
        for (int i = 0; i < length; i++)
        {
            if (i == 0 || dp[i-1] == 1)
            {
                for (int j = i; j < length; j++)
                {
                    string sub = s.substr(i, j - i + 1);
                    if (find(wordDict.begin(), wordDict.end(), sub) != wordDict.end())
                    {
                        dp[j] = 1;
                    }
                }
            }
        }
        return dp[length-1];
    }
};
