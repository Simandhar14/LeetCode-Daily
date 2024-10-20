class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<int> st;
        int n = expression.length();
        vector<char> vec;
        for (int i = 0; i < n; i++) {
            if (expression[i] == '|' || expression[i] == '&' ||
                expression[i] == '!')
                vec.push_back(expression[i]);
            else if (expression[i] == ')') {
                char exp = vec.back();
                vec.pop_back();
                int val = st.top();
                if(exp=='!') val=!val;
                st.pop();
                while (st.top() != 3) {
                    if (exp == '&')
                        val = val & st.top();
                    else 
                        val = val | st.top();
                    st.pop();
                }
                st.pop();
                st.push(val);
            } else if (expression[i] == '(')
                st.push(3);
            else if (expression[i] == 't')
                st.push(1);
            else if (expression[i] == 'f')
                st.push(0);
            else
                continue;
        }
        return st.top();
    }
};