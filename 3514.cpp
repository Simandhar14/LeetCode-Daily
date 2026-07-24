//cpp-brute force
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>st;
        unordered_set<int>result;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                st.insert(nums[i] ^ nums[j]);
            }
        }
        for(auto it=begin(st);it!=end(st);it++)
        {
            int xorval=*it;
            for(int &num:nums)
            {
                result.insert(xorval^num);
            }
        }
        return result.size();
    }
};
