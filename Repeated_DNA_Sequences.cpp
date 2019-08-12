# number : 187

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> mp;
        for (int i = 0; i <= (int)s.size() - 10; i++) {
            string sub = s.substr(i, 10);
            if (mp.find(sub) == mp.end()) {
                mp.insert(pair(sub, 1));
            }
            else if (mp[sub] == 1) {
                result.push_back(sub);
                mp[sub] += 1;
            }
        }
        return result;
    }
};
