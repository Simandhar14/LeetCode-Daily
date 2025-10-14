class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = i + k;
        int n = nums.size();
        while (j + k - 1 < n) {
            int start = i;
            int end = i + k - 1;
            bool notincreasing1=false,notincreasing2=false;
            while (start <= end - 1) {
                if (nums[start] >= nums[start + 1]) {
                    notincreasing1 = true;
                    break;
                }
                start++;
            }
            start = j;
            end = j + k - 1;
            while (start <= end - 1) {
                if (nums[start] >= nums[start + 1]) {
                    notincreasing2 = true;
                    break;
                }
                start++;
            }
            if (!notincreasing1 && !notincreasing2)
                return true;
            i++;
            j++;
        }
        return false;
    }
};

//optimal approach
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int subarraySize = 1;
        int l1 = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                subarraySize++;
            } else {
                if (l1 >= 2 * k || subarraySize >= 2 * k)
                    return true;
                else if (l1 >= k && subarraySize >= k)
                    return true;
                l1 = subarraySize;
                subarraySize = 1;
            }
        }
        if (l1 >= 2 * k || subarraySize >= 2 * k)
            return true;
        else if (l1 >= k && subarraySize >= k)
            return true;
        return false;
    }
};
