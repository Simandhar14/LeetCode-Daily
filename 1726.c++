class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }

        int count = 0;
        for (auto temp : mp) {
            int size = temp.second; 
            if (size >= 2) count += 4 * size * (size - 1); 
        }
        return count;
    }
};
