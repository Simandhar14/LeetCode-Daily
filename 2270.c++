class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total=accumulate(begin(nums),end(nums),0LL);
        long long count=0;
        long long sum=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            sum+=nums[i];
            if(sum>=total-sum) count++;
        }
        return count;
    }
};
