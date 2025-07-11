class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        vector<long long> rooms(n, 0);
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        
        priority_queue<long long, vector<long long>, greater<long long>> freeroom;
        for (int i = 0; i < n; i++) freeroom.push(i);

        int index = 0;
        while (index < meetings.size()) {
            long long currentStart = meetings[index][0];
            long long currentEnd = meetings[index][1];
            long long duration = currentEnd - currentStart;

            while (!pq.empty() && pq.top()[0] <= currentStart) {
                freeroom.push(pq.top()[1]);
                pq.pop();
            }

            if (!freeroom.empty()) {
                int room = freeroom.top();
                freeroom.pop();
                pq.push({currentEnd, room});
                rooms[room]++;
            } else {
                auto temp = pq.top(); pq.pop();
                long long newStart = temp[0];
                int room = temp[1];
                pq.push({newStart + duration, room});
                rooms[room]++;
            }
            index++;
        }

        int maxMeetings = -1, ans = -1;
        for (int i = 0; i < n; i++) {
            if (rooms[i] > maxMeetings) {
                maxMeetings = rooms[i];
                ans = i;
            }
        }
        return ans;
    }
};
