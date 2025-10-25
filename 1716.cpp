//brute force
class Solution {
public:
    int totalMoney(int n) {
        int day=1;
        int monday=1;
        int val=1;
        int totalMoney=0;
        while(n--)
        {
            totalMoney+=val;
            val++;
            day++;
            if(day>7)
            {
                day=1;
                monday++;
                val=monday;
            }
        }
        return totalMoney;
    }
};

//using sum of natural numbers formula
class Solution {
public:
    int totalMoney(int n) {
        int totalMoney=0;
        int startDay=1;
        while(n>0)
        {
            int days=min(7,n);
            int endDay=startDay+days-1;
            totalMoney+=((endDay-startDay+1) * (endDay+startDay))/2;
            n-=(endDay-startDay+1);
            startDay++;
        }
        return totalMoney;
    }
};
