class Solution {
public:
void solve( vector<vector<int>>&result,vector<int>&nums,int i,vector<int>&temp)
{
    if(i==nums.size()) return;
    temp.push_back(nums[i]);
    result.push_back(temp);
    solve(result,nums,i+1,temp);
    temp.pop_back();
    solve(result,nums,i+1,temp);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        solve(result,nums,0,temp);
        result.push_back({});
        return result;
    }
};

