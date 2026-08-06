//cpp
class Solution {
public:
bool check(int num,int t){
    int product=1;
    while(num>0)
    {
        int d=num%10;
        if(d==0) return true;
        product*=d;
        num/=10;
    }
    return product % t == 0;
}
    int smallestNumber(int n, int t) {
        while(true){
            if(check(n,t)) return n;
            n++;
        }
        return -1;
    }
};
