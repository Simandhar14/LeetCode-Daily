//gray code solution
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int operations=0;
        while(n>0)
        {
            operations^=n;
            n>>=1;
        }
        return operations;
    }
};

//pattern method

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0)
            return 0;
        vector<long long> bits(32, 0);
        int operations = 0;
        bits[0] = 1;
        for (int i = 1; i < 32; i++) {
            bits[i] = 2 * bits[i - 1] + 1;
        }
        bool flag = false;
        for (int i = 31; i >= 0; i--) {
            int ithbit=((1 << i)&n);
            if (ithbit !=0) {
                if (!flag)
                    operations += bits[i];
                else
                    operations -= bits[i];
                flag = !flag;
            }
        }
        return operations;
    }
};
