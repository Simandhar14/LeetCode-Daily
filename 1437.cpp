class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int index=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) continue;
            if(index==-1)
            {
                index=i;
            }else{
                if(i<=index+k) return false;
                index=i;
            }
        }
        return true;
    }
};
