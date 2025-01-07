class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        for(string wrd:words)
        {
            for(string str:words)
            {
                if(wrd==str) continue;
                if(str.find(wrd)!=string::npos)
                {
                    ans.push_back(wrd);
                    break;
                }
            }
        }
        return ans;
    }
};