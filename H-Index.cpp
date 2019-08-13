# number : 274

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int result = 0, len = (int)citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < len; i++) {
            if (len - i <= citations[i]) {
                result = result >= (len - i) ? result : (len - i);
            }
        }
        return result;
    }
};
