//cpp
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string temp = "";
            int sum = 0, group = 0;
            for (int i = 0; i < s.length(); i++) {
                group = 1;
                sum += s[i] - '0';
                if ((i + 1) % k == 0) {
                    temp += to_string(sum);
                    sum = 0;
                    group = 0;
                }
            }
            if (group)
                temp += to_string(sum);
            s = temp;
        }
        return s;
    }
};
