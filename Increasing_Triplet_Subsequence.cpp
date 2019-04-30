# number : 334

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int length = (int)nums.size();
        if (length < 3) { return false; }
        int min_so_far = INT_MAX, sec_min_so_far = INT_MAX;
        for (auto i : nums) {
            if (i <= min_so_far) { min_so_far = i; }
            else if (i <= sec_min_so_far)    { sec_min_so_far = i; }
            else { return true; }
        }
        return false;
    }
};
