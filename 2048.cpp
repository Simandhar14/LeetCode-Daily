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

//backtracking
class Solution {
public:
    int N;

    int solve(int digitsleft, string freq, int num) {
        if (digitsleft == 0) {
            if (num > N) {
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
                    return num;
                else
                    return 0;
            } else
                return 0;
        }
        for (int i = 1; i <= 9; i++) {
            int currentfreq = freq[i] - '0';
            if (currentfreq > 0 && currentfreq <= digitsleft) {
                int newnum = num * 10 + i;
                freq[i]--;
                int res = solve(digitsleft - 1, freq, newnum);
                if (res != 0)
                    return res;
                freq[i]++;
            }
        }
        return 0;
    }
    int nextBeautifulNumber(int n) {
        N = n;
        int digits = 0;
        int number = n;
        while (number > 0) {
            digits++;
            number /= 10;
        }
        string freq = string(10, '0');
        for (int i = 0; i < 10; i++) {
            freq[i] = i + '0';
        }

        int result=solve(digits, freq, 0);
        if(result==0)
        {
            result=solve(digits+1, freq, 0);
        }
        return result;
    }
};
