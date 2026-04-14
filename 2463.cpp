//cpp
class Solution {
public:
    long long solve(vector<int>& robot, vector<int>& pos, int i, int j,vector<vector<long long>>&dp) {
        if (i >= robot.size())
            return 0;
        if (i != robot.size() && j >= pos.size())
            return LLONG_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        long long result = LLONG_MAX;
        long long take = solve(robot, pos, i + 1, j + 1,dp);
        if (take != LLONG_MAX) {
            result = min(result, abs(robot[i] - pos[j]) + take);
        }
        long long skip = solve(robot, pos, i, j + 1,dp);
        if (skip != LLONG_MAX)
            result = min(result, skip);
        return dp[i][j] = result;
    }
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        long long minDist = LLONG_MAX;
        vector<int> pos;
        for (auto& temp : factory) {
            int index = temp[0];
            int freq = temp[1];
            while (freq--) {
                pos.push_back(index);
            }
        }
        sort(begin(robot), end(robot));
        sort(begin(pos), end(pos));
        vector<vector<long long>> dp(robot.size(),
                                     vector<long long>(pos.size(), -1));
        return solve(robot, pos, 0, 0, dp);
    }
};
