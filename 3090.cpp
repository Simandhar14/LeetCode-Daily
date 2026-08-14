//cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while (j < n) {
            int ch = s[j] - 'a';
            freq[ch]++;
            while (freq[ch] > 2) {
                freq[s[i] - 'a']--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};
