class Solution {
public:
    int MOD = 1e9 + 7;
    int numSub(string s) {
        int count = 0;
        int consecutiveOnes = -1;
        for (char& ch : s) {
            if (ch == '1') {
                if (consecutiveOnes == -1) {

                    consecutiveOnes = 1;
                } else
                    consecutiveOnes++;
                count = (count + consecutiveOnes) % MOD;
            } else {
                consecutiveOnes = -1;
            }
        }
        return count;
    }
};
