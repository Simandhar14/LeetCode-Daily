//cpp
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<bool, bool>> freq(26, {false, false});
        int special = 0;
        for (char& ch : word) {
            int idx;
            if (ch >= 'a') {
                idx = ch - 'a';
                freq[idx].first = true;
            } else {
                idx = ch - 'A';
                freq[idx].second = true;
            }
        }
        for (auto& temp : freq)
            if (temp.first && temp.second)
                special++;
        return special;
    }
};
