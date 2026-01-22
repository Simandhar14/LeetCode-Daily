//cpp
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
          int count = 0;
        while (true) {
            int i = 0;
            while (i < nums.size() - 1) {
                if (nums[i] > nums[i + 1])
                    break;
                i++;
            }
            if (i == nums.size() - 1)
                return count;
            count++;
            int index = 0;
            int sum = nums[1];
            int minsum = nums[0] + nums[1];
            for (int i = 1; i < nums.size() - 1; i++) {
                if (sum + nums[i + 1] < minsum) {
                    index = i;
                    minsum = sum + nums[i + 1];
                }
                sum = nums[i + 1];
            }
            nums[index] = minsum;
            nums.erase(begin(nums) + index + 1);
        }
        return 0;
    }
};
