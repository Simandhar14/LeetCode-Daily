class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int remNeeded = total % p;
        if (remNeeded == 0) return 0; 
        
        unordered_map<int, int> mp;
        mp[0] = -1;  
        
        int res = nums.size();
        long long curr = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            curr = (curr + nums[i]) % p;
            int target = (curr - remNeeded + p) % p;  
            
            if (mp.count(target))
                res = min(res, i - mp[target]);
            
            mp[curr] = i;  
        }
        
        return res == nums.size() ? -1 : res;
    }
};
