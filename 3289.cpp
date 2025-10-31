class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>sneakyNumbers;
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(st.count(nums[i]))
            {
                sneakyNumbers.emplace_back(nums[i]);
            }
            else st.insert(nums[i]);
        }
        return sneakyNumbers;
    }
};
