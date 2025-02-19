class Solution {
public:
    void solve(int n, int count, set<string>& st, string &temp) {
        if(count==n)
        {
            st.insert(temp);
            return;
        }
        for (char i = 'a'; i <= 'c'; i++) {
            if (!temp.empty() && temp.back() == i)
                continue;
            temp.push_back(i);
            solve(n, count + 1, st, temp);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string temp = "";
        set<string> st;
        solve(n, 0, st, temp);
        string result = "";
        if(k>st.size()) return result;
        for (auto it = st.begin(); it != st.end(); it++) {
            k--;
            if (k == 0) {
                result = *it;
                break;
            }
        }
        return result;
    }
};