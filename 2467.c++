#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = INT_MIN;

    bool bobdfs(unordered_map<int, int> &bobtime,
                unordered_map<int, vector<int>> &adj, int curr, int t,
                vector<int>& visited) {
        visited[curr] = 1;
        bobtime[curr] = t;

        if (curr == 0) {
            return true;
        }

        for (auto& ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                if (bobdfs(bobtime, adj, ngbr, t + 1, visited) == true) {
                    return true;
                }
            }
        }

        bobtime.erase(curr);
        return false;
    }

    void alicedfs(unordered_map<int, int>& bobtime, int time,
                  unordered_map<int, vector<int>>& adj, vector<int>& visited,
                  int u, int profit, vector<int>& amount) {
        visited[u] = 1;
        int value = profit;

        if (bobtime.count(u)==0 || time<bobtime[u] ) value+=amount[u];
        else if(time==bobtime[u]) value+=(amount[u]/2);
            
        bool leaf=true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                leaf=false;
                alicedfs(bobtime, time + 1, adj, visited, v, value, amount);
            }
        }
        if(leaf)  result = max(result, value);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int nodes = edges.size() + 1;
        unordered_map<int, vector<int>> adj;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, int> bobtime;
        vector<int> visited(nodes, 0);

        bobdfs(bobtime, adj, bob, 0, visited);

        visited = vector<int>(nodes, 0);
        alicedfs(bobtime, 0, adj, visited, 0, 0, amount);

        return result;
    }
};
