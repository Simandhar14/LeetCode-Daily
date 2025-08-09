class Solution {
public:
long long calculate(long long a,long long b)
{
    if(b==0) return 1;
    long long half=calculate(a,b/2);
    long long result=half * half;
    if(b%2==1)
    {
        result*=a;
    }
    return result;
}
    bool isPowerOfTwo(int n) {
        for(int i=0;i<=n/2;i++)
        {
            long long val=calculate(2,i);
            if(val>n) return false;
            if(val==n) return true;
        }
        return false;
    }
};
