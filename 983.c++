class Solution {
public:
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>&dp) {
        if (i >= days.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        int one = costs[0] + solve(i + 1, days, costs,dp);
        int j = i;
        int maxdays = days[j] + 7;
        while (j < days.size() && days[j] < maxdays) {
            j++;
        }
        int seven = costs[1] + solve(j, days, costs,dp);
        j = i;
        maxdays = days[j] + 30;
        while (j < days.size() && days[j] < maxdays) {
            j++;
        }
        int thirty = costs[2] + solve(j, days, costs,dp);
        return dp[i]=min({one, seven, thirty});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return solve(0, days, costs,dp);
    }
};