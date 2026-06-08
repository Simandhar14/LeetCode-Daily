//cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>result(n,0);
        int left=0,right=n-1;
        for(int i=0,j=n-1;i<n,j>=0;i++,j--)
        {
            if(nums[i]<pivot)
            {
                result[left]=nums[i];
                left++;
            }
            if(nums[j]>pivot)
            {
                result[right]=nums[j];
                right--;
            }
        }
        while(left<=right)
        {
            result[left]=pivot;
            left++;
        }
        return result;
    }
};
