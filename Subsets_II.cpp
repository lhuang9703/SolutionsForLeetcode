# number : 90

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> result;
        if (length <= 0)
            return result;
        vector<int> re;
        result.push_back(re);
        for (int i = 0; i < length; i++)
        {
            int size = result.size();
            for (int k = 0; k < size; k++)
            {
                re = result[k];
                re.push_back(nums[i]);
                sort(re.begin(), re.end());
                if (find(result.begin(), result.end(), re) == result.end())
                    result.push_back(re);
            }
        }
        return result;
    }
};
