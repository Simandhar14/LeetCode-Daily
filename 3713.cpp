//cpp
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int result = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int count = freq[s[j] - 'a'];
                bool equal = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] == 0)
                        continue;
                    if (freq[k] != count) {
                        equal = false;
                        break;
                    }
                }
                if (equal)
                    result = max(result, j - i + 1);
            }
        }
        return result;
    }
};
