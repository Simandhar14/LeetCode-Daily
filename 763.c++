class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastseen(26,-1);
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            int idx=ch-'a';
            lastseen[idx]=i;
        }
        int i=0;
        vector<int>partition;
        int maxlastseen=-1;
        for(int j=0;j<n;j++)
        {
            char ch=s[j];
            maxlastseen=max(maxlastseen,lastseen[ch-'a']);
            if(j==maxlastseen)
            {
                partition.push_back(j-i+1);
                i=j+1;
            }
        }
        if(i<n) partition.push_back(n-i);
        return partition;
    }
};
