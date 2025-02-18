class Solution {
public:
    string ans = "";
    void solve(vector<bool>& used, string pattern, int i, string& temp,
               int number) {
        if (i==pattern.length()) {
            if (ans.empty() || (temp < ans && temp.length()==pattern.length()+1)) {
                ans = temp;
            }
            return;
        }
        for (int j = 1; j <= 9; j++) {
            if (used[j])
                continue;
            if (i >= 0) {
                if (pattern[i] == 'I' && j > number) {
                    temp.push_back(j + '0');
                    used[j] = true;
                    solve(used, pattern, i+1,temp,j);
                    used[j] = false;
                    temp.pop_back();
                } else if (pattern[i] == 'D' && j < number) {
                    temp.push_back(j + '0');
                    used[j] = true;
                    solve(used, pattern, i+1,temp,j);
                    used[j] = false;
                    temp.pop_back();
                }
            } else {
                temp.push_back(j + '0');
                used[j] = true;
                solve(used, pattern, i+1,temp,j);
                used[j] = false;
                temp.pop_back();
            }
        }
    }
    string smallestNumber(string pattern) {
        vector<bool> used(10, false);
        int len = pattern.length();
        string temp = "";
        solve(used, pattern, -1, temp,-1);
        return ans;
    }
};