class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballcolors;
        unordered_map<int, int> colors;
        vector<int> result;
        for (auto temp : queries) {
            int x = temp[0];
            int y = temp[1];
            if (ballcolors[x]) {
                int prevcolor = ballcolors[x];
                colors[prevcolor]--;
                if (colors[prevcolor] == 0)
                    colors.erase(prevcolor);
            }
            colors[y]++;
            ballcolors[x] = y;
            result.push_back(colors.size());
        }
        return result;
    }
};