//cpp
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string result = s;
        vector<int> freq(26, 0);
        for (char& ch : s)
            freq[ch - 'a']++;

        int j = 0;
        for (int i = 0; i < n / 2; i++) {
            while (freq[j] <= 1)
                j++;
            s[i] = j + 'a';
            s[n - 1 - i] = j + 'a';
            freq[j] -= 2;
        }
        return min(result, s);
    }
};
