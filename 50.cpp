class Solution {
public:
    double myPow(double a, int n) {
        double ans=1.0;
        long long power=n;
        if(power<0) power=-power;
        while(power>0)
        {
            int bit=power&1;
            if(bit) ans=ans*a;
            power=power>>1;
            a=a*a;
        }
        return n<0 ? 1.0/ans : ans;
    }
};
