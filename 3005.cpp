class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxnum = *max_element(begin(nums), end(nums));
        vector<int> freq(maxnum + 1, 0);
        for (int n : nums)
            freq[n]++;
        int maxfreq = *max_element(begin(freq), end(freq));
        int totalFreq = 0;
        for (int n : freq)
            if (n == maxfreq)
                totalFreq += n;
        return totalFreq;
    }
};
