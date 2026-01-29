//c++
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if(source.length()!=target.length()) return -1;
        vector<vector<int>>adj(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++)
        {
            adj[i][i]=0;
        }
        for(int i=0;i<cost.size();i++)
        {
            int u=original[i]-'a';
            int v=changed[i]-'a';
            adj[u][v]=min(cost[i],adj[u][v]);
        }
        for(int via=0;via<26;via++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(adj[i][via]!=INT_MAX && adj[via][j]!=INT_MAX)
                    {
                        adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
                    }
                }
            }
        }
        long long minCost=0;
        for(int i=0;i<source.length();i++)
        {
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(u==v) continue;
            else if(adj[u][v]==INT_MAX) return -1;
            minCost+=adj[u][v];
        }
        return minCost;
    }
};

//java
class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
         if(source.length()!=target.length()) return -1;
         int [][]adj=new int[26][26];
          for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                adj[i][j] = Integer.MAX_VALUE;
            }
        }
        for(int i=0;i<26;i++)
        {
            adj[i][i]=0;
        }
        for(int i=0;i<cost.length;i++)
        {
            int u=original[i]-'a';
            int v=changed[i]-'a';
            adj[u][v]=Math.min(cost[i],adj[u][v]);
        }
        for(int via=0;via<26;via++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(adj[i][via]!=Integer.MAX_VALUE && adj[via][j]!=Integer.MAX_VALUE)
                    {
                        adj[i][j]=Math.min(adj[i][j],adj[i][via]+adj[via][j]);
                    }
                }
            }
        }
        long minCost=0;
        for(int i=0;i<source.length();i++)
        {
            int u=source.charAt(i)-'a';
            int v=target.charAt(i)-'a';
            if(u==v) continue;
            else if(adj[u][v]==Integer.MAX_VALUE) return -1;
            minCost+=adj[u][v];
        }
        return minCost;
    }
}
