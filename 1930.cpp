class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> st;
        vector<int> lastSeen(26, -1);
        vector<int> firstSeen(26, -1);
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (firstSeen[s[i] - 'a'] == -1)
                firstSeen[s[i] - 'a'] = i;
            for (int idx = 0; idx < 26; idx++) {
                if (firstSeen[s[i] - 'a'] == -1 || lastSeen[s[i] - 'a'] == -1)
                    continue;
                if (lastSeen[idx] < i &&
                    lastSeen[idx] > firstSeen[s[i] - 'a']) {
                    char ch = 'a' + idx;
                    string ss = string() + s[i] + ch + s[i];
                    if (!st.count(ss)){
                        cout<<i<<" "<<ss<<endl;
                        count++;
                    }
                    st.insert(ss);
                }
            }
            lastSeen[s[i] - 'a'] = i;
        }
        return count;
    }
};
