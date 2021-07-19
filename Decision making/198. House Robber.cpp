class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> DP(n, -1);
        DP[0] = nums[0];
        for (int i = 1; i < n; i++)
            DP[i] = max(DP[i - 1], (i - 2 >= 0 ? DP[i - 2] : 0) + nums[i]);

        return DP[n - 1];
    }
};