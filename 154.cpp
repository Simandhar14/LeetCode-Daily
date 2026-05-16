//cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = nums.size() - 1, mid, result = 0;
        while (l <= r) {
            while (l < r && nums[l] == nums[l + 1])
                l++;
            while (r > l && nums[r] == nums[r - 1])
                r--;
            mid = l + (r - l) / 2;
            if (nums[mid] < nums[result])
                result = mid;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return nums[result];
    }
};
