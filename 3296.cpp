//cpp
class Solution {
public:
    bool check(long long seconds, int mountainHeight, vector<int>& workerTimes) {
        int heightReduced = 0;
        for (int& time : workerTimes) {
            heightReduced += sqrt(((2 * seconds) / time) + 0.25) - 0.5;
        }
        return heightReduced >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 1;
        long long r = ((1LL*mountainHeight * (mountainHeight + 1)) / 2) *
                      *max_element(begin(workerTimes), end(workerTimes))*1LL;
        long long result = r;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (check(mid, mountainHeight, workerTimes)) {
                result = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return result;
    }
};
