class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(string ss:strs)
        {
            string temp=ss;
            sort(begin(temp),end(temp));
            mp[temp].push_back(ss);
        }
        vector<vector<string>>result;
        for(auto var:mp)
        {
            result.push_back(var.second);
        }
        return result;
    }
};