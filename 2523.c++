class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime(right + 1, 1);
        prime[1] = 0;
        for (int i = 2; i * i <= right; i++) {
            if (prime[i] == 1) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = 0;
                }
            }
        }
        int ans1=-1,ans2=-1;
        int diff=INT_MAX;
        int num1 = -1;
        int num2 = -1;
        for (int i = left; i <= right; i++) {
            if (prime[i] == 1) {
                if (num1 == -1) {
                    num1 = i;
                }else{
                    num2=i;
                    if(num2-num1<diff)
                    {
                        diff=num2-num1;
                        ans1=num1;
                        ans2=num2;
                    }
                    num1=num2;
                    num2=-1;
                }
            }
        }
        return {ans1,ans2};
    }
};