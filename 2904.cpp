//cpp
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = s;
        int len = n;
        int i = 0, ones = 0, start = -1;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1')
                ones++;
            if (ones == k) {
                while (ones == k && i <= j) {
                    if (start == -1 || j - i + 1 < len) {
                        start = i;
                        len = j - i + 1;
                    } else if (j - i + 1 == len) {
                        string ss = s.substr(i, j - i + 1);
                        string ans = s.substr(start, len);
                        if (ss < ans) {
                            start = i;
                            len = j - i + 1;
                        }
                    }
                    if (s[i] == '1')
                        ones--;
                    i++;
                }
            }
        }
        return start == -1 ? "" : s.substr(start, len);
    }
};
