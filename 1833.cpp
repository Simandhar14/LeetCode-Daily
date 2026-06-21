//cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(begin(costs), end(costs));
        int icecream = 0, i = 0;
        while (i < n && coins > 0) {
            if (coins < costs[i])
                break;
            coins -= costs[i];
            icecream++;
            i++;
        }
        return icecream;
    }
};
