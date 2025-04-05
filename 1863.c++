class Solution {
public:
int totalxor=0;
void solve(vector<int>& nums,int xorsum,int i)
{
    if(i>=nums.size()) {
        totalxor+=xorsum;
        return;
    }
    solve(nums,xorsum ^ nums[i],i+1);
    solve(nums,xorsum,i+1);
}
    int subsetXORSum(vector<int>& nums) {
        int xorsum=0;
        solve(nums,xorsum,0);
        return totalxor;
    }
};
