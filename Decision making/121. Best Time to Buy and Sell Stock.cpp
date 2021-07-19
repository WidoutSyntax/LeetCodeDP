class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - mn > profit)
                profit = prices[i] - mn;
            else
                mn = min(mn, prices[i]);
        }

        return profit;
    }
};