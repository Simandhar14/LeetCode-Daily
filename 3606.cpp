class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<string> result;
        map<string, multiset<string>> mp;
        int n = code.size();
        for (int i = 0; i < n; i++) {
            bool special = false;
            for (char& c : code[i]) {
                if(c=='_') continue;
                if (!isalnum(c)) {
                    special = true;
                    break;
                }
            }
            if (code[i] == "" || special ||
                (businessLine[i] != "electronics" &&
                 businessLine[i] != "grocery" &&
                 businessLine[i] != "pharmacy" &&
                 businessLine[i] != "restaurant") ||
                isActive[i] == false)
                continue;

            mp[businessLine[i]].insert(code[i]);
        }
        for (auto& temp : mp) {
            for (auto it : temp.second) {
                result.push_back(it);
            }
        }
        return result;
    }
};
