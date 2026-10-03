//cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int n = s.length();
        int open = 0, close = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')')
                close++;
            else
                open++;
            if (close > open) {
                open = 0, close = 0;
                continue;
            }
            if (open == close)
                result = max(result, open + close);
        }
        open = 0, close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')')
                close++;
            else
                open++;
            if (open > close) {
                open = 0, close = 0;
                continue;
            }
            if (open == close)
                result = max(result, open + close);
        }
        return result;
    }
};
