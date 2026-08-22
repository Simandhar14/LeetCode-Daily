//cpp
class Solution {
public:
    void solve(string& result, int i, string& digits, vector<vector<char>>& vec,
               vector<string>& ans) {
        if (i == digits.length()) {
            ans.push_back(result);
            return;
        }
        int num = digits[i] - '0';
        for (char& letter : vec[num]) {
            result.push_back(letter);
            solve(result, i + 1, digits, vec, ans);
            result.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> vec(10);
        string result = "";
        vec[2] = {'a', 'b', 'c'};
        vec[3] = {'d', 'e', 'f'};
        vec[4] = {'g', 'h', 'i'};
        vec[5] = {'j', 'k', 'l'};
        vec[6] = {'m', 'n', 'o'};
        vec[7] = {'p', 'q', 'r', 's'};
        vec[8] = {'t', 'u', 'v'};
        vec[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        solve(result, 0, digits, vec, ans);
        return ans;
    }
};
