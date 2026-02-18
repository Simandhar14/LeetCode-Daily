//cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = -1;

        while (n > 0) {
            int bit = n & 1;

            if (prevBit == bit)
                return false;

            prevBit = bit;
            n >>= 1;
        }
        return true;
    }
};
