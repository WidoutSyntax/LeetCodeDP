class Solution {
public:
    int find_cost(int ind, vector<int> &days, vector<int> &costs, vector<int> &DP)
    {
        int n = days.size();
        if (ind >= n)
            return 0;

        if (DP[ind] != -1)
            return DP[ind];

        int day = costs[0] + find_cost(ind + 1, days, costs, DP);

        int i;
        for (i = ind; i < n && days[i] < days[ind] + 7; i++);
        int week = costs[1] + find_cost(i, days, costs, DP);

        for (i = ind; i < n && days[i] < days[ind] + 30; i++);
        int month = costs[2] + find_cost(i, days, costs, DP);

        return DP[ind] = min({day, week, month});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> DP(367, -1);
        return find_cost(0, days, costs, DP);
    }
};