class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int a=1;a<=n;a++)
        {
            for(int b=a;b<=n;b++)
            {
                for(int c=a;c<=n;c++)
                {
                    if(a==sqrt((c+b) * (c-b))) count+=2;
                }
            }
        }
        return count;
    }
};

//optimal approach

class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int a=1;a<=n;a++)
        {
            for(int b=a+1;b<=n;b++)
            {
               int sum=a*a + b*b;
               int sqrtval=sqrt(sum);
               if((sqrtval*sqrtval)==sum && sqrtval<=n) count+=2;
            }
        }
        return count;
    }
};
