//cpp
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
                result = max(result, count);
            } else if (s[i] == ')')
                count--;
        }
        return result;
    }
};
