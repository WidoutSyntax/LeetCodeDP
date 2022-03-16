class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        vector<long long> DP(n + 1, 0);
        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 5;

        for (int i = 4; i <= n; i++)
            DP[i] = (2 * DP[i - 1] + DP[i - 3]) % MOD;

        return DP[n];
    }
};