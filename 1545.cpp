//cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++)
        {
            string str=s+"1";
            for(int j=s.size()-1;j>=0;j--)
            {
                str+= s[j]=='0' ? "1" : "0";
            }
            s=str;
            if(k<=s.size()) return s[k-1];
        }
        return s[k-1];
    }
};
