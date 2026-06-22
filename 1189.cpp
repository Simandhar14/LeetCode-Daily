//cpp
class Solution {
public:
    unordered_map<char, int> mp;
    int maxNumberOfBalloons(string text) {
        for (char& ch : text)
            mp[ch]++;
        int balloons =
            min({mp['b'], mp['a'], mp['l'] / 2, mp['o'] / 2, mp['n']});
        return balloons;
    }
};
