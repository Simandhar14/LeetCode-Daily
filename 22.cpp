class Solution {
public:
    void solve(string& ss, vector<string>& result, int open, int n) {
    int close = ss.size() - open;
    if (open == n && close == n) {
        result.push_back(ss);
        return;
    }
    if (open > close) {
        ss.push_back(')');
        solve(ss, result, open, n);
        ss.pop_back();
    }
    if (open < n) {
        ss.push_back('(');
        solve(ss, result, open + 1, n);
        ss.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string ss = "";
    solve(ss, result, 0, n);
    return result;
}
};
