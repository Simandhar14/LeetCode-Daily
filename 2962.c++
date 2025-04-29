class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxnum=*max_element(begin(nums),end(nums));
        int count=0;
        int n=nums.size();
        long long result=0;
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]==maxnum) count++;
            while(i<=j && count==k)
            {
                result+=n-j;
                if(nums[i]==maxnum) count--;
                i++;
            }
        }
        return result;
    }
};

//2nd way

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> index;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxNum) {
                index.push_back(i);
            }
            int len = index.size();
            if (len >= k) {
                result += index[len - k] + 1;
            }
        }

        return result;
    }
};
