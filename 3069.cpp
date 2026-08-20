//cpp
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result;
        vector<int> arr2;
        int n = nums.size();
        result.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < n; i++) {
            if (result.back() > arr2.back())
                result.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        for (int& num : arr2)
            result.push_back(num);
        return result;
    }
};
