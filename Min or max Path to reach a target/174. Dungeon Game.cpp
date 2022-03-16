class Solution {
public:
    int cal_health(int x, int y, int n , int m, vector<vector<int>> &dungeon, vector<vector<int>> &DP)
    {
        if (x == n || y == m)
            return INT_MAX;

        if (DP[x][y] != -1)
            return DP[x][y];

        int val1 = cal_health(x + 1, y, n, m, dungeon, DP);
        int val2 = cal_health(x, y + 1, n, m, dungeon, DP);

        int ans = -1;
        if (val1 == INT_MAX && val2 == INT_MAX)
            ans = 1 - dungeon[x][y];
        else
            ans = min(val1, val2) - dungeon[x][y];

        if (ans <= 0) ans = 1;
        return DP[x][y] = ans;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> DP(n, vector<int>(m, -1));

        return cal_health(0, 0, n, m, dungeon, DP);
    }
};

