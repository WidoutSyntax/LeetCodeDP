class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1])
            return 0;
        vector<vector<int>> DP(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    DP[i][j] = 1;
                else if (obstacleGrid[i][j] == 0)
                {
                    int left = j - 1 >= 0 ? DP[i][j - 1] : 0;
                    int up = i - 1 >= 0 ? DP[i - 1][j] : 0;
                    DP[i][j] = left + up;
                }
            }
        }

        return DP[n - 1][m - 1];
    }
};