//cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;
                char ch = st.top();
                if (ch == '(' && s[i] != ')' || ch == '{' && s[i] != '}' ||
                    ch == '[' && s[i] != ']')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
