//cpp
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

//java
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
