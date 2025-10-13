class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int i=1;
        while(i<words.size())
        {
            string temp1=words[i-1];
            string temp2=words[i];
            sort(begin(temp1),end(temp1));
            sort(begin(temp2),end(temp2));
            if(temp1==temp2)
            {
                words.erase(begin(words)+i);
                i=1;
            }else i++;
        }
        return words;
    }
};
