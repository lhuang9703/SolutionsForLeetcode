# number : 332

class Solution {
public:
    vector<string> v;
    vector<vector<string>> re;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        v.push_back("JFK");
        int len = (int)tickets.size();
        sort(tickets.begin(), tickets.end());
        dfs(tickets, "JFK", len);
        return re[0];
    }
    
    void dfs(vector<vector<string>>& tickets, string from, int len) {
        if (v.size() == len + 1) {
            re.push_back(v);
        }
        for (int i = 0; i < tickets.size(); i++) {
            if (tickets[i][0] == from) {
                vector<string> tmp = tickets[i];
                string to = tickets[i][1];
                v.push_back(to);
                tickets.erase(tickets.begin() + i);
                dfs(tickets, to, len);
                v.pop_back();
                tickets.insert(tickets.begin() + i, tmp);
            }
            if (re.size() == 1)
                return;
        }
    }
};
