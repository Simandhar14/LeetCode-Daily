class Solution {
public:
    bool solve(string& bottom, string& str, int i,
               unordered_map<string, vector<char>>& mp,
               unordered_map<string, bool>& memo) {

        if (bottom.length() == 1)
            return true;

        if (i == 0 && memo.count(bottom))
            return memo[bottom];

        string ss;
        ss.push_back(bottom[i]);
        ss.push_back(bottom[i + 1]);

        if (mp.find(ss) == mp.end())
            return false;

        for (char ch : mp[ss]) {
            string newstr = str;
            newstr.push_back(ch);

            if (i == bottom.size() - 2) {
                string empty = "";
                if (solve(newstr, empty, 0, mp, memo)) {
                    memo[bottom] = true;
                    return true;
                }
            } else {
                if (solve(bottom, newstr, i + 1, mp, memo)) {
                    return true;
                }
            }
        }

        if (i == 0)
            memo[bottom] = false;
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        string str = "";
        unordered_map<string, vector<char>> mp;
        unordered_map<string, bool> memo;
        for (string& ss : allowed) {
            string temp = "";
            temp.push_back(ss[0]);
            temp.push_back(ss[1]);
            mp[temp].push_back(ss[2]);
        }
        return solve(bottom, str, 0, mp, memo);
    }
};
