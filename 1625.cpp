class Solution {
public:
    void solve(string s, unordered_set<string>& seen, int a, int b) {
        if (seen.count(s))
            return;
        seen.insert(s);
        string add = s;
        for (int i = 1; i < s.size(); i += 2) {
            int num = add[i] - '0';
            int newnum = (num + a) % 10;
            add[i] = newnum+'0';
        }
        solve(add, seen, a, b);
        string rotate = s.substr(s.size() - b) + s.substr(0, s.size() - b);
        solve(rotate, seen, a, b);
    }
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        unordered_set<string> seen;
        solve(s, seen, a, b);
        string result = s;
        for (auto& ss : seen) {
            if (ss < result) {
                result = ss;
            }
        }
        return result;
    }
};
