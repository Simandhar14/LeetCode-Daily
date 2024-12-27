class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>vec(n,0);
        vec[0]=values[0];
        for(int i=1;i<n;i++)
        {
            vec[i]=max(vec[i-1],values[i]+i);
        }
        int ans=0;
        for(int j=1;j<n;j++)
        {
            ans=max(ans,values[j]-j+vec[j-1]);
        }
        return ans;
    }
};