class Solution {
public:
const int MOD=1e9+7;
long long findpower(long long a,long long b)
{
    if(b<=0) return 1;
    long long half=findpower(a,b/2)%MOD;
    long long result=(half*half)%MOD;
    if(b%2==1) result=(result*a)%MOD;
    return result;
}
    int countGoodNumbers(long long n) {
        long long evenpos = (n + 1) / 2;
long long oddpos = n / 2;
        long long val1=findpower(5,evenpos)%MOD;
        long long val2=findpower(4,oddpos)%MOD;
        return (val1 * val2)%MOD;
    }
};
