class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> DP(n + 1, vector<int>(m + 1, -1));
        for (int j = 0; j <= m; j++) DP[0][j] = 0;
        for (int i = 0; i <= n; i++) DP[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    DP[i][j] = (int)s1[i - 1] + DP[i - 1][j - 1];
                else
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }

        int total = 0;
        for (char ch : s1)
            total += (int)ch;
        for (char ch : s2)
            total += (int)ch;

        return total - 2 * DP[n][m];
    }
};