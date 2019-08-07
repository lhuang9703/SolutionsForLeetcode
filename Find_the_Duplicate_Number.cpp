# number : 287

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow_ptr = nums[0], quick_ptr = nums[0];
        do {
            slow_ptr = nums[slow_ptr];
            quick_ptr = nums[quick_ptr];
            quick_ptr = nums[quick_ptr];
        } while (slow_ptr != quick_ptr);
        
        int p = nums[0];
        while (p != slow_ptr) {
            p = nums[p];
            slow_ptr = nums[slow_ptr];
        }
        return p;
    }
};
