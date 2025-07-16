class Solution {
public:
int find(int i,vector<int>&nums)
{
    int len=0;
    int n=nums.size();
    bool odd=false;
    bool even=false;
    while(i<nums.size())
    {
        if(nums[i]%2==0) even=true;
        else odd=true;
        len++;
        if(odd)
        {
            while(i<n && nums[i]%2!=0) i++;
            odd=false;
        }else{
             while(i<n && nums[i]%2==0) i++;
             even=false;
        }
    }
    return len;
}
    int maximumLength(vector<int>& nums) {
        int alleven = 0;
        int allodd = 0;
        int alternateodd=0;
        int alternateeven=0;
        int n = nums.size();
        int firsteven = -1;
        int firstodd = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                alleven++;
                if(firsteven==-1) firsteven=i;
            } else{
                allodd++;
                if(firstodd==-1) firstodd=i;
                }
        }
        if(firstodd!=-1){
            alternateodd=find(firstodd,nums);
        }
        if(firsteven!=-1)
        {
            alternateeven=find(firsteven,nums);
        }
        return max({allodd,alleven,alternateodd,alternateeven});
    }
};
