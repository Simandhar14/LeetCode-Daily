///dutch national flag algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0){
                swap(nums[mid++],nums[low++]);
            }else if(nums[mid]==2){
                swap(nums[mid],nums[high--]);
            }else mid++;
        }  
    }
};
