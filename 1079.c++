class Solution {
public:
    void solve(unordered_set<string>& st, string& str, int count, int n,
               vector<bool>& used, string tiles) {
        if (count == n)
            return;
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                string temp = str + tiles[j];
                if (st.find(temp) == st.end())
                    st.insert(temp);
                used[j] = true;
                solve(st, temp, count+1, n, used, tiles);
                used[j] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        unordered_set<string> st;
        vector<bool> used(n, false);
        string str = "";
        solve(st, str, 0, n, used, tiles);
        return st.size();
    }
};