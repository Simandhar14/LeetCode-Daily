//cpp - bottom up
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> copies(n, 0);
        vector<vector<int>> t(n + 1, vector<int>(budget + 1, -1));
        int minPrice = INT_MAX;
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);
            int copy = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (items[j][0] % items[i][0] == 0)
                    copy++;
            }

            copies[i] = copy;
        }
        for (int i = 0; i <= budget; i++) {
            t[0][i] = i / minPrice;
        }
        for (int size = 1; size <= n; size++) {
            for (int money = 0; money <= budget; money++) {
                int take = 0;
                int price = items[size - 1][1];

                if (price <= money) {
                    take = 1 + copies[size - 1] + t[size - 1][money - price];
                }
                int skip = t[size - 1][money];
                t[size][money] = max(take, skip);
            }
        }
        int result = INT_MIN;
        for (int i = 0; i <= budget; i++)
            result = max(result, t[n][i]);
        return result;
    }
};

//cpp - top down
class Solution {
public:
    int dp[1001][1501];

    int solve(int n, int budget, int minItem, vector<vector<int>>& items, vector<int>& copies) {
        if(n == 0) {
            return budget/minItem;
        }
        if(dp[n][budget] != -1)
            return dp[n][budget];

        int take = 0;
        int price = items[n-1][1];

        if(price <= budget) {
            take = 1 + copies[n-1] + solve(n-1, budget-price, minItem, items, copies);
        }

        int skip = solve(n-1, budget, minItem, items, copies);

        return dp[n][budget] = max(take, skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> copies(n, 0); 
        int minItem = INT_MAX;

        for(int i = 0; i < n; i++) {
            minItem = min(minItem, items[i][1]);

            int copy = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                if(items[j][0] % items[i][0] == 0)
                    copy++;
            }

            copies[i] = copy;
        }

        memset(dp, -1, sizeof(dp));
        return solve(n, budget, minItem, items, copies);
    }
};
