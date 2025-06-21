class Solution {
public:
    int minimumDeletions(string word, int k) {
        int ans = INT_MAX;
        sort(begin(word), end(word));
        int count = 1;
        char ch = word[0];
        vector<int> freq;
        for (int i = 1; i < word.size(); i++) {
            if (ch == word[i]) {
                count++;
            } else {
                freq.emplace_back(count);
                ch = word[i];
                count = 1;
            }
        }
        freq.emplace_back(count);
        int n = freq.size();
        for (int i = 0; i < n; i++) {
            int deletefreq = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (freq[j] < freq[i])
                    deletefreq += freq[j];
                else if (freq[j] > freq[i] + k)
                    deletefreq += freq[j] - (freq[i] + k);
            }
            ans = min(ans, deletefreq);
        }
        return ans;
    }
};
