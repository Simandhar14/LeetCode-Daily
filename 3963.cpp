//cpp
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result;
        string ss(n, '#');
        result.push_back(string(n, '.'));
        ss[n - 1] = '.';
        for (int i = 0; i < m - 1; i++)
            result.push_back(ss);
        return result;
    }
};
