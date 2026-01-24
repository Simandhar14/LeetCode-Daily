//java
class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        int j = nums.length - 1;
        int maxSum = 0;
        while (i < j) {
            maxSum = Math.max(maxSum, nums[i] + nums[j]);
            i++;
            j--;
        }
        return maxSum;
    }
}

//cpp
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int i = 0;
        int j = nums.size() - 1;
        int maxSum = 0;
        while (i < j) {
            maxSum = max(maxSum, nums[i] + nums[j]);
            i++;
            j--;
        }
        return maxSum;
    }
};
