class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums)
            sum += x;
        if (sum & 1)
            return false;
        sum = sum / 2;
        vector<vector<bool>> DP(n + 1, vector<bool>(sum + 1, false));
        for (int j = 0; j <= sum; j++)
            DP[0][j] = false;
        for (int i = 0; i <= n; i++)
            DP[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j - nums[i - 1] >= 0)
                    DP[i][j] = DP[i - 1][j - nums[i - 1]] | DP[i - 1][j];
                else
                    DP[i][j] = DP[i - 1][j];
            }
        }

        return DP[n][sum];
    }
};