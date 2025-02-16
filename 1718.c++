class Solution {
public:
    bool solve(vector<int> &result, vector<bool> &used, int n, int len, int i) {
        if(i>=len) return true;
        if (result[i] != -1) {
            return solve(result, used, n, len, i + 1);
        }
        for (int num = n; num >= 1; num--) {
            if (used[num])
                continue;
            if (num == 1) {
                result[i] = num;
                used[num] = true;
                 if(solve(result, used, n, len, i + 1)) return true;
                result[i] = -1;
                used[num] = false;
            } else {
                if (i + num < len && result[i + num] == -1) {
                    result[i] = num;
                    result[i + num] = num;
                    used[num] = true;
                    if(solve(result, used, n, len, i + 1))return true;
                    result[i] = -1;
                    result[i + num] = -1;
                    used[num] = false;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int len = 1 + 2 * (n - 1);
        vector<bool> used(n + 1, false);
        vector<int> result(len, -1);
        solve(result, used, n, len, 0);
        return result;
    }
};