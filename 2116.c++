class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0)
            return false;
        stack<int> open;
        stack<int> any;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0')
                any.push(i);
            else if (s[i] == '(')
                open.push(i);
            else {
                if (!open.empty())
                    open.pop();
                else if (!any.empty())
                    any.pop();
                else
                    return false;
            }
        }
        while(!open.empty() && !any.empty() && open.top()<any.top())
        {
            open.pop();
            any.pop();
        }
        return open.empty();
    }
};