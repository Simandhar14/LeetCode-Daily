//cpp
class Solution {
public:
    int findDay(const string& day, const vector<int>& cumMonthDays) {
        int month = stoi(day.substr(0, 2));
        int date  = stoi(day.substr(3));
        return cumMonthDays[month - 1] + date;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cumMonthDays(13, 0);
        cumMonthDays[1] = 31; //January month , 1 based indexing
        for(int i = 1; i <= 12; i++) {
            cumMonthDays[i] = cumMonthDays[i-1] + monthDays[i-1];
        }
        int arriveAliceDay  = findDay(arriveAlice, cumMonthDays);
        int leaveAliceDay   = findDay(leaveAlice, cumMonthDays);
        int arriveBobDay    = findDay(arriveBob, cumMonthDays);
        int leaveBobDay     = findDay(leaveBob, cumMonthDays);
        int daysTogether = min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1;

        return daysTogether < 0 ? 0 : daysTogether;
    }
};
