class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st;
        int totalWords=0;
        int brokenWords=0;
        for(char ch:brokenLetters)
        {
            st.insert(ch);
        }
        stringstream ss(text);
        string word;
        while(ss>>word)
        {
            totalWords++;
            for(int i=0;i<word.size();i++)
            {
                if(st.count(word[i])){
                    brokenWords++;
                    break;
                }
            }
        }
        return totalWords-brokenWords;
    }
};
