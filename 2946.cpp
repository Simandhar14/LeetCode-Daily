//cpp
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        if (k == n || k == 0)
            return true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int shift = k % n;
                if (i % 2 == 0) {
                    int nextPos = j - shift;
                    if (nextPos < 0)
                        nextPos += n;
                    if (mat[i][j] != mat[i][nextPos])
                        return false;
                } else {
                    int nextPos = (j + shift) % n;
                    if (mat[i][j] != mat[i][nextPos])
                        return false;
                }
            }
        }
        return true;
    }
};
