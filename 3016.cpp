//cpp
class Solution {
public:
    int minimumPushes(string word) {
          vector<int>freq(26,0);
        for(char &ch:word)
        {
            freq[ch-'a']++;
        }
        sort(rbegin(freq),rend(freq));
        int buttons=8;
        int push=1;
        int totalPush=0;
        for(auto &num:freq)
        {
            if(num==0) continue;
            totalPush+=push * num;
            buttons--;
            if(buttons==0) {
                buttons=8;
                push++;
            }
        }
        return totalPush;
    }
};
