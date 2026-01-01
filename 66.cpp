class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int> result;
        for (int i = n - 1; i >= 0; i--) {
            int newnum;
            newnum = carry + digits[i];
            carry=0;
            if (newnum >= 10) {
                result.push_back(0);
                carry = 1;
            } else
                result.push_back(newnum);
        }
        if (carry)
            result.push_back(1);
        reverse(begin(result), end(result));
        return result;
    }
};
