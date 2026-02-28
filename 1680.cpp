//cpp
class Solution {
public:
    const int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long result = 0;
        for (int i = 1; i <=n; i++) {
            int bits = floor(log2(i)) + 1;
            result = ((result << bits) % M + i) % M;
        }
        return result;
    }
};
