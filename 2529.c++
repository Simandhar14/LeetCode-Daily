class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int negative=0;
        int i=0;
        while(i<n)
        {
             if(nums[i]==0) {
                i++;
                continue;
             }
             else if(nums[i]<0) negative++;
             else break;
             i++;
        }
        return max(negative,n-i);
    }
};

//binary search 
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto loweridx=lower_bound(begin(nums),end(nums),0);
        auto upperidx=upper_bound(begin(nums),end(nums),0);
        return max(loweridx-nums.begin(),nums.end()-upperidx);
    }
};