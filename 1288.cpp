//cpp
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals),
             [&](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        int remove = 0;
        int l1 = intervals[0][0];
        int r1 = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            int l2 = intervals[i][0];
            int r2 = intervals[i][1];
            if (l2 >= l1 && r2 <= r1) {
                remove++;
            } else {
                l1 = l2;
                r1 = r2;
            }
        }
        return n - remove;
    }
};
