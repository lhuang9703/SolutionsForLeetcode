# number : 18

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> result;
        set <vector<int>> s;
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                int i_j_sum = nums[i] + nums[j];
                int leftIndex = j + 1, rightIndex = nums.size() - 1;
                while (leftIndex < rightIndex)
                {
                    vector<int> v;
                    if (i_j_sum + nums[leftIndex] + nums[rightIndex] == target)
                    {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[leftIndex]);
                        v.push_back(nums[rightIndex]);
                        s.insert(v);
                        leftIndex++;
                    }
                    else if (i_j_sum + nums[leftIndex] + nums[rightIndex] < target)
                    {
                        leftIndex++;
                    }
                    else
                    {
                        rightIndex--;
                    }
                }
            }
        for (set<vector<int>>::iterator it = s.begin(); it != s.end(); it++)
            result.push_back(*it);
        return result;
    }
};
