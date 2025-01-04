class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result = 0;
        size_t n = s.length();
        unordered_set<char>letters;
        for(char ch:s)
        {
            letters.insert(ch);
        }
        for(char ch:letters)
        {
            int start=-1,end=-1;
            for(int i=0;i<n;i++)
            {
                if(ch==s[i])
                {
                    if(start==-1) start=i;
                    end=i;
                }
            }
            unordered_set<char> st;
            if (end == -1 || end - 2 < start)
                continue;
            int index = start + 1;
            while (index < end) {
                st.insert(s[index]);
                index++;
            }
            result+=st.size();
        }
        return result;
    }
};