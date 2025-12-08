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

//using extra space but better time complexity

class Solution {
public:
    int countTriples(int n) {
        int count=0;
        unordered_set<int>a2;
        for(int a=1;a<=n;a++)
        {
            a2.insert(a*a);
        }
        for(int b=1;b<=n;b++)
        {
            for(int c=b;c<=n;c++)
            {
                int multiply=(c+b) * (c-b);
                if(a2.find(multiply)!=a2.end()) count+=1;
            }
        }
        return count;
    }
};
