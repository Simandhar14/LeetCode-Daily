class Solution {
public:
    int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, int> mp;
        for (auto& temp : points) {
            int x = temp[0];
            int y = temp[1];
            mp[y]++;
        }
        long long result = 0;
        long long totalLines = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            int count = it->second;
            long long horizontalLines = (1LL *count * (count - 1)) / 2;
            result += (totalLines * horizontalLines);
            totalLines += horizontalLines;
        }
        return result%MOD;
    }
};
