# number : 47

class Solution {
public:
    vector<vector<int> > result;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        permute2(nums, 0, len - 1);
        return result;
    }

    void permute2(vector<int> nums, 
                  int start, int end) {
        if (start == end) {
            result.push_back(nums);
            return;
        } 
        else {
            for (int i = start; i <= end; i++) {
                if (i != start && nums[i] == nums[start])
                    continue;
                swap(nums[i], nums[start]);
                permute2(nums, start + 1, end);
            }
        }
    }
};
