//cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlti=0;
        int sum=0;
        for(auto &g:gain)
        {
            sum+=g;
            maxAlti=max(maxAlti,sum);
        }
        return maxAlti;
    }
};
