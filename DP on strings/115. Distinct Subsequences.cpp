class Solution {
    vector<vector<int>> DP;

    int makeSub(string s, string t, int ind1, int ind2)
    {
        if (ind2 == t.length())
            return 1;
        if (ind1 == s.length())
            return 0;

        if (DP[ind1][ind2] != -1)
            return DP[ind1][ind2];

        if (s[ind1] != t[ind2])
            return DP[ind1][ind2] = makeSub(s, t, ind1 + 1, ind2);
        else
        {
            int op1 = (DP[ind1 + 1][ind2 + 1] != -1 ? DP[ind1 + 1][ind2 + 1] : (DP[ind1 + 1][ind2 + 1] = makeSub(s, t, ind1 + 1, ind2 + 1)));
            int op2 = (DP[ind1 + 1][ind2] != -1 ? DP[ind1 + 1][ind2] : (DP[ind1 + 1][ind2] = makeSub(s, t, ind1 + 1, ind2)));
            return DP[ind1][ind2] = op1 + op2;
        }
    }

public:
    int numDistinct(string s, string t) {
        DP.resize(s.length() + 1);
        for (int i = 0; i <= s.length(); i++)
            DP[i].resize(t.length() + 1, -1);

        return makeSub(s, t, 0, 0);
    }
};