class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, int> mp;
        vector<string> result;
        int n=recipes.size();
        vector<bool>cooked(n,false);
        for (string ss : supplies) {
            mp[ss] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(cooked[j]) continue;
                bool flag = true;
                auto ingredient = ingredients[j];
                for (auto food : ingredient) {
                    if (mp[food] == 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    mp[recipes[j]] = 1;
                    result.push_back(recipes[j]);
                    cooked[j]=true;
                }
            }
        }
        return result;
    }
};
