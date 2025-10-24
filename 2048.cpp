//brute force
class Solution {
public:
    int nextBeautifulNumber(int n) {
        int number = n + 1;
        string maxnum=to_string(n);
        int digits=maxnum.size();
        int upperlimit=0;
        for(int i=0;i<digits+1;i++)
        {
            upperlimit=upperlimit*10+(digits+1);
        }
        while (number<=upperlimit) {
            string freq = string(10, '0');
            int temp = number;
            while (temp > 0) {
                int digit = temp % 10;
                temp /= 10;
                freq[digit]++;
            }
            bool correct = true;
            for (int i = 0; i <= 9; i++) {
                if (freq[i] == '0')
                    continue;
                if (i != freq[i] - '0') {
                    correct = false;
                    break;
                }
            }
            if (correct)
                return number;
            number++;
        }
        return -1;
    }
};
