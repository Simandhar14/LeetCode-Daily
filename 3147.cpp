class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=INT_MIN;
        vector<int>prefixsum(begin(energy),end(energy));
        for(int i=k;i<n;i++)
        {
           prefixsum[i]+=prefixsum[i-k];
           if(i+k>=n) ans=max(ans,prefixsum[i]);
        }
         prefixsum.assign(begin(energy),end(energy));
        for(int i=n-1-k;i>=k;i--)
        {
            prefixsum[i]+=prefixsum[i+k];
            ans=max(prefixsum[i],ans);
        }
        for(int i=n-k;i<n;i++)
        {
            ans=max(ans,energy[i]);
        }
        return ans;
    }
};
