class Solution {
public:
    typedef pair<long long, long long> p;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); //sort meetings acc to start time
        vector<int> booked(n, 0);
        priority_queue<int, vector<int>, greater<int>> free; //keep track of free rooms
        priority_queue<p, vector<p>, greater<p>> busy; //keep track of busy rooms
        for (int i = 0; i < n; i++)
            free.push(i);
        for (int i = 0; i < meetings.size(); i++) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];
            while (!busy.empty() && busy.top().first <= start) { //empty the busy rooms 
                free.push(busy.top().second);
                busy.pop();
            }
            if (!free.empty()) { //occupy the free room if found
                int room = free.top();
                free.pop();
                busy.push({end, room});
                booked[room]++;
            } else { // then take the first room which will be free
                int room = busy.top().second;
                long long time = busy.top().first;
                long long delayed = time - start;
                busy.pop();
                busy.push({delayed + end, room});
                booked[room]++;
            }
        }
        int maxbooked = 0;
        int maxroom = 0;
        for (int i = 0; i < n; i++) {
            if (booked[i] > maxbooked) {
                maxbooked = booked[i];
                maxroom = i;
            }
        }
        return maxroom;
    }
};
