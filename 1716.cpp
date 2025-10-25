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
