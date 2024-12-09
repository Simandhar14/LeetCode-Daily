class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>result;
        int n=nums.size();
        vector<int>cumulative(n,0);
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]%2 == nums[i]%2)
            {
                cumulative[i]=cumulative[i-1]+1;
            }else   cumulative[i]=cumulative[i-1];
        }
        for(auto temp:queries)
        {
            int start=temp[0];
            int end=temp[1];
            if(cumulative[end]-cumulative[start]==0) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};