class Solution {
    int DP[505][505];

    int maxVal(int l, int r, vector<int> nums)
    {
        if (DP[l][r] != -1)
            return DP[l][r];

        int ans = 0;
        for (int i = l + 1; i < r; i++)
        {
            int left = (DP[l][i] != -1 ? DP[l][i] : maxVal(l, i, nums));
            int right = (DP[i][r] != -1 ? DP[i][r] : maxVal(i, r, nums));
            left = DP[l][i], right = DP[i][r];
            ans = max(ans, nums[l] * nums[i] * nums[r] + left + right);
        }
        return DP[l][r] = ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v.push_back(1);
        for (int x : nums)
            v.push_back(x);
        v.push_back(1);
        memset(DP, -1, sizeof(DP));

        return maxVal(0, n + 1, v);
    }
};