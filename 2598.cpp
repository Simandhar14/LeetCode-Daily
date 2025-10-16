class Solution {
public:
    int binarySearch(vector<int>& nums) {
        for (int i = 0; i <= nums.back(); i++) { //find the smallest possible positive integer
            auto it = lower_bound(begin(nums), end(nums), i);
            if (*it > i)
                return i;
        }
        return nums.back() + 1; 
    }
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        for (int& num : nums) {
            num = ((num % value) + value) % value; //convert number to closest possible +ve number
        }
        sort(begin(nums), end(nums)); 
        int count = 1;
        int num = nums[0];
        int i = 1;
        while (i < n) { //here we are just adding the value based on the frequency of the same element
            while (i < n && nums[i] == num) {
                nums[i] += (value * count);
                count++;
                i++;
            }
            if (i < n) {
                num = nums[i];
                count = 1;
            }
            i++;
        }
        sort(begin(nums), end(nums)); //sort to perform binary search
        return binarySearch(nums);
    }
};
