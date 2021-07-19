class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        int not_have_stock = 0, have_stock = -prices[0] - fee;
        for (int i = 1; i < n; i++)
        {
            not_have_stock = max(not_have_stock, have_stock + prices[i]);
            have_stock = max(have_stock, not_have_stock - prices[i] - fee);
        }

        return not_have_stock;
    }
};