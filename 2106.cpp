class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> prefixsum;
        int ans = 0;
        unordered_map<int, int> mp;
        int n = 0;
        for (auto temp : fruits) {
            mp[temp[0]] += temp[1];
            n = max(temp[0], n);
        }
        n++;
        int totalfruits = 0;
        prefixsum.resize(n);
        
        for (int i = 0; i < n; i++) {
            totalfruits += mp[i];
            prefixsum[i] = totalfruits;
        }
        for (int i = 0; i < n; i++) {
            int startingsteps = abs(startPos - i);
            if (k < startingsteps)
                continue;
            int remainingsteps = abs(k - startingsteps);
            int rightsteps=i+remainingsteps;
            rightsteps=min(rightsteps,n-1);
            int totalfruits = prefixsum[rightsteps];
            if (i > 0)
                totalfruits -= prefixsum[i - 1];
            ans = max(ans, totalfruits);

            int leftsteps=i-remainingsteps;
            leftsteps=max(leftsteps,0);
            totalfruits=prefixsum[i];
            if(leftsteps>0) totalfruits-=prefixsum[leftsteps-1];
            ans=max(ans,totalfruits);
           
        }
        return ans;
    }
};
