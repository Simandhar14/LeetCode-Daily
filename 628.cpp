//cpp
class Solution {
public:
    int takeProduct(const vector<int>& freq, int start, int end, int step, int cnt) {
        int product = 1;

        for (int i = start; i != end && cnt > 0; i += step) {
            int temp = freq[i];
            while (temp > 0 && cnt > 0) {
                product *= (i - 1000);
                temp--;
                cnt--;
            }
        }

        return product;
    }

    int maximumProduct(vector<int>& nums) {
        vector<int> freq(2001, 0);
        int maxNum = INT_MIN;

        for (int num : nums) {
            freq[num + 1000]++;
            maxNum = max(maxNum, num);
        }

        int product1 = takeProduct(freq, 2000, -1, -1, 3);
        int product2 = maxNum * takeProduct(freq, 0, 2001, 1, 2);

        return max(product1, product2);
    }
};
