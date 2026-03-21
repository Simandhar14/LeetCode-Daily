//cpp
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int topRow=x;
        int bottomRow=x+k-1;
        while(topRow<bottomRow)
        {
            for(int col=y;col<y+k;col++)
            {
                swap(grid[topRow][col],grid[bottomRow][col]);
            }
            topRow++;
            bottomRow--;
        }
        return grid;
    }
};
