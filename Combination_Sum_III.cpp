# number : 216

class Solution {
public:
    vector<vector<int> > result;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k < 1 || n < 1)
            return result;
        vector<int> re;
        solute(k, n, 1, re);
        return result;
    }
    
    void solute(int k, int n, int start, vector<int>& re) {
        if (k == 0 && n == 0) {
            result.push_back(re);
            return;
        }
        for (int i = start; i < 10; i++) {
            re.push_back(i);
            solute(k - 1, n - i, i + 1, re);
            re.pop_back();
        }
    }
};
