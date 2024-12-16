class Solution {
public:
#define P pair<int,int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<P,vector<P>,greater<P>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        while(k--)
        {
            auto vec=pq.top();
            pq.pop();
            int x=vec.first;
            int i=vec.second;
            int val=x*multiplier;
            pq.push({val,i});
            nums[i]=val;
        }
        return nums;        
    }
};