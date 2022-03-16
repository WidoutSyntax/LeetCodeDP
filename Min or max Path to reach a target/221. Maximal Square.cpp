class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> DP(n, vector<int>(m, -1));

        int max_sq = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    int val1 = i - 1 >= 0 ? DP[i - 1][j] : 0;
                    int val2 = j - 1 >= 0 ? DP[i][j - 1] : 0;
                    int val3 = i - 1 >= 0 && j - 1 >= 0 ? DP[i - 1][j - 1] : 0;
                    DP[i][j] = min(val1, min(val2, val3)) + 1;
                }
                else
                    DP[i][j] = 0;

                max_sq = max(max_sq, DP[i][j]);
            }
        }

        return max_sq * max_sq;
    }
};