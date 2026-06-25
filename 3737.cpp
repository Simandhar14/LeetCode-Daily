//brute force
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int result=0;
        for(int i=0;i<n;i++)
        {
            int freq=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==target) freq++;
                int len=j-i+1;
                if(freq>len/2) result++;
            }
        }
        return result;
    }
};

//optimal
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;   
        
        int currSum = 0;
        
        mp[0] = 1; 

        long long validLeftPoints = 0;

        long long result = 0;

        for (int x : nums) {
            if (x == target) {
                validLeftPoints += mp[currSum];
                currSum++;
            } else {
                currSum--;
                validLeftPoints -= mp[currSum];
            }

            mp[currSum]++;

            result += validLeftPoints;
        }

        return result;
    }
};
