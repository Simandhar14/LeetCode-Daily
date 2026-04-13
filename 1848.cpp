//cpp
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int minDist=INT_MAX;
        for(int i=start;i<n;i++)
        {
            if(nums[i]==target)
            {
                minDist=min(minDist,i-start);
                break;
            }
        }
        for(int i=start-1;i>=0;i--)
        {
             if(nums[i]==target)
            {
                minDist=min(minDist,start-i);
                break;
            }
        }
        return minDist;
    }
};
