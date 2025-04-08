class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>mp(101,0);
        int n=nums.size();
        int index=-1;
        for(int i=n-1;i>=0;i--)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
            {
                index=i;
                break;
            }
        }
        if(index==-1) return 0;
        int operations=ceil((double)(index+1)/3);
        return operations;
    }
};
