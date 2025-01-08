class Solution {
public:
bool check(string str,string wrd)
{
    int n=str.size();
    if(n>wrd.size()) return false;
    for(int i=0;i<n;i++)
    {
        if(str[i]!=wrd[i]) {
            return false;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(str[n-1-i]!=wrd[wrd.length()-1-i]) {
            return false;
        }
    }
    return true;
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(words[i],words[j])) count++;
            }
        }
        return count;
    }
};