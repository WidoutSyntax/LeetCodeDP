class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n + 1, -1), count(n + 1, 0);
        int max_len = 1;

        lis[0] = 1;
        count[0] = 1;
        for (int i = 1; i < n; i++)
        {
            lis[i] = 1;
            count[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (lis[i] < lis[j] + 1)
                    {
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    }
                    else if (lis[i] == lis[j] + 1)
                        count[i] += count[j];
                }
            }
            max_len = max(max_len, lis[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (max_len == lis[i])
                ans += count[i];
        }

        return ans;
    }
};