class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int partitions=0;
        int total=accumulate(begin(nums),end(nums),0);
        int left=0;
        for(int i=0;i<n-1;i++)
        {
            left+=nums[i];
            total-=nums[i];
            bool even1=left%2==0;
            bool even2=total%2==0;
            if(even1==even2) partitions++;
        }
        return partitions;
    }
};
