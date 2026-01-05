class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result = 0;
        int smallestnum = INT_MIN;
        int negative = 0;
        for (auto& temp : matrix) {
            for (auto& num : temp) {
                if (num <=0) {
                    negative++;
                    smallestnum = max(smallestnum, num);
                }else smallestnum=max(smallestnum,-1*num);
                result += abs(num);
            }
        }
        return negative % 2 != 0 ? result + smallestnum*2 : result;
    }
};
