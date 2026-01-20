//cpp-brute force
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int num=0;num<nums[i];num++)
            {
                int val=num | (num+1);
                if(val==nums[i]) {
                    ans[i]=num;
                    break;
                }
            }
        }
        return ans;
    }
};

//java - brute force
class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        for (int i = 0; i < n; i++) {
            if (nums.get(i) % 2 == 0) continue;
            for (int num = 0; num < nums.get(i); num++) {
                int value = num | (num + 1);
                if (value == nums.get(i)) {
                    ans[i] = num;
                    break;
                }
            }
        }
        return ans;
    }
}

//cpp-better approach
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) continue;
            for(int j=0;j<32;j++){
                int bit=nums[i] & (1<<j);
                if(bit>0) continue;
                ans[i]=nums[i] ^ (1<<(j-1));
                break;
            }
        }
        return ans;
    }
};

//java-better approach
class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        for (int i = 0; i < n; i++) {
            if (nums.get(i) % 2 == 0) continue;
            for (int j = 0; j < 32; j++) {
               int bit = nums.get(i) & (1<<j);
               if(bit>0) continue;
               ans[i]=nums.get(i) ^ (1<<(j-1));
               break;
            }
        }
        return ans;
    }
}

