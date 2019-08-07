# number : 228

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int len = nums.size();
        if (len < 1)
            return result;
        if (len == 1) {
            result.push_back(to_string(nums[0]));
            return result;
        }
        int start = 0, end = start + 1;
        while (start != len && end != len) {
            if (nums[end] - 1 == nums[end-1]) {
                end++;
            }
            else {
                if (start != end - 1)
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[end - 1]));
                else 
                    result.push_back(to_string(nums[end - 1]));
                start = end++;
            }
        }
        if (start != end - 1)
            result.push_back(to_string(nums[start]) + "->" + to_string(nums[end - 1]));
        else 
            result.push_back(to_string(nums[end - 1]));
        return result;
    }
};
