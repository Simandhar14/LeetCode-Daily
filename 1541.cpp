//cpp
class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push('(');
            else {
                if (!st.empty()) {
                    if (i < n - 1 && s[i + 1] == ')') {
                        i = i + 1;
                    } else
                        count++;
                    st.pop();
                } else {
                    if (i < n - 1) {
                        if (s[i + 1] == ')') {
                            i = i + 1;
                            count++;
                        }
                    } else {
                        count += 2;
                        i = i + 1;
                    }
                }
            }
        }
        while (!st.empty()) {
            count += 2;
            st.pop();
        }
        return count;
    }
};
