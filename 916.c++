class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>mp;
        vector<string>result;
        for(string wrd:words2)
        {
            unordered_map<char,int>freq;
            for(char ch:wrd)
            {
                freq[ch]++;
                mp[ch]=max(freq[ch],mp[ch]);
            }
        }
        for(string wrd:words1)
        {
            int i=0;
            int n=wrd.length();
            unordered_map<char,int>temp=mp;
            while(i<n)
            {
                if(temp.find(wrd[i])!=temp.end())
                {
                    temp[wrd[i]]--;
                    if(temp[wrd[i]]==0) temp.erase(wrd[i]);
                }
                i++;
            }
            if(temp.empty()) result.push_back(wrd);
        }
        return result;
    }
};