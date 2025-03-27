class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>count;
        for(int num:nums)
        {
            count[num]++;
        }
        unordered_map<int,int>countatidx;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            countatidx[nums[i]]++;
            int rightlen=n-i-1;
            int leftlen=i+1;
            int rightcount=count[nums[i]] - countatidx[nums[i]];
            if(countatidx[nums[i]] > (floor(leftlen)/2) && rightcount > (floor(rightlen)/2)) {
                return i;
            }
        }
        return -1;
    }
};
