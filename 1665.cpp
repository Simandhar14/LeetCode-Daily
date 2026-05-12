//cpp
class Solution {
public:
    bool finishTasks(int energy, vector<vector<int>>& tasks) {
        for (auto& temp : tasks) {
            if (energy < temp[1])
                return false;
            if (energy < temp[0])
                return false;
            energy -= temp[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int left = 1, right = 0;
        sort(begin(tasks), end(tasks), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        for (auto& temp : tasks) {
            right += max(temp[0], temp[1]);
        }
        int minEffort = left;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (finishTasks(mid, tasks)) {
                minEffort = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return minEffort;
    }
};
