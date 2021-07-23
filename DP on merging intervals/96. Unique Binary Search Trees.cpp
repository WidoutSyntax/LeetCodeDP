class Solution {
public:
    int numTrees(int n) {
        vector<int> DP(n + 1, -1);
        DP[0] = 1;
        DP[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int start = 0, end = i - 1;
            int val = 0;
            while (end >= 0)
                val += DP[start++] * DP[end--];
            DP[i] = val;
        }

        return DP[n];
    }
};