class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        int i=0,j=0,ans=0;
        while(i<players.size() && j<trainers.size()){
            if(players[i]<=trainers[j])
            {
                i++;
                j++;
                ans++;
            }else if(trainers[j]<players[i]) j++;
        }
        return ans;
    }
};
