//cpp
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> firstIdx(26, -1);
        vector<int> lastIdx(26, -1);
        vector<bool> isValid(26, true);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (firstIdx[idx] == -1)
                firstIdx[idx] = i;
            lastIdx[idx] = i;
        }
        vector<string> result;
        for (int c = 0; c < 26; c++) {
            if (firstIdx[c] == -1)
                continue;
            for (int i = firstIdx[c]; i <= lastIdx[c]; i++) {
                int idx = s[i] - 'a';
                if (firstIdx[idx] < firstIdx[c]) {
                    isValid[c] = false;
                    break;
                }
                lastIdx[c] = max(lastIdx[c], lastIdx[idx]);
            }
        }
        int last = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (!isValid[c])
                continue;
            if (i == firstIdx[c] && lastIdx[c] < last) {
                result.push_back(
                    s.substr(firstIdx[c], lastIdx[c] - firstIdx[c] + 1));
                last = firstIdx[c];
            }
        }
        return result;
    }
};
