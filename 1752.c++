//brute force
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool peakFound = false;
        int minval=nums[0];
        int maxPeak = -1;
        for (int i = 0; i < n; i++) {
            if (maxPeak == -1) {
                minval=min(minval,nums[i]);
                if (i < n - 1 && nums[i] > nums[i + 1])
                    maxPeak = nums[i];
            } else {
                if (nums[i] > maxPeak || (i<n-1 && nums[i]>nums[i+1]))
                    return false;
            }
        }
        if(maxPeak!=-1 && nums.back()>minval) return false;
        return true;
    }
};

//better approach
class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i%n]>nums[(i+1)%n]) count++;
        }
        return count<=1;
    }
};
