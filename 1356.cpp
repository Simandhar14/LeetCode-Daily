class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        sort(begin(arr),end(arr));
        for(int &num:arr)
        {
            int setBits=__builtin_popcount(num);
            mp[setBits].push_back(num);
        }
        vector<int>result;
        for(auto &temp:mp)
        {
            for(auto &numbers:temp.second) result.push_back(numbers);
        }
        return result;
    }
};
