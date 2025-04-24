class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        unordered_set<int>st;
        for(int num:nums)
        {
            st.insert(num);
        }
        int i=0;
        int count=0;
        int n=nums.size();
        for(int j=0;j<n;j++)
        {
            mp[nums[j]]++;
            while(mp.size()==st.size() && i<n)
            {
                count+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
        }
        return count;
    }
};
