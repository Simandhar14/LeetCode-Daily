class Solution {
public:
    long long result = LLONG_MAX;
    bool check(vector<int>& rank, int totalcars, long long minutes) {
        int repairedcars = 0;
        for (int i = 0; i < rank.size(); i++) {
            int cars = sqrt(minutes / rank[i]);
            repairedcars += cars;
            if (repairedcars >= totalcars) {
                result = min(result, minutes);
                return true;
            }
        }
        if (repairedcars >= totalcars) {
            result = min(result, minutes);
            return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(ranks, cars, mid) == true) {
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return result;
    }
};
