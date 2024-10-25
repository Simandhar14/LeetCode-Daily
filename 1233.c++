class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder), end(folder));
        vector<string> result;
        for (string curr : folder) {
            string temp = curr;
            bool flag = false;
            while (!curr.empty()) {
                size_t pos = curr.find_last_of('/');
                curr = curr.substr(0, pos);
                if (st.find(curr) != st.end()) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                result.push_back(temp);
        }
        return result;
    }
};
