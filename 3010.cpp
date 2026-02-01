//cpp - better approach
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int minNum1 = INT_MAX;
        for (int i = 1; i < n; i++) {
            minNum1 = min(minNum1, nums[i]);
            ;
        }
        int freq = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == minNum1)
                freq++;
        }
        if (freq >= 2)
            return nums[0] + minNum1 * 2;
        int minNum2 = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] != minNum1) {
                minNum2 = min(minNum2, nums[i]);
            }
        }
        return nums[0] + minNum1 + minNum2;
    }
};

//cpp-brute force
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int minCost = INT_MAX;
        for (int j = 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                minCost = min(minCost, nums[0] + nums[j] + nums[k]);
            }
        }
        return minCost;
    }
};

//java-better approach
class Solution {
    public int minimumCost(int[] nums) {
        int minNum1=Integer.MAX_VALUE;
        int n=nums.length;
        for(int i=1;i<n;i++)
        {
            minNum1=Math.min(minNum1,nums[i]);
        }
        int freq=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==minNum1) freq++;
        }
        if(freq>1) return nums[0]+minNum1*2;
        int minNum2=Integer.MAX_VALUE;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=minNum1) minNum2=Math.min(minNum2,nums[i]);
        }
        return nums[0]+minNum1+minNum2;
    }
}
