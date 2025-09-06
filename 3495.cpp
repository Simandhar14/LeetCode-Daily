//tle
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long operations = 0;
        int n = queries.size();
        for (int i = 0; i < n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            vector<int> arr;
            for (int num = l; num <= r; num++)
                arr.emplace_back(num);
            bool allzero;
            long long op = 0;
            while (true) {
                allzero=true;
                for (int k=0;k<r-l+1;k++) {
                    if (arr[k] == 0)
                        continue;
                    else {
                        op++;
                        allzero = false;
                        arr[k] = floor(arr[k] / 4);
                    }
                }
                if (allzero) {
                    operations += (op+1) / 2;
                    break;
                }
            }
        }
        return operations;
    }
};
