class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        int totaldays = days;
        int i = 0;
        int n = meetings.size();
        while (i < n) {
            int minval = meetings[i][0];
            int maxval = meetings[i][1];
            
            while (i+1 < n && maxval>=meetings[i+1][0]) {
                minval = min(minval, meetings[i+1][0]);
                maxval = max(maxval, meetings[i+1][1]);
                i++;
            }
            totaldays -= (maxval - minval + 1);
             i++;
        }
        return totaldays;
    }
};
