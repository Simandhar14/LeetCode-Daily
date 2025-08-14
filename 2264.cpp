class Solution {
public:
    string largestGoodInteger(string num) {
        string result="";
        string ans="";
        size_t n=num.length();
        char ch='#';
        for(int j=0;j<n;j++)
        {
            if(ch=='#') ch=num[j];
            else if(ch!='#' && ch!=num[j]){
                ch=num[j];
                result="";
                result.push_back(ch);
                continue;
            }
            result.push_back(num[j]);
            if(result.size()==3)
            {
                if(result>ans) ans=result;
                result.pop_back();
            }
            
        }
        return ans;
    }
};
