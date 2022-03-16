class Solution {
public:
    int numSquares(int n) {
        vector<int> DP(n + 1, INT_MAX);
        DP[0] = 0;
        for (int sq = 1; sq <= n; sq++)
        {
            for (int i = 1; i * i <= sq; i++)
                DP[sq] = min(DP[sq], 1 + DP[sq - (i * i)]);
        }

        return DP[n];
    }
};