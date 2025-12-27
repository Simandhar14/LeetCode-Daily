class Solution {
public:
    int bestClosingTime(string customers) {
        int totalCust = 0;
        int n = customers.length();
        for (char& ch : customers)
            if (ch == 'Y')
                totalCust++;
        int result = INT_MAX;
        int closingTime = -1;
        int leftCust = 0;
        for (int i = 0; i < n; i++) {
            int cust = customers[i] == 'Y' ? 1 : 0;
            int noCust = i - leftCust;
            int missedCust = totalCust - leftCust;
            if (cust + missedCust + noCust < result) {
                result = min(result, cust + missedCust + noCust);
                closingTime = i;
            }
            leftCust += cust;
        }
        if (n - leftCust < result) {
            result = min(result, n - leftCust);
            closingTime = n;
        }
        return closingTime;
    }
};
