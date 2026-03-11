//cpp
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int num = 0;
        int digits=log2(n)+1;
        for (int i = 0; i < digits; i++) {
            int mask = 1 << i;
            int bit=n&mask;
            if (bit == 0){
                num += mask;
            }
        }
        return num;
    }
};

//using xor
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int digits=log2(n)+1;
        int mask=(1<<digits)-1;
        return n ^ mask;
    }
};
