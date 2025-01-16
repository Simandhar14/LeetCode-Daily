class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int result=0;
        if(m%2!=0)
        {
            for(int num:nums2)
            {
                result^=num;
            }
        }
         if(n%2!=0)
        {
            for(int num:nums1)
            {
                result^=num;
            }
        }
        return result;
    }
};