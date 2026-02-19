//cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 0;
        int result = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                curr++;
            }else{
                curr++;
                result+=min(prev,curr);
                prev=curr;
                curr=0;
            }
        }
        curr++;
        result += min(prev, curr);
        return result;
    }
};
