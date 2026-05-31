//cpp
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids),end(asteroids));
        long long sum=mass;
        for(int &num:asteroids)
        {
            if(sum<num) return false;
            sum+=num;
        }
        return true;
    }
};
