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

//without extra space
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int &i:nums){
            i+=n;
        }
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i])%n;
            if(nums[index]<0) ans.push_back(abs(nums[i])%n);
            else nums[index]*=-1;
        }
        return ans;
    }
};
