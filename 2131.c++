class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int result = 0;
        bool SameLetterWord = false;

        for (auto &temp : words) {
            string rev = temp;
            reverse(begin(rev), end(rev));

            if (temp == rev) {
                
                if (mp[temp] > 0) {
                   
                    result += 4;
                    mp[temp]--;
                } else {
                    
                    mp[temp]++;
                }
            } else {
               
                if (mp[rev] > 0) {
                    result += 4;
                    mp[rev]--;
                } else {
              
                    mp[temp]++;
                }
            }
        }

        for (auto &[word, count] : mp) {
            if (count > 0 && word[0] == word[1]) {
                result += 2;
                break;
            }
        }

        return result;
    }
};
