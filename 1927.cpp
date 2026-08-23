//cpp
class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') leftQ++;
            else leftSum += num[i] - '0';
            
            if (num[n/2 + i] == '?') rightQ++;
            else rightSum += num[n/2 + i] - '0';
        }
        if ((leftQ + rightQ) % 2 == 1) return true; //alice always win if odd
        int diff = leftSum - rightSum;
        int qDiff = leftQ - rightQ;
        if ((leftQ + rightQ) % 2 == 0) {
            if (leftQ == rightQ) {
                return diff != 0;  
            }
            int target = 9 * (rightQ - leftQ) / 2;
            return diff != target;
        }
        return true; 
    }
};
