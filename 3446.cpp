class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int mid = n / 2;
        int j = n - 1;
        int i = 0;
        bool decreasing=true;
        while (i >= 0 && i < n) {
            if(j==0) decreasing=false;
            vector<int> temp;
            int i_ = i;
            int j_ = j;
            while (i_ < n && j_ < n) {
                temp.push_back(grid[i_][j_]);
                i_++;
                j_++;
            }
            if (decreasing)
                sort(begin(temp), end(temp));
            else
                sort(begin(temp), end(temp), greater<int>());
            int k = 0;
            i_ = i;
            j_ = j;
            while (i_ < n && j_ < n) {
                grid[i_][j_] = temp[k];
                i_++;
                j_++;
                k++;
            }
            if (j > 0)
                j--;
            else
                i++;
        }
        return grid;
    }
};
