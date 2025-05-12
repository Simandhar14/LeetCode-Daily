class Solution {
public:
void solve(unordered_set<string>&st,vector<bool>&visit,vector<int>&digits,string &str)
{
    if(str.size()==3)
    {
        st.insert(str);
        return;
    }
    for(int i=0;i<digits.size();i++)
    {
        if(visit[i] || (str.size()==0 && digits[i]==0) || (str.size()==2 && digits[i]%2!=0)) continue;
        str.push_back(digits[i]+'0');
        visit[i]=true;
        solve(st,visit,digits,str);
        visit[i]=false;
        str.pop_back();
    }
}
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<int> result;
        unordered_set<string>st;
        string str="";
        vector<bool>visit(n,false);
        solve(st,visit,digits,str);
        for(auto str:st)
        {
            result.push_back(stoi(str));
        }
        sort(begin(result),end(result));
        return result;
    }
};
