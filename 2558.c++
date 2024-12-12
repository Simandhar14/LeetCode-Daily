class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long,vector<long long>>pq(begin(gifts),end(gifts));
        while(k--)
        {
            long long gift=pq.top();
            pq.pop();
            long long left=floor(sqrt(gift));
            if(gift==left) pq.push(gift);
            else pq.push(left);
        }
        long long result=0;
        while(!pq.empty())
        {
            result+=pq.top();
            pq.pop();
        }
        return result;
    }
};