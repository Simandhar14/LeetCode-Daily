//cpp
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> pos;
        int n = nums.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            pos[nums[i]] = i;
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            vec.push_back({sum, nums[i]});
        }
        auto lambda = [&](auto a, auto b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        };
        sort(begin(vec), end(vec), lambda);
        int swap = 0;
        for (int i = 0; i < n; i++) {
            int number = vec[i].second;
            if (i != pos[number]) {
                swap++;
                int index = pos[number];
                pos[nums[i]] = index;
                nums[pos[number]] = nums[i];
                pos[number] = i;
                nums[i] = number;
            }
        }
        return swap;
    }
};
