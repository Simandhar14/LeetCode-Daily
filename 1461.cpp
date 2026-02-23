//cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        string window = "";
        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            window.push_back(s[j]);
            if (j - i + 1 == k) {
                st.insert(window);
                window = window.substr(1);
                i++;
            }
        }
        return st.size() == (1 << k);
    }
};
