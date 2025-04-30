class Solution {
public:
int countdigits(int num)
{
    string str=to_string(num);
    return str.size();
}
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int num:nums)
        {
            int digits=countdigits(num);
            if(digits%2==0) count++;
        }
        return count;
    }
};
