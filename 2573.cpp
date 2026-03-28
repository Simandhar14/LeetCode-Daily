//brute force 
class Solution {
public:
bool check(string str,vector<vector<int>>& lcp)
{
    int n=str.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            string a=str.substr(i);
            string b=str.substr(j);
            string prefix="";
            int index=0;
            while(index<a.length() && index<b.length() && a[index]==b[index])
            {
                prefix.push_back(a[index]);
                index++;
            }
            if(prefix.length()!=lcp[i][j]) return false;
        }
    }
    return true;
}
    string solve(string str, int n, vector<vector<int>>& lcp) {
        if (n == 0) {
            if (check(str, lcp))
                return str;
            return "";
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            str.push_back(ch);
            string result = solve(str, n - 1, lcp);
            if (!result.empty())
                return result;
            str.pop_back();
        }
        return "";
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string str = "";
        return solve(str, n, lcp);
    }
};
