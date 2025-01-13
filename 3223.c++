class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(char ch: s)
        {
            int idx=ch-'a';
            freq[idx]++;
            if(freq[idx]==3) freq[idx]=1;
        }
        int result=0;
        for(int n:freq)
        {
            if(n==0) continue;
            result+=n;
        }
        return result;
    }
};