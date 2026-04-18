//cpp
class Solution {
public:
    int mirrorDistance(int n) {
        int num = n;
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return abs(rev - n);
    }
};
