class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int ones = 0;
        int tempOnes = 0;
        vector<int> leftZeros(n, 0);
        vector<int> rightZeros(n, 0);
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                zeros++;
            else if (s[i] == '1') {
                leftZeros[i] = zeros;
                zeros = 0;
                ones++;
            }
        }
        zeros = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                zeros++;
            else if (s[i] == '1') {
                rightZeros[i] = zeros;
                zeros = 0;
            }
        }
        int result = ones;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i == 0)
                    continue;
                if (tempOnes > 0) {
                    int idx = i - tempOnes;
                    int leftZero = leftZeros[idx];
                    int rightZero = rightZeros[i - 1];
                    if (leftZero > 0 && rightZero > 0)
                        result = max(result, leftZero + rightZero + ones);
                }
                tempOnes = 0;
            } else {
                tempOnes++;
            }
        }
        return result;
    }
};
