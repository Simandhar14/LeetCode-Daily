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
 