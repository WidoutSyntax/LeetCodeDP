class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> DP(3, vector<int>(n, -1));
        for (int j = 0; j < n; j++) DP[0][j] = 0;
        for (int i = 0; i <= 2; i++) DP[i][0] = 0;

        for (int i = 1; i <= 2; i++)
        {
            int mx = DP[i - 1][0] - prices[0];
            for (int j = 1; j < n; j++)
            {
                DP[i][j] = max(DP[i][j - 1], prices[j] + mx);
                mx = max(mx, DP[i - 1][j] - prices[j]);
            }
        }

        return DP[2][n - 1];
    }
};