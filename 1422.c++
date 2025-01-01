class Solution {
public:
    int maxScore(string s) {
        int result = 0;
        size_t n = s.length();
        vector<int> zeros(n, 0);
        vector<int> ones(n, 0);
        if (s[0] == '0')
            zeros[0] = 1;
        if (s[n - 1] == '1')
            ones[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            zeros[i] = zeros[i - 1] + (s[i] == '0' ? 1 : 0);
        }
        for (int i = n - 2; i >= 0; i--) {
            ones[i] = ones[i + 1] + (s[i] == '1' ? 1 : 0);
        }
        for (int i = 0; i < n - 1; i++) {
            result = max(result, zeros[i] + ones[i + 1]);
        }
        return result;
    }
};