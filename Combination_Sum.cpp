# number : 39

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> re;
        if (candidates.size() <= 0)
            return result;
        sort(candidates.begin(), candidates.end());
        addCombination(candidates, target, re);
        for (set<vector<int>>::iterator it = s.begin(); it != s.end(); it++)
            result.push_back(*it);
        return result;
    }
    void addCombination(vector<int>& candidates, int target, vector<int>& re) {
        if (target == 0)
        {
            vector<int> temp(re.begin(), re.end());
            sort(temp.begin(), temp.end());
            s.insert(temp);
            return;
        }
        for (int i = 0; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                re.push_back(candidates[i]);
                addCombination(candidates, target - candidates[i], re);
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
