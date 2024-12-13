class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>marked(n,0);
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        while(!pq.empty())
        {
            auto vec=pq.top();
            pq.pop();
            int idx=vec.second;
            if(marked[idx]) continue;
            score+=vec.first;
            if(idx>0) marked[idx-1]=1;
            if(idx<n-1) marked[idx+1]=1;
            marked[idx]=1;
        }
        return score;
    }
};