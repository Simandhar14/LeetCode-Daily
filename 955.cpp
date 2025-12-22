class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].length();
        unordered_set<int> delCols;
        while (true) {
            bool sorted = true;
            for (int i = 1; i < n; i++) {
                for (int col = 0; col < len; col++) {
                    if (delCols.count(col))
                        continue;
                    if (strs[i][col] < strs[i - 1][col]) {
                        delCols.insert(col);
                        sorted = false;
                    } else if (strs[i][col] > strs[i - 1][col])
                        break;
                }
            }
            if (sorted)
                break;
        }
        return delCols.size();
    }
};
