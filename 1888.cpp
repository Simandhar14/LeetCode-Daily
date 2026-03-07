//cpp-brute force
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int count = n;
        int result = INT_MAX;
        while (count) {
            string news = s.substr(1);
            news.push_back(s[0]);
            s = news;
            int startWithOne = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0 && s[i] == '0' || i % 2 != 0 && s[i] == '1')
                    startWithOne++;
            }
            result=min({result,startWithOne,n-startWithOne});
            count--;
        }
        return result;
    }
};

//cpp-sliding window
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s += s;
        int result = INT_MAX;
        int startWithOne = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && s[i] == '0' || i % 2 != 0 && s[i] == '1')
                startWithOne++;
        }
        result = min({result, startWithOne, n - startWithOne});
        for (int i = 1; i + n < s.length(); i++) {
            int prev = i - 1;
            if (prev % 2 == 0 && s[prev] == '0' ||
                prev % 2 != 0 && s[prev] == '1')
                startWithOne--;
            int last = i + n - 1;
            if (last % 2 == 0 && s[last] == '0' ||
                last % 2 != 0 && s[last] == '1')
                startWithOne++;
            result = min({result, startWithOne, n - startWithOne});
        }
        return result;
    }
};
