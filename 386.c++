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
