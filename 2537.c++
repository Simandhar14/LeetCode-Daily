class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<long long,long long>mp;
        long long totalpairs=0;
        long long countgood=0;
        int n=nums.size();
        int i=0;
        for(int j=0;j<n;j++)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]>=2) totalpairs+=mp[nums[j]]-1;
            while(i<n && totalpairs>=k)
            {
                countgood+=n-j;
                if(mp[nums[i]]>=2)totalpairs=totalpairs-(mp[nums[i]]-1);
                mp[nums[i]]--;
                i++;
            }
        }
        return countgood;
    }
};
