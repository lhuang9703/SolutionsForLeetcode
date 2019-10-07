# number : 283

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = (int)nums.size();
        int p = 0, q = 0;
        while (nums[p] != 0) {
            p++;
            if (p == length)
                return;
        }
        q = p;
        while (p < length && q < length) {
            while (nums[q] == 0 ) {
                q++;
                if (q == length)
                    return;
            }
            int temp  = nums[p];
            nums[p] = nums[q];
            nums[q] = temp;
            p++;
        }
    }
};
