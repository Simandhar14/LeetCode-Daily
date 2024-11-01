class Solution {
public:
    string makeFancyString(string s) {
        string result="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(i>0 && i<n-1 && s[i-1]==s[i] && s[i]==s[i+1]) continue;
            else result.push_back(s[i]);
        }
        return result;
    }
};