class Solution {
public:
int power(int a,int b)
{
    if(b==0) return 1;
    int half=power(a,b/2);
    int result=half*half;
    if(b%2==1) result*=a;
    return result;
}
    int countTriples(int n) {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=i;k<=n;k++)
                {
                    int a=power(i,2);
                    int b=power(j,2);
                    int c=power(k,2);
                    if((a+b)==c) count+=2;
                }
            }
        }
        return count;
    }
};
