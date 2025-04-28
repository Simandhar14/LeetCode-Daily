//brute force 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int length=1;
            long long sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                if(sum * length < k) result++;
                else break;
                length++;
                
            }
        }
        return result;
    }
};

//sliding window 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result=0;
        int n=nums.size();
        int i=0;
        long long sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];
            int length=j-i+1;
            while(i<j && sum * length>=k)
            {
                sum-=nums[i];
                i++;
                length=j-i+1;
            }
            if(sum * length <k) result+=length;
        }

        return result;
    }
};
