class Solution {
public:
    int find(int ind, int m, int n, vector<string> &strs, vector<vector<vector<int>>> &DP)
    {
        if (m == 0 && n == 0)
            return 0;
        if (ind == strs.size())
            return 0;
        if (m < 0 || n < 0)
            return INT_MIN;

        if (DP[ind][m][n] != -1)
            return DP[ind][m][n];

        int ct_0 = 0;
        for (char ch : strs[ind])
            if (ch == '0') ct_0++;
        int ct_1 = strs[ind].length() - ct_0;

        int taken = INT_MIN;
        if (m >= ct_0 && n >= ct_1)
            taken = 1 + find(ind + 1, m - ct_0, n - ct_1, strs, DP);
        int not_taken = find(ind + 1, m, n, strs, DP);

        return DP[ind][m][n] = max(taken, not_taken);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> DP(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return find(0, m, n, strs, DP);
    }
};