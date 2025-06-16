class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i=1;i<=n;i++)
        {
            result.emplace_back(i);
        }
        sort(begin(result),end(result),[&](int a,int b)
        {
            string ss1=to_string(a);
            string ss2=to_string(b);
            return ss1<ss2;
        });
        return result;
        
    }
};

//using recursion
class Solution {
public:
void solve(vector<int>&result,int n,int i){
    if(i>n) return;
    result.push_back(i);
    for(int j=0;j<=9;j++)
    {
        solve(result,n,(i*10)+j);
    }
}
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i=1;i<=9;i++)  solve(result,n,i);
        return result;
    }
};
