//cpp
class Solution {
public:
    bool checkLocal(string& str1, string& str2, string& word, int pos) {
        int n = str1.length();
        int m = str2.length();

        int start = max(0, pos - m + 1);
        int end = min(pos, n - 1);

        for (int i = start; i <= end; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    return false;
            }
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int len = n + m - 1;
        string word(len, '$');

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                int start = 0;
                for (int idx = i; idx < i + m; idx++) {
                    word[idx] = str2[start];
                    start++;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (word[i] == '$') {
                char smallest = '*';
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (checkLocal(str1, str2, word, i)) {
                        smallest = ch;
                        break;
                    }
                }
                if (smallest == '*')
                    return "";
                word[i] = smallest;
            }
        }

        for (int i = 0; i < n; i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (word[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }
            if (str1[i] == 'T' && !match)
                return "";
            if (str1[i] == 'F' && match)
                return "";
        }

        return word;
    }
};
