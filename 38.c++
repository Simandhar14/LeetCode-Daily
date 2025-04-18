class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string lastresult=countAndSay(n-1);
        string result="";
        int count=1;
        char ch=lastresult[0];
        for(int i=1;i<lastresult.length();i++)
        {
            if(ch!=lastresult[i])
            {
                result.push_back(count+'0');
                result.push_back(ch);
                ch=lastresult[i];
                count=1;
            }else count++;
        }
        result.push_back(count+'0');
        result.push_back(ch);
        return result;
    }
};
