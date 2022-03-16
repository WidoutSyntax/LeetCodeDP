class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = 0;
        for (int x : stones)
            sum += x;

        vector<vector<bool>> DP(n + 1, vector<bool>(sum + 1, false));
        for (int j = 0; j <= sum; j++) DP[0][j] = false;
        for (int i = 0; i <= n; i++) DP[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (stones[i - 1] <= j)
                    DP[i][j] = DP[i - 1][j - stones[i - 1]] | DP[i - 1][j];
                else
                    DP[i][j] = DP[i - 1][j];
            }
        }

        int min_diff = INT_MAX;
        for (int j = 0; j <= sum / 2; j++)
        {
            if (DP[n][j])
                min_diff = min(min_diff, abs(2 * j - sum));
        }

        return min_diff;
    }
};