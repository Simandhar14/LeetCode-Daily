class Solution {
public:
const int MOD=1000000007;
    int numOfSubarrays(vector<int>& arr) {
        int oddsum=0;
        int evensum=0;
        int prefixsum=0;
        int ans=0;
        for(int num:arr)
        {
            prefixsum+=num;
            if(prefixsum%2==0) {
                evensum++;
                ans=(ans+oddsum)%MOD;
            }else
            {
                oddsum++;
                ans=(ans+evensum+1)%MOD;
            }
        }
        return ans;
    }
};