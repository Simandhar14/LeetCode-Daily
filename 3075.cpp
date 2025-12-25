class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int decrement=0;
        priority_queue<int,vector<int>> pq;
        for(int &hap:happiness) pq.push(hap);

        long long result=0;
        while(!pq.empty() && k--)
        {
            int val=pq.top()-decrement;
            if(val<0) break;
            result+=val;
            pq.pop();
            decrement++;
        }
        return result;
    }
};
