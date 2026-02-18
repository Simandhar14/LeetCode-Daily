//difference array technique-cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diffArr(n,0);
        for(auto &book:bookings)
        {
            int start=book[0]-1;
            int end=book[1];
            int seats=book[2];
            diffArr[start]+=seats;
            if(end<n) diffArr[end]-=seats;
        }
        int cumSum=0;
        for(int &diff:diffArr)
        {
            cumSum+=diff;
            diff=cumSum;
        }
        return diffArr;
    }
};
