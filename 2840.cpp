//brute force
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string sorted1=s1,sorted2=s2;
        int n = s1.size();
        sort(begin(sorted1), end(sorted1));
        sort(begin(sorted2), end(sorted2));
        if(sorted1!=sorted2) return false;
        vector<bool>used(n,false);
        for (int i = 0; i < n; i++) {
            bool found = false;
            int j = i % 2 == 0 ? 0 : 1;
            while (j < n) {
                if (s2[i] == s1[j] && !used[j]) {
                    found = true;
                    used[j]=true;
                    break;
                }
                j += 2;
            }
            if (!found)
                return false;
        }
        return true;
    }
};

//optimal solution
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        unordered_map<char,int> odd;
        unordered_map<char,int> even;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                even[s1[i]]++;
            else
                odd[s1[i]]++;
        }
        for (int i = 0; i < n; i++) {
            char ch = s2[i];
            if (i % 2 == 0) {
                if (even.count(ch)) {
                    even[ch]--;
                    if (even[ch] == 0)
                        even.erase(ch);
                } else
                    return false;
            } else {
                if (odd.count(ch)) {
                    odd[ch]--;
                    if (odd[ch] == 0)
                        odd.erase(ch);
                } else
                    return false;
            }
        }
        return true;
    }
};
