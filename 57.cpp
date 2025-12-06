class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(begin(intervals), end(intervals),
             [&](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int newstart = newInterval[0];
        int newend = newInterval[1];
        int i = 0;
        while (i < n) {
            vector<int> temp = intervals[i];
            if (temp[0] >= newstart && temp[1] <= newend) {
                i++;
                continue;
            }else if(newstart>temp[1]){
                ans.push_back(temp);
            }else if(newend<temp[0])
            {
                ans.push_back({newstart, newend});
                break;
            }else{
                newstart = min(newstart, temp[0]);
                newend = max(newend, temp[1]);
            }
            i++;
        }
        if (i >= n) {
            ans.push_back({newstart, newend});
        } else {
            while (i < n) {
                ans.push_back(intervals[i]);
                i++;
            }
        }
        return ans;
    }
};
