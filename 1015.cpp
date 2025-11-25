class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k%5==0)
            return -1;
        int num = 0;
        int length = 1;
        while (true) {
            num = ((num * 10) + 1) % k;
            if (num == 0) {
                return length;
            }
            length++;
        }
        return -1;
    }
};

//java
class Solution {
    public int smallestRepunitDivByK(int k) {
        int rem=0;
        for(int len=1;len<=k;len++)
        {
            rem=(rem*10+1)%k;
            if(rem==0) return len;
        }
        return -1;
    }
}
