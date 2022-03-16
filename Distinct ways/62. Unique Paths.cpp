class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    DP[i][j] = 1;
                else
                {
                    int left = j - 1 >= 0 ? DP[i][j - 1] : 0;
                    int up = i - 1 >= 0 ? DP[i - 1][j] : 0;
                    DP[i][j] = left + up;
                }
            }
        }

        return DP[m - 1][n - 1];
    }
};