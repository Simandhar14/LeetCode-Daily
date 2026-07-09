class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<bool> result;

        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v)
                result.push_back(true);
            else {
                int left = min(u, v);
                int right = max(u, v);
                bool found = false;
                while (left < right) {
                    int newLeft = left + 1;
                    if (nums[right] - nums[left] <= maxDiff) {
                        found = true;
                        break;
                    }
                    while (newLeft < right &&
                           nums[newLeft] - nums[left] <= maxDiff) {
                        newLeft++;
                    }
                    if (newLeft == left + 1)
                        break;
                    left = newLeft-1;
                }
                result.push_back(found);
            }
        }

        return result;
    }
};
