class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        if (n == 2 && prices[1] > prices[0])
            return prices[1] - prices[0];
        else if (n == 2 && prices[1] <= prices[0])
            return 0;

        vector<vector<int>> DP(n, vector<int>(2, -1));
        DP[0][0] = 0;
        DP[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            DP[i][0] = max(DP[i - 1][0], DP[i - 1][1] + prices[i]);
            DP[i][1] = max(DP[i - 1][1], (i - 2 >= 0 ? DP[i - 2][0] : 0) - prices[i]);
        }

        return DP[n - 1][0];
    }
};