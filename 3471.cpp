//cpp
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n) return *max_element(begin(nums),end(nums));
        vector<int>freq(51,0);
        for(int i=0;i+k<=n;i++)
        {
            for(int j=i;j<i+k;j++)
            {
                freq[nums[j]]++;
            }
        }
        for(int i=50;i>=0;i--)
        {
            if(freq[i]==1) return i;
        }
        return -1;
    }
};
