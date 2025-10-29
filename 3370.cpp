class Solution {
public:
    int smallestNumber(int n) {
        if (n <= 3) {
            if (n <= 1)
                return 1;
            return 3;
        }
        int startnum = 8;
        while (startnum <=n) {
            startnum += startnum;
        }
        return startnum - 1;
    }
};

//best approach
class Solution {
public:
    int smallestNumber(int n) {
       int bits=log2(n)+1;
       int smallestNumber=(1<<bits)-1;
       return smallestNumber;
    }
};
