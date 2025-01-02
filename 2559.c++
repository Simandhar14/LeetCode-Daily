class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        vector<int> result;
        int n = words.size();
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            string wrd = words[i];
            if (i == 0) {
                if (st.find(wrd[0]) != st.end() &&
                    st.find(wrd[wrd.length() - 1]) != st.end())
                    prefix[i] = 1;
            } else {
                int val = 0;
                if (st.find(wrd[0]) != st.end() &&
                    st.find(wrd[wrd.length() - 1]) != st.end())
                    val = 1;
                prefix[i] = prefix[i - 1] + val;
            }
        }
        for(auto temp:queries)
        {
            int start=temp[0];
            int end=temp[1];
            int val=0;
            if(start==0) val=prefix[end];
            else val=prefix[end]-prefix[start-1];
            result.push_back(val);
        }
        return result;
    }
};