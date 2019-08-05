# number : 532

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        int result = 0;
        int len = nums.size();
        if (len <= 1)
            return result;
        sort(nums.begin(), nums.end());
        int lastItem = 0;
        for (int i = 0; i < len - 1; i++) {
            if (i != 0 && nums[i] == lastItem)
                continue;
            for (int j = i + 1; j < len; j++) {
                int t = nums[j] - nums[i];
                if (t == k) {
                    result += 1;
                    break;
                }
                if (t > k)
                    break;
            }
            lastItem = nums[i];
        }
        return result;
    }
};
