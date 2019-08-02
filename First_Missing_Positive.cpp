# number : 41

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) { // 第一遍遍历，为每个正数找到正确的位置
            if (nums[i] > 0 && nums[i] <= len && nums[i] != i + 1) {
                if (nums[i] != nums[nums[i] - 1]) {
                    int tmp = nums[i];
                    nums[i] = nums[nums[i] - 1];
                    nums[tmp - 1] = tmp;
                    i--;
                }
                else { // 如果该数对应的位置上已经有了正确的数，则忽略该数，将其置为非正数
                    nums[i] = 0;
                }
            }
        }
        for (int i = 0; i < len; i++) { // 第二遍遍历，找出第一个不符合条件的结果
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return len + 1; // 遍历结束都符合条件，则返回比数组中最大正数大的最小正数。[1,2,3]返回4
    }
};
