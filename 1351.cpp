//brute force
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negatives = 0;
        for (auto &row : grid) {
            for (int i = row.size() - 1; i >= 0; i--) {
                if (row[i] < 0) negatives++;
                else break;
            }
        }
        return negatives;
    }
};

//using binary search
class Solution {
public:
int bs(vector<int>&arr)
{
    int index=-1;
    int left=0;
    int right=arr.size()-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]<0)
        {
            index=mid;
            right=mid-1;
        }else left=mid+1;
    }
    return index;
}
    int countNegatives(vector<vector<int>>& grid) {
        int negatives = 0;
        int rows = grid.size();
        int cols=grid[0].size();
        for (int i = 0; i < rows; i++) {
           int index=bs(grid[i]);
           if(index!=-1) negatives+=cols-index;
        }
        return negatives;
    }
};

//best approach
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int i=m-1;
        int j=0;
        int negatives=0;
        while(i>=0 && j<n)
        {
            if(grid[i][j]<0){
                negatives+=n-j;
                i--;
            }else j++;
        }
        return negatives;
    }
};
