class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int distinct = 1;
        int n = nums.size();
        nums[0] = nums[0] - k;
        int prev = nums[0];
        for (int i = 1; i < n; i++) {
            int smallest = nums[i] - k;
            int largest = nums[i] + k;
            if (smallest > nums[i - 1]) {
                distinct++;
                nums[i] = smallest;
                prev = nums[i];
            } else {
                if (prev < largest) {
                    distinct++;
                    nums[i] = prev + 1;
                    prev = nums[i];
                } 
            }
        }
        return distinct;
    }
};
