class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> arr(n);
        bool zero = true;
        bool one = true;
        arr[0] = 0;
        for (int i = 0; i < n; i++) {
            arr[(i + 1) % n] = arr[i] ^ derived[i];
        }
        for (int i = 0; i < n; i++) {
            int val = arr[i] ^ arr[(i + 1) % n];
            if (val != derived[i]) {
                zero = false;
                break;
            }
        }
        arr[0] = 1;
        for (int i = 0; i < n; i++) {
            arr[(i + 1) % n] = arr[i] ^ derived[i];
        }
        for (int i = 0; i < n; i++) {
            int val = arr[i] ^ arr[(i + 1) % n];
            if (val != derived[i]) {
                one = false;
                break;
            }
        }
        return zero | one;
    }
};