//cpp
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<pair<int, int>> index(26, {INT_MAX, INT_MIN});
        for (int i = 0; i < n; i++) {
            int idx;
            if (word[i] >= 'a') {
                idx = word[i] - 'a';
                index[idx].first = i;
            } else {
                idx = word[i] - 'A';
                if (index[idx].second == INT_MIN)
                    index[idx].second = i;
            }
        }
        int special = 0;
        for (int i = 0; i < 26; i++) {
            if (index[i].first <= index[i].second)
                special++;
        }
        return special;
    }
};
