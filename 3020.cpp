class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        int result = 1;
        for (auto& temp : mp) {
            int subset = 0;
            long long num = temp.first;
            int freq = temp.second;
            if (num == 1) {
                result = max(result, (freq % 2 == 0) ? freq - 1 : freq);
                continue;
            }
            if (freq >= 2) {
                subset += 2;
                num = num * num;
                while (mp.count(num)) {
                    result = max(result, subset + 1);
                    if (mp[num] == 1)
                        break;
                    subset += 2;
                      if (num > LLONG_MAX / num)
        break;
                    num = num * num;
                }
            }
        }
        return result;
    }
};
