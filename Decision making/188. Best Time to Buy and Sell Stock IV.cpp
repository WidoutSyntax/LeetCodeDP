class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        vector<vector<int>> DP(k + 1, vector<int>(n, -1));
        for (int j = 0; j < n; j++) DP[0][j] = 0;
        for (int i = 0; i <= k; i++) DP[i][0] = 0;

        for (int i = 1; i <= k; i++)
        {
            int mx_diff = DP[i - 1][0] - prices[0];
            for (int j = 1; j < n; j++)
            {
                DP[i][j] = max(DP[i][j - 1], prices[j] + mx_diff);
                mx_diff = max(mx_diff, DP[i - 1][j] - prices[j]);
            }
        }

        return DP[k][n - 1];
    }
};