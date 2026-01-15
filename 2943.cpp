class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));
        int hStreak=1;
        int maxhStreak=1;
        for(int i=1;i<hBars.size();i++)
        {
            if(hBars[i]==hBars[i-1]+1) hStreak++;
            else hStreak=1;
            maxhStreak=max(maxhStreak,hStreak);
        }
        int vStreak=1;
        int maxvStreak=1;
        for(int i=1;i<vBars.size();i++)
        {
            if(vBars[i]==vBars[i-1]+1) vStreak++;
            else vStreak=1;
            maxvStreak=max(maxvStreak,vStreak);
        }
        int maxSide=min(maxvStreak,maxhStreak)+1;
        return maxSide*maxSide;
    }
};
