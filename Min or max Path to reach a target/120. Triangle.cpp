class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> pre = triangle[0], next;
        for (int i = 1; i < triangle.size(); i++)
        {
            vector<int> nxt(triangle[i].size(), -1);
            for (int j = 0; j < nxt.size(); j++)
            {
                int val1 = j < pre.size() ? pre[j] : INT_MAX;
                int val2 = j - 1 >= 0 ? pre[j - 1] : INT_MAX;
                nxt[j] = min(val1, val2) + triangle[i][j];
            }
            pre = nxt;
        }

        int min_val = *min_element(pre.begin(), pre.end());
        return min_val;
    }
};