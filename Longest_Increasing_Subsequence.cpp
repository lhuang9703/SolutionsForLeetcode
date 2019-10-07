# number : 300

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = (int)nums.size();
        if (length == 0)
            return 0;
        int *dp = new int[length];
        for (int i = 0; i < length; i++) {
            dp[i] = 1;
        }
        for (int i = length - 1; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int result = dp[0];
        for (auto item = 1; item < length; item++) {
            if (dp[item] > result)
                result = dp[item];
        }
        return result;
    }
};
