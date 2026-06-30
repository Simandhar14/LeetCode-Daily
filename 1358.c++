class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int n=s.length();
        int j=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            mp[ch]++;
            if(mp.size()==3)
            {
                count+=n-i;
                while(j<i)
                {
                    char ch=s[j];
                    mp[ch]--;
                    j++;
                    if(mp[ch]==0) mp.erase(ch);
                    if(mp.size()==3) count+=n-i;
                    else break;
                }
            }
        }
        return count;
    }

};

//brute force
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            int countA = 0, countB = 0, countC = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'a')
                    countA++;
                if (s[j] == 'b')
                    countB++;
                if (s[j] == 'c')
                    countC++;
                if (countA && countB && countC) {
                    result += n - j;
                    break;
                }
            }
        }
        return result;
    }
};
