//cpp
class Solution {
public:
    vector<int> validSequence(const string& word1, const string& word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<int> suf(n + 1, m); 
        
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = j + 1; 
        }

        vector<int> ans;
        ans.reserve(m); 
        
        j = 0; 
        bool canChange = true;

        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j] || (canChange && suf[i + 1] <= j + 1)) {
                ans.push_back(i);
                if (word1[i] != word2[j]) {
                    canChange = false; 
                }
                j++;
            }
        }

        return (ans.size() == m) ? ans : vector<int>();
    }
};
