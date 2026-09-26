//cpp
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, int> mp;
        int n = s.length();
        string result = "";
        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = i;
        }
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                start = i;
            } else if (s[i] == ')') {
                int len = i - start - 1;
                string temp = s.substr(start + 1, len);
                if (mp.count(temp)) {
                    int idx = mp[temp];
                    result += knowledge[idx][1];
                } else
                    result.push_back('?');
                start = -1;
            } else if (start == -1)
                result.push_back(s[i]);
        }
        return result;
    }
};
