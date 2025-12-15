class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long result = 0;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i] == prices[i - 1] - 1) {
                result += count;
                count++;
            } else {
                result += count;
                count = 1;
            }
        }
        return result+count;
    }
};
