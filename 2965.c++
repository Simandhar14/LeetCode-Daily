class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a=-1,b=1;
        int sum=0;
        int n=grid.size();
        n*=n;
        unordered_set<int>st;
        for(auto temp:grid)
        {
            for(int n:temp)
            {
                if(st.find(n)!=st.end()) a=n;
                else sum+=n;
                st.insert(n);
            }
        }
        int totalsum= (n* ( n+1))/2;
        return {a,totalsum-sum};
    }
};