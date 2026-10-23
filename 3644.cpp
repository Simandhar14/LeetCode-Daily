//cpp
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> notSorted;
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (i != nums[i])
                notSorted.push_back(i);
        }
        if(notSorted.empty()) return 0; //ascending
        reverse(begin(nums),end(nums)); //descending 
        bool flag=true;
          for (int i = 0; i < n; i++) {
            if (i != nums[i]){
                flag=false;
                break;
            }
        }
        if(flag) return 0;
        for (int bit = 0; bit < 32; bit++) {
            bool flag = true;
            for (int& num : notSorted) {
                int val = num &(1 << bit);
                if (val == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                k += 1 << bit;
        }
        return k;
    }
};
