class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long nums1sum = accumulate(begin(nums1), end(nums1), 0LL);
        long long nums2sum = accumulate(begin(nums2), end(nums2), 0LL);
        long long nums1zero = count(begin(nums1), end(nums1), 0);
        long long nums2zero = count(begin(nums2), end(nums2), 0);
        long long minsum1=nums1sum+nums1zero;
        long long minsum2=nums2sum+nums2zero;
        if(nums1sum>nums2sum && nums2zero==0 || nums2sum>nums1sum && nums1zero==0 ) return -1;
        return max(minsum1,minsum2);
    }
};
