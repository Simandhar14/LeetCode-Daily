class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        bool even=true;
        for(int i=0;i<n;i++)
        {
            int number=nums[i];
            if(i>0)
            {
                if(number%2==0 && even==true) return false;
                else if(number%2!=0 && even==false) return false;
                even=!even;
            }else
            {
                if(number%2==0) even=true;
                else even=false;
            }
        }
        return true;
    }
};