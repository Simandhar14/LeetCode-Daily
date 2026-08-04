//cpp
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int start = *min_element(begin(nums), end(nums));
        int ending = *max_element(begin(nums), end(nums));
        vector<int> freq(ending + 1, 0);
        vector<int> missing;
        for (int& num : nums)
            freq[num]++;
        for (int i = start; i <= ending; i++)
            if (freq[i] == 0)
                missing.push_back(i);
        return missing;
    }
};
