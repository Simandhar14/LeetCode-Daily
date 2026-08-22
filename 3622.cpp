//cpp
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int temp = n;
        while (temp > 0) {
            int d = temp % 10;
            sum += d;
            product *= d;
            temp /= 10;
        }
        int total = sum + product;
        return n % total == 0;
    }
};
