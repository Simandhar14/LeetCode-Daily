class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> result;
        map<int,long long>mp;
        for(auto &seg:segments)
        {
            int start=seg[0];
            int end=seg[1];
            int color=seg[2];
            mp[start]+=color;
            mp[end]-=color;
        }
        int start=-1;
        long long sum=0;
        for(auto &temp:mp)
        {
            if(sum==0)
            {
                start=temp.first;
                sum+=temp.second;
            }else{
                result.push_back({start,temp.first,sum});
                start=temp.first;
                sum+=temp.second;
            }
        }
        return result;
    }
};
