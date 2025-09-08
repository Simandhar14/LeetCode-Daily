class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int n1 = 1; n1 < n; n1++) {
            string ss = to_string(n1);
            int n2 = n - n1;
            string ss1 = to_string(n2);
            if (ss.find('0') == string::npos && ss1.find('0') == string::npos &&
                (n1 + n2) == n)
                return {n1, n2};
        }
        return {};
    }
};
