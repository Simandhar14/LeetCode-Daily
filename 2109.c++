class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int idx=0;
        int i=0;
        int n=s.length();
        while(i<n)
        {
            if(idx<spaces.size() && i==spaces[idx])
            {
                ans+=" ";
                idx++;
            }else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};