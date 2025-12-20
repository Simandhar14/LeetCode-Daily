class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int delcols=0;
        int n=strs.size();
        int len=strs[0].length();
        for(int col=0;col<len;col++)
        {
            char prev=strs[0][col];
            for(int i=1;i<strs.size();i++)
            {
                if(strs[i][col]<prev) {
                    delcols++;
                    break;
                }
                prev=strs[i][col];
            }
        }
        return delcols;
    }
};
