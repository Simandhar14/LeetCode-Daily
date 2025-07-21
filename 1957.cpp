class Solution {
public:
    string makeFancyString(string s) {
        string result="";
        int count=1;
        result.push_back(s[0]);
        for(int i=1;i<s.length();i++)
        {
            char last=result.back();
            if(s[i]!=last)
            {
                result.push_back(s[i]);
                count=1;
            }else{
                if(count<2) {
                    count++;
                    result.push_back(s[i]);
                    }
                else continue;
            }
        }
        return result;
    }
};
