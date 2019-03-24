# number : 40

typedef set<vector<int>>::iterator set_vec;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> re;
        if (candidates.size() <= 0)
            return result;
        sort(candidates.begin(), candidates.end());
        addCombination(candidates, target, 0, re);
        for (set_vec it = s.begin(); it != s.end(); it++)
            result.push_back(*it);
        return result;
    }
    void addCombination(vector<int>& candidates, int target, int begin_index, vector<int>& re) {
        if (target == 0)
        {
            s.insert(re);
            return;
        }
        for (int i = begin_index ; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                re.push_back(candidates[i]);
                addCombination(candidates, target - candidates[i], i + 1, re);
                re.pop_back();
            }
            else
                break;
        }
        return;
    }
private:
    set<vector<int>> s;
    vector<vector<int>> result;
};
