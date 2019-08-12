# number : 49

typedef map<string, vector<string> > mp_str_vecstr;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        mp_str_vecstr mp;
        for (string item : strs) {
            string key_str = item;
            sort(key_str.begin(), key_str.end());
            mp[key_str].push_back(item);
        }
        for (mp_str_vecstr::iterator it = mp.begin(); it != mp.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
