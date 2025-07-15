class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3)
            return false;
        int n = word.length();
        bool vowel = false;
        bool consonant = false;
        for (int i = 0; i < n; i++) {
            if (word[i] == '@' || word[i] == '$' || word[i] == '#')
                return false;
             if (isalpha(word[i])) {
                if (word[i] == 'a' || word[i] == 'A' || word[i] == 'e' ||
                    word[i] == 'E' || word[i] == 'i' || word[i] == 'I' ||
                    word[i] == 'o' || word[i] == 'O' || word[i] == 'u' ||
                    word[i] == 'U')
                    vowel = true;
                else
                    consonant = true;
            }
        }
        return consonant && vowel;
    }
};
