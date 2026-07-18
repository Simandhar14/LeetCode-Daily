//cpp using the stl
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxval = *max_element(begin(nums), end(nums));
        int minval = *min_element(begin(nums), end(nums));
        return __gcd(maxval, minval);
    }
};

//without stl
class Solution {
public:
    int calcGcd(int maxval, int minval) {
        for (int num = minval; num > 1; num--) {
            if (maxval % num==0 && minval % num==0)
                return num;
        }
        return 1;
    }
    int findGCD(vector<int>& nums) {
        int maxval = *max_element(begin(nums), end(nums));
        int minval = *min_element(begin(nums), end(nums));
        return calcGcd(maxval, minval);
    }
};
