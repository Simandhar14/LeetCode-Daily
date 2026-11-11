//cpp
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long both = min(need1, need2);

        long long allSeparate = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        long long allBoth     = 1LL * costBoth * max(need1, need2);
        long long mixed       = 1LL * costBoth * both
                              + 1LL * cost1 * (need1 - both)
                              + 1LL * cost2 * (need2 - both);

        return min({allSeparate, allBoth, mixed});
    }
};
