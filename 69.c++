class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int right = x;
        while (low <= right) {
            int mid = low + (right - low) / 2;
            if (mid == x/mid ) {
                return mid;
            } else if (mid <x/mid )
                low = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};