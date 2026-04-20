//brute force 
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxDist=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(colors[i]!=colors[j]) maxDist=max(maxDist,abs(j-i));
            }
        }
        return maxDist;
    }
};

//optimal approach using map
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = INT_MIN;
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            int color = colors[i];
            if (!mp.count(color)) {
                mp[color] = {i, i};
            } else {
                mp[color].second = i;
            }
        }
        for (auto& it : mp) {
            int minidx1 = it.second.first;
            int maxidx1 = it.second.second;
            for (auto& it2 : mp) {
                if (it == it2)
                    continue;
                int minidx2 = it2.second.first;
                int maxidx2 = it2.second.second;
                maxDist = max({maxDist, abs(minidx1-maxidx2),abs(minidx2-maxidx1)});
            }
        }
        return maxDist;
    }
};
