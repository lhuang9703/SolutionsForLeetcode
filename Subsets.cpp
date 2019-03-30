# number : 78

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int length = (int)nums.size();
        vector<int> re;
        result.push_back(re);
        /* 解法一 */ 
        for (int i = 0; i < length; i++)
        {
            int size = result.size();
            for (int j = 0; j < size; j++)
            {
                re = result[j];
                re.push_back(nums[i]);
                result.push_back(re);
            }
        }
        
        /* 解法二：位运算 */
        /*int total_size = pow(2, length);
        int count = 1;
        while (count < total_size)
        {
            for (int i = 0; i < length; i++)
            {
                int k = 1 << i;
                if (k & count)
                {
                    re.push_back(nums[i]);
                }
            }
            result.push_back(re);
            re.clear();
            count++;
        }*/
        return result;
    }
};
