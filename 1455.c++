class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>words;
        istringstream stream(sentence);
        string word;
        while(stream>>word)
        {
            words.push_back(word);
        }
        for(int i=0;i<words.size();i++)
        {
            if(words[i].starts_with(searchWord)) return i+1;
        }
        return -1;
    }
};