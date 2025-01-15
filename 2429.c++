class Solution {
public:
    bool isset(int bitposition, int x) {
        int val = 1 << bitposition;
        return val & x ;
    }
    int setbit(int bitposition, int x) {
        int val = 1 << bitposition;
        int result = x | val;
        return result;
    }
    int unsetbit(int bitposition, int x) {
        int val = 1 << bitposition;
        val = ~val;
        int result = x & val;
        return result;
    }
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int requiredsetbit = __builtin_popcount(num2);
        int currsetbit = __builtin_popcount(x);

        int bitposition = 0;
        if (currsetbit < requiredsetbit) {
            while (currsetbit < requiredsetbit) {

                if (!isset(bitposition, x)) {
                    x=setbit(bitposition, x);
                    currsetbit++;
                }
                bitposition++;
            }
        } else if (currsetbit > requiredsetbit) {
            bitposition = 0;
            while (currsetbit > requiredsetbit) {

                if (isset(bitposition, x)) {
                    x=unsetbit(bitposition, x);
                    currsetbit--;
                }
                bitposition++;
            }
        }
        return x;
    }
};