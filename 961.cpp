//best approach

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i-1]==nums[i] || i>1 && nums[i-2]==nums[i]) return nums[i];
        }
        if(nums[0]==nums.back()) return nums[0];
        return -1;
    }
};

//using bitset
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        bitset<10001>freq;
        for(int &num:nums)
        {
            if(freq[num]==1) return num;
            freq[num]=1;
        }
        return -1;
    }
};
