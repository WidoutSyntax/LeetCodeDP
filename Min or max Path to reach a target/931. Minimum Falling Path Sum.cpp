class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> DP(n, vector<int>(m, -1));
        for (int j = 0; j < m; j++)
            DP[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int val1 = i - 1 >= 0 && j - 1 >= 0 ? DP[i - 1][j - 1] : INT_MAX;
                int val2 = i - 1 >= 0 ? DP[i - 1][j] : INT_MAX;
                int val3 = i - 1 >= 0 && j + 1 < m ? DP[i - 1][j + 1] : INT_MAX;
                DP[i][j] = min(val1, min(val2, val3)) + matrix[i][j];
            }
        }

        int ans = *min_element(DP[n - 1].begin(), DP[n - 1].end());
        return ans;

    }
};