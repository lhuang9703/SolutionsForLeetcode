# number : 697

struct myStruct {
    int count;
    int begin;
    int end;
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int result = INT_MAX;
        int len = nums.size();
        map<int, myStruct> mp;
        myStruct m;
        for (int i = 0; i < len; i++) {
            if (mp.find(nums[i]) == mp.end()) {
                m.count = 1;
                m.begin = i;
                m.end = i;
                mp[nums[i]] = m;
            }
            else {
                mp[nums[i]].count++;
                mp[nums[i]].end = i;
            }
        }
        int maxCount = 0;
        for (auto item : mp) {
            if (item.second.count == maxCount) {
                maxCount = item.second.count;
                result = min(result, item.second.end - item.second.begin + 1);
            }
            else if (item.second.count > maxCount) {
                maxCount = item.second.count;
                result = item.second.end - item.second.begin + 1;
            }
        }
        return result;
    }
};
