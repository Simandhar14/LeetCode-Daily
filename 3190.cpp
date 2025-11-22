class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations=0;
        for(int &n:nums)
        {
            if(n%3==0) continue;
            operations+=min(n%3 , 3-n%3);
        }
        return operations;
    }
};

//better approach
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(), [&](int x){
            return x%3!=0; });
    }
};

