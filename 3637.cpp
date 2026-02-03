//cpp-better approach
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;
        
        int i = 0;
        while (i + 1 < n && nums[i] < nums[i+1]) {
            i++;
        }
        if (i == 0 || i == n - 1) return false;
        int p = i;
        while (i + 1 < n && nums[i] > nums[i+1]) {
            i++;
        }
        if (i == p || i == n - 1) return false;
        while (i + 1 < n && nums[i] < nums[i+1]) {
            i++;
        }
        return i == n - 1;
    }
};

//cpp
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for (int p = 1; p < n - 2; p++) {
            for (int q = p + 1; q < n-1; q++) {
                bool increasing = true;
                for (int idx = 0; idx < p; idx++) {
                    if (nums[idx] >= nums[idx + 1]) {
                        increasing = false;
                        break;
                    }
                }
                if (!increasing)
                    continue;
                bool decreasing = true;
                for (int idx = p; idx < q; idx++) {
                    if (nums[idx] <= nums[idx + 1]) {
                        decreasing = false;
                        break;
                    }
                }
                if (!decreasing)
                    continue;
                for (int idx = q; idx < n - 1; idx++) {
                    if (nums[idx] >= nums[idx + 1]) {
                        increasing = false;
                        break;
                    }
                }
                if (!increasing)
                    continue;
                return true;
            }
        }
        return false;
    }
};

//java
class Solution {
    public boolean isTrionic(int[] nums) {
         int n = nums.length;
        for (int p = 1; p < n - 2; p++) {
            for (int q = p + 1; q < n-1; q++) {
                boolean increasing = true;
                for (int idx = 0; idx < p; idx++) {
                    if (nums[idx] >= nums[idx + 1]) {
                        increasing = false;
                        break;
                    }
                }
                if (!increasing)
                    continue;
                boolean decreasing = true;
                for (int idx = p; idx < q; idx++) {
                    if (nums[idx] <= nums[idx + 1]) {
                        decreasing = false;
                        break;
                    }
                }
                if (!decreasing)
                    continue;
                for (int idx = q; idx < n - 1; idx++) {
                    if (nums[idx] >= nums[idx + 1]) {
                        increasing = false;
                        break;
                    }
                }
                if (!increasing)
                    continue;
                return true;
            }
        }
        return false;
    }
}
