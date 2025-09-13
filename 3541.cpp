class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int vowels = 0;
        int consonants = 0;
        for (auto temp : mp) {
            if (temp.first == 'a' || temp.first == 'e' || temp.first == 'i' ||
                temp.first == 'o' || temp.first == 'u') {
                vowels = max(vowels, temp.second);
            }
        }
        for (auto temp : mp) {
            if (temp.first != 'a' && temp.first != 'e' && temp.first != 'i' &&
                temp.first != 'o' && temp.first != 'u') {
                consonants = max(consonants, temp.second);
            }
        }
        return vowels+consonants;
    }
};
