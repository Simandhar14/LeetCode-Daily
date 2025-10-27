class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int beams = 0;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            int devices = 0;
            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1')
                    devices++;
            }
            if (devices == 0)
                continue;
            if (prev == -1)
                prev = devices;
            else if (prev != -1) {
                beams += devices * prev;
                prev = devices;
            }
        }
        return beams;
    }
};
