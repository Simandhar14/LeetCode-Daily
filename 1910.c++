//Brute Force

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len=part.length();
        while(s.find(part)!=string::npos)
        {
            size_t index=s.find(part);
            s.erase(index,len);
        }
        return s;
    }
};

//Stack method using string

class Solution {
public:
bool check(string result,string part)
{
    for(int i=part.length()-1;i>=0;i--)
    {
        if(part[i]!=result.back()) return false;
        result.pop_back();
    }
    return true;
}
    string removeOccurrences(string s, string part) {
        int len=part.length();
        string result="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            result.push_back(s[i]);
            if(result.size()>=len && check(result,part))
            {
                for(int j=0;j<len;j++)
                {
                    result.pop_back();
                }
            }
        }
        return result;
    }
};