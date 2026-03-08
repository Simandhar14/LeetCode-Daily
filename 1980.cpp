//cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st;
        int n = nums.size();
        string ss(n, '0');
        while (st.size()<=n) {
            st.insert(ss);
            int i = n - 1;
            while (i >= 0 && ss[i] == '1') {
                ss[i] = '0';
                i--;
            }
            if (i < 0)
                ss = "1" + ss;
            else
                ss[i] = '1';
        }
        for(string &str:nums) st.erase(str);
        return *begin(st);
    }
};
