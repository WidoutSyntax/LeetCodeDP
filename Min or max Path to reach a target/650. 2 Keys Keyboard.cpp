class Solution {
public:
    int minSteps(int n) {
        vector<int> DP(n + 1, -1);
        if (n <= 1)
            return 0;
        DP[0] = 0;
        DP[1] = 0;
        DP[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            DP[i] = i;
            for (int j = 2; j < i; j++)
                if (i % j == 0)
                    DP[i] = min(DP[i], (i / j) + DP[j]);
        }

        return DP[n];
    }
};