class Solution {
public:
typedef vector<int> vec;
vector<vector<int>> directions {{1,0},{0,1},{-1,0},{0,-1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>> dijkstra(n,vector<int>(m,INT_MAX));
        priority_queue<vec,vector<vec>,greater<vec>>pq;
        pq.push({0,0,0});
        while(!pq.empty())
        {
            auto val=pq.top();
            pq.pop();
            int time=val[0];
            int i=val[1];
            int j=val[2];
            for(auto dir:directions)
            {
                int newi=i+dir[0];
                int newj=j+dir[1];
                if(newi>=0 && newj>=0 && newi<n && newj<m){
                    int nexttime=moveTime[newi][newj];
                    int newtime=time;
                    if(time<nexttime) newtime+=(nexttime-time);
                    newtime++;
                    if(newtime<dijkstra[newi][newj])
                    {
                        dijkstra[newi][newj]=newtime;
                        pq.push({newtime,newi,newj});
                    }
                }
            }
        }
        return dijkstra[n-1][m-1];
    }
};
