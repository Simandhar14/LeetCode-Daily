class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int result = INT_MAX;
        vector<bool> required(friendships.size(), false);
        for (int len = 0; len < friendships.size(); len++) {
            for (int i = 1; i <= n; i++) {
                bool notcommon=true;
                for(auto person:friendships[len])
                {
                    auto it=find(begin(languages[person-1]),end(languages[person-1]),i);
                    if(it==languages[person-1].end()) 
                    {
                        notcommon=false;
                        break;
                    }
                }
                if(notcommon)
                {
                    required[len]=true;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            int ans = 0;
            unordered_set<int>temp;
            for (int j=0;j<friendships.size();j++) {
                int count = 0;
                if(required[j]==true) continue;
                for (auto& person : friendships[j]) {
                    if (find(languages[person-1].begin(), languages[person-1].end(), i) ==
                        languages[person-1].end()) {
                       temp.insert(person);
                    }
                }
                ans = temp.size();
            }
            result = min(ans, result);
        }
        return result;
    }
};
