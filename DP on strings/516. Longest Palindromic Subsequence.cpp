class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.length();
        vector<vector<int>> DP(n + 1, vector<int>(n + 1, -1));

        for (int j = 0; j <= n; j++) DP[0][j] = 0;
        for (int i = 0; i <= n; i++) DP[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    DP[i][j] = 1 + DP[i - 1][j - 1];
                else
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }

        return DP[n][n];
    }
};