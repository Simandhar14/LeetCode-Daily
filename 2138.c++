class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string>result;
        string temp="";
        for(char c:s)
        {
            temp=temp+c;
            if(temp.size()==k)
            {
                result.emplace_back(temp);
                temp.erase();
            }
        }
        if(!temp.empty())
        {
            while(temp.size()!=k)
            {
                temp=temp+fill;
            }
            result.emplace_back(temp);
        }
        return result;
    }
};
