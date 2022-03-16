class Solution {
    double ways(int x, int y, int n, int moves, vector<vector<vector<double>>> &DP)
    {
        int arrX[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int arrY[] = { -1, 1, -1, 1, -2, 2, -2, 2};

        if (x < 0 || x >= n || y < 0 || y >= n)
            return 0;
        if (moves == 0)
            return 1;

        if (DP[x][y][moves] != -1)
            return DP[x][y][moves];

        double ans = 0;
        for (int k = 0; k < 8; k++)
            ans += ways(x + arrX[k], y + arrY[k], n, moves - 1, DP);

        return DP[x][y][moves] = ans;

    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> DP(30, vector<vector<double>>(30, vector<double>(k + 1, -1)));
        double onboard = ways(row, column, n, k, DP);

        double deno = pow(8, k);
        double ans =  onboard / deno;
        return ans;
    }
};