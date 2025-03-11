class Solution {
public:
    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        vector<int> consindex;
        int consonant = 0;
        int nextcons = 0;
        long long count = 0;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            if (!isVowel(word[i]))
                consindex.emplace_back(i);
        }
        int i = 0;
        unordered_map<char, int> mp;
        for (int j = 0; j < n; j++) {
            char ch = word[j];
            if (isVowel(ch))
                mp[ch]++;
            else {
                consonant++;
                nextcons++;
            }
            while (i < j && consonant > k) {
                char ch = word[i];
                if (isVowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0)
                        mp.erase(ch);
                } else
                    consonant--;
                i++;
            }
            if (mp.size() == 5 && consonant == k) {
                if (nextcons < consindex.size())
                    count += consindex[nextcons] - j;
                else
                    count += n - j;
                while (i < j) {
                    char ch = word[i];
                    if (isVowel(ch)) {
                        mp[ch]--;
                        if (mp[ch] == 0)
                            mp.erase(ch);
                    } else
                        consonant--;
                    i++;
                    if (mp.size() == 5 && consonant == k) {
                        if (nextcons < consindex.size())
                            count += consindex[nextcons] - j;
                        else
                            count += n - j;
                    } else
                        break;
                }
            }
        }
        return count;
    }
};