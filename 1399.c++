class Solution {
public:
    int countLargestGroup(int n) {
        vector<int>freq(n+1,0);
        int count=0;
        int maxgrpsize=0;
        for(int i=1;i<=n;i++)
        {
            int num=i;
            int digitsum=0;
            while(num>0)
            {
                digitsum+=num%10;
                num/=10;
            }
            freq[digitsum]++;
            if(freq[digitsum]>maxgrpsize) {
                maxgrpsize=freq[digitsum];
                count=1;
            }else if(freq[digitsum]==maxgrpsize) count++;
        }
        return count;
    }
};
