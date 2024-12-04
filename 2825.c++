class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.length();
        int len=str2.length();
        int j=0,i=0;
        while(i<n && j<len)
        {
            if(str1[i]==str2[j] || str1[i]+1==str2[j] || str1[i]-25==str2[j]) j++;
            i++;
        }
        return j==len;
    }
};