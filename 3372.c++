class Solution {
public:
    int calculatenodes(int u, unordered_map<int, vector<int>>& mp, int dist,
                       int k, vector<bool>&visited) {
        if (dist > k)
            return 0;
        visited[u] = true;
        int count = 1;
        for (auto& v : mp[u]) {
            if (!visited[v]) {
                count += calculatenodes(v, mp, dist + 1, k, visited);
            }
        }
        return count;
    }
    void insertdata(unordered_set<int>& tree1,
                    unordered_map<int, vector<int>>& mp,
                    vector<vector<int>>& edges) {
        for (auto temp : edges) {
            int u = temp[0];
            int v = temp[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
            tree1.insert(u);
            tree1.insert(v);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        unordered_set<int> tree1;
        unordered_map<int, vector<int>> mp;
        insertdata(tree1, mp, edges2);
        int nodes = tree1.size();
        int maxnodes = 0;
        for (auto temp : tree1) {
            int u = temp;
            vector<bool> visited(nodes, false);
            maxnodes = max(maxnodes, calculatenodes(u, mp, 1, k, visited));
        }
        mp = unordered_map < int, vector<int>>();
        tree1 = unordered_set<int>();
        insertdata(tree1, mp, edges1);
        nodes = tree1.size();
        vector<int> result(nodes);
        for (int i = 0; i < nodes; i++) {
            vector<bool> visited(nodes, false);
            int reachableNodes = calculatenodes(i, mp, 0, k, visited);
            result[i] = reachableNodes + maxnodes;
        }
        return result;
    }
};
