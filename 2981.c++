class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string ss="";
            int j=i;
            int count=0;
            while(j<n)
            {
                if(s[i]==s[j]) {
                    count++;
                    mp[{s[i],count}]++;
                    j++;
                }
                else break;
            }
        }
        int len=-1;
        for(auto curr:mp)
        {
            auto vec=curr.first;
            int freq=vec.second;
            if(curr.second>=3)
            {
                len=max(len,freq);
            }
        }
        return len;
    }
};