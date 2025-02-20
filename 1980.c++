class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string>st(begin(nums),end(nums));
        for(int i=0;i<=n;i++)
        {
            string num=bitset<16>(i).to_string().substr(16-n);
            if(st.find(num)==st.end()) return num;
        }
        return "";
    }
};

//Backtracking

class Solution {
public:
string result;
void solve(int n,unordered_set<string>&st,string &temp)
{
    if(temp.size()==n)
    {
        if(st.find(temp)==st.end()) result=temp;
        return;
    }
    for(char ch='0';ch<='1';ch++)
    {
        temp.push_back(ch);
        solve(n,st,temp);
        temp.pop_back();
    }
}
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st(begin(nums),end(nums));
        int n=nums.size();
        string temp="";
        solve(n,st,temp);
        return result;
    }
};