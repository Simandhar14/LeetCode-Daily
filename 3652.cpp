class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefix(n, 0);
        vector<long long>prefixprices(n,0);
        long long result = LLONG_MIN;
        prefix[0] = strategy[0] * prices[0];
        prefixprices[0]=prices[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + strategy[i] * prices[i];
            prefixprices[i]=prefixprices[i-1]+prices[i];
        }
        int i = 0;
        for (int j = k - 1; j < n; j++) {
            long long rightsum = 0, leftsum = 0;
            if (j < n - 1) {
                rightsum = prefix[n - 1] - prefix[j];
            }
            if (i-1 >= 0)
                leftsum = prefix[i-1];
            long long windowsum = prefixprices[j]-prefixprices[i-1+k/2];
            result=max(result,leftsum+windowsum+rightsum);
            i++;
        }
        return max(result,prefix[n-1]);
    }
};
