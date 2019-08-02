# number : 45

class Solution {
public:
    int jump(vector<int>& nums) {
        return jumpMinSteps(nums, 0, nums.size() - 1);
    }
    
    int jumpMinSteps(vector<int>& nums, int start, int end) {
        if (start == end) { // 在目标位置，不需要跳跃
            return 0;
        }
        if (start + nums[start] >= end) { // 在该位置可以一步跳到目标位置
            return 1;
        }
        int tmp = 1, dis = INT_MIN;
        for (int i = 1; i <= nums[start]; i++) { // 贪心遍历该位置能够到达的所有位置，找到能够跳跃更远的位置
            if (i + nums[start + i] > dis) {
                tmp = i;
                dis = i + nums[start + i];
            }
        }
        return 1 + jumpMinSteps(nums, start + tmp, end); //跳到贪心选择出的位置，递归调用
    }
};
