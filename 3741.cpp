//cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, pair<int,int>> mp; 
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (mp.count(x)) {
                auto &[prev2, prev1] = mp[x];

                if (prev2 != -1) {
                    ans = min(ans, 2 * (i - prev2));
                }
                prev2 = prev1;
                prev1 = i;
            } else {
                mp[x] = {-1, i};
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
