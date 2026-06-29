class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;
        for (auto& str : patterns) {
            if (word.find(str) != string::npos)
                result++;
        }
        return result;
    }
};
