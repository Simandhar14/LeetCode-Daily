class Solution {
public:
vector<long long>dp;
    long long solve(unordered_map<int, int>& map, vector<int>& power, int i) {
        if (i >= power.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        long long take = 0,skip=0;
        skip +=solve(map, power, i + 1);
        auto it = upper_bound(begin(power) + i, end(power), power[i] + 2);
        int idx = it - begin(power);
        take += (1LL*power[i]*map[power[i]]) + solve(map, power, idx);
        return dp[i]=max(take, skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        long long maxDamage = 0;
        unordered_map<int, int> map;
        dp.resize(100001,-1);
        sort(begin(power), end(power));
        for (int n : power) {
            map[n]++;
        }
        return solve(map, power, 0);
    }
};
