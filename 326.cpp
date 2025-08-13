//recursion
class Solution {
public:
bool solve(int n)
{
    if(n==1) return true;
    if(n%3!=0) return false;
    return solve(n/3);
}
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        return solve(n);
    }
};

//another approach
class Solution {
public:
long long calculate(int a,int b)
{
    if(b==0) return 1;
    long long half=calculate(a,b/2);
    long long result=half*half;
    if(b%2==1) result*=a;
    return result;
}
    bool isPowerOfThree(int n) {
        int power=0;
        long long powerval=calculate(3,power); 
        unordered_set<long long>st;
        while(powerval<=n)
        {
            st.insert(powerval);
            st.insert(1/powerval);
            power++;
            powerval=calculate(3,power);
        }
        return st.count(n);
    }
};
