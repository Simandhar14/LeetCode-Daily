//cpp
class Solution {
public:
    int maxProduct(int n) {
        string ss = to_string(n);
        int len = ss.length();
        int maxval1 = 0;
        int count = 0;
        for (int i = 0; i < len; i++) {
            int num = ss[i] - '0';
            if (num > maxval1) {
                maxval1 = num;
                count = 1;
            } else if (num == maxval1) {
                count++;
            }
        }
        if (count > 1)
            return maxval1 * maxval1;
        int maxval2 = 0;
        for (int i = 0; i < len; i++) {
            int num = ss[i] - '0';
            if (num < maxval1 && num > maxval2) {
                maxval2 = num;
            }
        }
        return maxval2 * maxval1;
    }
};
