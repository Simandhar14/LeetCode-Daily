class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj,
             vector<bool>& secretPeople,
             int u,
             unordered_set<int>& visited) {

        visited.insert(u);
        for (int v : adj[u]) {
            if (!visited.count(v)) {
                secretPeople[v] = true;
                dfs(adj, secretPeople, v, visited);
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {

        vector<bool> secretPeople(n, false);
        secretPeople[0] = true;
        secretPeople[firstPerson] = true;

        map<int, vector<pair<int, int>>> mp;
        for (auto& temp : meetings) {
            mp[temp[2]].push_back({temp[0], temp[1]});
        }

        for (auto& it : mp) {
            unordered_map<int, vector<int>> adj;
            unordered_set<int> visited;

            for (auto& p : it.second) {
                adj[p.first].push_back(p.second);
                adj[p.second].push_back(p.first);
            }

            for (auto& p : it.second) {
                if (secretPeople[p.first] && !visited.count(p.first))
                    dfs(adj, secretPeople, p.first, visited);
                if (secretPeople[p.second] && !visited.count(p.second))
                    dfs(adj, secretPeople, p.second, visited);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (secretPeople[i]) result.push_back(i);
        return result;
    }
};
