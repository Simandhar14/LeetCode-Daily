//cpp
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        int n = queries.size();
        vector<string> result;
        for (int i = 0; i < n; i++) {
            string wrd = queries[i];
            for (auto& word : dictionary) {
                int unequal = 0;
                for (int idx = 0; idx < wrd.size(); idx++) {
                    if (wrd[idx] != word[idx])
                        unequal++;
                }
                if (unequal <= 2) {
                    result.push_back(wrd);
                    break;
                }
            }
        }
        return result;
    }
};
