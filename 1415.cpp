//cpp
class Solution {
public:
    vector<string> allStrings;
    void solve(string str, int n) {
        if (n == 0) {
            allStrings.push_back(str);
            return;
        }
        for (char nextch = 'a'; nextch <= 'c'; nextch++) {
            if (str.back() == nextch)
                continue;
            str.push_back(nextch);
            solve(str, n - 1);
            str.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string str = "";
        solve("a", n - 1);
        solve("b", n - 1);
        solve("c", n - 1);
        if(k>allStrings.size()) return "";
        return allStrings[k - 1];
    }
};
