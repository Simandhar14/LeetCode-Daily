class Solution {
public:
bool solve(string num,int i,int value,string &str,int target)
{
    if(i==num.length())
    {
        if(!str.empty())
        {
            value+=stoi(str);
        }
        if(value==target) return true;
        return false;
    }
    string temp=str+num[i];
    bool take=solve(num,i+1,value,temp,target);
    temp=num[i];
    int val=str!=""?stoi(str) : 0;
    bool nottake=solve(num,i+1,value+val,temp,target);
    return take || nottake;
}
bool check(int number,int target)
{
    string num=to_string(number);
    int len=num.length();
    string str="";
    return solve(num,0,0,str,target);
}
    int punishmentNumber(int n) {
        int result=0;
        for(int i=1;i<=n;i++)
        {
            int sq=i*i;
            if(check(sq,i)) result+=sq;
        }
        return result;
    }
};