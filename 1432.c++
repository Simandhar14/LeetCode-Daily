class Solution {
public:
    int maxDiff(int num) {
        string ss = to_string(num);
        string a = ss;
        string b = ss;
        int idx = a.find_first_not_of('9');
        if (idx != string::npos) {
            char ch = a[idx];
            replace(begin(a), end(a), ch, '9');
        }
        if (b[0] != '1') {
            idx = b.find_first_not_of('1');
            if (idx != string::npos) {
                char ch = b[idx];
                replace(begin(b), end(b), ch, '1');
            }
        } else {
            string temp = "";
            int index = 1;
            while (index < b.length()) {
                temp = b;
                idx = b.find_first_not_of('0', index);
                if (idx != string::npos) {
                    char ch = b[idx];
                    replace(begin(temp), end(temp), ch,
                            '0'); 
                    if (stoi(temp) != 0 && b[0]!=b[idx]) {
                        b = temp;
                        index = b.length();
                    }
                }
                index++;
            }
        }
        return stoi(a) - stoi(b);
    }
};
