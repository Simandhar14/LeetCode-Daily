class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.length();
        while(n>2)
        {
            int prev=s[0]-'0';
            for(int i=1;i<n;i++)
            {
                int curr=s[i]-'0';
                int newval=(prev+curr)%10;
                prev=curr;
                s[i-1]=newval+'0'; 
            }
            n--;
        }
        return s[0]==s[1];
    }
};
