//cpp
class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        ll lower = 1000;
        ll comma = 1;
        ll count = 0;
        while (lower <= n) {
            ll upper = min(1000 * lower - 1, n);
            count += (upper - lower + 1) * comma;
            lower *= 1000;
            comma++;
        }
        return count;
    }
};
