class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int lowercount = 0;
            bool lowerfound = false;
            bool upperfound = false;
            int uppercount = 0;
            int num = nums[i];
            for (int j = 0; j < n; j++) {
                if (nums[j] == num || nums[j] == num - 1) {
                    if (nums[j] == num - 1)
                        lowerfound = true;
                    lowercount++;
                } else if (nums[j] == num || nums[j] == num + 1) {
                    if (nums[j] == num + 1)
                        upperfound = true;
                    uppercount++;
                }
            }
            if (lowerfound) {
                ans = max({ans, lowercount});
            }
            if(upperfound)
            {
                ans = max({ans, uppercount});
            }
        }
        return ans;
    }
};
