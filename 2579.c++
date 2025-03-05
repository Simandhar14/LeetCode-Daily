class Solution {
public:
    long long coloredCells(int n) {
        long long initial=1;
        for(int i=2;i<=n;i++)
        {
            long long addedcells=4*(i-1);
            initial+=addedcells;
        }
        return initial;
    }
};