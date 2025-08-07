class Solution {
public:
    int n;
    vector<vector<int>> t;
    int child2(vector<vector<int>>& fruits, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return 0;
        if (i == n - 1 && j == n - 1)
            return 0;
        if (i == j || i > j) {
            return 0;
        }
        if (t[i][j] != -1)
            return t[i][j];
        int leftdown = child2(fruits, i + 1, j - 1);
        int rightdown = child2(fruits, i + 1, j + 1);
        int down = child2(fruits, i + 1, j);
        return t[i][j] = fruits[i][j] + max({leftdown, rightdown, down});
    }
    int child3(vector<vector<int>>& fruits, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return 0;
        if (i == n - 1 && j == n - 1)
            return 0;
        if (i == j || j > i) {
            return 0;
        }
        if (t[i][j] != -1)
            return t[i][j];
        int right = child3(fruits, i, j + 1);
        int rightup = child3(fruits, i - 1, j + 1);
        int rightdown = child3(fruits, i + 1, j + 1);
        return t[i][j] = fruits[i][j] + max({rightdown, right, rightup});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        int child1val = 0;
        t.resize(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            child1val += fruits[i][i];
            fruits[i][i] = 0;
        }
        int child2val = child2(fruits, 0, n - 1);
        int child3val = child3(fruits, n - 1, 0);
        return child1val + child2val + child3val;
    }
};
