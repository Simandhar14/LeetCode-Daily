//cpp
class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int longestDistance = 0;
        for (int i = 0; i < 32; i++) {
            int bit = n & 1;
            if (bit == 1) {
                if (prev == -1)
                    prev = i;
                else {
                    longestDistance = max(longestDistance, i - prev);
                    prev = i;
                }
            }
            n>>=1;
        }
        return longestDistance;
    }
};
