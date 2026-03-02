class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
         int n = grid.size();
        vector<int> endZero(n);
        for (int i = 0; i < n; i++) {
            int trailingZero = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1)
                    break;
                trailingZero++;
            }
            endZero[i] = trailingZero;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int zerosRequired = n - i - 1;
            if (endZero[i] >= zerosRequired)
                continue;
            int swapRow=-1;
            for(int j=i+1;j<n;j++)
            {
                if(endZero[j]>=zerosRequired)
                {
                    swapRow=j;
                    break;
                }
            }
            if(swapRow==-1) return -1;
            for(int row=swapRow;row>i;row--){
                swap(endZero[row],endZero[row-1]);
                swaps++;
            }
        }
        return swaps;
    }
};
