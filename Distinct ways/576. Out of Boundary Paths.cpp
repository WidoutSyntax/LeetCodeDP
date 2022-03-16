class Solution {
    const int MOD = 1e9 + 7;
    long long ways(int x, int y, int n, int m, int moves, vector<vector<vector<int>>> &DP)
    {
        if (moves < 0)
            return 0;
        if (x < 0 || x >= n || y < 0 || y >= m)
            return 1;
        if (moves == 0)
            return 0;

        if (DP[x][y][moves] != -1)
            return DP[x][y][moves];

        long long down = ways(x + 1, y, n, m, moves - 1, DP);
        long long up = ways(x - 1, y, n, m, moves - 1, DP);
        long long right = ways(x, y + 1, n, m, moves - 1, DP);
        long long left = ways(x, y - 1, n, m, moves - 1, DP);

        return DP[x][y][moves] = (((((left + right) % MOD) + up) % MOD) + down) % MOD;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> DP(m + 1, vector<vector<int>>(n + 1, vector<int>(52, -1)));
        return ways(startRow, startColumn, m, n, maxMove, DP);

    }
};