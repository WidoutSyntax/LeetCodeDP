class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> DP(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    DP[i][j] = grid[i][j];
                else
                {
                    int from_top = i - 1 >= 0 ? DP[i - 1][j] : INT_MAX;
                    int from_left = j - 1 >= 0 ? DP[i][j - 1] : INT_MAX;
                    DP[i][j] = min(from_top, from_left) + grid[i][j];
                }
            }
        }

        return DP[n - 1][m - 1];
    }
};