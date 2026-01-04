class Solution {
public:
    int findDivisorSum(int number) {
        int divisors = 0;
        int sumofdivisors = 0;
        for (int j = 1; j <= sqrt(number); j++) {
            if (number % j == 0) {
                divisors++;
                sumofdivisors += j;
                int divisor2 = number / j;
                if (divisor2 != j) {
                    divisors++;
                    sumofdivisors += divisor2;
                }
            }
            if (divisors > 4)
                break;
        }
        return divisors == 4 ? sumofdivisors : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += findDivisorSum(nums[i]);
        }
        return result;
    }
};
