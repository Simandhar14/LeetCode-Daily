//dp+memo
class Solution {
public:
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];
        int kval = 0, result = 0;
        for (int jump = 1; jump <= d; jump++) {
            if (i + jump >= arr.size())
                break;
            if (arr[i] > arr[i + jump] && arr[i] > kval) {
                result = max(result, 1 + dfs(i + jump, arr, d,dp));
            } else
                break;
            kval = max(kval, arr[i + jump]);
        }
        kval = 0;
        for (int jump = 1; jump <= d; jump++) {
            if (i - jump < 0)
                break;
            if (arr[i] > arr[i - jump] && arr[i] > kval) {
                result = max(result, 1 + dfs(i - jump, arr, d,dp));
            } else
                break;
            kval = max(kval, arr[i - jump]);
        }
        return dp[i] = result;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 0;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) {
            int visits = dfs(i, arr, d, dp);
            ans = max(ans, 1 + visits);
        }
        return ans;
    }
};
