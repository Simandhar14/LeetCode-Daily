class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int num = 1;
        for (int i = 0; i < (n % 2 == 0 ? n : n - 1); i += 2) {
            ans.emplace_back(num);
            ans.emplace_back(-1 * num);
            num++;
        }
        if (n % 2 != 0)
            ans.emplace_back(0);
        return ans;
    }
};
