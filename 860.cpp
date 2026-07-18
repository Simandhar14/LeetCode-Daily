//cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, fifteen = 0;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                if (five < 1)
                    return false;
                five--;
                ten++;
            } else if (bills[i] == 15) {
                fifteen++;
                if (ten > 0) {
                    ten--;
                } else if (five >= 2) {
                    five -= 2;
                } else
                    return false;
            } else {
                if (fifteen > 1) {
                    fifteen--;
                } else if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};
