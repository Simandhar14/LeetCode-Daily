class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>result;
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i+=3)
        {
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];
            if(c-b<=k && b-a<=k && c-a<=k) result.push_back({a,b,c});
            else return {};
        }
        return result;
    }
};
