//cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int largestArea = 0;
        for (int i = 0; i < m; i++) {
            vector<int> ones;
            for (int j = 0; j < n; j++) {
                if (i > 0 && matrix[i][j]!=0)
                    matrix[i][j] += matrix[i - 1][j];
                ones.push_back(matrix[i][j]);
            }
            sort(begin(ones), end(ones),greater<int>());
            for (int j = 0; j < n; j++) {
                if(ones[j]==0) break;
                largestArea = max(largestArea, ones[j] * (j + 1));
            }
        }
        return largestArea;
    }
};
