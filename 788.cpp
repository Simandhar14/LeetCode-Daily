//cpp
class Solution {
public:
    bool rotate(int number, unordered_map<int, int>& mp) {
        int oneOrZeroOrEight = 0;
        int digits = 0;
        while (number > 0) {
            int digit = number % 10;
            if (!mp.count(digit))
                return false;
            if (digit == 1 || digit == 0 || digit == 8)
                oneOrZeroOrEight++;
            number /= 10;
            digits++;
        }
        if (oneOrZeroOrEight == digits)
            return false;
        return true;
    }
    int rotatedDigits(int n) {
        unordered_map<int, int> mp;
        mp[0] = {0};
        mp[1] = {1};
        mp[8] = {8};
        mp[2] = {5};
        mp[5] = {2};
        mp[6] = {9};
        mp[9] = {6};
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (rotate(i, mp)) {
                result++;
            }
        }
        return result;
    }
};
