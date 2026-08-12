//cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;
        unordered_map<int,int>mp;
        int j=0,i=0;
        while(j<n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                while(i<j && mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};
