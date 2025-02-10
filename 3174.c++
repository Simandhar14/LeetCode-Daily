class Solution {
public:
    string clearDigits(string s) {
        string result="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(!result.empty())
            {
                if(isdigit(s[i]) && isalpha(result.back())) result.pop_back();
                else result.push_back(s[i]);
            }  else result.push_back(s[i]);
        }
        return result;
    }
};