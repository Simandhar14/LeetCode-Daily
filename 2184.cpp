//cpp
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxnum = *max_element(begin(nums), end(nums));
        int n=nums.size();
        if(n!=maxnum+1) return false;
        vector<int>freq(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=n) return false;
            freq[nums[i]]++;
        }
        for(int i=1;i<n;i++)
        {
            if(freq[i]==0 || freq[i]>1 && i!=n-1) return false;
        }
        return true;
    }
};
