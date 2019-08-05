# number : 46

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> v1;
        vector<int> mark;
        int len = nums.size();
        permute2(nums, result, v1, mark, len);
        return result;
    }
    void permute2(vector<int>& nums, 
                  vector<vector<int> >& result, 
                  vector<int>& v1, 
                  vector<int>& mark, 
                  int len) {
        if (v1.size() == len) {
            result.push_back(v1);
            v1.pop_back();
            return;
        }
        for (int i = 0; i < len; i++) {
            if (find(mark.begin(), mark.end(), i) == mark.end()) {
                mark.push_back(i);
                v1.push_back(nums[i]);
                permute2(nums, result, v1, mark, len);
                mark.pop_back();
            }
        }
        v1.pop_back();
    }
};
