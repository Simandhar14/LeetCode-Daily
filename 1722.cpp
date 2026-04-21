//cpp
class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]); 
    }
    void Union(int x, int y) {
        int parentx = find(x);
        int parenty = find(y);
        if (parentx == parenty)
            return;

        if (rank[parentx] > rank[parenty]) {
            parent[parenty] = parentx;
        } else if (rank[parentx] < rank[parenty]) {
            parent[parentx] = parenty;
        } else {
            parent[parentx] = parenty;
            rank[parenty]++;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU ob(n);

        for (auto& arr : allowedSwaps) {
            ob.Union(arr[0], arr[1]);
        }
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[ob.find(i)].push_back(i);
        }

        int hammingDistance = 0;
        for (auto &g : groups) {
            auto &indices = g.second;
            unordered_map<int, int> freq;
            for (int idx : indices) {
                freq[source[idx]]++;
            }
            for (int idx : indices) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    hammingDistance++;
                }
            }
        }

        return hammingDistance;
    }
};
