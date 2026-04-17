//cpp
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        int minDist=INT_MAX;
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);

        for(int i=0;i<n;i++)
        {
            bool trailingZero=false;
            int reverse=0;
            int num=nums[i];
            while(num>0)
            {
                int d=num%10;
                num/=10;
                if(d==0 && !trailingZero) continue;
                else trailingZero=true;
                reverse=reverse*10+d;
            }
            auto it=upper_bound(begin(mp[reverse]),end(mp[reverse]),i);
            if(it!=mp[reverse].end()) minDist=min(minDist,*it-i);
        }
        return minDist==INT_MAX ? -1 : minDist;
    }
};
