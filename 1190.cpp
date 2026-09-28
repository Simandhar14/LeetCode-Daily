//cpp
class Solution {
public:
    string reverseParentheses(string s) {
        string result = "";
        int n = s.length();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(result.size());
            else if (s[i] == ')') {
                int len = st.empty() == true ? 0 : st.top();
                st.pop();
                reverse(begin(result) + len, end(result));
            } else
                result += s[i];
        }
        return result;
    }
};
