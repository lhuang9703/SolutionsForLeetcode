# number : 122

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int length = (int)prices.size();
        if (length <= 1)
            return 0;
        for (auto i = 0; i < length - 1; i++)
        {
            if (prices[i + 1] > prices[i])
                max_profit += (prices[i + 1] - prices[i]);
        }
        return max_profit;
    }
};
