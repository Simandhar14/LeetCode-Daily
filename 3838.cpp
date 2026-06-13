//cpp
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for (auto& word : words) {
            int sum = 0;
            for (auto& ch : word) {
                sum += weights[ch - 'a'];
            }
            sum = 25 - (sum % 26);
            result.push_back(sum + 'a');
        }
        return result;
    }
};
