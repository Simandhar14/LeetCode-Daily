class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        if(n1!=n2) return false;
        int count=0;
        vector<int>freq(26,0);
        for(char ch:s1)
        {
            freq[ch-'a']++;
        }
        for(char ch:s2)
        {
            freq[ch-'a']--;
            if(freq[ch-'a']<0) return false;
        }
        for(int i=0;i<n1;i++)
        {
            if(s1[i]!=s2[i]) count++;
        }
        return count==2 || count==0;
    }
};