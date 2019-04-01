# number : 209

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int length = (int)nums.size();
        if (length <= 0)
            return 0;
        int left = 0, right = 0;
        int sum = nums[0];
        int result = INT_MAX;
        while (left < length && right < length)
        {
            if (sum >= s)
            {
                result = result < (right - left) + 1 ? result : (right - left) + 1;
                sum -= nums[left++];
            }
            else if (right == length - 1)   {   sum -= nums[left++];    }
            else    {   sum += nums[++right];   }
        }
        if (result != INT_MAX)  /* find sub array */
            return result;
        return 0;
    }
};
