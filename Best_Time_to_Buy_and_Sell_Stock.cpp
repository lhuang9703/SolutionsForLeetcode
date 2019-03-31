# number : 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = (int)prices.size();
        if (length <= 1)
            return 0;
        int min_day = 0;
        int max_profit = 0;
        for (int i = 1; i < length; i++)
        {
            int current_profit = prices[i] - prices[min_day];
            max_profit = max_profit >= current_profit ? max_profit : current_profit;
            if (prices[i] < prices[min_day])
                min_day = i;
        }
        return max_profit;
    }
};
