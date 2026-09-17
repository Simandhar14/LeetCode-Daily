//dp and memoization
class Solution {
public:
    int solve(int start, vector<int>& arr, int target, int count,
              vector<vector<int>>& dp) {
        if (count == 0) {
            return 0;
        }
        if (start >= arr.size())
            return INT_MAX;
        if (dp[start][count] != INT_MAX)
            return dp[start][count];
        int sum = 0;
        int result = INT_MAX;
        for (int i = start; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == target) {
                int ans = solve(i + 1, arr, target, count - 1, dp);
                if (ans != INT_MAX)
                    result = min(result, i - start + 1 + ans);
            }
            if(sum>target) break;
        }
        int ans = solve(start + 1, arr, target, count, dp);
        if (ans != INT_MAX)
            result = min(result, ans);
        return dp[start][count] = result;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int>(3, INT_MAX));
        int result = solve(0, arr, target, 2, dp);
        return result == INT_MAX ? -1 : result;
    }
};

//best approach
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLen(n, INT_MAX);
        int i = 0, currsum = 0, result = INT_MAX, minimum = INT_MAX;
        for (int j = 0; j < n; j++) {
            currsum += arr[j];
            while (currsum > target) {
                currsum -= arr[i];
                i++;
            }
            if (currsum == target) {
                int len = j - i + 1;
                if (i > 0 && minLen[i - 1] != INT_MAX) {
                    result = min(result, len + minLen[i - 1]);
                }
                minimum = min(minimum, len);
            }
            minLen[j] = minimum;
        }
        return result == INT_MAX ? -1 : result;
    }
};
