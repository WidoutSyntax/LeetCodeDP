class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> DP(n + 1, INT_MAX);
        DP[0] = 0;
        DP[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            int val1 = DP[i - 1] + cost[i - 1];
            int val2 = DP[i - 2] + cost[i - 2];
            DP[i] = min(val1, val2);
        }

        return DP[n];
    }
};