class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums)
            sum += x;
        if ((sum + target) & 1)
            return 0;
        sum = (sum + target) >> 1;
        if (sum < 0)
            sum *= -1;

        vector<vector<int>> DP(n + 1, vector<int>(sum + 1, -1));
        for (int j = 0; j <= sum; j++)
            DP[0][j] = 0;
        for (int i = 0; i <= n; i++)
            DP[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (nums[i - 1] <= j)
                    DP[i][j] = DP[i - 1][j - nums[i - 1]] + DP[i - 1][j];
                else
                    DP[i][j] = DP[i - 1][j];
            }
        }

        return DP[n][sum];
    }
};