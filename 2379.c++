class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        int n=blocks.size();
        int white=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(blocks[i]=='W') white++;
            while(i-j+1>k)
            {
                if(blocks[j]=='W') white--;
                j++;
            }
            if(i-j+1==k)ans=min(ans,white);
        }
        return ans;
    }
};