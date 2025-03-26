class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int remainder = grid[0][0] % x;
        vector<int> numbers;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (remainder != (grid[i][j] % x))
                    return -1;
                numbers.emplace_back(grid[i][j]);
            }
        }
        sort(begin(numbers), end(numbers));
        int len = numbers.size();
        int target = numbers[floor(len / 2)];
        int count = 0;
        for (int val : numbers) {
            if (val == target)
                continue;
            int diff = abs(target - val);
            count += diff / x;
        }
        return count;
    }
};
