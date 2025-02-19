class Solution {
public:
    void solve(int n, int count, vector<string>& st, string &temp) {
        if(count==n)
        {
            st.push_back(temp);
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
        vector<string> st;
        solve(n, 0, st, temp);
        string result = "";
        if(k>st.size()) return result;
        return st[k-1];
    }
};