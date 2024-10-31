class Solution {
public:
long long solve(vector<int>& robot,vector<int>&pos,int i,int j,int r_size,int p_size,vector<vector<long long>>&dp)
{
    if(i==r_size) return 0;
    if(i!=r_size && j>=p_size) return LLONG_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
      long long take = LLONG_MAX;
        long long next_take = solve(robot, pos, i + 1, j + 1, r_size, p_size, dp);
        if (next_take != LLONG_MAX) {
            take = abs(robot[i] - pos[j]) + next_take;
        }
        long long skip = solve(robot, pos, i, j + 1, r_size, p_size, dp);
        
        return dp[i][j] = min(take, skip);
}
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int r_size=robot.size();
        vector<int>pos;
        for(vector<int>temp:factory)
        {
            int p=temp[0];
            int count=temp[1];
            while(count--)
            {
                pos.push_back(p);
            }
        }
        sort(begin(robot),end(robot));
        sort(begin(pos),end(pos));
        int p_size=pos.size();
        vector<vector<long long>>dp(r_size,vector<long long>(p_size,-1));
        return solve(robot,pos,0,0,r_size,p_size,dp);
    }
};