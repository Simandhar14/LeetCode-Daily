//cpp
class Solution {
public:
    string processStr(string s) {
        string result="";
        for(char &ch:s)
        {
            if(ch>='a' && ch<='z') result.push_back(ch);
            else{
                if(ch=='#') result+=result;
                else if(ch=='%') reverse(begin(result),end(result));
                else{
                    if(!result.empty()) result.pop_back();
                }
            }
        }
        return result;
    }
};
