class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string x="";
        string num=to_string(n);
        for(int i=0;i<num.length();i++)
        {
            char ch=num[i];
            if(ch-'0'>0) x.push_back(ch);
        }
        long long sum=0;
        for(int i=0;i<x.length();i++) sum+=x[i]-'0';
        return 1LL * stoi(x) * sum;
    }
};
