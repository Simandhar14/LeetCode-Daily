//sliding window
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int result = 0;
        int countA = 0, countB = 0, countC = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                countA++;
            if (s[i] == 'b')
                countB++;
            if (s[i] == 'c')
                countC++;
            if (countA && countB && countC) {
                while (j < i && countA && countB && countC) {
                    result += n - i;
                    if (s[j] == 'a')
                        countA--;
                    if (s[j] == 'b')
                        countB--;
                    if (s[j] == 'c')
                        countC--;
                    j++;
                }
            }
        }
        return result;
    }
};

//brute force
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            int countA = 0, countB = 0, countC = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'a')
                    countA++;
                if (s[j] == 'b')
                    countB++;
                if (s[j] == 'c')
                    countC++;
                if (countA && countB && countC) {
                    result += n - j;
                    break;
                }
            }
        }
        return result;
    }
};

