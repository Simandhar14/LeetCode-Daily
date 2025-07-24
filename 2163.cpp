class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int len=nums.size();
        int n=len/3;
        vector<long long>leftsum(len,0);
        vector<long long>rightsum(len,0);
        priority_queue<long long,vector<long long>,greater<long long>> minheap;
        priority_queue<long long,vector<long long>> maxheap;
        long long sum=0;
        long long mindiff=LLONG_MAX;
        for(int i=0;i<len-n;i++)
        {
            sum+=nums[i];
            maxheap.push(nums[i]);
            if(maxheap.size()>n)
            {
                int top=maxheap.top();
                maxheap.pop();
                sum-=top;
            }
            leftsum[i]=sum;
        }
        sum=0;
        for(int i=len-1;i>=n;i--)
        {
            sum+=nums[i];
            minheap.push(nums[i]);
            if(minheap.size()>n)
            {
                int top=minheap.top();
                minheap.pop();
                sum-=top;
            }
            rightsum[i]=sum;
        }
        for(int i=n-1;i<len-n;i++)
        {
            long long diff=leftsum[i] - rightsum[i+1];
            if(diff<mindiff) mindiff=diff;
        }
        return mindiff;
    }
};
