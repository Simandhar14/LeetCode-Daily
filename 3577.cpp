class Solution {
public:
const int MOD=1e9+7;
    int countPermutations(vector<int>& complexity) {
        long long result=1;
        int n=complexity.size();
        sort(begin(complexity)+1,end(complexity));
        for(int i=1;i<n;i++)
        {
            if(complexity[i]==complexity[0] || complexity[i]<complexity[0]) return 0; 
        }
        for(int i=1;i<n;i++)
        {
           result=(result*i)%MOD;
        }
        return result;
    }
};
