//cpp
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost));
        if (cost.size() == 1)
            return cost[0];
        int i = cost.size() - 1;
        int minCost = 0;
        while (i - 1 >= 0) {
            minCost += cost[i] + cost[i - 1];
            i -= 3;
        }
        return minCost + (i >= 0 ? cost[i] : 0);
    }
};
